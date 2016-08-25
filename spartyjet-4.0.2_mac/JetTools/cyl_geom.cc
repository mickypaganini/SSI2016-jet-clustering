// Copyright 2010, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
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

#include "cyl_geom.hh"

namespace SpartyJet { 

void testHullLine(point_list_t& hull, point_t p) {
  // helper function for findConvexHull
  point_list_t::iterator it_prev = hull.end(); it_prev--;
  point_list_t::iterator it_pprev = it_prev; it_pprev--;
  line_t l(*it_pprev, *it_prev);
  if (!l.is_left(p) && (hull.size() > 2)) {
    hull.pop_back(); // remove last
    testHullLine(hull, p);
  } else {
    hull.push_back(p);
  }
}

void listToSet(point_list_t& inList, point_set_t& outSet) {
  point_list_t::iterator it = inList.begin();
  point_list_t::iterator itE = inList.end();
  point_set_t::iterator s_it = outSet.begin();
  for (; it != itE; ++it) {
    s_it = outSet.insert(s_it, *it);
  }  
}

}  // namespace SpartyJet
