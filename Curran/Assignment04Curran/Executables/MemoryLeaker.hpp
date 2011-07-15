#ifndef ASSIGNMENT04CURRAN_MEMORYLEAKER_HPP_
#define ASSIGNMENT04CURRAN_MEMORYLEAKER_HPP_

class MemoryLeaker {
  public:
    MemoryLeaker(const int n) :
        pLeaky(new double[n]) {
    }

    ~MemoryLeaker() {
        delete[] pLeaky;
    }

    void Reset(const int n) {
        delete[] pLeaky;
        pLeaky = new double[n];
    }

  private:
    double* pLeaky;  
};

#endif // ASSIGNMENT04CURRAN_MEMORYLEAKER_HPP_

