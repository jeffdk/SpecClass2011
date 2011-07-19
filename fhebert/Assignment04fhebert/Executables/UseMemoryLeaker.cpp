#include "MemoryLeaker.hpp"
int main() {
  // bla bla bla
    
  {
    MemoryLeaker* pMemLeaker = new MemoryLeaker(3);
    pMemLeaker->Reset(5);
    
    // deallocate pointer before it goes out of scope and the
    // corresponding memory blocks get lost
    delete pMemLeaker;
  }
                
  // Memory allocated should be same as at bla bla bla if no leaks
  return 0;
}
