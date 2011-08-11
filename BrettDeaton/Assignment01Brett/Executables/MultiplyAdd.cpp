#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "StudentProjects/SpecClass2011/BrettDeaton/Assignment01Brett/MultiplyAddBrett.hpp"

#include <iostream>
#include <cstdlib>

int main(int /*argc*/, char** /*argv*/) {
    std::string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double A = parser.Get<double>("A");
    double B = parser.Get<double>("B");
    double C = parser.Get<double>("C");
    std::cout << "A = " << A
	      << ", B = " << B
	      << ", C = " << C
	      << std::endl;
    std::cout << "A*B+C = " << A*B+C << std::endl;

    return EXIT_SUCCESS;
}

