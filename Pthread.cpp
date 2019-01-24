#include "convolution.hpp"
#include <pthread.h>

  
// maximum number of threads 
#define MAX_THREAD 5
  
vector<vector<float> > matA;
vector<float>  matB;
vector<float>  matC;
int t;
int m;

//int matA[MAX][MAX]; 
//int matB[MAX][MAX]; 
//int matC[MAX][MAX]; 
int step_i = 0; 
  
void* multi(void* arg) 
{ 
    int core = step_i++; 
    // Each thread computes 1/4th of matrix multiplication 
    for (int i = core * t/ MAX_THREAD; i < (core + 1) * t / MAX_THREAD; i++) {
        //for (int j = 0; j < t; j++)  {
            float sum = 0;
            for (int k = 0; k < m; k++){
                sum += matA[i][k] * matB[k];
            }
            matC[i] = sum;
        //}
    }            
} 
  
// Driver Code 
//int main()
vector<float> Pthread(vector<vector<float> > temp, vector<float> ker)
{ 
    // Generating random values in matA and matB 
    t =temp.size();
    m = ker.size();
    matA = temp;
    matB = ker;
    matC.reserve(t);
    
    // declaring four threads 
    pthread_t threads[MAX_THREAD]; 
  
    // Creating four threads, each evaluating its own part 
    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, multi, (void*)(p)); 
    } 
  
    // joining and waiting for all threads to complete 
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);     
  
    // Displaying the result matrix 
    /*cout << endl 
         << "Multiplication of A and B" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matC[i][j] << " ";         
        cout << endl; 
    } */
    return matC; 
}