//#include<bits/stdc++.h>
//#include <cstdlib>
//#include <cstdio>

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x);
vector<vector<float> > Tanh(vector<vector<float> > v);
vector<vector<float> > Padding(vector<vector<float> > mat, int pad);
vector<vector<float> > Pooling(vector<vector<float> > img, int kernel_size, int pad, string whichone);
vector<float> Softmax(vector<float> v);
vector<float> Sigmoid(vector<float> v);
vector<vector<float> > Relu(vector<vector<float> > v);
float getMax(vector<vector<float> > v);
float getAvg(vector<vector<float> > v);
void dispVector(vector<vector<float> > v);

int main(){
    vector<vector<float>> a,b,c1;
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
    dispVector(a);
    b = Pooling(a,2,0,"max");
    dispVector(b);
    c1 = Pooling(a,2,0,"avg");
    dispVector(c1);
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


void dispVector(vector<vector<float> > v){
    int rows = v.size();
    int cols = v[0].size();
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols;j++){
            cout << v[i][j]<< " ";
        }
        cout << "\n\n";
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

float getMax(vector<vector<float> > v){
    int rows = v.size();
    int cols = v[0].size();
    float currMax;
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols;j++){
            if (i == 0 && j == 0){
                currMax = v[i][j];
            } else{
                if (v[i][j]>currMax){
                    currMax = v[i][j];
                }
            }
        }
    }
    return currMax;
}

float getAvg(vector<vector<float> > v){
    int rows = v.size();
    int cols = v[0].size();
    float currAvg;
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols;j++){
            currAvg = currAvg + v[i][j];
        }
    }
    currAvg = currAvg/(rows * cols);
    return currAvg;
}

vector<vector<float> > Pooling(vector<vector<float> > img, int kernel_size, int pad, string whichone){
    vector<vector<float> > comp_img, padded_img;
    padded_img = Padding(img,pad);
    int padded_img_size = padded_img.size();
    int comp_img_size = floor(padded_img_size/kernel_size);
    for (int i = 0; i<comp_img_size;i++){//=kernel_size){
        vector<float> comp_image_row;
        for (int j = 0; j<comp_img_size;j++){//=kernel_size){
            vector<vector<float> > actual_pool;
            for (int k =0; k<kernel_size;k++){
                vector<float> actual_pool_row;
                for (int l = 0; l<kernel_size;l++){
                    float currEle = padded_img[i*kernel_size+k][j*kernel_size+l];
                    actual_pool_row.push_back(currEle);
                }
                actual_pool.push_back(actual_pool_row);
            }

            float ele;            
            if (whichone == "max"){
                ele = getMax(actual_pool);
                comp_image_row.push_back(ele);
            } else {
                ele = getAvg(actual_pool);
                comp_image_row.push_back(ele);
            }
        }
        comp_img.push_back(comp_image_row);
    }
    return comp_img;

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


