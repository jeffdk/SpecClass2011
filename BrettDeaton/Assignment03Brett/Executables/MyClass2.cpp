#include <cstdlib>

//*****************************************************************
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
//*****************************************************************
     
int main(void) {
     
  const MyClass2A a1=2; // ok
  const MyClass2A a2(2); // ok
  MyClass2A a3(2); // ok
  a3 = 5; // ok
  a3 = a2; // ok
  // a2 = a1; // fails: a2 was declared a const object, so we can't just change it willy nilly
     
  const MyClass2B b1=2; // ok
  const MyClass2B b2(2); // ok
  MyClass2B b3(2); // ok
  // b3 = 5; // fails: b3 is not a const object, but its private member cc is. And we are trying to poke around
  //            in there where we don't belong
  // b3 = b2; // fails: even though the values of cc for both of these objects are identical, that's just
  //             coincidence. We're not allowed to make assignments to b3 after construction because it's
  //             member cc is const.
     
  // const MyClass2C c1=2; // fails: because we've defined the MyClass2C constructor to require explicit casts,
  //                          we can't implicitly convert an int into a MyClass2C.
  const MyClass2C c1=static_cast<MyClass2C>(2); // ok
  const MyClass2C c2(2); // ok
  MyClass2C c3(2); // ok
  // c3 = 5; // fails: same as above. The compiler is trying to make the rhs into a MyClass2C, but it can't
  //            for God's sake. Try to be more careful.
     
  return EXIT_SUCCESS;
}
