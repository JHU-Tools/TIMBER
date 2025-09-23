# Start from ROOT official image
FROM rootproject/root:6.30.02-alma9

# Install system dependencies
RUN dnf install -y \
    boost-devel \
    fmt-devel \
    libarchive-devel \
    python3-pip \
    && dnf clean all

RUN python3 -m pip install --upgrade pip setuptools wheel
RUN python3 -m pip install correctionlib
WORKDIR /work
RUN git clone --branch Run3_docker https://github.com/JHU-Tools/TIMBER.git
WORKDIR /work/TIMBER
# Set TIMBERPATH
ENV TIMBERPATH=/work/TIMBER/
# Install Python dependencies from pyproject.toml
RUN pip3 install -e .
# Build libtimber
RUN chmod +x ./setup.sh
RUN ./setup.sh
