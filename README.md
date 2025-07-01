# TIMBER {#mainpage}
TIMBER (Tree Interface for Making Binned Events with RDataFrame) is an easy-to-use and fast python analysis framework used to quickly process CMS data sets. 
Default arguments assume the use of the NanoAOD format but any ROOT TTree can be processed.

## Installation instructions for python3

These instructions use python3 and CMSSW. The instructions below have been tested on el8 (lxplus and lpc).

```
cmsrel CMSSW_13_2_10
cd CMSSW_13_2_10
cmsenv
cd ..
python3 -m venv timber-env
git clone git@github.com:JHU-Tools/TIMBER.git
cd TIMBER/
mkdir bin
cd bin
git clone git@github.com:fmtlib/fmt.git
cd ../..
```

Boost library path (the boost version as well!) may change depending on the CMSSW version so this may need to be modified by hand. Testing to see if this wworks on lpc and lxplus el8/el9

Copy the whole multi-line string to the environment activation script

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
EOT
```

This will activate the python3 environment, set a proper LD_LIBRARY_PATH for boost libraries and build the TIMBER binaries

```
source timber-env/bin/activate
cd TIMBER
source setup_alternative.sh
```

Tip: Add the lines below to the top of `timber-env/bin/activate` script. With this, one can skip doing `cmsenv` every time after opening a new shell and just activate the environment instead.
```
cd CMSSW_13_2_10
cmsenv
cd ..
```