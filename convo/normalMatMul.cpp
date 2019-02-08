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
  /*
  vector<vector<float> > O(((n-m)/stride)+1);
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
  vector<float>  result = Pthread(temp,ker);
  */
  //returning the result
  return result;

}