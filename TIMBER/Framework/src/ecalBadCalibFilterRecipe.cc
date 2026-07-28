
#include "../include/ecalBadCalibFilterRecipe.h"
bool ecalBadCalibFilterRecipe(int run,  float PuppiMET_pt, float PuppiMET_phi,  int nJet, RVec<float> Jet_pt, RVec<float> Jet_eta, RVec<float> Jet_phi, RVec<float> Jet_neEmEF, RVec<float> Jet_chEmEF) {
    if(run >= 362433 && run <= 367144){
        if (PuppiMET_pt > 100){
            for (int i = 0; i < nJet; i++){
                float deltaPhi = TMath::Abs(Jet_phi.at(i) - PuppiMET_phi) < TMath::Pi() ? TMath::Abs(Jet_phi.at(i) - PuppiMET_phi) : 2*TMath::Pi() - TMath::Abs(Jet_phi.at(i) - PuppiMET_phi);
                if(Jet_pt.at(i) > 50 && Jet_eta.at(i) > -0.5 && Jet_eta.at(i) < -0.1  && Jet_phi.at(i) > -2.1 && Jet_phi.at(i) < -1.8 && (Jet_neEmEF.at(i) > 0.9 || Jet_chEmEF.at(i) > 0.9) && deltaPhi > 2.9)
                    return 0;
            }
        }
    }
    return 1;
}
