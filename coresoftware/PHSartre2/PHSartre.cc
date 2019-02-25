#include "PHSartre.h"
#include "PHSartreGenTrigger.h"

#include <phhepmc/PHHepMCGenEvent.h>
#include <phhepmc/PHHepMCGenEventMap.h>

#include <fun4all/Fun4AllReturnCodes.h>

#include <phool/PHCompositeNode.h>

#include <sartre/Sartre.h>

#include <TGenPhaseSpace.h>

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
  , _filename(name)
  , _tfile(nullptr)
  , _outTree(nullptr)
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

  _tfile = new TFile(_filename.c_str(), "RECREATE");

  /* Add tree branches */

  _outTree = new TTree("event_sartre","A Tree with Sartre Root Output");
  _outTree->Branch("event", &_eventcount, "event/I");

  _outTree->Branch("x", &event_x, "x");
  _outTree->Branch("Q2", &event_Q2, "Q2");
  _outTree->Branch("W", &event_W, "W");
  _outTree->Branch("t", &event_t, "t");
  _outTree->Branch("y", &event_y, "y");
  _outTree->Branch("s", &event_s, "s");
  _outTree->Branch("cross_section", &cross_section, "xsection nb");

  _outTree->Branch("particle_px", &particle_px);
  _outTree->Branch("particle_py", &particle_py);
  _outTree->Branch("particle_pz", &particle_pz);
  _outTree->Branch("particle_id", &particle_id);
  _outTree->Branch("particle_E", &particle_E);
  _outTree->Branch("particle_theta", &particle_theta);
  _outTree->Branch("particle_phi", &particle_phi);
  _outTree->Branch("particle_eta", &particle_eta);
  _outTree->Branch("particle_status", &particle_status);
  
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

  cout << " Tree Printing " << endl;
  _tfile->cd();
  _outTree->Write();
  _tfile->Close();
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

  /* Clear Tree Variables */
  particle_px.clear(); particle_py.clear(); particle_pz.clear(); particle_id.clear(); particle_E.clear(); particle_theta.clear(); particle_phi.clear(); particle_eta.clear();

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

  event_x=event->x;
  event_Q2=event->Q2;
  event_t=event->t;
  event_W=event->W;
  event_y=event->y;
  event_s=event->s;

  /* Push back initial particle vectors */
  // eIn
  particle_px.push_back(eIn->Px());
  particle_py.push_back(eIn->Py());
  particle_pz.push_back(eIn->Pz());
  particle_E.push_back(eIn->E());
  particle_theta.push_back(eIn->Theta());
  particle_phi.push_back(eIn->Phi());
  particle_eta.push_back(-999);
  particle_id.push_back(event->particles[0].pdgId);
  particle_status.push_back(0);

  // pIn
  particle_px.push_back(pIn->Px());
  particle_py.push_back(pIn->Py());
  particle_pz.push_back(pIn->Pz());
  particle_E.push_back(pIn->E());
  particle_theta.push_back(pIn->Theta());
  particle_phi.push_back(pIn->Phi());
  particle_eta.push_back(999);
  particle_id.push_back(event->particles[1].pdgId);
  particle_status.push_back(0);

  // gamma
  particle_px.push_back(gamma->Px());
  particle_py.push_back(gamma->Py());
  particle_pz.push_back(gamma->Pz());
  particle_E.push_back(gamma->E());
  particle_id.push_back(event->particles[3].pdgId);
  particle_status.push_back(4);

  // eOut
  particle_px.push_back(eOut->Px());
  particle_py.push_back(eOut->Py());
  particle_pz.push_back(eOut->Pz());
  particle_E.push_back(eOut->E());
  particle_theta.push_back(gamma->Theta());
  particle_phi.push_back(gamma->Phi());
  particle_eta.push_back(gamma->Eta());
  particle_id.push_back(event->particles[2].pdgId);
  particle_status.push_back(1);

  // hPomOut
  particle_px.push_back(PomOut->Px());
  particle_py.push_back(PomOut->Py());
  particle_pz.push_back(PomOut->Pz());
  particle_E.push_back(PomOut->E());
  particle_theta.push_back(PomOut->Theta());
  particle_phi.push_back(PomOut->Phi());
  particle_eta.push_back(PomOut->Eta());
  particle_id.push_back(event->particles[5].pdgId);
  particle_status.push_back(2);

  // If this is a nuclear breakup, add in the nuclear fragments
  // Otherwise, add in the outgoing hadron

  //If the event is incoherent, and nuclear breakup is enabled, fill the remnants to the tree

  if (settings->enableNuclearBreakup() and event->diffractiveMode == incoherent)
  {
    for (unsigned int iParticle = 7; iParticle < preVMDecaySize; iParticle++)
    {
      if (event->particles[iParticle].status == 1)
      {
        const Particle &particle = event->particles[iParticle];
	particle_px.push_back(particle.p.Px());
	particle_py.push_back(particle.p.Py());
	particle_pz.push_back(particle.p.Pz());
	particle_E.push_back(particle.p.E());
	// To be implemented //
	particle_theta.push_back(0);
	particle_phi.push_back(0);
	particle_eta.push_back(0);

	particle_id.push_back(particle.pdgId);
	particle_status.push_back(3);
      }
    }
  }
  else
    {
       particle_px.push_back(pOut->Px());
       particle_py.push_back(pOut->Py());
       particle_pz.push_back(pOut->Pz());
       particle_E.push_back(pOut->E());
       particle_theta.push_back(pOut->Theta());
       particle_phi.push_back(pOut->Phi());
       particle_eta.push_back(pOut->Eta());
       particle_id.push_back(event->particles[6].pdgId);
       particle_status.push_back(1);
  }

  // Photon Pomeron
  
  int isVMFinal = 3;
  if (doPerformDecay) isVMFinal = 2;

  particle_px.push_back(vm->Px());
  particle_py.push_back(vm->Py());
  particle_pz.push_back(vm->Pz());
  particle_E.push_back(vm->E());
  particle_theta.push_back(vm->Theta());
  particle_phi.push_back(vm->Phi());
  particle_eta.push_back(vm->Eta());
  particle_id.push_back(event->particles[4].pdgId);
  particle_status.push_back(isVMFinal);

  // Add the VM decay to the event

  if (doPerformDecay)
  {
    if (vmDecay1 && vmDecay2)
    {
       particle_px.push_back(vmDecay1->Px());
       particle_py.push_back(vmDecay1->Py());
       particle_pz.push_back(vmDecay1->Pz());
       particle_E.push_back(vmDecay1->E());
       particle_theta.push_back(vmDecay1->Theta());
       particle_phi.push_back(vmDecay1->Phi());
       particle_eta.push_back(vmDecay1->Eta());
       particle_id.push_back(daughterID);
       particle_status.push_back(3);

       particle_px.push_back(vmDecay2->Px());
       particle_py.push_back(vmDecay2->Py());
       particle_pz.push_back(vmDecay2->Pz());
       particle_E.push_back(vmDecay2->E());
       particle_theta.push_back(vmDecay2->Theta());
       particle_phi.push_back(vmDecay2->Phi());
       particle_eta.push_back(vmDecay2->Eta());
       particle_id.push_back(-daughterID);
       particle_status.push_back(3);
    }
    else
    {
      cout << "PHSartre: WARNING: Kinematics of Vector Meson does not allow decay!" << endl;
    }

    /* copy down cross section */
    cross_section = _sartre->totalCrossSection();
    /* fill event information tree */
    _outTree->Fill();
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
