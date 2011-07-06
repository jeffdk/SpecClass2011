    #include <iostream>
    #include <cstdlib>
     
    #include "OptionParser.hpp"
    #include "ReadFileIntoString.hpp"
    #include "MultiplyAddAaron.hpp"
     
    int main(int /*argc*/, char** /*argv*/) {
        
        std::string opts = ReadFileIntoString("MultiplyAdd.input");
        OptionParser parser(opts);
        double A = parser.Get<double>("A");
	double B = parser.Get<double>("B");
	double C = parser.Get<double>("C");
        double R = MultiplyAdd(A,B,C);
        std::cout << "A is " << A << ", B is " << B << ", C is " << C << std::endl;
        std::cout << "The result R= A*B + C is " << R << std::endl;
     
        return EXIT_SUCCESS;
    }


