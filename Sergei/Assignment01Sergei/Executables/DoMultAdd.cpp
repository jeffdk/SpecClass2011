#include <iostream>
#include <cstdlib>
 
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "MultiplyAddSergei.hpp"

int main(int /*argc*/, char** /*argv*/) {
   
  // Read in the input values using the OptionParser
  std::string opts = ReadFileIntoString("MultiplyAdd.input");
  OptionParser parser(opts);
  double A = parser.Get<double>("A");
  double B = parser.Get<double>("B");
  double C = parser.Get<double>("C");
  
  // Perform A*B+C
  double result = MultiplyAdd(A,B,C);
  
  //Output the result
  std::cout  << A << " * " << B<<" + " << C << " is" << std::endl;
  std::cout << result  << std::endl;
  
  // Return successful termination
  return EXIT_SUCCESS;
}
