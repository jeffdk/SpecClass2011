#include "MyVector.hpp"
#include "Require.hpp"
#include "Assignment02Aaron.hpp"
 
MyVector<double> sumVectors(const MyVector<double>& A,
                            const MyVector<double>& B, const double C) {
 
  //Test that the vectors are the same size                                    
  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size.\n");

  //Make two new MyVector<double> of the same size as the 
  //addends and fill it with zeroes                                                
 
  const int vectorSize = A.Size(); //length of each vector                      
  MyVector<double> sum(MV::Size(vectorSize), 0.);
  MyVector<double> result(MV::Size(vectorSize), 0.);
 
  //Add the vectors component-by-component                                      
  //Use the MyVector member function operator[](int i) which returns the        
  //the ith component of the vector.
  //Then the result is each component divided by
  //the double c. I'm doing this really inefficiently
  //simply because I don't know how C++ does order of operations.
                                        
 
  for(int i=0; i<vectorSize; ++i) {
    sum[i] = A[i] + B[i];
    result[i] = sum[i]/C;
  }
 
  //Return the result                                                           
 
  return result;
}
