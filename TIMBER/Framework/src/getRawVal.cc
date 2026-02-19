
#include <ROOT/RVec.hxx>
using namespace ROOT::VecOps;
RVec<float> getRawVal(int nJet, RVec<float> val, RVec<float> rawFactor){
    ROOT::VecOps::RVec<Float_t> rawVal = {};
    for (int i = 0; i < nJet; i ++){
        rawVal.push_back( val.at(i) * (1 - rawFactor.at(i) ) );
    }
    return rawVal;
}
