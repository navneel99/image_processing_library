#include "io.hpp"

void dispVector(vector<vector<float> > v){
    int rows = v.size();
    int cols = v[0].size();
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols;j++){
            cout << v[i][j]<< " ";
        }
        cout << "\n\n";
    }
}
void dispVector(vector<float>  v){
    int rows = v.size();
    for (int i = 0; i<rows;i++){
            cout << v[i]<< " ";
    }
    cout<<"\n\n";
}

void dispVector(vector<vector<vector<vector<float> > > > v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            for(int k=0; k<v[0][0].size(); k++){
                for(int m=0; m<v[0][0][0].size(); m++){
                    cout<<v[i][j][k][m]<<" ";
                }
                cout<<endl;;
            }
            cout<<"-----------------------"<<endl;
        }
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    }
}

void dispVector(vector<vector<vector<float> > > v){
        for(int j=0; j<v.size(); j++){
            for(int k=0; k<v[0].size(); k++){
                for(int m=0; m<v[0][0].size(); m++){
                    cout<<v[j][k][m]<<" ";
                }
                cout<<endl;;
            }
            cout<<"-----------------------"<<endl;
        }
}