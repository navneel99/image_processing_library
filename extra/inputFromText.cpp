#include "io.hpp"
#include "trans.hpp"

vector<vector<float> > inputFromText(string filename,int rows, bool trans){

    ifstream file(filename);
    string line;
    float ele;
    vector<vector<float> > mat;
    int c = 0;
    vector<float> row;
    while (getline(file,line,'\n')){
        /*
        stringstream ssline(line);
        while (ssline >> ele){
            c++;
            row.push_back((ele));
        }*/
        c++;
        ele = stof(line); 
        row.push_back(ele);
        if (c%rows == 0){
            mat.push_back(row);
            row.clear();
        }
        
    }
    //cout<< mat.size();
    //dispVector(mat);
    file.close();


    if(trans == true){
        vector<vector<float>> res = Trans (mat);
        return res;
    }
    return mat;
}