#ifndef _TIMBER_EFFLOADER_2DFUNC
#define _TIMBER_EFFLOADER_2DFUNC
#include <string>
#include "TFile.h"
#include "TEfficiency.h"
#include "TF2.h"
#include "TFitResultPtr.h"
#include "TFitResult.h"

/**
 * Class for handling efficiencies whose uncertainties are being evaluated via a fitted function.
 * A ROOT file containing the TEfficiency, TH2, TF2, and TFitResultPtr from the fit of the TF2 to
 * the TEfficiency must be passed to the class constructor.
 * 	NOTE: fitting a 2D TEfficiency only works in ROOT versions >6.28, so the fitting may have 
 * 	to be done outside of the CMSSW and the TF2 and TFitResultPtr saved to the file externally.
 */ 

class EffLoader_2Dfunc {
    private:
	TFile *file;
	TEfficiency *efficiency;
	TF2 *func;
	TFitResultPtr *resultPtr;
        float effval;
        float effup;
        float effdown;

    public:
	EffLoader_2Dfunc();
	EffLoader_2Dfunc(std::string filename, std::string funcname, std::string effname);
	std::vector<float> eval(float xval, float yval);
};

#endif
