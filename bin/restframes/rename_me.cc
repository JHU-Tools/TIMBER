#include "include/RestFramesHandler.hh"

#include "TLorentzVector.h"
#include "TVector3.h"
#include "include/RestFrames.hh"
#include <ROOT/RVec.hxx>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <random>

using namespace RestFrames;
using namespace ROOT::VecOps;

class LQ_VALVAL_RestFrames_Handler : public RestFramesHandler {
    private:

        // Reconstruction frames
        std::unique_ptr<DecayRecoFrame> VFVF;
        std::unique_ptr<DecayRecoFrame> VFa;
        std::unique_ptr<DecayRecoFrame> VFb;
        std::unique_ptr<DecayRecoFrame> XIa;
        std::unique_ptr<DecayRecoFrame> XIb;

        std::unique_ptr<VisibleRecoFrame> TAUa;
        std::unique_ptr<VisibleRecoFrame> TAUb;
        std::unique_ptr<VisibleRecoFrame> JETaa;
        std::unique_ptr<VisibleRecoFrame> JETab;
        std::unique_ptr<VisibleRecoFrame> JETba;
        std::unique_ptr<VisibleRecoFrame> JETbb;

        // Groups
        std::unique_ptr<CombinatoricGroup> JETS;
        std::unique_ptr<CombinatoricGroup> TAUS;

        std::unique_ptr<CombinatoricGroup> XIs;
        
        // Jigsaw
        std::unique_ptr<MinMassesCombJigsaw> MinJJ;
        std::unique_ptr<MinMassesCombJigsaw> MinJJa;
        std::unique_ptr<MinMassesCombJigsaw> MinJJb;
        std::unique_ptr<MinMassesCombJigsaw> MinTauTau;

        std::unique_ptr<MinMassesCombJigsaw> MinXiXi;

        std::unique_ptr<MinMassesSqCombJigsaw> MinSqJJ;
        std::unique_ptr<MinMassesSqCombJigsaw> MinSqTauTau;

        void define_tree() override;
        void define_groups_jigsaws() override;

    public:
        LQ_VALVAL_RestFrames_Handler();
        std::tuple<float,float> calculate_mass(TLorentzVector &tau1, TLorentzVector &tau2, TLorentzVector &jet1, TLorentzVector &jet2, TLorentzVector &jet3, TLorentzVector &jet4);

};

LQ_VALVAL_RestFrames_Handler::LQ_VALVAL_RestFrames_Handler() {
    initialize();
};

void LQ_VALVAL_RestFrames_Handler::define_tree() {
    LAB.reset(new LabRecoFrame("LAB","LAB"));
    VFVF.reset(new DecayRecoFrame("VFVF", "#psi #bar{#psi}"));
    LAB->AddChildFrame(*VFVF);

    // VF particle production
    VFa.reset(new DecayRecoFrame("VFa", "#psi_{a}"));
    VFb.reset(new DecayRecoFrame("VFb", "#psi_{b}"));
    VFVF->AddChildFrame(*VFa);
    VFVF->AddChildFrame(*VFb);
    // VF -> xi c
    JETaa.reset(new VisibleRecoFrame("JETaa", "q_{a,a}"));
    XIa.reset(new DecayRecoFrame("XIa","#xi_{a}"));
    VFa->AddChildFrame(*JETaa);
    VFa->AddChildFrame(*XIa);

    JETba.reset(new VisibleRecoFrame("JETba", "q_{b,a}"));
    XIb.reset(new DecayRecoFrame("XIb","#xi_{b}"));
    VFb->AddChildFrame(*JETba);
    VFb->AddChildFrame(*XIb);
    
    // xi -> tau s
    TAUa.reset(new VisibleRecoFrame("TAUa", "#tau_{a}"));
    JETab.reset(new VisibleRecoFrame("JETab", "q_{a,b}"));
    XIa->AddChildFrame(*TAUa);
    XIa->AddChildFrame(*JETab);

    TAUb.reset(new VisibleRecoFrame("TAUb", "#tau_{b}"));
    JETbb.reset(new VisibleRecoFrame("JETbb", "q_{b,b}"));
    XIb->AddChildFrame(*TAUb);
    XIb->AddChildFrame(*JETbb);
}

void LQ_VALVAL_RestFrames_Handler::define_groups_jigsaws() {
    // Combinatoric Group for jets
    JETS.reset(new CombinatoricGroup("JETS", "jet jigsaws"));
    JETS->AddFrame(*JETaa);
    JETS->AddFrame(*JETab);
    JETS->AddFrame(*JETba);
    JETS->AddFrame(*JETbb);

    // jet frames must have at least one element
    JETS->SetNElementsForFrame(*JETaa, 1);
    JETS->SetNElementsForFrame(*JETab, 1);
    JETS->SetNElementsForFrame(*JETba, 1);
    JETS->SetNElementsForFrame(*JETbb, 1);

    // Combinatoric group for tau's
    TAUS.reset(new CombinatoricGroup("TAU_SR1","Tau Jigsaws"));
    TAUS->AddFrame(*TAUa);
    TAUS->AddFrame(*TAUb);

    // Require 1 element for each tau
    TAUS->SetNElementsForFrame(*TAUa, 1);
    TAUS->SetNElementsForFrame(*TAUb, 1);

    // Combinatoric group for xi's
    XIs.reset(new CombinatoricGroup("XI","Xi Jigsaws"));
    XIs->AddFrame(*XIa);
    XIs->AddFrame(*XIb);

    // Require 1 element for each tau
    XIs->SetNElementsForFrame(*XIa, 1);
    XIs->SetNElementsForFrame(*XIb, 1);
    

    // -------------------- Define Jigsaws for reconstruction trees --------------
    std::string jigsaw_name;

    MinSqTauTau.reset(new MinMassesSqCombJigsaw("MinDiffTauTau", jigsaw_name, 2, 4));
    TAUS->AddJigsaw(*MinSqTauTau);
    MinSqTauTau->AddCombFrame(*TAUa, 0);
    MinSqTauTau->AddCombFrame(*TAUb, 1);
    MinSqTauTau->AddObjectFrame(*JETaa,0);
    MinSqTauTau->AddObjectFrame(*JETab,1);
    MinSqTauTau->AddObjectFrame(*JETba,2);
    MinSqTauTau->AddObjectFrame(*JETbb,3);


    jigsaw_name = "Minimize Masses of Jets aa, ab, ba, bb";
    MinJJ.reset(new MinMassesCombJigsaw("MinJET", jigsaw_name));
    JETS->AddJigsaw(*MinJJ);
    MinJJ->AddFrame(*JETaa,0);
    MinJJ->AddFrame(*JETab, 0);
    MinJJ->AddFrame(*JETba, 1);
    MinJJ->AddFrame(*JETbb, 1);
    // MinSqJJ.reset(new MinMassesSqCombJigsaw("MinDiffJJ", jigsaw_name, 2, 4));
    // JETS->AddJigsaw(*MinSqJJ);
    // MinSqJJ->AddCombFrame(*JETaa, 0);
    // MinSqJJ->AddCombFrame(*JETab, 0);
    // MinSqJJ->AddCombFrame(*JETba, 1);
    // MinSqJJ->AddCombFrame(*JETbb,1);

    // MinSqJJ->AddObjectFrame(*JET,0);
    // MinSqJJ->AddObjectFrame(*TAUb,1);

    jigsaw_name = "Minimize Mass of jets aa, ab";
    MinJJa.reset(new MinMassesCombJigsaw("MinJETa", jigsaw_name));
    JETS->AddJigsaw(*MinJJa);
    MinJJa->AddFrame(*JETaa,0);
    MinJJa->AddFrame(*JETab,1);

    jigsaw_name = "Minimize Mass of jets ba, bb";
    MinJJb.reset(new MinMassesCombJigsaw("MinJETb", jigsaw_name));
    JETS->AddJigsaw(*MinJJb);
    MinJJb->AddFrame(*JETba,0);
    MinJJb->AddFrame(*JETbb,1);


    // jigsaw_name = "Minimize M(#tau) a b";
    // MinTauTau.reset(new MinMassesCombJigsaw("MinTauTau", jigsaw_name));
    // TAUS->AddJigsaw(*MinTauTau);
    // MinTauTau->AddFrame(*TAUa,0);
    // MinTauTau->AddFrame(*TAUb,1);

    jigsaw_name = "Minimize M(#xi) a b";
    MinXiXi.reset(new MinMassesCombJigsaw("MinXiXi", jigsaw_name));
    XIs->AddJigsaw(*MinXiXi);
    MinXiXi->AddFrame(*XIa,0);
    MinXiXi->AddFrame(*XIb,1);
};

std::tuple<float, float> LQ_VALVAL_RestFrames_Handler::calculate_mass(TLorentzVector &tau1, TLorentzVector &tau2, TLorentzVector &jet1, TLorentzVector &jet2, TLorentzVector &jet3, TLorentzVector &jet4) {
    before_analysis();
    
    TAUS->AddLabFrameFourVector(tau1);
    TAUS->AddLabFrameFourVector(tau2);

    std::vector<RFKey> JETS_ID; // ID for tracking jets in tree
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet4));
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet3));
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet1));
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet2));

    LAB->AnalyzeEvent(); // analyze the event

    double calc_mass_VF_a = VFa->GetFourVector(*LAB).M();
    double calc_mass_VF_b = VFb->GetFourVector(*LAB).M();

    after_analysis();

    std::default_random_engine generator;
    std::bernoulli_distribution dist(0.5);
    bool which = dist(generator);

    if (which) return std::make_tuple(calc_mass_VF_b, calc_mass_VF_a);
    return std::make_tuple(calc_mass_VF_a, calc_mass_VF_b);
};

class LQ_VALVAL_RestFrames_Container : public RestFramesContainer {
    public:
        LQ_VALVAL_RestFrames_Container(int num_threads);
        RestFramesHandler *create_handler() override;

        RVec<float> compute_mass(int thread_index, RVec<float> tau_pt, RVec<float> tau_eta, RVec<float> tau_phi, RVec<float> tau_mass, RVec<float> jet_pt, RVec<float> jet_eta, RVec<float> jet_phi, RVec<float> jet_mass);
};

LQ_VALVAL_RestFrames_Container::LQ_VALVAL_RestFrames_Container (int num_threads) : RestFramesContainer(num_threads){
    initialize();
};

RestFramesHandler * LQ_VALVAL_RestFrames_Container::create_handler() {
    return new LQ_VALVAL_RestFrames_Handler;
}


RVec<float> LQ_VALVAL_RestFrames_Container::compute_mass(int thread_index, RVec<float> tau_pt, RVec<float> tau_eta, RVec<float> tau_phi, RVec<float> tau_mass, RVec<float> jet_pt, RVec<float> jet_eta, RVec<float> jet_phi, RVec<float> jet_mass) {

    // This pointer should explicitly not be deleted!
    LQ_VALVAL_RestFrames_Handler *rfh = static_cast<LQ_VALVAL_RestFrames_Handler *>(get_handler(thread_index));

    TLorentzVector jet_1;
    TLorentzVector jet_2;
    TLorentzVector jet_3;
    TLorentzVector jet_4;

    TLorentzVector tau_1;
    TLorentzVector tau_2;

    tau_1.SetPtEtaPhiM(tau_pt[0], tau_eta[0], tau_phi[0], tau_mass[0]);
    tau_2.SetPtEtaPhiM(tau_pt[1], tau_eta[1], tau_phi[1], tau_mass[1]);

    jet_1.SetPtEtaPhiM(jet_pt[0], jet_eta[0], jet_phi[0], jet_mass[0]);
    jet_2.SetPtEtaPhiM(jet_pt[1], jet_eta[1], jet_phi[1], jet_mass[1]);
    jet_3.SetPtEtaPhiM(jet_pt[2], jet_eta[2], jet_phi[2], jet_mass[2]);
    jet_4.SetPtEtaPhiM(jet_pt[3], jet_eta[3], jet_phi[3], jet_mass[3]);

    std::tuple<float, float> masses = rfh->calculate_mass(tau_1, tau_2, jet_1, jet_2, jet_3, jet_4);

    RVec<float> mass_vec;

    mass_vec.push_back(std::get<0>(masses));
    mass_vec.push_back(std::get<1>(masses));

    return mass_vec;
}