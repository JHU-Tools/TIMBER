# TIMBER {#mainpage}
[Full Documentation](https://lcorcodilos.github.io/TIMBER/)

TIMBER (Tree Interface for Making Binned Events with RDataFrame) is an easy-to-use and fast python analysis framework used to quickly process CMS data sets. 
Default arguments assume the use of the NanoAOD format but any ROOT TTree can be processed.

## Installation instructions for python3

These instructions use python3 and CMSSW. The instructions below have been tested on el8 (lxplus and lpc). To make it work on lxplus9 (el9), the CMSSW version should be changed to CMSSW_13_2_10.

```
cmsrel CMSSW_12_3_5
cd CMSSW_12_3_5
cmsenv
cd ..
python3 -m virtualenv timber-env
git clone git@github.com:JHU-Tools/TIMBER.git
cd TIMBER/
mkdir bin
cd bin
git clone git@github.com:fmtlib/fmt.git
cd ../..
```

Boost library path (the boost version as well!) may change depending on the CMSSW version so this may need to be modified by hand. This version works for both CMSSW versions used for lxplus8 and lxplus9. If one does not wish to use CMSSW, boost libraries will have to be installed (and added to the MakeFile).

Secondly, if operating on a cluster (e.g. FNAL LPC or CERN LXPLUS) and in a CMSSW environment, it is beneficial to have the CMSSW's [`correctionlib`](https://cms-nanoaod.github.io/correctionlib/) C++ libraries included. This is obtained by adding the path to the correctionlib include directory to the `ROOT_INCLUDE_PATH` environment variable.

This can all be automated by copying the whole following multi-line string to the environment activation script:

```
cat <<EOT >> timber-env/bin/activate

export BOOSTPATH=/cvmfs/cms.cern.ch/el8_amd64_gcc10/external/boost/1.78.0-0d68c45b1e2660f9d21f29f6d0dbe0a0/lib
if grep -q '\${BOOSTPATH}' <<< '\${LD_LIBRARY_PATH}'
then
  echo 'BOOSTPATH already on LD_LIBRARY_PATH'
else
  export LD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:\${BOOSTPATH}
  echo 'BOOSTPATH added to PATH'
fi

if [[ -z "${CMSSW_BASE}" ]]; then
    export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$(correction config --incdir)
fi

EOT
```

The following lines will activate the python3 environment, set a proper LD_LIBRARY_PATH for boost libraries and build the TIMBER binaries.

```
source timber-env/bin/activate
cd TIMBER
source setup.sh
```

Tip: Add the lines below to the top of `timber-env/bin/activate` script. With this, one can skip doing `cmsenv` every time after opening a new shell and just activate the environment instead.
```
cd CMSSW_12_3_5
cmsenv
cd ..
```

## Quick install
Despite the fact that Python 2.7 reached end-of-life on January 1st, 2020, it is still the dominant
version used by CMS. If you need CMSSW (ex. for JME modules), Python 2.7 is recommended. Otherwise,
please take this opportunity to start using Python 3! Remember to make sure your 
ROOT version has been built with Python 3 compatibility. For information on how to do this, see
[this explanation](doxysetup/Python3.md). Though this does not always work consistently when CMSSW code is needed.

Working in a virtual environment is also recommended. Below are the commands for using virtualenv but
you're obviously free to use your favorite tool for the job (you can install virtualenv for Python 3 with 
`pip install virtualenv` (`pip3` for Python 3)).

```
python -m virtualenv timber-env
source timber-env/bin/activate
git clone https://github.com/ammitra/TIMBER.git
cd TIMBER
source setup.sh
```

Some C++ modules also have the [boost library](https://www.boost.org/) as a dependency.
The internet has plenty instructions on how to install boost. The standard `apt-get`
(Ubuntu) and `brew` (macOS) package managers support install as well.

## The RDataFrame Backbone
TIMBER's speed comes from the use of 
[ROOT's RDataFrame](https://root.cern/doc/master/classROOT_1_1RDataFrame.html). 
RDataFrame offers "multi-threading and other low-level optimisations" which make analysis level
processing faster and more efficient than traditional python `for` loops. However,
RDataFrame derives its speed from its C++ back-end and while an RDataFrame object can be instantiated
and manipulated in python, any actions on it are written in C++ (even if you're using python).

## No more `for` loops
Using RDataFrame means a fundamental re-thinking of how we treat a block of data or simulation.
Instead of looping over the events or entries of a TTree (or other data format), the TTree is
converted into a table called the "data frame". A user then books a number of "lazy" actions on 
the data frame such as filtering out events or calculating new values. These actions aren't performed
though until the data frame needs to be evaluated (ex. you ask to plot a histogram from it). 

In this way, there are no more `for` loops and instead just actions on the data frame table that 
transform it into a final table of values that the analyzer cares about. 

## Anatomy of a data frame
Each row of the table is a separate event and each
column is a different variable in the event (a branch in TTree terms). Columns can be single values or
vectors (specifically [ROOT::VecOps:RVec](https://root.cern.ch/doc/v614/classROOT_1_1VecOps_1_1RVec.html)).

Since each row is an event, vectors are necessary for the case of multiple of the same physics object in 
an event - for example, multiple electrons. 

**NOTE** NanoAOD orders these vectors in \f$p_T\f$ of the objects. So if you'd like the \f$\eta\f$ of the leading electron, it is stored as `Electron_eta[0]`

This can make accessing values tricky! For example, if there's one electron in an event and the analyzer asks for `Electron_eta[1]`, the computer will return a seg fault. These are the types of problems that TIMBER attempts to solve (even if it's just by users sharing their experiences).

## Happy Analyzers
TIMBER is meant to keep both the processing fast via RDataFrame and the analyzer fast via python scripting.

To maintain python's appeal in HEP as a quick scripting language, TIMBER handles
interfacing with RDataFrame so the analyzer can focus on writing their analysis.

TIMBER automates opening one or many ROOT files, calculating the number of events generated 
(provided the ROOT files are NanoAOD simulation), loading in C++ scripts for use while looping over
the data frame, and grouping actions for easy manipulation.

In addition, TIMBER treats each step in the RDataFrame processing as a "node" and keeps track of these nodes as a larger tree. 
Each action (or group of actions) performed on a node produces another node and nodes store information about their parents or children. This makes it possible to write tools like `Nminus1()` which takes as input a node and a group of cuts to apply and returns N new nodes, each with every cut but one applied.

Finally, the RDataFrame for each node is always kept easily accessible so that any of the [native RDataFrame tools](https://root.cern/doc/master/classROOT_1_1RDataFrame.html) are at the user's fingertips.

## Sharing is caring
TIMBER includes a repository of common algorithms used frequently in CMS 
which access scale factors, calculate pileup weights, and more. These are all written 
in C++ for use in `Cut` and `Define` arguments and are provided so that users have a common tool box to share. 
Additionally, the AnalysisModules folder welcomes additions of custom C++ modules on a 
per-analysis basis so that the code can be properly archived for future reference and for sharing
with other analyzers.
