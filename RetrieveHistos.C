#include <TFile.h>
#include <TDirectory.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>

// To use MC histograms outside the function retrieveMC()
TH1D* hInvMassCharmBaryonToOmegaPi_MC = nullptr;
TH1D* hCosPaV0ToPv_MC = nullptr;
TH1D* hV0ldl_MC = nullptr;
TH1D* hCosPaCascToPv_MC = nullptr;
TH1D* hDcaCascDau_MC = nullptr;
TH1D* hCascldl_MC = nullptr;
TH1D* hKFParticleDcaXYV0DauPosToPv_MC = nullptr;
TH1D* hKFParticleDcaXYV0DauNegToPv_MC = nullptr;
TH1D* hDcaXYToPvCascDau_MC = nullptr;
TH1D* hKFParticleDcaCharmBaryonDau_MC = nullptr;
TH1D* hPtPiFromCharmBaryon_MC = nullptr;
TH1D* hNSigmaTPCKaFromCasc_MC = nullptr;
TH1D* hNSigmaTPCPiFromV0_MC = nullptr;
TH1D* hNSigmaTPCPrFromV0_MC = nullptr;
TH1D* hNSigmaTPCPiFromOmegac_MC = nullptr;

// To use Data histograms outside the function retrieveData()
TH1D* hInvMassCharmBaryonToOmegaPi_Data = nullptr;
TH1D* hCosPaV0ToPv_Data = nullptr;
TH1D* hV0ldl_Data = nullptr;
TH1D* hCosPaCascToPv_Data = nullptr;
TH1D* hDcaCascDau_Data = nullptr;
TH1D* hCascldl_Data = nullptr;
TH1D* hKFParticleDcaXYV0DauPosToPv_Data = nullptr;
TH1D* hKFParticleDcaXYV0DauNegToPv_Data = nullptr;
TH1D* hDcaXYToPvCascDau_Data = nullptr;
TH1D* hKFParticleDcaCharmBaryonDau_Data = nullptr;
TH1D* hPtPiFromCharmBaryon_Data = nullptr;
TH1D* hNSigmaTPCKaFromCasc_Data = nullptr;
TH1D* hNSigmaTPCPiFromV0_Data = nullptr;
TH1D* hNSigmaTPCPrFromV0_Data = nullptr;
TH1D* hNSigmaTPCPiFromOmegac_Data = nullptr;

void retrieveMC(const char* filename = "/Users/fernandatorres/Desktop/Omegac_analysis/ROOTFiles/MC/LHC24e3/AO2D_363960.root") {
    
    // Open ROOT file
    TFile *file = new TFile(filename);
    TDirectory *dir = (TDirectory*)file->Get("DF_2261906078565142");
    TTree *tree = (TTree*)dir->Get("O2hfkfomegacfull");
    
    // Create canvas and draw branch
    TCanvas* canvas_MC = new TCanvas("canvas_MC", "MC Histogram", 800, 600);
    tree->Draw("fInvMassCharmBaryon>>hInvMassCharmBaryonToOmegaPi_MC(100, 2.33, 3.16)");
    
    // Retrieve the histogram
    hInvMassCharmBaryonToOmegaPi_MC = (TH1D*)gDirectory->Get("hInvMassCharmBaryonToOmegaPi_MC");

    // Title and axis labels
    hInvMassCharmBaryonToOmegaPi_MC->SetTitle("Charm baryon invariant mass - #Omega #pi decay");
    hInvMassCharmBaryonToOmegaPi_MC->GetXaxis()->SetTitle("inv. Mass (GeV/#it{c}^{2})");
    hInvMassCharmBaryonToOmegaPi_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hInvMassCharmBaryonToOmegaPi_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC->AddEntry(hInvMassCharmBaryonToOmegaPi_MC, "MC", "l");
    legend_MC->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fInvMassCharmBaryon_MC_LHC24e3.pdf";
    canvas_MC->SaveAs(savePath_MC);
    
    // Checking binning
    // std::cout << "Number of bins for hInvMassCharmBaryonToOmegaPi_MC: " << hInvMassCharmBaryonToOmegaPi_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h1 = hInvMassCharmBaryonToOmegaPi_MC->GetBinLowEdge(1);
    double xmax_h1 = hInvMassCharmBaryonToOmegaPi_MC->GetBinLowEdge(hInvMassCharmBaryonToOmegaPi_MC->GetNbinsX()) +
                     hInvMassCharmBaryonToOmegaPi_MC->GetBinWidth(hInvMassCharmBaryonToOmegaPi_MC->GetNbinsX());
    std::cout << "Minimum x-value for hInvMassCharmBaryonToOmegaPi_MC: " << xmin_h1 << std::endl;
    std::cout << "Maximum x-value for hInvMassCharmBaryonToOmegaPi_MC: " << xmax_h1 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC2 = new TCanvas("canvas_MC2", "MC Histogram", 900, 600);
    tree->Draw("fCosPaV0ToPv>>hCosPaV0ToPv_MC(100, 0.946, 1.004)");
    
    // Retrieve the histogram
    hCosPaV0ToPv_MC = (TH1D*)gDirectory->Get("hCosPaV0ToPv_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaV0ToPv_MC->GetXaxis()->SetTitle("fCosPaV0ToPv");
    hCosPaV0ToPv_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaV0ToPv_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC2 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC2->AddEntry(hCosPaV0ToPv_MC, "MC", "l");
    legend_MC2->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC2 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fCosPaV0ToPv_MC_LHC24e3.pdf";
    canvas_MC2->SaveAs(savePath_MC2);
    
    // Checking binning
    // std::cout << "Number of bins for hCosPaV0ToPv_MC: " << hCosPaV0ToPv_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h2 = hCosPaV0ToPv_MC->GetBinLowEdge(1);
    double xmax_h2 = hCosPaV0ToPv_MC->GetBinLowEdge(hCosPaV0ToPv_MC->GetNbinsX()) +
                     hCosPaV0ToPv_MC->GetBinWidth(hCosPaV0ToPv_MC->GetNbinsX());
    std::cout << "Minimum x-value for hCosPaV0ToPv_MC: " << xmin_h2 << std::endl;
    std::cout << "Maximum x-value for hCosPaV0ToPv_MC: " << xmax_h2 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC3 = new TCanvas("canvas_MC3", "MC Histogram", 900, 600);
    tree->Draw("fV0ldl>>hV0ldl_MC(100, 0, 16400)");
    
    // Retrieve the histogram
    hV0ldl_MC = (TH1D*)gDirectory->Get("hV0ldl_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hV0ldl_MC->GetXaxis()->SetTitle("fV0ldl");
    hV0ldl_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hV0ldl_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC3 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC3->AddEntry(hV0ldl_MC, "MC", "l");
    legend_MC3->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC3 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fV0ldl_MC_LHC24e3.pdf";
    canvas_MC3->SaveAs(savePath_MC3);
    
    // Checking binning
    // std::cout << "Number of bins for hV0ldl_MC: " << hV0ldl_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h3 = hV0ldl_MC->GetBinLowEdge(1);
    double xmax_h3 = hV0ldl_MC->GetBinLowEdge(hV0ldl_MC->GetNbinsX()) +
                     hV0ldl_MC->GetBinWidth(hV0ldl_MC->GetNbinsX());
    std::cout << "Minimum x-value for hV0ldl_MC: " << xmin_h3 << std::endl;
    std::cout << "Maximum x-value for hV0ldl_MC: " << xmax_h3 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC4 = new TCanvas("canvas_MC4", "MC Histogram", 900, 600);
    tree->Draw("fCosPaCascToPv>>hCosPaCascToPv_MC"); // Same range as Data
    
    // Retrieve the histogram
    hCosPaCascToPv_MC = (TH1D*)gDirectory->Get("hCosPaCascToPv_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaCascToPv_MC->GetXaxis()->SetTitle("fCosPaCascToPv");
    hCosPaCascToPv_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaCascToPv_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC4 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC4->AddEntry(hCosPaCascToPv_MC, "MC", "l");
    legend_MC4->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC4 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fCosPaCascToPv_MC_LHC24e3.pdf";
    canvas_MC4->SaveAs(savePath_MC4);
    
    // Checking binning
    // std::cout << "Number of bins for hCosPaCascToPv_MC: " << hCosPaCascToPv_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h4 = hCosPaCascToPv_MC->GetBinLowEdge(1);
    double xmax_h4 = hCosPaCascToPv_MC->GetBinLowEdge(hCosPaCascToPv_MC->GetNbinsX()) +
                     hCosPaCascToPv_MC->GetBinWidth(hCosPaCascToPv_MC->GetNbinsX());
    std::cout << "Minimum x-value for hCosPaCascToPv_MC: " << xmin_h4 << std::endl;
    std::cout << "Maximum x-value for hCosPaCascToPv_MC: " << xmax_h4 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC5 = new TCanvas("canvas_MC5", "MC Histogram", 900, 600);
    tree->Draw("fDcaCascDau>>hDcaCascDau_MC(100, 0, 1.5)");
    
    // Retrieve the histogram
    hDcaCascDau_MC = (TH1D*)gDirectory->Get("hDcaCascDau_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaCascDau_MC->GetXaxis()->SetTitle("fDcaCascDau");
    hDcaCascDau_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaCascDau_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC5 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC5->AddEntry(hDcaCascDau_MC, "MC", "l");
    legend_MC5->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC5 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaCascDau_MC_LHC24e3.pdf";
    canvas_MC5->SaveAs(savePath_MC5);
    
    // Checking binning
    // std::cout << "Number of bins for hDcaCascDau_MC: " << hDcaCascDau_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h5 = hDcaCascDau_MC->GetBinLowEdge(1);
    double xmax_h5 = hDcaCascDau_MC->GetBinLowEdge(hDcaCascDau_MC->GetNbinsX()) +
                     hDcaCascDau_MC->GetBinWidth(hDcaCascDau_MC->GetNbinsX());
    std::cout << "Minimum x-value for hDcaCascDau_MC: " << xmin_h5 << std::endl;
    std::cout << "Maximum x-value for hDcaCascDau_MC: " << xmax_h5 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC6 = new TCanvas("canvas_MC6", "MC Histogram", 900, 600);
    tree->Draw("fCascldl>>hCascldl_MC");
    
    // Retrieve the histogram
    hCascldl_MC = (TH1D*)gDirectory->Get("hCascldl_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCascldl_MC->GetXaxis()->SetTitle("fCascldl");
    hCascldl_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCascldl_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC6 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC6->AddEntry(hCascldl_MC, "MC", "l");
    legend_MC6->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC6 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fCascldl_MC_LHC24e3.pdf";
    canvas_MC6->SaveAs(savePath_MC6);
    
    // Checking binning
    // std::cout << "Number of bins for hCascldl_MC: " << hCascldl_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h6 = hCascldl_MC->GetBinLowEdge(1);
    double xmax_h6 = hCascldl_MC->GetBinLowEdge(hCascldl_MC->GetNbinsX()) +
                     hCascldl_MC->GetBinWidth(hCascldl_MC->GetNbinsX());
    std::cout << "Minimum x-value for hCascldl_MC: " << xmin_h6 << std::endl;
    std::cout << "Maximum x-value for hCascldl_MC: " << xmax_h6 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC7 = new TCanvas("canvas_MC7", "MC Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau0>>hKFParticleDcaXYV0DauPosToPv_MC(100, -12, 7)");
    
    // Retrieve the histogram
    hKFParticleDcaXYV0DauPosToPv_MC = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauPosToPv_MC");
    
    // Axis labels
    hKFParticleDcaXYV0DauPosToPv_MC->GetXaxis()->SetTitle("fDcaXYToPvV0Dau0");
    hKFParticleDcaXYV0DauPosToPv_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauPosToPv_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC7 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC7->AddEntry(hKFParticleDcaXYV0DauPosToPv_MC, "MC", "l");
    legend_MC7->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC7 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaXYToPvV0Dau0_MC_LHC24e3.pdf";
    canvas_MC7->SaveAs(savePath_MC7);
    
    // Checking binning
    // std::cout << "Number of bins for hKFParticleDcaXYV0DauPosToPv_MC: " << hKFParticleDcaXYV0DauPosToPv_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h7 = hKFParticleDcaXYV0DauPosToPv_MC->GetBinLowEdge(1);
    double xmax_h7 = hKFParticleDcaXYV0DauPosToPv_MC->GetBinLowEdge(hKFParticleDcaXYV0DauPosToPv_MC->GetNbinsX()) +
                     hKFParticleDcaXYV0DauPosToPv_MC->GetBinWidth(hKFParticleDcaXYV0DauPosToPv_MC->GetNbinsX());
    std::cout << "Minimum x-value for hKFParticleDcaXYV0DauPosToPv_MC: " << xmin_h7 << std::endl;
    std::cout << "Maximum x-value for hKFParticleDcaXYV0DauPosToPv_MC: " << xmax_h7 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC8 = new TCanvas("canvas_MC8", "MC Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau1>>hKFParticleDcaXYV0DauNegToPv_MC(100, -19, 30)");
    
    // Retrieve the histogram
    hKFParticleDcaXYV0DauNegToPv_MC = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauNegToPv_MC");
    
    // Axis labels
    hKFParticleDcaXYV0DauNegToPv_MC->GetXaxis()->SetTitle("fDcaXYToPvV0Dau1");
    hKFParticleDcaXYV0DauNegToPv_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauNegToPv_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC8 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC8->AddEntry(hKFParticleDcaXYV0DauNegToPv_MC, "MC", "l");
    legend_MC8->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC8 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaXYToPvV0Dau1_MC_LHC24e3.pdf";
    canvas_MC8->SaveAs(savePath_MC8);
    
    // Checking binning
    // std::cout << "Number of bins for hKFParticleDcaXYV0DauNegToPv_MC: " << hKFParticleDcaXYV0DauNegToPv_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h8 = hKFParticleDcaXYV0DauNegToPv_MC->GetBinLowEdge(1);
    double xmax_h8 = hKFParticleDcaXYV0DauNegToPv_MC->GetBinLowEdge(hKFParticleDcaXYV0DauNegToPv_MC->GetNbinsX()) +
                     hKFParticleDcaXYV0DauNegToPv_MC->GetBinWidth(hKFParticleDcaXYV0DauNegToPv_MC->GetNbinsX());
    std::cout << "Minimum x-value for hKFParticleDcaXYV0DauNegToPv_MC: " << xmin_h8 << std::endl;
    std::cout << "Maximum x-value for hKFParticleDcaXYV0DauNegToPv_MC: " << xmax_h8 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC9 = new TCanvas("canvas_MC9", "MC Histogram", 900, 600);
    tree->Draw("fDcaXYToPvCascDau>>hDcaXYToPvCascDau_MC(100, -22, 18.5)");
    
    // Retrieve the histogram
    hDcaXYToPvCascDau_MC = (TH1D*)gDirectory->Get("hDcaXYToPvCascDau_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaXYToPvCascDau_MC->GetXaxis()->SetTitle("fDcaXYToPvCascDau");
    hDcaXYToPvCascDau_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaXYToPvCascDau_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC9 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC9->AddEntry(hDcaXYToPvCascDau_MC, "MC", "l");
    legend_MC9->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC9 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaXYToPvCascDau_MC_LHC24e3.pdf";
    canvas_MC9->SaveAs(savePath_MC9);
    
    // Checking binning
    // std::cout << "Number of bins for hDcaXYToPvCascDau_MC: " << hDcaXYToPvCascDau_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h9 = hDcaXYToPvCascDau_MC->GetBinLowEdge(1);
    double xmax_h9 = hDcaXYToPvCascDau_MC->GetBinLowEdge(hDcaXYToPvCascDau_MC->GetNbinsX()) +
                     hDcaXYToPvCascDau_MC->GetBinWidth(hDcaXYToPvCascDau_MC->GetNbinsX());
    std::cout << "Minimum x-value for hDcaXYToPvCascDau_MC: " << xmin_h9 << std::endl;
    std::cout << "Maximum x-value for hDcaXYToPvCascDau_MC: " << xmax_h9 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC10 = new TCanvas("canvas_MC10", "MC Histogram", 900, 600);
    tree->Draw("fDcaCharmBaryonDau>>hKFParticleDcaCharmBaryonDau_MC(100, 0, 2)");
    
    // Retrieve the histogram
    hKFParticleDcaCharmBaryonDau_MC = (TH1D*)gDirectory->Get("hKFParticleDcaCharmBaryonDau_MC");
    
    // Axis labels
    hKFParticleDcaCharmBaryonDau_MC->GetXaxis()->SetTitle("fDcaCharmBaryonDau");
    hKFParticleDcaCharmBaryonDau_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaCharmBaryonDau_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC10 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_MC10->AddEntry(hKFParticleDcaCharmBaryonDau_MC, "MC", "l");
    legend_MC10->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC10 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fDcaCharmBaryonDau_MC_LHC24e3.pdf";
    canvas_MC10->SaveAs(savePath_MC10);
    
    // Checking binning
    // std::cout << "Number of bins for hKFParticleDcaCharmBaryonDau_MC: " << hKFParticleDcaCharmBaryonDau_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h10 = hKFParticleDcaCharmBaryonDau_MC->GetBinLowEdge(1);
    double xmax_h10 = hKFParticleDcaCharmBaryonDau_MC->GetBinLowEdge(hKFParticleDcaCharmBaryonDau_MC->GetNbinsX()) +
                      hKFParticleDcaCharmBaryonDau_MC->GetBinWidth(hKFParticleDcaCharmBaryonDau_MC->GetNbinsX());
    std::cout << "Minimum x-value for hKFParticleDcaCharmBaryonDau_MC: " << xmin_h10 << std::endl;
    std::cout << "Maximum x-value for hKFParticleDcaCharmBaryonDau_MC: " << xmax_h10 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC11 = new TCanvas("canvas_MC11", "MC Histogram", 900, 600);
    tree->Draw("fKfptPiFromOmegac>>hPtPiFromCharmBaryon_MC(100, 0, 8.8)");
    
    // Retrieve the histogram
    hPtPiFromCharmBaryon_MC = (TH1D*)gDirectory->Get("hPtPiFromCharmBaryon_MC");
    
    // Axis labels
    hPtPiFromCharmBaryon_MC->GetXaxis()->SetTitle("fKfptPiFromOmegac");
    hPtPiFromCharmBaryon_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hPtPiFromCharmBaryon_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC11 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_MC11->AddEntry(hPtPiFromCharmBaryon_MC, "MC", "l");
    legend_MC11->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC11 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fKfptPiFromOmegac_MC_LHC24e3.pdf";
    canvas_MC11->SaveAs(savePath_MC11);
    
    // Checking binning
    // std::cout << "Number of bins for hPtPiFromCharmBaryon_MC: " << hPtPiFromCharmBaryon_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h11 = hPtPiFromCharmBaryon_MC->GetBinLowEdge(1);
    double xmax_h11 = hPtPiFromCharmBaryon_MC->GetBinLowEdge(hPtPiFromCharmBaryon_MC->GetNbinsX()) +
                      hPtPiFromCharmBaryon_MC->GetBinWidth(hPtPiFromCharmBaryon_MC->GetNbinsX());
    std::cout << "Minimum x-value for hPtPiFromCharmBaryon_MC: " << xmin_h11 << std::endl;
    std::cout << "Maximum x-value for hPtPiFromCharmBaryon_MC: " << xmax_h11 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC12 = new TCanvas("canvas_MC12", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCKaFromCasc>>hNSigmaTPCKaFromCasc_MC(100, -12.2, 12)");
    
    // Retrieve the histogram
    hNSigmaTPCKaFromCasc_MC = (TH1D*)gDirectory->Get("hNSigmaTPCKaFromCasc_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCKaFromCasc_MC->GetXaxis()->SetTitle("fNSigmaTPCKaFromCasc");
    hNSigmaTPCKaFromCasc_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCKaFromCasc_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC12 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_MC12->AddEntry(hNSigmaTPCKaFromCasc_MC, "MC", "l");
    legend_MC12->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC12 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCKaFromCasc_MC_LHC24e3.pdf";
    canvas_MC12->SaveAs(savePath_MC12);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCKaFromCasc_MC: " << hNSigmaTPCKaFromCasc_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h12 = hNSigmaTPCKaFromCasc_MC->GetBinLowEdge(1);
    double xmax_h12 = hNSigmaTPCKaFromCasc_MC->GetBinLowEdge(hNSigmaTPCKaFromCasc_MC->GetNbinsX()) +
                      hNSigmaTPCKaFromCasc_MC->GetBinWidth(hNSigmaTPCKaFromCasc_MC->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCKaFromCasc_MC: " << xmin_h12 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCKaFromCasc_MC: " << xmax_h12 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC13 = new TCanvas("canvas_MC13", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromV0>>hNSigmaTPCPiFromV0_MC(100, -4, 4.8)");
    
    // Retrieve the histogram
    hNSigmaTPCPiFromV0_MC = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromV0_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromV0_MC->GetXaxis()->SetTitle("fNSigmaTPCPiFromV0");
    hNSigmaTPCPiFromV0_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromV0_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC13 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_MC13->AddEntry(hNSigmaTPCPiFromV0_MC, "MC", "l");
    legend_MC13->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC13 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCPiFromV0_MC_LHC24e3.pdf";
    canvas_MC13->SaveAs(savePath_MC13);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCPiFromV0_MC: " << hNSigmaTPCPiFromV0_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h13 = hNSigmaTPCPiFromV0_MC->GetBinLowEdge(1);
    double xmax_h13 = hNSigmaTPCPiFromV0_MC->GetBinLowEdge(hNSigmaTPCPiFromV0_MC->GetNbinsX()) +
                      hNSigmaTPCPiFromV0_MC->GetBinWidth(hNSigmaTPCPiFromV0_MC->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCPiFromV0_MC: " << xmin_h13 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCPiFromV0_MC: " << xmax_h13 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC14 = new TCanvas("canvas_MC14", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPrFromV0>>hNSigmaTPCPrFromV0_MC(100, -19.5, 9)");
    
    // Retrieve the histogram
    hNSigmaTPCPrFromV0_MC = (TH1D*)gDirectory->Get("hNSigmaTPCPrFromV0_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPrFromV0_MC->GetXaxis()->SetTitle("fNSigmaTPCPrFromV0");
    hNSigmaTPCPrFromV0_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPrFromV0_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC14 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_MC14->AddEntry(hNSigmaTPCPrFromV0_MC, "MC", "l");
    legend_MC14->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC14 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCPrFromV0_MC_LHC24e3.pdf";
    canvas_MC14->SaveAs(savePath_MC14);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCPrFromV0_MC: " << hNSigmaTPCPrFromV0_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h14 = hNSigmaTPCPrFromV0_MC->GetBinLowEdge(1);
    double xmax_h14 = hNSigmaTPCPrFromV0_MC->GetBinLowEdge(hNSigmaTPCPrFromV0_MC->GetNbinsX()) +
                      hNSigmaTPCPrFromV0_MC->GetBinWidth(hNSigmaTPCPrFromV0_MC->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCPrFromV0_MC: " << xmin_h14 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCPrFromV0_MC: " << xmax_h14 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_MC15 = new TCanvas("canvas_MC15", "MC Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromOmegac>>hNSigmaTPCPiFromOmegac_MC");
    
    // Retrieve the histogram
    hNSigmaTPCPiFromOmegac_MC = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromOmegac_MC"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromOmegac_MC->GetXaxis()->SetTitle("fNSigmaTPCPiFromOmegac");
    hNSigmaTPCPiFromOmegac_MC->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromOmegac_MC->Draw("HIST");
    
    // Legend
    TLegend *legend_MC15 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_MC15->AddEntry(hNSigmaTPCPiFromOmegac_MC, "MC", "l");
    legend_MC15->Draw();
    
    // Define the path and save the canvas
    const char* savePath_MC15 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/fNSigmaTPCPiFromOmegac_MC_LHC24e3.pdf";
    canvas_MC15->SaveAs(savePath_MC15);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCPiFromOmegac_MC: " << hNSigmaTPCPiFromOmegac_MC->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h15 = hNSigmaTPCPiFromOmegac_MC->GetBinLowEdge(1);
    double xmax_h15 = hNSigmaTPCPiFromOmegac_MC->GetBinLowEdge(hNSigmaTPCPiFromOmegac_MC->GetNbinsX()) +
                      hNSigmaTPCPiFromOmegac_MC->GetBinWidth(hNSigmaTPCPiFromOmegac_MC->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCPiFromOmegac_MC: " << xmin_h15 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCPiFromOmegac_MC: " << xmax_h15 << std::endl;
}

//----------------------------------------------------------------------------------------------------------------------------

void retrieveData(const char* filename = "/Users/fernandatorres/Desktop/Omegac_analysis/ROOTFiles/Data/LHC23_apass4/AO2D_365078.root") {
    
    // Open ROOT file
    TFile *file = new TFile(filename);
    TDirectory *dir = (TDirectory*)file->Get("DF_2300440396766976");
    TTree *tree = (TTree*)dir->Get("O2hfkfomegacfull");

    // Create canvas and draw branch
    TCanvas* canvas_Data = new TCanvas("canvas_Data", "Data Histogram", 900, 600);
    tree->Draw("fInvMassCharmBaryon>>hInvMassCharmBaryonToOmegaPi_Data");

    // Retrieve the histogram
    hInvMassCharmBaryonToOmegaPi_Data = (TH1D*)gDirectory->Get("hInvMassCharmBaryonToOmegaPi_Data");
    
    // Title and axis labels
    hInvMassCharmBaryonToOmegaPi_Data->SetTitle("Charm baryon invariant mass - #Omega #pi decay");
    hInvMassCharmBaryonToOmegaPi_Data->GetXaxis()->SetTitle("inv. Mass (GeV/#it{c}^{2})");
    hInvMassCharmBaryonToOmegaPi_Data->GetYaxis()->SetTitle("entries");

    // Draw the histogram
    hInvMassCharmBaryonToOmegaPi_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_Data->AddEntry(hInvMassCharmBaryonToOmegaPi_Data, "Data", "l");
    legend_Data->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fInvMassCharmBaryon_Data_LHC23_apass4.pdf";
    canvas_Data->SaveAs(savePath_Data);
    
    // Checking binning
    // std::cout << "Number of bins for hInvMassCharmBaryonToOmegaPi_Data: " << hInvMassCharmBaryonToOmegaPi_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h1 = hInvMassCharmBaryonToOmegaPi_Data->GetBinLowEdge(1);
    double xmax_h1 = hInvMassCharmBaryonToOmegaPi_Data->GetBinLowEdge(hInvMassCharmBaryonToOmegaPi_Data->GetNbinsX()) +
                  hInvMassCharmBaryonToOmegaPi_Data->GetBinWidth(hInvMassCharmBaryonToOmegaPi_Data->GetNbinsX());
    std::cout << "Minimum x-value for hInvMassCharmBaryonToOmegaPi_Data: " << xmin_h1 << std::endl;
    std::cout << "Maximum x-value for hInvMassCharmBaryonToOmegaPi_Data: " << xmax_h1 << std::endl;
    
    //----------------------------------------------------------------

    // Create canvas and draw branch
    TCanvas* canvas_Data2 = new TCanvas("canvas_Data2", "Data Histogram", 900, 600);
    tree->Draw("fCosPaV0ToPv>>hCosPaV0ToPv_Data");
    
    // Retrieve the histogram
    hCosPaV0ToPv_Data = (TH1D*)gDirectory->Get("hCosPaV0ToPv_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaV0ToPv_Data->GetXaxis()->SetTitle("fCosPaV0ToPv");
    hCosPaV0ToPv_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaV0ToPv_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data2 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data2->AddEntry(hCosPaV0ToPv_Data, "Data", "l");
    legend_Data2->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data2 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fCosPaV0ToPv_Data_LHC23_apass4.pdf";
    canvas_Data2->SaveAs(savePath_Data2);
    
    // Checking binning
    // std::cout << "Number of bins for hCosPaV0ToPv_Data: " << hCosPaV0ToPv_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h2 = hCosPaV0ToPv_Data->GetBinLowEdge(1);
    double xmax_h2 = hCosPaV0ToPv_Data->GetBinLowEdge(hCosPaV0ToPv_Data->GetNbinsX()) +
                     hCosPaV0ToPv_Data->GetBinWidth(hCosPaV0ToPv_Data->GetNbinsX());
    std::cout << "Minimum x-value for hCosPaV0ToPv_Data: " << xmin_h2 << std::endl;
    std::cout << "Maximum x-value for hCosPaV0ToPv_Data: " << xmax_h2 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data3 = new TCanvas("canvas_Data3", "Data Histogram", 900, 600);
    tree->Draw("fV0ldl>>hV0ldl_Data");
    
    // Retrieve the histogram
    hV0ldl_Data = (TH1D*)gDirectory->Get("hV0ldl_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hV0ldl_Data->GetXaxis()->SetTitle("fV0ldl");
    hV0ldl_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hV0ldl_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data3 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data3->AddEntry(hV0ldl_Data, "Data", "l");
    legend_Data3->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data3 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fV0ldl_Data_LHC23_apass4.pdf";
    canvas_Data3->SaveAs(savePath_Data3);
    
    // Checking binning
    // std::cout << "Number of bins for hV0ldl_Data: " << hV0ldl_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h3 = hV0ldl_Data->GetBinLowEdge(1);
    double xmax_h3 = hV0ldl_Data->GetBinLowEdge(hV0ldl_Data->GetNbinsX()) +
                     hV0ldl_Data->GetBinWidth(hV0ldl_Data->GetNbinsX());
    std::cout << "Minimum x-value for hV0ldl_Data: " << xmin_h3 << std::endl;
    std::cout << "Maximum x-value for hV0ldl_Data: " << xmax_h3 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data4 = new TCanvas("canvas_Data4", "Data Histogram", 900, 600);
    tree->Draw("fCosPaCascToPv>>hCosPaCascToPv_Data");
    
    // Retrieve the histogram
    hCosPaCascToPv_Data = (TH1D*)gDirectory->Get("hCosPaCascToPv_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCosPaCascToPv_Data->GetXaxis()->SetTitle("fCosPaCascToPv");
    hCosPaCascToPv_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCosPaCascToPv_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data4 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data4->AddEntry(hCosPaCascToPv_Data, "Data", "l");
    legend_Data4->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data4 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fCosPaCascToPv_Data_LHC23_apass4.pdf";
    canvas_Data4->SaveAs(savePath_Data4);
    
    // Checking binning
    // std::cout << "Number of bins for hCosPaCascToPv_Data: " << hCosPaCascToPv_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h4 = hCosPaCascToPv_Data->GetBinLowEdge(1);
    double xmax_h4 = hCosPaCascToPv_Data->GetBinLowEdge(hCosPaCascToPv_Data->GetNbinsX()) +
                     hCosPaCascToPv_Data->GetBinWidth(hCosPaCascToPv_Data->GetNbinsX());
    std::cout << "Minimum x-value for hCosPaCascToPv_Data: " << xmin_h4 << std::endl;
    std::cout << "Maximum x-value for hCosPaCascToPv_Data: " << xmax_h4 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data5 = new TCanvas("canvas_Data5", "Data Histogram", 900, 600);
    tree->Draw("fDcaCascDau>>hDcaCascDau_Data");
    
    // Retrieve the histogram
    hDcaCascDau_Data = (TH1D*)gDirectory->Get("hDcaCascDau_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaCascDau_Data->GetXaxis()->SetTitle("fDcaCascDau");
    hDcaCascDau_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaCascDau_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data5 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data5->AddEntry(hDcaCascDau_Data, "Data", "l");
    legend_Data5->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data5 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaCascDau_Data_LHC23_apass4.pdf";
    canvas_Data5->SaveAs(savePath_Data5);
    
    // Checking binning
    // std::cout << "Number of bins for hDcaCascDau_Data: " << hDcaCascDau_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h5 = hDcaCascDau_Data->GetBinLowEdge(1);
    double xmax_h5 = hDcaCascDau_Data->GetBinLowEdge(hDcaCascDau_Data->GetNbinsX()) +
                     hDcaCascDau_Data->GetBinWidth(hDcaCascDau_Data->GetNbinsX());
    std::cout << "Minimum x-value for hDcaCascDau_Data: " << xmin_h5 << std::endl;
    std::cout << "Maximum x-value for hDcaCascDau_Data: " << xmax_h5 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data6 = new TCanvas("canvas_Data6", "Data Histogram", 900, 600);
    tree->Draw("fCascldl>>hCascldl_Data(100, 0, 6900)");
    
    // Retrieve the histogram
    hCascldl_Data = (TH1D*)gDirectory->Get("hCascldl_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hCascldl_Data->GetXaxis()->SetTitle("fCascldl");
    hCascldl_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hCascldl_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data6 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data6->AddEntry(hCascldl_Data, "Data", "l");
    legend_Data6->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data6 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fCascldl_Data_LHC23_apass4.pdf";
    canvas_Data6->SaveAs(savePath_Data6);
    
    // Checking binning
    // std::cout << "Number of bins for hCascldl_Data: " << hCascldl_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h6 = hCascldl_Data->GetBinLowEdge(1);
    double xmax_h6 = hCascldl_Data->GetBinLowEdge(hCascldl_Data->GetNbinsX()) +
                     hCascldl_Data->GetBinWidth(hCascldl_Data->GetNbinsX());
    std::cout << "Minimum x-value for hCascldl_Data: " << xmin_h6 << std::endl;
    std::cout << "Maximum x-value for hCascldl_Data: " << xmax_h6 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data7 = new TCanvas("canvas_Data7", "Data Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau0>>hKFParticleDcaXYV0DauPosToPv_Data");
    
    // Retrieve the histogram
    hKFParticleDcaXYV0DauPosToPv_Data = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauPosToPv_Data");
    
    // Axis labels
    hKFParticleDcaXYV0DauPosToPv_Data->GetXaxis()->SetTitle("fDcaXYToPvV0Dau0");
    hKFParticleDcaXYV0DauPosToPv_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauPosToPv_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data7 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data7->AddEntry(hKFParticleDcaXYV0DauPosToPv_Data, "Data", "l");
    legend_Data7->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data7 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaXYToPvV0Dau0_Data_LHC23_apass4.pdf";
    canvas_Data7->SaveAs(savePath_Data7);
    
    // Checking binning
    // std::cout << "Number of bins for hKFParticleDcaXYV0DauPosToPv_Data: " << hKFParticleDcaXYV0DauPosToPv_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h7 = hKFParticleDcaXYV0DauPosToPv_Data->GetBinLowEdge(1);
    double xmax_h7 = hKFParticleDcaXYV0DauPosToPv_Data->GetBinLowEdge(hKFParticleDcaXYV0DauPosToPv_Data->GetNbinsX()) +
                     hKFParticleDcaXYV0DauPosToPv_Data->GetBinWidth(hKFParticleDcaXYV0DauPosToPv_Data->GetNbinsX());
    std::cout << "Minimum x-value for hKFParticleDcaXYV0DauPosToPv_Data: " << xmin_h7 << std::endl;
    std::cout << "Maximum x-value for hKFParticleDcaXYV0DauPosToPv_Data: " << xmax_h7 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data8 = new TCanvas("canvas_Data8", "Data Histogram", 900, 600);
    tree->Draw("fDcaXYToPvV0Dau1>>hKFParticleDcaXYV0DauNegToPv_Data");
    
    // Retrieve the histogram
    hKFParticleDcaXYV0DauNegToPv_Data = (TH1D*)gDirectory->Get("hKFParticleDcaXYV0DauNegToPv_Data");
    
    // Axis labels
    hKFParticleDcaXYV0DauNegToPv_Data->GetXaxis()->SetTitle("fDcaXYToPvV0Dau1");
    hKFParticleDcaXYV0DauNegToPv_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaXYV0DauNegToPv_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data8 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data8->AddEntry(hKFParticleDcaXYV0DauNegToPv_Data, "Data", "l");
    legend_Data8->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data8 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaXYToPvV0Dau1_Data_LHC23_apass4.pdf";
    canvas_Data8->SaveAs(savePath_Data8);
    
    // Checking binning
    // std::cout << "Number of bins for hKFParticleDcaXYV0DauNegToPv_Data: " << hKFParticleDcaXYV0DauNegToPv_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h8 = hKFParticleDcaXYV0DauNegToPv_Data->GetBinLowEdge(1);
    double xmax_h8 = hKFParticleDcaXYV0DauNegToPv_Data->GetBinLowEdge(hKFParticleDcaXYV0DauNegToPv_Data->GetNbinsX()) +
                     hKFParticleDcaXYV0DauNegToPv_Data->GetBinWidth(hKFParticleDcaXYV0DauNegToPv_Data->GetNbinsX());
    std::cout << "Minimum x-value for hKFParticleDcaXYV0DauNegToPv_Data: " << xmin_h8 << std::endl;
    std::cout << "Maximum x-value for hKFParticleDcaXYV0DauNegToPv_Data: " << xmax_h8 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data9 = new TCanvas("canvas_Data9", "Data Histogram", 900, 600);
    tree->Draw("fDcaXYToPvCascDau>>hDcaXYToPvCascDau_Data");
    
    // Retrieve the histogram
    hDcaXYToPvCascDau_Data = (TH1D*)gDirectory->Get("hDcaXYToPvCascDau_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hDcaXYToPvCascDau_Data->GetXaxis()->SetTitle("fDcaXYToPvCascDau");
    hDcaXYToPvCascDau_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hDcaXYToPvCascDau_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data9 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data9->AddEntry(hDcaXYToPvCascDau_Data, "Data", "l");
    legend_Data9->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data9 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaXYToPvCascDau_Data_LHC23_apass4.pdf";
    canvas_Data9->SaveAs(savePath_Data9);
    
    // Checking binning
    // std::cout << "Number of bins for hDcaXYToPvCascDau_Data: " << hDcaXYToPvCascDau_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h9 = hDcaXYToPvCascDau_Data->GetBinLowEdge(1);
    double xmax_h9 = hDcaXYToPvCascDau_Data->GetBinLowEdge(hDcaXYToPvCascDau_Data->GetNbinsX()) +
                     hDcaXYToPvCascDau_Data->GetBinWidth(hDcaXYToPvCascDau_Data->GetNbinsX());
    std::cout << "Minimum x-value for hDcaXYToPvCascDau_Data: " << xmin_h9 << std::endl;
    std::cout << "Maximum x-value for hDcaXYToPvCascDau_Data: " << xmax_h9 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data10 = new TCanvas("canvas_Data10", "Data Histogram", 900, 600);
    tree->Draw("fDcaCharmBaryonDau>>hKFParticleDcaCharmBaryonDau_Data");
    
    // Retrieve the histogram
    hKFParticleDcaCharmBaryonDau_Data = (TH1D*)gDirectory->Get("hKFParticleDcaCharmBaryonDau_Data");
    
    // Axis labels
    hKFParticleDcaCharmBaryonDau_Data->GetXaxis()->SetTitle("fDcaCharmBaryonDau");
    hKFParticleDcaCharmBaryonDau_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hKFParticleDcaCharmBaryonDau_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data10 = new TLegend(0.15, 0.8, 0.25, 0.88);
    legend_Data10->AddEntry(hKFParticleDcaCharmBaryonDau_Data, "Data", "l");
    legend_Data10->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data10 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fDcaCharmBaryonDau_Data_LHC23_apass4.pdf";
    canvas_Data10->SaveAs(savePath_Data10);
    
    // Checking binning
    // std::cout << "Number of bins for hKFParticleDcaCharmBaryonDau_Data: " << hKFParticleDcaCharmBaryonDau_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h10 = hKFParticleDcaCharmBaryonDau_Data->GetBinLowEdge(1);
    double xmax_h10 = hKFParticleDcaCharmBaryonDau_Data->GetBinLowEdge(hKFParticleDcaCharmBaryonDau_Data->GetNbinsX()) +
                      hKFParticleDcaCharmBaryonDau_Data->GetBinWidth(hKFParticleDcaCharmBaryonDau_Data->GetNbinsX());
    std::cout << "Minimum x-value for hKFParticleDcaCharmBaryonDau_Data: " << xmin_h10 << std::endl;
    std::cout << "Maximum x-value for hKFParticleDcaCharmBaryonDau_Data: " << xmax_h10 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data11 = new TCanvas("canvas_Data11", "Data Histogram", 900, 600);
    tree->Draw("fKfptPiFromOmegac>>hPtPiFromCharmBaryon_Data");
    
    // Retrieve the histogram
    hPtPiFromCharmBaryon_Data = (TH1D*)gDirectory->Get("hPtPiFromCharmBaryon_Data");
    
    // Axis labels
    hPtPiFromCharmBaryon_Data->GetXaxis()->SetTitle("fKfptPiFromOmegac");
    hPtPiFromCharmBaryon_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hPtPiFromCharmBaryon_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data11 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_Data11->AddEntry(hPtPiFromCharmBaryon_Data, "Data", "l");
    legend_Data11->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data11 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fKfptPiFromOmegac_Data_LHC23_apass4.pdf";
    canvas_Data11->SaveAs(savePath_Data11);
    
    // Checking binning
    // std::cout << "Number of bins for hPtPiFromCharmBaryon_Data: " << hPtPiFromCharmBaryon_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h11 = hPtPiFromCharmBaryon_Data->GetBinLowEdge(1);
    double xmax_h11 = hPtPiFromCharmBaryon_Data->GetBinLowEdge(hPtPiFromCharmBaryon_Data->GetNbinsX()) +
                      hPtPiFromCharmBaryon_Data->GetBinWidth(hPtPiFromCharmBaryon_Data->GetNbinsX());
    std::cout << "Minimum x-value for hPtPiFromCharmBaryon_Data: " << xmin_h11 << std::endl;
    std::cout << "Maximum x-value for hPtPiFromCharmBaryon_Data: " << xmax_h11 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data12 = new TCanvas("canvas_Data12", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCKaFromCasc>>hNSigmaTPCKaFromCasc_Data");
    
    // Retrieve the histogram
    hNSigmaTPCKaFromCasc_Data = (TH1D*)gDirectory->Get("hNSigmaTPCKaFromCasc_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCKaFromCasc_Data->GetXaxis()->SetTitle("fNSigmaTPCKaFromCasc");
    hNSigmaTPCKaFromCasc_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCKaFromCasc_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data12 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_Data12->AddEntry(hNSigmaTPCKaFromCasc_Data, "Data", "l");
    legend_Data12->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data12 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCKaFromCasc_Data_LHC23_apass4.pdf";
    canvas_Data12->SaveAs(savePath_Data12);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCKaFromCasc_Data: " << hNSigmaTPCKaFromCasc_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h12 = hNSigmaTPCKaFromCasc_Data->GetBinLowEdge(1);
    double xmax_h12 = hNSigmaTPCKaFromCasc_Data->GetBinLowEdge(hNSigmaTPCKaFromCasc_Data->GetNbinsX()) +
                      hNSigmaTPCKaFromCasc_Data->GetBinWidth(hNSigmaTPCKaFromCasc_Data->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCKaFromCasc_Data: " << xmin_h12 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCKaFromCasc_Data: " << xmax_h12 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data13 = new TCanvas("canvas_Data13", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromV0>>hNSigmaTPCPiFromV0_Data");
    
    // Retrieve the histogram
    hNSigmaTPCPiFromV0_Data = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromV0_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromV0_Data->GetXaxis()->SetTitle("fNSigmaTPCPiFromV0");
    hNSigmaTPCPiFromV0_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromV0_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data13 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_Data13->AddEntry(hNSigmaTPCPiFromV0_Data, "Data", "l");
    legend_Data13->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data13 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCPiFromV0_Data_LHC23_apass4.pdf";
    canvas_Data13->SaveAs(savePath_Data13);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCPiFromV0_Data: " << hNSigmaTPCPiFromV0_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h13 = hNSigmaTPCPiFromV0_Data->GetBinLowEdge(1);
    double xmax_h13 = hNSigmaTPCPiFromV0_Data->GetBinLowEdge(hNSigmaTPCPiFromV0_Data->GetNbinsX()) +
                      hNSigmaTPCPiFromV0_Data->GetBinWidth(hNSigmaTPCPiFromV0_Data->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCPiFromV0_Data: " << xmin_h13 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCPiFromV0_Data: " << xmax_h13 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data14 = new TCanvas("canvas_Data14", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPrFromV0>>hNSigmaTPCPrFromV0_Data");
    
    // Retrieve the histogram
    hNSigmaTPCPrFromV0_Data = (TH1D*)gDirectory->Get("hNSigmaTPCPrFromV0_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPrFromV0_Data->GetXaxis()->SetTitle("fNSigmaTPCPrFromV0");
    hNSigmaTPCPrFromV0_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPrFromV0_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data14 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_Data14->AddEntry(hNSigmaTPCPrFromV0_Data, "Data", "l");
    legend_Data14->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data14 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCPrFromV0_Data_LHC23_apass4.pdf";
    canvas_Data14->SaveAs(savePath_Data14);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCPrFromV0_Data: " << hNSigmaTPCPrFromV0_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h14 = hNSigmaTPCPrFromV0_Data->GetBinLowEdge(1);
    double xmax_h14 = hNSigmaTPCPrFromV0_Data->GetBinLowEdge(hNSigmaTPCPrFromV0_Data->GetNbinsX()) +
                      hNSigmaTPCPrFromV0_Data->GetBinWidth(hNSigmaTPCPrFromV0_Data->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCPrFromV0_Data: " << xmin_h14 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCPrFromV0_Data: " << xmax_h14 << std::endl;
    
    //----------------------------------------------------------------
    
    // Create canvas and draw branch
    TCanvas* canvas_Data15 = new TCanvas("canvas_Data15", "Data Histogram", 900, 600);
    tree->Draw("fNSigmaTPCPiFromOmegac>>hNSigmaTPCPiFromOmegac_Data(100, -1080, 100)");
    
    // Retrieve the histogram
    hNSigmaTPCPiFromOmegac_Data = (TH1D*)gDirectory->Get("hNSigmaTPCPiFromOmegac_Data"); // Doesn't appear in the Analysis Results
    
    // Axis labels
    hNSigmaTPCPiFromOmegac_Data->GetXaxis()->SetTitle("fNSigmaTPCPiFromOmegac");
    hNSigmaTPCPiFromOmegac_Data->GetYaxis()->SetTitle("entries");
    
    // Draw the histogram
    hNSigmaTPCPiFromOmegac_Data->Draw("HIST");
    
    // Legend
    TLegend *legend_Data15 = new TLegend(0.65, 0.8, 0.75, 0.88);
    legend_Data15->AddEntry(hNSigmaTPCPiFromOmegac_Data, "Data", "l");
    legend_Data15->Draw();
    
    // Define the path and save the canvas
    const char* savePath_Data15 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/fNSigmaTPCPiFromOmegac_Data_LHC23_apass4.pdf";
    canvas_Data15->SaveAs(savePath_Data15);
    
    // Checking binning
    // std::cout << "Number of bins for hNSigmaTPCPiFromOmegac_Data: " << hNSigmaTPCPiFromOmegac_Data->GetNbinsX() << std::endl;
    
    // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
    double xmin_h15 = hNSigmaTPCPiFromOmegac_Data->GetBinLowEdge(1);
    double xmax_h15 = hNSigmaTPCPiFromOmegac_Data->GetBinLowEdge(hNSigmaTPCPiFromOmegac_Data->GetNbinsX()) +
                      hNSigmaTPCPiFromOmegac_Data->GetBinWidth(hNSigmaTPCPiFromOmegac_Data->GetNbinsX());
    std::cout << "Minimum x-value for hNSigmaTPCPiFromOmegac_Data: " << xmin_h15 << std::endl;
    std::cout << "Maximum x-value for hNSigmaTPCPiFromOmegac_Data: " << xmax_h15 << std::endl;
    
}

void combinedMCandData() {
    
    gStyle->SetOptStat(0);

    // Create canvas
    TCanvas* hInvMassCharmBaryonToOmegaPi_combined = new TCanvas("hInvMassCharmBaryonToOmegaPi_combined", "MC and Data Histograms", 800, 600);
    hInvMassCharmBaryonToOmegaPi_combined->SetLogy();
    
    // Draw the MC histogram
    hInvMassCharmBaryonToOmegaPi_MC->SetLineColor(kRed);
    hInvMassCharmBaryonToOmegaPi_MC->Scale(1.0/hInvMassCharmBaryonToOmegaPi_MC->Integral());
    hInvMassCharmBaryonToOmegaPi_MC->Draw("HIST");

    // Create the Trimmed Data histogram (cutting the middle part 2.55-2.85)
    TH1D* hTrimmed = (TH1D*)hInvMassCharmBaryonToOmegaPi_Data->Clone("hTrimmed");

    // Loop through every bin, find the lower and upper egde of the i bin, and remove those inside the range 2.55-2.85
    int nBins = hTrimmed->GetNbinsX();
    for (int i = 1; i <= nBins; ++i) {
        double binLowEdge = hTrimmed->GetBinLowEdge(i);
        double binUpEdge = binLowEdge + hTrimmed->GetBinWidth(i);

        if (binLowEdge >= 2.55 && binUpEdge <= 2.85) {
            hTrimmed->SetBinContent(i, 0);
            hTrimmed->SetBinError(i, 0);
        }
    }
    // Draw the Trimmed Data histogram
    hTrimmed->SetLineColor(kBlue);
    hTrimmed->Scale(1.0/hTrimmed->Integral());
    hTrimmed->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined = new TLegend(0.75, 0.8, 0.88, 0.88);
    legend_combined->AddEntry(hInvMassCharmBaryonToOmegaPi_MC, "MC", "l");
    legend_combined->AddEntry(hTrimmed, "Data", "l");
    legend_combined->Draw();

    // Define the path and save the canvas
    const char* savePath_combined = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hInvMassCharmBaryonToOmegaPi_combined.pdf";
    hInvMassCharmBaryonToOmegaPi_combined->SaveAs(savePath_combined);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hCosPaV0ToPv_combined = new TCanvas("hCosPaV0ToPv_combined", "MC and Data Histograms 2", 800, 600);
    hCosPaV0ToPv_combined->SetLogy();
    
    // Draw the MC histogram
    hCosPaV0ToPv_MC->SetLineColor(kRed);
    hCosPaV0ToPv_MC->Scale(1.0/hCosPaV0ToPv_MC->Integral());
    hCosPaV0ToPv_MC->Draw("HIST");

    // Draw the Data histogram
    hCosPaV0ToPv_Data->SetLineColor(kBlue);
    hCosPaV0ToPv_Data->Scale(1.0/hCosPaV0ToPv_Data->Integral());
    hCosPaV0ToPv_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined2 = new TLegend(0.67, 0.8, 0.77, 0.88);
    legend_combined2->AddEntry(hCosPaV0ToPv_MC, "MC", "l");
    legend_combined2->AddEntry(hCosPaV0ToPv_Data, "Data", "l");
    legend_combined2->Draw();

    // Define the path and save the canvas
    const char* savePath_combined2 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hCosPaV0ToPv_combined.pdf";
    hCosPaV0ToPv_combined->SaveAs(savePath_combined2);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hV0ldl_combined = new TCanvas("hV0ldl_combined", "MC and Data Histograms 3", 800, 600);
    hV0ldl_combined->SetLogy();
    
    // Draw the MC histogram
    hV0ldl_MC->SetLineColor(kRed);
    hV0ldl_MC->Scale(1.0/hV0ldl_MC->Integral());
    hV0ldl_MC->Draw("HIST");

    // Draw the Data histogram
    hV0ldl_Data->SetLineColor(kBlue);
    hV0ldl_Data->Scale(1.0/hV0ldl_Data->Integral());
    hV0ldl_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined3 = new TLegend(0.75, 0.8, 0.88, 0.88);
    legend_combined3->AddEntry(hV0ldl_MC, "MC", "l");
    legend_combined3->AddEntry(hV0ldl_Data, "Data", "l");
    legend_combined3->Draw();

    // Define the path and save the canvas
    const char* savePath_combined3 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hV0ldl_combined.pdf";
    hV0ldl_combined->SaveAs(savePath_combined3);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hCosPaCascToPv_combined = new TCanvas("hCosPaCascToPv_combined", "MC and Data Histograms 4", 800, 600);
    hCosPaCascToPv_combined->SetLogy();
    
    // Draw the MC histogram
    hCosPaCascToPv_MC->SetLineColor(kRed);
    hCosPaCascToPv_MC->Scale(1.0/hCosPaCascToPv_MC->Integral());
    hCosPaCascToPv_MC->Draw("HIST");

    // Draw the Data histogram
    hCosPaCascToPv_Data->SetLineColor(kBlue);
    hCosPaCascToPv_Data->Scale(1.0/hCosPaCascToPv_Data->Integral());
    hCosPaCascToPv_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined4 = new TLegend(0.70, 0.82, 0.82, 0.88);
    legend_combined4->AddEntry(hCosPaCascToPv_MC, "MC", "l");
    legend_combined4->AddEntry(hCosPaCascToPv_Data, "Data", "l");
    legend_combined4->Draw();

    // Define the path and save the canvas
    const char* savePath_combined4 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hCosPaCascToPv_combined.pdf";
    hCosPaCascToPv_combined->SaveAs(savePath_combined4);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hDcaCascDau_combined = new TCanvas("hDcaCascDau_combined", "MC and Data Histograms 5", 800, 600);
    hDcaCascDau_combined->SetLogy();
    
    // Draw the MC histogram
    hDcaCascDau_MC->SetLineColor(kRed);
    hDcaCascDau_MC->Scale(1.0/hDcaCascDau_MC->Integral());
    hDcaCascDau_MC->Draw("HIST");

    // Draw the Data histogram
    hDcaCascDau_Data->SetLineColor(kBlue);
    hDcaCascDau_Data->Scale(1.0/hDcaCascDau_Data->Integral());
    hDcaCascDau_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined5 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined5->AddEntry(hDcaCascDau_MC, "MC", "l");
    legend_combined5->AddEntry(hDcaCascDau_Data, "Data", "l");
    legend_combined5->Draw();

    // Define the path and save the canvas
    const char* savePath_combined5 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hDcaCascDau_combined.pdf";
    hDcaCascDau_combined->SaveAs(savePath_combined5);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hCascldl_combined = new TCanvas("hCascldl_combined", "MC and Data Histograms 6", 800, 600);
    hCascldl_combined->SetLogy();
    
    // Draw the MC histogram
    hCascldl_MC->SetLineColor(kRed);
    hCascldl_MC->Scale(1.0/hCascldl_MC->Integral());
    hCascldl_MC->Draw("HIST");

    // Draw the Data histogram
    hCascldl_Data->SetLineColor(kBlue);
    hCascldl_Data->Scale(1.0/hCascldl_Data->Integral());
    hCascldl_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined6 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined6->AddEntry(hCascldl_MC, "MC", "l");
    legend_combined6->AddEntry(hCascldl_Data, "Data", "l");
    legend_combined6->Draw();

    // Define the path and save the canvas
    const char* savePath_combined6 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hCascldl_combined.pdf";
    hCascldl_combined->SaveAs(savePath_combined6);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hKFParticleDcaXYV0DauPosToPv_combined = new TCanvas("hKFParticleDcaXYV0DauPosToPv_combined", "MC and Data Histograms 7", 800, 600);
    hKFParticleDcaXYV0DauPosToPv_combined->SetLogy();
    
    // Draw the MC histogram
    hKFParticleDcaXYV0DauPosToPv_MC->SetLineColor(kRed);
    hKFParticleDcaXYV0DauPosToPv_MC->Scale(1.0/hKFParticleDcaXYV0DauPosToPv_MC->Integral());
    hKFParticleDcaXYV0DauPosToPv_MC->Draw("HIST");

    // Draw the Data histogram
    hKFParticleDcaXYV0DauPosToPv_Data->SetLineColor(kBlue);
    hKFParticleDcaXYV0DauPosToPv_Data->Scale(1.0/hKFParticleDcaXYV0DauPosToPv_Data->Integral());
    hKFParticleDcaXYV0DauPosToPv_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined7 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined7->AddEntry(hKFParticleDcaXYV0DauPosToPv_MC, "MC", "l");
    legend_combined7->AddEntry(hKFParticleDcaXYV0DauPosToPv_Data, "Data", "l");
    legend_combined7->Draw();

    // Define the path and save the canvas
    const char* savePath_combined7 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hKFParticleDcaXYV0DauPosToPv_combined.pdf";
    hKFParticleDcaXYV0DauPosToPv_combined->SaveAs(savePath_combined7);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hKFParticleDcaXYV0DauNegToPv_combined = new TCanvas("hKFParticleDcaXYV0DauNegToPv_combined", "MC and Data Histograms 8", 800, 600);
    hKFParticleDcaXYV0DauNegToPv_combined->SetLogy();
    
    // Draw the MC histogram
    hKFParticleDcaXYV0DauNegToPv_MC->SetLineColor(kRed);
    hKFParticleDcaXYV0DauNegToPv_MC->Scale(1.0/hKFParticleDcaXYV0DauNegToPv_MC->Integral());
    hKFParticleDcaXYV0DauNegToPv_MC->Draw("HIST");

    // Draw the Data histogram
    hKFParticleDcaXYV0DauNegToPv_Data->SetLineColor(kBlue);
    hKFParticleDcaXYV0DauNegToPv_Data->Scale(1.0/hKFParticleDcaXYV0DauNegToPv_Data->Integral());
    hKFParticleDcaXYV0DauNegToPv_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined8 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined8->AddEntry(hKFParticleDcaXYV0DauNegToPv_MC, "MC", "l");
    legend_combined8->AddEntry(hKFParticleDcaXYV0DauNegToPv_Data, "Data", "l");
    legend_combined8->Draw();

    // Define the path and save the canvas
    const char* savePath_combined8 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hKFParticleDcaXYV0DauNegToPv_combined.pdf";
    hKFParticleDcaXYV0DauNegToPv_combined->SaveAs(savePath_combined8);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hDcaXYToPvCascDau_combined = new TCanvas("hDcaXYToPvCascDau_combined", "MC and Data Histograms 9", 800, 600);
    hDcaXYToPvCascDau_combined->SetLogy();
    
    // Draw the MC histogram
    hDcaXYToPvCascDau_MC->SetLineColor(kRed);
    hDcaXYToPvCascDau_MC->Scale(1.0/hDcaXYToPvCascDau_MC->Integral());
    hDcaXYToPvCascDau_MC->Draw("HIST");

    // Draw the Data histogram
    hDcaXYToPvCascDau_Data->SetLineColor(kBlue);
    hDcaXYToPvCascDau_Data->Scale(1.0/hDcaXYToPvCascDau_Data->Integral());
    hDcaXYToPvCascDau_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined9 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined9->AddEntry(hDcaXYToPvCascDau_MC, "MC", "l");
    legend_combined9->AddEntry(hDcaXYToPvCascDau_Data, "Data", "l");
    legend_combined9->Draw();

    // Define the path and save the canvas
    const char* savePath_combined9 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hDcaXYToPvCascDau_combined.pdf";
    hDcaXYToPvCascDau_combined->SaveAs(savePath_combined9);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hKFParticleDcaCharmBaryonDau_combined = new TCanvas("hKFParticleDcaCharmBaryonDau_combined", "MC and Data Histograms 10", 800, 600);
    hKFParticleDcaCharmBaryonDau_combined->SetLogy();
    
    // Draw the MC histogram
    hKFParticleDcaCharmBaryonDau_MC->SetLineColor(kRed);
    hKFParticleDcaCharmBaryonDau_MC->Scale(1.0/hKFParticleDcaCharmBaryonDau_MC->Integral());
    hKFParticleDcaCharmBaryonDau_MC->Draw("HIST");

    // Draw the Data histogram
    hKFParticleDcaCharmBaryonDau_Data->SetLineColor(kBlue);
    hKFParticleDcaCharmBaryonDau_Data->Scale(1.0/hKFParticleDcaCharmBaryonDau_Data->Integral());
    hKFParticleDcaCharmBaryonDau_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined10 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined10->AddEntry(hKFParticleDcaCharmBaryonDau_MC, "MC", "l");
    legend_combined10->AddEntry(hKFParticleDcaCharmBaryonDau_Data, "Data", "l");
    legend_combined10->Draw();

    // Define the path and save the canvas
    const char* savePath_combined10 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hKFParticleDcaCharmBaryonDau_combined.pdf";
    hKFParticleDcaCharmBaryonDau_combined->SaveAs(savePath_combined10);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hPtPiFromCharmBaryon_combined = new TCanvas("hPtPiFromCharmBaryon_combined", "MC and Data Histograms 11", 800, 600);
    hPtPiFromCharmBaryon_combined->SetLogy();
    
    // Draw the MC histogram
    hPtPiFromCharmBaryon_MC->SetLineColor(kRed);
    hPtPiFromCharmBaryon_MC->Scale(1.0/hPtPiFromCharmBaryon_MC->Integral());
    hPtPiFromCharmBaryon_MC->Draw("HIST");

    // Draw the Data histogram
    hPtPiFromCharmBaryon_Data->SetLineColor(kBlue);
    hPtPiFromCharmBaryon_Data->Scale(1.0/hPtPiFromCharmBaryon_Data->Integral());
    hPtPiFromCharmBaryon_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined11 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined11->AddEntry(hPtPiFromCharmBaryon_MC, "MC", "l");
    legend_combined11->AddEntry(hPtPiFromCharmBaryon_Data, "Data", "l");
    legend_combined11->Draw();

    // Define the path and save the canvas
    const char* savePath_combined11 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hPtPiFromCharmBaryon_combined.pdf";
    hPtPiFromCharmBaryon_combined->SaveAs(savePath_combined11);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hNSigmaTPCKaFromCasc_combined = new TCanvas("hNSigmaTPCKaFromCasc_combined", "MC and Data Histograms 12", 800, 600);
    hNSigmaTPCKaFromCasc_combined->SetLogy();
    
    // Draw the MC histogram
    hNSigmaTPCKaFromCasc_MC->SetLineColor(kRed);
    hNSigmaTPCKaFromCasc_MC->Scale(1.0/hNSigmaTPCKaFromCasc_MC->Integral());
    hNSigmaTPCKaFromCasc_MC->Draw("HIST");

    // Draw the Data histogram
    hNSigmaTPCKaFromCasc_Data->SetLineColor(kBlue);
    hNSigmaTPCKaFromCasc_Data->Scale(1.0/hNSigmaTPCKaFromCasc_Data->Integral());
    hNSigmaTPCKaFromCasc_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined12 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined12->AddEntry(hNSigmaTPCKaFromCasc_MC, "MC", "l");
    legend_combined12->AddEntry(hNSigmaTPCKaFromCasc_Data, "Data", "l");
    legend_combined12->Draw();

    // Define the path and save the canvas
    const char* savePath_combined12 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hNSigmaTPCKaFromCasc_combined.pdf";
    hNSigmaTPCKaFromCasc_combined->SaveAs(savePath_combined12);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hNSigmaTPCPiFromV0_combined = new TCanvas("hNSigmaTPCPiFromV0_combined", "MC and Data Histograms 13", 800, 600);
    hNSigmaTPCPiFromV0_combined->SetLogy();
    
    // Draw the MC histogram
    hNSigmaTPCPiFromV0_MC->SetLineColor(kRed);
    hNSigmaTPCPiFromV0_MC->Scale(1.0/hNSigmaTPCPiFromV0_MC->Integral());
    hNSigmaTPCPiFromV0_MC->Draw("HIST");

    // Draw the Data histogram
    hNSigmaTPCPiFromV0_Data->SetLineColor(kBlue);
    hNSigmaTPCPiFromV0_Data->Scale(1.0/hNSigmaTPCPiFromV0_Data->Integral());
    hNSigmaTPCPiFromV0_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined13 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined13->AddEntry(hNSigmaTPCPiFromV0_MC, "MC", "l");
    legend_combined13->AddEntry(hNSigmaTPCPiFromV0_Data, "Data", "l");
    legend_combined13->Draw();

    // Define the path and save the canvas
    const char* savePath_combined13 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hNSigmaTPCPiFromV0_combined.pdf";
    hNSigmaTPCPiFromV0_combined->SaveAs(savePath_combined13);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hNSigmaTPCPrFromV0_combined = new TCanvas("hNSigmaTPCPrFromV0_combined", "MC and Data Histograms 14", 800, 600);
    hNSigmaTPCPrFromV0_combined->SetLogy();
    
    // Draw the MC histogram
    hNSigmaTPCPrFromV0_MC->SetLineColor(kRed);
    hNSigmaTPCPrFromV0_MC->Scale(1.0/hNSigmaTPCPrFromV0_MC->Integral());
    hNSigmaTPCPrFromV0_MC->Draw("HIST");

    // Draw the Data histogram
    hNSigmaTPCPrFromV0_Data->SetLineColor(kBlue);
    hNSigmaTPCPrFromV0_Data->Scale(1.0/hNSigmaTPCPrFromV0_Data->Integral());
    hNSigmaTPCPrFromV0_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined14 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined14->AddEntry(hNSigmaTPCPrFromV0_MC, "MC", "l");
    legend_combined14->AddEntry(hNSigmaTPCPrFromV0_Data, "Data", "l");
    legend_combined14->Draw();

    // Define the path and save the canvas
    const char* savePath_combined14 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hNSigmaTPCPrFromV0_combined.pdf";
    hNSigmaTPCPrFromV0_combined->SaveAs(savePath_combined14);
    
    //----------------------------------------------------------------
    
    // Create canvas
    TCanvas* hNSigmaTPCPiFromOmegac_combined = new TCanvas("hNSigmaTPCPiFromOmegac_combined", "MC and Data Histograms 15", 800, 600);
    hNSigmaTPCPiFromOmegac_combined->SetLogy();
    
    // Draw the MC histogram
    hNSigmaTPCPiFromOmegac_MC->SetLineColor(kRed);
    hNSigmaTPCPiFromOmegac_MC->Scale(1.0/hNSigmaTPCPiFromOmegac_MC->Integral());
    hNSigmaTPCPiFromOmegac_MC->Draw("HIST");

    // Draw the Data histogram
    hNSigmaTPCPiFromOmegac_Data->SetLineColor(kBlue);
    hNSigmaTPCPiFromOmegac_Data->Scale(1.0/hNSigmaTPCPiFromOmegac_Data->Integral());
    hNSigmaTPCPiFromOmegac_Data->Draw("HIST SAME");

    // Legend
    TLegend* legend_combined15 = new TLegend(0.75, 0.80, 0.88, 0.88);
    legend_combined15->AddEntry(hNSigmaTPCPiFromOmegac_MC, "MC", "l");
    legend_combined15->AddEntry(hNSigmaTPCPiFromOmegac_Data, "Data", "l");
    legend_combined15->Draw();

    // Define the path and save the canvas
    const char* savePath_combined15 = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hNSigmaTPCPiFromOmegac_combined.pdf";
    hNSigmaTPCPiFromOmegac_combined->SaveAs(savePath_combined15);
    
}

int main() {
    retrieveMC();
    retrieveData();
    combinedMCandData();

    return 0;
}
