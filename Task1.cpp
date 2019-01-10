#include<bits/stdc++.h>

using namespace std;

void Convolution(vector<vector<int>>arr, vector<vector<int>>kernel, int x);
int main(){
  
  return 0;
}

void Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x){
  
  int ArrSize = arr.size();     //No. of rows

  int KernelSize = kernel.size(); //No. of rows
  
  int mid = (KernelSize + 1)/2;  //Finding the mid element of the kernel

  //Range of the mid to move 
  int x1 = (KernelSize-1)/2;
  int x2 = ArrSize - (KernelSize+1)/2;

  for(int i=x1; i<x2; i++){
    for(int j=x1; j<x2; j++){
      float term = 0;
      for(int m=i-x1; m<i+x1){
       
      }
    }
  }

} 

void Relu(){

} 

void Tanh(){

}

void MaxPooling(){

}

void Softmax(){

}

void Sigmoid(){
    
}