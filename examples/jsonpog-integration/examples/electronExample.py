## example how to read the electron format v2
from correctionlib import _core

evaluator = _core.CorrectionSet.from_file('./../POG/EGM/2016postVFP_UL/electron.json')

valsf= evaluator["UL-Electron-ID-SF"].evaluate("2016postVFP","sf","RecoBelow20",1.1, 15.0)
print("sf is:"+str(valsf))

valsf= evaluator["UL-Electron-ID-SF"].evaluate("2016postVFP","sf","RecoAbove20",1.1, 25.0)
print("sf is:"+str(valsf))

valsf= evaluator["UL-Electron-ID-SF"].evaluate("2016postVFP","sf","Medium",1.1, 34.0)
print("sf is:"+str(valsf))

valsystup= evaluator["UL-Electron-ID-SF"].evaluate("2016postVFP","sfup","Medium",1.1, 34.0)
print("systup is:"+str(valsystup))

valsystdown= evaluator["UL-Electron-ID-SF"].evaluate("2016postVFP","sfdown","Medium",1.1, 34.0)
print("systdown is:"+str(valsystdown))
