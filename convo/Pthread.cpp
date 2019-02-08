#include "../convolution.hpp"
#include <pthread.h>
#include "../io.hpp"
  
// maximum number of threads 
#define MAX_THREAD 5

vector<vector<float> > matA;
vector<float>  matB;
vector<float>  matC;
int t;
int m;
int step_i = 0; 


void* multi(void* arg) 
{ 
    int core = step_i++;  
    for (int i = core * t/ MAX_THREAD; i < (core + 1) * t / MAX_THREAD; i++) {
            float sum = 0;
            for (int k = 0; k < m; k++){
                sum += matA[i][k] * matB[k];
            }
            matC[i] = sum;
    }            
} 
  

vector<float> Pthread(vector<vector<float> > temp, vector<float> ker)
{ 
    t =temp.size();
    m = ker.size();
    matA = temp;
    matB = ker;
    ::matC.clear();
    for (int k = 0; k<t;k++){
        matC.push_back(0);
    }
    pthread_t threads[MAX_THREAD]; 
  
    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    } 
  
    // joining and waiting for all threads to complete 
    for (int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);     
    }  
//    ::matA.clear();
//    ::matB.clear();
    ::step_i = 0;
    return matC; 
}