#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/IO/CachedOfStream.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/StringUtils.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/MyContainers/MyVector.hpp"

#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

namespace OneDimDataWriters {

  class OutputReducedDatIlana: 
    public OneDimDataWriter, 
    Factory::Register<OutputReducedDatIlana> {
  public:
    static std::string ClassID() { return "reduceddat"; }
    static std::string Help() {
      return ClassID()+"\n"
	"Generates a separate file each time AppendToFileImpl is called,\n"
	"and outputs x_i and y_i as two columns in to each file. \n"
	"The i-th data-point is omitted if the angle calculated between \n"
	"the line-segment connecting and the i-th and (i+1)-st gridpoint \n"
	"is less than some user-specifiable minimum angle. \n"
	"OPTIONS: \n"
	" MinAngle = double\n";
    };

    OutputReducedDatIlana(const std::string& opts, 
			  const std::string& BaseName):
      mBaseName(BaseName), mOutFileNum(0)
    {
      OptionParser p(opts, Help());
      mMinAngle = p.Get<double>("MinAngle",true);
    };

    void TruncateFile() const{};
    
  private:
    const std::string mFileName;
    mutable int mOutFileNum;
    mutable double mMinAngle;
    const std::string mBaseName;

    void AppendToFileImpl(const double time, const MyVector<double>& x, 
				  const MyVector<double>& y) const;
  };

  //=========================================================================================
  
  void OutputReducedDatIlana::AppendToFileImpl(const double time,
					       const MyVector<double>& x,
					       const MyVector<double>& y) const {

    REQUIRE(x.Size()==y.Size(), "x and y are not the same size!");
    REQUIRE(x.Size()>0 && y.Size()>0, "x and y must have at least 1 data point!");

    // Calculate cosine of minimum angle
    double cosMinAngle = cos(mMinAngle*180./M_PI);

    // Every time AppendToFileImpl is called, the number of files is increased
    // File name reflects this.
    std::ostringstream File;
    File << mBaseName << "_Num" << ++mOutFileNum << ".dat";
    std::ofstream out(File.str().c_str());

    // First point
    out << DoubleToString(x[0],16) << " " << DoubleToString(y[0],16) << "\n";

    if(x.Size()>2) {
      for(int i=1; i<x.Size()-1; i++){

	double xdiff1 = x[i] - x[i-1];
	double ydiff1 = y[i] - y[i-1];
	double xdiff2 = x[i+1] - x[i];
	double ydiff2 = y[i+1] - y[i];

	// Figure out cosine of angle between line segments
	double cosAngle = (xdiff1*xdiff2 + ydiff1*ydiff2)/sqrt((xdiff1*xdiff1 + ydiff1*ydiff1)*(xdiff2*xdiff2 + ydiff2*ydiff2));

	if(cosAngle<=cosMinAngle)
	  out << DoubleToString(x[i],16) << " " << DoubleToString(y[i],16) << "\n";
      }
    }
    // Last point
    out << DoubleToString(x[x.Size()-1],16) << " " << DoubleToString(y[y.Size()-1],16) << "\n";
  }

}
