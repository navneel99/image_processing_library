#include "convolution.hpp"
vector<vector<float>> convm(vector<vector<float> > array, vector<vector<float> > kernel, int x, int stride,string type){

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
} else if (type == "openBlas"){
  result = cBlasImpl(temp,ker,n,m,t,stride);
} else{
  result = normalMatMul(temp,ker,n,m,t,stride);
}


//returning the vector 
return result;
}

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
  return O;

}

vector<vector<float> >cBlasImpl(vector<vector<float> > temp, vector<float> ker,int n,int m,int t,int stride){
  double *A, *B, *C;
  int s =sqrt(t);
  vector<vector<float> > res(s,vector<float>(s));
  A = new double[t*m*m];
  B = new double[m*m];
  C = new double[t];
  for (int i=0;i<t;i++){
    for (int j =0; j<m*m;j++){
      A[i*m*m+j] = static_cast<double>(temp[i][j]);
    }
  }
  for (int i =0; i<m*m;i++){
    B[i] = static_cast<double>(ker[i]);
  }
  cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,t,1,m*m,1,A,m*m,B,1,1,C,1);
  //resultant matrix has shape tx1 now, need to change to sxs
  for (int i =0;i<s;i++){
    for (int j=0;j<s;j++){
      res[i][j] = (float) C[i*s+j];
    }
  }
  return res;
}