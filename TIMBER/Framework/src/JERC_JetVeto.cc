// Requires CMSSW
/**
 * Class to handle the treatment of jet veto maps for Run 3 analyses.
 * Following the JERC guidelines here: https://cms-jerc.web.cern.ch/Recommendations/#jet-veto-maps 
 * These jet vetos are required for Run 3, and required for Run 2 only if performing a precision measurement with jets.
 * The safest procedure would be to veto events if ANY jet with a loose selection lies in the veto regions.
 * The nominal “loose selection” would be:
 *      jet pT > 15 GeV
 *      tight jet ID
 *      jet EM fraction (charged + neutral) < 0.9
 *      jets that don’t overlap with PF muon (dR < 0.2)        [NOT SURE HOW TO OBTAIN PF MUON IN NANOAOD]
 * 
 * The correctionlib CorrectionSet that handles the veto maps returns a nonzero value
 * if the region is vetoed. This class first checks that the jet passes the "loose selection"
 * and, if so, then checks the jet's (eta, phi) to see if it lies within the vetoed region.
 * If so, then the entire event should be vetoed and the class will return 1 for the event.
 * The analyzer should then make a TIMBER cut to remove these vetoed events, e.g.
 *  ###### CASE 1: want to run over all jets in the event ##############################
 *      CompileCpp('JERC_JetVeto vetoer = JERC_JetVeto(args);')
 *      a.Define('vetoed_events','vetoer.eval(args)')
 *      a.Cut('JERC_jet_veto','vetoed_events == 1')
 *
 */

#include <correction.h>
#include <ROOT/RVec.hxx>

using ROOT::VecOps::RVec;

class JERC_JetVeto {
    private:
        std::unique_ptr<correction::CorrectionSet> _cset;
        std::string _key;
        float _total;
        float _vetoed;
    public:
        JERC_JetVeto(std::string fname, std::string key);
        ~JERC_JetVeto();

        /**
         * @brief Loop over all (AK4) jets in the event, returning 1 if the event should be vetoed.
         *
         * @param jets TIMBER-created structure for the AK4 jet collection
         */
        template <class T>
        int eval(std::vector<T> jets) {
            int veto = 0;   // Start out assuming we don't veto the event
            _total++;       // Increment the number of events studied
            for (size_t ijet = 0; ijet < jets.size(); ijet++) {
                // First check whether we the jet passes the nominal "loose selection"
                bool jet_passes = (jets[ijet].pt > 15) && (jets[ijet].jetId == 6) && ((jets[ijet].chEmEF + jets[ijet].neEmEF) < 0.9);
                if (jet_passes) {   // Consult jet veto map
                    float veto;
                    std::map<std::string, correction::Variable::Type> map {
                        {"type", "jetvetomap"},  // name of the type of veto map. The recommended map for analyses is 'jetvetomap'. Other possible values: jetvetomap, jetvetomap_all, jetvetomap_hbp2m1, jetvetomap_hem1516, jetvetomap_hot
                        {"eta", jets[ijet].eta},
                        {"phi", jets[ijet].phi}
                    };
                    correction::Correction::Ref ref = _cset->at(_key);
                    std::vector<correction::Variable::Type> inputs;
                    for (const correction::Variable& input : ref->inputs()) {
                        inputs.push_back(map.at(input.name()));
                    }
                    veto = ref->evaluate(inputs);
                    if (veto) {
                        _vetoed++;
                        return 1;
                    }
                }
            }
            return veto;    // Return 0 if no vetoed jet found
        };
};

JERC_JetVeto::JERC_JetVeto(std::string fname, std::string key) : _key(key) {
    _cset = correction::CorrectionSet::from_file(fname.c_str());
};

JERC_JetVeto::~JERC_JetVeto() {
    // NOTE: The number of vetoed events will only be calculated and displayed if the RDF event loop is triggered.
    //       If only lazy actions are performed on the RDF, then the function that increments these values will
    //       not be triggered. If you see -nan% and did not trigger the RDF event loop, don't be alarmed!!
    float fraction = _vetoed/_total * 100;
    std::cout << "[JERC_JetVeto] Fraction of events vetoed using jet veto maps and nominal jet selection = " << fraction << "%" << std::endl;
    std::cout << "\tTotal number of events analyzed: " << _total << std::endl;
    std::cout << "\tTotal number of events vetoed:   " << _vetoed << std::endl;
}