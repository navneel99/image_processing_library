#ifndef io_h
#define io_h
#include "common.hpp"
vector<vector<float> > inputFromText(string filename, int rows, bool = true);
void dispVector(vector<vector<float> > v);
#endif