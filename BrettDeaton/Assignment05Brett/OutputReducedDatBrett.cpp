#include "OutputReducedDatBrett.hpp"
#include "StringUtils.hpp"
#include "MyVector.hpp"
#include "ConvertNumberToString.hpp"
#include <cmath>
#include <fstream>

namespace OneDimDataWriters {

  double OutputReducedDatBrett::ComputeAngleFromHorizon(const double xi, const double xii,
							const double yi, const double yii) const {
    double slope = (yii-yi)/(xii-xi);
    return arctan(slope);
  }
    
  
  void OutputReducedDatBrett::AppendToFileImpl(const double time,
					       const MyVector<double>& x,
					       const MyVector<double>& y) const {
    REQUIRE(x.Size()==y.Size(),
	    "Error: ordinate and abscissa vectors are not the same size.");
    int precision = 16;

    const double pi = 3.141592653589793;
    double lastAngle;
    double nextAngle = ComputeAngleFromHorizon(x[0],x[1],
					       y[0],y[1]);
    mOut << "# time = " << DoubleToString(time, precision) << std::endl;
    mOut << x[0] << "   " << y[0] << std::endl;
    for(int i=1; i<(x.Size()-1); ++i) {
      lastAngle = nextAngle;
      nextAngle = ComputeAngleFromHorizon(x[i],x[i+1],
					  y[i],y[i+1]);
      double dAngle = nextAngle - lastAngle;
      if (fabs(dAngle)<mMinAngle)
	mOut << DoubleToString(x[i],precision) << "   " <<
	  DoubleToString(y[i],precision) << std::endl;
    }
    mOut << DoubleToString(x[x.Size()],precision) << "   " <<
      DoubleToString(y[y.Size()],precision) << std::endl;
  }
}
