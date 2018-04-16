//File to store commonly used V0 selection cuts

//V0 cuts
const Float_t minPointing = 0.998;
const Float_t minImpactXY = 0.11;
const Float_t maxDCA = 0.9;

//pt refers to transverse momentum of decay particle
//Lambda 
const Float_t lam_maxPt = 0.10;
const Float_t lam_minPt = 0.096;
const Float_t lam_maxAlpha = 0.75;
const Float_t lam_minAlpha = 0.62;
//Anti-Lambda 
const Float_t antilam_maxPt = 0.10;
const Float_t antilam_minPt = 0.096;
const Float_t antilam_maxAlpha = -0.62;
const Float_t antilam_minAlpha = -0.75;

//K short
const Float_t k_maxPt = 0.21;
const Float_t k_minPt = 0.2;
const Float_t k_maxAlpha = 0.35;
const Float_t k_minAlpha = -0.35;

//Gamma
const Float_t gamma_maxPt = 0.006;
const Float_t gamma_maxAlpha = 0.4;
const Float_t gamma_minAlpha = -0.4;

//Functions
Bool_t isGammaDecay(Float_t ptArm, Float_t alpha){

	Bool_t answer = kTRUE;
	if(alpha < gamma_minAlpha || alpha > gamma_maxAlpha || ptArm > gamma_maxPt){
		answer = kFALSE;
		return answer;
	} 
	return answer;
}

Bool_t isV0accepted(Float_t pointing, Float_t rLength, Float_t impactXY, Float_t DCA){

	Bool_t answer = kTRUE;

	if(pointing < minPointing){ 
		answer = kFALSE; 
		return answer;
	}
	if(impactXY < minImpactXY){ 
		answer = kFALSE; 
		return answer;
	}
	if(DCA > maxDCA){ 
		answer = kFALSE; 
		return answer;
	}

	return answer;
}
