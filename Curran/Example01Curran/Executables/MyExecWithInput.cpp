#include <cstdlib>
#include <string>
#include <iostream>
 
#include "MyFirstLibCurran.hpp"
#include "ReadFileIntoString.hpp"
#include "OptionParser.hpp"

/** \file
 * Caps a value at a certain threshold, where both the threshold and the
 * original value are provided in the input file "ImposeCap.input".
 */
 
int main(int /*argc*/, char** /*argv*/) {
    std::cout << "Hello world!" << std::endl;
 
    std::string opts = ReadFileIntoString("ImposeCap.input");
    OptionParser parser(opts);
    double x = parser.Get<double>("Value");
    double cap = parser.Get<double>("Cap");
    double x_capped = ImposeCap(x, cap);
    std::cout << "x is " << x << ", cap is " << cap << std::endl;
    std::cout << "The capped value of x is " << x_capped << std::endl;
 
    return EXIT_SUCCESS;
}

