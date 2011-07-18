#include "MyRaiseToPower_fhebert.hpp"
// in this implementation, the compiler catches the bug
unsigned int MyRaiseToPower(const unsigned int a, const unsigned int n)
{
  // NOTE: this line fixes the bug. this is so that I can run make 
  // without it spewing errors at me all the time
  if (n==0) return 1;

  // this line is the one you wanted for the assignment. swap the comments
  // to check that the bug is indeed catched by the compiler.
  //if (n=0) return 1;

  if (n>1) return a*MyRaiseToPower(a, n-1);
  return a;
}

