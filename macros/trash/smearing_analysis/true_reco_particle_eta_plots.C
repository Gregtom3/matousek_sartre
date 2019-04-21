// Plots relevant eta distributions for DVMP

#include <vector>
int true_reco_particle_eta_plots()
{
  //----------------------------------------------------------------------------
  // Input File Names
  //----------------------------------------------------------------------------
  TString filename_mc_ep_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_ep_JPsi_ee_coherent_bNonSat_eictree.root";
			  
  TString filename_mc_smeared_ep_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/smearing_analysis/1M_Sartre_18x275_ep_JPsi_ee_coherent_bNonSat_eictree.smear.root";

  TString filename_mc_ep_coherent_bNonSat = "/sphenix/user/gregtom3/data/Fall2018/JPsi_reco_studies/18x275_JPsi_reco.root";
  
  TString filename_mc_smeared_ep_coherent_bNonSat = "/sphenix/user/gregtom3/data/Fall2018/JPsi_reco_studies/18x275_JPsi_reco.smear.root";

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

  //----------------------------------------------------------------------------
  // Load necessary eicsmear library
  //----------------------------------------------------------------------------
  
  gSystem->Load("libeicsmear");

  //----------------------------------------------------------------------------
  // Input TFiles from File Names
  //----------------------------------------------------------------------------
  
  TFile *file_mc_ep_coherent_bNonSat = new TFile(filename_mc_ep_coherent_bNonSat, "OPEN");
  TFile *file_mc_smeared_ep_coherent_bNonSat = new TFile(filename_mc_smeared_ep_coherent_bNonSat, "OPEN");
  TFile *file_mc_ep_coherent_bSat = new TFile(filename_mc_ep_coherent_bSat, "OPEN");
  TFile *file_mc_smeared_ep_coherent_bSat = new TFile(filename_mc_smeared_ep_coherent_bSat, "OPEN");
  
  TFile *file_mc_eAu_coherent_bNonSat = new TFile(filename_mc_eAu_coherent_bNonSat, "OPEN");
  TFile *file_mc_smeared_eAu_coherent_bNonSat = new TFile(filename_mc_smeared_eAu_coherent_bNonSat, "OPEN");
  TFile *file_mc_eAu_coherent_bSat = new TFile(filename_mc_eAu_coherent_bSat, "OPEN");
  TFile *file_mc_smeared_eAu_coherent_bSat = new TFile(filename_mc_smeared_eAu_coherent_bSat, "OPEN");

  TFile *file_mc_eAu_incoherent_bNonSat = new TFile(filename_mc_eAu_incoherent_bNonSat, "OPEN");
  TFile *file_mc_smeared_eAu_incoherent_bNonSat = new TFile(filename_mc_smeared_eAu_incoherent_bNonSat, "OPEN");
  TFile *file_mc_eAu_incoherent_bSat = new TFile(filename_mc_eAu_incoherent_bSat, "OPEN");
  TFile *file_mc_smeared_eAu_incoherent_bSat = new TFile(filename_mc_smeared_eAu_incoherent_bSat, "OPEN");
  
  //----------------------------------------------------------------------------
  // Input TTrees from TFiles
  //----------------------------------------------------------------------------
  
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

  //----------------------------------------------------------------------------
  // Events from EICTree and EICSmear
  //----------------------------------------------------------------------------
  erhic::EventMilou *event_ep_coherent_bNonSat  = NULL;
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

  //----------------------------------------------------------------------------
  // Branching events from tree
  //----------------------------------------------------------------------------

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

  //----------------------------------------------------------------------------
  // Create Eta Histogram of SCATTERED ELECTRON for ep_coherent_bNonSat
  //----------------------------------------------------------------------------

  TH1F *h1_eta_ep_coherent_bNonSat_true = new TH1F("h1_eta_ep_coherent_bNonSat_true","h1_eta_ep_coherent_bNonSat_true",100,-6,6);
  h1_eta_ep_coherent_bNonSat_true->SetLineColor(kBlack);
  TH1F *h1_eta_ep_coherent_bNonSat_reco = new TH1F("h1_eta_ep_coherent_bNonSat_reco","h1_eta_ep_coherent_bNonSat_reco",100,-6,6);
  h1_eta_ep_coherent_bNonSat_reco->SetLineColor(kRed);
  TH2F *h2_eta_ep_coherent_bNonSat_true_minus_reco = new TH2F("h2_eta_ep_coherent_bNonSat_true_minus_reco","h2_eta_ep_coherent_bNonSat_true_minus_reco",100,-6,6,100,-0.001,0.001);
  unsigned max_event = tree_smeared_ep_coherent_bNonSat->GetEntries();
  
  for ( unsigned ievent = 0; ievent < max_event/100; ievent++ )
    {
      if ( ievent%1000 == 0 )
        cout << "Processing event " << ievent << endl;

      /* load event */
      tree_ep_coherent_bNonSat->GetEntry(ievent);
      tree_smeared_ep_coherent_bNonSat->GetEntry(ievent);

     
      unsigned ntracks = eventS_ep_coherent_bNonSat->GetNTracks();
      
      for ( unsigned itrack = 0; itrack < ntracks; itrack++ )
        {
          Smear::ParticleMCS * sparticle = eventS_ep_coherent_bNonSat->GetTrack( itrack );
	  erhic::ParticleMC * tparticle = event_ep_coherent_bNonSat->GetTrack(itrack);
	  // Search for the scattered electron using truth info
	  if(tparticle->Id().Code()==-11)
	    {
	      if(sparticle!=NULL)
		{
		  cout << "Hello" << endl;
		  h2_eta_ep_coherent_bNonSat_true_minus_reco->Fill(tparticle->GetEta(),abs(tparticle->GetEta()-sparticle->GetEta()));
		}
	    }
	}
    }
  h2_eta_ep_coherent_bNonSat_true_minus_reco->Draw();
 
  return 0;
}
