// Plots relevant eta distributions for DVMP

#include <vector>
int eta_plots()
{
    gROOT->LoadMacro("/sphenix/user/gregtom3/SBU/research/macros/macros/sPHENIXStyle/sPhenixStyle.C");
  SetsPhenixStyle();

  //----------------------------------------------------------------------------
  // Input File Names
  //----------------------------------------------------------------------------
  
TString filename_ep_coherent_bNonSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/combine_eictree_eicsmear_50k/50k_Sartre_18x275_ep_JPsi_ee_coherent_bNonSat_eictree.combine.root";

TString filename_ep_coherent_bSat = "/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/combine_eictree_eicsmear_50k/50k_Sartre_18x275_ep_JPsi_ee_coherent_bSat_eictree.combine.root";

  //----------------------------------------------------------------------------
  // Input TFiles from File Names
  //----------------------------------------------------------------------------
  
  TFile *file_ep_coherent_bNonSat = new TFile(filename_ep_coherent_bNonSat, "OPEN");
  TFile *file_ep_coherent_bSat = new TFile(filename_ep_coherent_bSat, "OPEN");
  
  //----------------------------------------------------------------------------
  // Input TTrees from TFiles
  //----------------------------------------------------------------------------
  
  TTree *tree_ep_coherent_bNonSat = (TTree*)file_ep_coherent_bNonSat->Get("event");
  TTree *tree_ep_coherent_bSat = (TTree*)file_ep_coherent_bSat->Get("event");

  //----------------------------------------------------------------------------
  // Scaling Factors from Cross Section
  //----------------------------------------------------------------------------
  
  TVectorD *xsec_ep_coherent_bNonSat;
  file_ep_coherent_bNonSat->GetObject("xsec",xsec_ep_coherent_bNonSat);

  TVectorD *xsec_ep_coherent_bSat;
  file_ep_coherent_bSat->GetObject("xsec",xsec_ep_coherent_bSat);

  //----------------------------------------------------------------------------
  // Histograms 0
  //----------------------------------------------------------------------------
  
  TH1F *h0a_ep_coherent_bNonSat = new TH1F("h0a_ep_coheret_bNonSat","True Scattered Electron Eta",200,-6,6);

  TH1F *h0b_ep_coherent_bNonSat = new TH1F("h0b_ep_coherent_bNonSat","True Scattered Hadron Eta",200,0,10);

  TH1F *h0c_ep_coherent_bNonSat = new TH1F("h0c_ep_coherent_bNonSat","True Decayed Electron Eta",200,-6,6);

  TH1F *h0d_ep_coherent_bNonSat = new TH1F("h0d_ep_coherent_bNonSat","True Decayed Positron Eta",200,-6,6);

  TH1F *h0a_ep_coherent_bSat = new TH1F("h0a_ep_coheret_bSat","True Scattered Electron Eta",200,-6,6);

  TH1F *h0b_ep_coherent_bSat = new TH1F("h0b_ep_coherent_bSat","True Scattered Hadron Eta",200,0,10);

  TH1F *h0c_ep_coherent_bSat = new TH1F("h0c_ep_coherent_bSat","True Decayed Electron Eta",200,-6,6);

  TH1F *h0d_ep_coherent_bSat = new TH1F("h0d_ep_coherent_bSat","True Decayed Positron Eta",200,-6,6);

  //----------------------------------------------------------------------------
  // Plotting0
  //----------------------------------------------------------------------------
  
  TCanvas *c0a_ep_coherent = new TCanvas("c0a_ep_coherent","",700,500);
  TCanvas *c0b_ep_coherent = new TCanvas("c0b_ep_coherent","",700,500);
  TCanvas *c0c_ep_coherent = new TCanvas("c0c_ep_coherent","",700,500);
  TCanvas *c0d_ep_coherent = new TCanvas("c0d_ep_coherent","",700,500);

  plot0(tree_ep_coherent_bNonSat,xsec_ep_coherent_bNonSat(0),h0a_ep_coherent_bNonSat,h0b_ep_coherent_bNonSat,h0c_ep_coherent_bNonSat,h0d_ep_coherent_bNonSat);
  
  plot0(tree_ep_coherent_bSat,xsec_ep_coherent_bSat(0),h0a_ep_coherent_bSat,h0b_ep_coherent_bSat,h0c_ep_coherent_bSat,h0d_ep_coherent_bSat);

  /* Scattered Lepton */
  c0a_ep_coherent->cd();
  h0a_ep_coherent_bNonSat->SetLineColor(kRed);
  h0a_ep_coherent_bSat->SetLineColor(kBlue);
  h0a_ep_coherent_bSat->Draw();
  h0a_ep_coherent_bNonSat->Draw("Same");

  auto legend0a = new TLegend(0.75,0.8,0.9,0.9);
  legend0a->AddEntry(h0a_ep_coherent_bSat,"bSat","l");
  legend0a->AddEntry(h0a_ep_coherent_bNonSat,"bNonSat","l");
  legend0a->Draw("same");
 
  /* Scattered Hadron */
  c0b_ep_coherent->cd();
  h0b_ep_coherent_bNonSat->SetLineColor(kRed);
  h0b_ep_coherent_bSat->SetLineColor(kBlue);
  h0b_ep_coherent_bSat->Draw();
  h0b_ep_coherent_bNonSat->Draw("Same");

  auto legend0b = new TLegend(0.75,0.8,0.9,0.9);
  legend0b->AddEntry(h0b_ep_coherent_bSat,"bSat","l");
  legend0b->AddEntry(h0b_ep_coherent_bNonSat,"bNonSat","l");
  legend0b->Draw("same");

  /* Decayed Electron */
  c0c_ep_coherent->cd();
  h0c_ep_coherent_bNonSat->SetLineColor(kRed);
  h0c_ep_coherent_bSat->SetLineColor(kBlue);
  h0c_ep_coherent_bSat->Draw();
  h0c_ep_coherent_bNonSat->Draw("Same");

  auto legend0c = new TLegend(0.75,0.8,0.9,0.9);
  legend0c->AddEntry(h0c_ep_coherent_bSat,"bSat","l");
  legend0c->AddEntry(h0c_ep_coherent_bNonSat,"bNonSat","l");
  legend0c->Draw("same");

  /* Decayed Positron */
  c0d_ep_coherent->cd();
  h0d_ep_coherent_bNonSat->SetLineColor(kRed);
  h0d_ep_coherent_bSat->SetLineColor(kBlue);
  h0d_ep_coherent_bSat->Draw();
  h0d_ep_coherent_bNonSat->Draw("Same");

  auto legend0d = new TLegend(0.75,0.8,0.9,0.9);
  legend0d->AddEntry(h0d_ep_coherent_bSat,"bSat","l");
  legend0d->AddEntry(h0d_ep_coherent_bNonSat,"bNonSat","l");
  legend0d->Draw("same");
  
  delete c0a_ep_coherent; delete c0b_ep_coherent; delete c0c_ep_coherent; delete c0d_ep_coherent;
  //----------------------------------------------------------------------------
  // Histograms 1
  //----------------------------------------------------------------------------
  
  TH1F *h1a_ep_coherent_bNonSat = new TH1F("h1a_ep_coheret_bNonSat","Reco Scattered Electron Eta bNonSat",200,-6,6);

  TH1F *h1b_ep_coherent_bNonSat = new TH1F("h1b_ep_coherent_bNonSat","Reco Scattered Hadron Eta bNonSat",200,0,10);

  TH1F *h1c_ep_coherent_bNonSat = new TH1F("h1c_ep_coherent_bNonSat","Reco Decayed Electron Eta bNonSat",200,-6,6);

  TH1F *h1d_ep_coherent_bNonSat = new TH1F("h1d_ep_coherent_bNonSat","Reco Decayed Positron Eta bNonSat",200,-6,6);

  TH1F *h1a_ep_coherent_bSat = new TH1F("h1a_ep_coheret_bSat","Reco Scattered Electron Eta bSat",200,-6,6);

  TH1F *h1b_ep_coherent_bSat = new TH1F("h1b_ep_coherent_bSat","Reco Scattered Hadron Eta bSat",200,0,10);

  TH1F *h1c_ep_coherent_bSat = new TH1F("h1c_ep_coherent_bSat","Reco Decayed Electron Eta bSat",200,-6,6);

  TH1F *h1d_ep_coherent_bSat = new TH1F("h1d_ep_coherent_bSat","Reco Decayed Positron Eta bSat",200,-6,6);

  //----------------------------------------------------------------------------
  // Plotting 1
  //----------------------------------------------------------------------------
  
  TCanvas *c1a_ep_coherent = new TCanvas("c1a_ep_coherent","",700,500);
  TCanvas *c1b_ep_coherent = new TCanvas("c1b_ep_coherent","",700,500);
  TCanvas *c1c_ep_coherent = new TCanvas("c1c_ep_coherent","",700,500);
  TCanvas *c1d_ep_coherent = new TCanvas("c1d_ep_coherent","",700,500);

  plot1(tree_ep_coherent_bNonSat,xsec_ep_coherent_bNonSat(0),h1a_ep_coherent_bNonSat,h1b_ep_coherent_bNonSat,h1c_ep_coherent_bNonSat,h1d_ep_coherent_bNonSat);
  
  plot1(tree_ep_coherent_bSat,xsec_ep_coherent_bSat(0),h1a_ep_coherent_bSat,h1b_ep_coherent_bSat,h1c_ep_coherent_bSat,h1d_ep_coherent_bSat);

  //----------------------------------------------------------------------------
  // Histograms 2
  //----------------------------------------------------------------------------
  
  TH1F *h2a_ep_coherent_bNonSat = new TH1F("h2a_ep_coheret_bNonSat","Reco Scattered Electron Eta (pt>1GeV)",200,-6,6);

  TH1F *h2b_ep_coherent_bNonSat = new TH1F("h2b_ep_coherent_bNonSat","Reco Scattered Hadron Eta (pt>1GeV)",200,0,10);

  TH1F *h2c_ep_coherent_bNonSat = new TH1F("h2c_ep_coherent_bNonSat","Reco Decayed Electron Eta (pt>1GeV)",200,-6,6);

  TH1F *h2d_ep_coherent_bNonSat = new TH1F("h2d_ep_coherent_bNonSat","Reco Decayed Positron Eta (pt>1GeV)",200,-6,6);

  TH1F *h2a_ep_coherent_bSat = new TH1F("h2a_ep_coheret_bSat","Reco Scattered Electron Eta (pt>1GeV)",200,-6,6);

  TH1F *h2b_ep_coherent_bSat = new TH1F("h2b_ep_coherent_bSat","Reco Scattered Hadron Eta (pt>1GeV)",200,0,10);

  TH1F *h2c_ep_coherent_bSat = new TH1F("h2c_ep_coherent_bSat","Reco Decayed Electron Eta (pt>1GeV)",200,-6,6);

  TH1F *h2d_ep_coherent_bSat = new TH1F("h2d_ep_coherent_bSat","Reco Decayed Positron Eta (pt>1GeV)",200,-6,6);

  //----------------------------------------------------------------------------
  // Plotting 2
  //----------------------------------------------------------------------------

  plot2(tree_ep_coherent_bNonSat,xsec_ep_coherent_bNonSat(0),h2a_ep_coherent_bNonSat,h2b_ep_coherent_bNonSat,h2c_ep_coherent_bNonSat,h2d_ep_coherent_bNonSat);
  
  plot2(tree_ep_coherent_bSat,xsec_ep_coherent_bSat(0),h2a_ep_coherent_bSat,h2b_ep_coherent_bSat,h2c_ep_coherent_bSat,h2d_ep_coherent_bSat);

  h1a_ep_coherent_bNonSat->SetLineColor(kRed);
  h2a_ep_coherent_bNonSat->SetLineColor(kBlue);
  h1b_ep_coherent_bNonSat->SetLineColor(kRed);
  h2b_ep_coherent_bNonSat->SetLineColor(kBlue);
  h1c_ep_coherent_bNonSat->SetLineColor(kRed);
  h2c_ep_coherent_bNonSat->SetLineColor(kBlue);
  h1d_ep_coherent_bNonSat->SetLineColor(kRed);
  h2d_ep_coherent_bNonSat->SetLineColor(kBlue);
  
  /* Comparing Reco Eta for all recovered particles and those with a p>1 cut */
  c1a_ep_coherent->cd();
  h1a_ep_coherent_bNonSat->Draw();
  h2a_ep_coherent_bNonSat->Draw("same");
  auto legend1a = new TLegend(0.75,0.8,0.9,0.9);
  legend1a->AddEntry(h1a_ep_coherent_bNonSat,"No p cut","l");
  legend1a->AddEntry(h2a_ep_coherent_bNonSat,"p>1GeV cut","l");
  legend1a->Draw("same");
 
  c1b_ep_coherent->cd();
  h1b_ep_coherent_bNonSat->Draw();
  h2b_ep_coherent_bNonSat->Draw("same");
  auto legend1b = new TLegend(0.75,0.8,0.9,0.9);
  legend1b->AddEntry(h1b_ep_coherent_bNonSat,"No p cut","l");
  legend1b->AddEntry(h2b_ep_coherent_bNonSat,"p>1GeV cut","l");
  legend1b->Draw("same");
 
  c1c_ep_coherent->cd();
  h1c_ep_coherent_bNonSat->Draw();
  h2c_ep_coherent_bNonSat->Draw("same");
  auto legend1c = new TLegend(0.75,0.8,0.9,0.9);
  legend1c->AddEntry(h1c_ep_coherent_bNonSat,"No p cut","l");
  legend1c->AddEntry(h2c_ep_coherent_bNonSat,"p>1GeV cut","l");
  legend1c->Draw("same");
 
  c1d_ep_coherent->cd();
  h1d_ep_coherent_bNonSat->Draw();
  h2d_ep_coherent_bNonSat->Draw("same");
  auto legend1d = new TLegend(0.75,0.8,0.9,0.9);
  legend1d->AddEntry(h1d_ep_coherent_bNonSat,"No p cut","l");
  legend1d->AddEntry(h2d_ep_coherent_bNonSat,"p>1GeV cut","l");
  legend1d->Draw("same");
 

  //----------------------------------------------------------------------------
  // Plotting 3
  //----------------------------------------------------------------------------

  TCanvas *ca_residual_vs_true = new TCanvas("ca_residual_vs_true","ca_residual_vs_true",700,500);
  TH2F *h2_residual_vs_true = new TH2F("h2_residual_vs_true","Scattered Lepton Residual Eta vs. True Eta",200,-4,0,200,-0.001,0.001);
  tree_ep_coherent_bNonSat->Draw("true_scattered_lepton_eta-reco_scattered_lepton_eta:true_scattered_lepton_eta>>h2_residual_vs_true","reco_scattered_lepton_eta!=0","colz");
  
  
  
  return 0;
}

void plot0(TTree *tree,double xsec,TH1F* h0a, TH1F* h0b, TH1F* h0c, TH1F* h0d)
{
  //----------------------------------------------------------------------------
  // Plotting 
  // h0 -> True Eta Distribution
  // *** a -> Scattered Lepton
  // *** b -> Scattered Hadron
  // *** c -> Decayed Electron
  // *** d -> Decayed Positron
  //----------------------------------------------------------------------------
  /* Momentarily change the names of the histograms for root commands */
  TString oldname0a = h0a->GetName();
  TString oldname0b = h0b->GetName();
  TString oldname0c = h0c->GetName();
  TString oldname0d = h0d->GetName();
  /* Set new names */
  h0a->SetName("h0a");
  h0b->SetName("h0b");
  h0c->SetName("h0c");
  h0d->SetName("h0d");
  /* Fill hisotgrams */
  tree->Draw("true_scattered_lepton_eta>>h0a","","goff");
  tree->Draw("true_scattered_hadron_eta>>h0b","","goff");
  tree->Draw("true_decayed_electron_eta>>h0c","","goff");
  tree->Draw("true_decayed_positron_eta>>h0d","","goff");
  /* Scale hisotgrams to 10fb^-1 Luminosity using input cross section */
  unsigned nentries = tree->GetEntries();
  double scaleFactor = 10000000/(nentries/(xsec*1000000));
  h0a->Scale(scaleFactor);
  h0b->Scale(scaleFactor);
  h0c->Scale(scaleFactor);
  h0d->Scale(scaleFactor);
  /* Set Axes Labels */
  h0a->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h0a->GetYaxis()->SetTitle("d#sigma/d#eta"); 
  h0b->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h0b->GetYaxis()->SetTitle("d#sigma/d#eta");
  h0c->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h0c->GetYaxis()->SetTitle("d#sigma/d#eta");
  h0d->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h0d->GetYaxis()->SetTitle("d#sigma/d#eta");
  /* Return Hisotgrams to their oldnames captured at beginning */
  h0a->SetName(oldname0a);
  h0b->SetName(oldname0b);
  h0c->SetName(oldname0c);
  h0d->SetName(oldname0d);
}

void plot1(TTree *tree,double xsec,TH1F* h1a, TH1F* h1b, TH1F* h1c, TH1F* h1d)
{
  //----------------------------------------------------------------------------
  // Plotting 
  // h1 -> Reco Eta Distribution (No p cuts)
  // *** a -> Scattered Lepton
  // *** b -> Scattered Hadron
  // *** c -> Decayed Electron
  // *** d -> Decayed Positron
  //----------------------------------------------------------------------------
  /* Momentarily change the names of the histograms for root commands */
  TString oldname1a = h1a->GetName();
  TString oldname1b = h1b->GetName();
  TString oldname1c = h1c->GetName();
  TString oldname1d = h1d->GetName();
  /* Set new names */
  h1a->SetName("h1a");
  h1b->SetName("h1b");
  h1c->SetName("h1c");
  h1d->SetName("h1d");
  /* Fill hisotgrams */
  tree->Draw("reco_scattered_lepton_eta>>h1a","reco_scattered_lepton_eta!=0","goff");
  tree->Draw("reco_scattered_hadron_eta>>h1b","","goff");
  tree->Draw("reco_decayed_electron_eta>>h1c","reco_decayed_electron_eta!=0","goff");
  tree->Draw("reco_decayed_positron_eta>>h1d","reco_decayed_positron_eta!=0","goff");
  /* Scale hisotgrams to 10fb^-1 Luminosity using input cross section */
  unsigned nentries = tree->GetEntries();
  double scaleFactor = 10000000/(nentries/(xsec*1000000));
  h1a->Scale(scaleFactor);
  h1b->Scale(scaleFactor);
  h1c->Scale(scaleFactor);
  h1d->Scale(scaleFactor);
  /* Set Axes Labels */
  h1a->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h1a->GetYaxis()->SetTitle("d#sigma/d#eta"); 
  h1b->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h1b->GetYaxis()->SetTitle("d#sigma/d#eta");
  h1c->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h1c->GetYaxis()->SetTitle("d#sigma/d#eta");
  h1d->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h1d->GetYaxis()->SetTitle("d#sigma/d#eta");
  /* Return Hisotgrams to their oldnames captured at beginning */
  h1a->SetName(oldname1a);
  h1b->SetName(oldname1b);
  h1c->SetName(oldname1c);
  h1d->SetName(oldname1d);
}

void plot2(TTree *tree,double xsec,TH1F* h2a, TH1F* h2b, TH1F* h2c, TH1F* h2d)
{
  //----------------------------------------------------------------------------
  // Plotting 
  // h2 -> Reco Eta Distribution (p>1 cuts)
  // *** a -> Scattered Lepton
  // *** b -> Scattered Hadron
  // *** c -> Decayed Electron
  // *** d -> Decayed Positron
  //----------------------------------------------------------------------------
  /* Momentarily change the names of the histograms for root commands */
  TString oldname2a = h2a->GetName();
  TString oldname2b = h2b->GetName();
  TString oldname2c = h2c->GetName();
  TString oldname2d = h2d->GetName();
  /* Set new names */
  h2a->SetName("h2a");
  h2b->SetName("h2b");
  h2c->SetName("h2c");
  h2d->SetName("h2d");
  /* Fill hisotgrams */
  tree->Draw("reco_scattered_lepton_eta>>h2a","reco_scattered_lepton_p>1&&reco_decayed_electron_p>1&&reco_decayed_positron_p>1","goff");
  tree->Draw("reco_scattered_hadron_eta>>h2b","reco_scattered_lepton_p>1&&reco_decayed_electron_p>1&&reco_decayed_positron_p>1","goff");
  tree->Draw("reco_decayed_electron_eta>>h2c","reco_scattered_lepton_p>1&&reco_decayed_electron_p>1&&reco_decayed_positron_p>1","goff");
  tree->Draw("reco_decayed_positron_eta>>h2d","reco_scattered_lepton_p>1&&reco_decayed_electron_p>1&&reco_decayed_positron_p>1","goff");
  /* Scale hisotgrams to 10fb^-1 Luminosity using input cross section */
  unsigned nentries = tree->GetEntries();
  double scaleFactor = 10000000/(nentries/(xsec*1000000));
  h2a->Scale(scaleFactor);
  h2b->Scale(scaleFactor);
  h2c->Scale(scaleFactor);
  h2d->Scale(scaleFactor);
  /* Set Axes Labels */
  h2a->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h2a->GetYaxis()->SetTitle("d#sigma/d#eta"); 
  h2b->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h2b->GetYaxis()->SetTitle("d#sigma/d#eta");
  h2c->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h2c->GetYaxis()->SetTitle("d#sigma/d#eta");
  h2d->GetXaxis()->SetTitle("Pseudorapidity #eta");
  h2d->GetYaxis()->SetTitle("d#sigma/d#eta");
  /* Return Hisotgrams to their oldnames captured at beginning */
  h2a->SetName(oldname2a);
  h2b->SetName(oldname2b);
  h2c->SetName(oldname2c);
  h2d->SetName(oldname2d);
}
