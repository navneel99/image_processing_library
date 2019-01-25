#include "common.hpp"
#include <ctime>
#include "convolution.hpp"
#include "io.hpp"
#include <string>

void Outputtofile(int iterate, int rows, int columns);
vector<vector<float> > randMatrix(int rows,int columns);
vector<float> randVector(int rows);
float getTime(string type,vector<vector<float> > a,vector<float> b);
float* getTimes(vector<vector<float> > a, vector<float> b);


int main(int argc, char **argv){
    //cout << RAND_MAX;                   //2147483647    
    srand((int) time(0));
    //coloumns = rows*columns of input kernel size
    //rows = number of interations
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    int iterate = stoi(argv[3]);
    if(iterate != 0){
        Outputtofile(iterate, rows, columns);
    }else{
        vector<vector<float> > a = randMatrix(rows,columns);
        vector<float> b = randVector(columns);
        //float* timePtr = getTimes(a,b);
        float mean[3] ={0,0};
        float* timePtr;
        for(int i = 0; i<150; i++){
            //cout<<i<<"th iteration of getTimes()"<<endl;
            timePtr = getTimes(a,b);
            mean[0]+=timePtr[0];
            mean[1]+=timePtr[1];
        }
        //cout<<mean[0];
        float pthread_time = getTime("pthread",a,b); 
        mean[0]/=150;mean[1]/=150;
        cout<<"Pthreads' Time in micro seconds: "<<pthread_time<<endl;;
        cout<<"openBlas' Time in micro seconds: "<<mean[0]<<endl;;
        cout<<"MKL's Time in micro seconds: "<<mean[1]<<endl;;
    }    
    return 0; 
}


void Outputtofile(int iterate, int rows, int columns){
    ofstream file1, file2, file3;
    file1.open("graph.dat");

    for(int i=0; i<iterate; i++){
        vector<vector<float> > a = randMatrix(rows+i,columns);
        vector<float> b = randVector(columns);

        float mean[2] ={0,0};
        float pthread_time;
        float* timePtr;
        
        for(int i = 0; i<75; i++){
            timePtr = getTimes(a,b);
            mean[0]+=timePtr[0];mean[1]+=timePtr[1];
        }
        
        //pthread_time = getTime("pthread",a,b);
        
        mean[0]/=75;
        mean[1]/=75;
        
        file1<<i<<" "<<pthread_time<<" "<<mean[0]<<" "<< mean[1]<<"\n";
    }

    file1.close();
}

//This file will generate matrix of random numbers and vectors. We will then input it to the 3 variations 
//and note the respective times in a file. We will use GNU Plot next. This file should be independently 
//compiled along with openblas.cpp,mkl.cpp,Pthread.cpp,outfile.cpp

vector<vector<float> > randMatrix(int rows,int columns){
    vector<vector<float> > result(rows,vector<float>(columns));
    for ( int i = 0; i<rows;i++){
        for (int j = 0; j<columns;j++){
            result[i][j] = ((rand()%200)-100);
        }
    }
    return result;
}

vector<float> randVector(int rows){
    vector<float> result;
    for ( int i = 0; i<rows;i++){
        //cout<<"Tets";
        result.push_back((rand()%200)-100);
    }
    //dispVector(result);
    return result;
}

float getTime(string type,vector<vector<float> > a,vector<float> b){
    vector<float> answer;
    //double *A, *B, *C;
    //int len_a,len_b,len_c;
    tuple<double*,int> At,Bt,Ct;
    if (type == "openBlas" || type == "mkl"){
        At = createArray(a);
        Bt = createArray(b);
    }
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;
    if (type == "mkl"){
        start = high_resolution_clock::now();
        Ct = mklMatMul(At,Bt);
        stop = high_resolution_clock::now();
    } else if(type == "openBlas"){
        //answer = cBlasImpl(a,b);
        start = high_resolution_clock::now();        
        Ct = cBlasMatMul(At,Bt);
        stop = high_resolution_clock::now();
    } else {
        start = high_resolution_clock::now();
        answer = Pthread(a,b);
        stop = high_resolution_clock::now();
    }
    auto duration = duration_cast<microseconds>(stop-start);
    float time = duration.count();
    if (type == "openBlas" || type == "mkl"){
    answer = collectResult(Ct);
    if (type == "openBlas"){
        //dispVector(answer);
        Outputtofile("pthreadtest.txt",answer);
    }
    }
    return time;
}

float* getTimes(vector<vector<float> > a, vector<float> b){
    float* arr = new float[2];
    arr[0] = getTime("openBlas",a,b);
    arr[1] = getTime("mkl",a,b);
    return arr;
}

/*int main(int argc, char **argv){
    //cout << RAND_MAX;                   //2147483647    

    srand((int) time(0));
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    int lol = sqrt(columns);
    vector<vector<float> > a = randMatrix(rows,columns);
    vector<float> b = randVector(columns);

    float* timePtr = getTimes(a,b);
    float n_time = getTime("normal",a,b);
    cout<<"Normal's time in micro seconds: "<<n_time<<endl;
    cout<<"Pthreads' Time in micro seconds: "<<timePtr[0]<<endl;
    cout<<"openBlas' Time in micro seconds: "<<timePtr[1]<<endl;
    cout<<"MKL's Time in micro seconds: "<<timePtr[2]<<endl; 
    return 0; 
}*/

