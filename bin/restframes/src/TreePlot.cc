/////////////////////////////////////////////////////////////////////////
//   RestFrames: particle physics event analysis library
//   --------------------------------------------------------------------
//   Copyright (c) 2014-2016, Christopher Rogan
/////////////////////////////////////////////////////////////////////////
///
///  \file   TreePlot.cc
///
///  \author Christopher Rogan
///          (crogan@cern.ch)
///
///  \date   2015 July
///
//   This file is part of RestFrames.
//
//   RestFrames is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
// 
//   RestFrames is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// 
//   You should have received a copy of the GNU General Public License
//   along with RestFrames. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////

#include "TArc.h"
#include "TLine.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"

#include "../include/TreePlot.hh"
#include "../include/TreePlotNode.hh"
#include "../include/TreePlotLink.hh"
#include "../include/Jigsaw.hh"
#include "../include/State.hh"
#include "../include/CombinatoricGroup.hh"
#include "../include/DecayRecoFrame.hh"
#include "../include/VisibleRecoFrame.hh"
#include "../include/InvisibleRecoFrame.hh"

namespace RestFrames {

  using std::string;
  using std::vector;
  using std::map;
  using std::max;
  using std::min;

  ///////////////////////////////////////////////
  // TreePlot class methods
  // class which can plot RestFrame trees
  ///////////////////////////////////////////////
  TreePlot::TreePlot(const std::string& sname, 
		     const std::string& stitle)
    : RFPlot(sname, stitle){
    m_Type = kVanillaTree;
    m_GroupPtr = nullptr;
    m_CanvasPtr = nullptr;
    m_Log.SetSource("TreePlot "+GetName());
  }
  
  TreePlot::~TreePlot(){
    ClearTree();
  }

  void TreePlot::Clear(){
    ClearTree();
    RFPlot::Clear();
  }

  void TreePlot::ClearTree(){
    int Ntreenode = m_TreeNodes.size();
    for(int i = 0; i < Ntreenode; i++){
      delete m_TreeNodes[i];
    }
    m_TreeNodes.clear();
    
    int Ntreelink = m_TreeLinks.size();
    for(int i = 0; i < Ntreelink; i++){
      delete m_TreeLinks[i];
    }
    m_TreeLinks.clear();
    
    int Nleaflink = m_LeafLinks.size();
    for(int i = 0; i < Nleaflink; i++){
      delete m_LeafLinks[i];
    }
    m_LeafLinks.clear();

    m_Frames.Clear();
    m_Jigsaws.Clear();
    m_GroupPtr = nullptr;
    m_Type = kVanillaTree;

    m_SelfAssembling = false;

    m_JigsawColorMap.clear();
    m_FrameColorMap.clear();
  }

  TCanvas* TreePlot::GetNewCanvas(const std::string& name, 
				  const std::string& title){
    std::string sname, stitle;
    if(name == ""){
      char strn[10];
      sprintf(strn,"%d",GetNCanvases()+1);
      sname = GetName()+std::string(strn);
    } else {
      sname = name;
    }
    if(title == "")
      stitle = GetTitle();
    else 
      stitle = title;
    
    sname = GetUniqueName(sname);
    TCanvas* can = new TCanvas(sname.c_str(),stitle.c_str(),600,600);
    can->Range(0.,0.,1.,1.);
    return can;
  }
  
  void TreePlot::Draw(const std::string& name, const std::string& title,
		      bool invert_bkg_color,
		      bool invert_node_color){
    if(m_Type == kVanillaTree) 
      return;

    SetColors(invert_bkg_color,
	      invert_node_color);
    
    m_CanvasPtr = GetNewCanvas(name,title);
    
    if(m_Type == kFrameTree){
      bool do_jigsaws = (m_Jigsaws.GetN() > 0);
      DrawTreeLinks();
      if(do_jigsaws) DrawTreeNodes(true);
      if(do_jigsaws) DrawLeafLinks();
      DrawTreeNodes();
      DrawFrameTypeLegend();
      if(do_jigsaws) DrawJigsawLegend();
    }
    
    if(m_Type == kGroupTree){
      DrawTreeLinks();
      DrawTreeNodes();
      DrawTitle(m_GroupPtr->GetTitle());
    }
 
    m_CanvasPtr->Draw();
    m_CanvasPtr->SetFillColor(m_color_Bkg);
    m_CanvasPtr->Modified();
    AddCanvas(m_CanvasPtr);
  }

  void TreePlot::SetTree(const RestFrame& frame){
    if(!frame) return;
    ClearTree();
    m_Type = kFrameTree;

    FillFrameTree(frame);
    InitTreeGrid();
    ConvertNodeCoordinates(m_TreeNodes);
  }

  void TreePlot::AddJigsaw(const Jigsaw& jigsaw){
    if(m_Type != kFrameTree) 
      return;
    if(!jigsaw) 
      return;
    if(m_Jigsaws.Contains(jigsaw))
      return;
    if(!m_Frames.Contains(jigsaw.GetParentFrames()))
      return;
    
    FillJigsawLink(jigsaw);
    m_JigsawColorMap[&jigsaw] = int(m_JigsawColorMap.size());
    m_Jigsaws.Add(jigsaw);
  }

  void TreePlot::SetTree(const Group& group){
    if(!group) return;
    if(!group.IsSoundMind()) return;
    ClearTree();
    m_GroupPtr = &group;
    m_Type = kGroupTree;

    FillGroupTree(group);
    InitTreeGrid();
    ConvertNodeCoordinates(m_TreeNodes);
  }

  void TreePlot::SetTree(const Jigsaw& jigsaw){
    if(!jigsaw) return;
    if(!jigsaw.IsSoundMind()) return;
    ClearTree();
    m_GroupPtr = &jigsaw.GetGroup();
    m_Type = kGroupTree;

    FillJigsawTree(jigsaw);
    InitTreeGrid();
    ConvertNodeCoordinates(m_TreeNodes);
  }

  void TreePlot::InitTreeGrid(){
    int NcolMAX = 0;
    for(int irow = 0; irow < m_Nrow; irow++){
      if(m_Ncol[irow] > NcolMAX) NcolMAX = m_Ncol[irow];
    }
    m_Node_R = min(min(0.85/double(2*NcolMAX+1),0.85*0.85/double(2*m_Nrow+1)),0.12);
    if(m_Type == kGroupTree) 
      m_Node_R = min(min(0.65/double(2*NcolMAX+1),0.85/double(2*m_Nrow+1)),0.12);
  }

  void TreePlot::ConvertNodeCoordinates(vector<TreePlotNode*>& nodes){
    double xmin = 0.;
    double xmax = 1.;
    double ymin = 0.;
    double ymax = 1.;
    if(m_Type == kFrameTree) ymax = 0.8;
    int Nnode = nodes.size();
    for(int i = 0; i < Nnode; i++){
      double new_x = nodes[i]->GetX();
      double new_y = nodes[i]->GetY();
      new_x = xmin + (xmax-xmin)*(new_x+0.5)/double(m_Ncol[int(new_y)]);
      new_y = ymin + (ymax-ymin)*(1.-(new_y+0.5)/double(m_Nrow));
      nodes[i]->SetX(new_x);
      nodes[i]->SetY(new_y);
    }
  }

  void TreePlot::AddFrame(const RestFrame& frame){
    m_Frames += frame;
    if(m_FrameColorMap.count(frame.GetType()) <= 0)
      m_FrameColorMap[frame.GetType()] = int(frame.GetType())-1;
  }

  void TreePlot::FillFrameTree(const RestFrame& frame){
    m_Nrow = 0;
    m_Ncol.clear();

    TreePlotNode* top_nodePtr = new TreePlotNode();
    top_nodePtr->SetX(0.);
    top_nodePtr->SetY(0.);
    top_nodePtr->SetFrame(frame);
    top_nodePtr->SetLabel(frame.GetTitle());
    m_TreeNodes.push_back(top_nodePtr);
    AddFrame(frame);
    m_Ncol.push_back(1);
    FillFrameTreeMap(0, frame);
    m_Nrow = m_Ncol.size();
  }

  void TreePlot::FillFrameTreeMap(int irow, const RestFrame& frame){
    if(frame.IsDecayFrame() && frame.IsRecoFrame()){
      const DecayRecoFrame* rframePtr = dynamic_cast<const DecayRecoFrame*>(&frame);
      if(rframePtr){
	if(rframePtr->IsSelfAssemblingFrame()){
	  FillFrameTreeMap(irow, *rframePtr);
	  return;
	}
      }
    }
    TreePlotNode* frame_nodePtr = m_TreeNodes[m_TreeNodes.size()-1];

    int Nchild = frame.GetNChildren();
    for(int i = 0; i < Nchild; i++){
      const RestFrame& child = frame.GetChildFrame(i);
      if(irow+1 >= int(m_Ncol.size())){
  	m_Ncol.push_back(0);
      }
      TreePlotNode* child_nodePtr = new TreePlotNode();
      child_nodePtr->SetX(m_Ncol[irow+1]);
      child_nodePtr->SetY(irow+1);
      child_nodePtr->SetFrame(child);
      child_nodePtr->SetLabel(child.GetTitle());
      m_TreeNodes.push_back(child_nodePtr);
      AddFrame(child);
      TreePlotLink* linkPtr = new TreePlotLink(frame_nodePtr,child_nodePtr);
      m_TreeLinks.push_back(linkPtr);
      m_Ncol[irow+1]++;
      FillFrameTreeMap(irow+1,child);
    }
  }

  void TreePlot::FillFrameTreeMap(int irow, const DecayRecoFrame& frame){
    TreePlotNode* frame_nodePtr = m_TreeNodes[m_TreeNodes.size()-1];
    frame_nodePtr->SetSquare(true);
    m_SelfAssembling = true;
    int Nchild = frame.GetNChildren();
    for(int i = 0; i < Nchild; i++){
      const ReconstructionFrame& child = frame.GetChildFrame(i);
      bool expand_child = false;
      int N = -1;
      bool excl = false;
      if(child.IsVisibleFrame())
	if(dynamic_cast<CombinatoricGroup*>(&child.GetGroup())){
	  static_cast<CombinatoricGroup&>(child.GetGroup())
	    .GetNElementsForFrame(child, N, excl);
	  if( (N >= 2 && excl) || (N >= 1 && !excl) )
	    expand_child = true;
	}
      if(irow+1 >= int(m_Ncol.size())){
	m_Ncol.push_back(0);
      }
      if(expand_child){
	for(int j = 0; j < 3; j++){
	  TreePlotNode* child_nodePtr = new TreePlotNode();
	  child_nodePtr->SetX(m_Ncol[irow+1]+ double(j-1)*0.08);
	  child_nodePtr->SetY(irow+1);
	  child_nodePtr->SetFrame(child);
	  if(j == 2) child_nodePtr->SetLabel(GetSetTitle(child.GetTitle(),"i"));
	  m_TreeNodes.push_back(child_nodePtr);
	  TreePlotLink* linkPtr = new TreePlotLink(frame_nodePtr,child_nodePtr);
	  m_TreeLinks.push_back(linkPtr);
	}
	m_Ncol[irow+1]++;
	AddFrame(child);
      } else {
	TreePlotNode* child_nodePtr = new TreePlotNode();
	child_nodePtr->SetX(m_Ncol[irow+1]);
	child_nodePtr->SetY(irow+1);
	child_nodePtr->SetFrame(child);
	child_nodePtr->SetLabel(child.GetTitle());
	m_TreeNodes.push_back(child_nodePtr);
	AddFrame(child);
	TreePlotLink* linkPtr = new TreePlotLink(frame_nodePtr,child_nodePtr);
	m_TreeLinks.push_back(linkPtr);
	m_Ncol[irow+1]++;
	FillFrameTreeMap(irow+1,child);
      }
    }
  }

  void TreePlot::FillGroupTree(const Group& group){
    m_Nrow = 0;
    m_Ncol.clear();
  
    if(!group.GetParentState()) return;

    TreePlotNode* top_nodePtr = new TreePlotNode();
    top_nodePtr->SetX(0.);
    top_nodePtr->SetY(0.);
    top_nodePtr->SetState(group.GetParentState());
    top_nodePtr->SetLabel(GetStateTitle(group.GetParentState()));
    m_TreeNodes.push_back(top_nodePtr);
    m_Ncol.push_back(1);
    FillStateTreeMap(0, group.GetParentState());

    m_Nrow = m_Ncol.size();
  }

  void TreePlot::FillJigsawTree(const Jigsaw& jigsaw){
    m_Nrow = 0;
    m_Ncol.clear();
  
    if(!jigsaw.GetParentState()) return;

    TreePlotNode* top_nodePtr = new TreePlotNode();
    top_nodePtr->SetX(0.);
    top_nodePtr->SetY(0.);
    top_nodePtr->SetState(jigsaw.GetParentState());
    top_nodePtr->SetLabel(GetStateTitle(jigsaw.GetParentState()));
    m_TreeNodes.push_back(top_nodePtr);
    m_Ncol.push_back(1);
    FillStateTreeMap(0, jigsaw.GetParentState());

    m_Nrow = m_Ncol.size();
  }

  void TreePlot::FillStateTreeMap(int irow, const State& state){
    const Jigsaw& jigsaw = state.GetChildJigsaw();
    if(!jigsaw) return;
    
    TreePlotNode* state_nodePtr = m_TreeNodes[int(m_TreeNodes.size())-1];
    int Nchild = jigsaw.GetNChildren();

    for(int i = 0; i < Nchild; i++){
      State& child = jigsaw.GetChildState(i);
      if(child.IsEmpty()) continue;
      if(irow+1 >= int(m_Ncol.size())){
	m_Ncol.push_back(0);
      }
      TreePlotNode *child_nodePtr = new TreePlotNode();
      child_nodePtr->SetX(m_Ncol[irow+1]);
      child_nodePtr->SetY(irow+1);
      child_nodePtr->SetState(child);
      child_nodePtr->SetLabel(GetStateTitle(child));
      m_TreeNodes.push_back(child_nodePtr);
      TreePlotLink* linkPtr = new TreePlotLink(state_nodePtr,child_nodePtr);
      linkPtr->SetJigsaw(jigsaw);
      linkPtr->SetLabel(jigsaw.GetTitle());
      m_TreeLinks.push_back(linkPtr);
      m_Ncol[irow+1]++;
      FillStateTreeMap(irow+1, child);
    }
  }

  void TreePlot::FillJigsawLink(const Jigsaw& jigsaw){

    int Nsplit = jigsaw.GetNChildren();
    if(!jigsaw.GetGroup()) return;
    TreePlotNode* high_old = nullptr;
    TreePlotNode* high_new = nullptr;
   
    for(int s = 0; s < Nsplit; s++){
      RestFrameList frames =
	jigsaw.GetChildFrames(s)+
	jigsaw.GetDependancyFrames(s);
      int Nnode = m_TreeNodes.size();
      TreePlotNode* last_nodePtr = nullptr;
      double high = -1.;
      for(int n = 0; n < Nnode; n++){
	TreePlotNode* nodePtr = m_TreeNodes[n];
	const RestFrame& frame = nodePtr->GetFrame();
	if(frames.Contains(frame)){
	  nodePtr->AddJigsaw(jigsaw);
	  if(jigsaw.GetGroup().ContainsFrame(frame)){
	    if(nodePtr->GetY() > high){
	      high_new = nodePtr;
	      high = nodePtr->GetY();
	    }
	  }
	  if(last_nodePtr){
	    if(!(last_nodePtr->GetFrame() == nodePtr->GetFrame())){
	      TreePlotLink* linkPtr = new TreePlotLink(last_nodePtr,nodePtr);
	      linkPtr->SetJigsaw(jigsaw);
	      m_LeafLinks.push_back(linkPtr);
	    }
	  }
	  last_nodePtr = nodePtr;
	}
      }
      
      if(s != 0){
	TreePlotLink* linkPtr = new TreePlotLink(high_old,high_new);
	linkPtr->SetWavy(true);
	linkPtr->SetJigsaw(jigsaw);
	m_LeafLinks.push_back(linkPtr);
      }
      high_old = high_new;
    }
  }

  void TreePlot::SetColors(bool invert_bkg_color,
			   bool invert_node_color){
    if(invert_bkg_color)
      invert_node_color = !invert_node_color;
    
    m_style_Default = 1;
    m_style_Leaf = 7;
    m_color_Leaf.clear();
    
    if(invert_node_color){
      for(int i = 0; i < 3; i++){
	m_color_Node_text[i] = 7000+i*10;
	m_color_Node_fill[i] = 7003+i*10;
	if(invert_bkg_color)
	  m_color_Node_line[i] = 7000+i*10;
	else
	  m_color_Node_line[i] = 7002+i*10;
      }
      m_color_Node_text[3] = 18;
      m_color_Node_fill[3] = kGray+3;
      if(invert_bkg_color)
	m_color_Node_line[3] = 18;
      else
	m_color_Node_line[3] = kGray+1;
    } else {
      for(int i = 0; i < 3; i++){
	m_color_Node_text[i] = 7004+i*10;
	m_color_Node_fill[i] = 7001+i*10;
	if(invert_bkg_color)
	  m_color_Node_line[i] = 7002+i*10;
	else
	  m_color_Node_line[i] = 7004+i*10;
      }
      m_color_Node_text[3] = kGray+3;
      m_color_Node_fill[3] = 18;
      if(invert_bkg_color)
	m_color_Node_line[3] = kGray+2;
      else
	m_color_Node_line[3] = kGray+3;
    }

    if(invert_bkg_color){
      m_color_Text = kWhite;
      m_color_Bkg  = kBlack;
      for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  m_color_Leaf.push_back(7040+j*10+i*2);
      for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  m_color_Leaf.push_back(7060+j*10+i*2);
      m_color_Default_text = kWhite;
      m_color_Default_line = kWhite;
      m_color_Default_fill = kBlack;
    } else {
      m_color_Text = kBlack;
      m_color_Bkg  = kWhite;
      for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  m_color_Leaf.push_back(7043+j*10-i*2);
      for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  m_color_Leaf.push_back(7063+j*10-i*2);
      m_color_Default_text = kBlack;
      m_color_Default_line = kBlack;
      m_color_Default_fill = kWhite;
    }
  }
  
  void TreePlot::DrawTreeNodes(bool with_rings){
    int Nnode = m_TreeNodes.size();
    for(int i = 0; i < Nnode; i++)
      DrawNode(m_TreeNodes[i], with_rings);
  }

  void TreePlot::DrawTreeLinks(){
    int Nlink = m_TreeLinks.size();
    for(int i = 0; i < Nlink; i++)
      DrawLink(m_TreeLinks[i]);
  }

  void TreePlot::DrawLeafLinks(){
    int Nlink = m_LeafLinks.size();
    for(int i = 0; i < Nlink; i++)
      DrawLink(m_LeafLinks[i]);
  }

  void TreePlot::DrawLink(TreePlotLink* linkPtr){
    double x0 = linkPtr->GetNode1()->GetX();
    double y0 = linkPtr->GetNode1()->GetY();
    double x1 = linkPtr->GetNode2()->GetX();
    double y1 = linkPtr->GetNode2()->GetY();

    int icolor_line = m_color_Default_line;
    int icolor_text = -1;
    int icolor_fill = -1;
    int istyle = m_style_Default;
    int isize = int(m_Node_R*70.);
    bool DoWavy = linkPtr->DoWavy();

    const Jigsaw& jigsaw = linkPtr->GetJigsaw();

    if(!jigsaw.IsEmpty()){
      if(linkPtr->DoLabel()){
	int priority = GetJigsawPriority(jigsaw.GetNChildren(), jigsaw.GetNDependancyStates());
	icolor_line = m_color_Node_line[priority];
	icolor_text = m_color_Node_text[priority];
	icolor_fill = m_color_Node_fill[priority];
      } else {
	int Nj = m_Jigsaws.GetN();
	int index = m_Jigsaws.GetIndex(jigsaw);
	x0 += (double(index+1)-double(Nj+1)/2.)*m_Node_R*1./max(4.,double(Nj));
	x1 += (double(index+1)-double(Nj+1)/2.)*m_Node_R*1./max(4.,double(Nj));
	icolor_line = m_color_Leaf[m_JigsawColorMap[&jigsaw]%int(m_color_Leaf.size())];
	if(DoWavy){
	  istyle = m_style_Leaf;
	  isize++;
	}
      }
    }
      
    if(fabs(y0-y1) > 1e-10){ // nodes are at different heights - draw line
      TLine *line = new TLine(x0,y0,x1,y1);
      line->SetLineColor(icolor_line);
      line->SetLineWidth(isize);
      line->SetLineStyle(istyle);
      m_CanvasPtr->cd();
      line->Draw();
      AddTObject(line);
    } else { // nodes are at same height - draw arc
      TArc *arc;
      double c = fabs(x0-x1);
      double h = 1./double(2*m_Nrow)*0.8;
      if(h > c/2.){
	double R = c/2.;
	if(h > R+m_Node_R) arc = new TArc((x0+x1)/2.,y0+m_Node_R,R, 0., 180.);
	else arc = new TArc((x0+x1)/2.,y0+h-R,R, 0., 180.);
      } else {
	double R = h/2. + c*c/(8.*h);
	arc = new TArc((x0+x1)/2.,y0+h-R,R,
		       -asin(c/(2.*R))*180/TMath::Pi()+90., 
		       asin(c/(2.*R))*180/TMath::Pi()+90.);
      }
      arc->SetLineColor(icolor_line);
      arc->SetLineStyle(istyle);
      arc->SetFillStyle(0);
      arc->SetLineWidth(isize);
      m_CanvasPtr->cd();
      arc->Draw("only");
      AddTObject(arc);
    }
    
    if(linkPtr->DoLabel()){
      double x = x0;
      double y = (y0+y1)/2.;
      
      char* slabel = new char[500];
      sprintf(slabel,"#bf{%s}",linkPtr->GetLabel().c_str());
      TLatex* lat = new TLatex(x,y,slabel);
      lat->SetTextAlign(22);
      lat->SetNDC();
      lat->SetTextSize(1.);
      lat->SetTextFont(132);
      double Xsize = lat->GetXsize();
      double Ysize = lat->GetYsize();
      double scale = max(Xsize/(6.*m_Node_R),1.75*Ysize/(fabs(y0-y1)-2.*m_Node_R));
      lat->SetTextSize(1./scale);
      lat->SetTextColor(icolor_text);
      
      Xsize = lat->GetXsize()*1.05;
      Ysize = lat->GetYsize()*1.5;
      TBox *border = new TBox(x-Xsize/2., y-Ysize/2., x+Xsize/2.,y+Ysize/2.);
      border->SetLineColor(icolor_line);
      border->SetLineWidth(2);
      border->SetLineStyle(1);
      border->SetFillColor(icolor_fill);
      m_CanvasPtr->cd();
      border->Draw("l");
      m_CanvasPtr->cd();
      lat->DrawLatex(x,y,slabel);
      delete[] slabel;
      AddTObject(lat);
      AddTObject(border);
    }
  }

  void TreePlot::DrawNode(TreePlotNode* nodePtr, bool with_rings){
    double x = nodePtr->GetX();
    double y = nodePtr->GetY();

    int icolor_line = m_color_Default_line;
    int icolor_text = m_color_Default_text;
    int icolor_fill = m_color_Default_fill;
    int istyle = 1;
    int iwidth = int(m_Node_R*50.);;
    bool square = nodePtr->DoSquare();

    const RestFrame& frame = nodePtr->GetFrame();

    if(!frame.IsEmpty()){
      icolor_text = m_color_Node_text[m_FrameColorMap[frame.GetType()]];
      icolor_line = m_color_Node_line[m_FrameColorMap[frame.GetType()]];
      icolor_fill = m_color_Node_fill[m_FrameColorMap[frame.GetType()]];
    }

    if(with_rings){
      JigsawList jigsaws = nodePtr->GetJigsawList();
      int Njigsaw = jigsaws.GetN();
      for(int i = 0; i < Njigsaw; i++){
	double R = 1.03 + double(Njigsaw-i)*0.08;
	const Jigsaw& jigsaw = jigsaws[i];
	if(square){
	  TBox* ring = new TBox(x-m_Node_R*R*0.88,y-m_Node_R*R*0.88,
				x+m_Node_R*R*0.88,y+m_Node_R*R*0.88);
	  int jcolor = m_color_Leaf[m_JigsawColorMap[&jigsaw]%int(m_color_Leaf.size())];
	  ring->SetLineColor(jcolor);
	  ring->SetFillColor(jcolor);
	 
	  m_CanvasPtr->cd();
	  ring->Draw();
	  AddTObject(ring);
	} else {
	  TArc* ring = new TArc(x,y,m_Node_R*R);
	  int jcolor = m_color_Leaf[m_JigsawColorMap[&jigsaw]%int(m_color_Leaf.size())];
	  ring->SetLineColor(jcolor);
	  ring->SetFillColor(jcolor);
	 
	  m_CanvasPtr->cd();
	  ring->Draw();
	  AddTObject(ring);
	}
      }
    }
    if(square){
      TBox *box = new TBox(x-m_Node_R*0.88,y-m_Node_R*0.88,
			   x+m_Node_R*0.88,y+m_Node_R*0.88);
      box->SetLineColor(icolor_line);
      box->SetFillColor(icolor_fill);
      box->SetLineStyle(istyle);
      box->SetLineWidth(iwidth);
      m_CanvasPtr->cd();
      box->Draw("l");
      AddTObject(box);
    } else {
      TArc *circle = new TArc(x,y,m_Node_R);
      circle->SetLineColor(icolor_line);
      circle->SetFillColor(icolor_fill);
      circle->SetLineStyle(istyle);
      circle->SetLineWidth(iwidth);
      m_CanvasPtr->cd();
      circle->Draw();
      AddTObject(circle);
    }

    if(nodePtr->DoLabel()){
      char* nodetitle = new char[200];
      sprintf(nodetitle,"#bf{%s}",nodePtr->GetLabel().c_str());
      TLatex* lat = new TLatex(x,y,nodetitle);
      lat->SetTextAlign(22);
      lat->SetNDC();
      lat->SetTextSize(1.);
      lat->SetTextFont(132);
      double Rnorm = 
	sqrt(lat->GetXsize()*lat->GetXsize()+lat->GetYsize()*lat->GetYsize());
      lat->SetTextSize(1.8*m_Node_R/Rnorm);
      lat->SetTextColor(icolor_text);
      m_CanvasPtr->cd();
      lat->DrawLatex(x,y,nodetitle);
      delete[] nodetitle;
      AddTObject(lat);
    }
  }

  std::string TreePlot::GetStateTitle(const State& state){
    RestFrameList frames = state.GetListFrames();
    int Nf = frames.GetN();
    std::string title = "";
    if(Nf > 2) title.append("#splitline{");
    title.append(frames.Get(0).GetTitle());
    for(int f = 1; f < Nf; f++){
      if(f%((Nf+1)/2) == 0 && Nf > 2) title.append("}{");
      title.append("+ ");
      title.append(frames[f].GetTitle());
    }
    if(Nf > 2) title.append("}");
   
    return title;
  }

  std::string TreePlot::GetSetTitle(const std::string& set, 
				    const std::string& index){
    std::string title = "#left{#left(";
    title.append(set);
    title.append("#right)_{");
    title.append(index);
    title.append("}#right}");
    return title;
  }

  void TreePlot::DrawFrameTypeLegend(){
    vector<std::string> frame_title;
    frame_title.push_back("Lab State");
    frame_title.push_back("Decay States");
    frame_title.push_back("Visible States");
    frame_title.push_back("Invisible States");
    vector<FrameType> frame_type;
    frame_type.push_back(kLabFrame);
    frame_type.push_back(kDecayFrame);
    frame_type.push_back(kVisibleFrame);
    frame_type.push_back(kInvisibleFrame);
   
    TLatex* lat = new TLatex(0.,0.,"");
    lat->SetNDC();
    lat->SetTextAlign(12);
    lat->SetTextSize(0.045);
    lat->SetTextFont(132);
    lat->SetTextColor(m_color_Default_text);
    double X = 0.045;
    double Y = 0.955;
    double R = 0.035;
    double step = 2.2*R;
    for(int i = 0; i < 4; i++){
      TBox* white = new TBox(X-step/2.,Y-step/2.,0.36,Y+step/2.);
      white->SetFillColor(m_color_Bkg);
      white->SetLineColor(m_color_Bkg);
      white->Draw();
      AddTObject(white);
      if(m_FrameColorMap.count(frame_type[i]) <= 0) continue;
      TArc* circle = new TArc(X,Y,R);
      circle->SetLineColor(m_color_Node_line[m_FrameColorMap[frame_type[i]]]);
      circle->SetFillColor(m_color_Node_fill[m_FrameColorMap[frame_type[i]]]);
      circle->SetLineWidth(2);
      circle->Draw();
      AddTObject(circle);
      lat->DrawLatex(X+R*1.3,Y,frame_title[i].c_str());
      Y -= step;
    }
    if(m_SelfAssembling){
      TBox* white = new TBox(X-step/2.,Y-step/2.,0.36,Y+step/2.);
      white->SetFillColor(m_color_Bkg);
      white->SetLineColor(m_color_Bkg);
      white->Draw();
      AddTObject(white);
      TBox* box = new TBox(X-R*0.88,Y-R*0.88,X+R*0.88,Y+R*0.88);
      box->SetLineColor(m_color_Node_line[m_FrameColorMap[kDecayFrame]]);
      box->SetFillColor(m_color_Node_fill[m_FrameColorMap[kDecayFrame]]);
      box->Draw("l");
      AddTObject(box);
      lat->DrawLatex(X+R*1.3,Y,"Self Assembling");
    }
    AddTObject(lat);
  }

  void TreePlot::DrawJigsawLegend(){
    vector<std::string> ititle;
    vector<int> icolor_line;
    vector<int> icolor_text;
    int Nj = m_Jigsaws.GetN();
    for(int i = 0; i < Nj; i++){
      int jcolor = m_color_Leaf[m_JigsawColorMap[&m_Jigsaws[i]]%int(m_color_Leaf.size())];
      icolor_line.push_back(jcolor);
      icolor_text.push_back(jcolor);
      ititle.push_back(m_Jigsaws[i].GetLabel().c_str());
    }

    vector<TLine*> dum;
    for(int i = 0; i < Nj; i++){
      dum.push_back(new TLine(0.0,0.0,0.001,0.001));
      dum[i]->SetLineWidth(int(m_Node_R*70.));
      dum[i]->SetLineColor(icolor_line[i]);
      AddTObject(dum[i]);
    }
  
    TLegend* leg = new TLegend(0.60235,0.997-Nj*.078,0.8087,0.997);
    AddTObject(leg);
    vector<TLegendEntry*> entry;
    for(int i = 0; i < Nj; i++){
      entry.push_back(leg->AddEntry(dum[i], ititle[i].c_str()));
      entry[i]->SetMarkerSize(0);
      entry[i]->SetMarkerColor(icolor_line[i]);
      entry[i]->SetFillColor(m_color_Bkg);
    }
    leg->SetLineColor(m_color_Bkg);
    leg->SetFillColor(m_color_Bkg);
    leg->SetShadowColor(m_color_Bkg);
    leg->SetTextColor(m_color_Text);
    leg->SetTextFont(132);
    leg->SetTextSize(0.042);
    leg->Draw();
  }

  void TreePlot::DrawTitle(const std::string& title){
    TLatex* lat = new TLatex(0.0,0.0,title.c_str());
    lat->SetTextAlign(22);
    lat->SetNDC();
    lat->SetTextSize(0.045);
    lat->SetTextFont(132);
    lat->SetTextColor(m_color_Text);
    double x = lat->GetXsize()/2. + 0.01;
    double y = 1. - lat->GetYsize()/2. - 0.01;
    m_CanvasPtr->cd();
    lat->DrawLatex(x,y,title.c_str());
    AddTObject(lat);
  }

  int TreePlot::GetJigsawPriority(int Nout, int Ndep) const {
    if(Nout == 1 && Ndep == 0) return 0;
    if(Nout == 1 && Ndep == 1) return 1;
    return 2;
  }

}
