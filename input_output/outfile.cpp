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

void Outputtofile(string name, int a, int b){
    ofstream file;
    file.open(name,std::ios_base::app);
    file<<a<<" "<<b<<"\n";
    file.close();
}


void Outputtofile(string name, string message){
    ofstream file;
    file.open(name,std::ios_base::app);
    file <<message<<'\n';
    file.close();
}
void Outputtofile(string name, vector<float> ar,bool append){
    ofstream file;
    if (append == true){
    file.open(name,std::ios_base::app);
    } else{
    file.open(name);
    }
    for(int i=0; i<ar.size(); i++){
        file<<ar[i]<<" ";
        file<<"\n";
    }
    file.close();
}
void Outputtofile(string name, vector<vector<vector<float> > >ar){
    ofstream file;
    file.open(name);

    for(int i=0; i<ar.size(); i++){
        file<<"---------------------\n"<<"Depth = "<<i<<endl;
        for(int j=0; j<ar[0].size(); j++){
            for(int k=0;k<ar[0][0].size();k++){
                file<<ar[i][j][k]<<" ";
            }
        file<<"\n";            
        }
    }
    file.close();
}