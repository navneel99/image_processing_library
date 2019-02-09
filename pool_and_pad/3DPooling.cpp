#include "pooling.hpp"
#include "padding.hpp"

vector<vector<vector<float> > > Pool3D(vector<vector<vector<float> > > input, int kersize, int pad, string whichone )
{
	int inputsize = input.size();
	int inputdepth = input[0][0].size();
	vector<vector<vector<float> > > output(inputdepth, vector<vector<float> > (inputsize));


	for(int i=0; i<inputdepth; i++){
	vector<vector<float> > tempinput(inputsize);
		
		//taking the slice of the 3d matrix which is at depth i and storing it in the temp matrix
		for(int j=0; j<inputsize; j++){
			for(int k=0; k<inputsize; k++){
				tempinput[j][k] = input[i][j][k];
			}
		}

		output[i] = Pooling(tempinput, kersize, pad, whichone);
	}
}
