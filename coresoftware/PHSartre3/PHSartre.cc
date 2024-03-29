#include "PHSartre.h"
#include "PHSartreGenTrigger.h"

#include <phhepmc/PHHepMCGenEvent.h>
#include <phhepmc/PHHepMCGenEventMap.h>

#include <fun4all/Fun4AllReturnCodes.h>

#include <phool/PHCompositeNode.h>

#include <sartre/Sartre.h>

#include <TGenPhaseSpace.h>
#include <TVectorD.h>
#include <CLHEP/Vector/LorentzVector.h>

#include <HepMC/GenEvent.h>

#include <gsl/gsl_randist.h>

using namespace std;

PHSartre::PHSartre(const std::string &name)
  : SubsysReco(name)
  , _eventcount(0)
  , _gencount(0)
  , _registeredTriggers()
  , _triggersOR(true)
  , _triggersAND(false)
  , _configFile("")
  , _commands()
  , _sartre(nullptr)
  , settings(nullptr)
  , decay(nullptr)
  , daughterID(-1)
  , daughterMasses{0., 0.}
  , doPerformDecay(false)
  , myfile(nullptr)
  // , _filename(name)
  //  , _tfile(nullptr)
{
  char *charPath = getenv("SARTRE_DIR");
  if (!charPath)
  {
    cout << "PHSartre::Could not find $SARTRE_DIR path!" << endl;
    return;
  }

  //
  //  Create the generator and initialize it.
  //  Once initialized you cannot (should not) change
  //  the settings w/o re-initialing sartre.
  //
  _sartre = new Sartre();

  hepmc_helper.set_embedding_id(1);  // default embedding ID to 1
}

PHSartre::~PHSartre()
{
  delete _sartre;
}

int PHSartre::Init(PHCompositeNode *topNode)
{
  if (!_configFile.empty())
  {
    bool ok = _sartre->init(_configFile);
    if (!ok)
    {
      cerr << "Initialization of sartre failed." << endl;
      return Fun4AllReturnCodes::ABORTRUN;
    }
  }
  else
  {
    cerr << "Sartre configuration file must be specified" << endl;
    return Fun4AllReturnCodes::ABORTRUN;
  }

  settings = _sartre->runSettings();
  settings->list();

  create_node_tree(topNode);

  // event numbering will start from 1
  _eventcount = 0;

  decay = new TGenPhaseSpace();  // for VM decays
  daughterID = settings->userInt();
  if (daughterID && (settings->vectorMesonId() != 22))
  {
    doPerformDecay = true;
    daughterMasses[0] = settings->lookupPDG(daughterID)->Mass();
    daughterMasses[1] = settings->lookupPDG(-daughterID)->Mass();
    cout << "PHSartre: "
         << "Will decay vector meson: ";
    cout << "PHSartre: " << settings->lookupPDG(settings->vectorMesonId())->GetName();
    cout << "PHSartre: "
         << " -> ";
    cout << "PHSartre: " << settings->lookupPDG(daughterID)->GetName();
    cout << " ";
    cout << "PHSartre: " << settings->lookupPDG(-daughterID)->GetName();
    cout << endl;
  }

  //_tfile = new TFile(TString(_filename.c_str())+".root", "RECREATE");
  // std::string _filename = "testeroni";
  //TString eictreeout =  TString(_filename.c_str());
  //myfile.open(eictreeout);
  myfile = new ofstream(this->Name(),ios::out);
  *myfile << "PYTHIA EVENT FILE\n============================================\nI, ievent, genevent, subprocess, nucleon, targetparton, xtargparton, beamparton, xbeamparton, thetabeamparton, truey, trueQ2, truex, trueW2, trueNu, leptonphi, s_hat, t_hat, u_hat, pt2_hat, Q2_hat, F2, F1, R, sigma_rad, SigRadCor, EBrems, photonflux, nrTracks\n============================================\nI, K(I,1)  K(I,2)  K(I,3)  K(I,4)  K(I,5)             P(I,1)  P(I,2)  P(I,3)  P(I,4)  P(I,5) V(I,1)  V(I,2)  V(I,3)\n============================================\n";

  return Fun4AllReturnCodes::EVENT_OK;
}

int PHSartre::End(PHCompositeNode *topNode)
{
  if (Verbosity() > 1) cout << "PHSartre::End - I'm here!" << endl;

  cout << "PHSartre: "
       << " Total cross-section: " << _sartre->totalCrossSection() << " nb" << endl;
  _sartre->listStatus();

  cout << " *-------  Begin PHSARTRE Trigger Statistics  ----------------------"
       << "-------------------------------------------------* " << endl;
  cout << " |                                                                "
       << "                                                 | " << endl;
  cout << "                         PHSartre::End - " << _eventcount
       << " events passed trigger" << endl;
  cout << "                         Fraction passed: " << _eventcount
       << "/" << _gencount
       << " = " << _eventcount / float(_gencount) << endl;
  cout << " *-------  End PHSARTRE Trigger Statistics  ------------------------"
       << "-------------------------------------------------* " << endl;
  return Fun4AllReturnCodes::EVENT_OK;
  //TFile *_tfile = new TFile(TString(_filename.c_str())+".root", "RECREATE");
  //_tfile->cd();
  //TVectorD xsection(1);
  //xsection[0]=_sartre->totalCrossSection();
  //xsection.Write("xsec");
  //  myfile->close();
  //_tfile->Close();
  return Fun4AllReturnCodes::EVENT_OK;
}

//-* print pythia config info
void PHSartre::print_config() const
{
  settings->list();
}

int PHSartre::process_event(PHCompositeNode *topNode)
{
  if (Verbosity() > 1) cout << "PHSartre::process_event - event: " << _eventcount << endl;

  bool passedTrigger = false;
  Event *event = nullptr;

  TLorentzVector *eIn = nullptr;
  TLorentzVector *pIn = nullptr;
  TLorentzVector *eOut = nullptr;
  TLorentzVector *gamma = nullptr;
  TLorentzVector *vm = nullptr;
  TLorentzVector *PomOut = nullptr;
  TLorentzVector *pOut = nullptr;
  TLorentzVector *vmDecay1 = nullptr;
  TLorentzVector *vmDecay2 = nullptr;
  unsigned int preVMDecaySize = 0;


  while (!passedTrigger)
    {
      ++_gencount;
      
      // Generate a Sartre event
      event = _sartre->generateEvent();
      
    //
    //  If Sartre is run in UPC mode, half of the events needs to be
    //  rotated around and axis perpendicular to z:
    //  (only for symmetric events)
    //
    if (settings->UPC() and settings->A() == settings->UPCA())
    {
      randomlyReverseBeams(event);
    }

    // for sPHENIX/RHIC p+Au
    // (see comments in ReverseBeams)
    // reverse when the proton emits the virtual photon

    if (settings->UPC() and settings->A() == 197)
    {
      ReverseBeams(event);
    }

    // Set pointers to the parts of the event we will need:

    eIn = &event->particles[0].p;
    pIn = &event->particles[1].p;
    eOut = &event->particles[2].p;
    gamma = &event->particles[3].p;
    vm = &event->particles[4].p;
    PomOut = &event->particles[5].p;
    pOut = &event->particles[6].p;

    // To allow the triggering to work properly, we need to decay the vector meson here

    preVMDecaySize = event->particles.size();

    if (doPerformDecay)
    {
      if (decay->SetDecay(*vm, 2, daughterMasses))
      {
        double weight = decay->Generate();  // weight is always 1 here
        if ((weight - 1) > FLT_EPSILON)
        {
          cout << "PHSartre: Warning decay weight != 1, weight = " << weight << endl;
        }
        TLorentzVector *vmDaughter1 = decay->GetDecay(0);
        TLorentzVector *vmDaughter2 = decay->GetDecay(1);

        event->particles[4].status = 2;  // set VM status

        Particle vmDC1;
        vmDC1.index = event->particles.size();
        vmDC1.pdgId = daughterID;
        vmDC1.status = 1;  // final state
        vmDC1.p = *vmDaughter1;
        vmDC1.parents.push_back(4);
        event->particles.push_back(vmDC1);
        vmDecay1 = &event->particles[event->particles.size() - 1].p;

        Particle vmDC2;
        vmDC2.index = event->particles.size();
        vmDC2.pdgId = -daughterID;
        vmDC2.status = 1;  // final state
        vmDC2.p = *vmDaughter2;
        vmDC2.parents.push_back(4);
        event->particles.push_back(vmDC2);
        vmDecay2 = &event->particles[event->particles.size() - 1].p;
      }
      else
      {
        cout << "PHSartre: WARNING: Kinematics of Vector Meson does not allow decay!" << endl;
      }
    }

    // test trigger logic

    bool andScoreKeeper = true;
    if (Verbosity() > 2)
    {
      cout << "PHSartre::process_event - triggersize: " << _registeredTriggers.size() << endl;
    }

    for (unsigned int tr = 0; tr < _registeredTriggers.size(); tr++)
    {
      bool trigResult = _registeredTriggers[tr]->Apply(event);

      if (Verbosity() > 2)
      {
        cout << "PHSartre::process_event trigger: "
             << _registeredTriggers[tr]->GetName() << "  " << trigResult << endl;
      }

      if (_triggersOR && trigResult)
      {
        passedTrigger = true;
        break;
      }
      else if (_triggersAND)
      {
        andScoreKeeper &= trigResult;
      }

      if (Verbosity() > 2 && !passedTrigger)
      {
        cout << "PHSartre::process_event - failed trigger: "
             << _registeredTriggers[tr]->GetName() << endl;
      }
    }

    if ((andScoreKeeper && _triggersAND) || (_registeredTriggers.size() == 0))
    {
      passedTrigger = true;
    }
    }

  // fill HepMC object with event

  HepMC::GenEvent *genevent = new HepMC::GenEvent(HepMC::Units::GEV, HepMC::Units::MM);

  // add some information to the event
  genevent->set_event_number(_eventcount);
  *myfile << "0"; // I
  *myfile << "\t"; 
  *myfile << _eventcount; // ievent
  *myfile << "\t"; 
  *myfile << "1"; //genevent
  *myfile << "\t";
  *myfile << "0\t 0\t 0\t 0\t 0\t 0\t 0\t"; //subprocess
  *myfile << event->y; //truey
  *myfile << "\t";
  *myfile << event->Q2; //trueQ2
  *myfile << "\t";
  *myfile << event->x; //truex
  *myfile << "\t";
  *myfile << event->W; //trueW
  *myfile << "\t 0\t 0.1\t"; //trueNu
  *myfile << event->s; //trueS
  *myfile << "\t";
  *myfile << event->t; //trueT
  *myfile << "\t 0\t 0\t 0\t 0\t 0\t 0\t 0\t 0\t 0\t 0\t 0\t\n";
  *myfile << "============================================\n";

  //Push back initial particle vectors
  // eIn
  *myfile << "1\t"; //I
  *myfile << "21\t"; //Status (21 for beam)
  *myfile << "11\t"; //PDG
  *myfile << "0\t 0\t 0\t"; //Bogus
  *myfile << eIn->Px(); //Px
  *myfile << "\t"; 
  *myfile << eIn->Py(); //Py
  *myfile << "\t";
  *myfile << eIn->Pz(); //Pz
  *myfile << "\t";
  *myfile << eIn->E(); //Energy
  *myfile << "\t";
  *myfile << eIn->M(); //Mass
  *myfile << "\t 0\t 0\t 0\n"; //Vertex
  // pIn
  *myfile << "2\t";
  *myfile << "21\t"; // (21 for beam)
  *myfile << "2212\t";
  *myfile << "0\t 0\t 0\t";
  *myfile << pIn->Px();
  *myfile << "\t";
  *myfile << pIn->Py();
  *myfile << "\t";
  *myfile << pIn->Pz();
  *myfile << "\t";
  *myfile << pIn->E();
  *myfile << "\t";
  *myfile << pIn->M();
  *myfile << "\t 0\t 0\t 0\n";
  // gamma
  *myfile << "3\t";
  *myfile << "21\t"; 
  *myfile << "22\t";
  *myfile << "0\t 0\t 0\t";
  *myfile << gamma->Px();
  *myfile << "\t";
  *myfile << gamma->Py();
  *myfile << "\t";
  *myfile << gamma->Pz();
  *myfile << "\t";
  *myfile << gamma->E();
  *myfile << "\t";
  *myfile << gamma->M();
  *myfile << "\t 0\t 0\t 0\n";
  // eOut
  *myfile << "4\t";
  *myfile << "1\t";
  *myfile << "11\t";
  *myfile << "3\t 0\t 0\t"; // 3 for scattered lepton
  *myfile << eOut->Px();
  *myfile << "\t";
  *myfile << eOut->Py();
  *myfile << "\t";
  *myfile << eOut->Pz();
  *myfile << "\t";
  *myfile << eOut->E();
  *myfile << "\t";
  *myfile << eOut->M();
  *myfile << "\t 0\t 0\t 0\n";
  // hPomOut
  *myfile << "5\t";
  *myfile << "2\t";
  *myfile << event->particles[5].pdgId;
  *myfile << "\t 0\t 0\t 0\t";
  *myfile << PomOut->Px();
  *myfile << "\t";
  *myfile << PomOut->Py();
  *myfile << "\t";
  *myfile << PomOut->Pz();
  *myfile << "\t";
  *myfile << PomOut->E();
  *myfile << "\t";
  *myfile << PomOut->M();
  *myfile << "\t 0\t 0\t 0\n";
  // If this is a nuclear breakup, add in the nuclear fragments
  // Otherwise, add in the outgoing hadron

  //If the event is incoherent, and nuclear breakup is enabled, fill the remnants to the tree

  if (settings->enableNuclearBreakup() and event->diffractiveMode == incoherent)
  {
    for (unsigned int iParticle = 7; iParticle < preVMDecaySize; iParticle++)
    {
      if (event->particles[iParticle].status == 1)
      {

	// I am giving these particles a status of '5' to denote them for later analysis modules //
	const Particle &particle = event->particles[iParticle];
	*myfile << iParticle+3;
	*myfile << "\t";
	*myfile << "1\t";
	*myfile << particle.pdgId;
	*myfile << "\t";
	*myfile << "5\t 0\t 0\t";
	*myfile << particle.p.Px();
	*myfile << "\t";
	*myfile << particle.p.Py();
	*myfile << "\t";
	*myfile << particle.p.Pz();
	*myfile << "\t";
	*myfile << particle.p.E();
	*myfile << "\t";
	*myfile << particle.p.E(); //Use mass twice
	*myfile << "\t 0\t 0\t 0\n";
	
      }
    }
  }
  else
    {
      //Outgoing Hadron
       *myfile << "6\t";
       *myfile << "1\t";
       *myfile << event->particles[6].pdgId;
       *myfile << "\t 1\t 0\t 0\t";
       *myfile << pOut->Px();
       *myfile << "\t";
       *myfile << pOut->Py();
       *myfile << "\t";
       *myfile << pOut->Pz();
       *myfile << "\t";
       *myfile << pOut->E();
       *myfile << "\t";
       *myfile << pOut->M();
       *myfile << "\t 0\t 0\t 0\n";
  }

  // VM
  *myfile << "7\t";
  *myfile << "2\t";
  *myfile << event->particles[4].pdgId;
  *myfile << "\t 0\t 0\t 0\t";
  *myfile << vm->Px();
  *myfile << "\t";
  *myfile << vm->Py();
  *myfile << "\t";
  *myfile << vm->Pz();
  *myfile << "\t";
  *myfile << vm->E();
  *myfile << "\t";
  *myfile << vm->M();
  *myfile << "\t 0\t 0\t 0\n";

  // Add the VM decay to the event

  if (doPerformDecay)
  {
    if (vmDecay1 && vmDecay2)
      {
	*myfile << "8\t";
	*myfile << "1\t";
	*myfile << daughterID;
	*myfile << "\t 0\t 0\t 0\t";
	*myfile << vmDecay1->Px();
	*myfile << "\t";
	*myfile << vmDecay1->Py();
	*myfile << "\t";
	*myfile << vmDecay1->Pz();
	*myfile << "\t";
	*myfile << vmDecay1->E();
	*myfile << "\t";
	*myfile << vmDecay1->M();
	*myfile << "\t 0\t 0\t 0\n";

	*myfile << "9\t";
	*myfile << "1\t";
	*myfile << -daughterID;
	*myfile << "\t 0\t 0\t 0\t";
	*myfile << vmDecay2->Px();
	*myfile << "\t";
	*myfile << vmDecay2->Py();
	*myfile << "\t";
	*myfile << vmDecay2->Pz();
	*myfile << "\t";
	*myfile << vmDecay2->E();
	*myfile << "\t";
	*myfile << vmDecay2->M();
	*myfile << "\t 0\t 0\t 0\n";
    }
    else
    {
      cout << "PHSartre: WARNING: Kinematics of Vector Meson does not allow decay!" << endl;
    }
    *myfile<<" =============== Event finished =============== \n";
    if (_eventcount%1000==0)
      cout << _eventcount << " total events completed" << endl;
    //copy down cross section
    //cross_section = _sartre->totalCrossSection();
    //fill event information tree
    //_outTree->Fill();
  }

  // pass HepMC to PHNode

  PHHepMCGenEvent *success = hepmc_helper.insert_event(genevent);
  if (!success)
  {
    cout << "PHSartre::process_event - Failed to add event to HepMC record!" << endl;
    return Fun4AllReturnCodes::ABORTRUN;
  }

  // print outs

  if (Verbosity() > 2) cout << "PHSartre::process_event - FINISHED WHOLE EVENT" << endl;
  
  ++_eventcount;
  return Fun4AllReturnCodes::EVENT_OK;
}

int PHSartre::create_node_tree(PHCompositeNode *topNode)
{
  hepmc_helper.create_node_tree(topNode);

  return Fun4AllReturnCodes::EVENT_OK;
}

int PHSartre::ResetEvent(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

void PHSartre::register_trigger(PHSartreGenTrigger *theTrigger)
{
  if (Verbosity() > 1) cout << "PHSartre::registerTrigger - trigger " << theTrigger->GetName() << " registered" << endl;
  _registeredTriggers.push_back(theTrigger);
}

// UPC only
void PHSartre::randomlyReverseBeams(Event *myEvent)
{
  if (gsl_rng_uniform(hepmc_helper.get_random_generator()) > 0.5)
  {
    for (unsigned int i = 0; i < myEvent->particles.size(); i++)
      myEvent->particles.at(i).p.RotateX(M_PI);
  }
}

// Used to rotate into the sPHENIX/RHIC frame
// The photon emitting beam is always pz<0, and in sPHENIX this will be
// the ion direction. So what you want to run are two files with:
// A=1 UPCA=197 (no reversal, Au ion emits photon)
// A=197 UPCA=1 (reversal required, proton emits photon)
void PHSartre::ReverseBeams(Event *myEvent)
{
  for (unsigned int i = 0; i < myEvent->particles.size(); i++)
    myEvent->particles.at(i).p.RotateX(M_PI);
}
