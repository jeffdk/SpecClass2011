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
  a2 = a1; // fails
 
  const MyClass2B b1=2; // ok
  const MyClass2B b2(2); // ok
  MyClass2B b3(2); // ok
  // b3 = 5; // fails
  // b3 = b2; // fails
 
  // const MyClass2C c1=2; // fails
  const MyClass2C c1=static_cast<MyClass2C>(2); // ok
  const MyClass2C c2(2); // ok
  MyClass2C c3(2); // ok
  // c3 = 5; // fails
 
  return EXIT_SUCCESS;
}
