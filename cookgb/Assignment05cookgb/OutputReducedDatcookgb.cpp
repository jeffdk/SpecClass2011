#include "OneDimDataWriter.hpp"
#include "NdData.hpp"
#include "StringUtils.hpp"
#include "OptionParser.hpp"
#include "FancyTypeName.hpp"
#include "ConvertNumberToString.hpp"
 
#include <fstream>
#include <sstream>
#include <cmath>
 
namespace OneDimDataWriters {

  //================================================================
  class OutputReducedDatcookgb: public OneDimDataWriter,
				Factory::Register<OutputReducedDatcookgb> {
  public:
    static std::string ClassID() { return "redatgbc"; }
    static std::string Help() {
      return ClassID()+"\n"
	"Output each time to a new file.                           \n"
	"Save x_i  y_i as two columns.                             \n"
	"Cull the data so that as few points are saved as possible \n"
	"OPTIONS                                                   \n"
	"   MinAngle=double;   # Minimum angle for output          \n";
    };
    OutputReducedDatcookgb(const std::string& opts, 
			   const std::string& BaseName):
      mBaseName(BaseName), mCount(0)
    {
      OptionParser p(opts, Help());
      mCosMinAngle = cos(p.Get<double>("MinAngle"));
    };
    void TruncateFile() const {};
  private:
    const std::string mBaseName;
    mutable int mCount;
    double mCosMinAngle;

    void AppendToFileImpl(const double time,
			  const MyVector<double>& x,
			  const MyVector<double>& y) const;
  };

  void OutputReducedDatcookgb::AppendToFileImpl(const double time,
						const MyVector<double>& x,
						const MyVector<double>& y) const
  {
    std::ostringstream NewFile(mBaseName+".");
    NewFile << mCount++;  // put count as filename suffix
    std::ofstream out(NewFile.str().c_str());
    out << DoubleToString(x[0], 16) << "  " 
	<< DoubleToString(y[0], 16) << "\n";
    if(x.Size() > 2) { // make sure there are at least 3 points
      double lastx = x[0];
      double lasty = y[0];
      double dx1 = x[1] - x[0];
      double dy1 = y[1] - y[0];
      for(int i=1; i<x.Size()-1; ++i) {
	const double dx2 = x[i+1] - x[i];
	const double dy2 = y[i+1] - y[i];
	const double dotprod = dx1*dx2 + dy1*dy2;
	const double magnitude = sqrt((dx1*dx1+dy1*dy1)*(dx2*dx2+dy2*dy2));
	const double costheta = dotprod/magnitude;
	if(costheta <= mCosMinAngle) {
	  out << DoubleToString(x[i], 16) << "  " 
	      << DoubleToString(y[i], 16) << "\n";
	  dx1 = dx2;
	  dy1 = dy2;
	  lastx = x[i];
	  lasty = y[i];
	} else {
	  dx1 = x[i+1] - lastx;
	  dy1 = y[i+1] - lasty;
	}
      }
    }
    out << DoubleToString(x[x.Size()-1], 16) << "  " 
	<< DoubleToString(y[x.Size()-1], 16) << "\n";
  }
  //================================================================
}
