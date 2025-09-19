// Requires CMSSW
// Following the example from JME found here:
// https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/examples/jercExample.C

#include <correction.h>
#include <ROOT/RVec.hxx>

using ROOT::VecOps::RVec;

class BTagging_correctionlib_weight {
    private:
        std::unique_ptr<correction::CorrectionSet> _cset;
        std::string _key;
        bool _isData;
    public:
        BTagging_correctionlib_weight(std::string fname, std::string key, bool isData);
        ~BTagging_correctionlib_weight(){};
        RVec<float> eval(int flavor, float eta, float pt, float discriminant);
};

BTagging_correctionlib_weight::BTagging_correctionlib_weight(std::string fname, std::string key, bool isData) : _key(key), _isData(isData) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
};

// This implementation avoids using TIMBER's built-in Collection objects, which are difficult to work with and opaque from a developer standpoint
RVec<float> BTagging_correctionlib_weight::eval(int flavor, float eta, float pt, float discriminant) {
    
    RVec<float> out {1.0, 1.0, 1.0};
        // Map the JSON object name to the jet collection variable name

        if (!_isData) { // If running on MC, we want to obtain the SF and uncertainty
            correction::Correction::Ref ref  = _cset->at(_key);

            // Inputs for both SF and uncertainty 
            RVec<string> variations {"central", "up_jes", "down_jes"};
            for(int i = 0; i < 3; i++){
                std::vector<correction::Variable::Type> inputs;
                inputs.push_back(variations.at(i));
                inputs.push_back(flavor);
                inputs.push_back(std::abs(eta));
                inputs.push_back(pt);
                inputs.push_back(discriminant);
                 out[i] = ref->evaluate(inputs);
                
            }

        }
    return out;
};
