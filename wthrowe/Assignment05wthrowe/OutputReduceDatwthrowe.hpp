#ifndef OutputReduceDatwthrowe_hpp
#define OutputReduceDatwthrowe_hpp

#include "OneDimDataWriter.hpp"

namespace OneDimDataWriters {

  /// Output points removing interior values from approximately colinear
  /// segments.
  class OutputReduceDatwthrowe: public OneDimDataWriter,
				Factory::Register<OutputReduceDatwthrowe> {
  public:
    static std::string ClassID() { return "reduce_wthrowe"; }
    static std::string Help() {
      return ClassID() + "\n"
	"Outputs lines of 'x_i  y_i' with interior values from approximately\n"
	"colinear segments removed.\n"
	"Options:\n"
	"  MinAngle    = double\n"
	"  AspectRatio = double -- ratio of unit lengths on y- and x-axes";
    }

    OutputReduceDatwthrowe(const std::string& opts,
			   const std::string& BaseName);
    void TruncateFile() const;

  private:
    const std::string mBaseName;
    mutable int mFileNumber;
    double mMinAngle, mAspect;

    void AppendToFileImpl(const double time,
			  const MyVector<double>& x,
			  const MyVector<double>& y) const;
  };
}

#endif
