
class MyClass1 {
  public:
  	MyClass1(int c) : cc(c) {}
  	int getvalue() const { return cc;}
  	int getvalue_nonconst() { return cc;}
  private:
  	const int cc;
};
 
#include <iostream>
#include <cstdlib>

using namespace std; 
 
int main(void) {
  /*
	error: no matching function for call to ‘MyClass1::MyClass1()
    The object mine1 of class MyClass1 declared as const, but its data is not 	 		initialized
  */
  // const MyClass1 mine1; // fails to compile 
  
  const MyClass1 mine1a=2;
  const MyClass1 mine1b(2);
  MyClass1 mine1c(2);
  
  /*
	MyClass1Maxim.cpp:8: error: ‘const int MyClass1::cc’ is private
	MyClass1Maxim.cpp:26: error: within this context
  */  
  //int q1=mine1a.cc;// fails to compile
  
  int q2=mine1a.getvalue(); // ok
  int q3=mine1b.getvalue(); // ok

  /*
	error: passing ‘const MyClass1’ as ‘this’ argument of ‘int
	MyClass1::getvalue_nonconst()’ discards qualifiers	
	Object mine1a of class MyClass1 is declared as const, which requires the use of 	const member functions
  */
  //int q4=mine1a.getvalue_nonconst(); // fails to compile
  
  int q5=mine1c.getvalue_nonconst(); // ok
 
  cout << "cc for 'const MyClass1 mine1a=2'  : " << q2 << endl;
  cout << "cc for 'const MyClass1 mine1b(2)' : " << q3 << endl;
  cout << "cc for 'MyClass1 mine1c(2)'       : " << q5 << endl;
 
  return EXIT_SUCCESS;
}
