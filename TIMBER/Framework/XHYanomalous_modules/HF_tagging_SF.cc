#include "TIMBER/Framework/XHYanomalous_modules/HF_tagging_SF.h"

//Assign SFs based on year
HF_tagging_SF::HF_tagging_SF(float eff,int year){
	this->_eff = eff;
    switch (year) {
        case 2016:
            // Copy SF2016 array to SFs
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 7; ++j) {
                    SFs[i][j] = SF2016[i][j];
                    this->_wp = 0.9883;
                }
            }
            break;

        case 2017:
            // Copy SF2017 array to SFs
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 7; ++j) {
                    SFs[i][j] = SF2017[i][j];
                    this->_wp = 0.9870;
                }
            }
            break;

        case 2018:
            // Copy SF2018 array to SFs
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 7; ++j) {
                    SFs[i][j] = SF2018[i][j];
                    this->_wp = 0.9880;
                }
            }
            break;

        default:
                // Use SF2016APV as the default array
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 7; ++j) {
                        SFs[i][j] = SF2016APV[i][j];
                        this->_wp = 0.9883;
                    }
                }
                break;
    }

}

// Get the SF value based on pt
float HF_tagging_SF::getSFValue(float pt,int variation) {//variation 0,1,2 nom,down,up
    int ptIndex = -1;

    // Determine the pt index
    if (pt >= 250 && pt < 300) ptIndex = 0;
    else if (pt >= 300 && pt < 350) ptIndex = 1;
    else if (pt >= 350 && pt < 400) ptIndex = 2;
    else if (pt >= 400 && pt < 450) ptIndex = 3;
    else if (pt >= 450 && pt < 500) ptIndex = 4;
    else if (pt >= 500 && pt < 600) ptIndex = 5;
    else if (pt >= 600) ptIndex = 6;

    // Check if ptIndex is valid and return the SF value
    if (ptIndex != -1) {
        return SFs[variation][ptIndex];
    } else {
        std::cerr << "Warning: Invalid pt range for pt = " << pt << std::endl;
        return 1.0;  // Default value
    }
}

// Get event weight based on pt and PNet score
std::vector<float> HF_tagging_SF::getWeights(float pt,float pnet) {
    std::vector<float> out(3);
    float sf_nom = getSFValue(pt,0);
    float sf_down = getSFValue(pt,1);
    float sf_up  = getSFValue(pt,2);
    if(pnet>this->_wp){
        out[0] = sf_nom;
        out[1] = sf_down;
        out[2] = sf_up;
    }
    else{//SF_F = (1 - eff_pass*SF_pass) / 1 - eff_pass
        out[0] = (1.-this->_eff*sf_nom)/(1.-this->_eff);
        out[1] = (1.-this->_eff*sf_down)/(1.-this->_eff);
        out[2] = (1.-this->_eff*sf_up)/(1.-this->_eff);
    }
    return out;
}

std::vector<float> HF_tagging_SF::evtWeight(int nFatJet,RVec<float> FatJet_pt, RVec<float> FatJet_particleNetMD_Xbb,RVec<float> FatJet_particleNetMD_QCD){
    if(nFatJet<2){
        return {1.0,1.0,1.0};
    }
    if(FatJet_pt[0]<300 || FatJet_pt[1]<300.){
        return {1.0,1.0,1.0};
    }
    float pnet0 = FatJet_particleNetMD_Xbb[0]/(FatJet_particleNetMD_Xbb[0]+FatJet_particleNetMD_QCD[0]);
    float pnet1 = FatJet_particleNetMD_Xbb[1]/(FatJet_particleNetMD_Xbb[1]+FatJet_particleNetMD_QCD[1]);
    if(pnet0>pnet1){
        std::vector<float> out = getWeights(FatJet_pt[0],pnet0);
        return out;

    }
    else{
        std::vector<float> out = getWeights(FatJet_pt[1],pnet1);
        return out;
    }
}
