#include "OptionParser.hpp"
#include "OneDimDataWriter.hpp"
#include "CachedOfStream.hpp"
#include "MyVector.hpp"
#include <fstream>
#include <cmath>
namespace OneDimDataWriters {
  class OutputReducedDat_Bohn: public OneDimDataWriter,
    Factory::Register<OutputReducedDat_Bohn> {
  public:
    static std::string ClassID() { return "rdatBohn"; }
    static std::string Help() {
      return ClassID() + "\n"
    "Output scatter data which emits all superfluous points.  These points   \n"
    "are defined by all points where, if emitted, a line graph would remain  \n"
    "unchanged.  In practice, this routine will determine if points lie along\n"
    " a minimum angle, which is passed as an argument.                       \n"
    "OPTIONS                                                                 \n"
    "   MinAngle=double;  # Threshold angle for point to be printed          \n"
    ;
    };
    OutputReducedDat_Bohn(const std::string& opts, const std::string& BaseName):
      mFileName(BaseName+"."+ClassID())
    {
      OptionParser p(opts, Help());
      mMinCosAngle = cos(p.Get<double>("MinAngle") * (M_PI / 180.));
    };
    void TruncateFile() const {
      std::ofstream out(mFileName.c_str(), std::ios::trunc);
    };
  private:
    const std::string mFileName;
    double mMinCosAngle;

    void AppendToFileImpl(const double t,
                          const MyVector<double>& x,
                          const MyVector<double>& y) const;
  };
}
