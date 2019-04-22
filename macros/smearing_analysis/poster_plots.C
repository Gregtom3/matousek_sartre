int poster_plots()
{

  /* Plot 1 */
  TCanvas *c1 = new TCanvas("c1","c1",600,400);
  
  TString filename = "/sphenix/user/gregtom3/matousek_sartre/simulation/modules/1000000_sample_combine.root";
  
  TFile *inFile = new TFile(filename,"OPEN");
  
  TTree *inTree = (TTree*)inFile->Get("event");
  const int points = 200;
  TH1F *h1 = new TH1F("h1","h1",points,2.5,3.5);
  TH1F *h2 = new TH1F("h2","h2",points,2.5,3.5);
  TH1F *h3 = new TH1F("h3","h3",points,2.5,3.5);
  TH1F *h4 = new TH1F("h4","h4",points,0,4.0);
  /* Histogram sections */
  TCut cut1 = "true_decayed_electron_eta>-4&&true_decayed_electron_eta<4.0";
  TCut cut2 = "true_decayed_positron_eta>-4.0&&true_decayed_positron_eta<4.0";
  TCut cut3 = "sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))<=3.025";
  TCut cut4 = "sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))>=3.025&&sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))<=3.175";
  TCut cut5 = "sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))>=3.175";

  /* Draw from Tree into Histogram */
  // inTree->Draw("sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))>>h1",cut1&&cut2&&cut3,"goff");
  
  //  inTree->Draw("sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))>>h2",cut1&&cut2&&cut4,"goff");
  

  // inTree->Draw("sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))>>h3",cut1&&cut2&&cut5,"goff");

  inTree->Draw("sqrt(2*reco_decayed_electron_p*sin(reco_decayed_electron_theta)*reco_decayed_positron_p*sin(reco_decayed_positron_theta)*(cosh(reco_decayed_electron_eta-reco_decayed_positron_eta)-cos(reco_decayed_electron_phi-reco_decayed_positron_phi)))>>h4",cut1&&cut2,"goff");
  
  /* Modify plot */
  //h1->SetMarkerSize(0.5);
  //h2->SetMarkerSize(1);
  //h3->SetMarkerSize(0.5);
  //h1->SetMarkerStyle(20);
  //h2->SetMarkerStyle(20);
  //h2->SetMarkerColor(kBlue);
  //h3->SetMarkerStyle(20);
  h4->SetMarkerStyle(20);
  h4->SetMarkerSize(0.8);
  /* Draw plot */
  // h2->Draw("p");
  //h1->Draw("same p");
  //h3->Draw("same p");
  h4->GetXaxis()->SetTitle("Invariant Mass [GeV/c^{2}]");
  h4->GetYaxis()->SetTitle("Counts");
  h4->SetTitle("Recovered J/#Psi Invariant Mass");
  h4->Draw("p");
    
  /* Fit Plot */
    
  TF1 *fit = new TF1("fit","[0]*exp(-0.5*((x-[1])/[2])**2)+[3]+[4]*x+[5]*x^2+[6]*x^3+[7]*x^4+[8]*x^5+[9]*x^6+[10]*x^7+[11]*x^8",0,4);
    
  fit->SetParLimits(0,0.1,1000000);
  fit->SetParLimits(1,3.0,3.2);
  fit->SetParLimits(2,0.01,1);
  fit->SetLineWidth(4);
  fit->SetLineColor(kBlue);
  fit->SetNpx(1000);
  h4->Fit("fit","R0");
  fit->Draw("same");
  TString par0 = TString(std::to_string(fit->GetParameter(0)));
  TString par1 = TString(std::to_string(fit->GetParameter(1)));
  TString par2 = TString(std::to_string(fit->GetParameter(2)));
  TString par3 = TString(std::to_string(fit->GetParameter(3)));
  TString par4 = TString(std::to_string(fit->GetParameter(4)));
  TString par5 = TString(std::to_string(fit->GetParameter(5)));
  TString par6 = TString(std::to_string(fit->GetParameter(6)));
  TString par7 = TString(std::to_string(fit->GetParameter(7)));
  TString par8 = TString(std::to_string(fit->GetParameter(8)));
  TString par9 = TString(std::to_string(fit->GetParameter(9)));
  TString par10 = TString(std::to_string(fit->GetParameter(10)));
  TString par11 = TString(std::to_string(fit->GetParameter(11)));
    
  TString gaus = par0+"*exp(-0.5*((x-"+par1+")/"+par2+")**2)";
  TString poly = par3+"+x*"+par4+"+x^2*"+par5+"+x^3*"+par6+"+x^4*"+par7+"+x^5*"+par8+"+x^6*"+par9+"+x^7*"+par10+"+x^8*"+par11;
    
  TF1 *fit_gaus = new TF1("fit_gaus",gaus,0,4);
  fit_gaus->SetNpx(1000);
  fit_gaus->SetLineWidth(4);
  fit_gaus->SetLineColor(kGreen+4);
  fit_gaus->Draw("same");
    
  TF1 *fit_poly = new TF1("fit_poly",poly,0,4);
  fit_poly->SetNpx(1000);
  fit_poly->SetLineColor(kRed);
  fit_poly->SetLineStyle(9);
  fit_poly->Draw("same");
   h4->Draw("same p");
  gPad->RedrawAxis();

  auto legend = new TLegend(0.138686,0.678937,0.51877,0.879346);
  legend->SetHeader("Plot Legend","C");
  legend->AddEntry("h4","J/#Psi e^{-}e^{+} Decay Invariant Mass","p");
  legend->AddEntry("fit","Gaussian w/ Polynomial Background","l");
  legend->AddEntry("fit_gaus","Gaussian","l");
  legend->AddEntry("fit_poly","8th order Polynomial Background","l");
  legend->Draw("same");

  gStyle->SetOptStat(0);
  return 0;
}


