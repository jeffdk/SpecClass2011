#include "OutputReducedDatIryna.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
//#include "NdData.hpp"
//#include "StringUtils.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/ErrorHandling/Require.hpp"

#include <cstdlib>
#include <fstream>
#include <cmath>

namespace OneDimDataWriters {

 //namespace {
     void OutputReducedDatIryna::
     AppendToFileImpl(const double time, 
       	              const MyVector<double>& x,
		      const MyVector<double>& y) const {
        
	std::ostringstream outputFile;
    	outputFile << mBaseName;
    	//std::ofstream out(outputFile.str().c_str());

        const int size_x = x.Size();
	const int size_y = y.Size();
	
	REQUIRE(size_x == size_y, "Error: Data of x and y must have equal \
					length");
	// write first data point
	outputFile << DoubleToString(x[0], 16) << ""
	    << DoubleToString(y[0], 16) << "\n"; 

	if(size_x > 2){
	   for(int i = 1; i < size_x -1; ++i){

	      double old_dx = x[i] - x[i-1];
	      double old_dy = y[i] - y[i-1];
	      double old_angle = atan2(old_dy, old_dx); 

	      double dx = x[i+1] - x[i];
	      double dy = y[i+1] - y[i];
	      double angle = atan2(dy, dx);

	      if(angle - old_angle > mMinAngle || old_angle - angle > mMinAngle){
  	         outputFile << DoubleToString(x[i], 16) << ""
	             << DoubleToString(y[i], 16) << "\n"; 
	      }
	 
           }
	}

	// plot last point
	outputFile << DoubleToString(x[size_x -1], 16) << ""
	    << DoubleToString(y[size_y -1], 16) << "\n"; 


     }
  }  
//}
