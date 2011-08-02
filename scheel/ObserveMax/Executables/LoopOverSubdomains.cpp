#include "Utils/ErrorHandling/BasicMpi.hpp"
#include "Utils/ErrorHandling/MpiConstants.hpp"
#include "Utils/MpiWrappers/MpiCommunicator.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "Dust/Domain/Domain.hpp"

int main(int argc, char **argv) {

  // Set up parallelism
  MpiInit(&argc,&argv); 
  const MpiCommunicator world(MpiConst::MpiCommWorld());

  // Make a Domain from the Domain.input file.
  Domain D(ReadFileIntoString("Domain.input"),world);

  const int MyProcNumber = world.Rank(); // The number of this processor

  // Print out number of subdomains on each processor:
  std::cout << "Proc " << MyProcNumber << ": Number of subdomains = " 
	    << D.Size() << std::endl;

  // Loop over subdomains
  for(int sd=0;sd<D.Size();++sd) {
    std::cout << "Proc " << MyProcNumber << ": Subdomain " << sd 
	      << " name=" << D[sd].Name() 
	      << " extents=" << D[sd].Extents() << std::endl;
  }

  // Clean up
  MpiFinalize();
  return 0;
}
