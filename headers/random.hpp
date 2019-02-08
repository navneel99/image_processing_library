#ifndef random_h
#define random_h
#include "common.hpp"
#include <ctime>
#include "convolution.hpp"
#include "io.hpp"
#include <string>

void Outputtofile(string type,int iterate, int rows, int columns);
vector<vector<float> > randMatrix(int rows,int columns);
vector<float> randVector(int rows);
//float getTime(string type,vector<vector<float> > a,vector<float> b);

#endif