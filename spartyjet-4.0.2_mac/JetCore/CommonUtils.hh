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

#ifndef _JETCOMMONUTILS_HH_
#define _JETCOMMONUTILS_HH_

#include <ctime>
#include <algorithm>
#include <cmath>

namespace SpartyJet { 

// **************************************************************
// phi conversions
//  these are safe to run on phi values that are already in correct form
// **************************************************************
inline float to_minusPI_PI(float phi) {
  while (phi < -M_PI) phi += 2*M_PI;
  while (phi >= M_PI) phi -= 2*M_PI;
  return phi;
}
inline float to_zero_2PI(float phi) {
  while (phi < 0) phi += 2*M_PI;
  while (phi >= 2*M_PI) phi -= 2*M_PI;
  return phi;
}



// **************************************************************
// List utils
// **************************************************************
// Destroy all pointers in a container, and clear it
// T must be a container of pointers ex. list<T2*>
template<class T>
void clear_list(T& list) {
  typedef typename T::iterator it_t;
  it_t it  = list.begin();
  it_t itE = list.end();
  for (; it != itE; ++it) delete *it;
  list.clear();
}



// **************************************************************
// timing
// **************************************************************
class stopwatch {
public :
  stopwatch() : m_total(0) {}
  void start()  {m_last = std::clock();}
  void resume() {m_last = std::clock();}
  float pause() {
    std::clock_t now = std::clock();
    m_total = m_total +  now - m_last;
    m_last = now;
    return convert();
  }
  float stop() {float t = pause(); m_total = std::clock_t(0); return t;}
protected:
  std::clock_t m_last;
  std::clock_t m_total;
  
  float convert() {return float(m_total)*1000/CLOCKS_PER_SEC;}
};


}  // namespace SpartyJet
#endif
