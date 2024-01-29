from TIMBER.Tools.Common import CompileCpp
import ROOT
import os

# load the RestFrames shared library
ROOT.gSystem.Load(os.environ["TIMBERPATH"] + 'bin/restframes/lib/librestframes.so')

# Open the custom RestFramesHandler class that does actions on an event-level
blockcode_str = open('RestFramesHandler.cc','r').read()
ROOT.gInterpreter.Declare(blockcode_str)

# Instantiate the new class 
'''
There are two ways of doing this:
    1. Declare it directly, though then it will go out of scope and be unusable.
       To test this, uncomment the next two lines and watch what happens.
       This will have to be used in the RDataFrame code. 
'''
print('METHOD 1: ---------------------------------------------')
ROOT.gInterpreter.Declare('RestFramesHandler rfh = RestFramesHandler("TEST");')
ROOT.gInterpreter.Declare('rfh.test();')

'''
The second method is:
    2. Declaring it, then using it in the ROOT namespace. I don't think this will work
       with RDataFrame.
'''
print('METHOD 2: ---------------------------------------------')
test = ROOT.RestFramesHandler("TEST")
print(test)
test.test()
