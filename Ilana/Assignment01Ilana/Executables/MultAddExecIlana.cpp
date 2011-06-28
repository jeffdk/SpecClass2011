#include <iostream>
#include <cstdlib>
 
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "libAssignment01Ilana.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
    std::string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double a = parser.Get<double>("First multiplied value");
    double b = parser.Get<double>("Second multiplied value");
    double c = parser.Get<double>("Added value");
    double answer = MultiplyAdd(a, b, c);
    std::cout << "a is " << a << ", b is " << b << ", c is " << c << std::endl;
    std::cout << "The answer to a time b plus c is " << answer << std::endl;
 
    return EXIT_SUCCESS;
}
