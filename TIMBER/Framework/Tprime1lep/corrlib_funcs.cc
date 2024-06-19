// Methods in this file:
// pufunc() goldenjson()

// --------------------------------------------------------
// 		    PILE UP FXN
// --------------------------------------------------------
using namespace ROOT::VecOps;
using namespace std;

// Commented Method Only
RVec<double> pufunc(correction::Correction::Ref& pileupcorr, const float &numTrueInt) 
{
  RVec<double> pu = {pileupcorr->evaluate({numTrueInt, "nominal"}), pileupcorr->evaluate({numTrueInt, "up"}), pileupcorr->evaluate({numTrueInt, "down"})};
  return pu;
};

// Make sure the run passes the json? //TODO better explanation
bool goldenjson(lumiMask myLumiMask, const unsigned int &run, const unsigned int &luminosityBlock)
{
  return myLumiMask.accept(run, luminosityBlock);
};  
