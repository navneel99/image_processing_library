//#include<bits/stdc++.h>
//#include <cstdlib>
//#include <cstdio>

#include <iostream>
#include <vector>
using namespace std;


void Convolution(){

} 

//float* Relu(float arr[][]){


void Tanh(){

}

void MaxPooling(){

}

void Softmax(){

}

void Sigmoid(){
    
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

int main(){
    /*vector<vector<float>> a;
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
    }*/
return 0;
}

