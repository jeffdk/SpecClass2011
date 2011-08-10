#include <iostream>
#include <cstdlib>

#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "StudentProjects/SpecClass2011/wthrowe/Assignment01wthrowe/MultiplyAddwthrowe.hpp"

int main(int /*argc*/, char** /*argv*/) {
    std::string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double A = parser.Get<double>("A");
    double B = parser.Get<double>("B");
    double C = parser.Get<double>("C");
    double result = MultiplyAdd(A, B, C);
    std::cout << A << " * " << B << " + " << C << " = "
	      << result << std::endl;

    return EXIT_SUCCESS;
}

