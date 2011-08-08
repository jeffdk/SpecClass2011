#include "Problem3ComputeItemIlana.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/MyContainers/MyVector.hpp"

using std::string;
using namespace std;

namespace ComputeItems {
  
  Problem3ComputeItemIlana::Problem3ComputeItemIlana(const string& opts): 
    mResult(TensorStructure::Empty) {
    OptionParser p(opts,Help());
    mOutput = p.Get<string>("Output");
  }

  void Problem3ComputeItemIlana::RecomputeData(const DataBoxAccess& box) const {

      // Get coordinates from DataBox
      const MyVector<DataMesh>& coords = box.Get<MyVector<DataMesh> >("GlobalCoords");
      const Mesh& mesh = coords[0];

      // Calculate R^2, which is the square of the magnitude of the coordinates GlobalCoords
      DataMesh R2(mesh,0.0);
      for(int i=0;i<coords.Size();++i)
	R2 += coords[i]*coords[i];
      DataMesh R = sqrt(R2);
     
      // Make sure that R is not zero
      for(int i=0;i<R2.Size();++i)
	REQUIRE(R[i]!=0,"R is zero! Can't divide by zero!");

      // Calculate rhat^i/r^3
      for(int i=0;i<coords.Size();++i)
	mResult(i) = coords[i]/(R*R*R);
    }
}
