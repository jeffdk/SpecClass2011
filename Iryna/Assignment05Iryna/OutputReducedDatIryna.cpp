#include "OutputReducedDataIryna.hpp"
#include "OptionParser.hpp"

#include <cstdlib>
#include <cmath>

namespace OneDimDataWriters {

  class OutputReducedDatIryna: public OneDimDataWriter,
     Factory::Register<OutputReducedDatIryna>
  {
     public: 
	static string ClassID() {return "red_dat_i";}
	static string Help() {
           return ClassID() + "\n"
              "Output: Two columns containing x_i and y_i with each i-th    \n"
	      "data point omitted.                                          \n"
	      "OPTIONS: MinAngle -  if abs(180 - angle) < MinAngle, discard \n"
	      "the i-th data point."
        };
        OutputReducedDatIryna(const string& opts, const string& BaseName):
        mFileName(BaseName+".dat"), mOut(mFileName) {
	   REQUIRE(opts.empty(), Help()One);
	};
	void TruncateFile() const {
	   ofstream out(mFileName.c_str(), std::ios::trunc);
	};

     private:
        const string mFileName;
        mutable CachedOfStream mOut;

	void AppendToFileImpl(const double time, 
			      const MyVector<double>&,
			      const MyVector<double>& y) const;
     };

  }
}
