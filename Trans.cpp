#include "deps.hpp"

//function to transpose the given matrix
vector<vector<float>> Trans(vector<vector<float>> arr){
    int n=arr.size();

    vector<vector<float>> temp(n);
    for(int i=0; i<n; i++){
        temp[i] = vector<float>(n);
        for(int j=0; j<n; j++){
            temp[i][j] = arr[j][i];
        }
    }

//returning the transposed matrix
    return temp;
}