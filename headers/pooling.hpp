#ifndef pooling_h
#define pooling_h
#include "common.hpp"
vector<vector<float> > Pooling(vector<vector<float> > img, int kernel_size, int pad, string whichone);
vector<vector<vector<float> > > Pool3D(vector<vector<vector<float> > > input, int kernel_size, int pad, string whichone);
#endif
