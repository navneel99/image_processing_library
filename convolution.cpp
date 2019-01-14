#include "deps.hpp"

vector<vector<float> > Convolution(vector<vector<float>>arrr, vector<vector<float>>kernel, int pad){

// calling the padding the function 
    vector<vector<float>> arr = Padding(arrr, pad);

    int n=arr.size();
    int m=kernel.size();

//Defining the output vector O with predefined size
    vector<vector<float> > O(n-m+1);
    int tsize=n-m+1;
    int count =-1; 
    int counter=tsize;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

//Checking the constraints for input
            if(i+m<=n && j+m<=n){
              if(counter==tsize){
               counter=0; 
               count+=1;
               O[count]=vector<float>(tsize);
             }

//Calculating the elementwise multiplication             
            float term =0;
              for(int ii=0; ii<m; ii++){
                for(int jj=0; jj<m; jj++){
                        term = term + arr[i+ii][j+jj]*kernel[ii][jj];
                }
            }
            O[count][counter]=term;
            counter+=1;
            }else{
              break;
            }
        }
    }

//returning the output vector    
    return O;
}