#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/IO/CachedOfStream.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/StringParsing/StringUtils.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"

#include <iostream>
#include <fstream>
#include <cmath>

using std::string;
using namespace std;

namespace OneDimDataWriters{

  class OutputReducedDathohejd8 : public OneDimDataWriter,
          Factory::Register<OutputReducedDathohejd8>{
  public:
    static string ClassID() { return "redhohejd8";}
    static string Help() {
      return ClassID()+"\n"
      "Output suitable for x-y plot.  This class is designed  \n"
      "to reduce the size of the output file, so if the angle \n"
      "ALPHA between the line segments (i-1,i) and (i,i+1) is \n"
      "abs(180-ALPHA) < MinAngle, the point 'i' is discarded. \n"
      "-- OPTIONS --                                          \n"
      "MinAngle: determines the minimum angle requried to     \n"
      "          keep the point 'i'.  In degrees.             \n";
    }
    OutputReducedDathohejd8(const string& opts, const string& BaseName):
       mBaseName(BaseName), mCounter(0)
    {
      OptionParser p(opts, Help());
      mMinCosTheta = cos(p.Get<double>("MinAngle")*3.1415926535/180.0);
    };
    void TruncateFile() const {};
  private:
    const string mBaseName;
    mutable double mMinCosTheta;
    mutable int mCounter;

    void AppendToFileImpl(const double time,
                          const MyVector<double>& x,
                          const MyVector<double>& y) const;
  };

  void OutputReducedDathohejd8::AppendToFileImpl(const double time,
                        const MyVector<double>& x,
                        const MyVector<double>& y) const {

    REQUIRE(x.Size()==y.Size(), "x and y are not the same size");

    //create new file each time this routine is called
    std::ostringstream outputFile;
    outputFile << mBaseName << mCounter++ << ".redhohejd8";
    std::ofstream mOut(outputFile.str().c_str());

    //always prints the first data point
    mOut << DoubleToString(x[0], 16) << " " << DoubleToString(y[0], 16) << "\n";

    if(x.Size() > 2){ //guarantees at least three data points exist
      for(int i=1; i<x.Size()-1; i++){
        //length of segment i-1 -> i
        double dx1 = x[i]-x[i-1];
        double dy1 = y[i]-y[i-1];

        //length of segment i -> i+1
        double dx2 = x[i+1]-x[i];
        double dy2 = y[i+1]-y[i];

        //dot product of vectors
        double dotproduct = dx1*dx2 + dy1*dy2;
        double magnitude  = sqrt((dx1*dx1 + dy1*dy1) * (dx2*dx2 + dy2*dy2));
        double cosTheta = dotproduct/magnitude;

        if(cosTheta <= mMinCosTheta){
          mOut << DoubleToString(x[i], 16) << " " << DoubleToString(y[i], 16) << "\n";
        }
      }
    }

    //always prints the last data point
    mOut << DoubleToString(x[x.Size()-1], 16) << " " << DoubleToString(y[y.Size()-1], 16) << "\n";
    mOut.close();
  }
}
