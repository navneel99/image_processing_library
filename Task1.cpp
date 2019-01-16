#include "deps.hpp"

int main(int argc, char **argv){
    string outName = argv[0];
    string p_name = argv[1];
    string f1_name = argv[2];
    if (p_name == "Relu"){

        int num_rows = stoi(argv[3]);
        vector< vector<float> > a = inputFromText(f1_name,num_rows);
        a = Relu(a);
        dispVector(a);

    } else if (p_name == "Sigmoid"){  //Takes in a row vector

        vector <vector <float> > a = inputFromText(f1_name,1);
        vector<float> b = a[0]; //convert to a single row
        b = Sigmoid(b);
        a[0] = b; //Covert back to a matrix
        dispVector(a);
   
    } else if (p_name == "Softmax"){

        vector <vector <float> > a = inputFromText(f1_name,1);
        vector<float> b = a[0]; //convert to a single row
        b = Softmax(b);
        a[0] = b; //Covert back to a matrix
        dispVector(a);

    } else if (p_name == "Tanh"){
        
        int num_rows = stoi(argv[3]);
        vector< vector<float> > a = inputFromText(f1_name,num_rows);
        a = Tanh(a);
        dispVector(a);

    } else if (p_name == "Padding"){

        int num_rows = stoi(argv[3]);
        int padder = stoi(argv[4]);
        vector<vector<float> > a = inputFromText(f1_name,num_rows);
        a = Padding(a,padder);
        dispVector(a);

    } else if (p_name == "Pooling"){
        
        int num_rows = stoi(argv[3]);
        int kernel_size = stoi(argv[4]);
        int padder = stoi(argv[5]);
        string type = argv[6];
        if (type != "max" && type != "avg"){
            cout << "Wrong Type Entered"<< endl;
        } else{
            vector<vector<float> > a = inputFromText(f1_name,num_rows);
            a = Pooling(a,kernel_size,padder,type);
            dispVector(a);
        }

    } else if (p_name == "Convolution"){
         int conv_rows = stoi(argv[3]);
         int kernel = stoi(argv[4]);
         int ker_rows = stoi(argv[5]);
         int padder = stoi(argv[6]);
         int type = stoi(argv[7]);

         if(type == 1){
        //when type = 1 call the normal convolution function 
        //   vector<vector<float>> a = Convolution(f1_name, );
         }else if(type == 0){
        // when type = 0 call the convolution by matrix multiplication method
        //  vector<vector<float>> a = convm(f1_name, );
         }else{
             cout<<"Error"<<endl;
         }



       //  vector<vector<float>> a = Convolution(f1_name, )
        // Currently only one argument is needed for convolution, argv[3] can be the type 
        // eg. "matrix_mul" or "convolution" or you can make one more if else statement


    } else{

        cout << "None match"<<endl;

    }

return 0;
}