// Requires CMSSW
// Following the example from JME found here:
// https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/examples/jercExample.C
#ifndef JES_CORR
#define JES_CORR
#include <correction.h>
#include <ROOT/RVec.hxx>

using ROOT::VecOps::RVec;

class JES_correctionlib_multiSyst_weight {
    private:
        std::unique_ptr<correction::CorrectionSet> _cset;
        std::string _level_key;
        std::string _unc_keys;
        bool _isData;
    public:
        JES_correctionlib_multiSyst_weight(std::string fname, std::string level_key, std::string unc_keys, bool isData);
        ~JES_correctionlib_multiSyst_weight(){};
        RVec<RVec<float>> eval(RVec<float> pt, RVec<float> eta, RVec<float> phi, RVec<float> area, float fixedGridRhoFastjetAll, float run);
};

JES_correctionlib_multiSyst_weight::JES_correctionlib_multiSyst_weight(std::string fname, std::string level_key, std::string unc_keys, bool isData) : _level_key(level_key), _unc_keys(unc_keys), _isData(isData) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
};

// This implementation avoids using TIMBER's built-in Collection objects, which are difficult to work with and opaque from a developer standpoint
RVec<RVec<float>> JES_correctionlib_multiSyst_weight::eval(RVec<float> pt, RVec<float> eta, RVec<float> phi, RVec<float> area, float fixedGridRhoFastjetAll, float run) {
    RVec<RVec<float>> out (pt.size());
    for (size_t ijet = 0; ijet < pt.size(); ijet++) {
        // Map the JSON object name to the jet collection variable name
        std::map<std::string, correction::Variable::Type> map {
            { // jet transverse momentum
            "JetPt", pt[ijet]},
            { // jet pseudorapidity
            "JetEta", eta[ijet]},
            { // jet azimuthal angle
            "JetPhi", phi[ijet]},
            { // jet area
            "JetA", area[ijet]},
            { // median energy density (pileup)
            "Rho", fixedGridRhoFastjetAll},
            { // run number
            "run", run}
        };
        // Book {nom, up, down} SFs for the jet at index "ijet"
        RVec<float> ijet_out {1.0};

        if (!_isData) { // If running on MC, we want to obtain the SF and uncertainty
            // Obtain the SF and uncertainty given this jet's inputs
            correction::CompoundCorrection::Ref ref_sf  = _cset->compound().at(_level_key);

            // Inputs for both SF and uncertainty 
            std::vector<correction::Variable::Type> inputs_sf;
            float SF;
            float unc;

            // Loop over inputs for both
            for (const correction::Variable& input: ref_sf->inputs()) {
                inputs_sf.push_back(map.at(input.name()));
            }

            // Obtain the final SF and uncertainty for this jet 
            SF = ref_sf->evaluate(inputs_sf);

            std::vector<std::string> _unc_keys_split = {};
            std::string part;
            std::stringstream ss(_unc_keys);
            while (std::getline(ss, part, ',')) {
                _unc_keys_split.push_back(part);
            }
            
            ijet_out[0] = SF;
            for (auto _unc_key:_unc_keys_split){
                std::vector<correction::Variable::Type> inputs_unc;
                correction::Correction::Ref         ref_unc = _cset->at(_unc_key);
                for (const correction::Variable& input: ref_unc->inputs()) {
                    inputs_unc.push_back(map.at(input.name()));
                }
                unc = ref_unc->evaluate(inputs_unc);

                ijet_out.push_back(SF * (1. + unc));
                ijet_out.push_back(SF * (1. - unc));
            }
        
        }
        else {  
            throw std::runtime_error("Don't use this model on data.");            
        }
        out[ijet] = ijet_out;

    }
    return out;
};

#endif
