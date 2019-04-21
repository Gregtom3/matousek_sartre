#include <stdio.h>
#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <fun4all/Fun4AllServer.h>
#include <fun4all/SubsysReco.h>
#include <phool/recoConsts.h>
#include <phsartre/PHSartre.h>
#include <phsartre/PHSartreParticleTrigger.h>
R__LOAD_LIBRARY(libg4testbench.so)
R__LOAD_LIBRARY(libPHSartre.so)
#endif

int Fun4All_MCEventGen(
                       const int nEvents = 100,
                       const char * outputFile = "100_sample.txt"
                       )
{
  //===============
  // Input options
  //===============
  
  // Use particle generator Sartre
  const bool runsartre = true;

  //---------------
  // Load libraries
  //---------------
  gSystem->Load("libfun4all.so");
  gSystem->Load("libphhepmc.so");
  gSystem->Load("libg4hough.so");
  gSystem->Load("libg4detectors.so");
  gSystem->Load("libg4testbench.so");
  gSystem->Load("libg4eval.so");
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

      PHSartre* mysartre = new PHSartre(outputFile);
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
  //-----------------
  // Event processing
  //-----------------
  if (nEvents <= 0)
    {
      cout << "using 0 for number of events is a bad idea when using particle generators" << endl;
      cout << "it will run forever, so I just return without running anything" << endl;
      return 0;
    }
  else
    {
      se->run(nEvents);
      se->End();
      std::cout << "All done" << std::endl;
     
      delete se;
      gSystem->Exit(0);
    }
  return 0;
}
/*
     gROOT->LoadMacro("convert2eictree.C");
      
      convert2eictree(outputFileEICTree);

      gSystem->Load("libeicsmear");

      

      SmearTree(BuildEicSphenix(), outputFileEICSmear);
      
      // put cross section into relevant tfile
      TFile *inputf=new TFile(outputFileText,"OPEN");
      TVectorD *v = (TVectorD*)inputf->Get("xsec");
      inputf->Close();
      TFile *outputf=new TFile(outputFileEICSmear,"UPDATE");
      v->Write("xsec");
      outputf->Close();
     
      std::remove(outputFileText);
      std::remove(outputFileEICTree);
      

      gSystem->Exit(0);
    }
  return 0;
}
*/
