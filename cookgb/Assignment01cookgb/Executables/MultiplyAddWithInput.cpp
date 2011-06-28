#include <iostream>
#include <cstdlib>
 
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "MultiplyAddcookgb.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
    std::cout << "A simple app to multiply two numbers and add a third!" 
	      << std::endl;
 
    std::string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double a = parser.Get<double>("A");
    double b = parser.Get<double>("B");
    double c = parser.Get<double>("C");
    double result = MultiplyAdd(a,b,c);
    std::cout << "a is " << a 
	      << ", b is " << b 
	      << ", c is " << c 
	      << std::endl;
    std::cout << "The value of a*b+c is " << result << std::endl;
 
    return EXIT_SUCCESS;
}

