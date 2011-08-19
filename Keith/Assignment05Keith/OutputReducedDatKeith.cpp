
#include "OutputReducedDatKeith.hpp"

#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"

#include <iostream>
#include <fstream>

#include <cmath>

namespace OneDimDataWriters {

  OutputReducedDatKeith::OutputReducedDatKeith(const std::string& opts, 
                                               const std::string& BaseName):
    mBaseName(BaseName), mOutputFileCount(0)
  {
    OptionParser p(opts, Help());
    mMinAngle = p.Get<double>("MinAngle");
    mDebug = p.Get<bool>("DebuggingOutput",false);
  }

  // ================
  void OutputReducedDatKeith::TruncateFile() const {
    for(int i=1; i<=mOutputFileCount; ++i)
      std::ofstream out(generateFilename(mBaseName,mOutputFileCount).c_str(), 
                        std::ios::trunc);
    mOutputFileCount = 0;
  }

  // ================
  std::string OutputReducedDatKeith
  ::generateFilename(const std::string& basename, const int& count) const {
    return basename+"_Count"+IntToString(count)+".dat"; 
  }

  // ================
  void OutputReducedDatKeith::AppendToFileImpl(const double /*time*/, 
                                               const MyVector<double>& x, 
                                               const MyVector<double>& y) const
  {
    // I've been called, so I'll increment my num calls counter.
    ++mOutputFileCount;
    
    // create the output file
    std::ofstream out(generateFilename(mBaseName,mOutputFileCount).c_str());
    
    // x.Size() == y.Size() has already been checked in base class
    // AppendToFile().
    const int numPoints = y.Size();
    
    // This is not a REQUIRE because it's perfectly reasonable to want to
    // write no data to a file.  If numPoints==0, the file will be created
    // and left empty.
    if(numPoints>0) {

      // Write first point.
      if(!mDebug) {
        out << DoubleToString(x[0],16) << "   " << DoubleToString(y[0],16) 
            << std::endl;
      }
      
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
    } // end if(numPoints>0)
    
    // close the file
    out.close();
  }
  
} // end namespace OneDimDataWriters
