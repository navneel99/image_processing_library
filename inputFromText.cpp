#include "deps.hpp"
vector<vector<float> > inputFromText(string filename,int rows){
    ifstream file(filename);
    string line;
    //stringstream ssline;
    float ele;
    //string ele;
    //file.open(filename);
    vector<vector<float> > mat;
    int c =0;
    while (getline(file,line,' ')){
        vector<float> row;
        stringstream ssline(line);
        if (ssline >> ele){
            row.push_back((ele));
        }
        if (c ==rows){
            row.push_back('\n');
            mat.push_back(row);
        }
        
    }
    file.close();
    return mat;
}