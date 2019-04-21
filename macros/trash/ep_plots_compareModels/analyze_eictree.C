int analyze_eictree()
{
  TFile *inFile = new TFile("/sphenix/user/gregtom3/matousek_sartre/simulation/output_files/ep_plots_compareModels/eictree_18x275_ep_JPSi_DVMP_bNonSat.root","OPEN");
 
  TTree *inFile_EICTree = (TTree*)inFile->Get("EICTree");
  
  TCanvas *c1 = new TCanvas("c1","c1",600,400);
  TH2F *h2_p_eta_se = new TH2F("h2_p_eta_se","h2_p_eta_se",100,-6,6,100,0,50);
  inFile_EICTree->Draw("p:eta>>h2_p_eta_se","id==11&&KS==4");
  h2_p_eta_se->Draw("colz");
  h2_p_eta_se->SetTitle("Momentum vs. Eta (Scattered Electron)");
  h2_p_eta_se->GetYaxis()->SetTitle("p (GeV/c)");
  h2_p_eta_se->GetXaxis()->SetTitle("eta");
  gStyle->SetOptStat(0000);
  c1->SetLogz();

  TCanvas *c2 = new TCanvas("c2","c2",600,400);
  TH1F *h1_t = new TH1F("h1_t","h1_t",100,0,1);
  inFile_EICTree->Draw("-t_hat>>h1_t");
  h1_t->Draw();
  h1_t->SetTitle("Counts vs. |t|");
  h1_t->GetXaxis()->SetTitle("|t|");
  h1_t->GetYaxis()->SetTitle("Counts");
  gStyle->SetOptStat(0000);

  TCanvas *c3 = new TCanvas("c3","c3",600,400);
  TH2F *h2_p_eta_jpsi = new TH2F("h2_p_eta_jpsi","h2_p_eta_jpsi",100,-6,6,100,0,50);
  inFile_EICTree->Draw("p:eta>>h2_p_eta_jpsi","id==443");
  h2_p_eta_jpsi->Draw("colz");
  h2_p_eta_jpsi->SetTitle("Momentum vs. Eta (J/Psi)");
  h2_p_eta_jpsi->GetYaxis()->SetTitle("p (GeV/c)");
  h2_p_eta_jpsi->GetXaxis()->SetTitle("eta");
  gStyle->SetOptStat(0000);
  c3->SetLogz();

  return 0;

}
