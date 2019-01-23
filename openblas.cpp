#include "convolution.hpp"
#include <cblas.h>

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
