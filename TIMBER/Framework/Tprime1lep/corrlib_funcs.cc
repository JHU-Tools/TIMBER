// Methods in this file:
// goldenjson() pufunc() recofunc() idfunc() 

// --------------------------------------------------------
// 		    PILE UP FXN
// --------------------------------------------------------
#include <stdexcept>

using namespace ROOT::VecOps;
using namespace std;

// Commented Method Only

// Make sure the run passes the json? //TODO better explanation
/*bool goldenjson(lumiMask myLumiMask, const unsigned int &run, const unsigned int &luminosityBlock)
{
  return myLumiMask.accept(run, luminosityBlock);
};*/ 

// Pile Up Function
RVec<double> pufunc(correction::Correction::Ref& pileupcorr, const float &numTrueInt) 
{
  RVec<double> pu = {pileupcorr->evaluate({numTrueInt, "nominal"}), pileupcorr->evaluate({numTrueInt, "up"}), pileupcorr->evaluate({numTrueInt, "down"})};
  return pu;
};

// Reconstruct the lepton?
RVec<double> recofunc(correction::Correction::Ref& electroncorr, correction::Correction::Ref& muoncorr, string yrstr, const float &pt, const float &eta, const bool &isEl)
{
  RVec<double> reco;
  if(isEl == 0) { 
    reco = {muoncorr->evaluate({yrstr+"_UL",abs(eta),pt,"sf"}), 
      muoncorr->evaluate({yrstr+"_UL",abs(eta),pt,"systup"}), 
      muoncorr->evaluate({yrstr+"_UL",abs(eta),pt,"systdown"})};
  }else{
    reco = {electroncorr->evaluate({yrstr,"sf","RecoAbove20",eta,pt}), 
      electroncorr->evaluate({yrstr,"sfup","RecoAbove20",eta,pt}), 
      electroncorr->evaluate({yrstr,"sfdown","RecoAbove20",eta,pt})};
  }
  return reco;
}; 

// Get the ID of leptons?
RVec<float> idfunc(correction::Correction::Ref& muonidcorr, vector<float> &elid_pts, vector<float> &elid_etas, vector<vector<float>> &elecidsfs, vector<vector<float>> &elecidsfuncs, string &yrstr, const float &pt, const float &eta, const bool &isEl)
{
  RVec<float> id;
  if(isEl > 0){
    int ptbin = (std::upper_bound(elid_pts.begin(), elid_pts.end(), pt) - elid_pts.begin())-1;
    int etabin = (std::upper_bound(elid_etas.begin(), elid_etas.end(), eta) - elid_etas.begin())-1;
    
    id = {elecidsfs[ptbin][etabin], elecidsfuncs[ptbin][etabin]}; //PTL
     
  }else{  
    id = {static_cast<float>(muonidcorr->evaluate({yrstr+"_UL",abs(eta),pt,"sf"})), 
      static_cast<float>(muonidcorr->evaluate({yrstr+"_UL",abs(eta),pt,"systup"})), 
      static_cast<float>(muonidcorr->evaluate({yrstr+"_UL",abs(eta),pt,"systdown"}))};
  }
  return id;
}; 

