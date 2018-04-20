//A collection of commonly calculated distributions used for the calculation of
//the dielectron invariant mass spectrum. 
//
//1D inputs must be as a function of mass. 
//2D inputs can contain any desired axes.
//3D inputs must be functions of mass, pairPt and multiplicity.
//
//Functions:
//R factor calculations (Acceptance correction factor)
//	- Inputs 1D, output 1D
//	-	Inputs 3D, output 1D
//Combinatorial background (geometric mean)
//	- Inputs 1D, output 1D
//	- Inputs 2D, output 2D
//Spectrum calculations
//	- Inputs 1D (UL and comb.), output 1D 
//	- Inputs 3D (UL and comb.), output 3D
//Signal to background ratio
//	- Inputs 1D, output 1D
//Statistical significance
//	-Inputs 1D, output 1D
//

//TODO: 1D and 3D input options for all the above functions


//------------------------- R factor functions ---------------------------//
//1D inputs
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
//3D inputs
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


//-------------------- Combinatorial background ----------------------//
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

//-------------------- Spectrum Calculations -------------------------//
//1D inputs and ouputs
TH1F* calcDiElecSpectrum(const TH1F* unlike, const TH1F* backgr, const TH1F* rFactor = 0x0, TH1F* effCor = 0x0){

	if(!unlike){
		std::cout << "Unlike hist. not passed for spectrum calculation." << std::endl;
		return 0x0;
	}
	if(!backgr){
		std::cout << "Background hist. not passed for spectrum calculation." << std::endl;
		return 0x0;
	}

	Double_t intLuminosity = 1;

	//TODO: apply vert. reconstruction and trigger efficiency

	TH1F* rawSpectrum = (TH1F*)unlike->Clone("rawSpectrum");

	TH1F* correctedBackgr = (TH1F*)backgr->Clone("correctedBackgr");
	if(rFactor){
		std::cout << "Applying R factor" << std::endl;
		correctedBackgr->Multiply(rFactor);
	}else{
		std::cout << "No R factor applied" << std::endl;
	}

	rawSpectrum->Add(correctedBackgr, -1);

	if(effCor){
		Printf("Using efficiency correction!");
		rawSpectrum->Divide(effCor);
	}

	return rawSpectrum;
}
//3D input and output
TH3F* calcDiElecSpectrum(const TH3F* unlike, const TH3F* backgr, const TH3F* rFactor = 0x0, TH3F* effCor = 0x0){

	if(!unlike){
		std::cout << "Unlike hist. not passed for spectrum calculation." << std::endl;
		return 0x0;
	}
	if(!backgr){
		std::cout << "Background hist. not passed for spectrum calculation." << std::endl;
		return 0x0;
	}

	TH3F* rawSpectrum = (TH3F*)unlike->Clone("rawSpectrum");

	TH3F* correctedBackgr = (TH3F*)backgr->Clone("correctedBackgr");
	if(rFactor){
		std::cout << "Applying R factor" << std::endl;
		correctedBackgr->Multiply(rFactor);
	}else{
		std::cout << "No R factor applied" << std::endl;
	}

	rawSpectrum->Add(correctedBackgr, -1);

	if(effCor){
		Printf("Using efficiency correction!");
		rawSpectrum->Divide(effCor);
	}

	return rawSpectrum;
}



//-------------------- Signal-to-Background ratio -------------------//
TH1F* calcDiElecSB(const TH1* signal, const TH1* backgr){

	if(!signal){
		Printf("Signal hist missing for SB calculation");
		return 0x0;
	}
	if(!backgr){
		Printf("Background hist missing for SB calculation");
		return 0x0;
	}

	TH1F* histSB = (TH1F*)signal->Clone("histSB");
	histSB->Divide(backgr);

	return histSB;
}

//-------------------- Statistical significance ---------------------//
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

