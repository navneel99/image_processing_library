#include "pooling.hpp"
#include "padding.hpp"
vector<vector<vector<float> > > Pool3D(vector<vector<vector<float> > > input, int kersize, int pad, string whichone )
{
	int inputsize = input[0].size();
	int inputdepth = input.size();
	vector<vector<vector<float> > > output(inputdepth, vector<vector<float> > (inputsize));

    
	for(int i=0; i<inputdepth; i++){
	vector<vector<float> > tempinput(inputsize, vector<float>(inputsize));
		
		//taking the slice of the 3d matrix which is at depth i and storing it in the temp matrix
		for(int j=0; j<inputsize; j++){
			for(int k=0; k<inputsize; k++){
				tempinput[j][k] = input[i][j][k];
			}
		}
		

		vector<vector<float> > tempans = Pooling(tempinput, kersize, pad, whichone);
		output[i] = tempans;
  }
 	return output;
}

