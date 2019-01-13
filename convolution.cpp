#include "deps.hpp"

void Convolution(vector<vector<float> >arrr, vector<vector<float> >kernel, int pad){

    vector<vector<float>> arr = Padding(arrr, pad);

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
