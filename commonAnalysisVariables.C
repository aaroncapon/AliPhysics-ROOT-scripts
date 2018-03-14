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
	const Float_t refTracksTotal_cent = 7059386368;
	const Float_t refTracks0020_cent = 2815773952;
	const Float_t refTracks2060_cent = 3081831936;
	const Float_t refTracks60100_cent = 1161783680;
	//Average number of tracks
	const Float_t aveTracksTotal_cent = 27.09;
	const Float_t aveTracks0020_cent = 54.5;
	const Float_t aveTracks2060_cent = 29.6;
	const Float_t aveTracks60100_cent = 10.86;

	//Fast
	//Number reference tracks in mult classes
	const Float_t refTracksTotal_fast = 7005612032;
	const Float_t refTracks0020_fast = 2794202112;
	const Float_t refTracks2060_fast = 3058640128;
	const Float_t refTracks60100_fast = 1152771840;
	//Average number of tracks
	const Float_t aveTracksTotal_fast = 26.93;
	const Float_t aveTracks0020_fast = 54.19;
	const Float_t aveTracks2060_fast = 29.43;
	const Float_t aveTracks60100_fast = 10.79;

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
