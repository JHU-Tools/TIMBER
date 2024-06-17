## example how to read the muon format v2
## (Adapted from JMAR and EGM examples)
from correctionlib import _core

# Load CorrectionSet
fname = "../POG/MUO/2016postVFP_UL/muon_Z.json.gz"
if fname.endswith(".json.gz"):
    import gzip
    with gzip.open(fname,'rt') as file:
        data = file.read().strip()
        evaluator = _core.CorrectionSet.from_string(data)
else:
    evaluator = _core.CorrectionSet.from_file(fname)

# TrackerMuon Reconstruction UL scale factor
valsf = evaluator["NUM_TrackerMuons_DEN_genTracks"].evaluate("2016postVFP_UL", 1.1, 25.0, "sf")
print("sf is: " + str(valsf))

# Medium ID UL scale factor, down variation
valsf = evaluator["NUM_MediumID_DEN_TrackerMuons"].evaluate("2016postVFP_UL", 0.8, 35.0, "systdown")
print("systdown is: " + str(valsf))

# Medium ID UL scale factor, up variation
valsf = evaluator["NUM_MediumID_DEN_TrackerMuons"].evaluate("2016postVFP_UL", 0.8, 35.0, "systup")
print("systup is: " + str(valsf))

# Trigger UL systematic uncertainty only 
valsyst = evaluator["NUM_IsoMu24_or_IsoTkMu24_DEN_CutBasedIdTight_and_PFIsoTight"].evaluate("2016postVFP_UL", 1.8, 54.0, "syst")
print("syst is: " + str(valsyst))
