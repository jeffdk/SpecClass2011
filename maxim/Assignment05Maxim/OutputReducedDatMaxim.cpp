#include <cmath>
#include "OneDimDataWriter.hpp"

#include "OptionParser.hpp"
#include "MyVector.hpp"
#include "ConvertNumberToString.hpp"
#include "Require.hpp"
#include "CachedOfStream.hpp"
 
using std::string;
using std::ofstream;

namespace OneDimDataWriters { 
 
  /// Output for xmgrace for y-vs-t plots with one curve per x_i.
  class OutputReducedDatMaxim: public OneDimDataWriter,   
    Factory::Register<OutputReducedDatMaxim> {
  public:
    static string ClassID() { return "reduced"; }  
    static string Help() {
      return ClassID()+"\n"
	"Output for xmgrace, suitable for a y-t plot.  Each spatial point  \n"
	"y_i will produce one curve on the y-t plot.  Use                  \n"
	"  xmgrace -nxy filename                                           \n"
	"to display.                                                       \n"
	"x-values x_i and 'description' ignored.                           \n"
	"OPTIONS		                                                   \n"
    "  MinAngle=double;											       \n";
    };

    OutputReducedDatMaxim(const string& opts, const string& BaseName):
    mFileName(BaseName+".reduced"), mOut(mFileName) {
      OptionParser p(opts, Help());
      mMinAngle = p.Get<double>("MinAngle", true); // extracting option MinAngle
    };

    void TruncateFile() const {
      ofstream out(mFileName.c_str(), std::ios::trunc);
    };
  private:
    const string mFileName;
	double mMinAngle; // in degrees
    mutable CachedOfStream mOut;
 
    void AppendToFileImpl(const double time,
			  const MyVector<double>& x,
			  const MyVector<double>& y) const;
	
	// Vectors are assumed to be 2D, but will also work for 3D 
	double AngleBetweenVectors(const MyVector<double>& v1, const MyVector<double>& v2) const;
	
    // Works for any number of dimensions	
  	double ScalarProduct(const MyVector<double>& v1, const MyVector<double>& v2) const;

  };

  void OutputReducedDatMaxim::AppendToFileImpl(const double time,
                                   			   const MyVector<double>& x, 
                                   			   const MyVector<double>& y) const {
	 //mOut << DoubleToString(time, 16) << std::endl;
    
	 // always include the 1st point
	 mOut << DoubleToString(x[0], 16) << "   " << DoubleToString(y[0], 16) << std::endl;
     
	 int Omitted = 0; // for counting omitted points
	 for(int i=1; i<y.Size()-1; ++i) {
		
		// forming components of the vectors v1(dx1, dy1) connecting (i-1)-th and i-th points
		// v2(dx2, dy2) connecting i-th and (i+1)-th points
		const double dx1 = x[i]-x[i-1], dy1 = y[i]-y[i-1], dx2 = x[i+1]-x[i], dy2 = y[i+1]-y[i]; 		
		MyVector<double> v1(MV::fill, dx1, dy1), v2(MV::fill, dx2, dy2);
		
		// angle between vectors = 180-alpha, where alpha angle connecting two adjacent segments
		double angle = AngleBetweenVectors(v2, v1);
		if( fabs(angle) > mMinAngle ) {
			mOut << DoubleToString(x[i], 16) << "   " << DoubleToString(y[i], 16) << std::endl;
		} else { Omitted++;}
     }

	 // always include the last point
	 mOut << DoubleToString(x[y.Size()-1], 16) << "   " << DoubleToString(y[y.Size()-1], 16); 
	 mOut << std::endl;

	 // Some stats
	 mOut << "# "<< Omitted << " points omitted for angle=" << mMinAngle << std::endl; 
  }

  // Calculates the scalar dot product of two vectors v1 and v2
  double OutputReducedDatMaxim::ScalarProduct(const MyVector<double>& v1, 
							 				  const MyVector<double>& v2) const {
	 double product = 0.0;
	 for(int i = 0; i < v1.Size(); ++i)
		product += v1[i]*v2[i];
	 return product;
  }

  // Calculates the angle between 2D or 3D Vectors
  double OutputReducedDatMaxim::AngleBetweenVectors(const MyVector<double>& v1, 
							 						const MyVector<double>& v2) const {
	 double angle;
	 angle = acos( ScalarProduct(v1,v2)/sqrt(ScalarProduct(v1,v1)*ScalarProduct(v2,v2)) );
	 angle *=180.0/M_PI; // converting the result to degrees
	 return angle;
  }
}
