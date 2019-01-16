#include "deps.hpp"

vector<vector<float> > inputFromText(string filename,int rows, bool trans = true){

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


    if(trans == true){
        vector<vector<float>> res = Trans (mat);
        return res;
    }


    return mat;
}