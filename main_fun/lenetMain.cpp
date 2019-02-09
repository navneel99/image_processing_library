#include "common.hpp"
#include "convolution.hpp"
#include "io.hpp"
#include "pooling.hpp"

int main(int argc, char **argv){
    string ch = argv[1];
    int ch2 = stoi(argv[2]);
    vector<vector<float> > chr = inputFromText(ch, ch2,true);
    vector<vector<vector<float> > > ker1  { { {1,1},{1,1} },{ {1,1},{1,1} },{ {1,1},{1,1} },{ {1,1},{1,1} } };
    vector<vector<vector<float> > >test1  { { {1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{ {1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{{1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{{1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} } };
    vector<vector<vector<float> > >ans = Pool3D(test1,2,0,"max");
    for (int j =0; j < ans.size();j++){
        dispVector(ans[j]);
    }
    return 0;
}