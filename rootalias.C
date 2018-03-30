


//Format 1D histograms
//Just format colours
void format1Dhist(TH1* hist, Int_t colour, Int_t markerStyle = 21, Int_t markerSize = 1){
    hist->SetMarkerStyle(markerStyle);
    hist->SetMarkerColor(colour);
    hist->SetMarkerSize(markerSize);
    hist->SetLineColor(colour);
}
//Format colours, and add titles
void format1Dhist(TH1* hist, Int_t colour, TString xAxis, TString yAxis = "", Int_t markerStyle = 21, Int_t markerSize = 1){
    hist->SetMarkerStyle(markerStyle);
    hist->SetMarkerColor(colour);
    hist->SetMarkerSize(markerSize);
    hist->SetLineColor(colour);
    hist->GetYaxis()->SetTitle(yAxis);
    hist->GetXaxis()->SetTitle(xAxis);
}


//Function to format lower plot when taking ratios
void formatRatioPlot(TH1* hist, TString yAxis){

    hist->SetTitle("");

    hist->GetYaxis()->SetTitle(yAxis);
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

TH1F* calcDiElecRfactor(const TH3F* hPos, const TH3F* hNeg, const TH3F* hUnlike, Bool_t calcRfactor, Float_t minPt = 0, Float_t maxPt = 10, Float_t minMult = 0, Float_t maxMult = 100, Float_t setRfacOne = 0.3){

	Int_t minPtBin   = hPos->GetYaxis()->FindBin(minPt);
	Int_t maxPtBin   = hPos->GetYaxis()->FindBin(maxPt);
	Int_t minMultBin = hPos->GetZaxis()->FindBin(minMult);
	Int_t maxMultBin = hPos->GetZaxis()->FindBin(maxMult);

	//Clone used to make sure binning is identical.
	TH1F* rFactor     = (TH1F*)(hUnlike->ProjectionX("", minPtBin, maxPtBin, minMultBin, maxMultBin, "e"));
	TH1F* denominator = (TH1F*)(hNeg->ProjectionX("",    minPtBin, maxPtBin, minMultBin, maxMultBin, "e"));
	TH1F* tempHist    = (TH1F*)(hPos->ProjectionX("",    minPtBin, maxPtBin, minMultBin, maxMultBin, "e"));

	if(!rFactor){
		Printf("R factor plot not cloned (in calcDiElecRfactor)");
		return 0x0;
	}
	if(!denominator || !tempHist){
		Printf("Pos or Neg projection for Rfac not created (calcDiElecRfactor)");
		return 0x0;
	}

	//Get bin number for point at which we take R factor to be 1
	Int_t finalRealBin = rFactor->GetXaxis()->FindBin(setRfacOne);

	//Dummy R factor
	if(calcRfactor == kFALSE){
		rFactor->Reset(); //clear contents.
		for(Int_t i = 1; i <= rFactor->GetNbinsX(); i++){
			rFactor->SetBinContent(i, 1);
			rFactor->SetBinError(i, 0.001);
		}
	}
	//Real R factor
	else{
		Float_t valuePos, valueNeg;
		Float_t errorPos, errorNeg;
		for(Int_t i = 0; i <= hPos->GetNbinsX(); i++){

			valuePos = hPos->GetBinContent(i);
			valueNeg = hNeg->GetBinContent(i);

			errorPos = hPos->GetBinError(i);
			errorNeg = hNeg->GetBinError(i);

			if(i < finalRealBin){
				denominator->SetBinContent(i, 2*TMath::Sqrt(valuePos*valueNeg));
				denominator->SetBinError(i, TMath::Sqrt(errorPos) + TMath::Sqrt(errorNeg));
			}else{
				rFactor->SetBinContent(i, 1);
				rFactor->SetBinError(i, 0.00000001);
				denominator->SetBinContent(i, 1);
				denominator->SetBinError(i, 0.00000001);
			}
			if(valuePos == 0 && valueNeg == 0){
				Printf("A bin was empty in R fac calc. Using 1. Increase statistics!!");
				denominator->SetBinContent(i, 1);
			}
		}
		rFactor->Divide(denominator);
	}

	delete denominator;
	delete tempHist;

  return rFactor;
}

//R factor calculation with 1D histograms
TH1F* calcDiElecRfactor(const TH1F* hPos, const TH1F* hNeg, const TH1F* hUnlike, Bool_t calcRfactor, Float_t setRfacOne = 0.3){

	//Clone used to make sure binning is identical.
	TH1F* rFactor = (TH1F*)(hUnlike->Clone("rFactor"));
	TH1F* denominator = (TH1F*)(hNeg->Clone("denominator"));
	if(!rFactor){
		Printf("R factor plot not cloned (in calcDiElecRfactor)");
		return 0x0;
	}
	if(!denominator){
		Printf("Denominator for Rfac no created (calcDiElecRfactor)");
		return 0x0;
	}

	Int_t finalRealBin = rFactor->GetXaxis()->FindBin(setRfacOne);

	//Dummy R factor
	if(calcRfactor == kFALSE){
		rFactor->Reset(); //clear contents.
		for(Int_t i = 1; i <= rFactor->GetNbinsX(); i++){
			rFactor->SetBinContent(i, 1);
			rFactor->SetBinError(i, 0.001);
		}
	}
	//Real R factor
	else{
		Float_t valuePos, valueNeg;
		Float_t errorPos, errorNeg;
		for(Int_t i = 0; i <= hPos->GetNbinsX(); i++){

			valuePos = hPos->GetBinContent(i);
			valueNeg = hNeg->GetBinContent(i);

			errorPos = hPos->GetBinError(i);
			errorNeg = hNeg->GetBinError(i);

			if(i < finalRealBin){
				denominator->SetBinContent(i, 2*TMath::Sqrt(valuePos*valueNeg));
				denominator->SetBinError(i, TMath::Sqrt(errorPos) + TMath::Sqrt(errorNeg));
			}else{
				rFactor->SetBinContent(i, 1);
				rFactor->SetBinError(i, 0.00000001);
				denominator->SetBinContent(i, 1);
				denominator->SetBinError(i, 0.00000001);
			}
			/* if(valuePos == 0 && valueNeg == 0){ */
			/* 	Printf("A bin was empty in R fac calc. Using 1. Increase statistics!!"); */
			/* 	denominator->SetBinContent(i, 1); */
			/* } */
		}
		rFactor->Divide(denominator);
	}

	delete denominator;

  return rFactor;
}

//Calculate geomtric mean of like sign spectra for background calculation
TH1F* calcDiElecBackgr(const TH1F* hPos, const TH1F* hNeg){

    //Use geometric mean of like signs to calculate background
    TH1F* backgr = (TH1F*)hPos->Clone("backgr");
    backgr->Reset();

    Float_t valuePos, valueNeg;
    Float_t errorPos, errorNeg;
    for(Int_t i = 0; i <= hPos->GetNbinsX(); i++){

        valuePos = hPos->GetBinContent(i);
        valueNeg = hNeg->GetBinContent(i);
        errorPos = hPos->GetBinError(i);
        errorNeg = hNeg->GetBinError(i);
        backgr->SetBinContent(i, 2*TMath::Sqrt(valuePos*valueNeg));
        backgr->SetBinError(i, TMath::Sqrt(errorPos) + TMath::Sqrt(errorNeg));
    }
    return backgr;
}

//Two dimensional background calculation
TH2F* calcDiElecBackgr(const TH2F* hPos, const TH2F* hNeg){

    //Use geometric mean of like signs to calculate background
    TH2F* backgr = (TH2F*)hPos->Clone("backgr");
    backgr->Reset();

    Float_t valuePos, valueNeg;
    Float_t errorPos, errorNeg;
    for(Int_t i = 0; i <= hPos->GetNbinsX(); i++){
			for(Int_t j = 0; j <= hPos->GetNbinsY(); j++){

        valuePos = hPos->GetBinContent(i, j);
        valueNeg = hNeg->GetBinContent(i, j);
        errorPos = hPos->GetBinError(i, j);
        errorNeg = hNeg->GetBinError(i, j);
        backgr->SetBinContent(i, j, 2*TMath::Sqrt(valuePos*valueNeg));
        backgr->SetBinError(i, j, TMath::Sqrt(errorPos) + TMath::Sqrt(errorNeg));
			}
    }
    return backgr;
}
TH1* calcRawDiElecSpectrum(const TH1* unlike, const TH1* backgr, const TH1* rFactor = 0x0){

	TH1* rawSpectrum = (TH1*)unlike->Clone("rawSpectrum");

	TH1* correctedBackgr = (TH1*)backgr->Clone("correctedBackgr");
	if(rFactor){
		correctedBackgr->Multiply(rFactor);
	}

	rawSpectrum->Add(correctedBackgr, -1);

	return rawSpectrum;
}

TH1F* calcDiElecSpectrum(const TH1F* unlike, const TH1F* backgr, const TH1F* rFactor, TH1F* effCor = 0x0){

	Double_t intLuminosity = 1;

	//TODO: use vert. reconstruction and trigger efficiency

	TH1F* rawSpectrum = (TH1F*)unlike->Clone("rawSpectrum");

	TH1F* correctedBackgr = (TH1F*)backgr->Clone("correctedBackgr");
	correctedBackgr->Multiply(rFactor);

	rawSpectrum->Add(correctedBackgr, -1);

	if(effCor){
		Printf("Using efficiency correction!");
		rawSpectrum->Divide(effCor);
	}

	return rawSpectrum;
}

//Calculate significance, as per dielectron analysis definiton
TH1F* calcDiElecSignificance(const TH1F* signal, const TH1F* backgr){

    TH1F* significance = (TH1F*)signal->Clone("significance");

    Float_t errorSignal, errorBackgr;
    Float_t valueSignal, valueBackgr;
    Float_t binWidth;
    Float_t preScaling;
    Float_t finalError;

    for(Int_t i = 1; i <= significance->GetNbinsX(); i++){

        //Get S and B values
        valueSignal = signal->GetBinContent(i);
        valueBackgr = backgr->GetBinContent(i);
        errorSignal = signal->GetBinError(i);
        errorBackgr = backgr->GetBinError(i);
        binWidth = significance->GetBinWidth(i);

        //Find significance
        //Check if bins are empty. If so, assign dummy value
        if( (valueSignal == 0) && (valueBackgr == 0)){
            significance->SetBinContent(i, 0);
            significance->SetBinError(i, 0.000001);
        }
        else{
            preScaling = valueSignal/TMath::Sqrt(valueSignal + (2*valueBackgr));
            significance->SetBinContent(i, preScaling);


            finalError = 0.5*(TMath::Sqrt((errorSignal*errorSignal) + (16*errorBackgr*errorSignal) - 16*(errorBackgr*errorBackgr))/(errorSignal+(2*errorBackgr)));
            if(finalError != 0){
                significance->SetBinError(i, finalError);
            }else{
                significance->SetBinError(i, 0);
            }
        }
            //std::cout << "Sig: "       << valueSignal << ", backgr: " << valueBackgr << std::endl;
            //std::cout << "Bin width: " << binWidth << ", Bin " << i << " value: " << preScaling/TMath::Sqrt(binWidth) << std::endl;
    }


    return significance;
}

//Use Tefficiency class to calculate correct errors when finding selection
//efficiencies. Return result to histOrig
/* void calcTEfficiency(TH1* histEff, TH1* histOrig){ */

/* 	TEfficiency* histEff = new TEfficiency(*histEff, *histOrig); */

/* 	for(Int_t i = 0; i <= histOrig->GetNbinsX(); ++i){ */

/* 		histOrig->SetBinContent(i, histEff->GetEfficiency(i)); */
/* 		histOrig->SetBinError(i, TMath::Max(histEff->GetEfficiencyErrorLow(i), histEff->GetEfficiencyErrorUp(i))); */
/* 	} */
			
/* 	return; */
/* } */

//Common TLatex objects
TLatex* getTexTitle(Float_t xPos, Float_t yPos, Float_t textSize = 0.04){

    TLatex* tex = new TLatex(xPos, yPos, "ALICE Work in Progress");
    tex->SetNDC();
    tex->SetTextSize(textSize);
    tex->SetTextFont(42);

    return tex;
}
TLatex* getTexSystem(Float_t xPos, Float_t yPos, TString multRange = "", Bool_t isMC = kFALSE, Float_t textSize = 0.03){

    TString description = "p-Pb, #sqrt{#it{s}_{NN}} = 5.02 TeV";
		if(multRange != ""){
			description += ", " + multRange + " %";
		}
    if(isMC == kTRUE){
       description += ", DPMJET";
    }
    TLatex* tex = new TLatex(xPos, yPos, description);
    tex->SetNDC();
    tex->SetTextSize(textSize);
    tex->SetTextFont(42);

    return tex;
}
TLatex* getTexKinematics(Float_t xPos, Float_t yPos, Float_t textSize = 0.02){

    TLatex* tex = new TLatex(xPos, yPos, "0.2 < #it{p}_{T} < 10 GeV/#it{c}, |#eta| < 0.8");
    tex->SetNDC();
    tex->SetTextSize(textSize);
    tex->SetTextFont(42);

    return tex;
}
TLatex* getTexPairMom(Float_t xPos, Float_t yPos, Float_t textSize = 0.02, TString maxPt = "10", TString minPt = "0"){

	TString mid = "#it{p}_{T}^{pair} < ";
	TString units = " GeV/#it{c}";
	TLatex* tex = 0x0;
	if(minPt == "0"){
		TString pairPtDescription = mid + maxPt + units;
		tex = new TLatex(xPos, yPos, pairPtDescription);
	}
	else{
		TString pairPtDescription = minPt + " " + mid + maxPt + units;
		tex = new TLatex(xPos, yPos, pairPtDescription);
	}
	tex->SetNDC();
	tex->SetTextSize(textSize);
	tex->SetTextFont(42);

	return tex;
}
TLatex* getTexPairCuts(Float_t xPos, Float_t yPos, Bool_t hasITS, Float_t textSize = 0.02){

	TString massCut = "";
	if(hasITS){
		massCut = "#varphi_{V} < 2 for #it{m}_{ee} < 0.1 GeV/#it{c}^{2}";
	}else{
		massCut = "#varphi_{V} < 2 for #it{m}_{ee} < 0.1 GeV/#it{c}^{2}";
	}
	TLatex* tex = new TLatex(xPos, yPos, massCut);
	tex->SetNDC();
	tex->SetTextSize(textSize);
	tex->SetTextFont(42);

	return tex;
}
