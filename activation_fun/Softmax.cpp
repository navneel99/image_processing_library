#include "../softmax.hpp"

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
