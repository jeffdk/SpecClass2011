#include "OutputReducedDat_Bohn.hpp"
#include "OneDimDataWriter.hpp"
#include "NdData.hpp"
#include "StringUtils.hpp"
#include "OptionParser.hpp"
#include "ConvertNumberToString.hpp"

#include <fstream>
#include <cmath>

namespace OneDimDataWriters {
  void OutputReducedDat_Bohn::AppendToFileImpl(const double t,
                                               const MyVector<double>& x,
                                               const MyVector<double>& y) const
  {
    const int inputSize = x.Size();

    //Verify data
    REQUIRE(inputSize == y.Size(),
      "Input data must have the same lengths");
    REQUIRE(inputSize >= 1, "Input data must have at least one point");

    std::ostringstream outputFile;
    outputFile << mFileName;
    std::ofstream out(outputFile.str().c_str());

    //Write the first point, only if there are more than one point.
    // If there is only one, this will drop through to write the last point
    if (inputSize > 1)
    {
      out << DoubleToString(x[0], 16) << "   "
         << DoubleToString(y[0], 16) << "\n";


      if (inputSize >= 3)
      {
       double prev_dx = x[1] - x[0];
       double prev_dy = y[1] - y[0];
       double prevDMagSquared = prev_dx * prev_dx + prev_dy * prev_dy;

        // Ignore end points, since they are already explicitly coded
       for (int i = 1; i < inputSize - 1; i++)
       {
         double dx       = x[i + 1] - x[i];
         double dy       = y[i + 1] - y[i];
         double dMagSquared = dx * dx + dy * dy;
         double cosTheta = fabs(prev_dx * dx + prev_dy * dy) /
                        sqrt(prevDMagSquared * dMagSquared);
         if (cosTheta <= mMinCosAngle)
         {
           out << DoubleToString(x[i], 16) << "   "
               << DoubleToString(y[i], 16) << "\n";
           prev_dx = dx;
           prev_dy = dy;
           prevDMagSquared = dMagSquared;
         }
         //Here is where I would add these skipped points to a list.
         // This list would be looped over with the same comparison, only
         // the prev_dx would be from a point in the list to x[i].
         // By looping over all of these, we will ensure that we won't have
         // any drifting over the MinCosAngle given.
         //However, this isn't what was asked for in the problem
       }
     }
    }

    out << DoubleToString(x[inputSize - 1], 16) << "   "
        << DoubleToString(y[inputSize - 1], 16) << "\n";

    out.close();
  }
}

