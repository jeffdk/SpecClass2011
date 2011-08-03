#include "OneDimDataWriter.hpp"
#include "CachedOfStream.hpp"
#include "OptionParser.hpp"
#include "StringUtils.hpp"
#include "Require.hpp"
#include "ConvertNumberToString.hpp"
#include "MyVector.hpp"

#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

namespace OneDimDataWriters {

  // Same as OutputDat, but it can reduce data as well

  class OutputReducedDatIlana: public OneDimDataWriter, Factory::Register<OutputReducdedDatIlana> {
  public:
    static string ClassID() {return "reduceddatIlana";}
    static string Help() {
      return ClassID()+"\n"
	"Generates a separate file each time AppendToFileImp1 is called,\n"
	"and outputs x_i and y_i as too columns in to each file. \n"
	"The i-th data-point is omitted if the angle calculated between \n"
	"the line-segment connecting and the i-th and (i+1)-st gridpoint \n"
	"is less than some user-specifiable minimum angle. \n"
	"OPTIONS \n"
	" MinAngle = double\n";
    };

    OutputReducedDatIlana(const string& opts, const string& BaseName) {
      mFileName(BaseName+"."+ClassID()) {
	REQUIRE(opts.empty(), Help());
	OptionParser p(opts, Help());
	mMinangle = p.Get<double>("MinAngle");
      };
      void TruncateFile() const{
	ofstream out(mFileName.c_str(), std::ios::trunc);
      };
    };
  private:
    const string mFileName;
    mutable CashedOfStream mOut;
    double mMinAngle;
    double mBaseName;
    void AppendToFileImpl(const double time, const MyVector<double>& x, 
				  const MyVector<double>& y) const;
    };
    void OutputReducedDatIlana::AppendToFileImpl(const double time,
						 const MyVector<double>& x,
						 const MyVector<double>& y) const {

      REQUIRE(x.Size()==y.Size(), "x and y are not the same size!");
      REQUIRE(x.Size()>0 && y.Size()>0, "x and y must have at least 1 data point!");

      double mTanMinAngle = tan(mMinAngle*M_PI/180.);

      // First point
      mOut << DoubleToString(x[0],16) << " " << DoubleToString(y[0],16) << "\n";

      if(x.Size()>2) {
	for(int i=0; i<x.Size()-1; i++){
	  double xdiff = x[i+1] - x[i];
	  double ydiff = y[i+1] - y[i];
	  double TanAngle = ydiff/xdiff;
	  if(TanAngle>mTanMinAngle)
	    mOut << DoubleToString(x[i],16) << " " << DoubleToString(y[i],16) << "\n";
	};
      };

      // Last point
      mOut << DoubleToString(x[i],16) << " " << DoubleToString(y[i],16) << "\n";
      mOut << std::endl;
    };

};
