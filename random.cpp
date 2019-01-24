#include "common.hpp"
#include <ctime>
#include "convolution.hpp"
#include "io.hpp"


//This file will generate matrix of random numbers and vectors. We will then input it to the 3 variations 
//and note the respective times in a file. We will use GNU Plot next. This file should be independently 
//compiled along with openblas.cpp,mkl.cpp,Pthread.cpp,outfile.cpp

vector<vector<float> > randMatrix(int rows,int columns){
    vector<vector<float> > result(rows,vector<float>(columns));
    for ( int i = 0; i<rows;i++){
        for (int j = 0; j<columns;j++){
            result[i][j] = (rand()%100);
        }
    }
    return result;
}

vector<float> randVector(int rows){
    vector<float> result;
    for ( int i = 0; i<rows;i++){
        //cout<<"Tets";
        result.push_back(rand()%1000);
    }
    //dispVector(result);
    return result;
}

float getTime(string type,vector<vector<float> > a,vector<float> b){
    vector<float> answer;
    auto start = high_resolution_clock::now();
    if (type == "pthreads"){
        answer = Pthread(a,b);
    } else if(type == "openBlas"){
        answer = cBlasImpl(a,b);
    } else{
        answer = mklImpl(a,b);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    float time = duration.count();
    return time;
}

int main(int argc, char **argv){
    //cout << RAND_MAX;                   //2147483647    
    srand((int) time(0));
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    int lol = sqrt(columns);
    vector<vector<float> > a = randMatrix(rows,columns);
    vector<float> b = randVector(columns);

    float p_time = getTime("pthreads",a,b);
    float o_time = getTime("openBlas",a,b);
    float m_time = getTime("mkl",a,b);

    cout<<"Pthreads' Time in micro seconds: "<<p_time<<endl;;
    cout<<"openBlas' Time in micro seconds: "<<o_time<<endl;;
    cout<<"MKL's Time in micro seconds: "<<m_time<<endl;;    
    return 0; 
}

