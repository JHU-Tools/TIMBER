// Requires CMSSW
// Following the example from JME found here:
// https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/examples/jercExample.C

#include <correction.h>
#include <ROOT/RVec.hxx>

using ROOT::VecOps::RVec;

class JES_correctionlib_weight {
    private:
        std::unique_ptr<correction::CorrectionSet> _cset;
        std::string _level_key;
        std::string _unc_key;
        bool _isData;
    public:
        JES_correctionlib_weight(std::string fname, std::string level_key, std::string unc_key, bool isData);
        ~JES_correctionlib_weight(){};
        RVec<RVec<float>> eval(RVec<float> pt, RVec<float> eta, RVec<float> phi, RVec<float> area, float fixedGridRhoFastjetAll, float run);
};

JES_correctionlib_weight::JES_correctionlib_weight(std::string fname, std::string level_key, std::string unc_key, bool isData) : _level_key(level_key), _unc_key(unc_key), _isData(isData) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
};

// This implementation avoids using TIMBER's built-in Collection objects, which are difficult to work with and opaque from a developer standpoint
RVec<RVec<float>> JES_correctionlib_weight::eval(RVec<float> pt, RVec<float> eta, RVec<float> phi, RVec<float> area, float fixedGridRhoFastjetAll, float run) {
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
        RVec<float> ijet_out {1.0, 1.0, 1.0};

        if (!_isData) { // If running on MC, we want to obtain the SF and uncertainty
            // Obtain the SF and uncertainty given this jet's inputs
            correction::CompoundCorrection::Ref ref_sf  = _cset->compound().at(_level_key);
            correction::Correction::Ref         ref_unc = _cset->at(_unc_key);

            // Inputs for both SF and uncertainty 
            std::vector<correction::Variable::Type> inputs_sf;
            std::vector<correction::Variable::Type> inputs_unc;
            float SF;
            float unc;

            // Loop over inputs for both
            for (const correction::Variable& input: ref_sf->inputs()) {
                inputs_sf.push_back(map.at(input.name()));
            }
            for (const correction::Variable& input: ref_unc->inputs()) {
                inputs_unc.push_back(map.at(input.name()));
            }

            // Obtain the final SF and uncertainty for this jet 
            SF = ref_sf->evaluate(inputs_sf);
            unc = ref_unc->evaluate(inputs_unc);

            ijet_out[0] = SF;
            ijet_out[1] = SF * (1. + unc);
            ijet_out[2] = SF * (1. - unc);
        }
        else {  // Otherwise, if running on data we just want the SF correction. Set the up/down elements to 1.0
            correction::CompoundCorrection::Ref ref_sf  = _cset->compound().at(_level_key);
            std::vector<correction::Variable::Type> inputs_sf;
            float SF;
            for (const correction::Variable& input: ref_sf->inputs()) {
                inputs_sf.push_back(map.at(input.name()));
            }
            SF = ref_sf->evaluate(inputs_sf);
            ijet_out[0] = SF;   // leave indices 1,2 as 1.0 (dummy values)
        }
        out[ijet] = ijet_out;

    }
    return out;
};
