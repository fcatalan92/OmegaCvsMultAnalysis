#include <TFile.h>
#include <TDirectory.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>

const int nHistos = 15;

TH1D* HistosMC [nHistos] = {};
TH1D* HistosData [nHistos] = {};

std::string branchNames [nHistos] = {
    "InvMassCharmBaryon",
    "CosPaV0ToPv",
    "V0ldl",
    "CosPaCascToPv",
    "DcaCascDau",
    "Cascldl",
    "DcaXYToPvV0Dau0",
    "DcaXYToPvV0Dau1",
    "DcaXYToPvCascDau",
    "DcaCharmBaryonDau",
    "KfptPiFromOmegac",
    "NSigmaTPCKaFromCasc",
    "NSigmaTPCPiFromV0",
    "NSigmaTPCPrFromV0",
    "NSigmaTPCPiFromOmegac"
};

float minValues [nHistos] = {
    2.33,
    0.946,
    0,
    0.946,
    0,
    0,
    -12,
    -19,
    -22,
    0,
    0,
    -12.2,
    -4,
    -19.5,
    -10
};

float maxValues [nHistos] = {
    3.16,
    1.004,
    10000,
    1.004,
    1.5,
    6900,
    7,
    30,
    18.5,
    2,
    8.8,
    12,
    4.8,
    9,
    10
};

std::string titles [nHistos] = {
    "Charm Baryon Invariant Mass - #Omega^{-}#pi^{+} decay",
    "Cosine of Pointing Angle of V0 to PV",
    "Normalized Decay Length of V0",
    "Cosine of Pointing Angle of Cascade to PV",
    "DCA between Cascade Daughters",
    "Normalized Decay Length of Cascade",
    "DCAXY of Positive V0 Daughter to PV",
    "DCAXY of Negative V0 Daughter to PV",
    "DCAXY of Cascade Daughters to PV",
    "DCA between Charm Baryon Daughters",
    "pT of Pion from Charm Baryon",
    "NSigma TPC of Kaon from Cascade",
    "NSigma TPC of Pion from V0",
    "NSigma TPC of Proton from V0",
    "NSigma TPC of Pion from Omegac"
};

std::string xTitles [nHistos] = {
    "Inv. Mass (GeV/#it{c}^{2})",
    "Cos(#theta_{p})",
    "Normalized Decay Length",
    "Cos(#theta_{p})",
    "DCA",
    "Normalized Decay Length",
    "DCA_{xy}",
    "DCA_{xy}",
    "DCA_{xy}",
    "DCA",
    "#it{p}_{T} (GeV/#it{c})",
    "N_{#sigma}^{TPC}(K)",
    "N_{#sigma}^{TPC}(#pi)",
    "N_{#sigma}^{TPC}(p)",
    "N_{#sigma}^{TPC}(#pi)"
};

TH1D* hInvMassCharmBaryonToOmegaPi_MC = nullptr;
TH1D* hInvMassCharmBaryonToOmegaPi_Data = nullptr;

void retrieveMC(const char* filename = "/Users/fernandatorres/Desktop/Omegac_analysis/ROOTFiles/MC/LHC24e3/AO2D_363960.root") {
    
    // Open ROOT file
    TFile *file = new TFile(filename);
    TDirectory *dir = (TDirectory*)file->Get("DF_2261906078565142");
    TTree *tree = (TTree*)dir->Get("O2hfkfomegacfull");
    
    for (int i = 0; i < nHistos; i++) {
        // Create canvas and draw branch
        TCanvas* canvas_MC = new TCanvas(Form("canvas_MC_%d", i), "MC Histogram", 900, 600);
        tree->Draw(Form("f%s>>h%s_MC(100, %f, %f)", branchNames[i].c_str(), branchNames[i].c_str(), minValues[i], maxValues[i]));

        // Retrieve the histogram
        HistosMC[i] = (TH1D*)gDirectory->Get(Form("h%s_MC",branchNames[i].c_str()));
        hInvMassCharmBaryonToOmegaPi_MC = HistosMC[0];

        // Set labels
        HistosMC[i]->GetYaxis()->SetTitle("Entries");
        HistosMC[i]->GetXaxis()->SetTitle(xTitles[i].c_str());
        HistosMC[i]->SetTitle(titles[i].c_str());

        // Draw the histogram
        HistosMC[i]->Draw("HIST");

        // Legend
        TLegend *legend_MC = new TLegend(0.15, 0.8, 0.25, 0.88);
        legend_MC->AddEntry(HistosMC[i], "MC", "l");
        legend_MC->Draw();

        // Define the path and save the canvas
        const char* savePath_MC = Form("/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/MC/LHC24e3/f%s_MC_LHC24e3.pdf", branchNames[i].c_str());
        canvas_MC->SaveAs(savePath_MC);

        // Checking binning
        // std::cout << "Number of bins for" << branchNames[i] << ": " << HistosMC[i]->GetNbinsX() << std::endl;

        // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
        double xmin_h1 = HistosMC[i]->GetBinLowEdge(1);
        double xmax_h1 = HistosMC[i]->GetBinLowEdge(HistosMC[i]->GetNbinsX()) + HistosMC[i]->GetBinWidth(HistosMC[i]->GetNbinsX());
        std::cout << "Minimum x-value for " << branchNames[i] << ": " << xmin_h1 << std::endl;
        std::cout << "Maximum x-value for " << branchNames[i] << ": " << xmax_h1 << std::endl;
    }
}

//----------------------------------------------------------------------------------------------------------------------------

void retrieveData(const char* filename = "/Users/fernandatorres/Desktop/Omegac_analysis/ROOTFiles/Data/LHC23_apass4/AO2D_365078.root") {
    
    // Open ROOT file
    TFile *file = new TFile(filename);
    TDirectory *dir = (TDirectory*)file->Get("DF_2300440396766976");
    TTree *tree = (TTree*)dir->Get("O2hfkfomegacfull");

    for (int i = 0; i < nHistos; i++) {
        // Create canvas and draw branch
        TCanvas* canvas_Data = new TCanvas(Form("canvas_Data_%d", i), "Data Histogram", 900, 600);
        tree->Draw(Form("f%s>>h%s_Data(100, %f, %f)", branchNames[i].c_str(), branchNames[i].c_str(), minValues[i], maxValues[i]));

        // Retrieve the histogram
        HistosData[i] = (TH1D*)gDirectory->Get(Form("h%s_Data",branchNames[i].c_str()));
        hInvMassCharmBaryonToOmegaPi_Data = HistosData[0];

        // Set labels
        HistosData[i]->GetYaxis()->SetTitle("Entries");
        HistosData[i]->GetXaxis()->SetTitle(xTitles[i].c_str());
        HistosData[i]->SetTitle(titles[i].c_str());

        // Draw the histogram
        HistosData[i]->Draw("HIST");

        // Legend
        TLegend *legend_Data = new TLegend(0.15, 0.8, 0.25, 0.88);
        legend_Data->AddEntry(HistosData[i], "Data", "l");
        legend_Data->Draw();

        // Define the path and save the canvas
        const char* savePath_Data = Form("/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/Data/LHC23_apass4/f%s_Data_LHC23_apass4.pdf", branchNames[i].c_str());
        canvas_Data->SaveAs(savePath_Data);

        // Checking binning
        // std::cout << "Number of bins for" << branchNames[i] << ": " << HistosData[i]->GetNbinsX() << std::endl;

        // Bin-based approach to check lower edge of 1st bin and upper edge of last bin
        double xmin_h1 = HistosData[i]->GetBinLowEdge(1);
        double xmax_h1 = HistosData[i]->GetBinLowEdge(HistosData[i]->GetNbinsX()) + HistosData[i]->GetBinWidth(HistosData[i]->GetNbinsX());
        std::cout << "Minimum x-value for " << branchNames[i] << ": " << xmin_h1 << std::endl;
        std::cout << "Maximum x-value for " << branchNames[i] << ": " << xmax_h1 << std::endl;
    }
}

//----------------------------------------------------------------------------------------------------------------------------

void combinedMCandData() {

        gStyle->SetOptStat(0);
    
        // Create canvas
        TCanvas* hInvMassCharmBaryon_combined = new TCanvas("hInvMassCharmBaryon_combined", "Combined Histograms", 900, 600);
        hInvMassCharmBaryon_combined->SetLogy();
    
        // Draw the MC histogram
        HistosMC[0]->SetLineColor(kRed);
        HistosMC[0]->Scale(1.0/HistosMC[0]->Integral());
        HistosMC[0]->Draw("HIST");
    
        // Create the Trimmed Data histogram (cutting the middle part 2.55-2.85)
        TH1D* hTrimmed = (TH1D*)HistosData[0]->Clone("hTrimmed");
    
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
        TLegend* legend_invmass_combined = new TLegend(0.75, 0.8, 0.88, 0.88);
        legend_invmass_combined->AddEntry(HistosMC[0], "MC", "l");
        legend_invmass_combined->AddEntry(hTrimmed, "Data", "l");
        legend_invmass_combined->Draw();
    
        // Define the path and save the canvas
        const char* invmass_combined = "/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/hInvMassCharmBaryon_combined.pdf";
        hInvMassCharmBaryon_combined->SaveAs(invmass_combined);
    
    //----------------------------------------------------------------
    
    for (int i = 0; i < nHistos; i++) {
        // Create canvas and draw branch
        TCanvas* canvas_combined = new TCanvas(Form("canvas_combined_%d", i), "Combined Histogram", 900, 600);
        canvas_combined->SetLogy();

        // Set labels
        HistosMC[i]->GetYaxis()->SetTitle("Entries");
        HistosMC[i]->GetXaxis()->SetTitle(xTitles[i].c_str());
        HistosMC[i]->SetTitle(titles[i].c_str());
        
        HistosData[i]->GetYaxis()->SetTitle("Entries");
        HistosData[i]->GetXaxis()->SetTitle(xTitles[i].c_str());
        HistosData[i]->SetTitle(titles[i].c_str());

        // Draw MC histogram
        if (i == 0) {
            HistosMC[i]->SetLineColor(kRed);
            HistosMC[i]->Scale(1.0 / HistosMC[i]->Integral());
            HistosMC[i]->Draw("HIST");
        } else {
            HistosMC[i]->SetLineColor(kRed);
            HistosMC[i]->Scale(1.0 / HistosMC[i]->Integral());
            HistosMC[i]->Draw("HIST SAME");
        }
        
        // Draw on top Data histogram
        HistosData[i]->SetLineColor(kBlue);
        HistosData[i]->Scale(1.0 / HistosData[i]->Integral());
        HistosData[i]->Draw("HIST SAME");

        // Legend
        TLegend *legend_combined = new TLegend(0.15, 0.8, 0.25, 0.88);
        legend_combined->AddEntry(HistosMC[i], "MC", "l");
        legend_combined->AddEntry(HistosData[i], "Data", "l");
        legend_combined->Draw();

        // Define the path and save the canvas
        const char* savePath_combined = Form("/Users/fernandatorres/Desktop/Omegac_analysis/Histograms/CombinedHistos/LHC24e3_LHC23_apass4/f%s_combined.pdf", branchNames[i].c_str());
        canvas_combined->SaveAs(savePath_combined);
    }
}

int main() {
    retrieveMC();
    retrieveData();
    combinedMCandData();

    return 0;
}
