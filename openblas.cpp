#include "convolution.hpp"
#include <cblas.h>

double* createArray(vector<vector<float> >temp){
  int t = temp.size();
  int m = sqrt(temp[0].size());
  double *A;
  A = new double[t*m*m];
  for (int i=0;i<t;i++){
    for (int j =0; j<m*m;j++){
      A[i*m*m+j] = static_cast<double>(temp[i][j]);
    }
  }
  return A;
}

double* createArray(vector<float> ker){
  int m = sqrt(ker.size());
  double *B;
  B = new double[m*m];
  for (int i =0; i<m*m;i++){
    B[i] = static_cast<double>(ker[i]);
  }
  return B;
}

double* cBlasMatMul(double* A, double* B){
  double* C;

  int sqM = sizeof(B)/sizeof(B[0]);
  int full = sizeof(A)/sizeof(A[0]);
  int t = full/sqM;
  C = new double[t];
  cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,t,1,sqM,1,A,sqM,B,1,1,C,1);
  return C;
}

vector<float> collectResult(double* C){
  int len = sizeof(C)/sizeof(C[0]);
  vector<float> result(len);
  for (int i = 0; i< len; i++){
    result[i] = (float)C[i];
  }
  return result;
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
