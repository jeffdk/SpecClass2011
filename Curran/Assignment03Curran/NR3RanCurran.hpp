#ifndef ASSIGNMENT03CURRAN_NR3RANCURRAN_HPP_
#define ASSIGNMENT03CURRAN_NR3RANCURRAN_HPP_

//#include <cstdint>
#include <stdint.h>

namespace Assignment03Curran {

class NR3Ranq2 {
  public:
    NR3Ranq2(uint64_t seed);
    void Reset(uint64_t seed);
    uint64_t Next();
    double NextDouble();

  private:
    uint64_t v;
    uint64_t w;
};

}

#endif /* ASSIGNMENT03CURRAN_NR3RANCURRAN_HPP_ */

