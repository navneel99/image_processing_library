compiler = g++
root = ~
#root =/opt
comm_lib_path = intel/mkl
comm_lib = lib/intel64
intel = -m64 -I $(root)/$(comm_lib_path)/include -L$(root)/$(comm_lib_path)/$(comm_lib) -Wl,--no-as-needed $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_scalapack_lp64.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_intel_lp64.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_gnu_thread.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_core.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_blacs_intelmpi_lp64.a -lgomp -lpthread -lm -ldl

mainIn = convolution.cpp display.cpp inputFromText.cpp main.cpp matMul.cpp mkl.cpp openblas.cpp outfile.cpp padding.cpp pooling.cpp Pthread.cpp Relu.cpp Sigmoid.cpp Softmax.cpp Tanh.cpp Trans.cpp

randomIn = display.cpp random.cpp Pthread.cpp mkl.cpp openblas.cpp

main: $(mainIn)
	@echo "Compiling the 'main' function.This may take a while."
	@$(compiler) -o main.out  $(mainIn) $(intel)
	@echo "Compilation Complete. Your output file is 'main.out'."

plot: $(randomIn)
	@echo "Compiling the 'plotting' function. This may take a while."
	@$(compiler) -o plot.out $(randomIn) $(intel)
	@echo "Compilation complete. Your output file is 'plot.out'."
clean: 
	rm *.out 
