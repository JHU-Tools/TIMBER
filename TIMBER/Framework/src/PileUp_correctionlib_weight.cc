// Requires CMSSW
// Following the example from JME found here:
// https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/examples/jercExample.C

#include <correction.h>
#include <ROOT/RVec.hxx>

using ROOT::VecOps::RVec;

class PileUp_correctionlib_weight {
    private:
        std::unique_ptr<correction::CorrectionSet> _cset;
        std::string _key;
        bool _isData;
    public:
        PileUp_correctionlib_weight(std::string fname, std::string key, bool isData);
        ~PileUp_correctionlib_weight(){};
        RVec<float> eval(float Pileup_nTrueInt);
};

PileUp_correctionlib_weight::PileUp_correctionlib_weight(std::string fname, std::string key, bool isData) : _key(key), _isData(isData) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
};

// This implementation avoids using TIMBER's built-in Collection objects, which are difficult to work with and opaque from a developer standpoint
RVec<float> PileUp_correctionlib_weight::eval(float Pileup_nTrueInt) {
    RVec<float> out {1.0, 1.0, 1.0};
        // Map the JSON object name to the jet collection variable name

        if (!_isData) { // If running on MC, we want to obtain the SF and uncertainty
            correction::Correction::Ref ref  = _cset->at(_key);

            // Inputs for both SF and uncertainty 
            RVec<string> variations {"nominal", "up", "down"};
            for(int i = 0; i < 3; i++){
                std::vector<correction::Variable::Type> inputs;
                inputs.push_back(Pileup_nTrueInt);
                inputs.push_back(variations.at(i));
                out[i] = ref->evaluate(inputs);
            }

        }
    return out;
};
