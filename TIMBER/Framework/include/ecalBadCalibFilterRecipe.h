#include <TMath.h>
#include <ROOT/RVec.hxx>
using ROOT::VecOps::RVec;

bool ecalBadCalibFilterRecipe(int run,  float PuppiMET_pt, float PuppiMET_phi,  int nJet, RVec<float> Jet_pt, RVec<float> Jet_eta, RVec<float> Jet_phi, RVec<float> Jet_neEmEF, RVec<float> Jet_chEmEF);

