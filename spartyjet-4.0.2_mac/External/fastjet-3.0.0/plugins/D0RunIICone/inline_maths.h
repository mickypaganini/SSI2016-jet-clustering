#ifndef INLINE_MATHS
#define INLINE_MATHS

#include <cerrno>

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace d0{

namespace inline_maths {

const double PI = fabs(acos(-1.));

const double TWOPI = 2*PI;


inline double sqr(double a) {
  return a*a;
}



inline double min(double a, double b) {
  return (a < b) ? a : b;
}



inline double delta_phi(double phi1, double phi2) {
  return min( double(fabs(phi1-phi2)), double(2.*PI-fabs(phi1-phi2)) );
}



inline double phi(double px, double py) {
  return atan2(py, px);
}



inline double y(double E, double pz) {
  errno=0;
  double y;
  //cout << "inline_maths: ";
  if (fabs(E-pz) == 0.) {
    //    cout << "Error in header mathe.h: division by 0 in function eta!" <<  " p=" << p << " pz=" << pz << endl;
    //  exit(721);
    errno=721;
    y = 99999.;
  }
  else {
    y = 0.5*log((E+pz)/(E-pz));
  }
  //cout << "y: E=" << E << " pz=" << pz << " y=" << y << endl;
  return y;
}


} //end usename inline_maths


}  // namespace d0

FASTJET_END_NAMESPACE

#endif
