#include "deps.hpp"

vector<vector<float> > inputFromText(string filename,int rows){
    ifstream file(filename);
    string line;
    float ele;
    vector<vector<float> > mat;
    int c = 0;
    while (getline(file,line,'\n')){
        vector<float> row;
        stringstream ssline(line);
        while (ssline >> ele){
            c++;
            row.push_back((ele));
        }
        mat.push_back(row);
    }
    file.close();
    return mat;
}