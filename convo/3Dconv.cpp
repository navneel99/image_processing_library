#include "convolution.hpp"
//This function takes a 3D matrix of shape l*l*d and a filter 3D matrix of shape k*k*d*f where f is the number of fitrs to be used to convolve.
//

vector<vector<float> > add(vector<vector<float> > a,vector<vector<float> > b){
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a[0].size(); j++)
        {
            a[i][j] += b[i][j];
        }
        
    }
    return a;
}

vector<vector<vector<float> > >  convolution3D(vector<vector<vector <float> > > matrix, vector<vector<vector<vector<float> > > >filters){
    //kernel is k * k * input_channels * filters
    int mat_depth = matrix.size();  //2
    int mat_height = matrix[0].size(); //2
    int num_filters = filters.size(); //4
    int filter_size = filters[0][0].size();  //2

    vector<vector<vector<float> > > final_answer;
    
    for (int j =0; j < num_filters;j++){
        vector<vector<vector<float> > >curr_filter = filters[j]; //A 3D filter k*k*input_height
        vector<vector<float> > result;
        for (int i = 0;i<mat_depth;i++){
            if (i == 0){
                result = Convolution(matrix[i],curr_filter[i],0,1);
            }else{
                result = add(Convolution(matrix[i],curr_filter[i],0,1),result);
            }
        }
        /*for (int i = 0;i<mat_depth;i++){
            if (i == 0 ){
                result = Convolution(matrix[i],curr_filter,0,1);
            } else {
                result = add(Convolution(matrix[i],curr_filter,0,1),result);
            }
        }*/
        final_answer.push_back(result);
    }
    return final_answer;
}
