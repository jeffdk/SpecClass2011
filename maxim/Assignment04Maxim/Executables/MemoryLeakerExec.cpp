#include "MemoryLeaker.hpp"

int main() {
   // bla bla bla
 
  {
    MemoryLeaker* pMemLeaker = new MemoryLeaker(3);
    pMemLeaker->Reset(5);
	delete pMemLeaker; // deleting pMemLeaker at the end of the block
  }
 
  // Memory allocated should be same as at bla bla bla if no leaks
  return 0;
}
