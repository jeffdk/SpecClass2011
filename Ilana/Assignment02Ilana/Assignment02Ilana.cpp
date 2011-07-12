#include "MyVector.hpp"
#include "Assignment02Ilana.hpp"
#include "Require.hpp"
 
MyVector<double> sumVectors(const MyVector<double>& A,
                            const MyVector<double>& B, const double C) {

  REQUIRE(A.Size() == B.Size(), "Error: Vectors are not the same size!");
 
  //Make a new MyVector<double> of the same size as the addends                 
  //Fill each element with zero.                                                
 
  const int vectorSize = A.Size(); //length of each vector                      
  MyVector<double> sum(MV::Size(vectorSize), 0.);
 
  //Add the vectors component-by-component and divide the answer by
  //a constant C                                    
  //Use the MyVector member function operator[](int i) which returns the        
  //the ith component of the vector.                                            
 
  for(int i=0; i<vectorSize; ++i) {
    sum[i] = (A[i] + B[i])/C;
  }
 
  //Return the result                                                           
 
  return sum;
}
