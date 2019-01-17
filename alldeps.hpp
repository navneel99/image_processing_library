#ifndef __ALL_DEPS__
#define __ALL_DEPS__
/*
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Outputtofile(string s, vector<vector<float>> temp);
vector<vector<float> > Convolution(vector<vector<float>>arr, vector<vector<float>>kernel, int x);
vector<vector<float> > Tanh(vector<vector<float> > v);
vector<vector<float> > Padding(vector<vector<float> > mat, int pad);
vector<vector<float> > Pooling(vector<vector<float> > img, int kernel_size, int pad, string whichone);
vector<float> Softmax(vector<float> v);
vector<float> Sigmoid(vector<float> v);
vector<vector<float> > Relu(vector<vector<float> > v);
float getMax(vector<vector<float> > v);
float getAvg(vector<vector<float> > v);
void dispVector(vector<vector<float> > v);
vector<vector<float> > inputFromText(string filename, int rows);
*/
#include "common.hpp"
#include "convolution.hpp"
#include "pooling.hpp"
#include "relu.hpp"
#include "sigmoid.hpp"
#include "softmax.hpp"
#include "tanh.hpp"
#include "io.hpp"
#endif