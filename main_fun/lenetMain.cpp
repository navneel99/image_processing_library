#include "common.hpp"
#include "convolution.hpp"
#include "io.hpp"
#include "pooling.hpp"

void LenetArch(string image, string ker_l1, string ker_l2, string ker_l3, string ker_l4);

int main(int argc, char **argv){
    string ch1 = argv[1];
    string ch2 = argv[2];
    string ch3 = argv[3];
    string ch4 = argv[4];
    string ch5 = argv[5];
    //tuple < vector<vector<vector<vector<float> > > >, vector<float> > A = inputFromText3D(ch, ch2,ch3,ch4);
    /*vector<vector<vector<float> > > ker1  { { {1,1},{1,1} },{ {1,1},{1,1} },{ {1,1},{1,1} },{ {1,1},{1,1} } };
    vector<vector<vector<float> > >test1  { { {1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{ {1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{{1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{{1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} } };
    vector<vector<vector<float> > >ans = Pool3D(test1,2,0,"max");
    for (int j =0; j < ans.size();j++){
        dispVector(ans[j]);
    }*/

    LenetArch(ch1, ch2, ch3, ch4, ch5);

    return 0;
}