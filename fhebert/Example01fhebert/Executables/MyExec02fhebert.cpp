//
// as myevex01, but now we parse from an input file !
//

#include <iostream>
#include <cstdlib>

#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "MyLib01fhebert.hpp"


int main(int, char**)
{
  std::cout << std::endl << "hello world!" << std::endl << std::endl;

  std::string opts = ReadFileIntoString("WindowData.input");
  OptionParser parser(opts);

  double x0 = parser.Get<double>("val0");
  double x1 = parser.Get<double>("val1");
  double x2 = parser.Get<double>("val2");
  double xmin = parser.Get<double>("xmin");
  double xmax = parser.Get<double>("xmax");

  std::cout << "window zeroes everything outside of [" << xmin << "," << xmax << "]" << std::endl;

  std::cout << "some values before and after window:" << std::endl;
  std::cout << "x0 : " << x0 << "\t-->\t" << TopHatWindow(x0,xmin,xmax) << std::endl;
  std::cout << "x1 : " << x1 << "\t-->\t" << TopHatWindow(x1,xmin,xmax) << std::endl;
  std::cout << "x2 : " << x2 << "\t-->\t" << TopHatWindow(x2,xmin,xmax) << std::endl;
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
