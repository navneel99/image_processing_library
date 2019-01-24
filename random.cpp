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

float* getTimes(vector<vector<float> > a, vector<float> b){
    float* arr = new float[3];
    arr[0] = getTime("pthreads",a,b);
    arr[1] = getTime("openBlas",a,b);
    arr[2] = getTime("mkl",a,b);

    return arr;
}

int main(int argc, char **argv){
    //cout << RAND_MAX;                   //2147483647    

    srand((int) time(0));
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    int lol = sqrt(columns);
    vector<vector<float> > a = randMatrix(rows,columns);
    vector<float> b = randVector(columns);

    float* timePtr = getTimes(a,b);
    cout<<"Pthreads' Time in micro seconds: "<<timePtr[0]<<endl;;
    cout<<"openBlas' Time in micro seconds: "<<timePtr[1]<<endl;;
    cout<<"MKL's Time in micro seconds: "<<timePtr[2]<<endl;;    
    return 0; 
}

