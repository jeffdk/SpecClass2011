///
/// \file
/// Implements class OneDimDataWriters::OutputReducedDat

#include "OutputReducedDat_danh.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include <cmath>    // for atan2

namespace OneDimDataWriters {

//----------------------------------------------------------------------------
// Constructor
OutputReducedDat::
OutputReducedDat(const std::string opts, const std::string basename):
mFileName(basename+".dat"), mOut(mFileName), mMinAngle(0.0) {
  // Get the input file option, MinAngle
  OptionParser parser(opts, Help());
  mMinAngle = parser.Get<double>("MinAngle");
};

//----------------------------------------------------------------------------
void OutputReducedDat::TruncateFile() const {
  std::ofstream out(mFileName.c_str(), std::ios::trunc);
}; 

//----------------------------------------------------------------------------
// Implementation function
void OutputReducedDat::
AppendToFileImpl(const double /*time*/, const MyVector<double>& x,
                 const MyVector<double>& y) const
{
  // Ensure that x and y are the same size
  REQUIRE(y.Size()==x.Size(), "size mismatch");
  const int N = y.Size();

  // Write a header to the output file
  mOut << "# [1] = x" << std::endl;
  mOut << "# [2] = y" << std::endl;

  // Always write the first data point
  mOut << DoubleToString(x[0],9) << " " 
       << DoubleToString(y[0],9) << std::endl;

  // Write the second to N-1th data points only if they meet the criteria
  // specified in the help text
  for(int i=1; i<N-1; ++i) {
    const double Angle1 = atan2(y[i-1]-y[i], x[i-1]-x[i]);
    const double Angle2 = atan2(y[i]-y[i+1], x[i]-x[i+1]);
    if(Angle1-Angle2 > mMinAngle) {
      mOut << DoubleToString(x[i],9) << " "
           << DoubleToString(y[i],9) << std::endl;
    }
  }

  // Always write the last data point
  mOut << DoubleToString(x[N-1],9) << " "
       << DoubleToString(y[N-1],9) << std::endl;
}

}

