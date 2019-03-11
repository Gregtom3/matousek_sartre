#include <stdio.h>
int Fun4All_MCEventGen(
                       const int nEvents = 1,
                       const char * outputFileRaw = "test"
                       )
{
  //===============
  // Input options
  //===============

  // Use particle generator Sartre
  const bool runsartre = true;

  //Create EIC Tree and Smear
  const bool convert_2_eictree = true;
 
  // Setting Strings
  TString outputFileText = TString(outputFileRaw) + ".txt";
  TString outputFileEICTree = "eictree_" + TString(outputFileRaw) + ".txt";
  TString outputFileEICSmear = "eictree_" + TString(outputFileRaw) + ".root";



  //---------------
  // Load libraries
  //---------------
  gSystem->Load("libfun4all.so");
  gSystem->Load("libphhepmc.so");
  //gSystem->Load("libg4detectors.so");
  //gSystem->Load("libg4eval.so");

  //---------------
  // Fun4All server
  //---------------
  Fun4AllServer *se = Fun4AllServer::instance();
  se->Verbosity(0); // uncomment for batch production running with minimal output messages
  // se->Verbosity(Fun4AllServer::VERBOSITY_SOME); // uncomment for some info for interactive running

  // just if we set some flags somewhere in this macro
  recoConsts *rc = recoConsts::instance();
 

  /* Set world parameters in reco consts */
  rc->set_FloatFlag("WorldSizex", 1000.);
  rc->set_FloatFlag("WorldSizey", 1000.);
  rc->set_FloatFlag("WorldSizez", 1000.);
  rc->set_CharFlag("WorldShape", "G4Tubs");


  //-----------------
  // Event generation
  //-----------------

 
  if (runsartre)
    {
      // see coresoftware/generators/PHSartre/README for setup instructions
      // before running:
      // setenv SARTRE_DIR /opt/sphenix/core/sartre-1.20_root-5.34.36
      gSystem->Load("libPHSartre.so");

      PHSartre* mysartre = new PHSartre(outputFileText.Data());
      // see coresoftware/generators/PHSartre for example config
      mysartre->set_config_file("sartre.cfg");

      // particle trigger to enhance forward J/Psi -> ee
      //PHSartreParticleTrigger* pTrig = new PHSartreParticleTrigger("MySartreTrigger");
      //pTrig->AddParticles(-11);
      //pTrig->SetEtaHighLow(4.0,1.4);
      //pTrig->SetEtaHighLow(1.0,-1.1);  // central arm
      //pTrig->PrintConfig();
      //mysartre->register_trigger((PHSartreGenTrigger *)pTrig);
      se->registerSubsystem(mysartre);
    }

  // ------------------
  // Convert to EICTree
  // ------------------

  /*if (convert_2_eictree)
    {
      gSystem->Load("libeicsmearana.so");

      eic2smear*  mysmear = new eic2smear(outputFile);

      se->registerOutputManager(mysmear);
      }*/
  //-----------------
  // Event processing
  //-----------------
  if (nEvents <= 0 && !readhepmc)
    {
      cout << "using 0 for number of events is a bad idea when using particle generators" << endl;
      cout << "it will run forever, so I just return without running anything" << endl;
      return;
    }
  else
    {
      se->run(nEvents);
      se->End();
      std::cout << "All done" << std::endl;
     
      delete se;
      
      gROOT->LoadMacro("convert2eictree.C");
      convert2eictree(outputFileEICTree);

      gSystem->Load("libeicsmear");

      gROOT->LoadMacro("eic_sphenix.C");

      SmearTree(BuildEicSphenix(), outputFileEICSmear);

      std::remove(outputFileEICTree);
      //removeFile(outputFileEICTree);

      gSystem->Exit(0);
    }
}


void
G4Cmd(const char * cmd)
{
  Fun4AllServer *se = Fun4AllServer::instance();
  PHG4Reco *g4 = (PHG4Reco *) se->getSubsysReco("PHG4RECO");
  g4->ApplyCommand(cmd);
}
