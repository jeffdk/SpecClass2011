#include <iostream>

// Problem0Example1.cpp
void f(double& x) {
   x = 3;
}
int main() {
  double x = 6;
  f(x);
  std::cout << x << std::endl;
}
