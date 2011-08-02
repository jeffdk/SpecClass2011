#include "Utils/ErrorHandling/BasicMpi.hpp"
#include "Utils/ErrorHandling/MpiConstants.hpp"
#include "Utils/MpiWrappers/MpiCommunicator.hpp"
int main(int argc, char **argv) {

  // Initializes MPI.  The argc,argv are for command-line arguments.
  MpiInit(&argc,&argv); 

  // Set up a Communicator called 'world', meaning all processors.
  const MpiCommunicator world(MpiConst::MpiCommWorld());

  // Each processor has a number.
  const int MyProcNumber = world.Rank(); 

  // Print a message
  std::cout << "Proc " << MyProcNumber << " says Hello World" << std::endl;

  // Clean up
  MpiFinalize();
  return 0;
}
