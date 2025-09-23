# TIMBER
TIMBER (Tree Interface for Making Binned Events with RDataFrame) is an easy-to-use and fast python analysis framework used to quickly process CMS data sets. 
Default arguments assume the use of the NanoAOD format but any ROOT TTree can be processed.

## Installation instructions

This branch (`Run3_docker`) is specifically prepared for Docker-based workflows and pre-built images.  
It ensures all dependencies, including ROOT, Boost, libarchive, and TIMBER itself, are correctly installed without the need for local compilation.

### Pull the pre-built Docker image

```bash
docker pull mrogulji/timber:run3
docker run --rm -it -v /path/to/your/data:/work/data mrogulji/timber:run3 bash
```

- /path/to/your/data should point to your local data folder (bind mount).
- Inside the container, TIMBERPATH is already set, and libtimber is built.

### LPC example with singularity

```
APPTAINER_CACHEDIR=/tmp/apptainer_build_cache apptainer pull timber_run3.sif docker://mrogulji/timber:run3 #Build the .sif image
singularity shell  --bind `readlink $HOME` --bind `readlink -f ${HOME}/nobackup/` --bind /uscms_data --bind /cvmfs  timber_run3.sif #Open an interactive shell
singularity exec --bind `readlink $HOME`,`readlink -f ${HOME}/nobackup/`,/uscms_data,/cvmfs timber_run3.sif python3 $SCRIPT_PATH #Running a python script
singularity exec --bind `readlink $HOME`,`readlink -f ${HOME}/nobackup/`,/uscms_data,/cvmfs timber_run3.sif /bin/bash $SCRIPT_PATH #Running a shell script
```