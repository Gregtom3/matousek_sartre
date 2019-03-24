// Plots relevant eta distributions for DVMP

#include <vector>
int true_reco_particle_eta_plots(
                                 TString infile_eictree = "test_eictree.root",
				 TString infile_eicsmear = "test_eictree.smear.root",
				 TString outfilename = "out.root"
                                 )
{

  //----------------------------------------------------------------------------
  // Load necessary eicsmear library
  //----------------------------------------------------------------------------
  
  gSystem->Load("libeicsmear");

  //----------------------------------------------------------------------------
  // Input TFiles from File Names
  //----------------------------------------------------------------------------
  
  TFile *file_mc = new TFile(infile_eictree, "OPEN");
  TFile *file_mc_smeared = new TFile(infile_eicsmear, "OPEN");
 
  //----------------------------------------------------------------------------
  // Input TTrees from TFiles
  //----------------------------------------------------------------------------
  
  TTree *tree = (TTree*)file_mc->Get("EICTree");
  TTree *tree_smeared= (TTree*)file_mc_smeared->Get("Smeared");
 

  //----------------------------------------------------------------------------
  // Events from EICTree and EICSmear
  //----------------------------------------------------------------------------
  
  erhic::EventPythia *event  = NULL;
  Smear::Event       *eventS = NULL;
 
  //----------------------------------------------------------------------------
  // Branching events from tree
  //----------------------------------------------------------------------------

  tree->SetBranchAddress("event",&event);
  tree_smeared->SetBranchAddress("eventS", &eventS);
  
  //----------------------------------------------------------------------------
  // Output TFile
  //----------------------------------------------------------------------------

  TFile *out_file = new TFile(outfilename,"RECREATE");
  TTree *out_tree = new TTree("event","Tree filled with info from EICTree and EICSmear");
  
  //----------------------------------------------------------------------------
  // Truth Event-Wise Variables
  //----------------------------------------------------------------------------

  double true_x;
  double true_y;
  double true_Q2;
  double true_W2;
  double true_s;
  double true_t;

  //----------------------------------------------------------------------------
  // Truth Particle Info
  //----------------------------------------------------------------------------

  /* Incoming Beam Particles */
  double true_beam_lepton_px, true_beam_lepton_py, true_beam_lepton_pz, true_beam_lepton_pt, true_beam_lepton_p, true_beam_lepton_phi, true_beam_lepton_theta, true_beam_lepton_eta, true_beam_lepton_id;

  double true_beam_hadron_px, true_beam_hadron_py, true_beam_hadron_pz, true_beam_hadron_pt, true_beam_hadron_p, true_beam_hadron_phi, true_beam_hadron_theta, true_beam_hadron_eta, true_beam_hadron_id;

  /* Outgoing Scattered Particles */
  double true_scattered_lepton_px, true_scattered_lepton_py, true_scattered_lepton_pz, true_scattered_lepton_pt, true_scattered_lepton_p, true_scattered_lepton_phi, true_scattered_lepton_theta, true_scattered_lepton_eta, true_scattered_lepton_id;

  double true_scattered_hadron_px, true_scattered_hadron_py, true_scattered_hadron_pz, true_scattered_hadron_pt, true_scattered_hadron_p, true_scattered_hadron_phi, true_scattered_hadron_theta, true_scattered_hadron_eta, true_scattered_hadron_id;

  /* Outgoing Vector Meson Particles */
  
   double true_decayed_electron_px, true_decayed_electron_py, true_decayed_electron_pz, true_decayed_electron_pt, true_decayed_electron_p, true_decayed_electron_phi, true_decayed_electron_theta, true_decayed_electron_eta, true_decayed_electron_id;

  double true_decayed_positron_px, true_decayed_positron_py, true_decayed_positron_pz, true_decayed_positron_pt, true_decayed_positron_p, true_decayed_positron_phi, true_decayed_positron_theta, true_decayed_positron_eta, true_decayed_positron_id;

  /* Outgoing Nuclear Breakup Particles */
  std::vector<double> true_breakup_px, true_breakup_py, true_breakup_pz, true_breakup_pt, true_breakup_p, true_breakup_phi, true_breakup_theta, true_breakup_eta, true_breakup_id;
  //----------------------------------------------------------------------------
  // Reco Event-Wise Variables
  //----------------------------------------------------------------------------

  double reco_x;
  double reco_y;
  double reco_Q2;
  double reco_t;

  //----------------------------------------------------------------------------
  // Reco Particle Info
  //----------------------------------------------------------------------------

  /* Incoming Beam Particles */
  double reco_beam_lepton_px, reco_beam_lepton_py, reco_beam_lepton_pz, reco_beam_lepton_pt, reco_beam_lepton_p, reco_beam_lepton_phi, reco_beam_lepton_theta, reco_beam_lepton_eta, reco_beam_lepton_id;

  double reco_beam_hadron_px, reco_beam_hadron_py, reco_beam_hadron_pz, reco_beam_hadron_pt, reco_beam_hadron_p, reco_beam_hadron_phi, reco_beam_hadron_theta, reco_beam_hadron_eta, reco_beam_hadron_id;

  /* Outgoing Scattered Particles */
  double reco_scattered_lepton_px, reco_scattered_lepton_py, reco_scattered_lepton_pz, reco_scattered_lepton_pt, reco_scattered_lepton_p, reco_scattered_lepton_phi, reco_scattered_lepton_theta, reco_scattered_lepton_eta, reco_scattered_lepton_id;

  double reco_scattered_hadron_px, reco_scattered_hadron_py, reco_scattered_hadron_pz, reco_scattered_hadron_pt, reco_scattered_hadron_p, reco_scattered_hadron_phi, reco_scattered_hadron_theta, reco_scattered_hadron_eta, reco_scattered_hadron_id;

  /* Outgoing Vector Meson Particles */
  
  double reco_decayed_electron_px, reco_decayed_electron_py, reco_decayed_electron_pz, reco_decayed_electron_pt, reco_decayed_electron_p, reco_decayed_electron_phi, reco_decayed_electron_theta, reco_decayed_electron_eta, reco_decayed_electron_id;

  double reco_decayed_positron_px, reco_decayed_positron_py, reco_decayed_positron_pz, reco_decayed_positron_pt, reco_decayed_positron_p, reco_decayed_positron_phi, reco_decayed_positron_theta, reco_decayed_positron_eta, reco_decayed_positron_id;

  //----------------------------------------------------------------------------
  // True Tree Branching
  //----------------------------------------------------------------------------

  out_tree->Branch("true_x",&true_x);
  out_tree->Branch("true_y",&true_y);
  out_tree->Branch("true_Q2",&true_Q2);
  out_tree->Branch("true_W2",&true_W2);
  out_tree->Branch("true_s",&true_s);
  out_tree->Branch("true_t",&true_t);
 
  out_tree->Branch("true_beam_lepton_px",&true_beam_lepton_px);
  out_tree->Branch("true_beam_lepton_py",&true_beam_lepton_py);
  out_tree->Branch("true_beam_lepton_pz",&true_beam_lepton_pz);
  out_tree->Branch("true_beam_lepton_pt",&true_beam_lepton_pt);
  out_tree->Branch("true_beam_lepton_p",&true_beam_lepton_p);
  out_tree->Branch("true_beam_lepton_phi",&true_beam_lepton_phi);
  out_tree->Branch("true_beam_lepton_theta",&true_beam_lepton_theta);
  out_tree->Branch("true_beam_lepton_eta",&true_beam_lepton_eta);
  out_tree->Branch("true_beam_lepton_id",&true_beam_lepton_id);

  out_tree->Branch("true_beam_hadron_px",&true_beam_hadron_px);
  out_tree->Branch("true_beam_hadron_py",&true_beam_hadron_py);
  out_tree->Branch("true_beam_hadron_pz",&true_beam_hadron_pz);
  out_tree->Branch("true_beam_hadron_pt",&true_beam_hadron_pt);
  out_tree->Branch("true_beam_hadron_p",&true_beam_hadron_p);
  out_tree->Branch("true_beam_hadron_phi",&true_beam_hadron_phi);
  out_tree->Branch("true_beam_hadron_theta",&true_beam_hadron_theta);
  out_tree->Branch("true_beam_hadron_eta",&true_beam_hadron_eta);
  out_tree->Branch("true_beam_hadron_id",&true_beam_hadron_id);

  out_tree->Branch("true_scattered_lepton_px",&true_scattered_lepton_px);
  out_tree->Branch("true_scattered_lepton_py",&true_scattered_lepton_py);
  out_tree->Branch("true_scattered_lepton_pz",&true_scattered_lepton_pz);
  out_tree->Branch("true_scattered_lepton_pt",&true_scattered_lepton_pt);
  out_tree->Branch("true_scattered_lepton_p",&true_scattered_lepton_p);
  out_tree->Branch("true_scattered_lepton_phi",&true_scattered_lepton_phi);
  out_tree->Branch("true_scattered_lepton_theta",&true_scattered_lepton_theta);
  out_tree->Branch("true_scattered_lepton_eta",&true_scattered_lepton_eta);
  out_tree->Branch("true_scattered_lepton_id",&true_scattered_lepton_id);

  out_tree->Branch("true_scattered_hadron_px",&true_scattered_hadron_px);
  out_tree->Branch("true_scattered_hadron_py",&true_scattered_hadron_py);
  out_tree->Branch("true_scattered_hadron_pz",&true_scattered_hadron_pz);
  out_tree->Branch("true_scattered_hadron_pt",&true_scattered_hadron_pt);
  out_tree->Branch("true_scattered_hadron_p",&true_scattered_hadron_p);
  out_tree->Branch("true_scattered_hadron_phi",&true_scattered_hadron_phi);
  out_tree->Branch("true_scattered_hadron_theta",&true_scattered_hadron_theta);
  out_tree->Branch("true_scattered_hadron_eta",&true_scattered_hadron_eta);
  out_tree->Branch("true_scattered_hadron_id",&true_scattered_hadron_id);

  out_tree->Branch("true_decayed_electron_px",&true_decayed_electron_px);
  out_tree->Branch("true_decayed_electron_py",&true_decayed_electron_py);
  out_tree->Branch("true_decayed_electron_pz",&true_decayed_electron_pz);
  out_tree->Branch("true_decayed_electron_pt",&true_decayed_electron_pt);
  out_tree->Branch("true_decayed_electron_p",&true_decayed_electron_p);
  out_tree->Branch("true_decayed_electron_phi",&true_decayed_electron_phi);
  out_tree->Branch("true_decayed_electron_theta",&true_decayed_electron_theta);
  out_tree->Branch("true_decayed_electron_eta",&true_decayed_electron_eta);
  out_tree->Branch("true_decayed_electron_id",&true_decayed_electron_id);

  out_tree->Branch("true_decayed_positron_px",&true_decayed_positron_px);
  out_tree->Branch("true_decayed_positron_py",&true_decayed_positron_py);
  out_tree->Branch("true_decayed_positron_pz",&true_decayed_positron_pz);
  out_tree->Branch("true_decayed_positron_pt",&true_decayed_positron_pt);
  out_tree->Branch("true_decayed_positron_p",&true_decayed_positron_p);
  out_tree->Branch("true_decayed_positron_phi",&true_decayed_positron_phi);
  out_tree->Branch("true_decayed_positron_theta",&true_decayed_positron_theta);
  out_tree->Branch("true_decayed_positron_eta",&true_decayed_positron_eta);
  out_tree->Branch("true_decayed_positron_id",&true_decayed_positron_id);

  out_tree->Branch("true_breakup_px",&true_breakup_px);
  out_tree->Branch("true_breakup_py",&true_breakup_py);
  out_tree->Branch("true_breakup_pz",&true_breakup_pz);
  out_tree->Branch("true_breakup_pt",&true_breakup_pt);
  out_tree->Branch("true_breakup_p",&true_breakup_p);
  out_tree->Branch("true_breakup_phi",&true_breakup_phi);
  out_tree->Branch("true_breakup_theta",&true_breakup_theta);
  out_tree->Branch("true_breakup_eta",&true_breakup_eta);
  out_tree->Branch("true_breakup_id",&true_breakup_id);

  //----------------------------------------------------------------------------
  // Reco Tree Branching
  //----------------------------------------------------------------------------

  out_tree->Branch("reco_x",&reco_x);
  out_tree->Branch("reco_y",&reco_y);
  out_tree->Branch("reco_Q2",&reco_Q2);
  out_tree->Branch("reco_t",&reco_t);

  out_tree->Branch("reco_beam_lepton_px",&reco_beam_lepton_px);
  out_tree->Branch("reco_beam_lepton_py",&reco_beam_lepton_py);
  out_tree->Branch("reco_beam_lepton_pz",&reco_beam_lepton_pz);
  out_tree->Branch("reco_beam_lepton_pt",&reco_beam_lepton_pt);
  out_tree->Branch("reco_beam_lepton_p",&reco_beam_lepton_p);
  out_tree->Branch("reco_beam_lepton_phi",&reco_beam_lepton_phi);
  out_tree->Branch("reco_beam_lepton_theta",&reco_beam_lepton_theta);
  out_tree->Branch("reco_beam_lepton_eta",&reco_beam_lepton_eta);
  out_tree->Branch("reco_beam_lepton_id",&reco_beam_lepton_id);

  out_tree->Branch("reco_beam_hadron_px",&reco_beam_hadron_px);
  out_tree->Branch("reco_beam_hadron_py",&reco_beam_hadron_py);
  out_tree->Branch("reco_beam_hadron_pz",&reco_beam_hadron_pz);
  out_tree->Branch("reco_beam_hadron_pt",&reco_beam_hadron_pt);
  out_tree->Branch("reco_beam_hadron_p",&reco_beam_hadron_p);
  out_tree->Branch("reco_beam_hadron_phi",&reco_beam_hadron_phi);
  out_tree->Branch("reco_beam_hadron_theta",&reco_beam_hadron_theta);
  out_tree->Branch("reco_beam_hadron_eta",&reco_beam_hadron_eta);
  out_tree->Branch("reco_beam_hadron_id",&reco_beam_hadron_id);

  out_tree->Branch("reco_scattered_lepton_px",&reco_scattered_lepton_px);
  out_tree->Branch("reco_scattered_lepton_py",&reco_scattered_lepton_py);
  out_tree->Branch("reco_scattered_lepton_pz",&reco_scattered_lepton_pz);
  out_tree->Branch("reco_scattered_lepton_pt",&reco_scattered_lepton_pt);
  out_tree->Branch("reco_scattered_lepton_p",&reco_scattered_lepton_p);
  out_tree->Branch("reco_scattered_lepton_phi",&reco_scattered_lepton_phi);
  out_tree->Branch("reco_scattered_lepton_theta",&reco_scattered_lepton_theta);
  out_tree->Branch("reco_scattered_lepton_eta",&reco_scattered_lepton_eta);
  out_tree->Branch("reco_scattered_lepton_id",&reco_scattered_lepton_id);

  out_tree->Branch("reco_scattered_hadron_px",&reco_scattered_hadron_px);
  out_tree->Branch("reco_scattered_hadron_py",&reco_scattered_hadron_py);
  out_tree->Branch("reco_scattered_hadron_pz",&reco_scattered_hadron_pz);
  out_tree->Branch("reco_scattered_hadron_pt",&reco_scattered_hadron_pt);
  out_tree->Branch("reco_scattered_hadron_p",&reco_scattered_hadron_p);
  out_tree->Branch("reco_scattered_hadron_phi",&reco_scattered_hadron_phi);
  out_tree->Branch("reco_scattered_hadron_theta",&reco_scattered_hadron_theta);
  out_tree->Branch("reco_scattered_hadron_eta",&reco_scattered_hadron_eta);
  out_tree->Branch("reco_scattered_hadron_id",&reco_scattered_hadron_id);

  out_tree->Branch("reco_decayed_electron_px",&reco_decayed_electron_px);
  out_tree->Branch("reco_decayed_electron_py",&reco_decayed_electron_py);
  out_tree->Branch("reco_decayed_electron_pz",&reco_decayed_electron_pz);
  out_tree->Branch("reco_decayed_electron_pt",&reco_decayed_electron_pt);
  out_tree->Branch("reco_decayed_electron_p",&reco_decayed_electron_p);
  out_tree->Branch("reco_decayed_electron_phi",&reco_decayed_electron_phi);
  out_tree->Branch("reco_decayed_electron_theta",&reco_decayed_electron_theta);
  out_tree->Branch("reco_decayed_electron_eta",&reco_decayed_electron_eta);
  out_tree->Branch("reco_decayed_electron_id",&reco_decayed_electron_id);

  out_tree->Branch("reco_decayed_positron_px",&reco_decayed_positron_px);
  out_tree->Branch("reco_decayed_positron_py",&reco_decayed_positron_py);
  out_tree->Branch("reco_decayed_positron_pz",&reco_decayed_positron_pz);
  out_tree->Branch("reco_decayed_positron_pt",&reco_decayed_positron_pt);
  out_tree->Branch("reco_decayed_positron_p",&reco_decayed_positron_p);
  out_tree->Branch("reco_decayed_positron_phi",&reco_decayed_positron_phi);
  out_tree->Branch("reco_decayed_positron_theta",&reco_decayed_positron_theta);
  out_tree->Branch("reco_decayed_positron_eta",&reco_decayed_positron_eta);
  out_tree->Branch("reco_decayed_positron_id",&reco_decayed_positron_id);

  unsigned max_event = tree_smeared->GetEntries();
  
  for ( unsigned ievent = 0; ievent < max_event; ievent++ )
    {
      /* Cout Statement for Progress */
      if ( ievent%1000 == 0 )
	{
	  cout << "Processing event " << ievent << endl;
	}
      
      /* load event */
      tree->GetEntry(ievent);
      tree_smeared->GetEntry(ievent);

      unsigned ntracks = eventS->GetNTracks();
      
      // Assume all Smeared Particles are not findable
       reco_beam_lepton_px=NULL;
       reco_beam_lepton_py=NULL;
       reco_beam_lepton_pz=NULL;
       reco_beam_lepton_pt=NULL;
       reco_beam_lepton_p=NULL;
       reco_beam_lepton_phi=NULL;
       reco_beam_lepton_theta=NULL;
       reco_beam_lepton_eta=NULL;
       reco_beam_lepton_id=NULL;
       
       reco_beam_hadron_px=NULL;
       reco_beam_hadron_py=NULL;
       reco_beam_hadron_pz=NULL;
       reco_beam_hadron_pt=NULL;
       reco_beam_hadron_p=NULL;
       reco_beam_hadron_phi=NULL;
       reco_beam_hadron_theta=NULL;
       reco_beam_hadron_eta=NULL;
       reco_beam_hadron_id=NULL;
       
       reco_scattered_lepton_px=NULL;
       reco_scattered_lepton_py=NULL;
       reco_scattered_lepton_pz=NULL;
       reco_scattered_lepton_pt=NULL;
       reco_scattered_lepton_p=NULL;
       reco_scattered_lepton_phi=NULL;
       reco_scattered_lepton_theta=NULL;
       reco_scattered_lepton_eta=NULL;
       reco_scattered_lepton_id=NULL;
       
       reco_scattered_hadron_px=NULL;
       reco_scattered_hadron_py=NULL;
       reco_scattered_hadron_pz=NULL;
       reco_scattered_hadron_pt=NULL;
       reco_scattered_hadron_p=NULL;
       reco_scattered_hadron_phi=NULL;
       reco_scattered_hadron_theta=NULL;
       reco_scattered_hadron_eta=NULL;
       reco_scattered_hadron_id=NULL;
       
       reco_decayed_electron_px=NULL;
       reco_decayed_electron_py=NULL;
       reco_decayed_electron_pz=NULL;
       reco_decayed_electron_pt=NULL;
       reco_decayed_electron_p=NULL;
       reco_decayed_electron_phi=NULL;
       reco_decayed_electron_theta=NULL;
       reco_decayed_electron_eta=NULL;
       reco_decayed_electron_id=NULL;
       
       reco_decayed_positron_px=NULL;
       reco_decayed_positron_py=NULL;
       reco_decayed_positron_pz=NULL;
       reco_decayed_positron_pt=NULL;
       reco_decayed_positron_p=NULL;
       reco_decayed_positron_phi=NULL;
       reco_decayed_positron_theta=NULL;
       reco_decayed_positron_eta=NULL;
       reco_decayed_positron_id=NULL;
       
       for ( unsigned itrack = 0; itrack < ntracks; itrack++ )
	 {
	   Smear::ParticleMCS * sparticle = eventS->GetTrack( itrack );
	   erhic::ParticleMC * tparticle = event->GetTrack(itrack);

	  // Quick test to see if the particle was smeared
	  bool is_smeared = (sparticle!=NULL);

	  /* -------------------------------------
	     Particle Searching Using Truth Info
	     ------------------------------------- */

	  // Beam Lepton
	  if(tparticle->Id().Code()==11&&tparticle->GetStatus()==21)
	    {
	      true_beam_lepton_px=tparticle->GetPx();
	      true_beam_lepton_py=tparticle->GetPy();
	      true_beam_lepton_pz=tparticle->GetPz();
	      true_beam_lepton_pt=tparticle->GetPt();
	      true_beam_lepton_p=tparticle->GetP();
	      true_beam_lepton_phi=tparticle->GetPhi();
	      true_beam_lepton_theta=tparticle->GetTheta();
	      true_beam_lepton_eta=tparticle->GetEta();
	      true_beam_lepton_id=11;

	      // Fill Smeared Particle Info if Particle is Found
	      if(is_smeared)
		{
		  reco_beam_lepton_px=sparticle->GetPx();
		  reco_beam_lepton_py=sparticle->GetPy();
		  reco_beam_lepton_pz=sparticle->GetPz();
		  reco_beam_lepton_pt=sparticle->GetPt();
		  reco_beam_lepton_p=sparticle->GetP();
		  reco_beam_lepton_phi=atan(reco_beam_lepton_py/reco_beam_lepton_px);
		  reco_beam_lepton_theta=atan(reco_beam_lepton_pt/reco_beam_lepton_pz);
		  if(reco_beam_lepton_theta>0)
		    {
		      reco_beam_lepton_eta=-log((tan(reco_beam_lepton_theta/2)));
		    }
		  else
		    {
		      reco_beam_lepton_eta=-log(-(tan(reco_beam_lepton_theta/2)));
		    }
		}
	    }

	  // Beam Hadron
	  if(tparticle->Id().Code()!=11&&tparticle->Id().Code()!=22&&tparticle->GetStatus()==21)
	    {
	      true_beam_hadron_px=tparticle->GetPx();
	      true_beam_hadron_py=tparticle->GetPy();
	      true_beam_hadron_pz=tparticle->GetPz();
	      true_beam_hadron_pt=tparticle->GetPt();
	      true_beam_hadron_p=tparticle->GetP();
	      true_beam_hadron_phi=tparticle->GetPhi();
	      true_beam_hadron_theta=tparticle->GetTheta();
	      true_beam_hadron_eta=tparticle->GetEta();
	      true_beam_hadron_id=tparticle->Id().Code();

	      // Fill Smeared Particle Info if Particle is Found
	      if(is_smeared)
		{
		  reco_beam_hadron_px=sparticle->GetPx();
		  reco_beam_hadron_py=sparticle->GetPy();
		  reco_beam_hadron_pz=sparticle->GetPz();
		  reco_beam_hadron_pt=sparticle->GetPt();
		  reco_beam_hadron_p=sparticle->GetP();
		  reco_beam_hadron_phi=atan(reco_beam_hadron_py/reco_beam_hadron_px);
		  reco_beam_hadron_theta=atan(reco_beam_hadron_pt/reco_beam_hadron_pz);
		  if(reco_beam_hadron_theta>0)
		    {
		      reco_beam_hadron_eta=-log((tan(reco_beam_hadron_theta/2)));
		    }
		  else
		    {
		      reco_beam_hadron_eta=-log(-(tan(reco_beam_hadron_theta/2)));
		    }
		}
	    }

	  // Scattered Lepton
	  if(tparticle->Id().Code()==11&&tparticle->GetStatus()==1&&tparticle->GetParentIndex()==3)
	    {
	      true_scattered_lepton_px=tparticle->GetPx();
	      true_scattered_lepton_py=tparticle->GetPy();
	      true_scattered_lepton_pz=tparticle->GetPz();
	      true_scattered_lepton_pt=tparticle->GetPt();
	      true_scattered_lepton_p=tparticle->GetP();
	      true_scattered_lepton_phi=tparticle->GetPhi();
	      true_scattered_lepton_theta=tparticle->GetTheta();
	      true_scattered_lepton_eta=tparticle->GetEta();
	      true_scattered_lepton_id=11;
	      
	      // Fill Smeared Particle Info if Particle is Found
	      if(is_smeared)
		{
		  reco_scattered_lepton_px=sparticle->GetPx();
		  reco_scattered_lepton_py=sparticle->GetPy();
		  reco_scattered_lepton_pz=sparticle->GetPz();
		  reco_scattered_lepton_pt=sparticle->GetPt();
		  reco_scattered_lepton_p=sparticle->GetP();
		  reco_scattered_lepton_phi=atan(reco_scattered_lepton_py/reco_scattered_lepton_px);
		  reco_scattered_lepton_theta=atan(reco_scattered_lepton_pt/reco_scattered_lepton_pz);
		  if(reco_scattered_lepton_theta>0)
		    {
		      reco_scattered_lepton_eta=-log((tan(reco_scattered_lepton_theta/2)));
		    }
		  else
		    {
		      reco_scattered_lepton_eta=-log(-(tan(reco_scattered_lepton_theta/2)));
		    }
		}
	    }

	   // Scattered Hadron 
	  if(tparticle->GetParentIndex()==1)
	    {
	      true_scattered_hadron_px=tparticle->GetPx();
	      true_scattered_hadron_py=tparticle->GetPy();
	      true_scattered_hadron_pz=tparticle->GetPz();
	      true_scattered_hadron_pt=tparticle->GetPt();
	      true_scattered_hadron_p=tparticle->GetP();
	      true_scattered_hadron_phi=tparticle->GetPhi();
	      true_scattered_hadron_theta=tparticle->GetTheta();
	      true_scattered_hadron_eta=tparticle->GetEta();
	      true_scattered_hadron_id=tparticle->Id().Code();
	      
	      // Fill Smeared Particle Info if Particle is Found
	      if(is_smeared)
		{
		  reco_scattered_hadron_px=sparticle->GetPx();
		  reco_scattered_hadron_py=sparticle->GetPy();
		  reco_scattered_hadron_pz=sparticle->GetPz();
		  reco_scattered_hadron_pt=sparticle->GetPt();
		  reco_scattered_hadron_p=sparticle->GetP();
		  reco_scattered_hadron_phi=atan(reco_scattered_hadron_py/reco_scattered_hadron_px);
		  reco_scattered_hadron_theta=atan(reco_scattered_hadron_pt/reco_scattered_hadron_pz);
		  if(reco_scattered_hadron_theta>0)
		    {
		      reco_scattered_hadron_eta=-log((tan(reco_scattered_hadron_theta/2)));
		    }
		  else
		    {
		      reco_scattered_hadron_eta=-log(-(tan(reco_scattered_hadron_theta/2)));
		    }
		}
	    }

	  // Decayed Electron
	  if(tparticle->Id().Code()==11&&tparticle->GetStatus()==1&&tparticle->GetParentIndex()!=3)
	    {
	      true_decayed_electron_px=tparticle->GetPx();
	      true_decayed_electron_py=tparticle->GetPy();
	      true_decayed_electron_pz=tparticle->GetPz();
	      true_decayed_electron_pt=tparticle->GetPt();
	      true_decayed_electron_p=tparticle->GetP();
	      true_decayed_electron_phi=tparticle->GetPhi();
	      true_decayed_electron_theta=tparticle->GetTheta();
	      true_decayed_electron_eta=tparticle->GetEta();
	      true_decayed_electron_id=11;

	      // Fill Smeared Particle Info if Particle is Found
	      if(is_smeared)
		{
		  reco_decayed_electron_px=sparticle->GetPx();
		  reco_decayed_electron_py=sparticle->GetPy();
		  reco_decayed_electron_pz=sparticle->GetPz();
		  reco_decayed_electron_pt=sparticle->GetPt();
		  reco_decayed_electron_p=sparticle->GetP();
		  reco_decayed_electron_phi=atan(reco_decayed_electron_py/reco_decayed_electron_px);
		  reco_decayed_electron_theta=atan(reco_decayed_electron_pt/reco_decayed_electron_pz);
		  if(reco_decayed_electron_theta>0)
		    {
		      reco_decayed_electron_eta=-log((tan(reco_decayed_electron_theta/2)));
		    }
		  else
		    {
		      reco_decayed_electron_eta=-log(-(tan(reco_decayed_electron_theta/2)));
		    }
		}
	    }

	  // Decayed Positron
	  if(tparticle->Id().Code()==-11&&tparticle->GetStatus()==1&&tparticle->GetParentIndex()!=3)
	    {
	      true_decayed_positron_px=tparticle->GetPx();
	      true_decayed_positron_py=tparticle->GetPy();
	      true_decayed_positron_pz=tparticle->GetPz();
	      true_decayed_positron_pt=tparticle->GetPt();
	      true_decayed_positron_p=tparticle->GetP();
	      true_decayed_positron_phi=tparticle->GetPhi();
	      true_decayed_positron_theta=tparticle->GetTheta();
	      true_decayed_positron_eta=tparticle->GetEta();
	      true_decayed_positron_id=-11;

	      // Fill Smeared Particle Info if Particle is Found
	      if(is_smeared)
		{
		  reco_decayed_positron_px=sparticle->GetPx();
		  reco_decayed_positron_py=sparticle->GetPy();
		  reco_decayed_positron_pz=sparticle->GetPz();
		  reco_decayed_positron_pt=sparticle->GetPt();
		  reco_decayed_positron_p=sparticle->GetP();
		  reco_decayed_positron_phi=atan(reco_decayed_positron_py/reco_decayed_positron_px);
		  reco_decayed_positron_theta=atan(reco_decayed_positron_pt/reco_decayed_positron_pz);
		  if(reco_decayed_positron_theta>0)
		    {
		      reco_decayed_positron_eta=-log((tan(reco_decayed_positron_theta/2)));
		    }
		  else
		    {
		      reco_decayed_positron_eta=-log(-(tan(reco_decayed_positron_theta/2)));
		    }
		}
	    }

	  // Nuclear BreakUp Particles (PHSartre3 refers to their parentindex as 5 for their identification at THIS step
	  if(tparticle->GetParentIndex()==5)
	    {
	      true_breakup_px.push_back(tparticle->GetPx());
	      true_breakup_py.push_back(tparticle->GetPy());
	      true_breakup_pz.push_back(tparticle->GetPz());
	      true_breakup_pt.push_back(tparticle->GetPt());
	      true_breakup_p.push_back(tparticle->GetP());
	      true_breakup_phi.push_back(tparticle->GetPhi());
	      true_breakup_theta.push_back(tparticle->GetTheta());
	      true_breakup_eta.push_back(tparticle->GetEta());
	      true_breakup_id.push_back(tparticle->Id().Code());
	    }
	}
      
      /* Record True Event Info */
      true_x=event->GetTrueX();
      true_y=event->GetTrueY();
      true_Q2=event->GetTrueQ2();
      true_W2=event->GetTrueW2();
      true_s=event->GetHardS();
      true_t=event->GetHardT();
      /* Record Reco Event Info */

      /* Fill Output Tree */
      out_tree->Fill();
    }
  out_tree->Write();
  out_file->Close();
  return 0;
}
