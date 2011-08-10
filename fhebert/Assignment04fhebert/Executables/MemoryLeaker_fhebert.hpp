class MemoryLeaker {
  public:
    MemoryLeaker(const int n) 
      : pLeaky(new double[n]) {}

    // here we had  made a new double[n], so the class destructor
    // should delete it with delete[] as appropriate for arrays
    ~MemoryLeaker() {delete[] pLeaky;}

    // here we should delete before reallocating
    void Reset(const int n) {
      delete[] pLeaky;
      pLeaky = new double[n];
    }

  private:
    double * pLeaky;  
};
