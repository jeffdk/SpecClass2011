template<typename> class MyVector;

/**
 * Add two vectors together, component by component, and return the sum.
 *
 * @param v1    first vector addend
 * @param v2    second vector addend
 * @return      the vectors' sum
 */
MyVector<double> SumVectors(const MyVector<double>& v1,
                            const MyVector<double>& v2);

/**
 * Add two vectors together, component by component, divides the sum by a
 * scalar, and return the result.
 *
 * @param v1            first vector addend
 * @param v2            second vector addend
 * @param divisor       scalar to divide sum by
 * @return              the vectors' sum
 */
MyVector<double> SumVectorsAndDivide(const MyVector<double>& v1,
                                     const MyVector<double>& v2,
                                     double divisor);

