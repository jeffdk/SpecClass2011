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
      // a2 = a1; // fails
      // Because we declare a2 as a constant.
     
      const MyClass2B b1=2; // ok
      const MyClass2B b2(2); // ok
      MyClass2B b3(2); // ok
      // b3 = 5; // fails
      // because the private member of MyClass2B (cc) is a constant and can not use default assignment operator.
      // b3 = b2; // fails
      // The same reason as above, b3 can not change even if b2 has the same value.
     
      // const MyClass2C c1=2; // fails
      // explicit conversion does not allow to have assignment operator as MyClass2C=int.(They are from different type.)
      const MyClass2C c1=static_cast<MyClass2C>(2); // ok
      const MyClass2C c2(2); // ok
      MyClass2C c3(2); // ok
      c3 = 5; // fails
      // cc is constant so c3 is declared as constant so we can not  change it.
      return EXIT_SUCCESS;
    }

