//Collection of functions used during pairing process of potentail dielectron
//candidates
//----- Functions -----
//PhiV - angle between plane of pair and magnetic field
//Momentum from pt, eta and phi
//Invariant mass of mother particle
//Opening angle between pair
//Pair pt 

//Calculate angle between the plane of the pair and the magentic field
Float_t calcPhiV(const TVector3 &part1, const TVector3 &part2, Int_t leg1Charge, Int_t leg2Charge){

	//Check for an empty leg before calculation
	if(part1.Mag() == 0 || part2.Mag() == 0){
		std::cout << "One track leg is empty...." << std::endl;
		return -1.0;
	}

	//Need to check if using different dataset (made for LHC16q)
	//Define magnetic field direction (0,0,1)
	TVector3 mag_field(0,0,1);
	TVector3 temp1, temp2;

	//Potentially switch 1 <-> 2 based on charges and mag field direction
	if(leg1Charge == leg2Charge){//Like-sign
		if(leg1Charge > 0){
			temp1 = part2;
			temp2 = part1;
		}
		else{
			temp1 = part1;
			temp2 = part2;
		}
	}
	else{//Unlike-sign
		if(leg1Charge < 0){
			temp1 = part2;
			temp2 = part1;
		}
		else{
			temp1 = part1;
			temp2 = part2;
		}
	}

	TVector3 u = (temp1 + temp2).Unit();
	TVector3 v = temp1.Cross(temp2);

	TVector3 w   = u.Cross(v);
	Double_t w_mag = w.Mag();

	TVector3 ua  = (u.Cross(mag_field)).Unit();
	Double_t ua_mag = ua.Mag();

	Float_t w_ua = w.Dot(ua)/(w_mag * ua_mag);

	Float_t phiV = TMath::ACos(w_ua);

	return phiV;

}

//Calculate momentum of track leg
TVector3 calcMomentum(Double_t pT, Double_t phi, Double_t eta){

	TVector3 momentum;
	momentum.SetXYZ(pT*TMath::Cos(phi), pT*TMath::Sin(phi), pT*TMath::SinH(eta));

	return momentum;
}

//Calculate mass of mother particle
Float_t calcMass(const TVector3 &part1, const TVector3 &part2){

    //Check for an empty leg before calculation
    if(part1.Mag() == 0 || part2.Mag() == 0){
        std::cout << "One track leg is empty...." << std::endl;
        return -1.0;
    }

    Float_t mass = TMath::Sqrt(TMath::Abs(2*part1.Mag()*part2.Mag()*(1-TMath::Cos(part1.Angle(part2)))));
    //mass = TMath::Sqrt(TMath::Abs(mass));
    return mass;
}

//Calculate opening angle between decay legs
Float_t calcOpAngle(const TVector3 &part1, const TVector3 &part2){

    Float_t opAngle = part1.Angle(part2);
    return opAngle;
}

Float_t calcPairPt(const TVector3 &part1, const TVector3 &part2){

    TVector3 pairMom = part1 + part2;
    Float_t pairPt = pairMom.Pt();

    return pairPt;
}

