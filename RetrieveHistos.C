#include <TFile.h>
#include <TDirectory.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>

void retrieveMC(const char* filename = "/Users/fernandatorres/Desktop/Omegac_analysis/ROOTFiles/MC/LHC24e3/AO2D_363960.root") {
    
    // Open ROOT file
    TFile *file = new TFile(filename);
    TDirectory *dir = (TDirectory*)file->Get("DF_2261906078565142");
    TTree *tree = (TTree*)dir->Get("O2hfkfomegacfull");
    
    // Create canvas and draw branch
    TCanvas* canvas = new TCanvas("canvas", "MC Histogram", 800, 600);
    tree->Draw("fInvMassCharmBaryon>>hInvMassCharmBaryonToOmegaPi");
    // example for binning: tree.Draw("sqrt(x)>>hsqrt(500,10,20)")
    
    // Retrieve the histogram
    TH1D* hInvMassCharmBaryonToOmegaPi = (TH1D*)gDirectory->Get("hInvMassCharmBaryonToOmegaPi");

    // Title and axis labels
    hInvMassCharmBaryonToOmegaPi->SetTitle("Charm baryon invariant mass - #Omega #pi decay");
    hInvMassCharmBaryonToOmegaPi->GetXaxis()->SetTitle("inv. Mass (GeV/#it{c}^{2})");
    hInvMassCharmBaryonToOmegaPi->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hInvMassCharmBaryonToOmegaPi->Draw();
    
    // Legend
    TLegend *legend = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend->AddEntry(hInvMassCharmBaryonToOmegaPi, "MC", "l");
    legend->Draw();
    
    // Define the path and save the canvas
    const char* savePath = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fInvMassCharmBaryon_MC_LHC24e3.pdf";
    canvas->SaveAs(savePath);
    
    // Checking binning
    std::cout << "Number of bins for MC Inv. Mass: " << hInvMassCharmBaryonToOmegaPi->GetNbinsX() << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas2 = new TCanvas("canvas2", "MC Histogram", 900, 600);
    tree->Draw("fCosPaV0ToPv>>hCosPaV0ToPv");
    
    // Retrieve the histogram
    TH1D* hCosPaV0ToPv = (TH1D*)gDirectory->Get("hCosPaV0ToPv"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaV0ToPv->GetXaxis()->SetTitle("fCosPaV0ToPv");
    hCosPaV0ToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaV0ToPv->Draw();
    
    // Legend
    TLegend *legend2 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend2->AddEntry(hCosPaV0ToPv, "MC", "l");
    legend2->Draw();
    
    // Define the path and save the canvas
    const char* savePath2 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fCosPaV0ToPv_MC_LHC24e3.pdf";
    canvas2->SaveAs(savePath2);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas3 = new TCanvas("canvas3", "MC Histogram", 900, 600);
    tree->Draw("fV0ldl>>hV0ldl");
    
    // Retrieve the histogram
    TH1D* hV0ldl = (TH1D*)gDirectory->Get("hV0ldl"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hV0ldl->GetXaxis()->SetTitle("fV0ldl");
    hV0ldl->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hV0ldl->Draw();
    
    // Legend
    TLegend *legend3 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend3->AddEntry(hV0ldl, "MC", "l");
    legend3->Draw();
    
    // Define the path and save the canvas
    const char* savePath3 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fV0ldl_MC_LHC24e3.pdf";
    canvas3->SaveAs(savePath3);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas4 = new TCanvas("canvas4", "MC Histogram", 900, 600);
    tree->Draw("fCosPaCascToPv>>hCosPaCascToPv");
    
    // Retrieve the histogram
    TH1D* hCosPaCascToPv = (TH1D*)gDirectory->Get("hCosPaCascToPv"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaCascToPv->GetXaxis()->SetTitle("fCosPaCascToPv");
    hCosPaCascToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaCascToPv->Draw();
    
    // Legend
    TLegend *legend4 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend4->AddEntry(hCosPaCascToPv, "MC", "l");
    legend4->Draw();
    
    // Define the path and save the canvas
    const char* savePath4 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fCosPaCascToPv_MC_LHC24e3.pdf";
    canvas4->SaveAs(savePath4);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas5 = new TCanvas("canvas5", "MC Histogram", 900, 600);
    tree->Draw("fDcaCascDau>>hDcaCascDau");
    
    // Retrieve the histogram
    TH1D* hDcaCascDau = (TH1D*)gDirectory->Get("hDcaCascDau"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaCascDau->GetXaxis()->SetTitle("fDcaCascDau");
    hDcaCascDau->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaCascDau->Draw();
    
    // Legend
    TLegend *legend5 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend5->AddEntry(hDcaCascDau, "MC", "l");
    legend5->Draw();
    
    // Define the path and save the canvas
    const char* savePath5 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaCascDau_MC_LHC24e3.pdf";
    canvas5->SaveAs(savePath5);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas6 = new TCanvas("canvas6", "MC Histogram", 900, 600);
    tree->Draw("fCascldl>>hCascldl");
    
    // Retrieve the histogram
    TH1D* hCascldl = (TH1D*)gDirectory->Get("hCascldl"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCascldl->GetXaxis()->SetTitle("fCascldl");
    hCascldl->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCascldl->Draw();
    
    // Legend
    TLegend *legend6 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend6->AddEntry(hCascldl, "MC", "l");
    legend6->Draw();
    
    // Define the path and save the canvas
    const char* savePath6 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fCascldl_MC_LHC24e3.pdf";
    canvas6->SaveAs(savePath6);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas7 = new TCanvas("canvas7", "MC Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau0>>hKFParticleDcaXYV0DauPosToPv");
    
    // Retrieve the histogram
    TH1D* hKFParticleDcaXYV0DauPosToPv = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauPosToPv");
    
    // Axis labels
    hKFParticleDcaXYV0DauPosToPv->GetXaxis()->SetTitle("fDcaXYToPvV0Dau0");
    hKFParticleDcaXYV0DauPosToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauPosToPv->Draw();
    
    // Legend
    TLegend *legend7 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend7->AddEntry(hKFParticleDcaXYV0DauPosToPv, "MC", "l");
    legend7->Draw();
    
    // Define the path and save the canvas
    const char* savePath7 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaXYToPvV0Dau0_MC_LHC24e3.pdf";
    canvas7->SaveAs(savePath7);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas8 = new TCanvas("canvas8", "MC Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau1>>hKFParticleDcaXYV0DauNegToPv");
    
    // Retrieve the histogram
    TH1D* hKFParticleDcaXYV0DauNegToPv = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauNegToPv");
    
    // Axis labels
    hKFParticleDcaXYV0DauNegToPv->GetXaxis()->SetTitle("fDcaXYToPvV0Dau1");
    hKFParticleDcaXYV0DauNegToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauNegToPv->Draw();
    
    // Legend
    TLegend *legend8 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend8->AddEntry(hKFParticleDcaXYV0DauNegToPv, "MC", "l");
    legend8->Draw();
    
    // Define the path and save the canvas
    const char* savePath8 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaXYToPvV0Dau1_MC_LHC24e3.pdf";
    canvas8->SaveAs(savePath8);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas9 = new TCanvas("canvas9", "MC Histogram", 900, 600);
    tree->Draw("fDcaXYToPvCascDau>>hDcaXYToPvCascDau");
    
    // Retrieve the histogram
    TH1D* hDcaXYToPvCascDau = (TH1D*)gDirectory->Get("hDcaXYToPvCascDau"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaXYToPvCascDau->GetXaxis()->SetTitle("fDcaXYToPvCascDau");
    hDcaXYToPvCascDau->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaXYToPvCascDau->Draw();
    
    // Legend
    TLegend *legend9 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend9->AddEntry(hDcaXYToPvCascDau, "MC", "l");
    legend9->Draw();
    
    // Define the path and save the canvas
    const char* savePath9 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaXYToPvCascDau_MC_LHC24e3.pdf";
    canvas9->SaveAs(savePath9);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas10 = new TCanvas("canvas10", "MC Histogram", 900, 600);
    tree->Draw("fDcaCharmBaryonDau>>hKFParticleDcaCharmBaryonDau");
    
    // Retrieve the histogram
    TH1D* hKFParticleDcaCharmBaryonDau = (TH1D*)gDirectory->Get("hKFParticleDcaCharmBaryonDau");
    
    // Axis labels
    hKFParticleDcaCharmBaryonDau->GetXaxis()->SetTitle("fDcaCharmBaryonDau");
    hKFParticleDcaCharmBaryonDau->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaCharmBaryonDau->Draw();
    
    // Legend
    TLegend *legend10 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend10->AddEntry(hKFParticleDcaCharmBaryonDau, "MC", "l");
    legend10->Draw();
    
    // Define the path and save the canvas
    const char* savePath10 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaCharmBaryonDau_MC_LHC24e3.pdf";
    canvas10->SaveAs(savePath10);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas11 = new TCanvas("canvas11", "MC Histogram", 900, 600);
    tree->Draw("fKfptPiFromOmegac>>hPtPiFromCharmBaryon");
    
    // Retrieve the histogram
    TH1D* hPtPiFromCharmBaryon = (TH1D*)gDirectory->Get("hPtPiFromCharmBaryon");
    
    // Axis labels
    hPtPiFromCharmBaryon->GetXaxis()->SetTitle("fKfptPiFromOmegac");
    hPtPiFromCharmBaryon->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hPtPiFromCharmBaryon->Draw();
    
    // Legend
    TLegend *legend11 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend11->AddEntry(hPtPiFromCharmBaryon, "MC", "l");
    legend11->Draw();
    
    // Define the path and save the canvas
    const char* savePath11 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fKfptPiFromOmegac_MC_LHC24e3.pdf";
    canvas11->SaveAs(savePath11);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas12 = new TCanvas("canvas12", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCKaFromCasc>>hNSigmaTPCKaFromCasc");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCKaFromCasc = (TH1D*)gDirectory->Get("hNSigmaTPCKaFromCasc"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCKaFromCasc->GetXaxis()->SetTitle("hNSigmaTPCKaFromCasc");
    hNSigmaTPCKaFromCasc->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCKaFromCasc->Draw();
    
    // Legend
    TLegend *legend12 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend12->AddEntry(hNSigmaTPCKaFromCasc, "MC", "l");
    legend12->Draw();
    
    // Define the path and save the canvas
    const char* savePath12 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCKaFromCasc_MC_LHC24e3.pdf";
    canvas12->SaveAs(savePath12);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas13 = new TCanvas("canvas13", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromV0>>hNSigmaTPCPiFromV0");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCPiFromV0 = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromV0"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromV0->GetXaxis()->SetTitle("fNSigmaTPCPiFromV0");
    hNSigmaTPCPiFromV0->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromV0->Draw();
    
    // Legend
    TLegend *legend13 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend13->AddEntry(hNSigmaTPCPiFromV0, "MC", "l");
    legend13->Draw();
    
    // Define the path and save the canvas
    const char* savePath13 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCPiFromV0_MC_LHC24e3.pdf";
    canvas13->SaveAs(savePath13);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas14 = new TCanvas("canvas14", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPrFromV0>>hNSigmaTPCPrFromV0");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCPrFromV0 = (TH1D*)gDirectory->Get("hNSigmaTPCPrFromV0"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPrFromV0->GetXaxis()->SetTitle("fNSigmaTPCPrFromV0");
    hNSigmaTPCPrFromV0->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPrFromV0->Draw();
    
    // Legend
    TLegend *legend14 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend14->AddEntry(hNSigmaTPCPrFromV0, "MC", "l");
    legend14->Draw();
    
    // Define the path and save the canvas
    const char* savePath14 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCPrFromV0_MC_LHC24e3.pdf";
    canvas14->SaveAs(savePath14);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas15 = new TCanvas("canvas15", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromOmegac>>hNSigmaTPCPiFromOmegac");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCPiFromOmegac = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromOmegac"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromOmegac->GetXaxis()->SetTitle("fNSigmaTPCPiFromOmegac");
    hNSigmaTPCPiFromOmegac->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromOmegac->Draw();
    
    // Legend
    TLegend *legend15 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend15->AddEntry(hNSigmaTPCPiFromOmegac, "MC", "l");
    legend15->Draw();
    
    // Define the path and save the canvas
    const char* savePath15 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCPiFromOmegac_MC_LHC24e3.pdf";
    canvas15->SaveAs(savePath15);
}

//----------------------------------------------------------------------------------------------------------------------------

void retrieveData(const char* filename = "/Users/fernandatorres/Desktop/Omegac_analysis/ROOTFiles/Data/LHC23_apass4/AO2D_365078.root") {
    
    // Open ROOT file
    TFile *file = new TFile(filename);
    TDirectory *dir = (TDirectory*)file->Get("DF_2300440396766976");
    TTree *tree = (TTree*)dir->Get("O2hfkfomegacfull");

    // Create canvas and draw branch
    TCanvas* canvas = new TCanvas("canvas", "Data Histogram", 900, 600);
    tree->Draw("fInvMassCharmBaryon>>hInvMassCharmBaryonToOmegaPi");

    // Retrieve the histogram
    TH1D* hInvMassCharmBaryonToOmegaPi = (TH1D*)gDirectory->Get("hInvMassCharmBaryonToOmegaPi");

    // Title and axis labels
    hInvMassCharmBaryonToOmegaPi->SetTitle("Charm baryon invariant mass - #Omega #pi decay");
    hInvMassCharmBaryonToOmegaPi->GetXaxis()->SetTitle("inv. Mass (GeV/#it{c}^{2})");
    hInvMassCharmBaryonToOmegaPi->GetYaxis()->SetTitle("entries");

    // Draw the histogram
    hInvMassCharmBaryonToOmegaPi->Draw();
    
    // Legend
    TLegend *legend = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend->AddEntry(hInvMassCharmBaryonToOmegaPi, "Data", "l");
    legend->Draw();
    
    // Define the path and save the canvas
    const char* savePath = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fInvMassCharmBaryon_Data_LHC23_apass4.pdf";
    canvas->SaveAs(savePath);
    
    // Checking binning
    std::cout << "Number of bins for Data Inv. Mass: " << hInvMassCharmBaryonToOmegaPi->GetNbinsX() << std::endl;

    
    //----------------------------------------------------------------

    // Create canvas and draw branch
    TCanvas* canvas2 = new TCanvas("canvas2", "Data Histogram", 900, 600);
    tree->Draw("fCosPaV0ToPv>>hCosPaV0ToPv");
    
    // Retrieve the histogram
    TH1D* hCosPaV0ToPv = (TH1D*)gDirectory->Get("hCosPaV0ToPv"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaV0ToPv->GetXaxis()->SetTitle("fCosPaV0ToPv");
    hCosPaV0ToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaV0ToPv->Draw();
    
    // Legend
    TLegend *legend2 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend2->AddEntry(hCosPaV0ToPv, "Data", "l");
    legend2->Draw();
    
    // Define the path and save the canvas
    const char* savePath2 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fCosPaV0ToPv_Data_LHC23_apass4.pdf";
    canvas2->SaveAs(savePath2);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas3 = new TCanvas("canvas3", "Data Histogram", 900, 600);
    tree->Draw("fV0ldl>>hV0ldl");
    
    // Retrieve the histogram
    TH1D* hV0ldl = (TH1D*)gDirectory->Get("hV0ldl"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hV0ldl->GetXaxis()->SetTitle("fV0ldl");
    hV0ldl->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hV0ldl->Draw();
    
    // Legend
    TLegend *legend3 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend3->AddEntry(hV0ldl, "Data", "l");
    legend3->Draw();
    
    // Define the path and save the canvas
    const char* savePath3 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fV0ldl_Data_LHC23_apass4.pdf";
    canvas3->SaveAs(savePath3);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas4 = new TCanvas("canvas4", "Data Histogram", 900, 600);
    tree->Draw("fCosPaCascToPv>>hCosPaCascToPv");
    
    // Retrieve the histogram
    TH1D* hCosPaCascToPv = (TH1D*)gDirectory->Get("hCosPaCascToPv"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaCascToPv->GetXaxis()->SetTitle("fCosPaCascToPv");
    hCosPaCascToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaCascToPv->Draw();
    
    // Legend
    TLegend *legend4 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend4->AddEntry(hCosPaCascToPv, "Data", "l");
    legend4->Draw();
    
    // Define the path and save the canvas
    const char* savePath4 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fCosPaCascToPv_Data_LHC23_apass4.pdf";
    canvas4->SaveAs(savePath4);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas5 = new TCanvas("canvas5", "Data Histogram", 900, 600);
    tree->Draw("fDcaCascDau>>hDcaCascDau");
    
    // Retrieve the histogram
    TH1D* hDcaCascDau = (TH1D*)gDirectory->Get("hDcaCascDau"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaCascDau->GetXaxis()->SetTitle("fDcaCascDau");
    hDcaCascDau->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaCascDau->Draw();
    
    // Legend
    TLegend *legend5 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend5->AddEntry(hDcaCascDau, "Data", "l");
    legend5->Draw();
    
    // Define the path and save the canvas
    const char* savePath5 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaCascDau_Data_LHC23_apass4.pdf";
    canvas5->SaveAs(savePath5);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas6 = new TCanvas("canvas6", "Data Histogram", 900, 600);
    tree->Draw("fCascldl>>hCascldl");
    
    // Retrieve the histogram
    TH1D* hCascldl = (TH1D*)gDirectory->Get("hCascldl"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCascldl->GetXaxis()->SetTitle("fCascldl");
    hCascldl->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCascldl->Draw();
    
    // Legend
    TLegend *legend6 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend6->AddEntry(hCascldl, "Data", "l");
    legend6->Draw();
    
    // Define the path and save the canvas
    const char* savePath6 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fCascldl_Data_LHC23_apass4.pdf";
    canvas6->SaveAs(savePath6);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas7 = new TCanvas("canvas7", "Data Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau0>>hKFParticleDcaXYV0DauPosToPv");
    
    // Retrieve the histogram
    TH1D* hKFParticleDcaXYV0DauPosToPv = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauPosToPv");
    
    // Axis labels
    hKFParticleDcaXYV0DauPosToPv->GetXaxis()->SetTitle("fDcaXYToPvV0Dau0");
    hKFParticleDcaXYV0DauPosToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauPosToPv->Draw();
    
    // Legend
    TLegend *legend7 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend7->AddEntry(hKFParticleDcaXYV0DauPosToPv, "Data", "l");
    legend7->Draw();
    
    // Define the path and save the canvas
    const char* savePath7 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaXYToPvV0Dau0_Data_LHC23_apass4.pdf";
    canvas7->SaveAs(savePath7);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas8 = new TCanvas("canvas8", "Data Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau1>>hKFParticleDcaXYV0DauNegToPv");
    
    // Retrieve the histogram
    TH1D* hKFParticleDcaXYV0DauNegToPv = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauNegToPv");
    
    // Axis labels
    hKFParticleDcaXYV0DauNegToPv->GetXaxis()->SetTitle("fDcaXYToPvV0Dau1");
    hKFParticleDcaXYV0DauNegToPv->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauNegToPv->Draw();
    
    // Legend
    TLegend *legend8 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend8->AddEntry(hKFParticleDcaXYV0DauNegToPv, "Data", "l");
    legend8->Draw();
    
    // Define the path and save the canvas
    const char* savePath8 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaXYToPvV0Dau1_Data_LHC23_apass4.pdf";
    canvas8->SaveAs(savePath8);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas9 = new TCanvas("canvas9", "Data Histogram", 900, 600);
    tree->Draw("fDcaXYToPvCascDau>>hDcaXYToPvCascDau");
    
    // Retrieve the histogram
    TH1D* hDcaXYToPvCascDau = (TH1D*)gDirectory->Get("hDcaXYToPvCascDau"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaXYToPvCascDau->GetXaxis()->SetTitle("fDcaXYToPvCascDau");
    hDcaXYToPvCascDau->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaXYToPvCascDau->Draw();
    
    // Legend
    TLegend *legend9 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend9->AddEntry(hDcaXYToPvCascDau, "Data", "l");
    legend9->Draw();
    
    // Define the path and save the canvas
    const char* savePath9 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaXYToPvCascDau_Data_LHC23_apass4.pdf";
    canvas9->SaveAs(savePath9);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas10 = new TCanvas("canvas10", "Data Histogram", 900, 600);
    tree->Draw("fDcaCharmBaryonDau>>hKFParticleDcaCharmBaryonDau");
    
    // Retrieve the histogram
    TH1D* hKFParticleDcaCharmBaryonDau = (TH1D*)gDirectory->Get("hKFParticleDcaCharmBaryonDau");
    
    // Axis labels
    hKFParticleDcaCharmBaryonDau->GetXaxis()->SetTitle("fDcaCharmBaryonDau");
    hKFParticleDcaCharmBaryonDau->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaCharmBaryonDau->Draw();
    
    // Legend
    TLegend *legend10 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend10->AddEntry(hKFParticleDcaCharmBaryonDau, "Data", "l");
    legend10->Draw();
    
    // Define the path and save the canvas
    const char* savePath10 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaCharmBaryonDau_Data_LHC23_apass4.pdf";
    canvas10->SaveAs(savePath10);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas11 = new TCanvas("canvas11", "Data Histogram", 900, 600);
    tree->Draw("fKfptPiFromOmegac>>hPtPiFromCharmBaryon");
    
    // Retrieve the histogram
    TH1D* hPtPiFromCharmBaryon = (TH1D*)gDirectory->Get("hPtPiFromCharmBaryon");
    
    // Axis labels
    hPtPiFromCharmBaryon->GetXaxis()->SetTitle("fKfptPiFromOmegac");
    hPtPiFromCharmBaryon->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hPtPiFromCharmBaryon->Draw();
    
    // Legend
    TLegend *legend11 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend11->AddEntry(hPtPiFromCharmBaryon, "Data", "l");
    legend11->Draw();
    
    // Define the path and save the canvas
    const char* savePath11 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fKfptPiFromOmegac_Data_LHC23_apass4.pdf";
    canvas11->SaveAs(savePath11);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas12 = new TCanvas("canvas12", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCKaFromCasc>>hNSigmaTPCKaFromCasc");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCKaFromCasc = (TH1D*)gDirectory->Get("hNSigmaTPCKaFromCasc"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCKaFromCasc->GetXaxis()->SetTitle("fNSigmaTPCKaFromCasc");
    hNSigmaTPCKaFromCasc->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCKaFromCasc->Draw();
    
    // Legend
    TLegend *legend12 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend12->AddEntry(hNSigmaTPCKaFromCasc, "Data", "l");
    legend12->Draw();
    
    // Define the path and save the canvas
    const char* savePath12 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCKaFromCasc_Data_LHC23_apass4.pdf";
    canvas12->SaveAs(savePath12);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas13 = new TCanvas("canvas13", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromV0>>hNSigmaTPCPiFromV0");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCPiFromV0 = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromV0"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromV0->GetXaxis()->SetTitle("fNSigmaTPCPiFromV0");
    hNSigmaTPCPiFromV0->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromV0->Draw();
    
    // Legend
    TLegend *legend13 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend13->AddEntry(hNSigmaTPCPiFromV0, "Data", "l");
    legend13->Draw();
    
    // Define the path and save the canvas
    const char* savePath13 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCPiFromV0_Data_LHC23_apass4.pdf";
    canvas13->SaveAs(savePath13);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas14 = new TCanvas("canvas14", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPrFromV0>>hNSigmaTPCPrFromV0");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCPrFromV0 = (TH1D*)gDirectory->Get("hNSigmaTPCPrFromV0"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPrFromV0->GetXaxis()->SetTitle("fNSigmaTPCPrFromV0");
    hNSigmaTPCPrFromV0->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPrFromV0->Draw();
    
    // Legend
    TLegend *legend14 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend14->AddEntry(hNSigmaTPCPrFromV0, "Data", "l");
    legend14->Draw();
    
    // Define the path and save the canvas
    const char* savePath14 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCPrFromV0_Data_LHC23_apass4.pdf";
    canvas14->SaveAs(savePath14);
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas15 = new TCanvas("canvas15", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromOmegac>>hNSigmaTPCPiFromOmegac");
    
    // Retrieve the histogram
    TH1D* hNSigmaTPCPiFromOmegac = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromOmegac"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromOmegac->GetXaxis()->SetTitle("fNSigmaTPCPiFromOmegac");
    hNSigmaTPCPiFromOmegac->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromOmegac->Draw();
    
    // Legend
    TLegend *legend15 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend15->AddEntry(hNSigmaTPCPiFromOmegac, "Data", "l");
    legend15->Draw();
    
    // Define the path and save the canvas
    const char* savePath15 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCPiFromOmegac_Data_LHC23_apass4.pdf";
    canvas15->SaveAs(savePath15);
    
}
