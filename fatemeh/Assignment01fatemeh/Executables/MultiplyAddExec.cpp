
    #include <iostream>
    #include <cstdlib>
     
    #include "OptionParser.hpp"
    #include "ReadFileIntoString.hpp"
    #include "libAssignment01Fatemeh.hpp"
     
    int main( int /*argc*/, char** /*argv*/) {
        std::cout << "Hello world!" << std::endl;
     
        std::string opts = ReadFileIntoString("MultiplyAdd.input");
        OptionParser parser(opts);
        double a = parser.Get<double>("A");
        double b = parser.Get<double>("B");
        double c = parser.Get<double>("C");
        double multadd = MultiplyAdd(a,b,c);
        std::cout <<"A = "<< a <<", B = "<< b <<", C = "<< c << std::endl;
        std::cout << "A*B+C = " << multadd << std::endl;
     
        return EXIT_SUCCESS;
    }

