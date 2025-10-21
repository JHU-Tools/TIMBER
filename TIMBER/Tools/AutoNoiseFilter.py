
import ROOT
from TIMBER.Tools.Common import CompileCpp
CompileCpp('TIMBER/Framework/src/ecalBadCalibFilterRecipe.cc')

def AutoNoiseFilter(analyzer, year, isData):
    if year == "2022" or year == "2022EE" or year == "2023" or year == "2023BPix" or year == "2024":
        filterString = "Flag_goodVertices == 1 && Flag_globalSuperTightHalo2016Filter == 1 && Flag_EcalDeadCellTriggerPrimitiveFilter== 1 && Flag_BadPFMuonFilter == 1 && Flag_BadPFMuonDzFilter == 1 && Flag_hfNoisyHitsFilter == 1 && Flag_eeBadScFilter == 1"
        analyzer.Cut("NoiseFilters", filterString)
        if (year == "2022" or year == "2022EE" or year == "2023" or year == "2023BPix") and isData:
            analyzer.Cut("ecalBadCalibFilter", "ecalBadCalibFilterRecipe(run,  PuppiMET_pt, PuppiMET_phi,  nJet, Jet_pt, Jet_eta, Jet_phi, Jet_neEmEF, Jet_chEmEF)")
        elif year == 2024:
            analyzer.Cut("ecalBadCalibFilter", "Flag_ecalBadCalibFilter == 1")
    else:
        raise ValueError("Only years of Run3 is supported by the moment.")
    

