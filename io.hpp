#ifndef io_h
#define io_h
#include "common.hpp"
#include "trans.hpp"
vector<vector<float> > inputFromText(string filename, int rows,bool trans);
void dispVector(vector<vector<float> > v);
#endif