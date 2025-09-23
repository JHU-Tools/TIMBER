#!/usr/bin/env bash
set -e

# Install TIMBER in editable mode
pip3 install -e .

# Build libtimber if not present
if [ ! -d "bin/libtimber" ]; then
  make
fi