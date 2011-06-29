//
//
//

#include <iostream>
#include <cstdlib>

#include "MyLib01fhebert.hpp"

int main(int, char**)
{
  std::cout << std::endl << "hello world!" << std::endl << std::endl;

  double x0 = 3.2;
  double x1 = 4.823;
  double x2 = 12349.0;
  double xmin = 4.0;
  double xmax = 5.0;

  std::cout << "window zeroes everything outside of [" << xmin << "," << xmax << "]" << std::endl;

  std::cout << "some values before and after window:" << std::endl;
  std::cout << "x0 : " << x0 << "\t-->\t" << TopHatWindow(x0,xmin,xmax) << std::endl;
  std::cout << "x1 : " << x1 << "\t-->\t" << TopHatWindow(x1,xmin,xmax) << std::endl;
  std::cout << "x2 : " << x2 << "\t-->\t" << TopHatWindow(x2,xmin,xmax) << std::endl;
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
