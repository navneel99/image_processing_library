#include "random.hpp"

double getmklTimeM(vector<vector<float> > a,vector<float> b){
    vector<float> answer;
    tuple<double*,int> At,Bt,Ct;
    At = createArray(a);
    Bt = createArray(b);
    clock_t time_req;
    time_req =clock();
    Ct = mklMatMul(At,Bt);
    answer = collectResult(Ct);
    time_req = clock()-time_req;
    double ctime = (double)time_req/CLOCKS_PER_SEC;
    return ctime;
}

void OutputtofileM(int iterate, int rows, int columns){
    ofstream file1;
    file1.open("dat_files/mkl.dat",ios_base::app);
    for(int i=0; i<iterate; i++){
        vector<vector<float> > a = randMatrix(rows+i+1,columns);
        vector<float> b = randVector(columns);
        int repeater = 200;  
        double timeB,mean;  
        double stdDev = 0;
        for(int i = 0; i<repeater; i++){
            timeB = getmklTimeM(a,b);
            timeB *= 1000000;
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
        OutputtofileM(iterate, rows, columns);
    }else{
        vector<vector<float> > a = randMatrix(rows,columns);
        vector<float> b = randVector(columns);
        float timeB,mean;

        for(int i = 0; i<150; i++){
            timeB = getmklTimeM(a,b);
            timeB *= 1000000;
            mean+=timeB;
        }
        mean/=150; 
        cout<<"mkl's Time in microseconds: "<<mean<<endl;;
    }    
    return 0; 


}