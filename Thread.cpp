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



vector<vector<float> > convm(vector<vector<float> > array, vector<vector<float> > kernel, int x, int stride){

//calling the padding  function   
    vector<vector<float> > arr = Padding(array, x);

     int n=arr.size();
    int m=kernel.size();
    int t=(((n-m)/stride) +1)*(((n-m)/stride) +1);


    //float temp[t][m*m]; //the big matrix
    //float ker[m*m];   //unrolled kernel
	int k=0;
    vector<vector<float> > temp(t,vector<float>(m*m));
    vector<float> ker(m*m);

//making an temp kernel so that we can use it for multiplication
    for(int i=0; i<m; i++){
      for(int j=0; j<m; j++){
        ker[k]=kernel[i][j];
        k+=1;
      }
    }
    k=0;


//Making the matrix from the input matrix and kernel 
    for(int i=0; i<n; i+=stride){
        for(int j=0; j<n; j+=stride){
            int l=0;
            if(i+m<=n && j+m<=n){
            for(int ii=0; ii<m; ii++){
              for(int jj=0; jj<m; jj++){
                temp[k][l]=arr[i+ii][j+jj];
                l+=1;
              }
             }
             k+=1;
            }else{
              break;
            }
        }
    }

//Performing matrix multiplication and storing the result in the vector of size n-m+1 * n-m+1
//bigmatrix is of dimension (((n-m)/stride)+1)*(((n-m)/stride)+1) x (m*m) := temp
// unrolled kernel of size m*mx1 := ker

//Allocating the memory from the heap for execution
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

vector<vector<float> > tempres(((n-m)/stride) +1,vector<float>(((n-m)/stride) +1));

int counter = ((n-m)/stride) +1;
int count = -1;

for(int i=0; i<t; i++){
    if(counter == ((n-m)/stride) +1){
        counter = 0; 
        count++; 
    }
    tempres[count][counter] = rest[i];
    counter++; 
}

return tempres;
}

