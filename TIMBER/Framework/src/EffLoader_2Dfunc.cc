#include "../include/EffLoader_2Dfunc.h"

EffLoader_2Dfunc::EffLoader_2Dfunc(){}

EffLoader_2Dfunc::EffLoader_2Dfunc(std::string filename, std::string funcname, std::string effname) {
    file = TFile::Open(filename.c_str());
    efficiency = (TEfficiency*)file->Get(effname.c_str());
    func = (TF2*)file->Get(funcname.c_str());
    resultPtr = (TFitResultPtr*)file->Get(("TBinomialEfficiencyFitter_result_of_"+funcname).c_str());
}

std::vector<float> EffLoader_2Dfunc::eval(float xval, float yval) {
    // Get nominal value of the efficiency at evaluated point
    effval = func->Eval(xval,yval);
    // Now get the uncertainty at that point
    double ci[1];
    double points[] = {xval,yval};
    int stride1 = 2;
    int stride2 = 1;
    // have to get the underlying TFitResult from the TFitResultPtr before accessing GetConfidenceIntervals(), otherwise compiler breaks
    TFitResult* result = resultPtr->Get();
    result->GetConfidenceIntervals(2, stride1, stride2, points, ci, 0.683, false);
    // Now get the up and down variations on the uncertainty
    effup = effval + ci[0];
    effdown = effval - ci[0];
    return {effval,effup,effdown};
}

