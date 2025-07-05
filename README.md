# TIMBER {#mainpage}
TIMBER (Tree Interface for Making Binned Events with RDataFrame) is an easy-to-use and fast python analysis framework used to quickly process CMS data sets. 
Default arguments assume the use of the NanoAOD format but any ROOT TTree can be processed.

## Installation instructions for python3

These instructions use python3 and CMSSW. The instructions below have been tested on el8 and el9, both lxplus and lpc.

```
cmsrel CMSSW_13_2_10
cd CMSSW_13_2_10
cmsenv
cd ..
python3 -m virtualenv timber-env #If this step fails, you might need to do `python3 -m pip install --user virtualenv`
git clone git@github.com:JHU-Tools/TIMBER.git
cd TIMBER/
mkdir bin
cd bin
git clone git@github.com:fmtlib/fmt.git
cd ../..
```

Boost library path (the boost version as well!) may change depending on the CMSSW version so this may need to be modified by hand.

Copy the whole multi-line string to the environment activation script

```
cat <<EOT >> timber-env/bin/activate
export SCRAM_ARCH=${SCRAM_ARCH}
if [[ "\$SCRAM_ARCH" == "el8_amd64_gcc12" ]]; then
  BOOSTPATH=/cvmfs/cms.cern.ch/el8_amd64_gcc12/external/boost/1.78.0-26ff3be5a9865647d0222836b323286c/lib
elif [[ "\$SCRAM_ARCH" == "el9_amd64_gcc11" ]]; then
  BOOSTPATH=/cvmfs/cms.cern.ch/el9_amd64_gcc11/external/boost/1.78.0-c49033d06e1a3bf1beac1c01e1ef27d6/lib
else
  BOOSTPATH=/cvmfs/cms.cern.ch/el8_amd64_gcc10/external/boost/1.78.0-0d68c45b1e2660f9d21f29f6d0dbe0a0/lib
fi

if [[ ":\$LD_LIBRARY_PATH:" != *":\$BOOSTPATH:"* ]]; then
  export LD_LIBRARY_PATH="\${LD_LIBRARY_PATH:+\$LD_LIBRARY_PATH:}\$BOOSTPATH"
  echo "BOOSTPATH added to LD_LIBRARY_PATH"
else
  echo "BOOSTPATH already on LD_LIBRARY_PATH"
fi
EOT
```

This will activate the python3 environment, set a proper LD_LIBRARY_PATH for boost libraries and build the TIMBER binaries

```
source timber-env/bin/activate
cd TIMBER
source setup.sh
```

After installation, each new shell only requires `cmsenv` and `source timber-env/bin/activate`


Tip: Add the lines below to the top of `timber-env/bin/activate` script. With this, one can skip doing `cmsenv` every time after opening a new shell and just activate the environment instead.
```
cd CMSSW_13_2_10
cmsenv
cd ..
```