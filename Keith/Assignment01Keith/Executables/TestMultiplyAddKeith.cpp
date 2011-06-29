#include <iostream>
#include <cstdlib>

#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "MultiplyAddKeith.hpp"

int main(int /*argc*/, char** /*argv*/) {
  std::string opts = ReadFileIntoString("MultiplyAdd.input");
  OptionParser parser(opts);
  const double a = parser.Get<double>("A");
  const double b = parser.Get<double>("B");
  const double c = parser.Get<double>("C");

  const double res = MultiplyAdd(a, b, c);

  std::cout << "A = " << a << ", B = " << b << " and C = " << c 
            << std::endl;
  std::cout << "A * B + C = " << res << std::endl;

  return EXIT_SUCCESS;
}
