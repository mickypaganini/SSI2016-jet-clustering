// Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
//                 Brian Martin, and Christopher Vermilion
//
//----------------------------------------------------------------------
// This file is part of SpartyJet.
//
//  SpartyJet is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  SpartyJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with SpartyJet; if not, write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------

#include "EventView.hh"
#include "Jet2DView.hh"
#include "JetCore/JetDistances.hh"

#include "TH2.h"
#include "TPad.h"
#include "THStack.h"
#include "TLine.h"
#include "TList.h"
#include "TFile.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace SpartyJet {

// extension of THStack that owns its TH1's -- on deletion it deletes all the hists it holds
class HStackOwner : public THStack {
public:
  HStackOwner(const char* name, const char* title)
    : THStack(name, title) {}

  ~HStackOwner() {
    // clean up hists
    fHists->R__FOR_EACH(TH1,Delete)();
  }
};


TPad* EventViewBase::s_pad;  
int EventViewBase::option_low_pt_jet_color = kGray;
#define NUMBASE_COLOR 7
int EventViewBase::base_colors[NUMBASE_COLOR] = {kRed, kBlue, kGreen, kYellow, kMagenta,kCyan, kOrange};

int EventViewBase::color_code(int i) {
  if ((i<NUMBASE_COLOR) && (i > -1)) return base_colors[i];
  switch (i) {
    case -2:
      return kWhite;
    case -1:
      return kBlack;
  }
  return option_low_pt_jet_color;
}

TPad* EventViewBase::getPad() {return s_pad;}

void EventViewBase::setPad(TPad* p) {s_pad = p;}

TOvect_t EventViewBase::s_gc_objects;

// not needed now?
void EventViewBase::clear_graphic_objects(){

  for(size_t i=0;i < s_gc_objects.size(); i++) {
    delete s_gc_objects[i];
  }
  s_gc_objects.clear();
}

void EventViewBase::draw_jets(JetCollExtended& jcoll, JetCollExtended& inputcoll, string hname, string htitle) {
  //cout << "EventViewBase::draw_jets jcoll = "<< (&jcoll) << "  inputcoll"<< (&inputcoll) << endl;
  m_local_objects.clear();
  i_draw_jets(jcoll,inputcoll, hname, htitle);
  for (size_t i = 0; i < m_local_objects.size(); i++) s_gc_objects.push_back(m_local_objects[i]);
}
  
void LegoView::i_draw_jets(JetCollExtended& jcoll, JetCollExtended &inputcoll, string hname, string htitle) {
  s_pad->Clear();
  
  int current_color = 0;

  int n_eta = (int)(10/option_eta);
  int n_phi = (int)(2*3.14159265/option_phi);
  
  htitle += " ( #phi , #eta, P_{T} (GeV/c) )";

  // let TPad delete stack; the HStackOwner then deletes what it's holding if they have kCanDelete set
  THStack *stack = new HStackOwner("stack", htitle.c_str());
  stack->SetBit(kCanDelete);

  TH2F* tempplot  = NULL;
  TH2F* tempplot2 = NULL; 
  TH2F* tempplot3 = NULL;

  double phi, pt, eta;  

  vector<int>& algoIndices = jcoll.m_algoIndices;
  
  if (option_input == 1) {
    tempplot = new TH2F("tempplot", "Towers NOT in Jets", n_eta, -5, 5, n_phi, -3.141592, 3.141592);
    for (size_t in = 0; in < inputcoll.size(); in++)
      if (algoIndices[in] == -1) {
        Jet* constit = inputcoll[in];
        phi = constit->phi_std();
        pt = constit->pt();
        if (option_use_rapidity) eta = constit->rapidity();
        else eta = constit->eta();
        tempplot->Fill(eta, phi, pt); 
      }
    tempplot->SetFillColor(10);
    stack->Add(tempplot);
  }
  
  // add a void white histo 
  tempplot3 = new TH2F("tempplot3", "Towers in Jets", n_eta, -5, 5, n_phi, -3.141592, 3.141592);
  tempplot3->SetFillColor(kWhite);
  tempplot3->SetLineColor(kWhite);
  //tempplot3->SetFillStyle(0);
  stack->Add(tempplot3);
  
  for (size_t j = 0; j < jcoll.size(); j++) {
    if (jcoll[j]->pt() < option_min_pt_jet_display) continue;
    char name[15];
    sprintf(name, "tempplot2_%d", int(j));
    tempplot2 = new TH2F(name, "Towers in Jets", n_eta, -5, 5, n_phi, -3.141592, 3.141592);

    int nfound = 0;

    // can't use m_algoIndices for onthefly algorithms
    //     for(unsigned in = 0; in < inputcoll.size(); in++)
    //       if(inputcoll.m_algoIndices[m_alg][in] == j) {
    // 	cout << "filling lego with jet: " << inputcoll[in]->phi_std() << ", " << inputcoll[in]->eta() << ", " << inputcoll[in]->pt() << endl;
    // 	tempplot2->Fill(inputcoll[in]->phi_std(),inputcoll[in]->eta(),inputcoll[in]->pt());
    // 	nfound++;
    //       }

    Jet::jet_list_t::iterator citer = jcoll[j]->first_constituent();
    Jet* cjet;
    for (; citer != jcoll[j]->last_constituent(); citer++) {
      nfound++;
      cjet = *citer;
      phi = cjet->phi_std();
      pt = cjet->pt();
      if (option_use_rapidity) eta = cjet->rapidity();
      else eta = cjet->eta();
      tempplot2->Fill(eta, phi, pt);
    }
    
    if(nfound != jcoll[j]->get_constituent_num()) {
      cout << "ERROR - found " << nfound << " constituents of " //m_retrieveFile.get_alg_name(m_alg)
		<< ", jet " << j << ".  There should be " << jcoll[j]->get_constituent_num() << "!\n";
    }
    
    tempplot2->SetFillColor(color_code(current_color));
    tempplot2->SetLineColor(color_code(current_color));
    current_color++;

    stack->Add(tempplot2);
  }
  s_pad->cd(1);


  if (option_psr)  stack->Draw("LEGO10,PSR");
  else stack->Draw("LEGO10");

  if (option_use_rapidity) stack->GetXaxis()->SetTitle("Y");
  else stack->GetXaxis()->SetTitle("#eta");
  stack->GetYaxis()->SetTitle("#Phi");

  s_pad->Update();

  //s_gc_objects.push_back(tempplot);
  //s_gc_objects.push_back(tempplot2);
  //s_gc_objects.push_back(tempplot3); 
}


void Event2DView::clear_graphic_objects(){
  clear_list(m_gc_inpuColl);
  clear_list(m_gc_JetView);
  EventViewBase::clear_graphic_objects();
}

void Event2DView::i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, string hname, string htitle) {
  s_pad->Clear();

  int njet = jcoll.size();

  int nconstit = inputcoll.size();
  
  vector<int> &index = jcoll.m_algoIndices;
  
  // get aliases to collections
  MarkerColl<PtMarker> &input_markers =  * (new MarkerColl<PtMarker>()) ;
  m_gc_inpuColl.push_back(&input_markers);
  
  vector<Jet2DView> &jet_views = *(new vector<Jet2DView>(njet));
  m_gc_JetView.push_back(&jet_views);
    
  input_markers.set_color(kGray);
    
  for (int i = 0; i < njet; i++) jet_views[i].set_color(color_code(i));  
    
  double phi, pt, eta;
  for (int i = 0 ; i < nconstit; i++) {
    Jet *constit = inputcoll[i];
    phi = constit->phi_std();
    pt = constit->pt();
    if (option_use_rapidity) eta = constit->rapidity();
    else eta = constit->eta();
    
    if (option_2Dview_draw_input) input_markers.push_back(PtMarker(eta, phi, pt));
    if (index[i] > -1) jet_views[index[i]].push_back(eta, phi, pt);
  } 

  if (option_2Dview_scale_markers) {
    int minM = 20;
    if (nconstit < 21) minM = nconstit;
    float ptmin = inputcoll[minM]->pt();
    float ptmax = inputcoll[0]->pt();
    if (7*ptmin < ptmax) ptmin = ptmax/7.;
    float f = 4./(ptmax-ptmin);
    input_markers.set_size(0.4);
    for (int i = 0; i < njet; i++) jet_views[i].scale_markers(ptmin,f);
  }

  // we use an empty TH2 for the frame
  TH2F* h2 = new TH2F("2DView",("2DView for"+hname).c_str(),10,-5.2,5.2,10,-3.2,3.2);
  h2->SetBit(kCanDelete);
  //s_gc_objects.push_back(h2); // push back to garbage.

  h2->SetStats(0);
  h2->Draw(); // no need for cleanup?

  if (option_use_rapidity) h2->SetXTitle("Y");
  else h2->SetXTitle("#eta");
  h2->SetYTitle("#Phi");

  // Draw lines
  s_pad->Update();
  if (option_2Dview_draw_input) input_markers.Draw();
  for (int i = 0; i < njet; i++) {
    if (jcoll[i]->pt() > option_min_pt_jet_display) { 
      jet_views[i].buildHull();
      jet_views[i].Draw();
    }
  }
  s_pad->Update();
}

SnowMassView::SnowMassView() {
  option_ymin     = -5;
  option_ymax     = 5;
  option_phimin   = -M_PI;
  option_phimax   = M_PI;
  option_ystep    = 0.05;
  option_phistep  = 0.05;
  option_radius   = 0.7;
  option_drawjets = false;
  option_log      = false;
}

  
void SnowMassView::i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, string hname, string htitle){
  s_pad->Clear();

  htitle += " ( #phi , #eta, P_{T} (GeV/c) )";

  int ynum,phinum;

  THStack *stack = new HStackOwner("stack", htitle.c_str());
  stack->SetBit(kCanDelete);
  
  ynum = (int)((option_ymax - option_ymin)/option_ystep) +1;
  phinum = (int)((option_phimax - option_phimin)/option_phistep +1);

  float plot_phimin = (-M_PI) < option_phimin ? option_phimin : -M_PI; 
  float plot_phimax = (M_PI) > option_phimax  ? option_phimax : M_PI; 

  TH2F *smplot = new TH2F("smplot_f",htitle.c_str(),ynum,option_ymin,option_ymax,phinum,option_phimin,option_phimax);
  smplot->SetBit(kCanDelete);

  float s_r2 = option_radius*option_radius;

  for(unsigned in = 0; in < inputcoll.size(); in++) {
    float eta = inputcoll[in]->eta();
    float phi = inputcoll[in]->phi_std();

    // maximal point in eta where this constituent has an impact
    float eta_min = eta - option_radius;
    float eta_max = eta + option_radius;
    int iy_min = int ( (eta_min - option_ymin)/option_ystep -0.5 ); if (iy_min<0) iy_min = 0;
    int iy_max = int ( (eta_max - option_ymin)/option_ystep -0.5 ); if (iy_max>=ynum) iy_max = ynum-1 ;

    // maximal point in phi where this constituent has an impact
    float phi_min = phi - option_radius;
    float phi_max = phi + option_radius;
    // because of cylindrical, there maybe be 2 phi_max, phi_min if (eta,phi) is
    // close to M_PI or -M_PI
    float phi_min1=0, phi_min2=0;
    float phi_max1=0, phi_max2=0;
    int iphi_min1=0, iphi_min2=0;
    int iphi_max1=0, iphi_max2=0;
    phi_min1 = phi_min;
    phi_max1 = phi_max;
    iphi_min1 = int ( (phi_min1 - (option_phimin))/option_phistep -0.5 ); if (iphi_min1<0) iphi_min1 = 0;
    iphi_max1 = int ( (phi_max1 - (option_phimin))/option_phistep -0.5 ); if (iphi_max1>=phinum) iphi_max1 = phinum-1 ;
    
    if (phi_min < -M_PI) {// we're at down edge
      phi_min1 = plot_phimin ; phi_min2 = phi_min +2*M_PI; phi_max2= plot_phimax;
      iphi_min1=0; iphi_max2=phinum-1;
      iphi_min2 = int ( (phi_min2 - (-M_PI))/option_phistep -0.5 ); if (iphi_min2>phinum) iphi_min2 = phinum -1;      
    }
    if (phi_max > M_PI) {// we're at up edge
      phi_max1 = plot_phimax; phi_max2 = phi_max -2*M_PI; phi_min2= plot_phimin;
      iphi_max1=phinum-1; iphi_min2=0;
      iphi_max2 = int ( (phi_max2 - (-M_PI))/option_phistep -0.5 ); if (iphi_max2<0) iphi_max2 = 0 ;  
    }
  
    for (int iy = iy_min; iy < iy_max; iy++) {
      for (int iphi = iphi_min1; iphi < iphi_max1; iphi++) {
        float l_y   = option_ymin +   (iy+0.5)*option_ystep;
        float l_phi = option_phimin + (iphi+0.5)*option_phistep;
        //potential = 0;
        
        float term = (s_r2 - JetDistances::deltaEta(eta,l_y)*JetDistances::deltaEta(eta,l_y) - JetDistances::deltaPhi(phi, l_phi )*JetDistances::deltaPhi(phi, l_phi ) );
        if(term > 0)
          smplot->Fill(l_y,l_phi,0.5*inputcoll[in]->pt()*term);
      }
      // if not on the edge, iphi_min2 == iphi_max2 so nothing will be done here :
      for (int iphi = iphi_min2; iphi < iphi_max2; iphi++) {
        float l_y   = option_ymin +   (iy+0.5)*option_ystep;
        float l_phi = option_phimin + (iphi+0.5)*option_phistep;
        //potential = 0;
        
        float term = (s_r2 - JetDistances::deltaEta(eta,l_y)*JetDistances::deltaEta(eta,l_y) - JetDistances::deltaPhi(phi, l_phi )*JetDistances::deltaPhi(phi, l_phi ) );
        if(term > 0)
          smplot->Fill(l_y,l_phi,0.5*inputcoll[in]->pt()*term);
      }
    }
  }
  
  stack->Add(smplot);
  
  if (option_drawjets) {
    TH2F *jetplot = new TH2F("jetplot1_f",htitle.c_str(),phinum,option_phimin,option_phimax,ynum,option_ymin,option_ymax);
    jetplot->SetBit(kCanDelete);
    for(size_t j = 0; j < jcoll.size(); j++)
      smplot->Fill(jcoll[j]->eta(), jcoll[j]->phi_std(), jcoll[j]->pt());
    
    jetplot->SetFillColor(jcoll.color());
    
    stack->Add(jetplot);
  }
  
  s_pad->cd(1);
  
  if (option_log) s_pad->SetLogz();
  else s_pad->SetLogz(0);

  stack->Draw("LEGO1");
  
  s_pad->Update();
 
  //s_gc_objects.push_back(jetplot);
  //s_gc_objects.push_back(stack);
  //s_gc_objects.push_back(smplot);
  s_pad->SetLogz(0);
}


void PrintEvent::i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, string hname, string htitle) {  
  cout << "             E          Pt          eta         phi          mass         n" << endl;
  cout << "--------------------------------------------------------------------------------" << endl;

  if(jcoll.size() == 0)
    cout << "     no jets in this event for " << htitle << endl;
  else { // number of jets != 0
    cout << "    " << htitle << endl;
    for(unsigned j = 0; j < jcoll.size(); j++) {
      cout << "        " 
	   << setw(12) << jcoll[j]->E()   << setw(12) << jcoll[j]->pt()  
	   << setw(12) << jcoll[j]->eta() << setw(12) << jcoll[j]->phi_std()
	   << setw(12) << jcoll[j]->mass();
      cout << setw(12) << jcoll[j]->get_constituent_num();
      cout << endl;
    }
  }
}


void ParamSpace::i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, string hname, string htitle) {
  s_pad->Clear();
    
  double z,de,deltaY,deltaPhi;
  int num_pairs = 0, num_less_radius = 0;

  double rmax = jcoll.radius() > 0.0 ? jcoll.radius() : 0.5;
  TH2F *plotZvsY = new TH2F("plot","Parameter Space Z vs D_eta",(int)((2*rmax)*200),0,(2*rmax),100,0,1);
  TH1F *plotY = new TH1F("plotd","Parameter D_eta",(int)((2*rmax)*20),0,(2*rmax));
  TH1F *plotZ = new TH1F("plotz","Parameter Z",100,0,1 );    
  
  plotZvsY->SetBit(kCanDelete);
  plotY->SetBit(kCanDelete);
  plotZ->SetBit(kCanDelete);

  for(size_t j1 = 0; j1 < jcoll.size(); j1++) {
    for(size_t j2 = 0; j2 < jcoll.size(); j2++) {
      z = jcoll[j1]->E()/jcoll[j2]->E();
      if(z < 1) {
        deltaY = pow(jcoll[j1]->eta() - jcoll[j2]->eta(),2);
        deltaPhi = pow(jcoll[j1]->phi_std() - jcoll[j2]->phi_std(),2);
        de = pow(deltaY + deltaPhi,0.5);
        num_pairs++;
        if (de < jcoll.radius()) num_less_radius++;
        
        plotZvsY->Fill(de,z);
        plotY->Fill(de);
        plotZ->Fill(z);
      }
    }
  }
  
  plotZvsY->SetMarkerStyle(5);

  // Z vs D_eta output
  
  TPad *PlotsY = s_pad;
  PlotsY->Divide(2,2);
  
  PlotsY->cd(1);
  plotZvsY->GetXaxis()->SetTitle("d_eta (separation in eta and phi)");
  plotZvsY->GetYaxis()->SetTitle("z (Pt percentage in smaller jet)");
  plotZvsY->Draw();
  TLine* line = new TLine(jcoll.radius(),0,jcoll.radius(),1);
  line->SetBit(kCanDelete);
  line->Draw();
  
  PlotsY->cd(2);
  plotY->Draw();
  
  PlotsY->cd(3);
  plotZ->Draw();

  //s_gc_objects.push_back(plotZvsY);
  //s_gc_objects.push_back(plotY);
  //s_gc_objects.push_back(plotZ);
  //s_gc_objects.push_back(line);

  s_pad->cd();
  s_pad->Update();
}


} // namespace spartyjet



