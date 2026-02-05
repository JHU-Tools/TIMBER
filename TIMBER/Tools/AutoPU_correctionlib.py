'''
Automatic calculation of per-jet per-event JES factors and uncertainties.
'''
from TIMBER.Tools.Common import GetJMETag, CompileCpp
from TIMBER.Analyzer import Correction
import correctionlib
import ROOT
import os
'''
Should you wish to use a custom-named collection derived from the FatJet or Jet
collections, it is advisable to modify them in the script from which you call 
AutoJME, for example:

    from TIMBER.Tools.Common import AutoJME
    AutoJME.AK8collection = "myCustomAK8collection"
    AutoJME.AutoJME(analyzer, "myCustomAK8collection", 2017, '', True)
'''

def AutoPU(a, year):


    json = 'puWeights'

    fname = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/LUM/{year}/{json}.json.gz"
    if "2024" in year: #################AD HOC SOLUTION!!!
        fname = os.path.dirname(os.path.abspath(__file__)) + f"/2024_pu_json/puweights_2024.json"


    
    cset = correctionlib.CorrectionSet.from_file(fname)
    keys = list(cset.keys()) # NOTE: we are using "cset_jes.compound" here b/c individual JEC levels have not been implemented for AutoJME, and we are just using the compound "L1L2L3Res" JEC level
    print(f"keys: {keys}")
    key = keys[0] 
    pu = Correction("PileUp_Corr", "TIMBER/Framework/src/PileUp_correctionlib_weight.cc", [fname, key, a.isData], corrtype="weight")
    evalargs = {
            "Pileup_nTrueInt": "Pileup_nTrueInt"
    }

    a.AddCorrection(pu, evalargs)
