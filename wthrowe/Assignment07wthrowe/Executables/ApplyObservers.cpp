///
/// \file
/// Runs Observer's on a Domain.input file with associated .dump-files.
/// \ingroup Support 

#include "Support/ApplyObservers/ApplyObserversWork.hpp"
#include "Utils/ErrorHandling/BasicMpi.hpp"
#include "Utils/ErrorHandling/MpiConstants.hpp"
#include "Utils/MpiWrappers/MpiCommunicator.hpp"
#include "Utils/LowLevelUtils/CompileInfo.hpp"


int main(int argc, char* argv[])
{
  MpiInit(&argc, &argv);
  const MpiCommunicator world(MpiConst::MpiCommWorld());
  if(world.Rank()==0) std::cout << CompileInfo();

  ApplyObserversWork(argc, argv, world, "", "");

  MpiFinalize();
  return 0;  // 0 indicates success!
}

//============================================================================
