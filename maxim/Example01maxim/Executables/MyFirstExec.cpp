#include <iostream>
#include <cstdlib>
 
#include "MyFirstLibMaxim.hpp"
 
using namespace std;

int main(int /*argc*/, char** /*argv*/) {
    cout << "Hello world2!" << endl;
 
    double x = 5.5;
    double cap = 5.0;
    double x_capped = ImposeCap(x, cap);
    cout << "x is " << x << ", cap is " << cap << endl;
    cout << "The capped value of x is " << x_capped << endl;
 
    return EXIT_SUCCESS;
}
