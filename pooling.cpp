#include "pooling.hpp"
#include "padding.hpp"
float getMax(vector<vector<float> > v){
    int rows = v.size();
    int cols = v[0].size();
    float currMax;
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols;j++){
            if (i == 0 && j == 0){
                currMax = v[i][j];
            } else{
                if (v[i][j]>currMax){
                    currMax = v[i][j];
                }
            }
        }
    }
    return currMax;
}

float getAvg(vector<vector<float> > v){
    int rows = v.size();
    int cols = v[0].size();
    float currAvg = 0;
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols;j++){
            currAvg = currAvg + v[i][j];
        }
    }
    currAvg = currAvg/(rows * cols);
    return currAvg;
}

vector<vector<float> > Pooling(vector<vector<float> > img, int kernel_size, int pad, string whichone){
    vector<vector<float> > comp_img, padded_img;
    padded_img = Padding(img,pad);
    int padded_img_size = padded_img.size();
    int comp_img_size = floor(padded_img_size/kernel_size);
    for (int i = 0; i<comp_img_size;i++){//=kernel_size){
        vector<float> comp_image_row;
        for (int j = 0; j<comp_img_size;j++){//=kernel_size){
            vector<vector<float> > actual_pool;
            for (int k =0; k<kernel_size;k++){
                vector<float> actual_pool_row;
                for (int l = 0; l<kernel_size;l++){
                    float currEle = padded_img[i*kernel_size+k][j*kernel_size+l];
                    actual_pool_row.push_back(currEle);
                }
                actual_pool.push_back(actual_pool_row);
            }

            float ele;            
            if (whichone == "max"){
                ele = getMax(actual_pool);
                comp_image_row.push_back(ele);
            } else {
                ele = getAvg(actual_pool);
                comp_image_row.push_back(ele);
            }
        }
        comp_img.push_back(comp_image_row);
    }
    return comp_img;

}