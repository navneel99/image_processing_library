#ifndef convolution_h
#define convolution_h
#include "common.hpp"
#include "padding.hpp"
vector<vector<float> > Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x, int stride);
vector<vector<float> > convm(vector<vector<float>> arr, vector<vector<float>> kernel, int x, int stride,string type);
void* matMulFun(void* arg);
vector<vector<float> > normalMatMul(vector<vector<float> > temp, vector<float> ker,int n,int m,int t,int stride);
vector<vector<float> >cBlasImpl(vector<vector<float> > temp, vector<float> ker,int m,int t);
vector<vector<float> >mklImpl(vector<vector<float> > temp, vector<float> ker,int m,int t);
vector<vector<float> > Pthread(vector<vector<float> > temp, vector<float> ker, int m, int t);
#endif
