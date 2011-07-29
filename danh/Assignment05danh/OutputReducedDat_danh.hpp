///
/// \file
/// Defines class OneDimDataWriters::OutputReducedDat

#ifndef OUTPUTREDUCEDDAT_DANH_HPP
#define OUTPUTREDUCEDDAT_DANH_HPP

#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/IO/CachedOfStream.hpp"
#include <string>

namespace OneDimDataWriters {

/// This class implements a OneDimDataWriter that compresses the data by
/// omitting points that line along a straight line to within some tolerance.
class OutputReducedDat :
  public OneDimDataWriter, Factory::Register<OutputReducedDat> {
public:
  static std::string ClassID() {return "ReducedDat";}
  static std::string Help() {
    return
      "This OneDimDataWriter outputs a file each time it is called. Into    \n"
      "this file is output 'x_i y_i' as two columns such that the i-th data \n"
      "point is omitted if the following condition holds:                   \n"
      "Consider the line-segment connecting the (i-1)-th and i-th gridpoint \n"
      "and the line-segment connecting the i-th and (i+1)-st gridpoint,     \n"
      "and compute the angle Alpha connecting these two segments. Discard   \n"
      "the i-th data-point in the output if abs(pi-Alpha) < MinAngle.       \n"
      "Always output the first and last data points.                        \n"
      "                                                                     \n"
      "OPTIONS:                                                             \n"
      "  MinAngle = double;    # Discard points if angle<MinAngle (radians) \n"
    ;
  }
  OutputReducedDat(const std::string opts, const std::string basename);
  void TruncateFile() const;
private:
  void AppendToFileImpl(const double time, const MyVector<double>&,
                        const MyVector<double>& y) const;
private:
  const std::string mFileName;
  mutable CachedOfStream mOut;
  double mMinAngle;
};


}   // end namespace

#endif  // OUTPUTREDUCEDDAT_DANH_HPP
