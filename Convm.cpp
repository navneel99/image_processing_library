/*#include <iostream>
#include <vector>
using namespace std;
*/
#include "deps.hpp"

vector<vector<float>> convm(vector<vector<float>> arrr, vector<vector<float>> kernel, int x){

//for padding    
    vector<vector<float>> arr = padding(arrr, pad);

    int n=arr.size();
    int m=kernel.size();
    int t=(n-m+1)*(n-m+1);

    int k=0;
    float temp[t][m*m];
    float ker[m*m];
    //making an temp kernel so that we can use it for multiplication
    for(int i=0; i<m; i++){
      for(int j=0; j<m; j++){
        ker[k]=kernel[i][j];
        k+=1;
      }
    }
    k=0;

//Making the matrix from the input matrix and kernel 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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
vector<vector<float>> O(n-m+1);
int counter=n-m+1;
int count=-1;

for(int p=0; p<t; p++){
  int res=0;
  if(counter==n-m+1){
    counter=0;
    count+=1;
    O[count]=vector<float>(n-m+1);
  }
  for(int q=0; q<m*m; q++){
    res=res+temp[p][q]*ker[q];
  }
  O[count][counter]=res;
  counter+=1;
}

//returning the vector 
return O;
}