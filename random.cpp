#include "common.hpp"
#include <ctime>
#include "convolution.hpp"
#include "io.hpp"

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

        float* timePtr = getTimes(a,b);
        cout<<"Pthreads' Time in micro seconds: "<<timePtr[0]<<endl;;
        cout<<"openBlas' Time in micro seconds: "<<timePtr[1]<<endl;;
        cout<<"MKL's Time in micro seconds: "<<timePtr[2]<<endl;;
    }    
    return 0; 
}



void Outputtofile(int iterate, int rows, int columns){

    ofstream file1, file2, file3;
    file1.open("graph1pthread.dat");
    file2.open("graph2openblas.dat");
    file3.open("graph3mkl.dat");

    for(int i=0; i<iterate; i++){

        vector<vector<float> > a = randMatrix(rows,columns);
        vector<float> b = randVector(columns);

        float* timePtr = getTimes(a,b);

        file1<<i<<" "<<timePtr[0]<<"\n";
        file2<<i<<" "<<timePtr[1]<<"\n";
        file3<<i<<" "<<timePtr[2]<<"\n";
    }

    file1.close();
    file2.close();
    file3.close();
}

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
    double *A, *B, *C;
    if (type == "openBlas" || type == "mkl"){
        A = createArray(a);
        B = createArray(b);
    }
    auto start = high_resolution_clock::now();
    if (type == "pthreads"){
        answer = Pthread(a,b);
    } else if(type == "openBlas"){
        //answer = cBlasImpl(a,b);
        C = cBlasMatMul(A,B);
    } else if (type == "mkl"){
        C = mklMatMul(A,B);
    } else {
        answer = normalMatMul(a,b);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    float time = duration.count();
    if (type == "openBlas" || type == "mkl"){
    answer = collectResult(C);
    }
    return time;
}

float* getTimes(vector<vector<float> > a, vector<float> b){
    float* arr = new float[3];
    arr[0] = getTime("pthreads",a,b);
    arr[1] = getTime("openBlas",a,b);
    arr[2] = getTime("mkl",a,b);

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

