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

#include "JetHistoryView.hh"
#include "EventView.hh"

#include <vector>
using namespace std;

namespace SpartyJet {

  void JetHistoryView::buildJet() {
    Jet* j = getJet();
    SetX(j->eta());
    SetY(j->phi());
  }

  void JetHistoryView::debug(){
    std::cout << " JHV  "<< this << "  item="<< history.item << "  hind"<< hindex() << "  jet "<< jet() << std::endl;
  }

#define LOOP_OVER_CONSTIT( code )   hist_list_t constits; retrieveParentNodes(constits,true,false) ; \
  hist_list_t::iterator it = constits.begin();\
  hist_list_t::iterator itE = constits.end(); \
  for(; it != itE; ++it){ code }

  void JetHistoryView::drawConstituents(int color, int style, float size){    
    TAttMarker m(color,style,size);
    //std::cout << " drawConstituents  "; debug();
    //LOOP_OVER_CONSTIT(  std::cout << " --> it="<< *it<< "  "; (*it)->debug();  (*it)->drawJet(m); ) ;
    LOOP_OVER_CONSTIT(   (*it)->drawJet(m); ) ;
  }

  void JetHistoryView::setConstitutentAtt(TAttMarker &m){
    LOOP_OVER_CONSTIT( m.Copy( *(*it) ) ; ) ;
  }
  void JetHistoryView::setConstitutentStyle(int style){
    LOOP_OVER_CONSTIT( (*it)->SetMarkerStyle( style ) ; ) ;
  }
  void JetHistoryView::setConstitutentColor(int color){
    LOOP_OVER_CONSTIT( (*it)->SetMarkerColor( color ) ; ) ;
  }
  void JetHistoryView::setConstitutentSize(float size){
    LOOP_OVER_CONSTIT(  (*it)->SetMarkerSize( size ) ; ) ;
  }

  void JetHistoryView::drawParent(int color, int style, float size){
    TAttMarker m(color,style,size);
    vector<JetHistoryView*> p = parents();
    for (size_t i = 0; i < p.size(); ++i) p[i]->Draw(m);
  }


  // ////////////////////////////////////////////////////////////////
  // ////////////////////////////////////////////////////////////////

  JetHistViewCollection::JetHistViewCollection(JetCollection &jcoll) {
    // Copy a JetHistoryView for each jet, from its HistoryElement
    Jet::jet_list_t::const_iterator it, itE;
    it = jcoll.begin();
    itE = jcoll.end();
    for (; it != itE; ++it) {
      m_hview.push_back(new JetHistoryView(*((*it)->history())));
      m_hview.back()->buildJet();
    }
  }


  void JetHistViewCollection::drawConstituents(bool onlyFinalJet) {
    for(size_t i = 0 ; i< m_hview.size(); i++) {
      m_hview[i]->drawConstituents(EventViewBase::option_low_pt_jet_color);
    }
  }

}
