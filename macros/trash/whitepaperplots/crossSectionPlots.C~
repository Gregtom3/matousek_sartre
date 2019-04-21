int crossSectionPlots()
{
  // All TFiles have 50k events and are 18x275 jpsi DVMP
  TFile *ep_coherent_bSat = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/whitepaperplots/50k_18x275_ep_jpsi_coherent_bSat.root", "READ");
  
  TFile *ep_coherent_bNonSat = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/whitepaperplots/50k_18x275_ep_jpsi_coherent_bNonSat.root", "READ");

  TFile *eAu_coherent_bSat = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/whitepaperplots/50k_18x275_eAu_jpsi_coherent_bSat.root", "READ");

  TFile *eAu_coherent_bNonSat = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/whitepaperplots/50k_18x275_eAu_jpsi_coherent_bNonSat.root", "READ");

  TFile *eAu_incoherent_bSat = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/whitepaperplots/50k_18x275_eAu_jpsi_incoherent_bSat.root", "READ");
  
  TFile *eAu_incoherent_bNonSat = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/whitepaperplots/50k_18x275_eAu_jpsi_incoherent_bNonSat.root", "READ");
    
  // Open TTrees within TFiles
  TTree *t_ep_coherent_bSat=(TTree*)ep_coherent_bSat->Get("event_sartre");
  TTree *t_ep_coherent_bNonSat=(TTree*)ep_coherent_bNonSat->Get("event_sartre");
  TTree *t_eAu_coherent_bSat=(TTree*)eAu_coherent_bSat->Get("event_sartre");
  TTree *t_eAu_coherent_bNonSat=(TTree*)eAu_coherent_bNonSat->Get("event_sartre");
  TTree *t_eAu_incoherent_bSat=(TTree*)eAu_incoherent_bSat->Get("event_sartre");
  TTree *t_eAu_incoherent_bNonSat=(TTree*)eAu_incoherent_bNonSat->Get("event_sartre");


  // Scaling Plots from Integrated Lumi
  double scaleLumi = 10000000;
  int nevents = 50000;
  
  float xsection_ep_coherent_bSat;
  float xsection_ep_coherent_bNonSat;
  float xsection_eAu_coherent_bSat;
  float xsection_eAu_coherent_bNonSat;
  float xsection_eAu_incoherent_bSat;
  float xsection_eAu_incoherent_bNonSat;
  
  t_ep_coherent_bSat->SetBranchAddress("cross_section",&xsection_ep_coherent_bSat);
  t_ep_coherent_bNonSat->SetBranchAddress("cross_section",&xsection_ep_coherent_bNonSat);
  t_eAu_coherent_bSat->SetBranchAddress("cross_section",&xsection_eAu_coherent_bSat);
  t_eAu_coherent_bNonSat->SetBranchAddress("cross_section",&xsection_eAu_coherent_bNonSat);
  t_eAu_incoherent_bSat->SetBranchAddress("cross_section",&xsection_eAu_incoherent_bSat);
  t_eAu_incoherent_bNonSat->SetBranchAddress("cross_section",&xsection_eAu_incoherent_bNonSat);

  t_ep_coherent_bSat->GetEntry(10);
  t_ep_coherent_bNonSat->GetEntry(10);
  t_eAu_coherent_bSat->GetEntry(10);
  t_eAu_coherent_bNonSat->GetEntry(10);
  t_eAu_incoherent_bSat->GetEntry(10);
  t_eAu_incoherent_bNonSat->GetEntry(10);

  float scale_ep_coherent_bSat = scaleLumi/(nevents/(xsection_ep_coherent_bSat*1000000));
  float scale_ep_coherent_bNonSat=scaleLumi/(nevents/(xsection_ep_coherent_bNonSat*1000000));
  float scale_eAu_coherent_bSat=scaleLumi/197/(nevents/(xsection_eAu_coherent_bSat*1000000));
  float scale_eAu_coherent_bNonSat=scaleLumi/197/(nevents/(xsection_eAu_coherent_bNonSat*1000000));
  float scale_eAu_incoherent_bSat=scaleLumi/197/(nevents/(xsection_eAu_incoherent_bSat*1000000));
  float scale_eAu_incoherent_bNonSat=scaleLumi/197/(nevents/(xsection_eAu_incoherent_bNonSat*1000000));

  // Fill Histograms (bSat and bNonSat)
  
  TH1F *h1 = new TH1F("h1","h1",20,1,10);
  TH1F *h2 = new TH1F("h2","h2",20,1,10);
  TH1F *h3 = new TH1F("h3","h3",20,1,10);
  TH1F *h4 = new TH1F("h4","h4",20,1,10);

  t_ep_coherent_bSat->Draw("Q2>>h1","x<0.01");
  t_eAu_coherent_bSat->Draw("Q2>>h2","x<0.01");
  t_ep_coherent_bNonSat->Draw("Q2>>h3","x<0.01");
  t_eAu_coherent_bNonSat->Draw("Q2>>h4","x<0.01");

  h1->Scale(scale_ep_coherent_bSat);
  h2->Scale(scale_eAu_coherent_bSat);
  h3->Scale(scale_ep_coherent_bNonSat);
  h4->Scale(scale_eAu_coherent_bNonSat);

  h2->Divide(h1);
  h4->Divide(h3);
  h2->SetLineColor(kRed);
  h4->SetLineColor(kBlack);
  
  h4->GetYaxis()->SetRangeUser(0,5);
  gStyle->SetOptStat(0000);
  h4->SetTitle("Cross Section Ratio Plot");
  h4->GetXaxis()->SetTitle("Q2 (GeV^2)");
  h4->GetYaxis()->SetTitle("#frac{#sigma_{(eAu)}}{#sigma_{(ep)}}");
  
  
  auto legend = new TLegend(0.2,0.15,0.5,0.3);
  legend->AddEntry(h2,"bSat","l");
  legend->AddEntry(h4,"bNonSat","l");
  h4->Draw();
  h2->Draw("same");
  legend->Draw("same");
  
  
  return 0;
}
