#include <correction.h>
#include <ROOT/RVec.hxx>
class JetID_calculator{
public:
    std::unique_ptr<correction::CorrectionSet> _cset;
    correction::Correction::Ref ref_AK4_TLV_PUPPI;
    correction::Correction::Ref ref_AK4_T_PUPPI;
    correction::Correction::Ref ref_AK8_TLV_PUPPI;
    correction::Correction::Ref ref_AK8_T_PUPPI;
    correction::Correction::Ref ref_TLV_PUPPI;
    correction::Correction::Ref ref_T_PUPPI;
    JetID_calculator(std::string json_file, std::string jet_R){
        _cset = correction::CorrectionSet::from_file(json_file.c_str());
        ref_AK4_TLV_PUPPI = _cset->at("AK4PUPPI_TightLeptonVeto");
        ref_AK4_T_PUPPI = _cset->at("AK4PUPPI_Tight");
        ref_AK8_TLV_PUPPI = _cset->at("AK8PUPPI_TightLeptonVeto");
        ref_AK8_T_PUPPI = _cset->at("AK8PUPPI_Tight");
        if (jet_R == "AK4"){
            ref_TLV_PUPPI = ref_AK4_TLV_PUPPI;
            ref_T_PUPPI = ref_AK4_T_PUPPI;
        }
        else if (jet_R == "AK8"){
            ref_TLV_PUPPI = ref_AK8_TLV_PUPPI;
            ref_T_PUPPI = ref_AK8_T_PUPPI;
        }
        else{
            throw std::invalid_argument("Jet_R should be either AH4 or AK8.");
        }
    };
    RVec<unsigned char> eval( int nJet, RVec<float> eta, RVec<float> chHEF, RVec<float> neHEF, RVec<float> chEmEF, RVec<float> neEmEF, RVec<float> muEF, RVec<int> chMultiplicity, RVec<int> neMultiplicity);
};

RVec<unsigned char> JetID_calculator::eval( int nJet, RVec<float> eta, RVec<float> chHEF, RVec<float> neHEF, RVec<float> chEmEF, RVec<float> neEmEF, RVec<float> muEF, RVec<int> chMultiplicity, RVec<int> neMultiplicity){

    //RVec<unsigned char> JetIDs = {};
    RVec<unsigned char> JetIDs = {};
    for(int ijet = 0; ijet < nJet; ijet++){
        std::map<std::string, correction::Variable::Type> map {
            {
            "eta", eta.at(ijet)},
            { 
            "chHEF", chHEF.at(ijet)},
            { 
            "neHEF", neHEF.at(ijet)},
            { 
            "chEmEF", chEmEF.at(ijet)},
            { 
            "neEmEF", neEmEF.at(ijet)},
            { 
            "muEF", muEF.at(ijet)},
            { 
            //"chMultiplicity", chMultiplicity.at(ijet)},
            "chMultiplicity", static_cast<float>(chMultiplicity.at(ijet))},
            {
            //"neMultiplicity", neMultiplicity.at(ijet)},
            "neMultiplicity",  static_cast<float>(neMultiplicity.at(ijet))},
            {
            //"multiplicity", chMultiplicity.at(ijet) + neMultiplicity.at(ijet)}
            "multiplicity",  static_cast<float>(chMultiplicity.at(ijet) + neMultiplicity.at(ijet))}
        };
        std::vector<correction::Variable::Type> inputs_TLV_PUPPI;
        std::vector<correction::Variable::Type> inputs_T_PUPPI;
        for (const correction::Variable& input: ref_TLV_PUPPI->inputs()) {
            inputs_TLV_PUPPI.push_back(map.at(input.name()));
        }
        for (const correction::Variable& input: ref_T_PUPPI->inputs()) {
            inputs_T_PUPPI.push_back(map.at(input.name()));
        }
        float TLV_JetID = ref_TLV_PUPPI->evaluate(inputs_TLV_PUPPI);
        float T_JetID = ref_T_PUPPI->evaluate(inputs_T_PUPPI);
        //unsigned char JetID = static_cast<unsigned char>(std::round(TLV_JetID * 4 + T_JetID * 2));
        unsigned char JetID = static_cast<unsigned char>(std::round(TLV_JetID * 4 + T_JetID * 2));
        
        JetIDs.push_back(JetID);
    }
    return JetIDs;
};
