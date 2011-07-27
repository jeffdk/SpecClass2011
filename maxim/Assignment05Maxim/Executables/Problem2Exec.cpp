#include <cstdlib> // for EXIT_SUCCESS and string(?)

#include "OneDimDataWriter.hpp" // includes MyVector.hpp
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "BasicMpi.hpp"
#include "ComputeProfileAndOutput.hpp"

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

