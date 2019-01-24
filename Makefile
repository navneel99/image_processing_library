

compiler = g++
intel = -m64 -I /opt/intel/mkl/include -L/opt/intel/mkl/lib/intel64 -Wl,--no-as-needed /opt/intel/mkl/lib/intel64/libmkl_scalapack_lp64.a /opt/intel/mkl/lib/intel64/libmkl_intel_lp64.a /opt/intel/mkl/lib/intel64/libmkl_gnu_thread.a /opt/intel/mkl/lib/intel64/libmkl_core.a /opt/intel/mkl/lib/intel64/libmkl_blacs_intelmpi_lp64.a -lgomp -lpthread -lm -ldl
#output = 

mainIn = convolution.cpp display.cpp inputFromText.cpp main.cpp matMul.cpp mkl.cpp openblas.cpp outfile.cpp padding.cpp pooling.cpp Pthread.cpp Relu.cpp Sigmoid.cpp Softmax.cpp Tanh.cpp Trans.cpp
randomIn = display.cpp random.cpp Pthread.cpp mkl.cpp openblas.cpp

main: $(mainIn)
	$(compiler) -o main.out  $(mainIn) $(intel)

plot: $(randomIn)
	$(compiler) -o plot.out $(randomIn) $(intel)
clean: 
	rm *.out 

#g++ -o main.out  display.cpp random.cpp Pthread.cpp -m64 -I ~/intel/mkl/include -L~/intel/mkl/lib/intel64 -Wl,--no-as-needed ~/intel/mkl/lib/intel64/libmkl_scalapack_lp64.a ~/intel/mkl/lib/intel64/libmkl_intel_lp64.a ~/intel/mkl/lib/intel64/libmkl_gnu_thread.a ~/intel/mkl/lib/intel64/libmkl_core.a ~/intel/mkl/lib/intel64/libmkl_blacs_intelmpi_lp64.a -lgomp -lpthread -lm -ldl