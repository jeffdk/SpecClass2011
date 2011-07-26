#include <iostream>

// Compute a^n
unsigned int RaiseToPower(unsigned int a,  unsigned int n) {
  if(n==0) return 1;
  if(n>1) return a*RaiseToPower(a,n-1);
  return a;
}

int main() {
  std::cout << "2^3 = " << RaiseToPower(2,3) << std::endl;
}
