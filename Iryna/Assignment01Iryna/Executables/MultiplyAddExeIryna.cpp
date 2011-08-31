#include <iostream>
#include <cstdlib>

#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "libAssignment01Iryna.hpp"

int main(int /*argc*/, char** /*argv*/) {

    std::string opts = ReadFileIntoString("MultiplyAddIryna.input");
    OptionParser parser(opts);
    double a = parser.Get<double>("A");
    double b = parser.Get<double>("B");
    double c = parser.Get<double>("C");

    double final = MultiplyAdd(a, b, c);
    std::cout << "a is " << b << ", b is " << b << ", c is " << c << std::endl;
    std::cout << "a*b + c is: " << final << std::endl;

    return EXIT_SUCCESS;
}

