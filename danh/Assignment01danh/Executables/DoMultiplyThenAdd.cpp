#include <iostream>
#include <cstdlib>

#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Arithmetic.hpp"

int main(int /*argc*/, char** /*argv*/) {
    // Read in the input file
    const std::string opts = ReadFileIntoString("MultiplyAdd.input");

    // Parse the input file
    OptionParser parser(opts);
    const double A = parser.Get<double>("A");
    const double B = parser.Get<double>("B");
    const double C = parser.Get<double>("C");

    // Compute and print the result
    const double result = A*B + C;
    std::cout << A << "*" << B << " + " << C << " = " << result << std::endl;
}
