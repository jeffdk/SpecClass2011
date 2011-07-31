
#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"

#include <iostream>
#include <fstream>

#include <cmath>

namespace OneDimDataWriters {

  class OutputReducedDatKeith: 
    public OneDimDataWriter,
    Factory::Register<OutputReducedDatKeith> {
  public:
    static std::string ClassID() { return "reducedDat"; }
    static std::string Help() {
      return ClassID()+"\n"
        "Outputs x and y columns in a seperate file for each call to     \n"
        "  AppendToFileImpl().  Culls the input by computing the angle   \n"
        "  between the last and next line segment.  If this angle is     \n"
        "  below the threshold set by the MinAngle Option, the x,y pair  \n"
        "  will be discarded.                                            \n"
        "OPTIONS:                                                        \n"
        "  MinAngle = double;                                            \n"
        ;
    };
    OutputReducedDatKeith(const std::string& opts, 
                          const std::string& BaseName):
      mBaseName(BaseName), mOutputFileCount(0)
    {
      OptionParser p(opts, Help());
      mMinAngle = p.Get<double>("MinAngle");
      mDebug = p.Get<bool>("DebuggingOutput",false);
    };
    void TruncateFile() const {
      for(int i=1; i<=mOutputFileCount; ++i)
        std::ofstream out(genFilename(mBaseName,mOutputFileCount).c_str(), 
                          std::ios::trunc);
      mOutputFileCount = 0;
    };
  private:
    void AppendToFileImpl(const double time,
                          const MyVector<double>& x,
                          const MyVector<double>& y) const;
    std::string genFilename(const std::string& basename,
                            const int& count) const 
    { return basename+"_Count"+IntToString(count)+".dat"; };
  private:
    const std::string mBaseName;
    // counts the number of times that AppendToFileImpl is called.
    mutable int mOutputFileCount;
    double mMinAngle;
    bool mDebug;
  };
    
  // ================
  void OutputReducedDatKeith::AppendToFileImpl
  (const double /*time*/, 
   const MyVector<double>& x, 
   const MyVector<double>& y) const {

    // I've been called, so I'll increment my num calls counter.
    ++mOutputFileCount;

    // create the output file
    std::ofstream out(genFilename(mBaseName,mOutputFileCount).c_str());

    // Write first point.
    if(!mDebug) {
      out << DoubleToString(x[0],16) << "   " << DoubleToString(y[0],16) 
          << std::endl;
    }

    // x.Size() == y.Size() has already been checked in base class
    // AppendToFile().
    const int numPoints = y.Size();

    for(int i=1; i<numPoints-1; ++i) {
    
      // I could get deltaXb and deltaYb from the previous iteration,
      // but that would save just a couple floating point ops, so why
      // bother?
      const double deltaXa = x[i] - x[i-1];
      const double deltaYa = y[i] - y[i-1];
      const double deltaXb = x[i+1] - x[i];
      const double deltaYb = y[i+1] - y[i];

      const double aDotb = deltaXa*deltaXb + deltaYa*deltaYb;
      const double aCrossb = deltaXa*deltaYb - deltaXb*deltaYa;

      // const double angle = acos(aDotb/(sqrt(a2*b2)))*(360./(2.*M_PI));
      // etch.  acos sucks.  I wanna use atan2.

      // aCrossb is proportional to sin(angle)
      // aDotb is proportional to cos(angle)
      //   thus  aCrossb/aDotb = tan(angle)
      const double angle = atan2(-aCrossb, aDotb)*(360./(2.*M_PI));

      // actually write output
      if(mDebug) {
        out << DoubleToString(x[i],16) << "   " << DoubleToString(angle,16)
            << std::endl;
      } else {
        if(fabs(angle) > mMinAngle) 
          out << DoubleToString(x[i],16) << "   " << DoubleToString(y[i],16) 
              << std::endl;
      }
    } // end for loop
    
    // Write last point.
    if(!mDebug) {
      if(numPoints >= 2) {
        out << DoubleToString(x[numPoints-1],16) << "   " 
            << DoubleToString(y[numPoints-1],16) 
            << std::endl;
      }
    }

    // close the file
    out.close();
  }

} // end namespace OneDimDataWriters
