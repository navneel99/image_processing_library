#include "../sigmoid.hpp"

vector<float> Sigmoid(vector<float> v){
    for (int i = 0; i< v.size(); i++){
        float temp = (1/(1 + exp((-1) * v[i]))); 
        v[i] = temp;
    }
    return v;
}