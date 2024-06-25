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
#file_name = 'root://cmsxrootd.fnal.gov//store/mc/RunIISummer20UL18NanoAODv9/TprimeTprime_M-1500_TuneCP5_13TeV-madgraph-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/40000/447AD74F-034B-FA42-AD05-CD476A98C43D.root'
file_name = 'ourtestfile.root'

#TODO isMC? isVV? isSig? etc.
isMC = True
'''if "/mc/" in file_name:
  isMC = True
else: 
  isMC = False'''

year = sys.argv[1] # first command line argument

# Import the C++
CompileCpp('TIMBER/Framework/include/common.h') # Compile (via gInterpreter) commonly used c++ code
CompileCpp('TIMBER/Framework/Tprime1lep/cleanjet.cc') # Compile Our vlq c++ code
CompileCpp('TIMBER/Framework/Tprime1lep/utilities.cc') # Compile Our vlq c++ code
#ROOT.gInterpreter.ProcessLine('#include "../TIMBER/Framework/Tprime1lep/lumiMask.h"')
#CompileCpp('TIMBER/Framework/Tprime1lep/lumiMask.h')
#CompileCpp('TIMBER/Framework/Tprime1lep/lumiMask.cc')
CompileCpp('TIMBER/Framework/Tprime1lep/selfDerived_corrs.cc')
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

ROOT.gInterpreter.Declare('string year = "' + year + '";')

debug = False

# ------------------ Golden JSON Data ------------------
# change the jsonfile path to somewhere they have it in TIMBER
jsonfile = ""
if (year == "2016" or year == "2016APV"): jsonfile = "Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt"
elif (year == "2017"): jsonfile = "Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt"
elif (year == "2018"): jsonfile = "Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON.txt"
else: print(f'ERROR: Can\'t parse the year to assign a golden json file. Expected 2016, 2016APV, 2017, or 2018. Got: {year}\n')
#ROOT.gInterpreter.Declare("""
#const auto myLumiMask = lumiMask::fromJSON(\"""" + jsonfile + """\");
#//  std::cout << "Testing the JSON! Known good run/lumi returns: " << myLumiMask.accept(315257, 10) << ", and known bad run returns: " << myLumiMask.accept(315257, 90) << std::endl;
#""")

# ------------------ Self-derived corrections ------------------

#TODO more things here

    # Lepton scale factors not in correctionLib
ROOT.gInterpreter.ProcessLine("""
initialize(year);
""")
#can do things like this inside:   include <iostream>
#using namespace std; 
#std::cout << elid_pts.size() << elid_pts.at(2); //TODO remove
#std::cout << elecidsfs.size() << elecidsfs.at(0).size() << elecidsfs.at(0).at(0) << endl;
#""")

# ------------------ correctionsLib corrections ------------------
mutrig = "TkMu50";
if (year == "2016APV"): deepjetL = "0.0508"; yrstr = "2016preVFP"; yr = "16"; jecyr = "UL16APV"; jeryr = "Summer20UL16APV_JRV3"; jecver = "V7"
elif (year == "2016"): deepjetL = "0.0480"; yrstr = "2016postVFP"; yr = "16"; jecyr = "UL16"; jeryr = "Summer20UL16_JRV3"; jecver = "V7"
elif (year == "2017"): mutrig = "OldMu100_or_TkMu100"; deepjetL = "0.0532"; yrstr = "2017"; yr = "17"; jecyr = "UL17"; jeryr = "Summer19UL17_JRV2"; jecver = "V5"
elif (year == "2018"): mutrig = "OldMu100_or_TkMu100"; deepjetL = "0.0490"; yrstr = "2018"; yr = "18"; jecyr = "UL18"; jeryr = "Summer19UL18_JRV2"; jecver = "V5"
else: print(f'ERROR: Can\'t parse the year to assign correctionLib json files. Expected 2016, 2016APV, 2017, or 2018. Got: {year}\n')

ROOT.gInterpreter.Declare("""
string yrstr = \""""+yrstr+"""\"; string yr = \""""+yr+"""\"; string jecyr = \""""+jecyr+"""\"; string jeryr = \""""+jeryr+"""\"; string jecver = \""""+jecver+"""\"; string mutrig = \""""+mutrig+"""\";
float deepjetL = """+deepjetL+""";
""")


ROOT.gInterpreter.Declare("""
auto csetPU = correction::CorrectionSet::from_file("jsonpog-integration/POG/LUM/"+yrstr+"_UL/puWeights.json");
auto electroncorrset = correction::CorrectionSet::from_file("jsonpog-integration/POG/EGM/"+yrstr+"_UL/electron.json");
auto muoncorrset = correction::CorrectionSet::from_file("jsonpog-integration/POG/MUO/"+yrstr+"_UL/muon_Z.json");
auto metcorrset = correction::CorrectionSet::from_file("jsonpog-integration/POG/JME/"+yrstr+"_UL/met.json");

auto corrPU = csetPU->at("Collisions"+yr+"_UltraLegacy_goldenJSON");
auto electroncorr = electroncorrset->at("UL-Electron-ID-SF"); 
auto muoncorr = muoncorrset->at("NUM_TrackerMuons_DEN_genTracks");
auto muonidcorr = muoncorrset->at("NUM_MediumID_DEN_TrackerMuons");
auto muonhltcorr = muoncorrset->at("NUM_Mu50_or_"+mutrig+"_DEN_CutBasedIdGlobalHighPt_and_TkIsoLoose"); 
auto metptcorr = metcorrset->at("pt_metphicorr_pfmet_mc");
auto metphicorr = metcorrset->at("phi_metphicorr_pfmet_mc");
if(!isMC) {
  metptcorr = metcorrset->at("pt_metphicorr_pfmet_data");
  metphicorr = metcorrset->at("phi_metphicorr_pfmet_data"); };
""")

#from muonhltcorr => std::cout << "\t loaded muon trig" << std::endl; // REDO ME (Do we need to change something?)

# ------------------ MET Cuts ------------------
metVars = VarGroup('METVars')
metCuts = CutGroup('METCuts')
metCuts.Add('MET Filters', 'Flag_EcalDeadCellTriggerPrimitiveFilter == 1 && Flag_goodVertices == 1 && Flag_HBHENoiseFilter == 1 && Flag_HBHENoiseIsoFilter == 1 && Flag_eeBadScFilter == 1 && Flag_globalSuperTightHalo2016Filter == 1 && Flag_BadPFMuonFilter == 1 && Flag_ecalBadCalibFilter == 1')
metCuts.Add('Pass MET > 50', 'MET_pt > 50')
metCuts.Add('Event has jets',        'nJet > 0 && nFatJet > 0') # need jets 

# ------------------ Golden JSON (Data) || GEN Info (MC) ------------------
gjsonVars = VarGroup('GoldenJsonVars')
gjsonCuts = CutGroup('GoldenJsonCuts')
#if not isMC:
 #   gjsonVars.Add("passesJSON", "goldenjson(myLumiMask, run, luminosityBlock)")
 #   gjsonCuts.Add("Data passes Golden JSON", "passesJSON == 1") 

        # this was originally in the else block:
gjsonVars.Add("PileupWeights", "pufunc(corrPU, Pileup_nTrueInt)")

# ------------------- Lepton Selection --------- got this when adding hltfunc to corrlib_funcs.cc --------------
#auto LepSelect = LepDefs.Define("isMu", Form("(nMuon>0) && (HLT_Mu50%s) && (nSignalIsoMu==1) && (nVetoIsoLep==0) && (nElectron == 0 || nSignalIsoEl == 0)",tkmutrig.c_str()))
 #   .Define("isEl", Form("(nElectron>0) && (%s) && (nSignalIsoEl==1) && (nVetoIsoLep==0) && (nMuon == 0 || nSignalIsoMu == 0)",eltrig.c_str()))
  #  .Filter("isMu || isEl", "Event is either muon or electron")

# ------------------ Letpon Cuts ------------------
lVars = VarGroup('LeptonVars')
lVars.Add("TightMu", "abs(Muon_eta) < 2.4 && Muon_tightId == true && Muon_miniIsoId >= 3 && Muon_pt > 50")
lVars.Add("TightEl", "abs(Electron_eta) < 2.5 && Electron_mvaFall17V2noIso_WP90 == true && Electron_miniPFRelIso_all < 0.1 && Electron_pt > 50")
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


# -----------------------------MET Selection--------------------------------------------------------- 

metVars.Add("metxyoutput", "metfunc(metptcorr, metphicor, corrMETnoxy_pt, corrMETnoxy_phi, PV_npvs, run)")
metVars.Add("corrMET_pt","metxyoutput[0]")
metVars.Add("corrMET_phi","metxyoutput[1]")

metCuts.Add("Pass corr MET > 60", "corrMET_pt > 60")
metCuts.Add("Electron Triangle Cut", "isMu || corrMET_pt>((130/1.5)*DeltaPhi(lepton_phi, corrMET_phi)-130)");

# ------------------ Add scale factors and MC jet-based calcs ------------------
#TODO could be a fatJetVar group
if isMC:
  jVars.Add("leptonRecoSF", "recofunc(electroncorr, muoncorr, yrstr, lepton_pt, lepton_eta, isEl)")
  jVars.Add("leptonIDSF", "idfunc(muonidcorr,elid_pts,elid_etas,elecidsfs,elecidsfuncs,yrstr, lepton_pt, lepton_eta, isEl)") #at(0) 
  jVars.Add("leptonIsoSF", "isofunc(muiso_pts,muiso_etas,muonisosfs,muonisosfunc,elid_pts,elid_etas,elecisosfs,elecisosfunc, lepton_pt, lepton_eta, isEl)")
  jVars.Add("leptonHLTSF", "hltfunc(muonhltcorr,elhlt_pts,elhlt_etas,elechltsfs,elechltuncs,yrstr, lepton_pt, lepton_eta, isEl)")

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


nodeToPlot = a.Apply([metVars, metCuts, gjsonVars, gjsonCuts, lVars, lCuts, jVars, jCuts, rframeVars])
#nodeToPlot = a.Apply(metCuts)
#a.Apply(lVars)
#a.Apply(lCuts)
#a.Apply(jVars) ## where problem is
#a.Apply(jCuts)
#a.Apply(rframeVars)

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
    #TODO need to figure out how to exclude the things related to nSub and Sub.
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

print("--------- Analysis End ---------")

out.Close()


a.Close()

