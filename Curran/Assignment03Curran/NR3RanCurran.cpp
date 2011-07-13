#include "NR3RanCurran.hpp"

namespace Assignment03Curran {

NR3Ranq2::NR3Ranq2(const uint64_t seed) {
    Reset(seed);
}

void NR3Ranq2::Reset(const uint64_t seed) {
    v = 4101842887655102017LL;
    w = 1;
    v ^= seed;
    w = Next();
    v = Next();
}

uint64_t NR3Ranq2::Next() {
    v ^= v >> 17;
    w = 4294957665U * (w & 0xffffffff) + (w >> 32);
    v ^= v << 31;
    v ^= v >> 8;

    return v ^ w;
}

double NR3Ranq2::NextDouble() {
    return 5.42101086242752217E-20 * Next();
}

}

