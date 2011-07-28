#include "OptionParser.hpp"
#include "OneDimDataWriter.hpp"
#include "MyVector.hpp"
#include "CachedOfStream.hpp"

#include <cstdlib>
#include<fstream>
#include <cmath>

namespace OneDimDataWriters {

  class OutputReducedDatIryna: public OneDimDataWriter,
     Factory::Register<OutputReducedDatIryna>
  {
     public: 
	static string ClassID() {return "rdatIryna";}
	static string Help() {
           return ClassID() + "\n"
              "Output: Two columns containing x_i and y_i with each i-th    \n"
	      "data point omitted.                                          \n"
	      "OPTIONS: MinAngle = double;  if abs(180 - angle) < MinAngle, 
	      "discard the i-th data point. \n" ;
        };
        OutputReducedDatIryna(const string& opts, const string& BaseName):
         mFileName(BaseName+".dat"), mOut(mFileName) { // check .dat
	   OptionParser p(opts, Help());
	   MinAngleRad = p.Get<double>("MinAngle") * (M_PI / 180.0);
	};
	void TruncateFile() const {
	   std::ofstream out(mFileName.c_str(), std::ios::trunc);
	};

     private:
        const std::string mFileName;
        double MinAngleRad;

	void AppendToFileImpl(const double time, 
			      const MyVector<double>&,
			      const MyVector<double>& y) const;
     };

  }
}
