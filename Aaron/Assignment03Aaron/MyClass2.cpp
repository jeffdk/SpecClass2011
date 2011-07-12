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
        explicit MyClass2C(int c) : cc(c) {} // << CHANGED, no longer converts to int
                                             //automatically, what you feed it must be 
                                             //int
      private:
        const int cc;
    };
     
    int main(void) {
     
      const MyClass2A a1=2; // ok
      const MyClass2A a2(2); // ok
      MyClass2A a3(2); // ok
      a3 = 5; // ok, creates a temporary MyClass for a3 and fills with 5
      a3 = a2; // ok, a3 is a nonconst class, see its construction
      // a2 = a1; // fails, can't change a2
     
      const MyClass2B b1=2; // ok
      const MyClass2B b2(2); // ok
      MyClass2B b3(2); // ok
      // b3 = 5; // fails, bc the cc member in b3 is const and can't be set to 5
      // b3 = b2; // fails, same reason
     
      // const MyClass2C c1=2; // fails
      const MyClass2C c1=static_cast<MyClass2C>(2); // ok, std way of converting
      const MyClass2C c2(2); // ok
      MyClass2C c3(2); // ok
      // c3 = 5; // fails
     
      return EXIT_SUCCESS;
    }


