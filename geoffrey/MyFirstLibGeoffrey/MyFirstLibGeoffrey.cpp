#include "MyFirstLibGeoffrey.hpp"

double ImposeCap(const double x, const double max) {
  if (x < max) {
    return x;
  } else {
    return max;
  }
}
