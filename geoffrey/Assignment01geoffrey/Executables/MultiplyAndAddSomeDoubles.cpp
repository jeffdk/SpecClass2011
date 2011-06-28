#include <iostream>
#include <cstdlib>

#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"

int main(void)
{  
  //Create an option parser from the string from file MultiplyAdd.input
  //Then read in the 3 doubles A, B, C
  //Set default values to zero, so if a double is not specified, you 
  //still get a meaningful result and not an error.
  
  OptionParser p(ReadFileIntoString("MultiplyAdd.input"));
  const double A = p.Get<double>("A",0.);
  const double B = p.Get<double>("B",0.);
  const double C = p.Get<double>("C",0.);

  //compute the result
  const double result = A*B+C;

  //print out the result
  std::cout << A << " * " << B << " + " << C << " = " << result << std::endl;

  return EXIT_SUCCESS;
}
