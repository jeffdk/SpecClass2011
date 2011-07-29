#include <iostream>
double& add(const double& a, const double& b) { 
   double c = a + b;
   return c;
}
int main() {
  double x  = 6;
  double y  = 5;
  double& z = add(x,y);
  std::cout << x << " " << y << " " << z << std::endl;
}
