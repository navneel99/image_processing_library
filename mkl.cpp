#include "convolution.hpp"
#include "mkl.h"

vector<float> mklImpl(vector<vector<float> > temp, vector<float> ker){
  int t = temp.size();
  int m = sqrt(ker.size());
  double *A, *B, *C;
  int s =sqrt(t);
  //vector<vector<float> > res(s,vector<float>(s));
//  A = new double[t*m*m];
  A = (double *)mkl_malloc(t*m*m*sizeof( double),64 );
  B = (double *)mkl_malloc(m*m*sizeof( double),64 );
  C = (double *)mkl_malloc(t*sizeof( double),64 );
  
//  B = new double[m*m];
//  C = new double[t];
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
  vector<float>  res(t);
  /*for (int i =0;i<s;i++){
    for (int j=0;j<s;j++){
      res[i][j] = (float) C[i*s+j];
    }
  }*/
  for (int i = 0; i<t; i++){
    res[i] = (float) C[i];
  }
  return res;
}
