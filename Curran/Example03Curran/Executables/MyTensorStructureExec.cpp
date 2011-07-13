#include <cstdlib>
#include <iostream>

#include "TensorStructure.hpp"
     
int main(int /*argc*/, char** /*argv*/) {
    // the integer sets the dimension (range of indices = 0..dim-1)
    // the string sets the symmetries
    // the length of the string set the rank
    const TensorStructure nonsymmetric(3, "ab");
    const TensorStructure symmetric(3, "aa");
    const TensorStructure mixed(4, "abb"); // e.g., for GhKappa
   
    std::cout << "mixed tensor structure: " << mixed << std::endl;
    std::cout << "mixed tensor structure dim: " << mixed.Dim() << std::endl;
    std::cout << "mixed tensor structure rank: " << mixed.Rank() << std::endl;
    std::cout << "mixed tensor structure specs: " << mixed.Spec() << std::endl;
   
    return EXIT_SUCCESS;
}

