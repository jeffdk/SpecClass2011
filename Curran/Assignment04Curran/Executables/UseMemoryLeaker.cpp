#include <cstdlib>

#include "MemoryLeaker.hpp"

int main(int /*argc*/, char** /*argv*/) {
    // bla bla bla
 
    {
        MemoryLeaker* pMemLeaker = new MemoryLeaker(3);
        pMemLeaker->Reset(5);
        delete pMemLeaker;
    }
 
    // Memory allocated should be the same as at "bla bla bla" if no leaks
    return EXIT_SUCCESS;
}

