#ifndef _TIMBER_CORRLIBFUNCS
#define _TIMBER_CORRLIBFUNCS
// Methods in this file:
// pufunc()
#include <iostream> 
// --------------------------------------------------------
// 		    PILE UP FXN
// --------------------------------------------------------
using namespace ROOT::VecOps;
using namespace std;
    
//  correction::CompoundCorrection::Ref ak4corr;
//  correction::Correction::Ref ak4corrUnc;
//  correction::Correction::Ref ak4ptres;
//  correction::Correction::Ref ak4jer;
    
class Corrlib_funcs {
  public:
    // Commented Method Only
    static RVec<double> pufunc(correction::Correction::Ref& pileupcorr, const float &numTrueInt) {
      RVec<double> pu = {pileupcorr->evaluate({numTrueInt, "nominal"}), pileupcorr->evaluate({numTrueInt, "up"}), pileupcorr->evaluate({numTrueInt, "down"})};
      return pu;
    };    
    
};
#endif
