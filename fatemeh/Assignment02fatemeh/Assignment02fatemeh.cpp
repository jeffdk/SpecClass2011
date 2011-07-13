#include <MyVector.hpp>
#include <Assignment02fatemeh.hpp>
#include <Require.hpp>

MyVector<double> div_sumVectors(const MyVector<double>& A, const MyVector<double>& B,const double& C)
{
  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size.\n");
  REQUIRE(C != 0.0, "Error: Constant double should be nonzero!\n");
  int vectorSize = A.Size();
  MyVector<double> sum(MV::Size(vectorSize),0.0);
  MyVector<double> sum_div(MV::Size(vectorSize),0.0);
  for (int i=0; i<vectorSize ;i++){
    sum[i] = A[i]+B[i];
    sum_div[i] = sum[i]/C;
  }
  return sum_div;
}
