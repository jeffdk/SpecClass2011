#include <iostream>
#include <cstdlib>
 
#include "MyFirstLibBrett.hpp"
 
int main(int argc, char** argv) {
    std::cout << "Hello world!" << std::endl;
 
    
    if(argc==1)
      {
	std::cout << "You must provide a number as an argument of this program\n";
	return EXIT_FAILURE;
      }
    else
      {
	double x = atof(argv[1]);
	double cap = 5.0;
	double x_capped = ImposeCap(x, cap);
	std::cout << "x is " << x << ", cap is " << cap << std::endl;
	std::cout << "The capped value of x is " << x_capped << std::endl;
      }
    
    return EXIT_SUCCESS;
}
