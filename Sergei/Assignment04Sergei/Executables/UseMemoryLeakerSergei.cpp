#include "MemoryLeakerSergei.hpp"
int main() {
   // bla bla bla

  {
    MemoryLeaker* pMemLeaker = new MemoryLeaker(3);
    pMemLeaker->Reset(5);
    // Need to explicitly delete pMemLeaker since the destructor is not
    // called when it goes out of scope.
    delete pMemLeaker;
  }
 
  // Memory allocated should be same as at bla bla bla if no leaks
  return 0;
}
