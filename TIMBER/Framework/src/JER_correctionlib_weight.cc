// Requires CMSSW
#ifndef JER_CORR
#define JER_CORR
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
        std::string _key_res;
        std::string _key_sf;
        std::string _fname;        
        // Variables for JER correction algorithm
        float _dRMax, _dPtMaxFactor;
        std::mt19937 _rnd;
        //static constexpr const double MIN_JET_ENERGY = 1e-2;
        // Variables to keep track of GEN matching info
        float _total = 0.;
        float _matched = 0.; 

    public:
        JER_correctionlib_weight(std::string fname, std::string key_res, std::string key_sf, float dRMax, float dPtMaxFactor = 3.);
        ~JER_correctionlib_weight();

        /**
         * @brief Perform the actual matching
         * 
         * @param jet Lorentz vector for the reco jet.
         * @param genJets Vector of Lorentz vectors of the gen jets.
         * @param resolution pT resolution to consider.
         * @return LorentzV The gen jet that matches the reco jet.
         */
        float match( float pt, float eta, float phi, int nGenJet, RVec<float> genJet_pt, RVec<float> genJet_eta, RVec<float> genJet_phi, float resolution);

        RVec<RVec<float>> eval(int nJet, RVec<float> jet_pt, RVec<float> jet_eta, RVec<float> jet_phi, int nGenJet, RVec<float> genJet_pt, RVec<float> genJet_eta, RVec<float> genJet_phi, float fixedGridRhoFastjetAll);
};

JER_correctionlib_weight::JER_correctionlib_weight(std::string fname, std::string key_res, std::string key_sf, float dRMax, float dPtMaxFactor) : _dRMax(dRMax), _dPtMaxFactor(dPtMaxFactor), _key_res(key_res), _key_sf(key_sf), _fname(fname) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
}

JER_correctionlib_weight::~JER_correctionlib_weight() {
    // NOTE: The matching efficiency will only be calculated and displayed if the RDF event loop is triggered.
    //       If only lazy actions are performed on the RDF, then the function that increments these values will
    //       not be triggered. If you see -nan% and did not trigger the RDF event loop, don't be alarmed!!
    float fraction = _matched/_total * 100.;
    std::cout << "[JER_correctionlib_weight] Gen matching efficiency = " << fraction << "%" << std::endl;
    std::cout << "\tTEST"<<_fname << std::endl;
    std::cout << "\tTotal number of RECO jets matched to a GEN jet: " << _matched << std::endl;
    std::cout << "\tTotal number of RECO jets analyzed:             " << _total << std::endl;
}


RVec<RVec<float>> JER_correctionlib_weight::eval(int nJet, RVec<float> jet_pt, RVec<float> jet_eta, RVec<float> jet_phi, int nGenJet, RVec<float> genJet_pt, RVec<float> genJet_eta, RVec<float> genJet_phi, float fixedGridRhoFastjetAll){
    RVec< RVec<float> > out (nJet);
    for (size_t ijet = 0; ijet < nJet; ijet++) {
        // Book {nom, up, down} SFs for the jet at index "ijet"
        RVec<float> ijet_out {1.0, 1.0, 1.0};
        
        // Get the resolution for this jet given its eta, pt, and event rho
        float res;
        std::map<std::string, correction::Variable::Type> resMap {
            {"JetPt", jet_pt[ijet]},
            {"JetEta", jet_eta[ijet]},
            {"Rho", fixedGridRhoFastjetAll}
        };
        correction::Correction::Ref ref_res = _cset->at(_key_res);
        std::vector<correction::Variable::Type> inputs_res;
        for (const correction::Variable& input : ref_res->inputs()) {
            inputs_res.push_back(resMap.at(input.name()));
        }
        res = ref_res->evaluate(inputs_res);

        // Now attempt to match the RECO jet to a GEN jet
        float genPt = match(jet_pt[ijet], jet_eta[ijet], jet_phi[ijet], nGenJet, genJet_pt, genJet_eta, genJet_phi, jet_pt[ijet] * res);

        // Keep track of the number of total and matched jets to print upon object destruction
        _total++;
        if (genPt >= 0) {_matched++;}
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
                {"JetEta", jet_eta[ijet]},
                 {"JetPt", jet_pt[ijet]},
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
            if (genPt >= 0) { // Case 1
                dpT = jet_pt.at(ijet) - genPt;
                smearFactor = 1. + (jet_sf -1.) * dpT / jet_pt.at(ijet);
            }
            else if (jet_sf > 1) {  // Case 2
                std::normal_distribution<> d(0, res);
                smearFactor = 1. + d(_rnd) * std::sqrt(jet_sf * jet_sf - 1.);
            }
            else {
                smearFactor = 1.;
            }
            smearFactor = smearFactor < 0 ? 0 : smearFactor;

            ijet_out[i] = smearFactor;

        } // end loop over variations
        // Return {nom,up,down} values for the jet at index "ijet"
        out[ijet] = ijet_out;
    }
    return out;
}

float JER_correctionlib_weight::match( float pt, float eta, float phi, int nGenJet, RVec<float> genJet_pt, RVec<float> genJet_eta, RVec<float> genJet_phi, float resolution) {
    double min_dR = std::numeric_limits<double>::infinity();
    // Match if dR < _dRMax and dPt < dPtMaxFactor
    float out_pt = -1.;
    for (int i = 0; i < nGenJet; i ++){
        float deltaEta = std::abs(eta - genJet_eta.at(i));
        float deltaPhi = std::abs(phi - genJet_phi.at(i)) < M_PI ? std::abs(phi - genJet_phi.at(i)) : 2*M_PI - std::abs(phi - genJet_phi.at(i));
        float dR = sqrt(deltaEta * deltaEta + deltaPhi * deltaPhi);
        if (dR > min_dR) {
            continue;
        }
        if (dR < _dRMax) {
            double dPt = std::abs(pt - genJet_pt.at(i));
            if ((resolution == -1) || (dPt <= _dPtMaxFactor * resolution)) {
                min_dR = dR;
                out_pt = genJet_pt.at(i);
            }
        }
    }
    return out_pt;
}





#endif
