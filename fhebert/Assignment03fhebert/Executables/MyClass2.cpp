
#include <cstdlib>


class MyClass2A
{
  public:
  MyClass2A(int c) : cc(c) {}

  private:
  int cc;
};


class MyClass2B
{
  public:
  MyClass2B(int c) : cc(c) {}

  private:
  const int cc;
};


class MyClass2C
{
  public:
  explicit MyClass2C(int c) : cc(c) {}

  private:
  const int cc;
};


int main(void)
{
  // test cases on 2A
  const MyClass2A a1=2;
  const MyClass2A a2(2);
  MyClass2A a3(2);

  a3 = 5;
  a3 = a2;
  //a2 = a1;
  // fails because we declared a2 as const instance of MyClass2A
  // => can't modify the instance in any way.


  // test cases on 2B
  const MyClass2B b1=2;
  const MyClass2B b2(2);
  MyClass2B b3(2);
  
  //b3 = 5;
  //b3 = b2;
  // here, b3 is a non-const instance of MyClass2B and so it can be modified.
  // however, both of these fail because the variable MyClass2B.cc is declared
  // const and so we can't reassign it.


  // test cases on 2C
  // const MyClass2C c0=2; 
  // this first one fails because MyClass2C has an explicit constructor
  // => can't create by typecasting a MyClass from an int.
  const MyClass2C c1=static_cast<MyClass2C>(2);
  const MyClass2C c2(2);
  MyClass2C c3(2);
  //c3 = 5;
  // this fails for the same reason: 5 must be typecast into a MyClass2C
  // before c3 can be set equal to it. this is prevented by the explicit
  // constructor.

  return EXIT_SUCCESS;
}
