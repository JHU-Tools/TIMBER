from TIMBER.Analyzer import *
from TIMBER.Tools.Common import *

import ROOT
from ROOT import TFile
import sys, os

from TIMBER.Tools.RestFramesHandler import load_restframes

# From https://gist.github.com/pieterdavid/a560e65658386d70a1720cb5afe4d3e9#file-df-py  example
import correctionlib
correctionlib.register_pyroot_binding()

sys.path.append('../../')
sys.path.append('../../../')

num_threads = 1
file_name = 'root://cmsxrootd.fnal.gov//store/mc/RunIISummer20UL18NanoAODv9/TprimeTprime_M-1500_TuneCP5_13TeV-madgraph-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/40000/447AD74F-034B-FA42-AD05-CD476A98C43D.root'

# Import the C++
CompileCpp('TIMBER/Framework/include/common.h') # Compile (via gInterpreter) commonly used c++ code
CompileCpp('TIMBER/Framework/Tprime1lep/cleanjet.cc') # Compile Our vlq c++ code
CompileCpp('TIMBER/Framework/Tprime1lep/utilities.cc') # Compile Our vlq c++ code
CompileCpp('TIMBER/Framework/Tprime1lep/corrlib_funcs.cc') 

handler_name = 'Tprime_handler.cc'
class_name = 'Tprime_RestFrames_Container'

# Enable using 4 threads
ROOT.ROOT.EnableImplicitMT(num_threads)

# load rest frames handler
load_restframes(num_threads, handler_name, class_name, 'rfc')

# Create analyzer instance
a = analyzer(file_name)

print('==========================INITIALIZED ANALYZER========================')

# Get correctionsLib
ROOT.gInterpreter.Declare("""
string yrstr = "2018"; 
string yr = "18"; 
auto csetPU = correction::CorrectionSet::from_file("jsonpog-integration/POG/LUM/"+yrstr+"_UL/puWeights.json");
auto corrPU = csetPU->at("Collisions"+yr+"_UltraLegacy_goldenJSON");
""")

# Golden JSON Data
a.Define("PileupWeights", "pufunc(corrPU, Pileup_nTrueInt)")

# ------------------ MET Cuts ------------------
metCuts = CutGroup('METCuts')
metCuts.Add('MET Filters', 'Flag_EcalDeadCellTriggerPrimitiveFilter == 1 && Flag_goodVertices == 1 && Flag_HBHENoiseFilter == 1 && Flag_HBHENoiseIsoFilter == 1 && Flag_eeBadScFilter == 1 && Flag_globalSuperTightHalo2016Filter == 1 && Flag_BadPFMuonFilter == 1 && Flag_ecalBadCalibFilter == 1')
metCuts.Add('Pass MET > 50', 'MET_pt > 50')
metCuts.Add('Event has jets',        'nJet > 0 && nFatJet > 0') # need jets 

# ------------------ Letpon Cuts ------------------
lVars = VarGroup('LeptonVars')
lVars.Add("TightMu", "abs(Muon_eta) < 2.4 && Muon_tightId == true && Muon_miniIsoId >= 3 && Muon_pt > 30")
lVars.Add("TightEl", "abs(Electron_eta) < 2.5 && Electron_mvaFall17V2noIso_WP90 == true && Electron_miniPFRelIso_all < 0.1 && Electron_pt > 30")
lVars.Add("VetoMu", "abs(Muon_eta) < 2.4 && Muon_looseId == true && Muon_miniIsoId >= 1 && Muon_pt > 10 && TightMu == false")
lVars.Add("VetoEl", "abs(Electron_eta) < 2.5 && Electron_mvaFall17V2noIso_WPL == true && Electron_miniPFRelIso_all < 0.4 && Electron_pt > 10 && TightEl == false")
lVars.Add("nVetoLep", "Sum(VetoMu)+Sum(VetoEl)")
lVars.Add("nTightMu", "Sum(TightMu)")
lVars.Add("nTightEl", "Sum(TightEl)")
lVars.Add("TMuon_pt", "Muon_pt[TightMu == true]")
lVars.Add("TMuon_eta", "Muon_eta[TightMu == true]")
lVars.Add("TMuon_phi", "Muon_phi[TightMu == true]")
lVars.Add("TMuon_mass", "Muon_mass[TightMu == true]")
lVars.Add("TElectron_pt", "Electron_pt[TightEl == true]")
lVars.Add("TElectron_eta", "Electron_eta[TightEl == true]")
lVars.Add("TElectron_phi", "Electron_phi[TightEl == true]")
lVars.Add("TElectron_mass", "Electron_mass[TightEl == true]")
lVars.Add("TMuon_P4", "fVectorConstructor(TMuon_pt,TMuon_eta,TMuon_phi,TMuon_mass)")
lVars.Add("TElectron_P4", "fVectorConstructor(TElectron_pt,TElectron_eta,TElectron_phi,TElectron_mass)")
lVars.Add("TMuon_jetIdx", "Muon_jetIdx[TightMu == true]")
lVars.Add("TElectron_jetIdx", "Electron_jetIdx[TightEl == true]")
        # select lepton
lVars.Add("isMu","nMuon > 0 && nTightMu == 1 && (nElectron == 0 || nTightEl == 0) && nVetoLep == 0 && (HLT_Mu50 == 1 || HLT_Mu15_IsoVVVL_PFHT450 == 1)") 
lVars.Add("isEl","nElectron > 0 && nTightEl == 1 && (nMuon == 0 || nTightMu == 0) && nVetoLep==0 && (HLT_Ele35_WPTight_Gsf == 1 || HLT_Ele15_IsoVVVL_PFHT450 == 1)") 
        
        # filter lepton
lCuts = CutGroup('LeptonCuts')
lCuts.Add("Event is either muon or electron", "isMu || isEl")
        # assign lepton
lVars.Add("assignleps","assign_leps(isMu,isEl,TightMu,TightEl,Muon_pt,Muon_eta,Muon_phi,Muon_mass,Muon_miniPFRelIso_all,Electron_pt,Electron_eta,Electron_phi,Electron_mass,Electron_miniPFRelIso_all)")
lVars.Add("lepton_pt","assignleps[0]")
lVars.Add("lepton_eta","assignleps[1]")	
lVars.Add("lepton_phi","assignleps[2]")
lVars.Add("lepton_mass","assignleps[3]")
lVars.Add("lepton_miniIso","assignleps[4]")

# ------------------ Jet Cleaning Cuts ------------------
jVars = VarGroup('JetCleaningVars')

jVars.Add("Jet_P4", "fVectorConstructor(Jet_pt,Jet_eta,Jet_phi,Jet_mass)")
jVars.Add("FatJet_P4", "fVectorConstructor(FatJet_pt,FatJet_eta,FatJet_phi,FatJet_mass)")
jVars.Add("Jet_EmEF","Jet_neEmEF + Jet_chEmEF")
#jVars.Add("DummyZero","float(0.0)")

#jVars.Add("cleanedJets", "cleanJets(Jet_P4,Jet_rawFactor,TMuon_P4,TMuon_jetIdx,TElectron_P4,TElectron_jetIdx)")

#cleanerJet = ROOT.cleanJets(ROOT.Jet_P4,ROOT.Jet_rawFactor,ROOT.TMuon_P4,ROOT.TMuon_jetIdx,ROOT.TElectron_P4,ROOT.TElectron_jetIdx)

#print(jVars["cleanedJets[0]"])
#print(cleanerJet.size)

#jVars.Add("cleanedJets", "cleanJets(Jet_P4,Jet_rawFactor,Jet_muonSubtrFactor,Jet_area,Jet_EmEF,Jet_jetId,Jet_P4,Jet_jetId,SMuon_P4,SMuon_jetIdx,SElectron_P4,SElectron_jetIdx,fixedGridRhoFastjetAll,DummyZero,DummyZero") # muon and EM factors unused in this call, args 6-7 are dummies
#jVars.Add("cleanMets", "cleanJets(Jet_P4,Jet_rawFactor,Jet_muonSubtrFactor,Jet_area,Jet_EmEF,Jet_jetId,Jet_P4,Jet_jetId,Muon_P4,Muon_jetIdx,SElectron_P4,SElectron_jetIdx,fixedGridRhoFastjetAll,RawMET_pt,RawMET_phi") # lepton args unused in this call, args 6-7 are dummies
#jVars.Add("cleanFatJets", "cleanJets(FatJet_P4,FatJet_rawFactor,FatJet_rawFactor,FatJet_area,FatJet_area,FatJet_jetId,FatJet_P4,FatJet_jetId,SMuon_P4,SMuon_jetIdx,SElectron_P4,SElectron_jetIdx,fixedGridRhoFastjetAll,DummyZero,DummyZero") # args 2, 4, 6, 7 are dummies
#jVars.Add("cleanedJets", cleanJets, {"Jet_P4","Jet_rawFactor","Jet_muonSubtrFactor","Jet_area","Jet_EmEF","Jet_jetId","Jet_P4","Jet_jetId","SMuon_P4","SMuon_jetIdx","SElectron_P4","SElectron_jetIdx","fixedGridRhoFastjetAll","DummyZero","DummyZero"}) # muon and EM factors unused in this call, args 6-7 are dummies
#jVars.Add("cleanMets", cleanJets, {"Jet_P4","Jet_rawFactor","Jet_muonSubtrFactor","Jet_area","Jet_EmEF","Jet_jetId","Jet_P4","Jet_jetId","Muon_P4","Muon_jetIdx","SElectron_P4","SElectron_jetIdx","fixedGridRhoFastjetAll","RawMET_pt","RawMET_phi"}) # lepton args unused in this call, args 6-7 are dummies
#jVars.Add("cleanFatJets", cleanJets, {"FatJet_P4","FatJet_rawFactor","FatJet_rawFactor","FatJet_area","FatJet_area","FatJet_jetId","FatJet_P4","FatJet_jetId","SMuon_P4","SMuon_jetIdx","SElectron_P4","SElectron_jetIdx","fixedGridRhoFastjetAll","DummyZero","DummyZero"}) # args 2, 4, 6, 7 are dummies


#print(<Node>)
#print(a.GetNode(JetCleaningVars__cleanedJets))
#print(a.GetActiveNode()) #Take("cleanedJets"))

#print(a.DataFrame().G

''' 
jVars.Add("cleanedJet_pt", "cleanedJets[0]")
jVars.Add("cleanedJet_eta", "cleanedJets[1]")
jVars.Add("cleanedJet_phi", "cleanedJets[2]")
jVars.Add("cleanedJet_mass", "cleanedJets[3]")
jVars.Add("cleanedJet_rawFactor", "cleanedJets[4]")
jVars.Add("DR_lepJets","DeltaR_VecAndFloat(cleanedJet_eta,cleanedJet_phi,lepton_eta,lepton_phi)")
jVars.Add("ptrel_lepJets","ptRel(cleanedJet_pt,cleanedJet_eta,cleanedJet_phi,cleanedJet_mass,lepton_pt,lepton_eta,lepton_phi,lepton_mass)") 
jVars.Add("goodcleanJets", "cleanedJet_pt > 30 && abs(cleanedJet_eta) < 2.4 && Jet_jetId > 1 && (DR_lepJets > 0.4 || ptrel_lepJets > 20)")
jVars.Add("NJets_central", "(int) Sum(goodcleanJets)")
jVars.Add("gcJet_pt", "cleanedJet_pt[goodcleanJets == true]")
jVars.Add("gcJet_eta", "cleanedJet_eta[goodcleanJets == true]")
jVars.Add("gcJet_phi", "cleanedJet_phi[goodcleanJets == true]")
jVars.Add("gcJet_mass", "cleanedJet_mass[goodcleanJets == true]")
jVars.Add("gcJet_DeepFlav", "Jet_btagDeepFlavB[goodcleanJets == true]")
jVars.Add("gcJet_DeepFlavM", "gcJet_DeepFlav > 0.2783")
jVars.Add("NJets_DeepFlavM", "(int) Sum(gcJet_DeepFlavM)")
'''
jVars.Add("DR_lepFatJets","DeltaR_VecAndFloat(FatJet_eta,FatJet_phi,lepton_eta,lepton_phi)")
jVars.Add("ptrel_lepFatJets","ptRel(FatJet_pt,FatJet_eta,FatJet_phi,FatJet_mass,lepton_pt,lepton_eta,lepton_phi,lepton_mass)") 
jVars.Add("goodcleanFatJets", "FatJet_pt > 200 && abs(FatJet_eta) < 2.4 && FatJet_jetId > 1 && (DR_lepFatJets > 0.8 || ptrel_lepFatJets > 20)")
jVars.Add("NFatJets_central", "(int) Sum(goodcleanFatJets)")
jVars.Add("gcFatJet_pt", "FatJet_pt[goodcleanFatJets == true]")
jVars.Add("gcFatJet_eta", "FatJet_eta[goodcleanFatJets == true]")
jVars.Add("gcFatJet_phi", "FatJet_phi[goodcleanFatJets == true]")
jVars.Add("gcFatJet_mass", "FatJet_mass[goodcleanFatJets == true]")
jVars.Add("gcFatJet_sdmass", "FatJet_msoftdrop[goodcleanFatJets == true]")

        # HT Calculation and Final Preselection Cut
#jVars.Add('AK4HT', 'Sum(gcJet_pt)')    

jCuts = CutGroup('JetCuts')
#jCuts.Add('AK4 HT Pass', 'AK4HT > 510')    
jCuts.Add('3 AK8s Pass', 'NFatJets_central > 2')    # need to ensure three jets exist

#jCuts.Add('3 AK8s Pass', 'nFatJet > 2')


# ------------------ Post Preselection Analysis ------------------
ppaVars = VarGroup('postPreSelectionAnalysisVars')
#TODO think.  Do we need the next one?  This one requires a lot of code from 
#../../../RJRanalysis/CMSSW_11_0_0/src/RJR/step1RDF_forLJMet.cpp
#ppaVars.Add("decayMode_or_genTTbarMass",decayModeSelection_genTTbarMassCalc,{"nGenPart","GenPart_pdgId","GenPart_mass", "GenPart_pt","GenPart_phi","GenPart_eta", "GenPart_genPartIdxMother","GenPart_status"})
ppaVars.Add("lepton_lv","lvConstructor(lepton_pt,lepton_eta,lepton_phi,lepton_mass)")
ppaVars.Add("AK4HTpMETpLepPt","AK4HT + lepton_pt + MET_pt") 
ppaVars.Add("dnnJ","FatJet_deepTag_QCDothers[goodcleanFatJets == true]")	
ppaVars.Add("int_dnnT","(FatJet_deepTag_TvsQCD * FatJet_deepTag_QCD) / (1 - FatJet_deepTag_TvsQCD)") 
ppaVars.Add("dnnT","int_dnnT[goodcleanFatJets == true]")		
ppaVars.Add("dnnH","FatJet_deepTag_H[goodcleanFatJets == true]")
ppaVars.Add("int_dnnZ","(FatJet_deepTag_ZvsQCD * FatJet_deepTag_QCD) / (1 - FatJet_deepTag_ZvsQCD)") 
ppaVars.Add("dnnZ","int_dnnZ[goodcleanFatJets == true]")			
ppaVars.Add("int_dnnW","(FatJet_deepTag_WvsQCD * FatJet_deepTag_QCD) / (1 - FatJet_deepTag_WvsQCD)") 
ppaVars.Add("dnnW","int_dnnW[goodcleanFatJets == true]")		
ppaVars.Add("int_dnnB","(FatJet_deepTag_QCD - FatJet_deepTag_QCDothers)") 
ppaVars.Add("dnnB","int_dnnB[goodcleanFatJets == true]")		
ppaVars.Add("dnnLargest","maxFxn(dnnJ,dnnT,dnnH,dnnZ,dnnW,dnnB)")	
ppaVars.Add("nJ_DeepAK8","Sum(dnnLargest == 0)")			
ppaVars.Add("nT_DeepAK8","Sum(dnnLargest == 1)")			
ppaVars.Add("nH_DeepAK8","Sum(dnnLargest == 2)")			
ppaVars.Add("nZ_DeepAK8","Sum(dnnLargest == 3)")			
ppaVars.Add("nW_DeepAK8","Sum(dnnLargest == 4)")			
ppaVars.Add("nB_DeepAK8","Sum(dnnLargest == 5)")			
ppaVars.Add("int_tau21","(FatJet_tau2 / FatJet_tau1)")			
ppaVars.Add("tau21","int_tau21[goodcleanFatJets == true]")  
ppaVars.Add("tau21_1","tau21[0]")					
ppaVars.Add("tau21_2","tau21[1]")					
ppaVars.Add("tau21_3","tau21[2]")					
ppaVars.Add("minDR_ptRel_lead_lepAK8","minDR_ptRel_lead_calc(gcFatJet_pt,gcFatJet_eta,gcFatJet_phi,gcFatJet_mass,lepton_lv)")
ppaVars.Add("minDR_lepAK8","minDR_ptRel_lead_lepAK8[0]")		
ppaVars.Add("ptRel_lepAK8","minDR_ptRel_lead_lepAK8[1]")		
ppaVars.Add("minDR_leadAK8otherAK8","minDR_ptRel_lead_lepAK8[2]")	
ppaVars.Add("minDR_ptRel_lead_lepJets","minDR_ptRel_lead_calc(gcJet_pt,gcJet_eta,gcJet_phi,gcJet_mass,lepton_lv)")
ppaVars.Add("minDR_lepJet","minDR_ptRel_lead_lepJets[0]")		
ppaVars.Add("ptRel_lepJet","minDR_ptRel_lead_lepJets[1]")		
ppaVars.Add("DR_lepAK8s","DeltaR_VecAndFloat(gcFatJet_eta,gcFatJet_phi,lepton_eta,lepton_phi)")
ppaVars.Add("W_lv","lpNu_WCalc(MET_pt,MET_phi,lepton_lv)") 
#ppaVars.Add("minMlj",minMleppJet_calc,{"gcJet_pt","gcJet_eta","gcJet_phi","gcJet_mass", "lepton_lv","gcJet_DeepFlav"})				
ppaVars.Add("W_dRLep","dR_Wt_Calc(W_lv,lepton_lv)")			
#ppaVars.Add("minMleppJet","minMlj[0]")					
ppaVars.Add("ind_MinMlj","(int) minMlj[1]")				
ppaVars.Add("NJetsDeepFlavwithSF","(int) minMlj[2]")		
#ppaVars.Add("isLeptonic","isLeptonic_X(minMleppJet)")			
#ppaVars.Add("t_lv","lpNu_t_Calc(isLeptonic,gcJet_pt,gcJet_eta,gcJet_phi,gcJet_mass,W_lv,minMleppJet,ind_MinMlj)")
ppaVars.Add("t_pt","t_lv[0]")						
ppaVars.Add("t_eta","t_lv[1]")						
ppaVars.Add("t_phi","t_lv[2]")						
ppaVars.Add("t_mass","t_lv[3]")						
ppaVars.Add("t_dRWb","t_lv[4]")						
ppaVars.Add("top_lv","top_lvConstructor(t_pt,t_eta,t_phi,t_mass)")	
#ppaVars.Add("tj_vec","three_jet(top_lv,W_lv,isLeptonic,gcFatJet_pt,gcFatJet_eta,gcFatJet_phi,gcFatJet_mass,dnnT,dnnH,dnnZ,dnnW,dnnB,dnnLargest,gcFatJet_sdmass)")
"""
ppaVars.Add("Tprime1_DeepAK8_Mass","tj_vec[0]")				
ppaVars.Add("Tprime2_DeepAK8_Mass","tj_vec[1]")				
ppaVars.Add("Tprime1_DeepAK8_pt","tj_vec[2]")				
ppaVars.Add("Tprime2_DeepAK8_pt","tj_vec[3]")				
ppaVars.Add("Tprime1_DeepAK8_eta","tj_vec[4]")				
ppaVars.Add("Tprime2_DeepAK8_eta","tj_vec[5]")				
ppaVars.Add("Tprime1_DeepAK8_Phi","tj_vec[6]")				
ppaVars.Add("Tprime2_DeepAK8_Phi","tj_vec[7]")				
ppaVars.Add("Tprime1_DeepAK8_deltaR","tj_vec[8]")			
ppaVars.Add("Tprime2_DeepAK8_deltaR","tj_vec[9]")			
ppaVars.Add("Bprime1_DeepAK8_Mass","tj_vec[10]")			
ppaVars.Add("Bprime2_DeepAK8_Mass","tj_vec[11]")			
ppaVars.Add("Bprime1_DeepAK8_pt","tj_vec[12]")				
ppaVars.Add("Bprime2_DeepAK8_pt","tj_vec[13]")				
ppaVars.Add("Bprime1_DeepAK8_eta","tj_vec[14]")				
ppaVars.Add("Bprime2_DeepAK8_eta","tj_vec[15]")				
ppaVars.Add("Bprime1_DeepAK8_Phi","tj_vec[16]")				
ppaVars.Add("Bprime2_DeepAK8_Phi","tj_vec[17]")				
ppaVars.Add("Bprime1_DeepAK8_deltaR","tj_vec[18]")			
ppaVars.Add("Bprime2_DeepAK8_deltaR","tj_vec[19]")			
ppaVars.Add("leptonicTprimeJetIDs_DeepAK8","(int) tj_vec[23]")		
ppaVars.Add("leptonicBprimeJetIDs_DeepAK8","(int) tj_vec[24]")		
ppaVars.Add("hadronicTprimeJetIDs1_DeepAK8","(int) tj_vec[25]")		
ppaVars.Add("hadronicTprimeJetIDs2_DeepAK8","(int) tj_vec[26]")		
ppaVars.Add("hadronicBprimeJetIDs1_DeepAK8","(int) tj_vec[27]")		
ppaVars.Add("hadronicBprimeJetIDs2_DeepAK8","(int) tj_vec[28]")		
"""
ppaVars.Add("TPrime1_lv","top_lvConstructor(Tprime1_DeepAK8_pt,Tprime1_DeepAK8_eta,Tprime1_DeepAK8_Phi,Tprime1_DeepAK8_Mass)") 
ppaVars.Add("TPrime2_lv","top_lvConstructor(Tprime2_DeepAK8_pt,Tprime2_DeepAK8_eta,Tprime2_DeepAK8_Phi,Tprime2_DeepAK8_Mass)") 
ppaVars.Add("BPrime1_lv","top_lvConstructor(Bprime1_DeepAK8_pt,Bprime1_DeepAK8_eta,Bprime1_DeepAK8_Phi,Bprime1_DeepAK8_Mass)") 
ppaVars.Add("BPrime2_lv","top_lvConstructor(Bprime2_DeepAK8_pt,Bprime2_DeepAK8_eta,Bprime2_DeepAK8_Phi,Bprime2_DeepAK8_Mass)") 
#ppaVars.Add("TTagged","three_jet_TTag(top_lv,W_lv,isLeptonic,gcFatJet_pt,gcFatJet_eta,gcFatJet_phi,gcFatJet_mass,dnnLargest,hadronicTprimeJetIDs1_DeepAK8,hadronicTprimeJetIDs2_DeepAK8)")
ppaVars.Add("validT","TTagged[0]")					
ppaVars.Add("TtaggedDecay","TTagged[1]")				
#ppaVars.Add("BTagged","three_jet_BTag(top_lv,W_lv,isLeptonic,gcFatJet_pt,gcFatJet_eta,gcFatJet_phi,gcFatJet_mass,dnnLargest, hadronicBprimeJetIDs1_DeepAK8,hadronicBprimeJetIDs2_DeepAK8)")
ppaVars.Add("validB","BTagged[0]")					
ppaVars.Add("BtaggedDecay","BTagged[1]")




# ------------------ Results ------------------
rframeVars = VarGroup('restFrameVars')
rframeVars.Add('VLQ_mass', 'rfc.compute_mass(rdfslot_, lepton_pt, lepton_eta, lepton_phi, lepton_mass, gcFatJet_pt, gcFatJet_eta, gcFatJet_phi, gcFatJet_mass, MET_pt, MET_phi)')
rframeVars.Add('VLQ_mass_T', 'VLQ_mass[0]')
rframeVars.Add('VLQ_mass_Tbar', 'VLQ_mass[1]')
rframeVars.Add('VLQ_mass_T_r', 'VLQ_mass[2]')
rframeVars.Add('VLQ_mass_Tbar_r', 'VLQ_mass[3]')
rframeVars.Add('VLQ_mass_ratio', 'VLQ_mass_T/VLQ_mass_Tbar')
rframeVars.Add('VLQ_mass_avg', '(VLQ_mass_T+VLQ_mass_Tbar)*0.5')


# -------------------------------------


#nodeToPlot = a.Apply([metCuts, lVars, lCuts, jVars, jCuts, ppaVars, rframeVars])
nodeToPlot = a.Apply(metCuts)
a.Apply(lVars)
a.Apply(lCuts)

a.Apply(jVars) ## where problem is

a.Apply(jCuts)
a.Apply(rframeVars)

#snapshotOptions = ROOT.RDF.RSnapshotOptions.RSnapshotOptions() #a.DataFrame.RSnapshotOptions()
#snapshotOptions.fLazy = False
#columns = a.GetColumnNames()
#a.DataFrame.Snapshot("VarFilters", "newfile.root", columns, snapshotOptions ) #.fLazy)


allColumns = a.GetColumnNames()
columns = [] #allColumns

#i = 0
for col in allColumns:
    #i = i + 1
    #if i > 49: continue
    if col == "run": break # lets just skip all the original branches?

    if ("P4" in col) or ("cleanJets" in col) or ("cleanFatJets" in col) or ("cleanMets" in col) or ("Dummy" in col): continue 
    if ("LHE" in col) and ("Weight" not in col) and (col != "LHE_HT") and (col != "LHE_Vpt") and (col != "gcHTCorr_WjetLHE"): continue
    if col.startswith("Muon") and ("_tightId" not in col) and ("_isPF" not in col) and ("tunep" not in col) and ("genPartFlav" not in col): continue
    if col.startswith("Electron") and ("genPartFlav" not in col): continue
    if col.startswith("Jet") and ("rawFactor" not in col): continue
    if col.startswith("FatJet") and ("rawFactor" not in col): continue
    if col.startswith("PPS") or col.startswith("Proton") or col.startswith("L1_"): continue
    if col.startswith("Gen") or col.startswith("Soft") or col.startswith("fixed"): continue
    if col.startswith("Sub") or col.startswith("RawPuppi") or col.startswith("Calo") or col.startswith("Chs"): continue
    if col.startswith("Corr") or col.startswith("Fsr") or col.startswith("Iso") or col.startswith("Tau"): continue
    if col.startswith("SV") or col.startswith("Puppi") or col.startswith("Photon") or col.startswith("Low"): continue
    if col.startswith("HLT") or col.startswith("HT") or col.startswith("boosted") or col.startswith("Deep"): continue
    if col.startswith("Flag") or col == "Bprime_gen_info" or col == "t_gen_info" or col == "W_gen_info" or col == "metxyoutput": continue
    if col == "assignleps" or col == "pnetoutput" or col == "t_output" or col == "Bprime_output" or col.startswith("Other"): continue
    if col.startswith("PS") or col.startswith("PV") or col.startswith("Tk") or col.startswith("Trig"): continue
    if col.startswith("nCorr") or col.startswith("nFsr"): continue
    if col.startswith("nGen") or col.startswith("nIso") or col.startswith("nLow"): continue
    if col.startswith("nOther") or col.startswith("nPS") or col.startswith("nPhoton"): continue
    if col.startswith("nSV") or col.startswith("nSub") or col.startswith("nTau") or col.startswith("nTrig"): continue
    if col.startswith("nboosted"): continue
    
    columns.append(col)

#TODO think do we really want to recreate this everytime?  or just create?
a.Snapshot(columns, "out_Tprime.root", "Events", lazy=False, openOption='RECREATE', saveRunChain=False)


myHist1 = a.GetActiveNode().DataFrame.Histo1D(('m_T_lab', 'Mass of T lab', 25, 500, 2000), 'VLQ_mass_T')
myHist2 = a.GetActiveNode().DataFrame.Histo1D(('m_Tbar_lab', 'Mass of Tbar lab', 25, 500, 2000), 'VLQ_mass_Tbar')
myHist1a = a.GetActiveNode().DataFrame.Histo1D(('m_T', 'Mass of T', 25, 500, 2000), 'VLQ_mass_T_r')
myHist2a = a.GetActiveNode().DataFrame.Histo1D(('m_Tbar', 'Mass of Tbar', 25, 500, 2000), 'VLQ_mass_Tbar_r')
myHist3 = a.GetActiveNode().DataFrame.Histo1D(('m_T/m_Tbar', 'Mass ratio of the two particles', 25, 0, 2), 'VLQ_mass_ratio')
myHist4 = a.GetActiveNode().DataFrame.Histo1D(('m_avg', 'Mass average of the two', 25, 500, 2000), 'VLQ_mass_avg')

out = ROOT.TFile.Open('test_Tprime_out.root','RECREATE') #'UPDATE')
myHist1.Write()
myHist2.Write()
myHist1a.Write()
myHist2a.Write()
myHist3.Write()
myHist4.Write()

out.Close()

a.PrintNodeTree('test_Tprime_out.png')

a.Close()

