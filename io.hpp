#ifndef io_h
#define io_h
#include "common.hpp"
#include "trans.hpp"
vector<vector<float> > inputFromText(string filename, int rows,bool trans);
void Outputtofile(string name, vector<vector<float>> ar);
void Outputtofile(string name, string message);
void dispVector(vector<vector<float> > v);
void dispVector(vector<float>  v);
void Write(int size1, string name1);
#endif
