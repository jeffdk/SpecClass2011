#include "MyVector.hpp"
#include "OneDimDataWriter.hpp"
#include "BasicMpi.hpp"
#include "MpiCommunicator.hpp"
#include "ReadFileIntoString.hpp"
#include "OptionParser.hpp"
#include <cstdlib>
#include <cmath>

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

int main(int argc, char** argv) {

    MpiInit(&argc, &argv);
        const std::string helptxt =
	  "OneDFormat.input:                                                       \n"
	  "Input file for Assignment 5, Problem 2.                                 \n"
	  "Format   = string;               # Which 1-D output format              \n"
	  "Basename = string;               # Filename (without extension)         \n"
	  "Times    = double, double, ...;  # Which times to output                \n";
 
    const std::string options = ReadFileIntoString("OneDFormat.input");
    OptionParser parser(options, helptxt);
    const std::string format   = parser.Get<std::string>("Format");
    const std::string basename = parser.Get<std::string>("Basename");
    MyVector<double> times     = parser.Get<MyVector<double> >("Times");
 
    OneDimDataWriter* pWriter = OneDimDataWriter::Create(format, basename);
    for(int i = 0; i < times.Size(); ++i) {
        ComputeProfileAndOutput(times[i], pWriter);
    }
    delete pWriter;

    MpiFinalize();
    return EXIT_SUCCESS;
}
