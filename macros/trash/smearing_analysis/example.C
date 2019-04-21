// Plots relevant eta distributions for DVMP

#include <vector>
int true_reco_particle_eta_plots()
{
  /* Input file names */

  TString filename_mc_ep_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_ep_JPsi_ee_coherent_bNonSat_eictree.root";
			  
  TString filename_mc_smeared_ep_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_ep_JPsi_ee_coherent_bNonSat_eictree.smear.root";

   TString filename_mc_ep_coherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_ep_JPsi_ee_coherent_bSat_eictree.root";
			  
  TString filename_mc_smeared_ep_coherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_ep_JPsi_ee_coherent_bSat_eictree.smear.root";

   TString filename_mc_eAu_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_eAu_JPsi_ee_coherent_bNonSat_eictree.root";
			  
  TString filename_mc_smeared_eAu_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_eAu_JPsi_ee_coherent_bNonSat_eictree.smear.root";

  TString filename_mc_eAu_coherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_eAu_JPsi_ee_coherent_bSat_eictree.root";
			  
  TString filename_mc_smeared_eAu_coherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_eAu_JPsi_ee_coherent_bSat_eictree.smear.root";
  
   TString filename_mc_eAu_incoherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/50k_Sartre_18x275_eAu_JPsi_ee_incoherent_bNonSat_eictree.root";
			  
  TString filename_mc_smeared_eAu_incoherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/50k_Sartre_18x275_eAu_JPsi_ee_incoherent_bNonSat_eictree.smear.root";

  TString filename_mc_eAu_incoherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/50k_Sartre_18x275_eAu_JPsi_ee_incoherent_bSat_eictree.root";
			  
  TString filename_mc_smeared_eAu_incoherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/50k_Sartre_18x275_eAu_JPsi_ee_incoherent_bSat_eictree.smear.root";

  /* Loading libraries */
  gSystem->Load("libeicsmear");

  /* Input TFiles */
  /* ep TFiles*/
  TFile *file_mc_ep_coherent_bNonSat = new TFile(filename_mc_ep_coherent_bNonSat, "OPEN");
  TFile *file_mc_smeared_ep_coherent_bNonSat = new TFile(filename_mc_smeared_ep_coherent_bNonSat, "OPEN");
  TFile *file_mc_ep_coherent_bSat = new TFile(filename_mc_ep_coherent_bSat, "OPEN");
  TFile *file_mc_smeared_ep_coherent_bSat = new TFile(filename_mc_smeared_ep_coherent_bSat, "OPEN");
  
  /* eAu coherent TFiles */
  TFile *file_mc_eAu_coherent_bNonSat = new TFile(filename_mc_eAu_coherent_bNonSat, "OPEN");
  TFile *file_mc_smeared_eAu_coherent_bNonSat = new TFile(filename_mc_smeared_eAu_coherent_bNonSat, "OPEN");
  TFile *file_mc_eAu_coherent_bSat = new TFile(filename_mc_eAu_coherent_bSat, "OPEN");
  TFile *file_mc_smeared_eAu_coherent_bSat = new TFile(filename_mc_smeared_eAu_coherent_bSat, "OPEN");

  /* eAu incoherent TFiles */
  TFile *file_mc_eAu_incoherent_bNonSat = new TFile(filename_mc_eAu_incoherent_bNonSat, "OPEN");
  TFile *file_mc_smeared_eAu_incoherent_bNonSat = new TFile(filename_mc_smeared_eAu_incoherent_bNonSat, "OPEN");
  TFile *file_mc_eAu_incoherent_bSat = new TFile(filename_mc_eAu_incoherent_bSat, "OPEN");
  TFile *file_mc_smeared_eAu_incoherent_bSat = new TFile(filename_mc_smeared_eAu_incoherent_bSat, "OPEN");
  
  /* Input TTrees */
  TTree *tree_ep_coherent_bNonSat = (TTree*)file_mc_ep_coherent_bNonSat->Get("EICTree");
  TTree *tree_smeared_ep_coherent_bNonSat= (TTree*)file_mc_smeared_ep_coherent_bNonSat->Get("Smeared");
  TTree *tree_ep_coherent_bSat = (TTree*)file_mc_ep_coherent_bSat->Get("EICTree");
  TTree *tree_smeared_ep_coherent_bSat= (TTree*)file_mc_smeared_ep_coherent_bSat->Get("Smeared");

  TTree *tree_eAu_coherent_bNonSat = (TTree*)file_mc_eAu_coherent_bNonSat->Get("EICTree");
  TTree *tree_smeared_eAu_coherent_bNonSat= (TTree*)file_mc_smeared_eAu_coherent_bNonSat->Get("Smeared");
  TTree *tree_eAu_coherent_bSat = (TTree*)file_mc_eAu_coherent_bSat->Get("EICTree");
  TTree *tree_smeared_eAu_coherent_bSat= (TTree*)file_mc_smeared_eAu_coherent_bSat->Get("Smeared");

  TTree *tree_eAu_incoherent_bNonSat = (TTree*)file_mc_eAu_incoherent_bNonSat->Get("EICTree");
  TTree *tree_smeared_eAu_incoherent_bNonSat= (TTree*)file_mc_smeared_eAu_incoherent_bNonSat->Get("Smeared");
  TTree *tree_eAu_incoherent_bSat = (TTree*)file_mc_eAu_incoherent_bSat->Get("EICTree");
  TTree *tree_smeared_eAu_incoherent_bSat= (TTree*)file_mc_smeared_eAu_incoherent_bSat->Get("Smeared");

  /* Get Events from EICTree and eic-smear */
  erhic::EventPythia *event_ep_coherent_bNonSat  = NULL;
  Smear::Event       *eventS_ep_coherent_bNonSat = NULL;
  erhic::EventPythia *event_ep_coherent_bSat  = NULL;
  Smear::Event       *eventS_ep_coherent_bSat = NULL;

  erhic::EventPythia *event_eAu_coherent_bNonSat  = NULL;
  Smear::Event       *eventS_eAu_coherent_bNonSat = NULL;
  erhic::EventPythia *event_eAu_coherent_bSat  = NULL;
  Smear::Event       *eventS_eAu_coherent_bSat = NULL;

  erhic::EventPythia *event_eAu_incoherent_bNonSat  = NULL;
  Smear::Event       *eventS_eAu_incoherent_bNonSat = NULL;
  erhic::EventPythia *event_eAu_incoherent_bSat  = NULL;
  Smear::Event       *eventS_eAu_incoherent_bSat = NULL;

  tree_ep_coherent_bNonSat->SetBranchAddress("event",&event_ep_coherent_bNonSat);
  tree_smeared_ep_coherent_bNonSat->SetBranchAddress("eventS", &eventS_ep_coherent_bNonSat);
  tree_ep_coherent_bSat->SetBranchAddress("event",&event_ep_coherent_bSat);
  tree_smeared_ep_coherent_bSat->SetBranchAddress("eventS", &eventS_ep_coherent_bSat);

  tree_eAu_coherent_bNonSat->SetBranchAddress("event",&event_eAu_coherent_bNonSat);
  tree_smeared_eAu_coherent_bNonSat->SetBranchAddress("eventS", &eventS_eAu_coherent_bNonSat);
  tree_eAu_coherent_bSat->SetBranchAddress("event",&event_eAu_coherent_bSat);
  tree_smeared_eAu_coherent_bSat->SetBranchAddress("eventS", &eventS_eAu_coherent_bSat);

  tree_eAu_incoherent_bNonSat->SetBranchAddress("event",&event_eAu_incoherent_bNonSat);
  tree_smeared_eAu_incoherent_bNonSat->SetBranchAddress("eventS", &eventS_eAu_incoherent_bNonSat);
  tree_eAu_incoherent_bSat->SetBranchAddress("event",&event_eAu_incoherent_bSat);
  tree_smeared_eAu_incoherent_bSat->SetBranchAddress("eventS", &eventS_eAu_incoherent_bSat);

   unsigned max_event = tree_smeared->GetEntries();
  
  for ( unsigned ievent = 0; ievent < max_event; ievent++ )
    {
      if ( ievent%1000 == 0 )
        cout << "Processing event " << ievent << endl;

      /* load event */
      tree->GetEntry(ievent);
      tree_smeared->GetEntry(ievent);

     
      unsigned ntracks = eventS->GetNTracks();
      cout << event->GetTrueX() << endl; 
	/*for ( unsigned itrack = 0; itrack < ntracks; itrack++ )
        {
          Smear::ParticleMCS * sparticle = eventS->GetTrack( itrack );
	  erhic::ParticleMC * tparticle = event->GetTrack(itrack);

	  
	  }*/
    }

      
  

    


  

  myfile->Write();
  myfile->Close();
  return 0;
}

Double_t mybw(Double_t* x, Double_t* par)
{
  Double_t arg1 = 14.0/22.0; // 2 over pi
  Double_t arg2 = par[1]*par[1]*par[2]*par[2]; //Gamma=par[1]  M=par[2]
  Double_t arg3 = ((x[0]*x[0]) - (par[2]*par[2]))*((x[0]*x[0]) - (par[2]*par[2]));
  Double_t arg4 = x[0]*x[0]*x[0]*x[0]*((par[1]*par[1])/(par[2]*par[2]));
  return par[0]*arg1*arg2/(arg3 + arg4);
}
