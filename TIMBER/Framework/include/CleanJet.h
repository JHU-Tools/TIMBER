#ifndef _TIMBER_CLEANJET
#define _TIMBER_CLEANJET
// Methods in this file:
// assign_leps(C), cleanJets()
#include <iostream> 
// --------------------------------------------------------
// 		    JET CLEANING FXN
// --------------------------------------------------------
using namespace ROOT::VecOps;
using namespace std;
    
//  correction::CompoundCorrection::Ref ak4corr;
//  correction::Correction::Ref ak4corrUnc;
//  correction::Correction::Ref ak4ptres;
//  correction::Correction::Ref ak4jer;
    
class CleanJet {
  public:
    // Commented Method Only
        
    // ---- Assign Leptons Function ----
    static RVec<float> assign_leps(bool isMu, bool isEl, RVec<int> &TPassMu, RVec<int> &TPassEl, RVec<float> &Muon_pt, RVec<float> &Muon_eta, RVec<float> &Muon_phi, RVec<float> &Muon_mass, RVec<float> &Muon_miniPFRelIso_all, RVec<float> &Electron_pt, RVec<float> &Electron_eta, RVec<float> &Electron_phi, RVec<float> &Electron_mass, RVec<float> &Electron_miniPFRelIso_all)
    {
    
      float lep_pt = -9;
      float lep_eta = -9;
      float lep_phi = -9; 
      float lep_mass = -9;
      float lep_miniIso = -9;
    
      if(isMu){
        for(unsigned int imu=0; imu < Muon_pt.size(); imu++) {
          if(TPassMu.at(imu) == 1){
    	      if (lep_pt > -1) cout << "Problem: found two muons with TPassMu = 1" << endl;
    		    lep_pt = Muon_pt.at(imu);
    		    lep_eta = Muon_eta.at(imu);
    		    lep_phi = Muon_phi.at(imu);
    	      lep_mass = Muon_mass.at(imu);
    	      lep_miniIso = Muon_miniPFRelIso_all.at(imu);
          }
        }
      }else if(isEl){
        for(unsigned int iel=0; iel < Electron_pt.size(); iel++) {
          if(TPassEl.at(iel) == 1){
    	      if (lep_pt > -1) cout << "Problem: found two electrons with TPassEl = 1" << endl;
    	      lep_pt = Electron_pt.at(iel);
    	      lep_eta = Electron_eta.at(iel);
    	      lep_phi = Electron_phi.at(iel);
    	      lep_mass = Electron_mass.at(iel);
    	      lep_miniIso = Electron_miniPFRelIso_all.at(iel);
          }
        }
      }
      
      RVec<float> lepVec = {lep_pt,lep_eta,lep_phi,lep_mass,lep_miniIso};
      return lepVec;
    };
        
    // ---- Clean Jets Function ----
    static RVec<RVec<float>> cleanJets(RVec<TLorentzVector> &jt_p4, RVec<float> &jt_rf, RVec<TLorentzVector> &mu_p4, RVec<int> mu_jetid, RVec<TLorentzVector> &el_p4, RVec<int> &el_jetid)
    {
      // This one is intended to read in jets that have NOT been filtered yet, for connection with JetIdx
      // No filtering will happen and no reordering will happen, just sending back new 4-vec and raw factor
      RVec<float> cleanJetPt;
      RVec<float> cleanJetEta;
      RVec<float> cleanJetPhi;
      RVec<float> cleanJetMass;
    
      for (unsigned int imu = 0; imu < mu_p4.size(); imu++)
      {
    
        if (mu_jetid[imu] == -1)
          continue; // no matched jet for this muon
    
        // first correct jet by its rawfactor
        TLorentzVector newJet = jt_p4[mu_jetid[imu]] - mu_p4[imu]; // subtract muon
        // then correctionLib needs to now go here to correct this jet
        float newraw = jt_rf[mu_jetid[imu]]; // dummy, FIXME
    
        jt_p4[mu_jetid[imu]] = newJet; // overwrite the old jet
        jt_rf[mu_jetid[imu]] = newraw; // overwrite the old correction factor
      }
    
      for (unsigned int iel = 0; iel < el_p4.size(); iel++)
      {
    
        if (el_jetid[iel] == -1)
          continue; // no matched jet for this electron
    
        // first correct jet by its rawfactor
        TLorentzVector newJet = jt_p4[el_jetid[iel]] - el_p4[iel]; // subtract electron
        // then correctionLib needs to now go here to correct this jet
        float newraw = jt_rf[el_jetid[iel]]; // dummy, FIXME
    
        jt_p4[el_jetid[iel]] = newJet; // overwrite the old jet
        jt_rf[el_jetid[iel]] = newraw; // overwrite the old correction factor
      }
    
      for (unsigned int ijet = 0; ijet < jt_p4.size(); ijet++)
      {
        cleanJetPt.push_back(jt_p4[ijet].Pt());
        cleanJetEta.push_back(jt_p4[ijet].Eta());
        cleanJetPhi.push_back(jt_p4[ijet].Phi());
        cleanJetMass.push_back(jt_p4[ijet].M());
      }
    
      RVec<RVec<float>> output;
      
      output.push_back(cleanJetPt);
      output.push_back(cleanJetEta);
      output.push_back(cleanJetPhi);
      output.push_back(cleanJetMass);
      output.push_back(jt_rf);
      
      return output;
    
      // the "2D cut variables"
      //   dR[i] = DeltaR(jt_eta[i],lep_eta,jt_phi[i],lep_phi);
      //   pt_rel[i] =
    
      //   isClean = true;
      //   if(dR[i] < dR_LIM && pt_rel[i] < 25){isClean = false;}
      //   if(isClean == false){continue;}
      //   if(isClean == true){cleanJets_[i] = 1;}
      // }
      // return cleanJets_;
    
      // FIXME: this is just the 2D cut. Try Electron/Muon/Jet_cleanmask, try Electron/Muon_jetidx, try Electron/Muon_jetPtRelv2,
      // Can I implement the adjustment and re-JEC of jets?
      // Better to just add it to CRAB job when getting the JEC unc?
      // Leptonic W events...this should be fine
      // Leptonic t events...is the ptRel enough to keep a b-jet?
    };
};
#endif
