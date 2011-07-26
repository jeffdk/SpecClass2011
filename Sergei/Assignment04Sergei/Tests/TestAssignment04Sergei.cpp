#include <iostream>
#include <cstdlib>
 
#include "Require.hpp"
#include "OptionParser.hpp"
#include "UtilsForTesting.hpp"
#include "ReadFileIntoString.hpp"
#include "MyVector.hpp"
#include "Volume_Sergei.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
                             
  
  const double PI = 3.1415926535897932;
  MyVector<double> radii(MV::fill,2.0,3.0,4.0,5.0,6.0,7.0,8.0);
  
  double result=0.0;
  std::cout<<"The radii are\n"<<std::endl;
  std::cout<<radii<<std::endl;
  result = TotalVolumeOfSpheresFromRadii(radii);
  std::cout<<"The result is\n"<<std::endl;
  std::cout<<result<<std::endl;
  double answer = 4./3*PI*1295;
 
  double diff = result-answer;
  std::cout<<"The difference between result and right answer is\n"<<std::endl;
  std::cout<<diff<<std::endl;
  REQUIRE(diff<1e-12 && diff>-1e-12, "The computed volume is incorrect!");
  
}
