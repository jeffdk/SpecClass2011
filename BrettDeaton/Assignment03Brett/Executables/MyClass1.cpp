#include <iostream>
#include <cstdlib>
#include "Utils/LowLevelUtils/Ran2Class.hpp"
     
class MyClass1 {
public:
  MyClass1(int c) : cc(c) {}
  int getvalue() const { return cc;}
  int getvalue_nonconst() { return cc;}
private:
  const int cc;
};
     
     
int main(void) {
     
  // const MyClass1 mine1; // fails to compile: we haven't defined a constructor without arguments
  const MyClass1 mine1a=2;
  const MyClass1 mine1b(2);
  MyClass1 mine1c(2);
  // int q1=mine1a.cc;// fails to compile: cc is a clandestine member of MyClass1, we don't need to know about it
  int q2=mine1a.getvalue(); // ok
  int q3=mine1b.getvalue(); // ok
  // int q4=mine1a.getvalue_nonconst(); // fails to compile: mine1a is a const object, and the compiler has no way
  //                                       to know that the function getvalue_nonconst() is not modifying it, so,
  //                                       like an over-cautious parent it throws a compile error, keeping us safe.
  int q5=mine1c.getvalue_nonconst(); // ok
     
  std::cout << "cc for 'const MyClass1 mine1a=2'  : " << q2 << std::endl;
  std::cout << "cc for 'const MyClass1 mine1b(2)' : " << q3 << std::endl;
  std::cout << "cc for 'MyClass1 mine1c(2)'       : " << q5 << std::endl;

  return EXIT_SUCCESS;
}
