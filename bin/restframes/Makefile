CXX = g++
ROOTFLAGS = `root-config --glibs --libs`
CXXFLAGS = -I./src `root-config --cflags`

libdir = lib/

cdir = src/

SRCS = $(cdir)RFBase.cc  $(cdir)RFKey.cc  $(cdir)RFList.cc  $(cdir)RFLog.cc  $(cdir)RFPlot.cc  $(cdir)RFCharge.cc\
         $(cdir)TreePlot.cc  $(cdir)TreePlotNode.cc  $(cdir)TreePlotLink.cc\
         $(cdir)HistPlot.cc  $(cdir)HistPlotVar.cc  $(cdir)HistPlotCategory.cc\
         $(cdir)RestFrame.cc  $(cdir)ReconstructionFrame.cc  $(cdir)GeneratorFrame.cc\
         $(cdir)LabFrame.cc  $(cdir)DecayFrame.cc  $(cdir)VisibleFrame.cc  $(cdir)InvisibleFrame.cc\
         $(cdir)LabRecoFrame.cc  $(cdir)DecayRecoFrame.cc  $(cdir)VisibleRecoFrame.cc  $(cdir)InvisibleRecoFrame.cc\
         $(cdir)SelfAssemblingRecoFrame.cc\
         $(cdir)LabGenFrame.cc  $(cdir)DecayGenFrame.cc  $(cdir)VisibleGenFrame.cc  $(cdir)InvisibleGenFrame.cc\
         $(cdir)ResonanceGenFrame.cc  $(cdir)ppLabGenFrame.cc\
         $(cdir)State.cc  $(cdir)VisibleState.cc  $(cdir)InvisibleState.cc  $(cdir)CombinatoricState.cc\
         $(cdir)Group.cc  $(cdir)InvisibleGroup.cc  $(cdir)CombinatoricGroup.cc\
         $(cdir)Jigsaw.cc  $(cdir)InvisibleJigsaw.cc  $(cdir)CombinatoricJigsaw.cc\
         $(cdir)SetMassInvJigsaw.cc  $(cdir)SetRapidityInvJigsaw.cc  $(cdir)ContraBoostInvJigsaw.cc\
         $(cdir)CombinedCBInvJigsaw.cc  $(cdir)MinMassDiffInvJigsaw.cc  $(cdir)MinMassesSqInvJigsaw.cc\
         $(cdir)MaxProbBreitWignerInvJigsaw.cc\
         $(cdir)MinMassesCombJigsaw.cc $(cdir)MinMassChi2CombJigsaw.cc $(cdir)MaxProbBreitWignerCombJigsaw.cc\
         $(cdir)MinMassDiffCombJigsaw.cc $(cdir)MinMassesSqCombJigsaw.cc $(cdir)RestFramesHandler.cc \

incrf = include/

HDRS = $(incrf)RFKey.hh $(incrf)RFCharge.hh $(incrf)RFPlot.hh $(incrf)RFBase.hh $(incrf)RFLog.hh\
        $(incrf)RestFrame.hh $(incrf)ReconstructionFrame.hh $(incrf)GeneratorFrame.hh\
        $(incrf)LabFrame.hh $(incrf)DecayFrame.hh $(incrf)VisibleFrame.hh $(incrf)InvisibleFrame.hh\
        $(incrf)LabRecoFrame.hh $(incrf)DecayRecoFrame.hh $(incrf)VisibleRecoFrame.hh $(incrf)InvisibleRecoFrame.hh\
        $(incrf)SelfAssemblingRecoFrame.hh\
        $(incrf)LabGenFrame.hh $(incrf)DecayGenFrame.hh $(incrf)VisibleGenFrame.hh $(incrf)InvisibleGenFrame.hh\
        $(incrf)ResonanceGenFrame.hh $(incrf)ppLabGenFrame.hh\
        $(incrf)State.hh $(incrf)VisibleState.hh $(incrf)InvisibleState.hh $(incrf)CombinatoricState.hh\
        $(incrf)Group.hh $(incrf)InvisibleGroup.hh $(incrf)CombinatoricGroup.hh\
        $(incrf)Jigsaw.hh $(incrf)InvisibleJigsaw.hh $(incrf)CombinatoricJigsaw.hh\
        $(incrf)SetMassInvJigsaw.hh $(incrf)SetRapidityInvJigsaw.hh $(incrf)ContraBoostInvJigsaw.hh\
        $(incrf)CombinedCBInvJigsaw.hh $(incrf)MinMassDiffInvJigsaw.hh $(incrf)MinMassesSqInvJigsaw.hh\
        $(incrf)MaxProbBreitWignerInvJigsaw.hh\
        $(incrf)MinMassesCombJigsaw.hh $(incrf)MinMassChi2CombJigsaw.hh $(incrf)MaxProbBreitWignerCombJigsaw.hh\
        $(incrf)MinMassDiffCombJigsaw.hh $(incrf)MinMassesSqCombJigsaw.hh\
        $(incrf)TreePlot.hh $(incrf)TreePlotNode.hh $(incrf)TreePlotLink.hh\
        $(incrf)HistPlotVar.hh $(incrf)HistPlotCategory.hh $(incrf)HistPlot.hh $(incrf)RFList.hh $(incrf)RestFramesHandler.hh \

OBJS = $(SRCS:%.cc=%.o)

EXE = test_out

%.o : %.cc
	$(CXX) -fPIC $(CXXFLAGS) -c $*.cc -o $*.o $(ROOTFLAGS)

all : librestframes

librestframes : $(OBJS) | binlib
	$(CXX) -shared -fPIC -o $(libdir)librestframes.so $(OBJS)

depend : $(SRCS)
	$(CXX) $(CXXFLAGS) -M $(SRCS) $(ROOTFLAGS) > depend.mak

depend.mak :
	touch $@

binlib:
	mkdir -p $(libdir)

clean :
	rm -f *.o *.so $(libdir)*.so depend.mak $(cdir)*.o $(EXE)

include depend.mak
