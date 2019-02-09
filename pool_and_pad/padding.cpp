#include "padding.hpp"
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