#include <cstdlib>
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/ErrorHandling/Require.hpp"

using namespace std;

Tensor<DataMesh> InverseTensor3x3(const Tensor<DataMesh>& t);

int main(void) {
	const int dim = 3;
	Mesh m(IPoint(MV::fill, 1, 1, 1));
	Tensor<DataMesh> t(dim, "aa", m);

	// populating the elements of the tensor
	srand ( time(NULL) );
	for(int i = 0; i < dim; i++) {
		for(int j = i; j < dim; j++) {
			t(i,j) = rand()%10; // random from 0 to 9
			if(i != j)			
				t(j,i) = t(i,j);			
		}
	}
	cout << "3x3 2nd rank tensor" << endl;		
	cout << t << endl;

	Tensor<DataMesh> t_inv(dim, "aa", m); // tensor for storing the inverse

	cout << endl << "Inverting..." << endl;
	t_inv = InverseTensor3x3(t);
	cout << t_inv;

	cout << endl << "Inverting again..." << endl;
	Tensor<DataMesh> t_inv_inv(dim, "aa", m); // storage for the inverse of the inverse
	t_inv_inv = InverseTensor3x3(t_inv);
	cout << t_inv_inv << endl;

	/*
	cout << endl << "Using member function InvertMatrix" << endl;
	
	Tensor<DataMesh> t_inv2(dim, "aa", m);
	t_inv2 = InvertMatrix(t);

	cout << t_inv2 << endl;
	*/

	return EXIT_SUCCESS;
}

/*
	InverseTensor3x3 calculates the inverse of 2nd rank 3x3 tensor t
	The function returns the inverse
*/
Tensor<DataMesh> InverseTensor3x3(const Tensor<DataMesh>& t) {
	//Mesh m(IPoint(MV::fill, 3, 3));
	Mesh m = t(0,0); // extracting the mesh out of the tensor
	DataMesh det(m), A(m), B(m), C(m), D(m), E(m), F(m), G(m), H(m), K(m);
	int dim = t.Dim(), rank = t.Rank();
	
	REQUIRE(3 == dim, "Should be in three dimensions");	
	REQUIRE(2 == rank, "Should be of rank 2");	


	Tensor<DataMesh> t_inv(dim, "aa", m);
	
	// the first column elements	
	A = t(1,1)*t(2,2) - t(1,2)*t(2,1);
	B = t(1,2)*t(2,0) - t(1,0)*t(2,2);
	C = t(1,0)*t(2,1) - t(1,1)*t(2,0);
	
	// second
	D = t(0,2)*t(2,1) - t(0,1)*t(2,2);
	E = t(0,0)*t(2,2) - t(0,2)*t(2,0);
	F = t(2,0)*t(0,1) - t(0,0)*t(2,1);
	
	// third	
	G = t(0,1)*t(1,2) - t(0,2)*t(2,2);
	H = t(0,2)*t(1,0) - t(0,0)*t(1,2);
	K = t(0,0)*t(1,1) - t(0,1)*t(1,0);
	
	
	det = t(0,0)*A + t(0,1)*B + t(0,2)*C; // determinant

	// matrix singularity check	
	
	for(int i = 0; i < det.Size(); ++i)	
		REQUIRE(det[i] != 0, "Matrix is singular");

	t_inv(0,0)=A/det;	t_inv(0,1) = D/det;		t_inv(0,2) = G/det;
	t_inv(1,0)=B/det;	t_inv(1,1) = E/det;		t_inv(1,2) = H/det;
	t_inv(2,0)=C/det;	t_inv(2,1) = F/det;		t_inv(2,2) = K/det;

	return t_inv;
}
