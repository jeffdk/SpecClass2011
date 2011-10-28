    #include <iostream>
    #include <cstdlib>
     
    #include "StudentProjects/SpecClass2011/Casey/Example01Casey/MyFirstLibCasey.hpp"
     
    int main(int /*argc*/, char** /*argv*/) {
        std::cout << "Hello world!" << std::endl;
     
        double x = 5.5;
        double cap = 5.0;
        double x_capped = ImposeCap(x, cap);
        std::cout << "x is " << x << ", cap is " << cap << std::endl;
        std::cout << "The capped value of x is " << x_capped << std::endl;
     
        return EXIT_SUCCESS;
    }

