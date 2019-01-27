#include "random.hpp"



float getPthreadTime(vector<vector<float> > a,vector<float> b){
    vector<float> answer;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;    
    start = high_resolution_clock::now();
    answer = Pthread(a,b);
    stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    float time = duration.count();
    time = time *(0.000001);
    return time;
}


void OutputtofileP(int iterate, int rows, int columns){
    ofstream file1;
    file1.open("pthread.dat",ios_base::app);
    for(int i=0; i<iterate; i++){
        vector<vector<float> > a = randMatrix(rows+i+1,columns);
        vector<float> b = randVector(columns);
        int repeater = 200; 
  
        float timeB,mean;  
        float stdDev = 0;
        for(int i = 0; i<repeater; i++){
            timeB = getPthreadTime(a,b);
            if (timeB<0){
                cout<<"NegTime!"<<endl;
            }
            mean+=timeB;
            stdDev += pow(timeB,2);
        }
        stdDev/=repeater;
        mean/=repeater;  //openBlas
        stdDev-=pow(mean,2);
        stdDev=pow(abs(stdDev/repeater),0.5);
        file1<<rows+i+1<<" "<<mean<<" "<<stdDev<<"\n";
    }

    file1.close();
}



int main(int argc, char **argv){
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    int iterate = stoi(argv[3]);
    srand((int) time(0));
    if(iterate != 0){
        OutputtofileP(iterate, rows, columns);
    }else{
        vector<vector<float> > a = randMatrix(rows,columns);
        vector<float> b = randVector(columns);
        float timeB,mean;
        for(int i = 0; i<150; i++){
            timeB = getPthreadTime(a,b);
            mean+=timeB;
        }
        mean/=150; 
        cout<<"pthreads' Time in seconds: "<<mean<<endl;;
    }    
    return 0; 


}