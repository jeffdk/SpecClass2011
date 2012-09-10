#include <iostream>
#include <cstdlib>
 
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "StudentProjects/SpecClass2011/jwendell/Assignment01jwendell/MultAddjwendell.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
  
  std::cout << " Reading in Info!!!" << std::endl;

  std::string opts = ReadFileIntoString("Math.input");
  OptionParser parser(opts);
  double A0 = parser.Get<double>("A");
  double B0 = parser.Get<double>("B");
  double C0 = parser.Get<double>("C");
  double Answer = MultAdd(A0,B0,C0);
  std::cout << " A is " << A0 << ", B is " << B0 << ", C is " << C0 << std::endl;
  std::cout << " A*B+C =" << Answer << std::endl;

  return EXIT_SUCCESS;
}
