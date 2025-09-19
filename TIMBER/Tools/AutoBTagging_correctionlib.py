'''
Automatic calculation of per-jet per-event JES factors and uncertainties.
'''
from TIMBER.Tools.Common import GetJMETag, CompileCpp
from TIMBER.Analyzer import Correction
import correctionlib
import ROOT

'''
Should you wish to use a custom-named collection derived from the FatJet or Jet
collections, it is advisable to modify them in the script from which you call 
AutoJME, for example:

    from TIMBER.Tools.Common import AutoJME
    AutoJME.AK8collection = "myCustomAK8collection"
    AutoJME.AutoJME(analyzer, "myCustomAK8collection", 2017, '', True)
'''

def AutoBTagging(a, year, ijets):


    json = 'btagging'

    fname = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/BTV/{year}/{json}.json.gz"


    
    cset = correctionlib.CorrectionSet.from_file(fname)
    keys = list(cset.keys()) # NOTE: we are using "cset_jes.compound" here b/c individual JEC levels have not been implemented for AutoJME, and we are just using the compound "L1L2L3Res" JEC level
    print(f"keys: {keys}")
    key = "particleNet_shape" 
    for ijet in ijets:
        if ijet == 0:
            btagging = Correction(f"BTagging_Corr_{ijet}", "TIMBER/Framework/src/BTagging_correctionlib_weight.cc", [fname, key, a.isData], corrtype="weight")
        else:
            btagging = btagging.Clone(f"BTagging_Corr_{ijet}")
        
        evalargs = {
            "flavor": "5",
            "eta": f"FatJet_eta[{ijet}]",
            "pt": f"FatJet_pt[{ijet}]",
            "discriminant": f"FatJet_particleNet_XbbVsQCD[{ijet}]"
    }

        a.AddCorrection(btagging, evalargs)
