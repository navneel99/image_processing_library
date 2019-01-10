//#include<bits/stdc++.h>
//#include <cstdlib>
//#include <cstdio>

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x);
int main(){
    /*
    vector<vector<float>> a,b;
    int r,c;
    cout << "Enter number of Rows and Columns: ";
    cin >> r >> c;
    for(int i = 0; i<r; i++){
        vector<float> ele;
        for (int j = 0; j<c;j++){
            float f;
            cout << "Row "<<i<<", Column "<<j<<" :";
            cin >> f;
            ele.push_back(f);
        }
        a.push_back(ele);
    }
    b = Tanh(a);
    
    vector<float> a = {1,2,3,4};
    a = Sigmoid(a);
    */
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



vector<vector<float> > Tanh(vector<vector<float> > v){
    vector<float> row;
    float ele;
    for (int it = 0; it < v.size(); it++){
        row = v.at(it);
        for (int it2 = 0;it2 < row.size(); it2++){
            ele = row.at(it2);
            row[it2] = tanh(ele);
        }
        v[it] = row;
    }
    return v;

}

void MaxPooling(){

}

vector<float> Softmax(vector<float> v){
    vector<float> v2;
    float pden = 0.0;
    for(int i = 0; i < v.size();i++){
        float temp; 
        temp = exp(v.at(i));
        pden+=temp;
        v2.push_back(temp);
    }
    for (int i = 0; i < v2.size();i++){
        v2[i] = v2[i]/pden;
    }
    return v2;
}

vector<float> Sigmoid(vector<float> v){
    for (int i = 0; i< v.size(); i++){
        float temp = (1/(1 + exp((-1) * v[i]))); 
        v[i] = temp;
    }
    //cout << v[0]<<" "<<v[1]<<endl;
    return v;
}

vector<vector<float> > Relu(vector<vector<float> > v){
    vector<float> row;
    float ele;
    for (int it = 0; it < v.size(); it++){
        row = v.at(it);
        for (int it2 = 0;it2 < row.size(); it2++){
            ele = row.at(it2);
            if (ele < 0){
                row[it2] = 0;
            }
        }
        v[it] = row;
    }
    return v;
} 

