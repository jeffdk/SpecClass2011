#include "Dust/Domain/Observer.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include <string>

namespace Observers {
  class PointwiseAvgIlana : public Observer {
  public:
    static std::string ClassID() {return "PointwiseAvgIlana";}
    static std::string Help() {
      return
	"PointwiseAvgIlana  \n"
        "Returns the average value of all components  \n"
        "of a Tensor<DataMesh> over all points in a Domain  \n"
        "OPTIONS:  \n"
        "  Input = string;  #which Tensor to act on  \n"
        "  Filename = string;  #Output filename  \n";
    }
  public:
    PointwiseAvgIlana(const std::string &Opts,
		      const DataBox&,const std::string& Dir);
    void Observe(const DataBox& box,
		 const double TimeForDumpFiles,
		 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName, mInput;
  };
}
