#include "pooling.hpp"
#include "common.hpp"
#include "convolution.hpp"
#include "io.hpp"
#include "relu.hpp"
#include "softmax.hpp"

void LenetArch(string image, string ker_l1, string ker_l2, string ker_l3, string ker_l4){
    string output_folder = "layerwise_outputs/";
    vector<vector<float> > img = inputFromText(image,28,false); //transpose is false as everything is in row major
    tuple<vector<vector<vector<vector<float> > > >,vector<float> > ker_lay_1 = inputFromText3D(ker_l1,5,1,20);
    tuple<vector<vector<vector<vector<float> > > >,vector<float> > ker_lay_2 = inputFromText3D(ker_l2,5,20,50);
    tuple<vector<vector<vector<vector<float> > > >,vector<float> > ker_lay_3 = inputFromText3D(ker_l3,4,50,500);
    tuple<vector<vector<vector<vector<float> > > >,vector<float> > ker_lay_4 = inputFromText3D(ker_l4,1,500,10);

    vector<vector<vector<vector<float> > > > weights_lay_1 = get<0>(ker_lay_1);
    vector<vector<vector<vector<float> > > > weights_lay_2 = get<0>(ker_lay_2);
    vector<vector<vector<vector<float> > > > weights_lay_3 = get<0>(ker_lay_3);
    vector<vector<vector<vector<float> > > > weights_lay_4 = get<0>(ker_lay_4);

    vector<float> bias_lay_1 = get<1>(ker_lay_1);
    vector<float> bias_lay_2 = get<1>(ker_lay_2);
    vector<float> bias_lay_3 = get<1>(ker_lay_3);
    vector<float> bias_lay_4 = get<1>(ker_lay_4);

    //Conv_Layer_1
    vector<vector<vector<float> > > image_vector(1,vector<vector<float> >(28) );
    image_vector[0] = img;
    
    vector<vector<vector<float> > > ans_layer_1 = convolution3D(image_vector, weights_lay_1);
    for(int d=0; d<ans_layer_1.size(); d++){
       for(int i=0; i<ans_layer_1[0].size(); i++){
           for(int j=0; j<ans_layer_1[0][0].size(); j++){
               ans_layer_1[d][i][j] = ans_layer_1[d][i][j] + bias_lay_1[d];
            }
        }
    }
    Outputtofile(output_folder+"output__conv1.txt",ans_layer_1);

    //Pool_layer_2
    vector<vector<vector<float> > > ans_layer_2 = Pool3D(ans_layer_1, 2, 0, "max");
    
    Outputtofile(output_folder+"output__pool1.txt",ans_layer_2);
    //Conv_Layer_3
    vector<vector<vector<float> > > ans_layer_3 = convolution3D(ans_layer_2, weights_lay_2);
      for(int d=0; d<ans_layer_3.size(); d++){
       for(int i=0; i<ans_layer_3[0].size(); i++){
           for(int j=0; j<ans_layer_3[0][0].size(); j++){
               ans_layer_3[d][i][j] = ans_layer_3[d][i][j] + bias_lay_2[d];
            }
        }
    }
    Outputtofile(output_folder+"output__conv2.txt",ans_layer_3);
    

    //Pool_layer_4
    vector<vector<vector<float> > > ans_layer_4 = Pool3D(ans_layer_3, 2, 0, "max");
    
    Outputtofile(output_folder+"output__pool2.txt",ans_layer_4);
	
    //Fully Connected Layer_5
    vector<vector<vector<float> > > ans_layer_5 = FullyConnected3D(ans_layer_4,weights_lay_3);

     for(int d=0; d<ans_layer_5.size(); d++){
       for(int i=0; i<ans_layer_5[0].size(); i++){
           for(int j=0; j<ans_layer_5[0][0].size(); j++){
               ans_layer_5[d][i][j] = ans_layer_5[d][i][j] + bias_lay_3[d];
            }
        }
    }

     ans_layer_5 = Relu(ans_layer_5);
    Outputtofile(output_folder+"output__fc1.txt",ans_layer_5);

    //Fully Connected Layer_6
    vector<vector<vector<float> > > ans_layer_6 = convolution3D(ans_layer_5,weights_lay_4);
     for(int d=0; d<ans_layer_6.size(); d++){
       for(int i=0; i<ans_layer_6[0].size(); i++){
           for(int j=0; j<ans_layer_6[0][0].size(); j++){
               ans_layer_6[1][i][j] = ans_layer_6[1][i][j] + bias_lay_4[d];
            }
        }
    }

    Outputtofile(output_folder+"output__fc2.txt",ans_layer_6);    

    vector<float> finalans(10);
    for(int i=0; i<finalans.size(); i++){
        finalans[i] = ans_layer_6[i][0][0];

    }

    finalans = Softmax(finalans);
    Outputtofile(output_folder+"output__softmax.txt",finalans,false); //false to not append to the output file

    float max = finalans[0];
    int max_digit = 0;
    cout<< "Probabilities along with digits:"<<endl;
    for (int i =0;i<finalans.size();i++){
        cout<<i<<" ==> "<<finalans[i]<<endl;
        if (finalans[i]>max){
            max = finalans[i];
            max_digit = i;
        }
    }
    cout<< "Thus, the image is most likely of "<<max_digit<<endl;
}