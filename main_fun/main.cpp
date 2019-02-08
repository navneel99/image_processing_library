#include "../alldeps.hpp"

int main(int argc, char **argv){

    string erMessage = "Arguments have not been correctly entered.";
    string erMessage2 = "Wrong Type Entered.";
    string erMessage3 = "Please enter the arguments correctly!";
    string outFile = "Output.txt";

    ofstream file;
    file.open(outFile,ios_base::app);
    for (int i =0;i<argc;i++){
        file << argv[i]<<" ";
    }
    file<<"\n"<<endl;
    file.close();
    string outName = argv[0];
    string p_name = argv[1];
    string f1_name = argv[2];
    if (p_name == "Relu"){
        if ((argc == 4)){        
        int num_rows = stoi(argv[3]);
        vector< vector<float> > a = inputFromText(f1_name,num_rows,true);
        a = Relu(a);
        Outputtofile(outFile,a);
        dispVector(a);
        }
        else{
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }

    } else if (p_name == "Sigmoid"){  //Takes in a row vector
        if (argc == 3){
        vector <vector <float> > a = inputFromText(f1_name,1,false); //nx1 matrix
        vector <float> b;
        int temp = a.size();
        for (int i = 0; i<temp;i++){
            b.push_back(a[i][0]);
        }
        b = Sigmoid(b);
        for (int i = 0;i<temp;i++){
            a[i][0] = b[i];
        }
        Outputtofile(outFile,a);
        dispVector(a);
        } else{
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }
    } else if (p_name == "Softmax"){
        if (argc == 3){
        vector <vector <float> > a = inputFromText(f1_name,1,false);
        vector<float> b; 
        int temp = a.size();
        for (int i = 0; i<temp;i++){
            b.push_back(a[i][0]);
        }
        b = Softmax(b);
        for (int i = 0;i<temp;i++){
            a[i][0] = b[i];
        }
        Outputtofile(outFile,a);
        dispVector(a);
        }else{
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }
    } else if (p_name == "Tanh"){
        if (argc == 4){
        int num_rows = stoi(argv[3]);
        vector< vector<float> > a = inputFromText(f1_name,num_rows,true);
        a = Tanh(a);
        Outputtofile(outFile,a);
        dispVector(a);
        } else {
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }
    } else if (p_name == "Padding"){
        if (argc == 5){
        int num_rows = stoi(argv[3]);
        int padder = stoi(argv[4]);
        vector<vector<float> > a = inputFromText(f1_name,num_rows,true);
        a = Padding(a,padder);
        Outputtofile(outFile,a);
        dispVector(a);
        } else{
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }
    } else if (p_name == "Pooling"){
        if (argc == 7){
        int num_rows = stoi(argv[3]);
        int kernel_size = stoi(argv[4]);
        int padder = stoi(argv[5]);
        string type = argv[6];
        if (type != "max" && type != "avg"){
            cout << "Wrong Type Entered"<< endl;
            Outputtofile(outFile,erMessage2);
        } else{
            vector<vector<float> > a = inputFromText(f1_name,num_rows,true);
            a = Pooling(a,kernel_size,padder,type);
            Outputtofile(outFile,a);
            dispVector(a);
        }
        } else{
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }
    } else if (p_name == "Convolution"){
        if (argc == 9 || argc == 10){
         int conv_rows = stoi(argv[3]);
         string kfile_name = argv[4];
         int ker_rows = stoi(argv[5]);
         string pad = argv[6];
         int stride = stoi(argv[7]);
         string type = argv[8];
         vector<vector<float> > input_matrix = inputFromText(f1_name, conv_rows, true);
         vector<vector<float> > kernel = inputFromText(kfile_name, ker_rows, true);

         int padder;

         if(pad == "same"){
             padder = (conv_rows - 1)*stride + ker_rows - conv_rows;
             padder = padder/2;
         }else if(pad == "valid"){
             padder = 0;
         }else{
             cout<<"Value of padding not correct";
             exit;
         }
         
         if(type == "Convolution"){
        //when type = convolution call the normal convolution function 
           vector<vector<float>> a = Convolution(input_matrix, kernel, padder, stride);
           Outputtofile(outFile,a);
           dispVector(a);
         }else if(type == "Matrix"){
        // when type = Matrix call the convolution by matrix multiplication method
            string type2;
            if (argc == 9){
              type2 = "pthreads";
            }else{
                type2 = argv[9];
            }
          vector<vector<float> > a = convm(input_matrix, kernel, padder, stride,type2);
          Outputtofile(outFile,a);
          dispVector(a);
         }else{
             cout<<"Error"<<endl;
             Outputtofile(outFile,erMessage2);
         }
        } else{
            cout << erMessage3<<endl;
            Outputtofile(outFile,erMessage);
        }
    } else{
        cout << "None match"<<endl;
        exit(1);
    }
    file.open(outFile,ios_base::app);
    file<<"End of the output\n"<<endl;
    file.close();
return 0;
}