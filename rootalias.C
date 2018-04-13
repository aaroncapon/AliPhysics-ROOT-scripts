//Common histogram formatting operations

//Format 1D histograms
//Just format colours
void format1Dhist(TH1* hist, Int_t colour, Int_t markerStyle = 21, Int_t markerSize = 1){
    hist->SetMarkerStyle(markerStyle);
    hist->SetMarkerColor(colour);
    hist->SetMarkerSize(markerSize);
    hist->SetLineColor(colour);
		hist->SetLineWidth(2);
}
//Format colours, and add titles
void format1Dhist(TH1* hist, Int_t colour, TString xAxis, TString yAxis = "", Int_t markerStyle = 21, Int_t markerSize = 1){
    hist->SetMarkerStyle(markerStyle);
    hist->SetMarkerColor(colour);
    hist->SetMarkerSize(markerSize);
    hist->SetLineColor(colour);
		hist->SetLineWidth(2);
    hist->GetYaxis()->SetTitle(yAxis);
    hist->GetXaxis()->SetTitle(xAxis);
}


//Function to format lower plot when taking ratios
void formatRatioPlot(TH1* hist, TString yAxis = "", Int_t colour = kWhite){

    hist->SetTitle("");
		if(colour != kWhite){
			hist->SetMarkerColor(colour);
			hist->SetLineColor(colour);
		}
		if(yAxis != ""){
			hist->GetYaxis()->SetTitle(yAxis);
		}
    hist->GetYaxis()->CenterTitle();
    hist->GetYaxis()->SetNdivisions(505);
    hist->GetYaxis()->SetTitleSize(20);
    hist->GetYaxis()->SetTitleFont(43);
    hist->GetYaxis()->SetTitleOffset(1.55);
    hist->GetYaxis()->SetLabelFont(43);
    hist->GetYaxis()->SetLabelSize(15);

    hist->GetXaxis()->SetTitleSize(20);
    hist->GetXaxis()->SetTitleFont(43);
    hist->GetXaxis()->SetTitleOffset(4.);
    hist->GetXaxis()->SetLabelFont(43);
    hist->GetXaxis()->SetLabelSize(15);

    return;
}
