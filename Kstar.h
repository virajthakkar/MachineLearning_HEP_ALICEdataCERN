//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct  5 19:47:07 2018 by ROOT version 6.10/04
// from TTree fTreeEvent/Event
// found on file: total.root
//////////////////////////////////////////////////////////

#ifndef Kstar_h
#define Kstar_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Kstar {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         fAmplitude_V0A;
   Float_t         fAmplitude_V0C;
   Float_t         fAmplitude_V0AEq;
   Float_t         fAmplitude_V0CEq;
   Float_t         fPPVsMult_V0A;
   Float_t         fPPVsMult_V0C;
   Float_t         fPPVsMult_V0M;
   Float_t         fPPVsMult_V0AEq;
   Float_t         fPPVsMult_V0CEq;
   Float_t         fPPVsMult_V0MEq;
   Float_t         fPPVsMult_V0B;
   Float_t         fPPVsMult_V0Apartial;
   Float_t         fPPVsMult_V0Cpartial;
   Float_t         fPPVsMult_V0S;
   Float_t         fPPVsMult_V0SB;
   Int_t           fRefMultEta5;
   Int_t           fRefMultEta8;
   Int_t           fRefMultDiffEta[20];
   Int_t           fTrueMultEta5;
   Int_t           fTrueMultEta8;
   Int_t           fTrueMultVZEROA;
   Int_t           fTrueMultVZEROC;
   Int_t           fRunNumber;
   Int_t           fEvSel_MCType;
   Bool_t          fEvSel_HasAtLeastSPDVertex;
   Bool_t          fEvSel_VtxZCut;
   Bool_t          fEvSel_IsNotPileup;
   Bool_t          fEvSel_IsNotPileupMV;
   Bool_t          fEvSel_IsNotPileupInMultBins;
   Bool_t          fEvSel_Triggered;
   Bool_t          fEvSel_IsINELgtZERO;
   Int_t           fEvSel_nTracklets;
   Int_t           fEvSel_nSPDClusters;
   Float_t         fEvSel_VtxZ;
   Int_t           fEvSel_nSPDPrimVertices;
   Float_t         fEvSel_distZ;
   Int_t           fEvSel_nContributors;
   Int_t           fEvSel_nContributorsPileup;
   Int_t           fTreeEventNTrack;
   Int_t           fTreeMCPid[61];   //[fTreeEventNTrack]
   Int_t           fTreeMCMotherTrId[61];   //[fTreeEventNTrack]
   Int_t           fTreeMCMotherPid[61];   //[fTreeEventNTrack]
   Float_t         fTreeMCRapidity[61];   //[fTreeEventNTrack]
   Float_t         fTreeMCPx[61];   //[fTreeEventNTrack]
   Float_t         fTreeMCPy[61];   //[fTreeEventNTrack]
   Float_t         fTreeMCPz[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableEta[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariablePhi[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariablePt[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableY[61];   //[fTreeEventNTrack]
   Int_t           fTreeTrackVariableCharge[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableMomentum[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableMomentumPx[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableMomentumPy[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableMomentumPz[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTpcMomentum[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTpcSignal[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableDcaXY[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableDcaZ[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTpcNCls[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTpcNCrossedRows[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableLeastRatioCrossedRowsOverFindable[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableChiSqrPerTpcCls[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableChiSqrPerItsCls[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTPCNSigmaPion[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTPCNSigmaKaon[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTPCNSigmaProton[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTOFNSigmaPion[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTOFNSigmaKaon[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTOFNSigmaProton[61];   //[fTreeEventNTrack]
   Float_t         fTreeTrackVariableTOFBeta[61];   //[fTreeEventNTrack]

   // List of branches
   TBranch        *b_fAmplitude_V0A;   //!
   TBranch        *b_fAmplitude_V0C;   //!
   TBranch        *b_fAmplitude_V0AEq;   //!
   TBranch        *b_fAmplitude_V0CEq;   //!
   TBranch        *b_fPPVsMult_V0A;   //!
   TBranch        *b_fPPVsMult_V0C;   //!
   TBranch        *b_fPPVsMult_V0M;   //!
   TBranch        *b_fPPVsMult_V0AEq;   //!
   TBranch        *b_fPPVsMult_V0CEq;   //!
   TBranch        *b_fPPVsMult_V0MEq;   //!
   TBranch        *b_fPPVsMult_V0B;   //!
   TBranch        *b_fPPVsMult_V0Apartial;   //!
   TBranch        *b_fPPVsMult_V0Cpartial;   //!
   TBranch        *b_fPPVsMult_V0S;   //!
   TBranch        *b_fPPVsMult_V0SB;   //!
   TBranch        *b_fRefMultEta5;   //!
   TBranch        *b_fRefMultEta8;   //!
   TBranch        *b_fRefMultDiffEta;   //!
   TBranch        *b_fTrueMultEta5;   //!
   TBranch        *b_fTrueMultEta8;   //!
   TBranch        *b_fTrueMultVZEROA;   //!
   TBranch        *b_fTrueMultVZEROC;   //!
   TBranch        *b_fRunNumber;   //!
   TBranch        *b_fEvSel_MCType;   //!
   TBranch        *b_fEvSel_HasAtLeastSPDVertex;   //!
   TBranch        *b_fEvSel_VtxZCut;   //!
   TBranch        *b_fEvSel_IsNotPileup;   //!
   TBranch        *b_fEvSel_IsNotPileupMV;   //!
   TBranch        *b_fEvSel_IsNotPileupInMultBins;   //!
   TBranch        *b_fEvSel_Triggered;   //!
   TBranch        *b_fEvSel_IsINELgtZERO;   //!
   TBranch        *b_fEvSel_nTracklets;   //!
   TBranch        *b_fEvSel_nSPDClusters;   //!
   TBranch        *b_fEvSel_VtxZ;   //!
   TBranch        *b_fEvSel_nSPDPrimVertices;   //!
   TBranch        *b_fEvSel_distZ;   //!
   TBranch        *b_fEvSel_nContributors;   //!
   TBranch        *b_fEvSel_nContributorsPileup;   //!
   TBranch        *b_fTreeEventNTrack;   //!
   TBranch        *b_fTreeMCPid;   //!
   TBranch        *b_fTreeMCMotherTrId;   //!
   TBranch        *b_fTreeMCMotherPid;   //!
   TBranch        *b_fTreeMCRapidity;   //!
   TBranch        *b_fTreeMCPx;   //!
   TBranch        *b_fTreeMCPy;   //!
   TBranch        *b_fTreeMCPz;   //!
   TBranch        *b_fTreeTrackVariableEta;   //!
   TBranch        *b_fTreeTrackVariablePhi;   //!
   TBranch        *b_fTreeTrackVariablePt;   //!
   TBranch        *b_fTreeTrackVariableY;   //!
   TBranch        *b_fTreeTrackVariableCharge;   //!
   TBranch        *b_fTreeTrackVariableMomentum;   //!
   TBranch        *b_fTreeTrackVariableMomentumPx;   //!
   TBranch        *b_fTreeTrackVariableMomentumPy;   //!
   TBranch        *b_fTreeTrackVariableMomentumPz;   //!
   TBranch        *b_fTreeTrackVariableTpcMomentum;   //!
   TBranch        *b_fTreeTrackVariableTpcSignal;   //!
   TBranch        *b_fTreeTrackVariableDcaXY;   //!
   TBranch        *b_fTreeTrackVariableDcaZ;   //!
   TBranch        *b_fTreeTrackVariableTpcNCls;   //!
   TBranch        *b_fTreeTrackVariableTpcNCrossedRows;   //!
   TBranch        *b_fTreeTrackVariableLeastRatioCrossedRowsOverFindable;   //!
   TBranch        *b_fTreeTrackVariableChiSqrPerTpcCls;   //!
   TBranch        *b_fTreeTrackVariableChiSqrPerItsCls;   //!
   TBranch        *b_fTreeTrackVariableTPCNSigmaPion;   //!
   TBranch        *b_fTreeTrackVariableTPCNSigmaKaon;   //!
   TBranch        *b_fTreeTrackVariableTPCNSigmaProton;   //!
   TBranch        *b_fTreeTrackVariableTOFNSigmaPion;   //!
   TBranch        *b_fTreeTrackVariableTOFNSigmaKaon;   //!
   TBranch        *b_fTreeTrackVariableTOFNSigmaProton;   //!
   TBranch        *b_fTreeTrackVariableTOFBeta;   //!

   Kstar(TTree *tree=0);
   virtual ~Kstar();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Kstar_cxx
Kstar::Kstar(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("total.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("total.root");
      }
      f->GetObject("fTreeEvent",tree);

   }
   Init(tree);
}

Kstar::~Kstar()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Kstar::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Kstar::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Kstar::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fAmplitude_V0A", &fAmplitude_V0A, &b_fAmplitude_V0A);
   fChain->SetBranchAddress("fAmplitude_V0C", &fAmplitude_V0C, &b_fAmplitude_V0C);
   fChain->SetBranchAddress("fAmplitude_V0AEq", &fAmplitude_V0AEq, &b_fAmplitude_V0AEq);
   fChain->SetBranchAddress("fAmplitude_V0CEq", &fAmplitude_V0CEq, &b_fAmplitude_V0CEq);
   fChain->SetBranchAddress("fPPVsMult_V0A", &fPPVsMult_V0A, &b_fPPVsMult_V0A);
   fChain->SetBranchAddress("fPPVsMult_V0C", &fPPVsMult_V0C, &b_fPPVsMult_V0C);
   fChain->SetBranchAddress("fPPVsMult_V0M", &fPPVsMult_V0M, &b_fPPVsMult_V0M);
   fChain->SetBranchAddress("fPPVsMult_V0AEq", &fPPVsMult_V0AEq, &b_fPPVsMult_V0AEq);
   fChain->SetBranchAddress("fPPVsMult_V0CEq", &fPPVsMult_V0CEq, &b_fPPVsMult_V0CEq);
   fChain->SetBranchAddress("fPPVsMult_V0MEq", &fPPVsMult_V0MEq, &b_fPPVsMult_V0MEq);
   fChain->SetBranchAddress("fPPVsMult_V0B", &fPPVsMult_V0B, &b_fPPVsMult_V0B);
   fChain->SetBranchAddress("fPPVsMult_V0Apartial", &fPPVsMult_V0Apartial, &b_fPPVsMult_V0Apartial);
   fChain->SetBranchAddress("fPPVsMult_V0Cpartial", &fPPVsMult_V0Cpartial, &b_fPPVsMult_V0Cpartial);
   fChain->SetBranchAddress("fPPVsMult_V0S", &fPPVsMult_V0S, &b_fPPVsMult_V0S);
   fChain->SetBranchAddress("fPPVsMult_V0SB", &fPPVsMult_V0SB, &b_fPPVsMult_V0SB);
   fChain->SetBranchAddress("fRefMultEta5", &fRefMultEta5, &b_fRefMultEta5);
   fChain->SetBranchAddress("fRefMultEta8", &fRefMultEta8, &b_fRefMultEta8);
   fChain->SetBranchAddress("fRefMultDiffEta", fRefMultDiffEta, &b_fRefMultDiffEta);
   fChain->SetBranchAddress("fTrueMultEta5", &fTrueMultEta5, &b_fTrueMultEta5);
   fChain->SetBranchAddress("fTrueMultEta8", &fTrueMultEta8, &b_fTrueMultEta8);
   fChain->SetBranchAddress("fTrueMultVZEROA", &fTrueMultVZEROA, &b_fTrueMultVZEROA);
   fChain->SetBranchAddress("fTrueMultVZEROC", &fTrueMultVZEROC, &b_fTrueMultVZEROC);
   fChain->SetBranchAddress("fRunNumber", &fRunNumber, &b_fRunNumber);
   fChain->SetBranchAddress("fEvSel_MCType", &fEvSel_MCType, &b_fEvSel_MCType);
   fChain->SetBranchAddress("fEvSel_HasAtLeastSPDVertex", &fEvSel_HasAtLeastSPDVertex, &b_fEvSel_HasAtLeastSPDVertex);
   fChain->SetBranchAddress("fEvSel_VtxZCut", &fEvSel_VtxZCut, &b_fEvSel_VtxZCut);
   fChain->SetBranchAddress("fEvSel_IsNotPileup", &fEvSel_IsNotPileup, &b_fEvSel_IsNotPileup);
   fChain->SetBranchAddress("fEvSel_IsNotPileupMV", &fEvSel_IsNotPileupMV, &b_fEvSel_IsNotPileupMV);
   fChain->SetBranchAddress("fEvSel_IsNotPileupInMultBins", &fEvSel_IsNotPileupInMultBins, &b_fEvSel_IsNotPileupInMultBins);
   fChain->SetBranchAddress("fEvSel_Triggered", &fEvSel_Triggered, &b_fEvSel_Triggered);
   fChain->SetBranchAddress("fEvSel_IsINELgtZERO", &fEvSel_IsINELgtZERO, &b_fEvSel_IsINELgtZERO);
   fChain->SetBranchAddress("fEvSel_nTracklets", &fEvSel_nTracklets, &b_fEvSel_nTracklets);
   fChain->SetBranchAddress("fEvSel_nSPDClusters", &fEvSel_nSPDClusters, &b_fEvSel_nSPDClusters);
   fChain->SetBranchAddress("fEvSel_VtxZ", &fEvSel_VtxZ, &b_fEvSel_VtxZ);
   fChain->SetBranchAddress("fEvSel_nSPDPrimVertices", &fEvSel_nSPDPrimVertices, &b_fEvSel_nSPDPrimVertices);
   fChain->SetBranchAddress("fEvSel_distZ", &fEvSel_distZ, &b_fEvSel_distZ);
   fChain->SetBranchAddress("fEvSel_nContributors", &fEvSel_nContributors, &b_fEvSel_nContributors);
   fChain->SetBranchAddress("fEvSel_nContributorsPileup", &fEvSel_nContributorsPileup, &b_fEvSel_nContributorsPileup);
   fChain->SetBranchAddress("fTreeEventNTrack", &fTreeEventNTrack, &b_fTreeEventNTrack);
   fChain->SetBranchAddress("fTreeMCPid", fTreeMCPid, &b_fTreeMCPid);
   fChain->SetBranchAddress("fTreeMCMotherTrId", fTreeMCMotherTrId, &b_fTreeMCMotherTrId);
   fChain->SetBranchAddress("fTreeMCMotherPid", fTreeMCMotherPid, &b_fTreeMCMotherPid);
   fChain->SetBranchAddress("fTreeMCRapidity", fTreeMCRapidity, &b_fTreeMCRapidity);
   fChain->SetBranchAddress("fTreeMCPx", fTreeMCPx, &b_fTreeMCPx);
   fChain->SetBranchAddress("fTreeMCPy", fTreeMCPy, &b_fTreeMCPy);
   fChain->SetBranchAddress("fTreeMCPz", fTreeMCPz, &b_fTreeMCPz);
   fChain->SetBranchAddress("fTreeTrackVariableEta", fTreeTrackVariableEta, &b_fTreeTrackVariableEta);
   fChain->SetBranchAddress("fTreeTrackVariablePhi", fTreeTrackVariablePhi, &b_fTreeTrackVariablePhi);
   fChain->SetBranchAddress("fTreeTrackVariablePt", fTreeTrackVariablePt, &b_fTreeTrackVariablePt);
   fChain->SetBranchAddress("fTreeTrackVariableY", fTreeTrackVariableY, &b_fTreeTrackVariableY);
   fChain->SetBranchAddress("fTreeTrackVariableCharge", fTreeTrackVariableCharge, &b_fTreeTrackVariableCharge);
   fChain->SetBranchAddress("fTreeTrackVariableMomentum", fTreeTrackVariableMomentum, &b_fTreeTrackVariableMomentum);
   fChain->SetBranchAddress("fTreeTrackVariableMomentumPx", fTreeTrackVariableMomentumPx, &b_fTreeTrackVariableMomentumPx);
   fChain->SetBranchAddress("fTreeTrackVariableMomentumPy", fTreeTrackVariableMomentumPy, &b_fTreeTrackVariableMomentumPy);
   fChain->SetBranchAddress("fTreeTrackVariableMomentumPz", fTreeTrackVariableMomentumPz, &b_fTreeTrackVariableMomentumPz);
   fChain->SetBranchAddress("fTreeTrackVariableTpcMomentum", fTreeTrackVariableTpcMomentum, &b_fTreeTrackVariableTpcMomentum);
   fChain->SetBranchAddress("fTreeTrackVariableTpcSignal", fTreeTrackVariableTpcSignal, &b_fTreeTrackVariableTpcSignal);
   fChain->SetBranchAddress("fTreeTrackVariableDcaXY", fTreeTrackVariableDcaXY, &b_fTreeTrackVariableDcaXY);
   fChain->SetBranchAddress("fTreeTrackVariableDcaZ", fTreeTrackVariableDcaZ, &b_fTreeTrackVariableDcaZ);
   fChain->SetBranchAddress("fTreeTrackVariableTpcNCls", fTreeTrackVariableTpcNCls, &b_fTreeTrackVariableTpcNCls);
   fChain->SetBranchAddress("fTreeTrackVariableTpcNCrossedRows", fTreeTrackVariableTpcNCrossedRows, &b_fTreeTrackVariableTpcNCrossedRows);
   fChain->SetBranchAddress("fTreeTrackVariableLeastRatioCrossedRowsOverFindable", fTreeTrackVariableLeastRatioCrossedRowsOverFindable, &b_fTreeTrackVariableLeastRatioCrossedRowsOverFindable);
   fChain->SetBranchAddress("fTreeTrackVariableChiSqrPerTpcCls", fTreeTrackVariableChiSqrPerTpcCls, &b_fTreeTrackVariableChiSqrPerTpcCls);
   fChain->SetBranchAddress("fTreeTrackVariableChiSqrPerItsCls", fTreeTrackVariableChiSqrPerItsCls, &b_fTreeTrackVariableChiSqrPerItsCls);
   fChain->SetBranchAddress("fTreeTrackVariableTPCNSigmaPion", fTreeTrackVariableTPCNSigmaPion, &b_fTreeTrackVariableTPCNSigmaPion);
   fChain->SetBranchAddress("fTreeTrackVariableTPCNSigmaKaon", fTreeTrackVariableTPCNSigmaKaon, &b_fTreeTrackVariableTPCNSigmaKaon);
   fChain->SetBranchAddress("fTreeTrackVariableTPCNSigmaProton", fTreeTrackVariableTPCNSigmaProton, &b_fTreeTrackVariableTPCNSigmaProton);
   fChain->SetBranchAddress("fTreeTrackVariableTOFNSigmaPion", fTreeTrackVariableTOFNSigmaPion, &b_fTreeTrackVariableTOFNSigmaPion);
   fChain->SetBranchAddress("fTreeTrackVariableTOFNSigmaKaon", fTreeTrackVariableTOFNSigmaKaon, &b_fTreeTrackVariableTOFNSigmaKaon);
   fChain->SetBranchAddress("fTreeTrackVariableTOFNSigmaProton", fTreeTrackVariableTOFNSigmaProton, &b_fTreeTrackVariableTOFNSigmaProton);
   fChain->SetBranchAddress("fTreeTrackVariableTOFBeta", fTreeTrackVariableTOFBeta, &b_fTreeTrackVariableTOFBeta);
   Notify();
}

Bool_t Kstar::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Kstar::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Kstar::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Kstar_cxx
