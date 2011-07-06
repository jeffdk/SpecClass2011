#include <TensorStructure.hpp>

int main(void) {

  // the integer sets the dimension (range of indices = 0..dim-1)
  // the string sets the symmetries
  // the length of the string set the rank
  const TensorStructure nonsymmetric(3, "ab");
  const TensorStructure symmetric(3, "aa");
  const TensorStructure mixed(4, "abb"); // e.g., for GhKappa

  std::cout << "mixed tensor structure:"<<mixed<<"\n";
  std::cout << "mixed tensor structure dim:"<<mixed.Dim()<<"\n";
  std::cout << "mixed tensor structure rank:"<<mixed.Rank()<<"\n";
  std::cout << "mixed tensor structure specs:"<<mixed.Spec()<<"\n";

  return 0;
}