#include <cmath>

#include "ComputeProfileAndOutput.hpp"
#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/MyContainers/MyVector.hpp"

// Computes the x's and y's and outputs the result
void ComputeProfileAndOutput(const double t,
                             const OneDimDataWriter* writer) {
    const int N = 1024;
    MyVector<double> x(MV::Size(2*N+1)), y(MV::Size(2*N+1));
    for(int i = 0; i <= 2*N; ++i) {
        x[i] = 0.01*(i-N);
        y[i] = exp(-x[i]*x[i]/(t*t)); // heat-diffusion
    }
    writer->AppendToFile(t, x, y);
}
