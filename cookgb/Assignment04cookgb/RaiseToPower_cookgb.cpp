#include "RaiseToPower_cookgb.hpp"
// Compute a^n
unsigned int RaiseToPower(unsigned int a,  unsigned int n) {
  if(0==n) return 1;
  if(1<n) return a*RaiseToPower(a,n-1);
  return a;
}
