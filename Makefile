compiler = g++
root = ~
#root =/opt
comm_lib_path = intel/mkl
comm_lib = lib/intel64
head_dir = headers

intel = -m64 -I $(root)/$(comm_lib_path)/include -L$(root)/$(comm_lib_path)/$(comm_lib) -Wl,--no-as-needed $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_scalapack_lp64.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_intel_lp64.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_gnu_thread.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_core.a $(root)/$(comm_lib_path)/$(comm_lib)/libmkl_blacs_intelmpi_lp64.a -lgomp -lpthread -lm -ldl
openBlas = -lpthread -lopenblas

ac_fun = activation_fun
io_fun = input_output
convo_fun = convo
poolpad_fun = pool_and_pad
main_fun = main_fun
extra_fun = extra

mainIn = $(main_fun)/main.cpp  $(poolpad_fun)/*.cpp  $(extra_fun)/Trans.cpp  $(ac_fun)/*.cpp $(io_fun)/*.cpp $(convo_fun)/*.cpp $(extra_fun)/inputFromText.cpp

mkl_files = $(extra_fun)/random.cpp $(convo_fun)/Pthread.cpp $(convo_fun)/mkl.cpp $(convo_fun)/mklblascomm.cpp  $(main_fun)/mklMain.cpp  $(io_fun)/*.cpp

pthread_files = $(io_fun)/*.cpp $(extra_fun)/random.cpp $(convo_fun)/Pthread.cpp  $(main_fun)/pthreadsMain.cpp

openblas_files = $(extra_fun)/random.cpp $(convo_fun)/openblas.cpp $(main_fun)/openblasMain.cpp $(convo_fun)/mklblascomm.cpp $(io_fun)/*.cpp

lenet_files = $(main_fun)/lenetMain.cpp $(extra_fun)/inputFromText.cpp $(extra_fun)/Trans.cpp $(io_fun)/display.cpp $(convo_fun)/3Dconv.cpp $(convo_fun)/convolution.cpp $(poolpad_fun)/*.cpp

main: $(mainIn)
	@echo "Compiling the 'main' function.This may take a while."
	@$(compiler) -o main.out  -I $(head_dir)/ $(mainIn) $(intel)
	@echo "Compilation Complete. Your output file is 'main.out'."

clean: 
	rm *.out *.exe

plot_pthreads: $(pthread_files)
	@echo "Compiling only the pThreads engine."
	@$(compiler) -o plot_pthreads.out -I $(head_dir)/ $(pthread_files) -lpthread 
	@echo "Output File is 'plot_pthreads.out'.The graph points,once the code runs are in 'pthreads.dat'"

plot_openblas: $(openblas_files)
	@echo "Compiling only the openBlas engine."
	@$(compiler) -o plot_openblas.out -I $(head_dir)/ $(openblas_files) $(openBlas) 
	@echo "Output File is 'plot_openblas.out'.The graph points,once the code runs are in 'openblas.dat'"

plot_mkl: $(mkl_files)
	@echo "Compiling only the mkl engine."
	@$(compiler) -o plot_mkl.out -I $(head_dir)/ $(mkl_files) $(intel) 
	@echo "Output File is 'plot_mkl.out'.The graph points,once the code runs are in 'mkl.dat'"

lenet: $(lenet_files)
	@echo "LeNet Compile."
	@$(compiler) -o lenet.out -I $(head_dir)/ $(lenet_files)
	@echo "Done."
