#include "StudentProjects/SpecClass2011/Ilana/Assignment04Ilana/Executables/MemoryLeaker_Ilana.hpp"

int main() {
   // bla bla bla
 
  {
    MemoryLeaker* pMemLeaker = new MemoryLeaker(3);
    pMemLeaker->Reset(5);

    //delete pMemLeaker so that memory is de-allocated
    delete pMemLeaker;
  }

 
  // Memory allocated should be same as at bla bla bla if no leaks
  return 0;
}
