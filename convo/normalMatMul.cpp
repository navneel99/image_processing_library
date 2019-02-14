#include "convolution.hpp"

vector<float> normalMatMul(vector<vector<float> > temp, vector<float> ker){
  int t = temp.size();
  int m = sqrt(ker.size());
  vector<float> result(t,0);
  for (int i = 0; i < t; i++){
    for (int j = 0; j < m*m; j++){
      result[i] += temp[i][j] * ker[j];
    }
  }
 
  //returning the result
  return result;

}