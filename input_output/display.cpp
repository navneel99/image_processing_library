#include "io.hpp"

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
void dispVector(vector<float>  v){
    int rows = v.size();
    for (int i = 0; i<rows;i++){
            cout << v[i]<< " ";
    }
    cout<<"\n\n";
}