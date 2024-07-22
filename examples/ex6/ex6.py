# Goal: Use ONNX with TIMBER to use a trained neural network to do inference. 
# ONNX is used to save a neural network in a .onnx file, and onnxruntime is used to
# access that neural network for use in inference. This example uses the data from
# two columns from an RDataFrame as input for the neural network, then creates a new
# column in the RDataFrame containing the output from the neural network that corresponds
# with each input.
# This example does not handle the creation of the .onnx file, it uses an existing one.

import ROOT
from TIMBER.Tools.Common import *
from TIMBER.Analyzer import *
import onnxruntime as ort #this import is needed to read the .onnx file that contains the trained neural network
import numpy as np

#Adapted from here: https://root-forum.cern.ch/t/make-rdataframes-interoperable-with-other-python-tools/48384/3 and here https://root-forum.cern.ch/t/adding-a-numpy-array-as-a-new-column-to-an-existing-rdataframe/60230/4
#this function adds a numpy array to an existing RDataFrame
def add_to_df(analyzer,prediction,column_name):
    analyzer.Define("myEntry", "static unsigned int myEntry = 0; return myEntry++;")
    @ROOT.Numba.Declare(["int"], "float")
    #need to be able to call a funtion in analyzer.Define()
    def get_prediction(index):
        return prediction[index]
    
    analyzer.Define(column_name, "Numba::get_prediction(myEntry)")

#function to run inference using the neural network and return an array containing the result
def inference(x, y):
    ort_sess = ort.InferenceSession('trained_model.onnx',providers=['CPUExecutionProvider'])
    
    #If you need to figure out the input shape and name
    # input_meta = ort_sess.get_inputs()
    # for input in input_meta:
    #     print(f"Input name: {input.name}, Shape: {input.shape}, Type: {input.type}")
    
    #Only one input
    input_name = ort_sess.get_inputs()[0].name
    input_data = np.array([[x, y]], dtype=np.float32)

    # Run inference
    results = ort_sess.run(None, {input_name: input_data})#Result is an array with a single float because the batch size is 1

    print(x,y,results[0])
    return results[0]

a = analyzer("signalLH1800_bstar16.root") #return to this to look at the .root file
a.Cut("nFatJet","nFatJet>1")
a.Define("pt0","FatJet_pt[0]")
a.Define("pt1","FatJet_pt[1]")
#create numpy arrays with the data from two columns from the RDataFrame
pt0 = np.array(a.DataFrame.AsNumpy(["pt0"])["pt0"], dtype=np.float32)
pt1 = np.array(a.DataFrame.AsNumpy(["pt1"])["pt1"], dtype=np.float32)

input_data = np.stack((pt0, pt1), axis=1) #Input to the model are two floats
ort_sess = ort.InferenceSession('trained_model.onnx', providers=['CPUExecutionProvider']) #Provider: T-mobile hehe
input_name = ort_sess.get_inputs()[0].name #Only one input so we take element 0
results = ort_sess.run(None, {input_name: input_data})[0]
results = results.flatten()#Flatten the single output

add_to_df(a,results,"inference")
a.DataFrame.Range(5).Display(["pt0", "pt1", "inference"]).Print()