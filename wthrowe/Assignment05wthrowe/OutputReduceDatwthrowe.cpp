#include "OutputReduceDatwthrowe.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/MyContainers/MyVector.hpp"

#include <cmath>
#include <sstream>

namespace OneDimDataWriters {

  namespace {
    inline std::string GetFilename(const std::string& BaseName,
				   const int num) {
      std::ostringstream name;
      name << BaseName << num << ".dat";
      return name.str();
    }
  }

  OutputReduceDatwthrowe::
  OutputReduceDatwthrowe(const std::string& opts,
			 const std::string& BaseName) :
    mBaseName(BaseName),
    mFileNumber(0) {
    OptionParser p(opts);
    mMinAngle = p.Get<double>("MinAngle");
    mAspect = p.Get<double>("AspectRatio", 1);
  }

  void OutputReduceDatwthrowe::
  TruncateFile() const {
    for(int i=0;i<mFileNumber;i++) {
      unlink(GetFilename(mBaseName, i).c_str());
    }
    mFileNumber = 0;
  }

  void OutputReduceDatwthrowe::
  AppendToFileImpl(const double /*time*/,
		   const MyVector<double>& x,
		   const MyVector<double>& y) const {
    ASSERT(x.Size()==y.Size(),
	   "This can't fail because the base class checks");
    std::ofstream out(GetFilename(mBaseName, mFileNumber++).c_str(),
		      std::ios::trunc);
    if(x.Size() < 1)
      return;
    double last_angle = 1e300; // large number
    for(int i=0;i<x.Size()-1;i++) {
      double angle = std::atan2(y[i+1]-y[i], mAspect*(x[i+1]-x[i]));
      if(std::abs(angle-last_angle) >= mMinAngle)
	out << x[i] << "   " << y[i] << "\n";
      last_angle = angle;
    }
    out << x[x.Size()-1] << "   " << y[x.Size()-1] << "\n";
  }
}
