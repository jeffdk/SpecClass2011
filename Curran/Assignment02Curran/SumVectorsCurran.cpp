#include "SumVectorsCurran.hpp"

#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/Require.hpp"
 
MyVector<double> SumVectors(const MyVector<double>& v1,
                            const MyVector<double>& v2) {
    // Check preconditions
    REQUIRE(v1.Size() == v2.Size(), "Addends must be the same size");

    // Make a new MyVector<double> of the same size as the addends and fill
    //   each element with zero
    const int vectorSize = v1.Size();
    MyVector<double> sum(MV::Size(vectorSize), 0.0);
 
    // Add the vectors component-by-component
    for(int i = 0; i < vectorSize; ++i) {
        sum[i] = v1[i] + v2[i];
    }
 
    return sum;
}

MyVector<double> SumVectorsAndDivide(const MyVector<double>& v1,
                                     const MyVector<double>& v2,
                                     const double divisor) {
    // Check preconditions
    REQUIRE(v1.Size() == v2.Size(), "Addends must be the same size");
    //REQUIRE(divisor != 0.0, "Divisor must be non-zero");

    // Make a new MyVector<double> of the same size as the addends and fill
    //   each element with zero
    const int vectorSize = v1.Size();
    MyVector<double> sum(MV::Size(vectorSize), 0.0);
 
    // Add the vectors component-by-component
    for(int i = 0; i < vectorSize; ++i) {
        sum[i] = (v1[i] + v2[i]) / divisor;
    }
 
    return sum;
}

