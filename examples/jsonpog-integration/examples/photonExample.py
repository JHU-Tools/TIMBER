## example how to read the photon format v2
from correctionlib import _core

evaluator = _core.CorrectionSet.from_file('./../POG/EGM/photon.json')

valsyst= evaluator["UL-Photon-ID-SF"].evaluate("2016postVFP","sfup","Medium",1.1, 34.0)
print("sfup is:"+str(valsyst))

valsf= evaluator["UL-Photon-CSEV-SF"].evaluate("2016postVFP","sf","Loose","EBInc")
print("sf is:"+str(valsf))

valsf= evaluator["UL-Photon-PixVeto-SF"].evaluate("2016postVFP","sf","Loose","EBInc")
print("sf is:"+str(valsf))

valsf= evaluator["UL-Photon-PixVeto-SF"].evaluate("2016postVFP","sfup","Loose","EBInc")
print("sfup is:"+str(valsf))

valsf= evaluator["UL-Photon-PixVeto-SF"].evaluate("2016postVFP","sfdown","Loose","EBInc")
print("sfdown is:"+str(valsf))
