#include <Tensor.hpp>
#include <Require.hpp>

int main(void) {

  TensorStructure s(3,"aa"); // we create the TensorStructure first
  Tensor<double> t1(s, 0.0); // make a tensor from the structure and 
                             // set all its elements to zero
  Tensor<double> t2(3,"aa", 0.0);   // the same as before

  t2.assign(3,"ab",2);              // change tensor content
  t2 = t1;                          // this is also fine
  t2 = Tensor<double>(3,"aa", 0.0); // correct, but *** inefficient ***

  Tensor<double> t3(3,"aa");  // uninitialized doubles
  t3 = t1;                    // you can do this
  t3.assign(t1.Structure());  //this will set the structure, not the values

  t1(1,2) = 2; // will test the symmetry of t1
  std::cout << "This better be TWO:: t1(2,1)="<<t1(2,1)<<"\n";
}
