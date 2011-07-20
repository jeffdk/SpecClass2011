#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "Assignment02Bohn.hpp"

#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"

int main(int /*arg*/, char** /*argv*/) {
	OptionParser p(ReadFileIntoString("Vectors.input"));
	const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
	const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
	const double C = p.Get<double>("DenominatorOfQuotient");

	//These two take care of all of the equalities
	REQUIRE(A.Size() == B.Size(), "Error: vectors A and B not the same size.\n");
	const MyVector<double> sum = SumVectors(A, B);

	// Should write a function to calculate magnitude, although I'm sure
	// MyVector knows it's magnitude
	double resultMagnitudeSq = 0.0;
	for (int i = 0; i < sum.Size(); i++)
		resultMagnitudeSq += sum[i] * sum[i];

	//Use one of these.  If the inputs to SumVectors are from numerical
	//calculations, consider using resultMagnitudeSq < tol for some small tol
  //REQUIRE(resultMagnitudeSq == 0, "Error: vectors don't sum to zero.\n");
	//IS_ZERO(resultMagnitudeSq ,"Sum of vector and its negative nonzero...bug?")

  //REQUIRE(C != 0, "Denominator cannot be zero.\n");
  IS_TRUE(C != 0, "Denominator cannot be zero.\n");

	const MyVector<double> quotient = DivideVectors(sum, C);

	// I don't need the old result magnitude anymore.  It's not great practice
	// but I'll use it again anyway.  I would make these variable names
	// more descriptive, and they would be unique
	resultMagnitudeSq = 0.0;
	for (int i = 0; i < quotient.Size(); i++)
		resultMagnitudeSq += quotient[i] * quotient[i];

	REQUIRE(resultMagnitudeSq == 0, "Error: vectors' quotient should be zero");


	std::cout << "Vector A = " << A << std::endl;
	std::cout << "Vector B = " << B << std::endl;
	std::cout << "Sum      = " << sum << std::endl;
	std::cout << "C = " << C << std::endl;
	std::cout << "Quotient = " << quotient << std::endl;

	return UtilsForTesting::NumberOfTestsFailed();
}
