#include "Utils/MyContainers/MyVector.hpp"
#include "Assignment02Iryna.hpp"

#include "Utils/ErrorHandling/Require.hpp"

MyVector<double> addDivideVectors(const MyVector<double>& A,
                            const MyVector<double>& B, const double C) {

  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size. \n");

  //Make a new MyVector<double> of the same size as the addends                 
  //Fill each element with zero.                                                

  const int vectorSize = A.Size(); //length of each vector                      
  MyVector<double> result(MV::Size(vectorSize), 0.);

  //Add the vectors component-by-component                                      
  //Use the MyVector member function operator[](int i) which returns the        
  //the ith component of the vector.                                            

  for(int i=0; i<vectorSize; ++i) {
    result[i] = (A[i] + B[i]) / C;
  }

  //Return the result                                                           

  return result;
}

