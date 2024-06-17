#include "include/RestFramesHandler.hh"

#include "TLorentzVector.h"
#include "TVector3.h"
#include "include/RestFrames.hh"
#include <ROOT/RVec.hxx>
#include <algorithm>
#include <iostream>
#include <array> //TODO think about replacing std::array<float, 4> with RVec<float>?
#include <memory>
#include <mutex>
#include <random>

using namespace RestFrames;
using namespace ROOT::VecOps;

class Tprime_RestFrames_Handler : public RestFramesHandler {
    private:

        // Reconstruction frames
        std::unique_ptr<DecayRecoFrame> TTbar;
        std::unique_ptr<DecayRecoFrame> T;
        std::unique_ptr<VisibleRecoFrame> Tbar;
        
	std::unique_ptr<DecayRecoFrame> W;
        std::unique_ptr<VisibleRecoFrame> b;
        //std::unique_ptr<VisibleRecoFrame> J0;
        //std::unique_ptr<VisibleRecoFrame> J1;

        std::unique_ptr<VisibleRecoFrame> l;
        std::unique_ptr<InvisibleRecoFrame> nu;

        // Groups
        std::unique_ptr<CombinatoricGroup> JETS;

        std::unique_ptr<InvisibleGroup> INV;
        
        // Jigsaws
	std::unique_ptr<SetMassInvJigsaw> NuM;
	std::unique_ptr<SetRapidityInvJigsaw> NuR;

	std::unique_ptr<MinMassChi2CombJigsaw> MinChi2;

        void define_tree() override;
	void define_groups_jigsaws() override;

    public:
        Tprime_RestFrames_Handler();
        std::array<double, 4> calculate_mass(TLorentzVector &lepton, TVector3 &met3, TLorentzVector &jet1, TLorentzVector &jet2, TLorentzVector &jet3); //, TLorentzVector &jet4);
	//std::tuple<float,float>
};

Tprime_RestFrames_Handler::Tprime_RestFrames_Handler() {
    initialize();
};

void Tprime_RestFrames_Handler::define_tree() {
    LAB.reset(new LabRecoFrame("LAB","LAB"));
    TTbar.reset(new DecayRecoFrame("TTbar", "T#bar{T}"));
    LAB->AddChildFrame(*TTbar);

    // Vector Like T quark particle production
    T.reset(new DecayRecoFrame("T", "T"));
    Tbar.reset(new VisibleRecoFrame("Tbar", "#bar{T}"));
    TTbar->AddChildFrame(*T);
    TTbar->AddChildFrame(*Tbar);
    // T -> W b
    W.reset(new DecayRecoFrame("W","W"));
    b.reset(new VisibleRecoFrame("b", "b"));
    T->AddChildFrame(*W);
    T->AddChildFrame(*b);

/*    J1.reset(new VisibleRecoFrame("J1", "J1_{AK8}"));
    J0.reset(new VisibleRecoFrame("J0","J0_{AK8}"));
    Tbar->AddChildFrame(*J1);
    Tbar->AddChildFrame(*J0);	*/
    
    // W -> l nu
    l.reset(new VisibleRecoFrame("l", "#it{l}"));
    nu.reset(new InvisibleRecoFrame("nu", "#nu"));
    W->AddChildFrame(*l);
    W->AddChildFrame(*nu);
}

void Tprime_RestFrames_Handler::define_groups_jigsaws() {
    // Combinatoric Group for jets
    JETS.reset(new CombinatoricGroup("JETS", "Jet Jigsaws"));
    JETS->AddFrame(*b);
    JETS->AddFrame(*Tbar);
    //JETS->AddFrame(*J1);
    //JETS->AddFrame(*J0);

    // jet frames must have at least one element
    JETS->SetNElementsForFrame(*b, 1);
    JETS->SetNElementsForFrame(*Tbar, 2);
    //JETS->SetNElementsForFrame(*J1, 1);
    //JETS->SetNElementsForFrame(*J0, 1);
    
    // Invisible Group for Neutrino
    INV.reset(new InvisibleGroup("INV", "MET Jigsaws"));
    INV->AddFrame(*nu);

    // -------------------- Define Jigsaws for reconstruction trees --------------
    std::string jigsaw_name;

    // 1 Minimize equal (vector) top masses neutrino jigsaws
    jigsaw_name = "M_{#nu} = f(m_{b#it{l}J_{0}J_{1}} , m_{b#it{l}} , m_{J_{0}J_{1}})";
    NuM.reset(new SetMassInvJigsaw("NuM", jigsaw_name));
    INV->AddJigsaw(*NuM); 
    
    // 2 
    jigsaw_name = "#eta_{#nu} = #eta_{b #it{l} Tbar}";
    NuR.reset(new SetRapidityInvJigsaw("NuR", jigsaw_name));
    INV->AddJigsaw(*NuR);
    NuR->AddVisibleFrame(*l); 
    NuR->AddVisibleFrame(*b); 
    NuR->AddVisibleFrame(*Tbar); 
    //+*b+*Tbar);	//TODO not sure about this line

    // 4 Combinatoric Jigsaws 
    // MinMassesSqCombJigsaw worked but same problem as MinMassesCombJigsaw
    // MinMassDiffCombJigsaw Initialized Analysis but fell into some infinite loop
    // MinMassChi2ComJigsaw works very well
    jigsaw_name = "Minimize Chi^2";
    MinChi2.reset(new MinMassChi2CombJigsaw("MinChi2", jigsaw_name, 2, 2));
    JETS->AddJigsaw(*MinChi2);
    MinChi2->AddObjectFrame(*l, 0);
    MinChi2->AddObjectFrame(*b, 0);
    MinChi2->AddCombFrame(*b, 0);
    MinChi2->AddObjectFrame(*Tbar, 1);
    MinChi2->AddCombFrame(*Tbar, 1);
    MinChi2->SetMass(1435, 0);
    MinChi2->SetSigma(205.2, 0);
    MinChi2->SetMass(1456, 1);
    MinChi2->SetSigma(173.2, 1); 

    /*--------------------jigsaw_name = "Minimize Masses of Jets b, J0, J1";
    MinJJ.reset(new MinMassesCombJigsaw("MinJET", jigsaw_name));
    JETS->AddJigsaw(*MinJJ);
    MinJJ->AddFrame(*b,0);
    MinJJ->AddFrame(*J1, 1);
    MinJJ->AddFrame(*J0, 1);
    // MinSqJJ.reset(new MinMassesSqCombJigsaw("MinDiffJJ", jigsaw_name, 2, 4));
    // A
    // JETS->AddJigsaw(*MinSqJJ);
    // MinSqJJ->AddCombFrame(*b, 0);
    // MinSqJJ->AddCombFrame(*J1, 1);
    // MinSqJJ->AddCombFrame(*JETbb,1);

    // MinSqJJ->AddObjectFrame(*JET,0);
    // MinSqJJ->AddObjectFrame(*TAUb,1);

    jigsaw_name = "Minimize Mass of jets aa, ab";
    MinJJa.reset(new MinMassesCombJigsaw("MinJETa", jigsaw_name));
    JETS->AddJigsaw(*MinJJa);
    MinJJa->AddFrame(*b,0);

    jigsaw_name = "Minimize Mass of jets ba, bb";
    MinJJb.reset(new MinMassesCombJigsaw("MinJETb", jigsaw_name));
    JETS->AddJigsaw(*MinJJb);
    MinJJb->AddFrame(*J1,0);
    MinJJb->AddFrame(*JETbb,1);
    */

    // jigsaw_name = "Minimize M(#tau) a b";
    // MinTauTau.reset(new MinMassesCombJigsaw("MinTauTau", jigsaw_name));
    // TAUS->AddJigsaw(*MinTauTau);
    // MinTauTau->AddFrame(*l,0);
    // MinTauTau->AddFrame(*TAUb,1);
};

std::array<double, 4> Tprime_RestFrames_Handler::calculate_mass(TLorentzVector &lepton, TVector3 &met3, TLorentzVector &jet1, TLorentzVector &jet2, TLorentzVector &jet3) { //, TLorentzVector &jet4) {
    before_analysis();
    
    INV->SetLabFrameThreeVector(met3);	
    l->SetLabFrameFourVector(lepton);
    //TAUS->AddLabFrameFourVector(tau1);
    //TAUS->AddLabFrameFourVector(tau2);

    std::vector<RFKey> JETS_ID; // ID for tracking jets in tree
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet3));
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet1));
    JETS_ID.push_back(JETS->AddLabFrameFourVector(jet2));
    //JETS_ID.push_back(JETS->AddLabFrameFourVector(jet4));
    //b->SetLabFrameFourVector(jet4));

    LAB->AnalyzeEvent(); // analyze the event

    double calc_mass_T = T->GetFourVector(*LAB).M();
    double calc_mass_Tbar = Tbar->GetFourVector(*LAB).M();
    double T_mass = T->GetMass();
    double Tbar_mass = Tbar->GetMass();

    std::array<double, 4> result = {calc_mass_T, calc_mass_Tbar, T_mass, Tbar_mass};

    after_analysis();

    /*std::default_random_engine generator;
    std::bernoulli_distribution dist(0.5);
    bool which = dist(generator);
    
    if (which) return std::make_tuple(calc_mass_Tbar, calc_mass_T); */
    return result; //std::make_tuple(calc_mass_T, calc_mass_Tbar);
};

class Tprime_RestFrames_Container : public RestFramesContainer {
    public:
        Tprime_RestFrames_Container(int num_threads);
        RestFramesHandler *create_handler() override;

        RVec<float> compute_mass(int thread_index, float lepton_pt, float lepton_eta, float lepton_phi, float lepton_mass, RVec<float> jet_pt, RVec<float> jet_eta, RVec<float> jet_phi, RVec<float> jet_mass, float met_pt, float met_phi);
};

Tprime_RestFrames_Container::Tprime_RestFrames_Container (int num_threads) : RestFramesContainer(num_threads){
    initialize();
};

RestFramesHandler * Tprime_RestFrames_Container::create_handler() {
    return new Tprime_RestFrames_Handler;
}


RVec<float> Tprime_RestFrames_Container::compute_mass(int thread_index, float lepton_pt, float lepton_eta, float lepton_phi, float lepton_mass, RVec<float> jet_pt, RVec<float> jet_eta, RVec<float> jet_phi, RVec<float> jet_mass, float met_pt, float met_phi) {

    // This pointer should explicitly not be deleted!
    Tprime_RestFrames_Handler *rfh = static_cast<Tprime_RestFrames_Handler *>(get_handler(thread_index));

    TLorentzVector jet_1;
    TLorentzVector jet_2;
    TLorentzVector jet_3;
  //  TLorentzVector jet_4;

    TLorentzVector lepton;

    TVector3 met3;
    
    lepton.SetPtEtaPhiM(lepton_pt, lepton_eta, lepton_phi, lepton_mass);  //TODO in the future we want to make sure the muon/lepton is good enough
    //lepton.SetPtEtaPhiM(lepton_pt[0], lepton_eta[0], lepton_phi[0], lepton_mass[0]);  //TODO in the future we want to make sure the muon/lepton is good enough

    jet_1.SetPtEtaPhiM(jet_pt[0], jet_eta[0], jet_phi[0], jet_mass[0]);
    jet_2.SetPtEtaPhiM(jet_pt[1], jet_eta[1], jet_phi[1], jet_mass[1]);
    jet_3.SetPtEtaPhiM(jet_pt[2], jet_eta[2], jet_phi[2], jet_mass[2]);
//    jet_4.SetPtEtaPhiM(jet_pt[3], jet_eta[3], jet_phi[3], jet_mass[3]);
    
    double MET_px  = met_pt*std::cos(met_phi);
    double MET_py  = met_pt*std::sin(met_phi);
    met3  = TVector3(MET_px, MET_py, 0.0);
    //std::tuple<float, float> masses = rfh->calculate_mass(lepton, met3, jet_1, jet_2, jet_3); //, jet_4);
    std::array<double, 4> masses = rfh->calculate_mass(lepton, met3, jet_1, jet_2, jet_3); //, jet_4);

    RVec<float> mass_vec;

    mass_vec.push_back(masses[0]);
    mass_vec.push_back(masses[1]);
    mass_vec.push_back(masses[2]);
    mass_vec.push_back(masses[3]);

    /*mass_vec.push_back(std::get<0>(masses));
    mass_vec.push_back(std::get<1>(masses)); */

    return mass_vec;
}
