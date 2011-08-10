class MemoryLeaker {
public:
  MemoryLeaker(const int n) 
    : pLeaky(new double[n]) {}

  //here pLeaky is an array, so we have to 
  //delete it with delete[]
  ~MemoryLeaker() {delete[] pLeaky;}
  void Reset(const int n) {
    delete[] pLeaky;
    pLeaky = new double[n];
  }
private:
  double * pLeaky;  
};
