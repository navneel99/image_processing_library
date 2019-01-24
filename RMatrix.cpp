#include "io.hpp"
#include <time.h>

void Write(int size1, string name1){
	ofstream file;
    file.open (name1);

	srand(time(0));

	for(int i=0; i<size1; i++){
		for(int j=0; j<size1; j++){
			int random = rand()%100; 
			file<<random<<" ";
		}
		file<<"\n";
	}

	file.close();
}