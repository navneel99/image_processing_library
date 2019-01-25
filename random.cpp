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
        float mean[3] ={0,0,0};
        float* timePtr;
        for(int i = 0; i<150; i++){
            //cout<<i<<"th iteration of getTimes()"<<endl;
            timePtr = getTimes(a,b);
            mean[0]+=timePtr[0];
            mean[1]+=timePtr[1];
            mean[2]+=timePtr[2];
        }
        mean[0]/=150;  //openblas
        mean[1]/=150;  //mkl
        mean[2]/=150;  //pthread
        cout<<"Pthreads' Time in nano seconds: "<<mean[2] <<endl;;
        cout<<"openBlas' Time in nano seconds: "<<mean[0] <<endl;;
        cout<<"MKL's Time in nano seconds: "<<mean[1] <<endl;;
    }    
    return 0; 
}


void Outputtofile(int iterate, int rows, int columns){
    ofstream file1, file2, file3;
    file1.open("graph.dat");

    for(int i=0; i<iterate; i++){
        vector<vector<float> > a = randMatrix(rows+i+1,columns);
        vector<float> b = randVector(columns);

        float mean[3] ={0,0,0};
        //float pthread_time;
        float* timePtr;
        int repeater = 500; 
        float pthread_stddev[repeater];       
        float openblas_stddev[repeater];       
        float mkl_stddev[repeater];       
        for(int i = 0; i<repeater; i++){
            timePtr = getTimes(a,b);
            mean[0]+=timePtr[0];
            openblas_stddev[i] = timePtr[0];
            mean[1]+=timePtr[1];
            mkl_stddev[i] = timePtr[1];
            mean[2]+=timePtr[2];
            pthread_stddev[i] = timePtr[2];
        }
        
        mean[0]/=repeater;  //openBlas
        mean[1]/=repeater;  //mkl
        mean[2]/=repeater;  //Pthreads
        float opbstdDev,mklstdDev,pthrstdDev;
        for(int j =0; j<repeater;j++){
            opbstdDev += pow((openblas_stddev[j]-mean[0]),2);
            mklstdDev += pow((mkl_stddev[j]-mean[1]),2);
            pthrstdDev += pow((pthread_stddev[j]-mean[2]),2);
        }
        opbstdDev=pow((opbstdDev/repeater),0.5);
        mklstdDev=pow((mklstdDev/repeater),0.5);
        pthrstdDev=pow((pthrstdDev/repeater),0.5);
        /*cout<<"Pthreads:"<<'\n'<<"Mean is: "<<mean[2]<<'\n';
        
        for (int k =0;k<repeater;k++){
            cout<< pthread_stddev[k]<<" ";
        }
        
        cout<<"\n";
        cout<<"Standard Deviation is: "<<pthrstdDev<<endl;
        */
        file1<<rows+i+1<<" "<<mean[2]<<" "<<mean[0]<<" "<< mean[1]<<" "<< pthrstdDev << " " << opbstdDev << " " << mklstdDev <<"\n";
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
    steady_clock::time_point start;
    //clock_t time_taken;
    steady_clock::time_point stop;
    if (type == "mkl"){
        start = steady_clock::now();
        //time_taken = clock();
        Ct = mklMatMul(At,Bt);
        //time_taken = clock() - time_taken;
        stop = steady_clock::now();
    } else if(type == "openBlas"){
        //answer = cBlasImpl(a,b);
        start = steady_clock::now(); 
        //time_taken = clock();
        Ct = cBlasMatMul(At,Bt);
        //time_taken = clock() - time_taken;
        stop = steady_clock::now();
    } else {
        start = steady_clock::now();
        //time_taken = clock();
        answer = Pthread(a,b);
        //time_taken = clock() - time_taken;
        stop = steady_clock::now();
    }
    auto duration = duration_cast<microseconds>(stop-start);
    float time = duration.count();
    //float time = ((float)time_taken/CLOCKS_PER_SEC)*(10^9);
    if (type == "openBlas" || type == "mkl"){
    answer = collectResult(Ct);
    }
    return time;
}

float* getTimes(vector<vector<float> > a, vector<float> b){
    float* arr = new float[3];
    arr[0] = getTime("openBlas",a,b);
    arr[1] = getTime("mkl",a,b);
    arr[2] = getTime("pthreads",a,b);
    return arr;
}
