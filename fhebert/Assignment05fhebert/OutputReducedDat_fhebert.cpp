
#include "Utils/IO/CachedOfStream.hpp"
#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/StringParsing/StringUtils.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

#include <fstream>
#include <cmath>
using std::string;

namespace OneDimDataWriters {


  class OutputReducedDat_fhebert: public OneDimDataWriter,
    Factory::Register<OutputReducedDat_fhebert>
  {
    public:
      static string ClassID() {return "rdatfh";}
      static string Help() {
        return ClassID() + "\n"
        "file output: saves each x_i, y_i in a separate column.               \n"
        "reduces data so that nearly-colinear points are eliminated, saving   \n"
        "space in both data files and plots.                                  \n"
        " OPTIONS:                                                            \n"
        " MinAngle = double; # min allowed angle before elimination (radians) \n";
      };
    
      OutputReducedDat_fhebert(const string& Opts, const string& BaseName):
        mBaseName(BaseName),
        mCount(0)
      {
        OptionParser p(Opts, Help());
        mMinAngle = p.Get<double>("MinAngle");
      };

      void TruncateFile() const {};

    private:
      const string mBaseName;
      mutable int mCount;
      double mMinAngle;

      void AppendToFileImpl(const double time,
                            const MyVector<double>& x,
                            const MyVector<double>& y) const;
  };

  void OutputReducedDat_fhebert::AppendToFileImpl(const double time,
      const MyVector<double>& x,
      const MyVector<double>& y) const
  {
    const int xlen = x.Size();
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
