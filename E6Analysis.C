#define E6Analysis_cxx
#include "E6Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TFile.h>
#include <TF1.h>
#include <TLorentzVector.h>


void E6Analysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L E6Analysis.C
//      root> E6Analysis t
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
   if (fChain == 0) return;

   int rapMin = -5;
   int rapMax =  5;

   //Statistic and Fitting box
   gStyle->SetOptStat("KsiouRMen");
   gStyle->SetOptFit(11112);

   //output file
   TFile *output = new TFile("E6AnalysisResults.root","RECREATE");

   //histograms
   TH1F *h_eventnumber = new TH1F("h_eventnumber","Number of events",5,0,5);

   //Canvas 
   TCanvas *c1 = new TCanvas("a1","1200E6", 800,600);
   TCanvas *c2 = new TCanvas("a2","1200E6", 800,600);
   TCanvas *c3 = new TCanvas("a3","1200E6", 800,500);
   TCanvas *c4 = new TCanvas("a4","1200E6", 800,500);

   c1->Divide(2,3);
   c1->Draw();
   c2->Divide(2,3);
   c2->Draw();
   c3->Divide(2,1);
   c3->Draw();
   c4->Divide(2,1);
   c4->Draw();



   //For Z Boson
   TH1F *histMassPairZ = new TH1F("histMassPairZ",";m_{Z}(GeV/c^{2});Entries",5./0.02,0.,150.);
   histMassPairZ->SetTitle("Mass Pair Z Histogram");
   TH1F *histPtZ = new TH1F("histPtZ","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtZ->SetTitle("p_{T} Z Histogram");
   TH1F *histRapidityZ = new TH1F("histRapidityZ",";y;Entries",100,rapMin,rapMax);
   histRapidityZ->SetTitle("Rapidity Z Histogram");
   TH1F *histEtaZ = new TH1F("histEtaZ",";#eta;Entries",100,rapMin,rapMax);
   histEtaZ->SetTitle("#eta Z Histogram");
   TH1F *histPhiZ = new TH1F("histPhiZ",";#phi;Entries",100,rapMin,rapMax);
   histPhiZ->SetTitle("#Phi Z Histogram");
   TH1F *histTotalZ = new TH1F("histTotalZ",";ToplamZ;Entries",100,0,5);
   histTotalZ->SetTitle("Toplam Z Histogram");

   //For W
   TH1F *histMassPairW = new TH1F("histMassPairW",";m_{W}(GeV/c^{2});Entries",5./0.02,0.,150.);
   histMassPairW->SetTitle("Mass Pair W Histogram");
   TH1F *histPtW = new TH1F("histPtW","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtW->SetTitle("p_{T} W Histogram");
   TH1F *histRapidityW = new TH1F("histRapidityW",";y;Entries",100,rapMin,rapMax);
   histRapidityW->SetTitle("Rapidity W Histogram");
   TH1F *histEtaW = new TH1F("histEtaW",";#eta;Entries",100,rapMin,rapMax);
   histEtaW->SetTitle("#eta W Histogram");
   TH1F *histPhiW = new TH1F("histPhiW",";#phi;Entries",100,rapMin,rapMax);
   histPhiW->SetTitle("#Phi W Histogram");
   TH1F *histTotalW = new TH1F("histTotalW",";ToplamW;Entries",100,0,5);
   histTotalW->SetTitle("Toplam W Histogram");

   //For E6 d
   TH1F *histMassPaird = new TH1F("histMassPaird",";m_{dZ}(GeV/c^{2});Entries",140.,0.,1500.);
   histMassPaird->SetTitle("Mass Pair d Jet from Z Boson Histogram");
   TH1F *histPtd = new TH1F("histPtd","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtd->SetTitle("p_{T} d  Histogram");
   TH1F *histRapidityd = new TH1F("histRapidityd",";y;Entries",100,rapMin,rapMax);
   histRapidityd->SetTitle("Rapidity d Histogram");
   TH1F *histEtad = new TH1F("histEtad",";#eta;Entries",100,rapMin,rapMax);
   histEtad->SetTitle("#eta d Histogram");
   TH1F *histPhid = new TH1F("histPhid",";#phi;Entries",100,rapMin,rapMax);
   histPhid->SetTitle("#Phi d Histogram");
   TH1F *histTotald = new TH1F("histTotald",";Toplamd;Entries",100,0,5);
   histTotald->SetTitle("Toplam d Histogram");

   //For E6 D
   TH1F *histMassPairD = new TH1F("histMassPairD",";m_{DW}(GeV/c^{2});Entries",140.,0.,1500.);
   histMassPairD->SetTitle("Mass Pair D Jet From W Histogram");
   TH1F *histPtD = new TH1F("histPtD","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtD->SetTitle("p_{T} D Histogram");
   TH1F *histRapidityD = new TH1F("histRapidityD",";y;Entries",100,rapMin,rapMax);
   histRapidityD->SetTitle("Rapidity D Histogram");
   TH1F *histEtaD = new TH1F("histEtaD",";#eta;Entries",100,rapMin,rapMax);
   histEtaD->SetTitle("#eta D Histogram");
   TH1F *histPhiD = new TH1F("histPhiD",";#phi;Entries",100,rapMin,rapMax);
   histPhiD->SetTitle("#Phi D Histogram");
   TH1F *histTotalD = new TH1F("histTotalD",";ToplamD;Entries",100,0,5);
   histTotalD->SetTitle("Toplam D Histogram");

   //get event number
   int eventnumber = 0; 

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //eventnumber=++;
      cout << "Olay Sayisi = " << eventnumber << endl;
      h_eventnumber->Fill(1);
      
      //Define Variables
      TLorentzVector Z;
      TLorentzVector W;
      TLorentzVector D;
      TLorentzVector d;
      TLorentzVector Mde1;
      TLorentzVector Mde2;

      // Declarations
      Z.SetPtEtaPhiM (Particle_PT[2], Particle_Eta[2], Particle_Phi[2], Particle_M[2]);
      W.SetPtEtaPhiM (Particle_PT[3], Particle_Eta[3], Particle_Phi[3], Particle_M[3]);
      D.SetPtEtaPhiM (Particle_PT[4], Particle_Eta[4], Particle_Phi[4], Particle_M[4]);
      d.SetPtEtaPhiM (Particle_PT[5], Particle_Eta[5], Particle_Phi[5], Particle_M[5]);

      // Mass Calculation for E6
      Mde1 = Z + d;
      Mde2 = W + D;


      //Filling Histograms

      // E6 d
      histMassPaird->Fill(Mde1.M());
      histPtd->Fill(Mde1.Pt());
      histRapidityd->Fill(Mde1.Rapidity());
      histEtad->Fill(Mde1.Eta());
      histPhid->Fill(Mde1.Phi());

      // E6 D
      histMassPairD->Fill(Mde2.M());
      histPtD->Fill(Mde2.Pt());
      histRapidityD->Fill(Mde2.Rapidity());
      histEtaD->Fill(Mde2.Eta());
      histPhiD->Fill(Mde2.Phi());

      //Z
      histMassPairZ->Fill(Z.M());
      histPtZ->Fill(Z.Pt());
      histRapidityZ->Fill(Z.Rapidity());
      histEtaZ->Fill(Z.Eta());
      histPhiZ->Fill(Z.Phi());

      //W
      histMassPairW->Fill(W.M());
      histPtW->Fill(W.Pt());
      histRapidityW->Fill(W.Rapidity());
      histEtaW->Fill(W.Eta());
      histPhiW->Fill(W.Phi());


      
  } // end main event loop

      
      output->cd();

      h_eventnumber->Write();
      histMassPaird->Write();
      histPtd->Write();
      histRapidityd->Write();
      histEtad->Write();
      histPhid->Write();

      h_eventnumber->Write();
      histMassPairD->Write();
      histPtD->Write();
      histRapidityD->Write();
      histEtaD->Write();
      histPhiD->Write();

      h_eventnumber->Write();
      histMassPairZ->Write();
      histPtZ->Write();
      histRapidityZ->Write();
      histEtaZ->Write();
      histPhiZ->Write();

      h_eventnumber->Write();
      histMassPairW->Write();
      histPtW->Write();
      histRapidityW->Write();
      histEtaW->Write();
      histPhiW->Write();

      //Canvas
      c1->cd(1); histPtZ->Draw();
      c1->cd(3); histEtaZ->Draw();
      c1->cd(5); histPhiZ->Draw();
      c1->cd(2); histPtW->Draw();
      c1->cd(4); histEtaW->Draw();
      c1->cd(6); histPhiW->Draw();
      c1->SaveAs("ZveWDagilimlar.ps");

      c2->cd(1); histPtd->Draw();
      c2->cd(3); histEtad->Draw();
      c2->cd(5); histPhid->Draw();
      c2->cd(2); histPtD->Draw();
      c2->cd(4); histEtaD->Draw();
      c2->cd(6); histPhiD->Draw();
      c2->SaveAs("JetDagilimlar.ps");

      c3->cd(2); histMassPairW->Draw();
      gPad->SetLogy();
      c3->cd(1); histMassPairZ->Draw();
      gPad->SetLogy();
      c3->SaveAs("ZveWMassDagilimlarr.ps");

      c4->cd(2); histMassPaird->Draw();
      gPad->SetLogy();
      c4->cd(1); histMassPairD->Draw();
      gPad->SetLogy();
      c4->SaveAs("JetMassDagilimlar.ps");

      

      output->Close();
      cout << "Finished!!!" << endl;

}
