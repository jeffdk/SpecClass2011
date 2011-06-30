#include <cstdlib>
#include <string>
#include <iostream>
 
#include "SumVectorsCurran.hpp"
#include "MyVector.hpp"
#include "ReadFileIntoString.hpp"
#include "OptionParser.hpp"
#include "UtilsForTesting.hpp"

/** \file
 * Tests the SumVectors and SumVectorsAndDivide functions using an input file.
 * The addends in the input file must be minus one another, or the test will
 * fail.  The test will also fail if the divisor is zero.
 */
 
int main(int /*argc*/, char** /*argv*/) {
    // Read in operands from input file
    std::string opts = ReadFileIntoString("Vectors.input");
    OptionParser parser(opts);
    const MyVector<double> v1 =
            parser.Get<MyVector<double> >("FirstVectorToAdd");
    const MyVector<double> v2 =
            parser.Get<MyVector<double> >("SecondVectorToAdd");
    const double divisor = parser.Get<double>("Divisor");

    // Ensure that divisor is not zero
    //REQUIRE(divisor != 0.0, "Divisor must be non-zero.");
    IS_TRUE(divisor != 0.0, "Divisor must be non-zero.");
 
    // Store sum of vectors in a new vector
    MyVector<double> result = SumVectorsAndDivide(v1, v2, divisor);

    // Test that the magnitude of the result is zero
    double mag_sq = 0.0;
    for (int i = 0; i < result.Size(); ++i) {
        mag_sq += result[i]*result[i];
    }
    IS_ZERO(mag_sq, "Vectors did not sum to zero.");
 
    // Print out the results
    std::cout << "Vector 1 = " << v1 << std::endl;
    std::cout << "Vector 2 = " << v2 << std::endl;
    std::cout << "Sum      = " << result << std::endl;
 
    // Return success
    return UtilsForTesting::NumberOfTestsFailed();
}

