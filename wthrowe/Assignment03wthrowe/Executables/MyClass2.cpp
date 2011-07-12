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
  // You can't reassign a const value (in this case because the implicit
  // operator= isn't const).
  // a2 = a1; // fails
 
  const MyClass2B b1=2; // ok
  const MyClass2B b2(2); // ok
  MyClass2B b3(2); // ok
  // You can't assign to the const member b3.cc (through the default operator=)
  // b3 = 5; // fails
  // ditto
  // b3 = b2; // fails
 
  // Can't implicitly convert an int to a MyClass2C.
  // const MyClass2C c1=2; // fails
  const MyClass2C c1=static_cast<MyClass2C>(2); // ok
  const MyClass2C c2(2); // ok
  MyClass2C c3(2); // ok
  // Can't implicitly convert an int to a MyClass2C to pass to operator=
  // c3 = 5; // fails
 
  return EXIT_SUCCESS;
}
