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
    public:
        JES_correctionlib_weight(std::string fname, std::string level_key, std::string unc_key);
        ~JES_correctionlib_weight(){};
        RVec<RVec<float>> eval(RVec<float> pt, RVec<float> eta, RVec<float> phi, RVec<float> area, float fixedGridRhoFastjetAll);
};

JES_correctionlib_weight::JES_correctionlib_weight(std::string fname, std::string level_key, std::string unc_key) : _level_key(level_key), _unc_key(unc_key) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
};

// This implementation avoids using TIMBER's built-in Collection objects, which are difficult to work with and opaque from a developer standpoint
RVec<RVec<float>> JES_correctionlib_weight::eval(RVec<float> pt, RVec<float> eta, RVec<float> phi, RVec<float> area, float fixedGridRhoFastjetAll) {
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
            "Rho", fixedGridRhoFastjetAll}
        };
        // Book {nom, up, down} SFs for the jet at index "ijet"
        RVec<float> ijet_out {1.0, 1.0, 1.0};

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
        out[ijet] = ijet_out;

    }
    return out;
};