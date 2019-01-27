compiler = g++
#root = ~
root =/opt
comm_lib_path = intel/mkl
comm_lib = lib/intel64
intel = -m64 -I $(root)/$(comm_lib_path)/include -L$(root)/$(comm_lib_path)/$(comm_lib) -Wl,--no-as-needed $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_scalapack_lp64.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_intel_lp64.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_gnu_thread.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_core.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_blacs_intelmpi_lp64.a -lgomp -lpthread -lm -ldl
openBlas = -lpthread -lopenblas

mainIn = convolution.cpp display.cpp inputFromText.cpp main.cpp matMul.cpp mkl.cpp openblas.cpp outfile.cpp padding.cpp pooling.cpp Pthread.cpp Relu.cpp Sigmoid.cpp Softmax.cpp Tanh.cpp Trans.cpp normalMatMul.cpp

mkl_files = display.cpp random.cpp Pthread.cpp mkl.cpp outfile.cpp mklMain.cpp

pthread_files = display.cpp random.cpp Pthread.cpp outfile.cpp pthreadsMain.cpp

openblas_files = display.cpp random.cpp openblas.cpp outfile.cpp blasMain.cpp

main: $(mainIn)
	@echo "Compiling the 'main' function.This may take a while."
	@$(compiler) -o main.out  $(mainIn) $(intel)
	@echo "Compilation Complete. Your output file is 'main.out'."

clean: 
	rm *.out *.exe

plot_pthreads: $(pthread_files)
	@echo "Compiling only the pThreads engine."
	@$(compiler) -o plot_pthreads.out $(pthread_files) -lpthread 

plot_openblas: $(openblas_files)
	@echo "Compiling only the openBlas engine."
	@$(compiler) -o plot_openblas.out $(openblas_files) $(openBlas) 
plot_mkl: $(mkl_files)
	@echo "Compiling only the mkl engine."
	@$(compiler) -o plot_mkl.out $(mkl_files) $(intel) 