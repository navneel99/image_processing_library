#include "common.hpp"
#include "convolution.hpp"
#include "io.hpp"
#include "pooling.hpp"

int main(int argc, char **argv){
    string ch = argv[1];
    int ch2 = stoi(argv[2]);
    int ch3 = stoi(argv[3]);
    int ch4 = stoi(argv[4]);
    tuple < vector<vector<vector<vector<float> > > >, vector<float> > A = inputFromText3D(ch, ch2,ch3,ch4);
    /*vector<vector<vector<float> > > ker1  { { {1,1},{1,1} },{ {1,1},{1,1} },{ {1,1},{1,1} },{ {1,1},{1,1} } };
    vector<vector<vector<float> > >test1  { { {1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{ {1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{{1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} },{{1,0,1,0},{1,0,1,0},{1,0,1,0},{1,0,1,0} } };
    vector<vector<vector<float> > >ans = Pool3D(test1,2,0,"max");
    for (int j =0; j < ans.size();j++){
        dispVector(ans[j]);
    }*/

    for (int i = 0;i<ch4;i++){
        cout<<"Filter = "<<i+1<<endl;
        for(int j = 0; j<ch3;j++){
            cout<<"depth = "<<j<<endl;
            dispVector(get<0>(A)[i][j]);
        }
    }
    cout<<"Bias: "<<endl;
    dispVector(get<1>(A));
    return 0;
}