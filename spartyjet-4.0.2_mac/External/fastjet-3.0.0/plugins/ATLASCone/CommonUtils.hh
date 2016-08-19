// File taken from SpartyJet v2.20.0

#ifndef _JETCOMMONUTILS_HH_
#define _JETCOMMONUTILS_HH_

#include <ctime>
#include <algorithm>
#include <cmath>

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace atlas{

// **************************************************************
// phi conversions 
// **************************************************************
inline  float to_minusPI_PI(float phi){
  while(phi < -M_PI) phi += 2*M_PI;
  while(phi >= M_PI) phi -= 2*M_PI;
  return phi;
}
inline  float to_zero_2PI(float phi){
  while(phi < 0) phi += 2*M_PI;
  while(phi >= 2*M_PI) phi -= 2*M_PI;
  return phi;
}



// **************************************************************
// List utils
// **************************************************************
// Destroy all pointers in a container, and clear it
// T must be a container of pointers ex. list<T2*>
template<class T>
void clear_list(T & list){
  typedef typename T::iterator it_t;
  it_t it = list.begin();
  it_t itE = list.end();
  for(; it != itE; ++it){
    delete *it;
  }
  list.clear();
}





// **************************************************************
// timing
// **************************************************************
class stopwatch {
public :
  stopwatch() : m_total(0){};
  void start(){m_last = std::clock();};
  void resume(){m_last = std::clock();};
  float pause() {
    std::clock_t now=std::clock();
    m_total = m_total +  now - m_last;
    m_last = now;
    return convert();
  }
  float stop(){float t=pause(); m_total = std::clock_t(0); return t;}
protected:
  std::clock_t m_last;
  std::clock_t m_total;
  
  float convert(){ return float(m_total)*1000/CLOCKS_PER_SEC;}
};


}  // namespace atlas

FASTJET_END_NAMESPACE
#endif
