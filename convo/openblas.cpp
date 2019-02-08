#include "convolution.hpp"
#include <cblas.h>


tuple<double*,int> cBlasMatMul(tuple<double*,int> At, tuple<double*,int> Bt){
  double* C;
  int sqM = get<1>(Bt);
  int full = get<1>(At);
  double* A = get<0>(At);
  double* B = get<0>(Bt);
  int t = full/sqM;
  C = new double[t];
  cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,t,1,sqM,1,A,sqM,B,1,1,C,1);

  return make_tuple(C,t);
}

vector<float> cBlasImpl(vector<vector<float> > temp, vector<float> ker){
  int t = temp.size();
  int m = sqrt(ker.size());
  double *A, *B, *C;
  int s =sqrt(t);
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
  vector<float> res(t);
  for (int i = 0; i<t; i++){
    res[i] = (float) C[i];
  }
  return res;
}
