#include "OutputReducedDatIryna.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/IO/CachedOfStream.hpp"

#include <cstdlib>
#include <fstream>
#include <cmath>

namespace OneDimDataWriters {

  OutputReducedDatIryna::OutputReducedDatIryna(const std::string& opts,
                                               const std::string& BaseName):
     mBaseName(BaseName){
     OptionParser parser(opts, Help());
     mMinAngle = parser.Get<double>("MinAngle");
  }

  void OutputReducedDatIryna::TruncateFile() const {
  }

  void OutputReducedDatIryna::
         AppendToFileImpl(const double time, 
         const MyVector<double>& x,
         const MyVector<double>& y) const {
        
     std::ostringstream outputFile;
     outputFile << mBaseName << ".dat";

     const int size_x = x.Size();
     const int size_y = y.Size();
	
     REQUIRE(size_x == size_y, "Error: Data of x and y must have equal \
				length");
     CachedOfStream outfile(outputFile.str());

     if(size_x == 0){}

     if(size_x > 0){	
        // write first data point
        outfile << DoubleToString(x[0], 16) << ""
                << DoubleToString(y[0], 16) << "\n"; 

        if(size_x > 2){
           for(int i = 1; i < size_x -1; ++i){

              double old_dx = x[i] - x[i-1];
              double old_dy = y[i] - y[i-1];
              double old_angle = atan2(old_dy, old_dx); 

              double dx = x[i+1] - x[i];
              double dy = y[i+1] - y[i];
              double angle = atan2(dy, dx);

              if(angle - old_angle > mMinAngle || old_angle - angle > 
                                                     mMinAngle){
                 outfile << DoubleToString(x[i], 16) << ""
	                << DoubleToString(y[i], 16) << "\n"; 
              }
	 
           }
	}

        // plot last point
        outfile << DoubleToString(x[size_x -1], 16) << ""
                 << DoubleToString(y[size_y -1], 16) << "\n"; 
     }	
	
  }   
}  

