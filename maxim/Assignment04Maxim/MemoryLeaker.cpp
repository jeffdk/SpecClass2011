#include "MemoryLeaker.hpp"

MemoryLeaker::MemoryLeaker(const int n) : pLeaky(new double[n]) {}

MemoryLeaker::~MemoryLeaker() {
	delete[] pLeaky; // adding [] after delete
}

void MemoryLeaker::Reset(const int n){
	delete[] pLeaky;// deleting the old array
	pLeaky = new double[n];
}
