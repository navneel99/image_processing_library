#ifndef convolution_h
#define convolution_h
#include "common.hpp"
#include "padding.hpp"
vector<vector<float> > Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x, int stride);
vector<vector<float> > convm(vector<vector<float>> arr, vector<vector<float>> kernel, int x, int stride);
#endif