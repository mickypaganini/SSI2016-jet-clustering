#ifndef __CMS_ITERATIVE_CONE__SORT_BY_ET_H__
#define __CMS_ITERATIVE_CONE__SORT_BY_ET_H__

#include <limits>
#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace cms{

// This is the code that deals with the ordering in Et
//
// It comes from the CMSSW file  ???VERSION???
//   CMSSW/PhysicsTools/Utilities/interface/EtComparator.h
// The code has been slightly adapted to ack on PseudoJets 
// rather than the CMS types for 4-vectors
// 
// For completeness, here is a copy of the exact CMS code 
// we've used
//  
//   template <class T>
//   struct NumericSafeGreaterByEt {
//     typedef T first_argument_type;
//     typedef T second_argument_type;
//     bool operator()(const T& a1, const T& a2) {
//       return
//         fabs (a1.et()-a2.et()) > std::numeric_limits<double>::epsilon() ? a1.et() > a2.et() :
//         fabs (a1.px()-a2.px()) > std::numeric_limits<double>::epsilon() ? a1.px() > a2.px() :
//         a1.pz() > a2.pz();
//     }
//   };

template <class T>
struct NumericSafeGreaterByEt {
  typedef T first_argument_type;
  typedef T second_argument_type;
  bool operator()(const T& a1, const T& a2) {
    // FastJet::PseudoJet does not provide a direct access to Et2
    // Plus, we want it to be computed in the same way as in the CMS
    // code (actually the Root code that is used by CMS)
    double et1 = a1.Et();
    double et2 = a2.Et();

    // now we can come back to the CMS code
    return
      fabs (et1-et2) > std::numeric_limits<double>::epsilon() ? et1 > et2 :
      fabs (a1.px()-a2.px()) > std::numeric_limits<double>::epsilon() ? a1.px() > a2.px() :
      a1.pz() > a2.pz();
  }
};

}  // namespace cms

FASTJET_END_NAMESPACE


#endif   // __CMS_ITERATIVE_CONE__SORT_BY_ET_H__
