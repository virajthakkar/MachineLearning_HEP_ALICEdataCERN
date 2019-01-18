
Double_t BWPoly2(Double_t *x, Double_t *par)
{
  return (par[0]*par[1]*0.01*1)/(2*3.14159)/((x[0]-par[2])*(x[0]-par[2])+(par[1]*par[1])/4.)+ par[3]+ par[4]*x[0]+par[5]*x[0]*x[0];
  
}

Double_t BW(Double_t *x, Double_t *par)
{
  return (par[0]*par[1]*0.01*1)/(2*3.14159)/((x[0]-par[2])*(x[0]-par[2])+(par[1]*par[1])/4.);
}

Double_t Pol2(Double_t *x, Double_t *par)
{
  return par[0]+ par[1]*x[0]+par[2]*x[0]*x[0];
}


void invmass()
{
  gStyle->SetOptFit(1);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetStatColor(0);
  gStyle->SetCanvasColor(0);
  gStyle->SetPadColor(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFillColor(0);
  gStyle->SetLineColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleColor(1);

  TCanvas *cinv[2];
  for(Int_t ip = 0; ip < 2; ip++)
    {
      cinv[ip] = new TCanvas(Form("cinv%d",ip),"cinv",10,10,600,600); 
      cinv[ip]->SetLeftMargin(0.2);
      cinv[ip]->SetRightMargin(0.05);
      cinv[ip]->SetBottomMargin(0.2); 
    }

  ////sig eff=0.93////
  TFile *f1 = new TFile("TMVApp_sig.root");
  TH1F *hsig =(TH1F*)f1->Get("invsig");
  TH1F *hsig1 =(TH1F*)f1->Get("invbkg");
  TH1F *htmva=(TH1F*)hsig->Clone("htmva");
  htmva->Sumw2();
  
  TFile *f2 = new TFile("TMVApp_bkg.root");
  TH1F *hbkg =(TH1F*)f2->Get("invsig");
  TH1F *hbkg1 =(TH1F*)f2->Get("invbkg");
  TH1F *htmva_bkg=(TH1F*)hbkg->Clone("htmva_bkg");
  htmva_bkg->Sumw2();


  htmva->GetXaxis()->SetTitle("M_{k#pi} (GeV/c^{2})");
  htmva->GetXaxis()->SetTitleSize(0.05);
  htmva->GetXaxis()->SetTitleOffset(1.03);
  htmva->GetXaxis()->SetTitleFont(42);
  htmva->GetXaxis()->CenterTitle(true);
  htmva->GetXaxis()->SetLabelSize(0.05);
  htmva->GetXaxis()->SetLabelFont(42);
  htmva->GetXaxis()->SetNdivisions(511);
  htmva->GetYaxis()->SetTitle("Counts(/10 MeV/c^{2})");
  htmva->GetYaxis()->SetTitleFont(42);
  htmva->GetYaxis()->CenterTitle(true);
  htmva->GetYaxis()->SetTitleSize(0.05);
  htmva->GetYaxis()->SetTitleOffset(1.7);
  htmva->GetYaxis()->SetLabelSize(0.05);
  htmva->GetYaxis()->SetLabelFont(42);
  htmva->GetYaxis()->SetNdivisions(509);


  htmva_bkg->GetXaxis()->SetTitle("M_{k#pi}");
  htmva_bkg->GetXaxis()->SetTitleSize(0.05);
  htmva_bkg->GetXaxis()->SetTitleOffset(1.03);
  htmva_bkg->GetXaxis()->SetTitleFont(42);
  htmva_bkg->GetXaxis()->CenterTitle(true);
  htmva_bkg->GetXaxis()->SetLabelSize(0.05);
  htmva_bkg->GetXaxis()->SetLabelFont(42);
  htmva_bkg->GetXaxis()->SetNdivisions(511);
  htmva_bkg->GetYaxis()->SetTitle("Counts(/10 MeV/c^{2})");
  htmva_bkg->GetYaxis()->SetTitleFont(42);
  htmva_bkg->GetYaxis()->CenterTitle(true);
  htmva_bkg->GetYaxis()->SetTitleSize(0.05);
  htmva_bkg->GetYaxis()->SetTitleOffset(1.7);
  htmva_bkg->GetYaxis()->SetLabelSize(0.05);
  htmva_bkg->GetYaxis()->SetLabelFont(42);
  htmva_bkg->GetYaxis()->SetNdivisions(509);
 

  
  htmva->SetMarkerStyle(20);
  htmva->SetMarkerColor(1);
  htmva->SetLineColor(1);

  htmva_bkg->SetMarkerStyle(20);
  htmva_bkg->SetMarkerColor(2);
  htmva_bkg->SetLineColor(2);
    
  TH1F *htmva_clone=(TH1F*)htmva->Clone("htmva_clone");
  TH1F *htmva_bkg_clone=(TH1F*)htmva_bkg->Clone("htmva_bkg_clone");








  
  float fitlow=0.69;
  float fithi=1.2;
  float normlow=5;
  float normhigh=10;
 
  htmva_bkg->Scale(htmva->Integral(normlow,normhigh)/(htmva_bkg->Integral(normlow,normhigh)));
  htmva_bkg_clone->Scale(htmva_clone->Integral(normlow,normhigh)/(htmva_bkg_clone->Integral(normlow,normhigh)));

  
  htmva->Add(htmva_bkg,-1);

 
  TF1 *fitFcn1 = new TF1("fitFcn1",BWPoly2,fitlow,fithi,6);
  fitFcn1->SetParameter(0,100);
  fitFcn1->FixParameter(1,0.048);
  fitFcn1->SetParLimits(2,0.85,0.95);
  fitFcn1->SetParameter(3,10.0);
  fitFcn1->SetParameter(4,100.0);
  fitFcn1->SetParameter(5,10000.0);
  fitFcn1->SetLineColor(2);
  fitFcn1->SetParNames("Yield","Width","Mass","p0","p1","p2");

  htmva->Fit(fitFcn1,"IER+");

  float a=fitFcn1->GetParameter(0);
  float b=fitFcn1->GetParameter(2);
  float c=fitFcn1->GetParameter(3);
  float d=fitFcn1->GetParameter(4);
  float e=fitFcn1->GetParameter(5);


  TF1 *fitFcn2 = new TF1("fitFcn2",BW,fitlow,fithi,3);
  fitFcn2->FixParameter(0,a);
  fitFcn2->FixParameter(1,0.048);
  fitFcn2->FixParameter(2,b);
  fitFcn2->SetLineColor(209);
  fitFcn2->SetLineStyle(2);
  
  TF1 *fitFcn3 = new TF1("fitFcn3",Pol2,fitlow,fithi,3);
  fitFcn3->FixParameter(0,c);
  fitFcn3->FixParameter(1,d);
  fitFcn3->FixParameter(2,e);
  fitFcn3->SetLineColor(4);

  

  cout<<"signal by BW  "<<fitFcn2->Integral(0.6,2.0)/0.01<<"\n";
  cout<<htmva_clone->Integral(10,50)<<"\n";
  cout<<"Significance bdt===="<<(fitFcn2->Integral(0.6,2.0)/0.01)/sqrt(htmva_clone->Integral(10,50))<<"\n";  //0.7 to 1.1


  cinv[0]->cd();
  htmva_clone->Draw();
  htmva_bkg_clone->Draw("same");
  TLegend *l1 = new TLegend(0.2365772,0.7801394,0.3708054,0.8797909);
   l1->SetTextFont(42);
   l1->SetBorderSize(0);
   l1->SetFillStyle(0);
   l1->SetFillColor(0);
   l1->SetMargin(0.25);
   l1->SetTextSize(0.03);
   l1->SetEntrySeparation(0.5);
   l1->AddEntry(htmva_clone,"Unlike pair after BDT cut","p");
   l1->AddEntry(htmva_bkg_clone,"Normalized like pair after BDT cut","p");
   l1->Draw();

  cinv[1]->cd();
  htmva->Draw();
  fitFcn3->Draw("same");
  fitFcn2->Draw("same");
 TLegend *l2 = new TLegend(0.1565772,0.701394,0.508054,0.8797909);
   l2->SetTextFont(42);
   l2->SetBorderSize(0);
   l2->SetFillStyle(0);
   l2->SetFillColor(0);
   l2->SetMargin(0.25);
   l2->SetTextSize(0.03);
   l2->SetEntrySeparation(0.5);
   l2->AddEntry(fitFcn1,"BW + Pol2","l");
   l2->AddEntry(fitFcn2,"BW","l");
   l2->AddEntry(fitFcn3,"Pol2","l");
   l2->Draw();
  

  
}
