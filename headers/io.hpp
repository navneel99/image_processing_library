#ifndef io_h
#define io_h
#include "common.hpp"
#include "trans.hpp"
vector<vector<float> > inputFromText(string filename, int rows,bool trans);
void Outputtofile(string name, vector<vector<float>> ar);
void Outputtofile(string name, string message);
void Outputtofile(string name, vector<float> ar);
void Outputtofile(string name, vector<vector<vector<float> > >ar);
void dispVector(vector<vector<vector<vector<float> > > > v);
void dispVector(vector<vector<vector<float> > > v);
void dispVector(vector<vector<float> > v);
void dispVector(vector<float>  v);
void Write(int size1, string name1);
void Outputtofile(int iterate, int rows, int columns);
// vector<vector<vector<float> > > inputFromText3D(string filename,int rows,int depth, int bias);
tuple< vector<vector<vector<vector<float> > > >,vector<float> > inputFromText3D(string filename,int rows,int depth,int filters);

#endif
