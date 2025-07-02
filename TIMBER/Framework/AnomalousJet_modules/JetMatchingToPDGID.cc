#include "../include/common.h"

// Match jet to gen particle by PDG ID within DeltaR
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
