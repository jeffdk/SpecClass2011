//
// francois hebert, jun 2011
//
// this code reads in an input file "MultiplyAdd.input" which should
// define three numbers a,b,c. it then calculates a*b+c and prints
// the result to stdout.
//

#include <iostream>
#include <cstdlib>

#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "MyAssignment01fhebert.hpp"


int main(int, char**)
{
  std::string args = ReadFileIntoString("MultiplyAdd.input");
  OptionParser parser(args);

  double a = parser.Get<double>("a");
  double b = parser.Get<double>("b");
  double c = parser.Get<double>("c");
  double d = MultAdd(a,b,c);

  std::cout << "  (" << a << " * " << b << ") + " << c << " = " << d << std::endl;

  return EXIT_SUCCESS;
}
