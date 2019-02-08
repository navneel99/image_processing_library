#include "../convolution.hpp"
#include "mkl.h"

/*tuple<double*,int> createArray(vector<vector<float> >temp){
  int t = temp.size();
  //int m = sqrt(temp[0].size())
  int m = temp[0].size();
  double *A;
  A = new double[t*m];
  for (int i=0;i<t;i++){
    for (int j =0; j<m;j++){
      A[i*m+j] = static_cast<double>(temp[i][j]);
    }
  }
  return make_tuple(A,t*m);
}

tuple<double*,int> createArray(vector<float> ker){
  int m = (ker.size());
  double *B;
  B = new double[m];
  for (int i =0; i<m;i++){
    B[i] = static_cast<double>(ker[i]);
  }
  return make_tuple(B,m);
}

vector<float> collectResult(tuple<double*,int> Ct){
  int len = get<1>(Ct);
  double* C = get<0>(Ct);
  vector<float> result(len);
  for (int i = 0; i< len; i++){
    result[i] = (float)C[i];
  }
  return result;
}
*/
tuple<double*,int> mklMatMul(tuple<double*,int> At, tuple<double*,int> Bt){
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

vector<float> mklImpl(vector<vector<float> > temp, vector<float> ker){
  int t = temp.size();
  int m = sqrt(ker.size());
  double *A, *B, *C;
  int s =sqrt(t);


  A = (double *)mkl_malloc(t*m*m*sizeof( double),64 );
  B = (double *)mkl_malloc(m*m*sizeof( double),64 );
  C = (double *)mkl_malloc(t*sizeof( double),64 );
  

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

  for (int i = 0; i<t; i++){
    res[i] = (float) C[i];
  }
  return res;
}
