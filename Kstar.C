#define Kstar_cxx
#include "Kstar.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include<math.h>
#include"TROOT.h"
#include<iostream>

void Kstar::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Kstar.C
//      root> Kstar t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
     // Mass of K+ =493.677 MeV/c2 .....Mass of 139.57061 MeV/c2 ... Mass of Kstar0=895.55 Mev/c2
  int  Event=0;
 
   
  float invmass_s,d1pt_s,d2pt_s,costheta_s,motherpt_s,
  dcazd1_s,dcaxyd1_s,dcazd2_s,dcaxyd2_s,dcad1_s,dcad2_s,motherp_s, d1p_s,d2p_s,d1eta_s,d2eta_s,mothereta_s,motherE_s,costs_s,costs1_s;
  float invmass_b,d1pt_b,d2pt_b,costheta_b,motherpt_b,
  dcazd1_b,dcaxyd1_b,dcazd2_b,dcaxyd2_b,dcad1_b,dcad2_b,motherp_b, d1p_b,d2p_b,d1eta_b,d2eta_b,mothereta_b,motherE_b,costs_b,costs1_b;    
    
  
 // TFile *f1 = new TFile("application2_read.root","RECREATE");
  TFile *f1 = new TFile("likesignplusplusfeatures_0.8pt1.2.root","RECREATE");
  TTree *tree_sig = new TTree("tree_sig","Signal tree");
  TTree *tree_bkg = new TTree("tree_bkg","Background tree");


  tree_sig->Branch("invmass",&invmass_s,"invmass_s/F");
  tree_sig->Branch("daughter1pt",&d1pt_s,"d1pt_s/F");
  tree_sig->Branch("daughter2pt",&d2pt_s,"d2pt_s/F");
  tree_sig->Branch("costheta",&costheta_s,"costheta_s/F");
  tree_sig->Branch("motherpt",&motherpt_s,"motherpt_s/F");
  tree_sig->Branch("dcazd1",&dcazd1_s,"dcazd1_s/F");
  tree_sig->Branch("dcazd2",&dcazd2_s,"dcazd2_s/F");
  tree_sig->Branch("dcaxyd1",&dcaxyd1_s,"dcaxyd1_s/F");
  tree_sig->Branch("dcaxyd2",&dcaxyd2_s,"dcaxyd2_s/F");
  tree_sig->Branch("dcad1",&dcad1_s,"dcad1_s/F");
  tree_sig->Branch("dcad2",&dcad2_s,"dcad2_s/F");
  tree_sig->Branch("motherp",&motherp_s,"motherp_s/F");
  tree_sig->Branch("daughter1p",&d1p_s,"d1p_s/F");
  tree_sig->Branch("daughter2p",&d2p_s,"d2p_s/F");
  tree_sig->Branch("daughter1eta",&d1eta_s,"d1eta_s/F");
  tree_sig->Branch("daughter2eta",&d2eta_s,"d2eta_s/F");
  tree_sig->Branch("mothereta",&mothereta_s,"mothereta_s/F");
  tree_sig->Branch("motherE",&motherE_s,"motherE_s/F");
  tree_sig->Branch("costs",&costs_s,"costs_s/F");
  tree_sig->Branch("costs1",&costs1_s,"costs1_s/F");
  

  tree_bkg->Branch("invmass",&invmass_b,"invmass_b/F");
  tree_bkg->Branch("daughter1pt",&d1pt_b,"d1pt_b/F");
  tree_bkg->Branch("daughter2pt",&d2pt_b,"d2pt_b/F");
  tree_bkg->Branch("costheta",&costheta_b,"costheta_b/F");
  tree_bkg->Branch("motherpt",&motherpt_b,"motherpt_b/F");
  tree_bkg->Branch("dcazd1",&dcazd1_b,"dcazd1_b/F");
  tree_bkg->Branch("dcazd2",&dcazd2_b,"dcazd2_b/F");
  tree_bkg->Branch("dcaxyd1",&dcaxyd1_b,"dcaxyd1_b/F");
  tree_bkg->Branch("dcaxyd2",&dcaxyd2_b,"dcaxyd2_b/F");
  tree_bkg->Branch("dcad1",&dcad1_b,"dcad1_b/F");
  tree_bkg->Branch("dcad2",&dcad2_b,"dcad2_b/F");
  tree_bkg->Branch("motherp",&motherp_b,"motherp_b/F");
  tree_bkg->Branch("daughter1p",&d1p_b,"d1p_b/F");
  tree_bkg->Branch("daughter2p",&d2p_b,"d2p_b/F");
  tree_bkg->Branch("daughter1eta",&d1eta_b,"d1eta_b/F");
  tree_bkg->Branch("daughter2eta",&d2eta_b,"d2eta_b/F");
  tree_bkg->Branch("mothereta",&mothereta_b,"mothereta_b/F");
  tree_bkg->Branch("motherE",&motherE_b,"motherE_b/F");  
  tree_bkg->Branch("costs",&costs_b,"costs_b/F");
  tree_bkg->Branch("costs1",&costs1_b,"costs1_b/F");
  
    const float massK=0.493677; //GeV
    const float massPi=0.13957061; //GeV
    
  int k1,k2;  
  float mass,Energyd1,Energyd2,cosangle;
  float mass_b,Energyd1_b,Energyd2_b,cosangle_b;
  TLorentzVector trackm(0,0,0,0);
  TLorentzVector trackd1(0,0,0,0); TLorentzVector trackd1_clone(0,0,0,0);
  TLorentzVector trackd2(0,0,0,0);
  
  TVector3 vectord1;
  TVector3 vectord2;
  TVector3 vectormother,vectormother_b;
  
  TLorentzVector trackm_b(0,0,0,0);
  TLorentzVector trackd1_b(0,0,0,0);
  TLorentzVector trackd2_b(0,0,0,0);
  
  TVector3 momentumD(0,0,0);
  TVector3 momentumM(0,0,0);

  TVector3 vectord1_b;
  TVector3 vectord2_b; 
  
  //TH1D *hsig=new TH1D("hsig","Invariant Mass distribution of K*^{0}",90,0.6,1.5);
  //TH1D *hcos=new TH1D("hcos","cos #theta between momentum 3 vector of daughters K^{+} and #pi^{-} ",200,-1,1);
  
  if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
  
  
  cout<<"Number of events are-----------------------------------------------------"<<nentries<<endl;
//***************************EVENT LOOP************************************************************************************************
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++)
   {
      int sum_s=0.0;
      int sum_b=0.0;
     
      Event=jentry;
  
       
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //cout<<"EVENT number---------------------------------------------------------------------------------------------------- "<<jentry<<endl;
     if(jentry%20000==0)cout<<"Number of events processed =========== "<<jentry<<endl;
    
      if(TMath::Abs(fEvSel_VtxZ)<10)
      {
          // Track loop****************************************************************************************************//
     for(k1=0;k1<fTreeEventNTrack;k1++)
      {
              //cout<<"Track  "<<k<<endl;
      if(TMath::Abs(fTreeTrackVariableEta[k1])<0.8 && fTreeTrackVariablePt[k1]>0.15 && fTreeTrackVariableTpcNCrossedRows[k1]>70 && fTreeTrackVariableLeastRatioCrossedRowsOverFindable[k1]>0.8
        && fTreeTrackVariableChiSqrPerTpcCls[k1]<4 && fTreeTrackVariableChiSqrPerItsCls[k1]<36 && TMath::Abs(fTreeTrackVariableDcaZ[k1])<2 
        && TMath::Abs(fTreeTrackVariableDcaXY[k1])< 7*(0.0026 + 0.005/fTreeTrackVariablePt[k1])      )
      {
         //cout<<"Conditions fulfilled  "<<endl; 
         
        for(k2=0;k2<fTreeEventNTrack;k2++)
        { 
        if(TMath::Abs(fTreeTrackVariableEta[k2])<0.8 && fTreeTrackVariablePt[k2]>0.15 && fTreeTrackVariableTpcNCrossedRows[k2]>70 && fTreeTrackVariableLeastRatioCrossedRowsOverFindable[k2]>0.8
        && fTreeTrackVariableChiSqrPerTpcCls[k2]<4 && fTreeTrackVariableChiSqrPerItsCls[k2]<36 && TMath::Abs(fTreeTrackVariableDcaZ[k2])<2 
        && TMath::Abs(fTreeTrackVariableDcaXY[k2])< 7*(0.0026 + 0.005/fTreeTrackVariablePt[k2])      )    
        {
            //----------------SIGNAL---------------------------
        if(fTreeMCPid[k1]==321 && fTreeMCPid[k2]==-211) // K+ =321 and Pi- =-211 ; Kstar0 =313
        {
        //cout<<"We got K+ and Pi- pairs  " <<endl;
        if(fTreeMCMotherTrId[k1]==fTreeMCMotherTrId[k2] && fTreeMCMotherPid[k1]==313 && fTreeMCMotherPid[k2]==313)
        {   
           // cout<<"It is K star0    !!!!   -----------------------------------------------in the Event number="<<jentry<<endl;
           // cout<<"Track mother from 1="<<setw(5)<<fTreeMCMotherTrId[k1]<<" Track Mother from 2="<<setw(5)<<fTreeMCMotherTrId[k2]<<endl;
            //cout<<"PID from 1="<<setw(5)<<fTreeMCMotherPid[k1]<<" PID from 2="<<setw(5)<<fTreeMCMotherPid[k2]<<endl;
            // Mass of K+ =493.677 MeV/c2 .....Mass of Pi =139.57061 MeV/c2
            vectord1.SetXYZ(fTreeTrackVariableMomentumPx[k1],fTreeTrackVariableMomentumPy[k1],fTreeTrackVariableMomentumPz[k1]);
            vectord2.SetXYZ(fTreeTrackVariableMomentumPx[k2],fTreeTrackVariableMomentumPy[k2],fTreeTrackVariableMomentumPz[k2]);
            
            Energyd1=TMath::Sqrt(massK*massK + vectord1.Mag2()   );
            Energyd2=TMath::Sqrt(massPi*massPi + vectord2.Mag2()   );
            
            trackd1.SetPxPyPzE(fTreeTrackVariableMomentumPx[k1],fTreeTrackVariableMomentumPy[k1],fTreeTrackVariableMomentumPz[k1],Energyd1);
            trackd2.SetPxPyPzE(fTreeTrackVariableMomentumPx[k2],fTreeTrackVariableMomentumPy[k2],fTreeTrackVariableMomentumPz[k2],Energyd2);
            trackm=trackd1+trackd2;
            vectormother.SetXYZ(trackm.Px(),trackm.Py(),trackm.Pz());
             trackd1_clone=trackd1;
            if(/*TMath::Abs(trackm.Rapidity())<0.5 &&*/ 0.6<trackm.Mag() && trackm.Mag() <1.2 && trackm.Pt()>=0.8 && trackm.Pt()<=1.2)
            {
                
             motherp_s=vectormother.Mag();
             d1p_s=vectord1.Mag();
             d2p_s=vectord2.Mag();  
                
                
            mass=trackm.Mag();
            invmass_s=mass;
            //hsig->Fill(mass);
            d1pt_s=trackd1.Pt();
            d2pt_s=trackd2.Pt();
            motherpt_s=trackm.Pt();
            
            
            cosangle=(vectord1*vectord2)/(vectord1.Mag()*vectord2.Mag());
            costheta_s=cosangle;
            //hcos->Fill(cosangle);
            
            dcazd1_s=fTreeTrackVariableDcaZ[k1];
            dcazd2_s=fTreeTrackVariableDcaZ[k2];
           // cout<<"Difference dca z d1-d2   "<<dcazd1_s-dcazd2_s<<endl;
            dcaxyd1_s=fTreeTrackVariableDcaXY[k1];
            dcaxyd2_s=fTreeTrackVariableDcaXY[k2];
           //  cout<<"Difference dca xy d1-d2   "<<dcaxyd1_s-dcaxyd2_s<<endl;
            dcad1_s=TMath::Sqrt(dcazd1_s*dcazd1_s + dcaxyd1_s*dcaxyd1_s);
            dcad2_s=TMath::Sqrt(dcazd2_s*dcazd2_s + dcaxyd2_s*dcaxyd2_s);
           // cout<<"Difference dca  d1-d2   "<<dcad1_s-dcad2_s<<endl;
            d1eta_s=fTreeTrackVariableEta[k1];
            d2eta_s=fTreeTrackVariableEta[k2];
            mothereta_s=trackm.Eta();
            motherE_s=trackm.E();
            
             momentumM=trackm.Vect();
		  TVector3 normal(trackm.Y() / trackm.Pt(), -trackm.X() / trackm.Pt(), 0.0);
		  TVector3 normal1(0,0,1);
		  Double_t betaX = -trackm.X() / trackm.E();
		  Double_t betaY = -trackm.Y() / trackm.E();
		  Double_t betaZ = -trackm.Z() / trackm.E();
		  trackd1_clone.Boost(betaX, betaY, betaZ);
		  momentumD = trackd1_clone.Vect();
		  Double_t cosThetaStar = TMath::Abs(normal.Dot(momentumD)) / momentumD.Mag();
		  Double_t cosThetaStar1 = TMath::Abs(normal1.Dot(momentumD)) / momentumD.Mag();
		  costs_s=cosThetaStar;
		  costs1_s=cosThetaStar1;
            
	    tree_sig->Fill();      
            
            }//Rapidity cut 
        }
        } //Pid selection if loop ends  // Signal Loop
        
        
        // Like sign background 
        if(fTreeMCPid[k1]==321 && fTreeMCPid[k2]==211) // K+ =321 and Pi =211 
        {
            
          //  cout<<"Like sign background------------------------------"<<endl;
            vectord1_b.SetXYZ(fTreeTrackVariableMomentumPx[k1],fTreeTrackVariableMomentumPy[k1],fTreeTrackVariableMomentumPz[k1]);
            vectord2_b.SetXYZ(fTreeTrackVariableMomentumPx[k2],fTreeTrackVariableMomentumPy[k2],fTreeTrackVariableMomentumPz[k2]);
            
            Energyd1_b=TMath::Sqrt(massK*massK + vectord1_b.Mag2()   );
            Energyd2_b=TMath::Sqrt(massPi*massPi + vectord2_b.Mag2()   );
            
            trackd1_b.SetPxPyPzE(fTreeTrackVariableMomentumPx[k1],fTreeTrackVariableMomentumPy[k1],fTreeTrackVariableMomentumPz[k1],Energyd1_b);
            trackd2_b.SetPxPyPzE(fTreeTrackVariableMomentumPx[k2],fTreeTrackVariableMomentumPy[k2],fTreeTrackVariableMomentumPz[k2],Energyd2_b);
            trackm_b=trackd1_b+trackd2_b;
            vectormother_b.SetXYZ(trackm_b.Px(),trackm_b.Py(),trackm_b.Pz());
             trackd1_clone=trackd1_b;
             if(/*TMath::Abs(trackm_b.Rapidity())<0.5  &&*/ 0.6< trackm_b.Mag() && trackm_b.Mag()<1.2 && trackm_b.Pt()>=0.8 && trackm_b.Pt()<=1.2)
            {
                 
             
                   
             motherp_b=vectormother_b.Mag();
             d1p_b=vectord1_b.Mag();
             d2p_b=vectord2_b.Mag();  
            mass_b=trackm_b.Mag();
            invmass_b=mass_b;
            //hsig->Fill(mass);
            d1pt_b=trackd1_b.Pt();
            d2pt_b=trackd2_b.Pt();
            motherpt_b=trackm_b.Pt();
            
            
            cosangle_b=(vectord1_b*vectord2_b)/(vectord1_b.Mag()*vectord2_b.Mag());
            costheta_b=cosangle_b;
            //hcos->Fill(cosangle);
            
            dcazd1_b=fTreeTrackVariableDcaZ[k1];
            dcazd2_b=fTreeTrackVariableDcaZ[k2];
            // cout<<"Difference  bkg dca z d1-d2   "<<dcazd1_b-dcazd2_b<<endl;
            dcaxyd1_b=fTreeTrackVariableDcaXY[k1];
            dcaxyd2_b=fTreeTrackVariableDcaXY[k2];
              //cout<<"Difference dca bkg xy d1-d2   "<<dcaxyd1_b-dcaxyd2_b<<endl;
            dcad1_b=TMath::Sqrt(dcazd1_b*dcazd1_b + dcaxyd1_b*dcaxyd1_b);
            dcad2_b=TMath::Sqrt(dcazd2_b*dcazd2_b + dcaxyd2_b*dcaxyd2_b);
             // cout<<"Difference dca bkg d1-d2   "<<dcad1_b-dcad2_b<<endl;
            d1eta_b=fTreeTrackVariableEta[k1];
            d2eta_b=fTreeTrackVariableEta[k2];
            mothereta_b=trackm_b.Eta();
            motherE_b=trackm_b.E();
            
               momentumM=trackm_b.Vect();
		  TVector3 normal(trackm_b.Y() / trackm_b.Pt(), -trackm_b.X() / trackm_b.Pt(), 0.0);
		  TVector3 normal1(0,0,1);
		  Double_t betaX = -trackm_b.X() / trackm_b.E();
		  Double_t betaY = -trackm_b.Y() / trackm_b.E();
		  Double_t betaZ = -trackm_b.Z() / trackm_b.E();
		  trackd1_clone.Boost(betaX, betaY, betaZ);
		  momentumD = trackd1_clone.Vect();
		  Double_t cosThetaStar = TMath::Abs(normal.Dot(momentumD)) / momentumD.Mag();
		  Double_t cosThetaStar1 = TMath::Abs(normal1.Dot(momentumD)) / momentumD.Mag();
		  costs_b=cosThetaStar;
		  costs1_b=cosThetaStar1;
          
            tree_bkg->Fill();       
            } //Rapidity cut
        } // Like sign ends ++-----------------
        
      /*  if(fTreeMCPid[k1]==-321 && fTreeMCPid[k2]==-211) // K+ =321 and Pi =211 
        {
            
          //  cout<<"Like sign background------------------------------"<<endl;
            vectord1_b.SetXYZ(fTreeTrackVariableMomentumPx[k1],fTreeTrackVariableMomentumPy[k1],fTreeTrackVariableMomentumPz[k1]);
            vectord2_b.SetXYZ(fTreeTrackVariableMomentumPx[k2],fTreeTrackVariableMomentumPy[k2],fTreeTrackVariableMomentumPz[k2]);
            
            Energyd1_b=TMath::Sqrt(massK*massK + vectord1_b.Mag2()   );
            Energyd2_b=TMath::Sqrt(massPi*massPi + vectord2_b.Mag2()   );
            
            trackd1_b.SetPxPyPzE(fTreeTrackVariableMomentumPx[k1],fTreeTrackVariableMomentumPy[k1],fTreeTrackVariableMomentumPz[k1],Energyd1_b);
            trackd2_b.SetPxPyPzE(fTreeTrackVariableMomentumPx[k2],fTreeTrackVariableMomentumPy[k2],fTreeTrackVariableMomentumPz[k2],Energyd2_b);
            trackm_b=trackd1_b+trackd2_b;
            vectormother_b.SetXYZ(trackm_b.Px(),trackm_b.Py(),trackm_b.Pz());
             if(TMath::Abs(trackm_b.Rapidity())<0.5 && 0.6< trackm_b.Mag() && trackm_b.Mag()<1.2)
            {
             motherp_b=vectormother_b.Mag();
             d1p_b=vectord1_b.Mag();
             d2p_b=vectord2_b.Mag();
            mass_b=trackm_b.Mag();
            invmass_b=mass_b;
            //hsig->Fill(mass);
            d1pt_b=trackd1_b.Pt();
            d2pt_b=trackd2_b.Pt();
            motherpt_b=trackm_b.Pt();
            
            
            cosangle_b=(vectord1_b*vectord2_b)/(vectord1_b.Mag()*vectord2_b.Mag());
            costheta_b=cosangle_b;
            //hcos->Fill(cosangle);
            
            dcazd1_b=fTreeTrackVariableDcaZ[k1];
            dcazd2_b=fTreeTrackVariableDcaZ[k2];
            // cout<<"Difference  bkg dca z d1-d2   "<<dcazd1_b-dcazd2_b<<endl;
            dcaxyd1_b=fTreeTrackVariableDcaXY[k1];
            dcaxyd2_b=fTreeTrackVariableDcaXY[k2];
              //cout<<"Difference dca bkg xy d1-d2   "<<dcaxyd1_b-dcaxyd2_b<<endl;
            dcad1_b=TMath::Sqrt(dcazd1_b*dcazd1_b + dcaxyd1_b*dcaxyd1_b);
            dcad2_b=TMath::Sqrt(dcazd2_b*dcazd2_b + dcaxyd2_b*dcaxyd2_b);
             // cout<<"Difference dca bkg d1-d2   "<<dcad1_b-dcad2_b<<endl;
            tree_bkg->Fill();       
            } //Rapidity cut
        } // Like sign ends --    -----------------*/
        
        
        
        
        
        
        } //selection conditions for track2
        
        } //k2 track for loop ends
         
         
         
         
          
      } // selection conditions if ends  
              
      }// **************end of TRACK1 loop**************************
          
          
          
          
      } // Event selection conditions
      
            
      
   } // **********************End of Event loop*************************

    //hsig->Draw();
   // hcos->Draw();
    
    f1->cd();
  tree_sig->Write();
  tree_bkg->Write();
  f1->Close();
    
}
