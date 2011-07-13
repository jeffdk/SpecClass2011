#include "RaiseToPower_Curran.hpp"

unsigned int RaiseToPower(const unsigned int a, const unsigned int n) {
    if (n == 0) return 1;
    if (n > 1) return a*RaiseToPower(a, n-1);
    return a;
}

