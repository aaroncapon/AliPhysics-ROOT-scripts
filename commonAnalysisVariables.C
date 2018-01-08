//A file to store common variables used throughout analysis
struct analysisCuts16q{
	
	//------------PID cuts-------------------//
	//MVA cuts
	const Float_t MVAcut_cent = 0.05;
	const Float_t MVAcut_fast = 0.1;

	//Standard Cuts
	//Common cuts between data sets
	const Float_t minEsigITS = -3;
	const Float_t maxEsigITS = 1;
	const Float_t minEsigTOF = -3;
	const Float_t maxEsigTOF = 3;
	//cent specific PID cuts
	const Float_t minEsigTPC_cent = -1.5;
	const Float_t maxEsigTPC_cent = 4;
	const Float_t minPsigTPC_cent = 3.5;
	//fast speicific PID cuts
	const Float_t minEsigTPC_cent = -3;
	const Float_t maxEsigTPC_cent = 3;
	const Float_t minPsigTPC_cent = 4;


	//--------- Track cuts --------------------//
	const Float_t minTPCcrossed = 100;
	const Float_t minTPCclusters = 80;
	const Float_t minTPCcrossFindable = 0.8;
	const Float_t maxTPCcrossFindable = 1.1;
	const Float_t maxFracTPCshared = 0.4;

	//ITS cuts are implented as less than cuts
	const Float_t minITShits_cent = 4;
	const Float_t minITShits_fast = 3;

	const Float_t maxITSchi2 = 4.5;
	const Float_t maxfITSshared = 0.01;

	const Float_t maxDCAz = 3;
	const Float_t maxDCAxy = 1;

	const Bool_t reqSPD = kTRUE;

	//--------- Pair cuts --------------------//
	const Float_t minPhiVmassCut = 0.02; //Exclude smaller than
	const Float_t maxPhiV = (3/4.)*TMath::Pi(); //Exclude greater than

	//Float_t minOpAngle = 0.05; //Exclude smaller than

	//Float_t minInvMassPrefilter = 0.05;
	//Float_t minOpAnglePrefilter = 0.05;

	const Float_t minPhiVmassPre = 0.02; //Exclude smaller than
	const Float_t maxPhiVPre = (3/4.)*TMath::Pi(); //Exclude greater than
};
