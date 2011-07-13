#include <cstdlib>
#include <iostream>

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
 
using namespace std;

int main(void) {
 
  const MyClass2A a1=2; // ok
  const MyClass2A a2(2); // ok
  MyClass2A a3(a1); // ok
  a3 = 5; // ok
  a3 = a2; // ok
  
  /*
 	error: passing ‘const MyClass2A’ as ‘this’ argument of ‘MyClass2A& 
	MyClass2A::operator=(const MyClass2A&)’ discards qualifiers

	a2 is const can't change it
  */
  //a2 = a1; // fails
 
  const MyClass2B b1=2; // ok
  const MyClass2B b2(2); // ok
  MyClass2B b3(2); // ok

  /*
	error: non-static const member ‘const int MyClass2B::cc’, can't use default 
	assignment operator

	Can't change the value of a constant member cc in class MyClass2B
  */
  //b3 = 5; // fails
  //b3 = b2; // fails

  /*
	error: conversion from ‘int’ to non-scalar type ‘const MyClass2C’ requested
	key word 'explicit' restricts the default conversion of types
  */ 
  //const MyClass2C c1=2; // fails

  const MyClass2C c1=static_cast<MyClass2C>(2); // ok
  // or in an old school kind of way  
  // const MyClass2C c1=(MyClass2C)(2);

  const MyClass2C c2(2); // ok
  MyClass2C c3(2); // ok

  /* 
	error: no match for ‘operator=’ in ‘c3 = 5’
	Two things: 1) cc is declared as const; 2) 'explicit' restricts default conversion
  */
  //c3 = 5; // fails

  // c3 = static_cast<MyClass2C>(5); // would work if cc wasn't const
  
  cout << "I'm finished" << endl;
  return EXIT_SUCCESS;
}
