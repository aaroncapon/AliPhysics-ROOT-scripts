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
	const Float_t minEsigTPC_fast = -3;
	const Float_t maxEsigTPC_fast = 3;
	const Float_t minPsigTPC_fast = 4;


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
	const Float_t minPhiVmassCut_cent = 0.100; //Exclude smaller than
	const Float_t minPhiVmassCut_fast = 0.100; //Exclude smaller than
	const Float_t maxPhiV = 2; //Exclude greater than

	const Float_t minPhiVmassPre = 0.02; //Exclude smaller than
	const Float_t maxPhiVPre = (3/4.)*TMath::Pi(); //Exclude greater than

	//Cent 
	//Number reference tracks in mult classes
	const Float_t refTracksTotal_cent = 6683318784;
	const Float_t refTracks0020_cent = 2815773952;
	const Float_t refTracks2040_cent = 1819967616;
	const Float_t refTracks4060_cent = 1261865472;
	const Float_t refTracks6080_cent = 785711488;
	const Float_t refTracks4080_cent = refTracks4060_cent + refTracks6080_cent;
	
	//Fast
	//Number reference tracks in mult classes
	const Float_t refTracksTotal_fast = 6633006080;
	const Float_t refTracks0020_fast = 2794202112;
	const Float_t refTracks2040_fast = 1806116480;
	const Float_t refTracks4060_fast = 1252523136;
	const Float_t refTracks6080_fast = 780171328;
	const Float_t refTracks4080_fast = refTracks4060_fast + refTracks6080_fast;
	
};

struct cutVariations16q{
	
	//------------PID cuts-------------------//
	//MVA cuts
	const Float_t MVAcut_cent[15]         = {0.05, 0.1, 0.0, -0.1, -0.05,  0.15,  0.0, 0.05, 0.05, -0.1, 0.2, -0.2, 0.0,  0.1, -0.1};
	const Float_t MVAcut_fast[15]         = {0.10, 0.4, 0.2,  0.0, -0.01, -0.05, 0.05, 0.15, 0.20, -0.2, 0.0,  0.1, 0.2, -0.1,  0.0};
	const Float_t minTPCcrossed[15]       = { 100,  80, 100,   90,   110,    80,   80,  100,   80,  110,  90,  100,  80,  100,   80};
	const Float_t minTPCclusters[15]      = {  80,  70,  90,   80,   100,   100,   70,   90,   90,   90, 100,  100,  80,   80,  100};
	const Float_t minTPCcrossFindable[15] = { 0.8, 0.7, 0.6,  0.8,   0.9,   0.9,  0.6,  0.9,  0.6,  0.8, 0.7,  0.6, 0.8,  0.8,  0.5};
	const Float_t maxTPCcrossFindable[15] = { 1.1, 1.1, 1.1,  1.1,   1.1,   1.1,  1.1,  1.1,  1.1,  1.1, 1.1,  1.1, 1.1,  1.1,  1.1};
	const Float_t maxFracTPCshared[15]    = { 0.4, 0.2, 0.6,  0.5,   0.5,   0.3,  0.3,  0.4,  0.5,  0.4, 0.4,  0.6, 0.5,  0.4,  0.4};
	const Float_t minITShits_cent[15]     = {   4,   5,   6,    5,     4,     4,    4,    5,    5,    4,   6,    6,   4,    5,    4};
	const Float_t minITShits_fast[15]     = {   3,   4,   4,    3,     3,     4,    4,    4,    3,    3,   4,    3,   3,    3,    3};
	const Float_t maxITSchi2[15]          = { 4.5, 3.5, 3.5,  3.5,     5,     6,    7,  100,  4.5,  4.5, 3.5,  100, 4.5,    7,  3.5};
		
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
	const Float_t minEsigTPC_fast = -3;
	const Float_t maxEsigTPC_fast = 3;
	const Float_t minPsigTPC_fast = 4;

	//Conversion cuts not varied for this study
	const Float_t maxfITSshared = 0.01;
	const Bool_t reqSPD = kTRUE;

	//--------- Pair cuts --------------------//
	const Float_t minPhiVmassCut_cent = 0.100; //Exclude smaller than
	const Float_t minPhiVmassCut_fast = 0.100; //Exclude smaller than
	const Float_t maxPhiV = 2; //Exclude greater than
		
};
//------Varied track cuts for systematics
//PID cuts are held constant for these cut sets
//Define loose track cuts (for systematic study)
struct looseCuts16q{
		
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
	const Float_t minEsigTPC_fast = -3;
	const Float_t maxEsigTPC_fast = 3;
	const Float_t minPsigTPC_fast = 4;

	//Track cuts
	const Float_t minTPCcrossed = 80;
	const Float_t minTPCclusters = 60;
	const Float_t minTPCcrossFindable = 0.6;
	const Float_t maxTPCcrossFindable = 1.1;
	const Float_t maxFracTPCshared = 1.0;

	//ITS cuts are implented as less than cuts
	const Float_t minITShits_cent = 3;
	const Float_t minITShits_fast = 2;

	const Float_t maxITSchi2 = 10;
	const Float_t maxfITSshared = 0.01;

	const Float_t maxDCAz = 5;
	const Float_t maxDCAxy = 2;

	const Bool_t reqSPD = kTRUE;

	//--------- Pair cuts --------------------//
	const Float_t minPhiVmassCut = 0.02; //Exclude smaller than
	const Float_t maxPhiV = (3/4.)*TMath::Pi(); //Exclude greater than

	const Float_t minPhiVmassPre = 0.02; //Exclude smaller than
	const Float_t maxPhiVPre = (3/4.)*TMath::Pi(); //Exclude greater than
};

//Define tight track cuts (for systematic study)
struct tightCuts16q{
		
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
	const Float_t minEsigTPC_fast = -3;
	const Float_t maxEsigTPC_fast = 3;
	const Float_t minPsigTPC_fast = 4;

	//Track cuts
	const Float_t minTPCcrossed = 110;
	const Float_t minTPCclusters = 90;
	const Float_t minTPCcrossFindable = 0.9;
	const Float_t maxTPCcrossFindable = 1.1;
	const Float_t maxFracTPCshared = 0.2;

	//ITS cuts are implented as less than cuts
	const Float_t minITShits_cent = 5;
	const Float_t minITShits_fast = 3;

	const Float_t maxITSchi2 = 3.5;
	const Float_t maxfITSshared = 0.01;

	const Float_t maxDCAz = 2.;
	const Float_t maxDCAxy = 0.5;

	const Bool_t reqSPD = kTRUE;

	//--------- Pair cuts --------------------//
	const Float_t minPhiVmassCut = 0.02; //Exclude smaller than
	const Float_t maxPhiV = (3/4.)*TMath::Pi(); //Exclude greater than

	const Float_t minPhiVmassPre = 0.02; //Exclude smaller than
	const Float_t maxPhiVPre = (3/4.)*TMath::Pi(); //Exclude greater than
};
