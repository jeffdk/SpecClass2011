#include "OutputReducedDatBrett.hpp"
#include "StringUtils.hpp"
#include "MyVector.hpp"
#include "ConvertNumberToString.hpp"
#include <fstream>

namespace OneDimDataWriters {

  void OutputReducedDatBrett::AppendToFileImpl(const double time,
					       const MyVector<double>&,
					       const MyVector<double>& y) const {
    mOut << DoubleToString(time, 16);
    for(int i=0; i<y.Size(); ++i)
      mOut << "   " << DoubleToString(y[i], 16);
    mOut << std::endl;
  }
}
