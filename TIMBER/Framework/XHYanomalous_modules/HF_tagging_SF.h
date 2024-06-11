#include <ROOT/RVec.hxx>
#include <TRandom.h>
#include <vector>
using namespace ROOT::VecOps;

class HF_tagging_SF {
    public:
		float _eff;
        float _wp;
        float SFs[3][7];

        HF_tagging_SF(float eff,int year);
        ~HF_tagging_SF(){};
        float getSFValue(float pt, int variation);
        std::vector<float> getWeights(float pt,float pnet);
        std::vector<float> evtWeight(int nFatJet,RVec<float> FatJet_pt, RVec<float> FatJet_particleNetMD_Xbb,RVec<float> FatJet_particleNetMD_QCD);

		//SF[i][j] i denotes nom/down/up, j denotes pt category
		//pt cats: 250-300,300-350, 350-400, 400-450, 450-500, 500-600, 600+
		//https://coli.web.cern.ch/coli/.cms/btv/boohft-calib/20240131_bb_ULNanoV9_PNetXbbVsQCD_ak8_inclWP_extendPtBins_2016/4_fit/
		
		//High purity WP {"2016APV":0.9883,"2016":0.9883,"2017":0.9870,"2018":0.9880}
		float SF2016APV[3][7] = {
                                {1.005, 1.034, 0.999, 1.059, 1.053, 1.131, 1.037},
                                {0.963, 0.973, 0.961, 0.938, 0.975, 1.052, 0.916},
                                {1.050, 1.100, 1.039, 1.129, 1.134, 1.213, 1.164}
                                };
		
        float SF2016[3][7] = {
                            {1.028, 1.009, 1.043, 1.039, 1.016, 1.048, 1.090},
                            {0.955, 0.930, 0.994, 0.993, 0.972, 0.983, 1.013},
                            {1.102, 1.086, 1.093, 1.087, 1.063, 1.116, 1.170}
                            };

        float SF2017[3][7] = {
                            {1.044, 1.061, 1.102, 1.068, 1.049, 1.063, 1.050},
                            {0.948, 0.961, 1.018, 1.012, 0.979, 1.003, 1.005},
                            {1.141, 1.161, 1.186, 1.112, 1.120, 1.125, 1.091}
                            };

        float SF2018[3][7] = {
                            {0.993, 0.995, 1.043, 1.032, 0.997, 1.077, 1.032},
                            {0.918, 0.950, 0.988, 0.975, 0.931, 1.039, 0.983},
                            {1.067, 1.040, 1.095, 1.092, 1.063, 1.115, 1.079}
                            };
};