#include "convolution.hpp"
#include <pthread.h>

struct data
{
  int row;
  int column;
  vector<vector<float> > Matrix;
  vector<float> kernel;
  vector<float> result;
  int m;
};



//bigmatrix is of dimension (((n-m)/stride)+1)*(((n-m)/stride)+1) x (m*m) := temp
// unrolled kernel of size m*mx1 := ker

void* matMulFun(void* arg){
  data* curr;
  curr = (data*) arg;
  int unr_ker_size = (curr->m)*(curr->m);
  vector<vector<float> > bigmat = curr->Matrix;
  vector<float> unr_ker = curr->kernel;

  float sum; 
  sum = 0;

  for (int j =0; j<unr_ker_size;j++){
    sum += bigmat[curr->row][j] * unr_ker[j];
  }
  
  (curr->result)[curr->row] = sum;
  pthread_exit(NULL);
}


vector<vector<float> > Pthread(vector<vector<float> > temp, vector<float> ker, int m, int t){
	
//Performing matrix multiplication and storing the result in the vector of size n-m+1 * n-m+1
//bigmatrix is of dimension (((n-m)/stride)+1)*(((n-m)/stride)+1) x (m*m) := temp
// unrolled kernel of size m*mx1 := ker

vector<float> may(t);

data curr1;
curr1.Matrix = temp;
curr1.kernel = ker;
curr1.m = m; 
curr1.row = 0; 
curr1.column = 1;
curr1.result = may;

for (int i =0; i< t; i++){
// j will be 1; the number of columns of the resultant matrix
  curr1.row = i;
  
  pthread_t tid;
  pthread_create(&tid,NULL,matMulFun, (void * ) &curr1);
  pthread_join(tid,NULL);
}

vector<float> rest = curr1.result;
int s = pow(t,0.5);

vector<vector<float> > tempres(s,vector<float>(s));


//converting the answer we got in the form of vector<vector<float>> from vector<float>

int counter = s;
int count = -1;

for(int i=0; i<t; i++){
    if(counter == s){
        counter = 0; 
        count++; 
    }
    tempres[count][counter] = rest[i];
    counter++; 
}

return tempres;
}