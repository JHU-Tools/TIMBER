from TIMBER.Tools.Common import CompileCpp
import ROOT
import os
def AutoJetID(a, year, jet_types = ["Jet", "FatJet"], nanoAOD_ver = 15):
    if nanoAOD_ver == 12:
        #THIS ONLY WORKS FOR TIGHT WP WITH |DELTA ETA| < 2,7. MORE COMPLICATED RECIPE IS NEEDED FOR OTHER REGION AND TIGHTLEPTOVETO WP.
        if "Jet" in jet_types:
            a.Define("Jet_jetId_corr", f'Jet_jetId')
        if "FatJet" in jet_types:
            a.Define("FatJet_jetId_corr", f'FatJet_jetId')
    elif nanoAOD_ver > 12:
        CompileCpp('TIMBER/Framework/src/JetID_calculator.cc')
        #json_file = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/JME/{year}/jetid.json.gz"
        json_file = os.path.dirname(os.path.abspath(__file__)) + f"/jetid_jsons/{year}/jetid.json"
        if "Jet" in jet_types:
            ROOT.gInterpreter.Declare(f'JetID_calculator JetID_AK4("{json_file}", "AK4");')
            a.Define("Jet_jetId_corr", f'JetID_AK4.eval(nJet, Jet_eta, Jet_chHEF, Jet_neHEF, Jet_chEmEF, Jet_neEmEF, Jet_muEF, Jet_chMultiplicity, Jet_neMultiplicity)')
        if "FatJet" in jet_types:
            ROOT.gInterpreter.Declare(f'JetID_calculator JetID_AK8("{json_file}", "AK8");')
            a.Define("FatJet_jetId_corr", 'JetID_AK8.eval(nFatJet, FatJet_eta, FatJet_chHEF, FatJet_neHEF, FatJet_chEmEF, FatJet_neEmEF, FatJet_muEF, FatJet_chMultiplicity, FatJet_neMultiplicity)')
