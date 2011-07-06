#include "MyVector.hpp"
#include "Assignment02jeffdk.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"
 
MyVector<double> sumVectorsThenDivide(const MyVector<double>& A,
				      const MyVector<double>& B,
				      const double divsor ) {
  //Check that the vectors are the same size                                    
  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size.\n");

  //Do Question 1. of the assignment.  Part a) UtilsForTesting Part b)
  //  ASSERT, which will trigger termination of the code if compiled
  //  with DEBUG.  Also, we can REQUIRE, which will terminate the code
  //  in any case if the condition is not met.

  //  Pick which part we want to do
  const char Part = 'a';
   
  if ( Part == 'b'  ||  Part == 'B') {
    // Note, UtilsForTesting does not explicitly have a IS_NONZERO
    //  macro.  I had to get creative and use the example described in
    //  the doxygen comments for Finite.hpp.
    
    //  If divsor is zero, 1.0/divsor should be Inf, -Inf, or NaN
    //  then, 1.0/divsor - 1.0/divsor will not give 0.0, which it
    //  should give if divisor is non-zero.
    IS_ZERO( 1.0/divsor - 1.0/divsor, 
	     "Divsor in sumVectorsThenDivide is zero! BAD!");
  }
  else if (Part == 'a' ||  Part == 'A'){
      ASSERT( divsor != 0.0,
	      "Divsor in sumVectorsThenDivide is zero! =( " );
      REQUIRE( divsor != 0.0,
	       "Divsor in sumVectorsThenDivide is zero! ;_; " );
  }
  else    {
    REQUIRE(false,
	    "You must pick Part to be 'a' (check with ASSERT/REQUIRE) or "
	    << " 'b' (check with UtilsForTesting)" );
  }

  //Make a new MyVector<double> of the same size as the addends                 
  //Fill each element with zero.                                                
 
  const int vectorSize = A.Size(); //length of each vector                      
  MyVector<double> sum(MV::Size(vectorSize), 0.);
 
  //Add the vectors component-by-component                                      
  //Use the MyVector member function operator[](int i) which returns the        
  //the ith component of the vector.                                            
 
  for(int i=0; i<vectorSize; ++i) {
    sum[i] = A[i] + B[i];
    sum[i] /= divsor;
  }
 
  //Return the result 
  // Note: if we are doing part b, we won't stop the
  // code if divisor is zero.  This is bad in the everyday case
  // because the sum vector will have NaNs or Infs!
  return sum;
}
