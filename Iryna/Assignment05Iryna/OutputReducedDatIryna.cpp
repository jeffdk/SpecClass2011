#include "OutputReducedDatIryna.hpp"
#include "OptionParser.hpp"
#include "NdData.hpp"
#include "StringUtils.hpp"
#include "ConvertNumberToString.hpp"

#include <cstdlib>
#include <fstream>
#include <cmath>

namespace OneDimDataWriters {

  namespace {
     void OutputReducedDatIryna::
     AppendToFileImpl(const double t, 
       	              const MyVector<double>& x,
		      const MyVector<double>& y) const {

        const int size_x = x.Size();
	const int size_y = y.Size();
	
	REQUIRE(size_x == size_y, "Error: Data of x and y must have equal \
					length");
	if(size_x < 2)

	if(size_x > 2){
	   old_dx = x[1] - x[0];
	   old_dy = y[1] - y[0];
	   old_angle = tan(old_dy / old_dx); 
        
	}

     }
  }  
}
