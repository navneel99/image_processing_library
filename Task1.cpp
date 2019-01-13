#include "deps.hpp"


int main(int argc, char **argv){
    vector<vector<float> > a = inputFromText("exampleMat.txt", 3);
    dispVector(a);
return 0;
}