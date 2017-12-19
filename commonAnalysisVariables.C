//A file to store common variables used throughout analysis
struct analysisCuts16q{
	
	//PID cuts
	const Float_t MVAcut = 0.05;
	//cent cuts (same as Scheids DCA analysis cuts)
	const Float_t minEsigITS = -3;
	const Float_t maxEsigITS = 1;
	const Float_t minEsigTPC = -1.5;
	const Float_t maxEsigTPC = 4;
	const Float_t minPsigTPC = 3.5;
	const Float_t maxEsigTOF = 3;


	//--------- Track cuts --------------------//
	const Float_t minTPCcrossed = 100;
	const Float_t minTPCclusters = 80;
	const Float_t minTPCcrossFindable = 0.8;
	const Float_t maxTPCcrossFindable = 1.1;
	const Float_t maxFracTPCshared = 0.4;

	const Float_t minITShits = 4;
	const Float_t maxITSchi2 = 4.5;
	const Float_t maxfITSshared = 0.01;

	const Float_t maxDCAz = 3;
	const Float_t maxDCAxy = 1;


	//--------- Pair cuts --------------------//
	const Float_t minInvMassPhiVcut = 0.02; //Exclude smaller than
	const Float_t maxPhiV = (3/4.)*TMath::Pi(); //Exclude greater than

	//Float_t minOpAngle = 0.05; //Exclude smaller than

	//Float_t minInvMassPrefilter = 0.05;
	//Float_t minOpAnglePrefilter = 0.05;

	//Float_t maxPhiVprefilter = 2.5;
};
