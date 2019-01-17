//#include "deps.hpp"
#include "alldeps.hpp"

int main(int argc, char **argv){
    string outName = argv[0];
    string p_name = argv[1];
    string f1_name = argv[2];
    if (p_name == "Relu"){
        if (argc == 4){        
        int num_rows = stoi(argv[3]);
        vector< vector<float> > a = inputFromText(f1_name,num_rows,true);
        a = Relu(a);
        dispVector(a);
        }
        else{
            cout << "Please enter the arguments correctly!"<<endl;
        }

    } else if (p_name == "Sigmoid"){  //Takes in a row vector
        if (argc == 3){
        vector <vector <float> > a = inputFromText(f1_name,1,false);
        vector<float> b = a[0]; //convert to a single row
        b = Sigmoid(b);
        a[0] = b; //Covert back to a matrix
        dispVector(a);
        } else{
            cout << "Please enter the arguments correctly!"<<endl;
        }
    } else if (p_name == "Softmax"){
        if (argc == 3){
        vector <vector <float> > a = inputFromText(f1_name,1,false);
        vector<float> b = a[0]; //convert to a single row
        b = Softmax(b);
        a[0] = b; //Covert back to a matrix
        dispVector(a);
        }else{
            cout << "Please enter the arguments correctly!"<<endl;
        }
    } else if (p_name == "Tanh"){
        if (argc == 4){
        int num_rows = stoi(argv[3]);
        vector< vector<float> > a = inputFromText(f1_name,num_rows,true);
        a = Tanh(a);
        dispVector(a);
        } else {
            cout << "Please enter the arguments correctly!"<<endl;
        }
    } else if (p_name == "Padding"){
        if (argc == 5){
        int num_rows = stoi(argv[3]);
        int padder = stoi(argv[4]);
        vector<vector<float> > a = inputFromText(f1_name,num_rows,true);
        a = Padding(a,padder);
        dispVector(a);
        } else{
            cout << "Please enter the arguments correctly!"<<endl;
        }
    } else if (p_name == "Pooling"){
        if (argc == 7){
        int num_rows = stoi(argv[3]);
        int kernel_size = stoi(argv[4]);
        int padder = stoi(argv[5]);
        string type = argv[6];
        if (type != "max" && type != "avg"){
            cout << "Wrong Type Entered"<< endl;
        } else{
            vector<vector<float> > a = inputFromText(f1_name,num_rows,true);
            a = Pooling(a,kernel_size,padder,type);
            dispVector(a);
        }
        } else{
            cout << "Please enter the arguments correctly!"<<endl;
        }
    } else if (p_name == "Convolution"){
        if (argc == 8){
         int conv_rows = stoi(argv[3]);
         string kfile_name = argv[4];
         int ker_rows = stoi(argv[5]);
         string pad = argv[6];
         int stride = stoi(argv[7]);
         string type = argv[8];
         vector<vector<float>> input_matrix = inputFromText(f1_name, conv_rows, true);
         vector<vector<float>> kernel = inputFromText(kfile_name, ker_rows, true);

         int padder;

         if(pad == "same"){
             padder = (conv_rows - 1)*stride + ker_rows - conv_rows;
         }else if(pad == "valid"){
             padder = 0;
         }else{
             cout<<"value of padding not correct";
             exit;
         }

         if(type == "convolution"){
        //when type = 1 call the normal convolution function 
           vector<vector<float>> a = Convolution(input_matrix, kernel, padder, stride);
           dispVector(a);
         }else if(type == "Matrix"){
        // when type = 0 call the convolution by matrix multiplication method
          vector<vector<float>> a = convm(input_matrix, kernel, padder, stride);
          dispVector(a);
         }else{
             cout<<"Error"<<endl;
         }
        } else{
            cout << "Please enter the arguments correctly!"<<endl;
        }
       //  vector<vector<float>> a = Convolution(f1_name, )
    } else{

        cout << "None match"<<endl;

    }

return 0;
}