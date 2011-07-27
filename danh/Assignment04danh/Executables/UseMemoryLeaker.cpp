#include "MemoryLeaker_danh.hpp"
int main() {
   // bla bla bla
 
  {
    MemoryLeaker* pMemLeaker = new MemoryLeaker(3);
    pMemLeaker->Reset(5);
  }
 
  // Memory allocated should be same as at bla bla bla if no leaks
}
