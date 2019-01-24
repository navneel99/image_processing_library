#ifndef convolution_h
#define convolution_h
#include "common.hpp"
#include "padding.hpp"
vector<vector<float> > Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x, int stride);
vector<vector<float> > convm(vector<vector<float>> arr, vector<vector<float>> kernel, int x, int stride,string type);
void* matMulFun(void* arg);
vector<float> normalMatMul(vector<vector<float> > temp, vector<float> ker);
vector<float> cBlasImpl(vector<vector<float> > temp, vector<float> ker);
vector<float> mklImpl(vector<vector<float> > temp, vector<float> ker);
vector<float>  Pthread(vector<vector<float> > temp, vector<float> ker);
vector<vector<float> > vectorToMatrix(vector<float> v, int t);
double* createArray(vector<vector<float> >temp);
double* createArray(vector<float> ker);
double* cBlasMatMul(double* A, double* B);
double* mklMatMul(double* A, double* B);
vector<float> collectResult(double* C);

#endif
