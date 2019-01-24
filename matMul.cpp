#include "convolution.hpp"
vector<vector<float> > convm(vector<vector<float> > array, vector<vector<float> > kernel, int x, int stride,string type){

//calling the padding  function   
    vector<vector<float>> arr = Padding(array, x);

    int n=arr.size();
    int m=kernel.size();
    int t=(((n-m)/stride) +1)*(((n-m)/stride) +1);

    int k=0;
    vector<vector<float> > temp(t,vector<float>(m*m));
    vector<float> ker(m*m);

//making an temp kernel so that we can use it for multiplication
    for(int i=0; i<m; i++){
      for(int j=0; j<m; j++){
        ker[k]=kernel[i][j];
        k+=1;
      }
    }
    k=0;

//Making the matrix from the input matrix and kernel 
    for(int i=0; i<n; i+=stride){
        for(int j=0; j<n; j+=stride){
            int l=0;
            if(i+m<=n && j+m<=n){
            for(int ii=0; ii<m; ii++){
              for(int jj=0; jj<m; jj++){
                temp[k][l]=arr[i+ii][j+jj];
                l+=1;
              }
             }
             k+=1;
            }else{
              break;
            }
        }
    }

//Performing matrix multiplication and storing the result in the vector of size n-m+1 * n-m+1
vector<vector<float> >result ;
if (type == "MKL"){
  result = mklImpl(temp,ker,m,t);
} else if (type == "openBlas"){
  result = cBlasImpl(temp,ker,m,t);
} else{
  result = Pthread(temp,ker,m,t);
}


//returning the vector 
return result;
}


//Multiplication using pthreads
vector<vector<float> > normalMatMul(vector<vector<float> > temp, vector<float> ker,int n,int m,int t,int stride){

  vector<vector<float>> O(((n-m)/stride)+1);
  int counter=((n-m)/stride)+1;
  int count=-1;

  for(int p=0; p<t; p++){
    int res=0;
    if(counter == ((n-m)/stride)+1){
      counter=0;
      count+=1;
      O[count]=vector<float>(((n-m)/stride)+1);
    }
    for(int q=0; q<m*m; q++){
      res=res+temp[p][q]*ker[q];
    }
    O[count][counter]=res;
    counter+=1;
  }

  //calling the pthread function to get the result. This function is definied in the file named Pthread.cpp
  vector<vector<float> > result = Pthread(temp,ker, m, t);

  //returning the result
  return result;

}
