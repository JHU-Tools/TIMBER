
#include <ROOT/RVec.hxx>
using namespace ROOT::VecOps;
RVec<float> getRawVal(int nJet, RVec<float> val, RVec<float> rawFactor){
    ROOT::VecOps::RVec<Float_t> rawVal = {};
    for (int i = 0; i < nJet; i ++){
        rawVal.push_back( val.at(i) * (1 - rawFactor.at(i) ) );
    }
    return rawVal;
}


RVec<float> JME_defineVal(int n, RVec<int> Idx, RVec<float> Val_all){
    ROOT::VecOps::RVec<float> Val = {};
    for (int i = 0; i < n; i ++){
        if(Idx.at(i) < 0)
            Val.push_back(std::numeric_limits<float>::lowest());
        else
            Val.push_back(Val_all.at(Idx.at(i)));    
    }
    return Val;
}


RVec<float> JME_invM(int nFatJet, RVec<int> FatJet_subJetIdx1, RVec<int> FatJet_subJetIdx2, RVec<float> subjet1_pt, RVec<float> subjet1_eta, RVec<float> subjet1_phi, RVec<float> subjet1_mass,RVec<float> subjet2_pt, RVec<float> subjet2_eta, RVec<float> subjet2_phi, RVec<float> subjet2_mass){
    RVec<float> mSDs = {};
    for(int i = 0; i < nFatJet; i++){
        if (FatJet_subJetIdx1.at(i) < 0 && FatJet_subJetIdx2.at(i) < 0)
            mSDs.push_back(-1);
        else{
            ROOT::Math::PtEtaPhiMVector vector1(0,0,0,0);
            ROOT::Math::PtEtaPhiMVector vector2(0,0,0,0);
            if (FatJet_subJetIdx1.at(i) >= 0 ){
                float mass1 = subjet1_mass.at(i);
                float pt1 = subjet1_pt.at(i);
                float eta1 = subjet1_eta.at(i);
                float phi1 = subjet1_phi.at(i);
                vector1 =  ROOT::Math::PtEtaPhiMVector(pt1, eta1, phi1, mass1);
            }
            if (FatJet_subJetIdx2.at(i) >= 0 ){
                float mass2 = subjet2_mass.at(i);
                float pt2 = subjet2_pt.at(i);
                float eta2 = subjet2_eta.at(i);
                float phi2 = subjet2_phi.at(i);

                vector2 = ROOT::Math::PtEtaPhiMVector(pt2, eta2, phi2, mass2);
            }
            RVec<ROOT::Math::PtEtaPhiMVector> Vectors = {vector1, vector2};
            mSDs.push_back(hardware::InvariantMass(Vectors));
        }
            
            
    }
    return mSDs;

}



