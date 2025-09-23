SOURCE_DIR=TIMBER/Framework/src/
HEADER_DIR=TIMBER/Framework/include/
EXT_DIR=TIMBER/Framework/ext/
BIN_DIR=bin/libtimber/
CORR_DIR=/usr/local/lib64/python3.9/site-packages/correctionlib/include/

CC=gcc
INCLUDE=-I/usr/include/ -I bin/ -I./ `root-config --cflags --ldflags --glibs` -I$(EXT_DIR) -I$(CORR_DIR)

LIBS=-lstdc++ -lboost_wserialization -lboost_filesystem -larchive

CFLAGS=-g -Wno-attributes -fPIC -c

CPP_FILES=$(wildcard $(SOURCE_DIR)*.cc $(EXT_DIR)*.cpp  $(EXT_DIR)*.cc)
HEADERS=$(CPP_FILES:$(SOURCE_DIR)%.cc=$(HEADER_DIR)%.h)

JME_FILES=JER_correctionlib_weight.cc JES_correctionlib_weight.cc JERC_JetVeto.cc
JME_FILES:=$(JME_FILES:%.cc=$(SOURCE_DIR)%.cc)

O_FILES=$(CPP_FILES:$(SOURCE_DIR)%.cc=$(BIN_DIR)%.o)

.PHONY: all clean
.DEFAULT: all

all: libtimber

libtimber: $(O_FILES)
	$(CC) -fPIC -shared $(INCLUDE) $(LIBS) -o $(BIN_DIR)libtimber.so $(O_FILES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: $(SOURCE_DIR)%.cc | $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	- rm -rf $(BIN_DIR)
