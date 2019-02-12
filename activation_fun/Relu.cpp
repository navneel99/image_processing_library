#include "relu.hpp"
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
vector<vector<vector<float> > >Relu (vector<vector<vector<float> > > v){
    int row = v.size();
    int col = v[0].size();
    int dep = v[0][0].size();
    for (int i = 0; i < row;i++){
        for(int j = 0; j<col;j++){
            for(int k = 0; k< dep; k++){
                float ele = v[i][j][k];
                if (ele < 0){
                    v[i][j][k] = 0;
                }
            }
        }
    }
} 

