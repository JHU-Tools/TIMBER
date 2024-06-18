// Methods in this file:
// pufunc()

// --------------------------------------------------------
// 		    PILE UP FXN
// --------------------------------------------------------
using namespace ROOT::VecOps;
using namespace std;

//  correction::CompoundCorrection::Ref ak4corr;
//  correction::Correction::Ref ak4corrUnc;
//  correction::Correction::Ref ak4ptres;
//  correction::Correction::Ref ak4jer;
  
// Commented Method Only
RVec<double> pufunc(correction::Correction::Ref& pileupcorr, const float &numTrueInt) 
{
  RVec<double> pu = {pileupcorr->evaluate({numTrueInt, "nominal"}), pileupcorr->evaluate({numTrueInt, "up"}), pileupcorr->evaluate({numTrueInt, "down"})};
  return pu;
};    
