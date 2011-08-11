#include "ObservePointwiseAvgCurran.hpp"

#include <fstream>

#include "Dust/Domain/Domain.hpp"
#include "Utils/DataBox/DataBox.hpp"
#include "Utils/DataBox/DataBoxAccess.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/DataMesh/DataMeshNorms.hpp"
#include "Utils/IO/PrependDirectoryName.hpp"
#include "Utils/MiscUtils/MpiUtils.hpp"
#include "Utils/MiscUtils/SimpleProfiler.hpp"
#include "Utils/MpiWrappers/MpiCommunicator.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/Tensor/Tensor.hpp"
 
namespace Observers {
 
PointwiseAvgCurran::PointwiseAvgCurran(const std::string &opts,
                                       const DataBox& /*box*/,
                                       const std::string& dir) {
    OptionParser parser(opts, Help());
    input_name_ = parser.Get<std::string>("Input");
    file_path_  = PrependDirectory(parser.Get<std::string>("Filename"), dir);
}
 
void PointwiseAvgCurran::Observe(const DataBox& box, const double /*time*/,
                                 const std::string& first_col) const {
    SimpleProfiler prof("PointwiseAvgCurran");
    typedef Tensor<DataMesh> TDm;

    DataBoxAccess access(box, "Observers::PointwiseAvgCurran::Observe");
    const Domain& domain = access.Get<Domain>("Domain");
 
    // Process this node's Subdomains
    double sum = 0.0;
    int count = 0;
    for(int sd = 0; sd < domain.Size(); ++sd) {
        const TDm& Input = access[sd].Get<TDm>(input_name_);
        for(TDm::const_iterator i = Input.begin(); i != Input.end(); ++i) {
            const int size = (*i).Size();
            sum += PointwiseAverage(*i) * size;
            count += size;
        }
    }

    // Accumulate Domain totals
    sum = MPreduceAdd(sum, domain.Communicator());
    count = MPreduceAdd(count, domain.Communicator());
 
    // Write output to file
    if (domain.Communicator().Rank() == 0) {
        const double avg = sum / count;
        std::ofstream out(file_path_.c_str(), std::ios::app);
        out << first_col << " " << avg << std::endl;
    }
}

}
 
REGISTER_OBSERVER(PointwiseAvgCurran)

