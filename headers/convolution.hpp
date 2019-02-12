#ifndef convolution_h
#define convolution_h
#include "common.hpp"
#include "padding.hpp"
vector<vector<float> > Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int pad, int stride);
vector<vector<float> > convm(vector<vector<float>> arr, vector<vector<float>> kernel, int x, int stride,string type);
void* matMulFun(void* arg);
void* multi(void* arg);
vector<float> normalMatMul(vector<vector<float> > temp, vector<float> ker);
vector<float> cBlasImpl(vector<vector<float> > temp, vector<float> ker);
vector<float> mklImpl(vector<vector<float> > temp, vector<float> ker);
vector<float>  Pthread(vector<vector<float> > temp, vector<float> ker);
vector<vector<float> > vectorToMatrix(vector<float> v, int t);
//double* createArray(vector<vector<float> >temp);
tuple<double*,int> createArray(vector<vector<float> >temp);
//double* createArray(vector<float> ker);
tuple<double*,int> createArray(vector<float> ker);
//double* cBlasMatMul(double* A, double* B);
tuple<double*,int> cBlasMatMul(tuple<double*,int> At, tuple<double*,int> Bt);
//double* mklMatMul(double* A, double* B);
tuple<double*,int> mklMatMul(tuple<double*,int> At, tuple<double*,int> Bt);

//vector<float> collectResult(double* C);
vector<float> collectResult(tuple<double*,int> Ct);

//vector<vector<vector<vector<float> > > > convolution3D(vector<vector<vector <float> > > matrix, vector<vector<vector<vector<float> > > >filters);
vector<vector<vector<float> > >  convolution3D(vector<vector<vector <float> > > matrix, vector<vector<vector<vector<float> > > >filters);

#endif
