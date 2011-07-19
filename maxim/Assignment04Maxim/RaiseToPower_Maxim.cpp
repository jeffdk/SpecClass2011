#include "RaiseToPower_Maxim.hpp"
// Compute a^n
unsigned int RaiseToPower(const unsigned int a, const unsigned int n) {
  if(0 == n) return 1;
  if(n > 1) return a*RaiseToPower(a,n-1);
  return a;
}
