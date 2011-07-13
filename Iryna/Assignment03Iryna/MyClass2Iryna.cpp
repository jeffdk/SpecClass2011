#include <cstdlib>
class MyClass2A {
  public:
    MyClass2A(int c) : cc(c) {}
  private:
    int cc;
};
 
class MyClass2B {
  public:
    MyClass2B(int c) : cc(c) {}
  private:
    const int cc; // << CHANGED
};
 
 
class MyClass2C {
  public:
    explicit MyClass2C(int c) : cc(c) {} // << CHANGED
  private:
    const int cc;
};
 
int main(void) {
 
  const MyClass2A a1=2; // ok
  const MyClass2A a2(2); // ok
  MyClass2A a3(2); // ok
  a3 = 5; // ok
  a3 = a2; // ok
// can't assign a new value to a const MyClass2A instance
// a2 = a1; // fails --> gives "error: passing 'const MyClass2A' as 'this' argument
 
  const MyClass2B b1=2; // ok
  const MyClass2B b2(2); // ok
  MyClass2B b3(2); // ok
// The value held in b3 is a constant, even if we don't specifically say so in the declaration
   // b3 = 5; // fails-->"error: non-static const member.. can't use default assignment operator
   // b3 = b2; // fails--> same error message as above; note: synthesized method 'MyClass2b& MyClass2B::operator=(const MyClass2B&)' first required here.
 
// Can't initialize in this way because of "explicit" call
// const MyClass2C c1=2; // fails-->"error: conversion from 'int' to non-scalar type 'const MyClass2c' requested"
  const MyClass2C c1=static_cast<MyClass2C>(2); // ok
  const MyClass2C c2(2); // ok
  MyClass2C c3(2); // ok
// Can't change the value of c3 because it's const. Even if it wasn't const, we still can't change the value in this format because of "explicit" use
// c3 = 5; // fails-->"error: no match for 'operator=' in 'c3=5'; note: candidate is: MyClass2C& MyClass2C::operator=(const MyClass2C&)"
 
  return EXIT_SUCCESS;
}
