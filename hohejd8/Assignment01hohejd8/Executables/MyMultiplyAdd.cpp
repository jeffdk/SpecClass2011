#include <iostream>
#include <cstdlib>

#include "MultiplyAddhohejd8.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"

using namespace std;

int main(int /*argc*/, char** /*argv*/){
   std::string opts = ReadFileIntoString("MultiplyAdd.input");
   OptionParser p(opts);
   
   double a = p.Get<double>("A");
   double b = p.Get<double>("B");
   double c = p.Get<double>("C");

   cout << "A = " << a << endl;
   cout << "B = " << b << endl;
   cout << "C = " << c << endl;
   cout << "A*B + C = " << MultiplyAddhohejd8(a, b, c) << endl;

   return EXIT_SUCCESS;
}
