bool calBadCalibFilterRecipe(int run,  float PuppiMET_pt, float PuppiMET_phi,  int nJet, RVec<float> Jet_pt, RVec<float> Jet_eta, RVec<float> Jet_phi, RVec<float> Jet_neEmEF, RVec<float> Jet_chEmEF) {
    if(run >= 362433 && run <= 367144){
        if (PuppiMET_pt > 100){
            for (int i = 0; i < nJet; i++){
                float deltaPhi = std::abs(Jet_phi[i] - PuppiMET_phi) < M_PI ? std::abs(Jet_phi[i] - PuppiMET_phi) : 2*M_PI - std::abs(Jet_phi[i] - PuppiMET_phi);
                if(Jet_pt[i] > 50 && Jet_eta[i] > -0.5 && Jet_eta[i] < -0.1 && (Jet_neEmEF[i] > 0.9 || Jet_chEmEF[i] > 0.9) && deltaPhi > 2.9)
                    return 0;
            }
        }
    }
    return 1;
}
