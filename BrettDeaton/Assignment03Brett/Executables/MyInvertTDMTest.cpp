// Matrix inversion applied to a tensor field
//   Brett Deaton
//   7.12.11

#include "StudentProjects/SpecClass2011/BrettDeaton/Assignment03Brett/InvertTDMBrett.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/LowLevelUtils/Ran2Class.hpp"
#include <cstdlib>
    
int main(void) {

  TensorStructure s(3,"aa");

  const Mesh m1(IPoint(MV::fill,1,1));
  Tensor<DataMesh> tdm1(s,m1);

  // **************************************************************************
  // a really easy test: inverse of I
  for(int a=0;a<3;++a){
    for(int b=0;b<=a;++b){
      tdm1(a,b)[0] = (a==b) ? 1 : 0;
    }
  }
  std::cout << "*** Test 1 ***\n";
  std::cout << "I =\n" << tdm1 << "\n";
  std::cout << "I^{-1} =\n" << InvertTDM(tdm1) << "\n";

  // **************************************************************************  
  // a sort of easy test: inverse of {{1,0,0},  =   {{1,0,0},
  //                                  {0,2,0},       {0,0.5,0},
  //                                  {0,0,5}}       {0,0,0.2}}
  tdm1(1,1)[0]=2;
  tdm1(2,2)[0]=5;
  std::cout << "\n*** Test 2 ***\n";
  std::cout << "A =\n" << tdm1 << "\n";
  std::cout << "A^{-1} =\n" << InvertTDM(tdm1) << "\n";

  // **************************************************************************
  // a hard test: inverse of {rand}:
  Ran2 rand(123435);
  for(int a=0;a<3;++a){
    for(int b=0;b<=a;++b){
      tdm1(a,b)[0] = rand();
    }
  }

  Tensor<DataMesh> itdm1(InvertTDM(tdm1));
  std::cout << "\n*** Test 3 ***\n";
  std::cout << "B =\n" << tdm1 << "\n";
  std::cout << "B^{-1} =\n" << itdm1 << "\n";
  std::cout << "B*B^{-1} =\n" << MatrixMultiply(tdm1,itdm1) << "\n";
  
  // **************************************************************************
  // the hardest test: now do it for a 3D tensor field
  const Mesh m2(IPoint(MV::fill,10,10,10));
  Tensor<DataMesh> tdm2(s,m2);
  
  // populate the tensor field with gibberish
  IPoint p(MV::fill,0,0,0);
  for(int a=0;a<3;++a){
    for(int b=0;b<=a;++b){
      for(int i=0;i<tdm2(a,b).Extents()[0];++i){
	for(int j=0;j<tdm2(a,b).Extents()[1];++j){
	  for(int k=0;k<tdm2(a,b).Extents()[2];++k){
	    p.assign(MV::fill,i,j,k);
	    tdm2(a,b)[tdm2(a,b).DataOffset(p)] = rand();
	  }
	}
      }
    }
  }

  Tensor<DataMesh> itdm2(InvertTDM(tdm2));
  Tensor<DataMesh> ShouldBeI(MatrixMultiply(tdm2,itdm2));
  double epsilon = 1000*pow(2.,-53.); // let's be generous here
  std::cout << epsilon << "\n";
  std::cout << "\n*** Test 4 ***\n";
  // std::cout << "C =" << tdm2 << "\n";
  // std::cout << "C^{-1} =" << itdm2 << "\n";
  // std::cout << "C*C^{-1} = " << ShouldBeI << "\n";
  std::cout << "Checking that C*C^{-1} = I to order roundoff.\n";
  for(int a=0;a<3;++a){
    for(int b=0;b<3;++b){
      for(int i=0;i<tdm2(a,b).Extents()[0];++i){
        for(int j=0;j<tdm2(a,b).Extents()[1];++j){
          for(int k=0;k<tdm2(a,b).Extents()[2];++k){
            p.assign(MV::fill,i,j,k);
	    if(a==b){
	      if(fabs(ShouldBeI(a,b)[tdm2(a,b).DataOffset(p)]-1.)>epsilon){
		std::cout << "A diagonal element of C*C^{-1} is not unity within O(roundoff).\n";
		std::cout << "~I(" << a << "," << b << ")[" << p << "]-1 = " <<
		  ShouldBeI(a,b)[tdm2(a,b).DataOffset(p)]-1. << "\n";
	      }
	    }
	    else{
	      if(fabs(ShouldBeI(a,b)[tdm2(a,b).DataOffset(p)])>epsilon){
		std::cout << "An off diagonal element of C*C^{-1} is not O(roundoff).\n";
		std::cout << "~I(" << a << "," << b << ")[" << p << "] = " <<
		  ShouldBeI(a,b)[tdm2(a,b).DataOffset(p)] << "\n";
	      }
	    }
          }
        }
      }
    }
  }
  
  return EXIT_SUCCESS;
}
