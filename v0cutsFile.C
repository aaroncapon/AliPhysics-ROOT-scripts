//File to store commonly used V0 selection cuts


struct v0cutsFile{

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

};
