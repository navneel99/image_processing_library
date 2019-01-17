#include "io.hpp"

void Outputtofile(string name, vector<vector<float> > ar){
    ofstream file;
    file.open(name,std::ios_base::app);

    for(int i=0; i<ar.size(); i++){
        for(int j=0; j<ar[0].size(); j++){
            file<<ar[i][j]<<" ";
        }
        file<<"\n";
    }
    file.close();
}
void Outputtofile(string name, string message){
    ofstream file;
    file.open(name,std::ios_base::app);
    file <<message<<'\n';
    file.close();
}
