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

// What is MET? it returns the corrections for met's transverse momentum and phi angle. 
RVec<float> metfunc(correction::Correction::Ref& metptcorr, correction::Correction::Ref& metphicorr, 
                    const float &met, const float &phi, const int &npvs, const unsigned int &run)
//assigned types as per BtoTW git analyzer_RDF.cc
{
   float floatrun = run;
   float floatnpvs = npvs;
   float tmpmet = met;
      if(tmpmet > 6500) tmpmet = 6499;
         RVec<float> corrmet = {static_cast<float>(metptcorr->evaluate({tmpmet, phi, floatnpvs, floatrun})),
                              static_cast<float>(metphicorr->evaluate({tmpmet, phi, floatnpvs, floatrun}))};
  return corrmet;
};

// IDK what this function does. What's HLT? seems to be calling a bunch of variables under HLT 
// (electrons? and a muon correction)
RVec<double> hltfunc(correction::Correction::Ref& muonhltcorr, vector<float> &elhlt_pts,
                     vector<float> &elhlt_etas, vector<vector<float>> &elechltsfs, vector<vector<float>> &elechltuncs,
                     <string> &yrstr, const float &pt, const float &eta, const bool &isEl)
// I assumed hltfunc is a double type vector because of the definition of its return value below.
{
    RVec<double> hlt;
    if(isEl > 0){
      int ptbin = (std::upper_bound(elhlt_pts.begin(), elhlt_pts.end(), pt) - elhlt_pts.begin())-1;
      int etabin = (std::upper_bound(elhlt_etas.begin(), elhlt_etas.end(), 
	            abs(eta)) - elhlt_etas.begin())-1;
      hlt = {elechltsfs[ptbin][etabin], elechltuncs[ptbin][etabin]};  
    }
    else {
      hlt = {muonhltcorr->evaluate({yrstr+"_UL",abs(eta),pt,"sf"}), 
	     muonhltcorr->evaluate({yrstr+"_UL",abs(eta),pt,"systup"}), 
	     muonhltcorr->evaluate({yrstr+"_UL",abs(eta),pt,"systdown"})};
    }
    return hlt;
 }; 


