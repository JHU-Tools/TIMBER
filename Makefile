SOURCE_DIR=TIMBER/Framework/src/
HEADER_DIR=TIMBER/Framework/include/
EXT_DIR=TIMBER/Framework/ext/
BIN_DIR=bin/libtimber/
FMT_DIR=bin/fmt/include/

CC=gcc
INCLUDE=-I/usr/include/ -I bin/ -I./ `root-config --cflags --ldflags --glibs` -I/usr/include/ -I$(EXT_DIR) -I$(FMT_DIR)

LIBS=-lstdc++ -lboost_wserialization -lboost_filesystem -L bin/libarchive/lib/ -Wl,-rpath=bin/libarchive/lib/ -larchive

CFLAGS=-g -Wno-attributes -fPIC -c

CVMFS=/cvmfs/cms.cern.ch/$(SCRAM_ARCH)/cms/cmssw/$(CMSSW_VERSION)

# Define BOOST_BASE depending on SCRAM_ARCH
ifeq ($(SCRAM_ARCH),el8_amd64_gcc12)
  BOOST_BASE=/cvmfs/cms.cern.ch/el8_amd64_gcc12/external/boost/1.78.0-26ff3be5a9865647d0222836b323286c
else ifeq ($(SCRAM_ARCH),el9_amd64_gcc11)
  BOOST_BASE=/cvmfs/cms.cern.ch/el9_amd64_gcc11/external/boost/1.78.0-c49033d06e1a3bf1beac1c01e1ef27d6
else
  BOOST_BASE=/cvmfs/cms.cern.ch/$(SCRAM_ARCH)/external/boost/1.78.0-0d68c45b1e2660f9d21f29f6d0dbe0a0
endif

CMSSW=-I$(CVMFS)/src -I$(BOOST_BASE)/include -L$(BOOST_BASE)/lib -L$(CVMFS)/lib/$(SCRAM_ARCH)

CPP_FILES=$(wildcard $(SOURCE_DIR)*.cc $(EXT_DIR)*.cpp  $(EXT_DIR)*.cc)
HEADERS=$(CPP_FILES:$(SOURCE_DIR)%.cc=$(HEADER_DIR)%.h)

JME_FILES=JetSmearer.cc JetRecalibrator.cc JMR_weight.cc JER_weight.cc JES_weight.cc JMS_weight.cc JME_common.cc
JME_FILES:=$(JME_FILES:%.cc=$(SOURCE_DIR)%.cc)
ifndef CMSSW_VERSION
	CPP_FILES:=$(filter-out $(JME_FILES), $(CPP_FILES))
else
	CMSSW:=$(CMSSW) -lCondFormatsJetMETObjects -lJetMETCorrectionsModules
endif

O_FILES=$(CPP_FILES:$(SOURCE_DIR)%.cc=$(BIN_DIR)%.o)

.PHONY: all clean
.DEFAULT: all

all: libtimber

libtimber: $(O_FILES)
	$(CC) -fPIC -shared $(CMSSW) $(INCLUDE) $(LIBS) -o $(BIN_DIR)libtimber.so $(O_FILES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: $(SOURCE_DIR)%.cc | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CMSSW) $(INCLUDE) $(LIBS) $< -o $@

clean:
	- rm -rf $(BIN_DIR)
