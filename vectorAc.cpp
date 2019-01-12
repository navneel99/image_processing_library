/*
//#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
*/
#include "deps.hpp"

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