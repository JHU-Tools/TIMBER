#!/usr/bin/env bash

# Set TIMBERPATH
export TIMBERPATH="$PWD/"
echo "TIMBERPATH set to $TIMBERPATH"
pip3 install -e .

# Build libtimber if not present
if [ ! -d "bin/libtimber" ]; then
  make
fi
