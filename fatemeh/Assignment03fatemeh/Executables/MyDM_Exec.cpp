    #include "DataMesh.hpp"
    #include <cstdlib>
     
    int main(void) {
      const IPoint extents(MV::Size(3), 10);
      const Mesh m(extents);
      DataMesh a(m);
      for (int i=0; i<10; i++){
	for (int j=0; j<10; j++){
	  for (int k=0; k<10; k++){
	    int n=k*100+j*10+i;
	    a[n]=1000*i + 100*j + 100000*k;
	    //only for check
	    //if (i==3 && j==9 && k==5){
	    //std::cout<<"a(1,2,3)="<<a[n]<<std::endl;
	    //}
	    //if (a[n]==301200){
	    //std::cout<<"a[n]=301200 at i="<<i<<" j="<<j<<" k="<<k<<std::endl;
	    //}
	  }
	}
      }
      
      std::cout << "DataMesh a=:"<<a<<"\n";
      //const IPoint p1(MV::fill,1,2,3);
      //std::cout << "index of point " << p1 << "="<< m.DataOffset(p1)<<"\n";
      	
      return EXIT_SUCCESS;
    }

	
