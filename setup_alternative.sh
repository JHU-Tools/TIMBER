#!/usr/bin/env bash

if [[ "$VIRTUAL_ENV" == "" ]]; then
  echo "ERROR: Create and activate a virtual environment and try again"
  return
fi

pip install -e .

# Add TIMBERPATH to activate script if not already there
activate_path=$VIRTUAL_ENV/bin/activate
TIMBERPATH="$PWD"

if ! grep -q "$TIMBERPATH" "$activate_path"; then
  echo "export TIMBERPATH=${TIMBERPATH}" >> "$activate_path"
  echo "Added TIMBERPATH to $activate_path"
fi

# Clone and build libarchive if not present
if [ ! -d "bin/libarchive" ]; then
  git clone -b v3.6.2 https://github.com/libarchive/libarchive.git
  cd libarchive
  cmake . -DCMAKE_INSTALL_PREFIX=../bin/libarchive
  make
  make install
  cd ..
  rm -rf libarchive
fi

# Build libtimber if not present
if [ ! -d "bin/libtimber" ]; then
  make
fi
