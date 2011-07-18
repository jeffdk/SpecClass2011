#include <iostream>
#include <cstdlib>
 
class MyClass1
{
  public:
  MyClass1(int c) : cc(c) {}
  int getvalue() const { return cc;}
  int getvalue_nonconst() { return cc;}
  private:
  const int cc;
};
              
               
int main(void)
{                
  // const MyClass1 mine1; // fails to compile
  // there is no default constructor that would work without arguments
  // this is because we want to be sure to initialize the variable cc
 
  const MyClass1 mine1a=2;
  const MyClass1 mine1b(2);
  MyClass1 mine1c(2);
 
  // int q1=mine1a.cc;// fails to compile
  // member variable cc is private, can't access it this way
 
  int q2=mine1a.getvalue(); // ok
  int q3=mine1b.getvalue(); // ok

  // int q4=mine1a.getvalue_nonconst(); // fails to compile
  // can't call a non-const function of a const instance of a class
  // this is to guarantee you won't accidentally modify the class instance
 
  int q5=mine1c.getvalue_nonconst(); // ok
                                
  std::cout << "cc for 'const MyClass1 mine1a=2'  : " << q2 << std::endl;
  std::cout << "cc for 'const MyClass1 mine1b(2)' : " << q3 << std::endl;
  std::cout << "cc for 'MyClass1 mine1c(2)'       : " << q5 << std::endl;
                                          
  return EXIT_SUCCESS;
}
