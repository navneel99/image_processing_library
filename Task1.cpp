#include "deps.hpp"
int main(int argc, char **argv){
    /*ifstream file;
    string line;
    stringstream ssline;
    float ele;*/
    /*vector<vector<float>> a,b,c1,c2;
    int r,c;
    cout << "Enter number of Rows and Columns: ";
    cin >> r >> c;
    for(int i = 0; i<r; i++){
        vector<float> ele;
        for (int j = 0; j<c;j++){
            float f;
            cout << "Row "<<i<<", Column "<<j<<" :";
            cin >> f;
            ele.push_back(f);
        }
        a.push_back(ele);
    }

    dispVector(a);
    b = Pooling(a,2,0,"max");
    dispVector(b);
    c1 = Pooling(a,2,0,"avg");
    dispVector(c1);*/
    /*file.open(argv[1]);
    vector<vector<float> > mat;
    while (getline(file,line)){
        vector<float> row;
        ssline << line;
        while (ssline >> ele){
            row.push_back(ele);
        }
        mat.push_back(row);
    }
    file.close();*/
    vector<vector<float> > a = inputFromText("exampleMat.txt", 3);
    dispVector(a);
    //cout << argv[1];
return 0;
}