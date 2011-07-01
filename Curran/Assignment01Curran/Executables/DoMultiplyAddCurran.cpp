#include <cstdlib>
#include <string>
#include <iostream>
 
#include "MultiplyAddCurran.hpp"
#include "ReadFileIntoString.hpp"
#include "OptionParser.hpp"

/** \file
 * Performs a multiply-add operation on values read from an input file.
 * The resulting executable "DoMultiplyAddCurran" will read the file
 * "MultiplyAdd.input", parse the 'double' options "A", "B", and "C", and print
 * the value of A*B+C.
 */
 
int main(int /*argc*/, char** /*argv*/) {
    // Read and parse input
    std::string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double a = parser.Get<double>("A");
    double b = parser.Get<double>("B");
    double c = parser.Get<double>("C");

    // Compute result
    double result = MultiplyAdd(a, b, c);

    // Perform output
    std::cout << "A is " << a << ", B is " << b << ", C is " << c << std::endl;
    std::cout << "The value of A*B+C is " << result << std::endl;
 
    return EXIT_SUCCESS;
}

