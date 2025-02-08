// Requires CMSSW

#include <correction.h>
#include <ROOT/RVec.hxx>
#include <Math/GenVector/LorentzVector.h>
#include <Math/GenVector/PtEtaPhiM4D.h>
#include <Math/Vector4Dfwd.h>
#include "../include/common.h"
#include <random>

using ROOT::VecOps::RVec;
using LorentzV = ROOT::Math::PtEtaPhiMVector;

class JER_correctionlib_weight {
    private:
        std::unique_ptr<correction::CorrectionSet> _cset;
        // JSON keys for each of the correction objects
        std::string _key_jes;
        std::string _key_res;
        std::string _key_sf;        
        // Variables for JER correction algorithm
        float _dRMax, _dPtMaxFactor;
        std::mt19937 _rnd;
        static constexpr const double MIN_JET_ENERGY = 1e-2;

    public:
        JER_correctionlib_weight(std::string fname, std::string key_jes, std::string key_res, std::string key_sf, float dRMax, float dPtMaxFactor = 3.);
        ~JER_correctionlib_weight(){};

        /**
         * @brief Perform the actual matching
         * 
         * @param jet Lorentz vector for the reco jet.
         * @param genJets Vector of Lorentz vectors of the gen jets.
         * @param resolution pT resolution to consider.
         * @return LorentzV The gen jet that matches the reco jet.
         */
        LorentzV match(LorentzV& jet, RVec<LorentzV> genJets, float resolution);


        /**
         * @brief Main function called by JER correction class.
         *
         * @param jets TIMBER-created structure for the jet collection (AK4/AK8). Can be a custom collection name
         * @param genJets TIMBER-created structure for the generator jet collection. By default, this is automatically created in TIMBER as "GenJet"
         * @param fixedGridRhoFastjetAll NanoAOD column of the same name storing the density rho
         */
        template <class Tjet, class TgenJet>
        RVec<RVec<float>> eval(std::vector<Tjet> jets, std::vector<TgenJet> genJets, float fixedGridRhoFastjetAll){
            RVec< RVec<float> > out (jets.size());
            for (size_t ijet = 0; ijet < jets.size(); ijet++) {
                // Book {nom, up, down} SFs for the jet at index "ijet"
                RVec<float> ijet_out {1.0, 1.0, 1.0};
                
                // Get the resolution for this jet given its eta, pt, and event rho
                float res;
                std::map<std::string, correction::Variable::Type> resMap {
                    {"JetPt", jets[ijet].pt},
                    {"JetEta", jets[ijet].eta},
                    {"Rho", fixedGridRhoFastjetAll}
                };
                correction::Correction::Ref ref_res = _cset->at(_key_res);
                std::vector<correction::Variable::Type> inputs_res;
                for (const correction::Variable& input : ref_res->inputs()) {
                    inputs_res.push_back(resMap.at(input.name()));
                }
                res = ref_res->evaluate(inputs_res);

                // Now attempt to match the RECO jet to a GEN jet
                LorentzV reco_jet = hardware::TLvector(jets[ijet]);
                LorentzV genJet = match(reco_jet, hardware::TLvector(genJets), jets[ijet].pt * res);

                // Now begin a loop over the variations {0: "nom", 1: "up", 2: "down"}
                float smearFactor, dpT, sigma, jet_sf;
                for (size_t i=0; i<3; i++) {
                    // Determine the variation
                    std::string variation;
                    if (i == 0) {
                        variation = "nom";
                    }
                    else if (i == 1) {
                        variation = "up";
                    }
                    else {
                        variation = "down";
                    }
                    // Get the JER scale factor
                    float jet_sf;
                    std::map<std::string, correction::Variable::Type> sfMap {
                        {"JetEta", jets[ijet].eta},
                        {"systematic", variation}
                    };
                    correction::Correction::Ref ref_sf = _cset->at(_key_sf);
                    std::vector<correction::Variable::Type> inputs_sf;
                    for (const correction::Variable& input : ref_sf->inputs()) {
                        inputs_sf.push_back(sfMap.at(input.name()));
                    }
                    jet_sf = ref_sf->evaluate(inputs_sf);

                    // Now determine how to handle the various cases.
                    //      Case 1: we have a "good" gen jet matched to the reco jet.
                    //      Case 2: we don't have a gen jet. Smear jet pt using a random gaussian variation.
                    if (genJet.Pt() > -1) {
                        dpT = reco_jet.Pt() - genJet.Pt();
                        smearFactor = 1. + (jet_sf -1.) * dpT / reco_jet.Pt();
                    }
                    else if (jet_sf > 1) {
                        std::normal_distribution<> d(0, res);
                        smearFactor = 1. + d(_rnd) * std::sqrt(jet_sf * jet_sf - 1.);
                    }
                    else {
                        smearFactor = 1.;
                    }

                    if (reco_jet.E() * smearFactor < MIN_JET_ENERGY) {
                        // Negative or too small smearFactor. We would change direction of the jet
                        // and this is not what we want.
                        // Recompute the smearing factor in order to have jet.energy() == MIN_JET_ENERGY
                        smearFactor = MIN_JET_ENERGY / reco_jet.E();
                    }

                    ijet_out[i] = smearFactor;

                } // end loop over variations
                // Return {nom,up,down} values for the jet at index "ijet"
                out[ijet] = ijet_out;
            }
            return out;
        }
};

JER_correctionlib_weight::JER_correctionlib_weight(std::string fname, std::string key_jes, std::string key_res, std::string key_sf, float dRMax, float dPtMaxFactor = 3.) : _dRMax(dRMax), _dPtMaxFactor(dPtMaxFactor), _key_jes(key_jes), _key_res(key_res), _key_sf(key_sf) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
}

LorentzV JER_correctionlib_weight::match(LorentzV& jet, RVec<LorentzV> genJets, float resolution) {
    // Match if dR < _dRMax and dPt < dPtMaxFactor
    double min_dR = std::numeric_limits<double>::infinity();
    LorentzV out (-1,0,0,0);

    for (const LorentzV & genJet : genJets) {
        float dR = hardware::DeltaR(genJet, jet);
        if (dR > min_dR) {
            continue;
        }
        if (dR < _dRMax) {
            double dPt = std::abs(genJet.pt() - jet.pt());
            if ((resolution == -1) || (dPt <= _dPtMaxFactor * resolution)) {
                min_dR = dR;
                out = genJet;
            }
        }
    }
    return out;
}