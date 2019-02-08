#include "convolution.hpp"

tuple<double*,int> createArray(vector<vector<float> >temp){
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

