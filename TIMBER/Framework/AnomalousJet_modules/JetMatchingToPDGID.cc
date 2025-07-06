#include "../include/common.h"
#include "ROOT/RVec.hxx"

using namespace ROOT::VecOps; //RVec

// Match jet to gen particle by PDG ID within DeltaR
//Returns 1 if GenPart with ID is within DeltaR of the jet, 0 otherwise
int JetMatchingToPDGID(
    RVec<int> GenPart_pdgId, 
    RVec<int> GenPart_statusFlags, 
    RVec<ROOT::Math::PtEtaPhiMVector> GenPart_vect, 
    ROOT::Math::PtEtaPhiMVector jet, 
    int ID, 
    float R)
{
    for (size_t i = 0; i < GenPart_pdgId.size(); i++) {
        if (GenPart_statusFlags[i] & (1 << 13)) { // isLastCopy
            if (GenPart_pdgId[i] == ID) {
                if (hardware::DeltaR(GenPart_vect[i], jet) < R) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


// Go through FatJetPFCand collection, return pfCand indices for which FatJetPFCand_pfCandIdx matches jet index
RVec<int> GetPFCandIndicesForJet(
    const RVec<int>& FatJetPFCands_jetIdx, 
    const RVec<int>& FatJetPFCands_pFCandsIdx, 
    int jetIdx,
    int nFatJetPFCands)
{   
    RVec<int> result_indices;
    for (size_t i = 0; i < nFatJetPFCands; ++i) {
        if (FatJetPFCands_jetIdx[i] != jetIdx)
            continue;
        result_indices.push_back(FatJetPFCands_pFCandsIdx[i]);
    }
    return result_indices;
}


RVec<float> GetNeuronVectorByIndex(
    const RVec<RVec<float>>& all_neurons, 
    int index)
{
    if (index < 0 || index >= (int)all_neurons.size()) return {};
    return all_neurons[index];
}