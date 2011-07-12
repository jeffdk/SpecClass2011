    #include <iostream>
    #include <cstdlib>
     
    //Declare a class which will generate members that are ints
    class MyClass1 {
      //This are the public functions
      public:
      //This constructs the class, a constant integer
      MyClass1(int c) : cc(c) {}
      //This is a function that promises that the value given is const
      int getvalue() const { return cc;}
      //As above but no such promise
      int getvalue_nonconst() { return cc;}
      private:
      const int cc;
    };
     
     
    int main(void) {
     
      // const MyClass1 mine1; // fails to compile 
      //We are declaring members of this class, they are integers, and constructing them
      //in various ways
      const MyClass1 mine1a=2;
      const MyClass1 mine1b(2);
      MyClass1 mine1c(2); //Not declared a const
      // int q1=mine1a.cc;// fails to compile
      int q2=mine1a.getvalue(); // ok, fills with value of mine1a
      int q3=mine1b.getvalue(); // ok, fills with value of mine1b
      // int q4=mine1a.getvalue_nonconst(); // fails to compile, mine1a is const
      int q5=mine1c.getvalue_nonconst(); // ok, mine1c is not promised to be const
     
      std::cout << "cc for 'const MyClass1 mine1a=2'  : " << q2 << std::endl;
      std::cout << "cc for 'const MyClass1 mine1b(2)' : " << q3 << std::endl;
      std::cout << "cc for 'MyClass1 mine1c(2)'       : " << q5 << std::endl;
     
      return EXIT_SUCCESS;
    }


