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


int main(int argc, char **argv){
    //cout << RAND_MAX;                   //2147483647    
    srand((int) time(0));
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    int lol = sqrt(columns);
    vector<vector<float> > a = randMatrix(rows,columns);
    vector<float> b = randVector(columns);


    cout<<"Pthreads' Time in micro seconds: ";;
    auto start = high_resolution_clock::now();
    vector<float> answer = Pthread(a,b);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << duration.count()<<endl;

    cout<<"openBlas' Time in micro seconds: ";;
    start = high_resolution_clock::now();
    answer = cBlasImpl(a,b);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << duration.count()<<endl;

    cout<<"MKL's Time in micro seconds: ";;
    start = high_resolution_clock::now();
    answer = mklImpl(a,b);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << duration.count()<<endl;
    



    return 0; 
}

