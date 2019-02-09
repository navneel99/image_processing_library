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
    file.close();


    if(trans == true){
        vector<vector<float>> res = Trans (mat);
        return res;
    }
    return mat;
}
//vector<vector<vector<float> > > inputFromText3D(string filename,int rows,int depth, int bias){
tuple< vector<vector<vector<vector<float> > > >,vector<float> > inputFromText3D(string filename,int rows,int depth,int filters){
    vector<vector<vector<vector<float> > > >final_result;
    vector<vector<vector<float> > > result;
    ifstream file(filename);
    string line;
    float ele;
    vector<vector<float> > mat;
    bool biasCheck = false;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    vector<float> row;
    while (getline(file,line,'\n')){
        if (biasCheck == false){
            b++;
            c++;
            ele = stof(line); 
            row.push_back(ele);
            if (c%rows == 0){
                mat.push_back(row);
                row.clear();//Next row starts
                d++;
                if (d%rows == 0){
                    result.push_back(mat);
                    mat.clear();
                    e++;
                    if (e%depth == 0){
                        final_result.push_back(result);
                        result.clear();
                        if (b == rows * rows * depth*filters){
                        biasCheck = true;
                        }
                    }
                    
                }
            }
        } else{
            ele = stof(line);
            row.push_back(ele);
        }
    }
    file.close();
    return make_tuple(final_result,row);

}