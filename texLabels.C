//Common TLatex objects
TLatex* getTexTitle(Float_t xPos, Float_t yPos, TString title = "", Float_t textSize = 0.04){

	
	TLatex* tex = new TLatex(xPos, yPos, title);
	tex->SetNDC();
	tex->SetTextSize(textSize);
	tex->SetTextFont(42);

	return tex;
}
TLatex* getTexSystem(Float_t xPos, Float_t yPos, TString multRange = "", Bool_t isMC = kFALSE, Float_t textSize = 0.03){

	TString description = "p-Pb, #sqrt{#it{s}_{NN}} = 5.02 TeV";
	if(multRange != "" && multRange != "MB"){
		description += ", " + multRange + " %";
	}
	else if(multRange == "MB"){
		description += ", MB";
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
TLatex* getTexKinematics(Float_t xPos, Float_t yPos, Float_t textSize = 0.03){

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
TLatex* getTexPairCuts(Float_t xPos, Float_t yPos, Float_t textSize = 0.02){

	TLatex* tex = new TLatex(xPos, yPos, "#varphi_{V} < 2 for #it{m}_{ee} < 0.1 GeV/#it{c}^{2}");
	tex->SetNDC();
	tex->SetTextSize(textSize);
	tex->SetTextFont(42);

	return tex;
}
