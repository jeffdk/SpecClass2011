#include <cstdlib>
#include "Tensor.hpp"
#include "DataMesh.hpp"
#include "InvertTensorBohn.hpp"

int CompareTensors(const Tensor<DataMesh> a, const Tensor<DataMesh> b)
{
  //Should require these are the same dimensions and all of that

  Tensor<DataMesh> diff = a;

  for (int i = 0; i < diff.Dim(); i++)
    for (int j = 0; j < diff.Dim(); j++)
      diff(i, j) = a(i, j) - b(i, j);

  int numErrors = 0;

  const double tol = 1.0e-10;
  for (int j = 0; j < diff.Dim(); j++)
    for (int k = 0; k < diff.Dim(); k++)
      for (int i = 0; i < diff(0, 0).Size(); i++)
      {
        if (diff(j, k)[i] > tol || diff(j, k)[i] < -tol)
        numErrors++;
      }
  return numErrors;
}

Tensor<DataMesh> InvertTensor(const Tensor<DataMesh> input)
{
  const Mesh m(input(0, 0));
  Tensor<DataMesh> output = input;;

  const double tol = 1.0e-16;

  // Use the explicit formula for efficiency
  // Let's use adj A over det A
  DataMesh detInput(m);
  detInput =
      input(0, 0) * (input(1, 1) * input(2, 2) - input(1, 2) * input(2, 1))
    + input(0, 1) * (input(1, 2) * input(2, 0) - input(1, 0) * input(2, 2))
    + input(0, 2) * (input(1, 0) * input(2, 1) - input(1, 1) * input(2, 0));

  for (int i = 0; i < detInput.Size(); i++)
    REQUIRE(detInput[i] > tol || detInput[i] < -tol,
      "Tensor cannot be inverted, determinant is zero");

  output(0, 0) = (input(1, 1)*input(2, 2)-input(1, 2)*input(2, 1)) / detInput;
  output(0, 1) = (input(0, 2)*input(2, 1)-input(0, 1)*input(2, 2)) / detInput;
  output(0, 2) = (input(0, 1)*input(1, 2)-input(0, 2)*input(1, 1)) / detInput;
  output(1, 1) = (input(0, 0)*input(2, 2)-input(0, 2)*input(2, 0)) / detInput;
  output(1, 2) = (input(0, 2)*input(1, 0)-input(0, 0)*input(1, 2)) / detInput;
  output(2, 2) = (input(0, 0)*input(1, 1)-input(0, 1)*input(1, 0)) / detInput;

  // If it's not symmetric, we need to do the entire tensor
  if (input.Structure() != TensorStructure(input.Dim(), "aa"))
  {
    output(1, 0) = (input(1, 2)*input(2, 0)-input(1, 0)*input(2, 2))/detInput;
    output(2, 0) = (input(1, 0)*input(2, 1)-input(1, 1)*input(2, 0))/detInput;
    output(2, 1) = (input(0, 1)*input(2, 0)-input(0, 0)*input(2, 1))/detInput;
  }
  return output;
}
