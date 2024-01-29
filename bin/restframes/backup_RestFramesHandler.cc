#include "include/RestFrames.hh"
#include <ROOT/RVec.hxx>
#include <iostream>

using namespace RestFrames;

class RestFramesHandler {
    private:
        std::string _outFile;
	// RestFrame stuff
	LabRecoFrame *LAB_R1;
	DecayRecoFrame *EE_R1;
	DecayRecoFrame *Ea_R1;
	DecayRecoFrame *Eb_R1;
	VisibleRecoFrame *Baa_R1;
        VisibleRecoFrame *Bab_R1;
        VisibleRecoFrame *TAUa_R1;
	VisibleRecoFrame *Bba_R1;
	InvisibleRecoFrame *Nba_R1;
	DecayRecoFrame *Tb_R1;
	VisibleRecoFrame *Bbb_R1;
	DecayRecoFrame *Wb_R1;
	VisibleRecoFrame *Lb_R1;
	InvisibleRecoFrame *Nbb_R1;
	// Groups
	InvisibleGroup *INV_R1;
	CombinatoricGroup *B_R1;
	CombinatoricGroup *TAU_R1;
	// Jigsaw
	SetMassInvJigsaw *NuNuM_R1;
	SetRapidityInvJigsaw *NuNuR_R1;
	MinMassesSqInvJigsaw *MinMt_R1;
	MinMassesCombJigsaw *MinBB_R1;
	MinMassesCombJigsaw *MinBBa_R1;
	MinMassesCombJigsaw *MinBBb_R1;
	MinMassesCombJigsaw *MinTauTau_R1;
    public:
        RestFramesHandler(std::string output_name);
        ~RestFramesHandler();
};

RestFramesHandler::RestFramesHandler(std::string output_name) { 
    _outFile = output_name;
    g_Log << LogInfo << "Instantiated RestFramesHandler..." << LogEnd;
    g_Log << LogInfo << "Will save to output file: " << _outFile << LogEnd;
    // lab reco
    LAB_R1 = new LabRecoFrame("LAB_R1","LAB");
    EE_R1 = new DecayRecoFrame("EE_R1", "E #bar{E}");
    LAB_R1->AddChildFrame(*EE_R1);
    // E particle production
    Ea_R1 = new DecayRecoFrame("Ea_R1", "E_{a}");
    Eb_R1 = new DecayRecoFrame("Eb_R1", "E_{b}");
    EE_R1->AddChildFrame(*Ea_R1);
    EE_R1->AddChildFrame(*Eb_R1);
    // E -> b b tau
    Baa_R1 = new VisibleRecoFrame("Baa_R1", "b_{a,a}");
    Bab_R1 = new VisibleRecoFrame("Bab_R1", "b_{a,b}");
    TAUa_R1 = new VisibleRecoFrame("TAUa_R1", "#tau_{a}");
    Ea_R1->AddChildFrame(*Baa_R1);
    Ea_R1->AddChildFrame(*Bab_R1);
    Ea_R1->AddChildFrame(*TAUa_R1);
    // E -> t b nu_tau
    Bba_R1 = new VisibleRecoFrame("Bba_R1", "b_{b,a}");
    Nba_R1 = new InvisibleRecoFrame("Nba_R1", "#nu_{b,a}");
    Tb_R1 = new DecayRecoFrame("Tb_R1", "t");
    Eb_R1->AddChildFrame(*Bba_R1);
    Eb_R1->AddChildFrame(*Nba_R1);
    Eb_R1->AddChildFrame(*Tb_R1);
    // t -> W b
    Bbb_R1 = new VisibleRecoFrame("Bbb_R1", "b_{b,b}");
    Wb_R1 = new DecayRecoFrame("Wb_R1", "W_{b}");
    Tb_R1->AddChildFrame(*Bbb_R1);
    Tb_R1->AddChildFrame(*Wb_R1);
    // W -> nu l
    Lb_R1 = new VisibleRecoFrame("Lb_R1", "#it{l}");
    Nbb_R1 = new InvisibleRecoFrame("Nbb_R1", "#nu_{b,b}");
    Wb_R1->AddChildFrame(*Lb_R1);
    Wb_R1->AddChildFrame(*Nbb_R1);

    // --------------------------------------------------------------------------
    if(LAB_R1->InitializeTree())
        g_Log << LogInfo << "...Successfully initialized reconstruction trees" << LogEnd;
    else
        g_Log << LogError << "...Failed initializing reconstruction trees" << LogEnd;
    // --------------------------------------------------------------------------

    // -------------------- Define Groups for reconstruction trees --------------
    std::string _groupName;

    // Invisible for neutrinos
    _groupName = "#splitline{#nu #nu Jigsaws for}{min M_{bb_a}^{2}+ M_{#tau #tau}^{2}}";
    INV_R1 = new InvisibleGroup("INV_R1", _groupName);
    INV_R1->AddFrame(*Nba_R1);
    INV_R1->AddFrame(*Nbb_R1);
    // Combinatoric Group for b's
    B_R1 = new CombinatoricGroup("VIS_R1","b-jet Jigsaws");
    B_R1->AddFrame(*Baa_R1);
    B_R1->AddFrame(*Bab_R1);
    B_R1->AddFrame(*Bba_R1);
    B_R1->AddFrame(*Bbb_R1);
    // b-jet frames must have at least one element
    B_R1->SetNElementsForFrame(*Baa_R1, 1);
    B_R1->SetNElementsForFrame(*Bab_R1, 1);
    B_R1->SetNElementsForFrame(*Bba_R1, 1);
    B_R1->SetNElementsForFrame(*Bbb_R1, 1);
    // Combinatoric group for tau's
    TAU_R1 = new CombinatoricGroup("TAU_R1","Tau Jigsaws");
    TAU_R1->AddFrame(*TAUa_R1);
    TAU_R1->AddFrame(*Lb_R1);
    TAU_R1->SetNElementsForFrame(*TAUa_R1, 1);
    TAU_R1->SetNElementsForFrame(*Lb_R1, 1);

    // -------------------- Define Jigsaws for reconstruction trees --------------
    std::string jigsaw_name;

    // Minimize sum Mt^2 jigsaws
    jigsaw_name = "M_{#nu#nu} = f(m_{ #{#tau#} } , m_{ #tau }^{ a} , m_{#tau}^{ b})";
    NuNuM_R1 = new SetMassInvJigsaw("NuNuM_R1", jigsaw_name);
    INV_R1->AddJigsaw(*NuNuM_R1);

    jigsaw_name = "#eta_{#nu#nu} = #eta_{#{b#}, #{tau#} }";
    NuNuR_R1 = new SetRapidityInvJigsaw("NuNuR_R1", jigsaw_name);
    INV_R1->AddJigsaw(*NuNuR_R1);
    NuNuR_R1->AddVisibleFrames(LAB_R1->GetListVisibleFrames());

    jigsaw_name = "min #Sigma M_{b_a}^{2} + M_{b_{ba}}^{2} + M_{#tau} ";
    MinMt_R1 = new MinMassesSqInvJigsaw("MinMt_R1", jigsaw_name, 2);
    INV_R1->AddJigsaw(*MinMt_R1);
    MinMt_R1->AddInvisibleFrame(*Nba_R1, 0);
    MinMt_R1->AddInvisibleFrame(*Nbb_R1, 1);
    MinMt_R1->AddVisibleFrames(*Lb_R1+*Bbb_R1, 0);
    MinMt_R1->AddVisibleFrames(*Bba_R1+*Baa_R1, 1);
    MinMt_R1->AddMassFrame(*Bbb_R1, 0);
    MinMt_R1->AddMassFrame(*Bba_R1, 1);

    jigsaw_name = "Minimize M(b) aa, ab, ba, bb";
    MinBB_R1 = new MinMassesCombJigsaw("MinBB_R1", jigsaw_name);
    B_R1->AddJigsaw(*MinBB_R1);
    MinBB_R1->AddFrame(*Baa_R1,0);
    MinBB_R1->AddFrame(*Bab_R1, 0);
    MinBB_R1->AddFrame(*Bba_R1, 1);
    MinBB_R1->AddFrame(*Bbb_R1, 1);

    jigsaw_name = "Minimize M(b) aa, ab";
    MinBBa_R1 = new MinMassesCombJigsaw("MinBBa_R1", jigsaw_name);
    B_R1->AddJigsaw(*MinBBa_R1);
    MinBBa_R1->AddFrame(*Baa_R1,0);
    MinBBa_R1->AddFrame(*Bab_R1,1);

    jigsaw_name = "Minimize M(b) ba, bb";
    MinBBb_R1 = new MinMassesCombJigsaw("MinBBb_R1", jigsaw_name);
    B_R1->AddJigsaw(*MinBBb_R1);
    MinBBb_R1->AddFrame(*Bba_R1,0);
    MinBBb_R1->AddFrame(*Bbb_R1,1);

    jigsaw_name = "Minimize M(#tau) a b";
    MinTauTau_R1 = new MinMassesCombJigsaw("MinTauTau_R1", jigsaw_name);
    TAU_R1->AddJigsaw(*MinTauTau_R1);
    MinTauTau_R1->AddFrame(*TAUa_R1,0);
    MinTauTau_R1->AddFrame(*Lb_R1,1);

    if(LAB_R1->InitializeAnalysis())
        g_Log << LogInfo << "...Successfully initialized analysis" << LogEnd;
    else
        g_Log << LogError << "...Failed initializing analysis" << LogEnd;

};

RestFramesHandler::~RestFramesHandler() {
    // rip
    delete LAB_R1;
    delete EE_R1;
    delete Ea_R1;
    delete Eb_R1;
    delete Baa_R1;
    delete Bab_R1;
    delete TAUa_R1;
    delete Bba_R1; 
    delete Nba_R1;
    delete Tb_R1;
    delete Bbb_R1;
    delete Wb_R1;
    delete Lb_R1;
    delete Nbb_R1;
    delete INV_R1;
    // Groups
    delete INV_R1;
    delete B_R1;
    delete TAU_R1;
    // Jigsaw
    delete NuNuM_R1;
    delete NuNuR_R1;
    delete MinMt_R1;
    delete MinBB_R1;
    delete MinBBa_R1;
    delete MinBBb_R1;
    delete MinTauTau_R1;
};


