

#include "OutputReducedDat_fhebert.hpp"
#include "Utils/IO/CachedOfStream.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/StringParsing/StringUtils.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/ErrorHandling/Require.hpp"

#include <fstream>
#include <cmath>
using std::string;

namespace OneDimDataWriters {


  OutputReducedDat_fhebert::
  OutputReducedDat_fhebert(const string& Opts, const string& BaseName):
    mBaseName(BaseName),
    mCount(0)
  {
    OptionParser p(Opts, Help());
    mMinAngle = p.Get<double>("MinAngle");
  };


  void OutputReducedDat_fhebert::
  AppendToFileImpl(const double time,
      const MyVector<double>& x,
      const MyVector<double>& y) const
  {
    // base class checks that x,y are arrays of equal length
    // there is therefore no need to keep two variables around for this
    const int xlen = x.Size();
    // if list is zero-length, exit:
    REQUIRE(xlen>0, "can't write data of 0 length to file");

    const string file(mBaseName + IntToString(mCount++) + "." + ClassID());
    std::ofstream out(file.c_str());

    // always write first point
    out << DoubleToString(x[0], 16) << "   "
        << DoubleToString(y[0], 16) << "\n";

    // if there are intermediate points, start checking angles:
    if (xlen > 2)
    {
      double lastX = x[0];
      double lastY = y[0];
      double thisX = x[1];
      double thisY = y[1];
      double lastDx = thisX - lastX;
      double lastDy = thisY - lastY;
      double lastAngle = atan2(lastDy, lastDx);
      
      // for sanity checking each step:
      // when we remove a point, we create a new line segment.
      // we want to check that this new segment is at a sufficiently
      // small angle relative to the previous "anchor" segment
      double anchorAngle = lastAngle;

      for (int i=1; i<xlen-1; ++i)
      {
        const double nextX = x[i+1];
        const double nextY = y[i+1];
        const double nextDx = nextX - thisX;
        const double nextDy = nextY - thisY;
        const double nextAngle = atan2(nextDy, nextDx);
        
        // for sanity checks:
        // this is the angle we'll get if we drop our i'th point
        const double newAngle = atan2(lastDy+nextDy, lastDx+nextDx);

        // if
        // - angles are different enough
        // - angles close, but removing a point would make a kink "behind" us
        // then write this point to file
        if (fabs(nextAngle - lastAngle) > mMinAngle ||
            fabs(newAngle - anchorAngle) > mMinAngle)
        {
          out << DoubleToString(thisX, 16) << "   "
              << DoubleToString(thisY, 16) << "\n";
          // reset variables for next time
          lastX = thisX;
          lastY = thisY;
          lastDx = nextDx;
          lastDy = nextDy;
          anchorAngle = lastAngle;
          lastAngle = nextAngle;
        } else {
          // angles were too close.. skip this point
          lastDx += nextDx;
          lastDy += nextDy;
          lastAngle = newAngle;
        }
        thisX = nextX;
        thisY = nextY;
      }
    }

    // always write last point
    out << DoubleToString(x[xlen-1], 16) << "   "
        << DoubleToString(y[xlen-1], 16) << "\n\n";
  }
}
