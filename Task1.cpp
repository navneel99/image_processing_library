//#include<bits/stdc++.h>
//#include <cstdlib>
//#include <cstdio>

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x);
vector<vector<float> > Tanh(vector<vector<float> > v);
vector<vector<float> > Padding(vector<vector<float> > mat, int pad);
vector<vector<float> > MaxPooling(vector<vector<float> > img, vector<vector<float> > ker, int pad);
vector<float> Softmax(vector<float> v);
vector<float> Sigmoid(vector<float> v);
vector<vector<float> > Relu(vector<vector<float> > v);

int main(){
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
    /*
    b = Padding(a,2);
    cout << b.size()<<endl;
    cout << b[0].size()<<endl;


    b = Tanh(a);
    
    vector<float> a = {1,2,3,4};
    a = Softmax(a);
    */
return 0;
}

void Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x){
    int n=arr.size();
  int m=kernel.size();

  int tsize=n-m+1;
  float O[tsize][tsize];

  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         float term =0;
          for(int ii=0; ii<m; ii++){
              for(int jj=0; jj<m; jj++){
                if(i+m<=n && j+m<=n){
                      term = term + arr[i+ii][j+jj]*kernel[ii][jj];
                }else{
                  break;
                }
              }
          }
              if((i+(m-3)/2)<tsize && (j+(m-3)/2)<tsize){
              O[i+(m-3)/2][j+(m-3)/2] = term;
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

vector<vector<float> > Padding(vector<vector<float> > mat, int pad){
    for (int j = 0;j<mat.size();j++){
        vector<float> row = mat.at(j);
        for (int i = 0; i<pad;i++){
            row.push_back(0);
            row.emplace(row.begin(),0);
        }
        mat[j] = row;
    }
    int new_row_length = mat.size() + 2 * pad;
    vector<float> zero_row(new_row_length);
    for (int i = 0;i<pad;i++){
        mat.push_back(zero_row);
        mat.emplace(mat.begin(),zero_row);
    }
    return mat;
}

vector<vector<float> > MaxPooling(vector<vector<float> > img, vector<vector<float> > ker, int pad){


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


