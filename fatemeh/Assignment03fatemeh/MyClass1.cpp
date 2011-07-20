#include <iostream>
#include <cstdlib>
 
class MyClass1 {
  public:
  MyClass1(int c) : cc(c) {}
  int getvalue() const { return cc;}
  int getvalue_nonconst() { return cc;}
  private:
  const int cc;
};
 
 
int main(void) {
 
  //const MyClass1 mine1; // fails to compile
  //because it does not follow the way that the contructor has been defined, and  the value of the integer should be specified at the time of declaration.
  const MyClass1 mine1a=2;
  const MyClass1 mine1b(2);
  MyClass1 mine1c(2);
  //int q1=mine1a.cc;// fails to compile
  //It failed because cc is a private member of MyClass1 and should not be called in the main function. 
  int q2=mine1a.getvalue(); // ok
  int q3=mine1b.getvalue(); // ok
  //int q4=mine1a.getvalue_nonconst(); // fails to compile
  //because we mine1a has been specified as a const in line 17.
  int q5=mine1c.getvalue_nonconst(); // ok
 
  std::cout << "cc for 'const MyClass1 mine1a=2'  : " << q2 << std::endl;
  std::cout << "cc for 'const MyClass1 mine1b(2)' : " << q3 << std::endl;
  std::cout << "cc for 'MyClass1 mine1c(2)'       : " << q5 << std::endl;
 
  return EXIT_SUCCESS;
}
