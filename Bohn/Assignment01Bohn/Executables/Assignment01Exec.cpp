#include <iostream>
#include <cstdlib>

#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "StudentProjects/SpecClass2011/Bohn/Assignment01Bohn/Assignment01Bohn.hpp"

int main(int /*argc*/, char** /*argv*/) {
	std::string opts = ReadFileIntoString("MultiplyAdd.input");
	OptionParser parser(opts);
	double mult1 = parser.Get<double>("A");
	double mult2 = parser.Get<double>("B");
	double add   = parser.Get<double>("C");
	double multiply_add_result = MultiplyAdd(mult1, mult2, add);
	std::cout << "A is " << mult1 << ", B is " << mult2 << ", C is " << add << std::endl;
	std::cout << "The value of A * B + C is " << multiply_add_result << std::endl;

    return EXIT_SUCCESS;
}

