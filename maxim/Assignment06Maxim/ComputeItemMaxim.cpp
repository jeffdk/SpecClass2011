
#include "ComputeItemMaxim.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"

using std::string;
using namespace std;

namespace ComputeItems {
  
  ComputeItemMaxim::ComputeItemMaxim(const string& opts): mResult(TensorStructure::Empty) {    
	OptionParser p(opts, Help());
    mOutput=p.Get<string>("Output");
  }
 
  void ComputeItemMaxim::RecomputeData(const DataBoxAccess& box) const {
	const MyVector<DataMesh>& coords=box.Get<MyVector<DataMesh> >("GlobalCoords");

	// preparing mResult to hold hat{r}^i/r^2	
	mResult.assign(coords.Size(), "a", static_cast<DataMesh>(coords[0]));

	DataMesh R(coords[0], 0.0), sum(coords[0], 0.0); // Radius

	{
		int i;
		//Computing radious	
		for(i = 0; i < coords.Size(); i++) 
			sum +=coords[i]*coords[i];

		R = sqrt(sum);

		for(i = 0; i < coords.Size(); i++)
			mResult(i) = coords[i]/R/R/R;
	}
  } 
}
