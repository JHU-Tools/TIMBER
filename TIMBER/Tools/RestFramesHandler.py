from TIMBER.Analyzer import *
from TIMBER.Tools.Common import *

import ROOT
import os

def load_restframes(num_threads, name_of_cpp_handler, name_of_class, name_of_object):

    timberpath = os.environ["TIMBERPATH"]

    # load the RestFrames shared library
    ROOT.gSystem.Load(timberpath + 'bin/restframes/lib/librestframes.so')

    # Open the custom RestFramesHandler class that does actions on an event-level
    blockcode_str_cpp = open(timberpath + 'bin/restframes/'+name_of_cpp_handler,'r').read()

    blockcode_str_reformat = blockcode_str_cpp.replace('#include "include/', '#include "'+timberpath+'bin/restframes/include/')
    ROOT.gInterpreter.Declare(blockcode_str_reformat)

    # Instantiate the new class 
    print(name_of_class+' '+name_of_object+' = '+name_of_class+'('+str(num_threads)+');')
    ROOT.gInterpreter.Declare(name_of_class+' '+name_of_object+' = '+name_of_class+'('+str(num_threads)+');')
    ROOT.gInterpreter.ProcessLine(name_of_object+".test_all();")
    print('Successfully initialized RestFrame handlers')
