//
//
//

#include "MyLib01fhebert.hpp"

double TopHatWindow(const double x, const double xmin, const double xmax)
{
  double out = x;

  if (x < xmin)
    out = 0.0;
  else if (x > xmax)
    out = 0.0;

  return out;
}

