    #include "DataMesh.hpp"
    #include "Tensor.hpp"
    #include <cstdlib>
    #include "Ran2Class.hpp"

//Inverse
Tensor<DataMesh> Inverse(Tensor<DataMesh> a){
  //check if the matrix is symmetric, 3*3 and invertible
  //*********************************************************
  for (int i=0; i<a.Dim();i++){
    for (int i=0; j<a.Dim();j++){
      REQUIRE (a(i,j)==a(j,i),"The matrix is not symmetric.");
    }
  }
  REQUIRE (a.Dim()=3,"The matrix is not 3*3.");
  REQUIRE (Det!=0,"The matrix is not invertible");
  //*********************************************************
  Tensor<DataMesh> Inva(3,aa,a);
  for (int n=0; n<a.Size(); n++){
    Tensor<double> CFa(3,aa,0.0);
    double Deta = GetDet(a);
    CFa = GetCofactor(a);
    Inva[n] = CFa/Deta;
  }
  return Inva;
}


///Cofactor
Tensor<double> GetCofactor(Tensor<double> a){
  Tensor<double> C(3,aa,0.0);
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      MyVector<int> Index(MV::fill,i+1,i+2,j+1,j+2);
      for(int k=0; k<4; k++){
	if(Index(k)==3){Index(k)=0;}
	if(Index(k)==4){Index(k)=1;}
      }
      C(i,j)=pow(-1,i+j)*(a(Index(0),Index(3))*a(Index(1),Index(2))-a(Index(1),Index(3))*a(Index(0),Index(2)));
    }
  }
  return C;
}

//Determinant
double GetDet(Tensor<double> a){
  Tensor<double> Cofactor(3,aa,0.0) = GetCofactor(a);
  double Det = 0;
  for (int i=0; i<3; i++){
    Det += a(0,i)*Cofactor(0,i);
  }
  return Det;
}

//Multiplication of two matrix:
//**************This part is not complete yet!

   int main(void) {
      const IPoint extents(MV::Size(2), 2);
      const Mesh m(extents);
      Tensor<DataMesh> A(3,"aa",m,1.0);
      Tensor<DataMesh> InverseA(3,"aa",m,1.0);
      Ran2 ran(123456);
	for(int n=0; n<A.Size(); n++){
	  for(int i=0; i<3; i++){
	    for(int j=0; j<3; j++){
	      A(i,j)[n]=ran();
	    }
	  }
	}
	InverseA = Inverse(A);
	
	REQUIRE(MLTP(A,InverseA)=Identity;"The multiplication of tensor and its inverse is not the identity matrix.")


      return EXIT_SUCCESS;
    }

