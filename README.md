# image_processing_library
The first task of COP290 course, IIT Delhi. 

## Installation
### MKL
To install the Intel Math Kernel Library in Ubuntu run the script
<pre>./install_mkl.sh</pre>
This script was used as it is from <a href="https://github.com/eddelbuettel/mkl4deb/blob/master/script.sh">this link</a>
Do note that you need to set up environmental variables. 
Information regarding that can be found <a href="https://software.intel.com/en-us/mkl-linux-developer-guide-automating-the-process-of-setting-environment-variables">here</a> 

### OpenBlas
OpenBlas installation can be done by just running this script in Ubuntu. 
<pre> ./install_openblas.sh</pre>
For other operating systems, please go over this <a href = "https://github.com/xianyi/OpenBLAS/wiki/Installation-Guide"> wiki</a>.

## Running the program

Run the script 
<pre> ./automate.sh</pre>
Choose out of the 4 options. Either Choose the number or the option name and follow along the instructions given.

For detailed execution refer the details given below.

## Makefile

### The main function
The code can be compiled in different ways. If you want to run functions like Pooling, Convolutions.... etc.Use the command
<pre> make main </pre>
<!--To compile the code, run 
```sh
make
```-->
### Matrix multiplication using Pthreads
To compile the program for Pthreads multiplication,
<pre> make plot_pthreads </pre>

### Matrix multiplication using Intel MKL
To compile the program for MKL matrix multiplication,
<pre> make plot_mkl </pre>

### Matrix multiplication using openBlas
To compile the program for Matrix multiplication using openBlas,
<pre> make plot_openblas </pre>

### LeNet Architecture
To compile the LeNet Architecture with the trained weights
<pre> make lenet </pre>

### Removing files
And to remove all the .out files, .eps files and empty the .dat files, run
```sh
make clean
```

## Functions
The program has many functions which can be run individually with different set of arguments.

### Sigmoid

The sigmoid activation function can be called using the syntax below:

<pre>
$ ./main.out Sigmoid <i>file_path</i>
</pre>

Here the *file_path*(string) is the relative path fo the txt file containing a **vector**, for the function to be applied to. The function returns a vector after applying the Sigmoid function to each of its elements. 

### Softmax

To call the Softmax function,

<pre>
$ ./main.out Softmax <i>file_path</i>
</pre>

Same as sigmoid, the *file_path*(string) is the relative path fo the txt file containing a **vector**, for the function to be applied to. The function returns a vector after applying the Softmax function to each of its elements.

### Relu

To call the Relu function on the matrix,
<pre>
$ ./main.out Relu <i>file_path</i>  <i>num_rows</i>  
</pre>

The Relu function, takes the *file_path*(string) of the txt file containing a **matrix** in the **column major** order. It returns a vector in the row major order after applying the Relu function to each of its elements.<br>
*num_rows*(int) is the user input of the number of rows present in the matrix given in the file.
### Tanh

To call the Tanh function on the matrix,
<pre>
$ ./main.out Tanh <i>file_path</i>  <i>num_rows</i>  
</pre>

The Tanh function, takes the *file_path*(string) of the txt file containing a **matrix** in the **column major** order. It returns a matrix in the row major order after applying the Relu function to each of its elements.<br>
*num_rows*(int) is the user input of the number of rows present in the matrix given in the file.

### Padding
To call the padding function on the matrix,
<pre>
$ ./main.out Padding <i>file_path</i> <i> num_rows</i> <i>pad_num</i>
</pre>
Padding function takes *file_path*(string) as the relative path to the txt file containing a **matrix** in the **column major** order.<br><br>
*num_rows*(int) is the user input of the number of rows present in the matrix given in the file.<br><br>
*pad_num*(int) is the number of zeros to add on each side of the matrix. For eg. On a 4x4 matrix adding a *pad_num* of 1 will add 1 zero on each side and make the matrix (1+4+1)x(1+4+1) i.e. 6x6.<br><br>

### Pooling 
To call the pooling function,
<pre>
$ ./main.out Pooling <i>file_path</i> <i>num_rows</i> <i>kernel_size</i> <i>pad_num</i> <i>type</i>
</pre>
Padding function takes *file_path*(string) as the relative path to the txt file containing a **matrix** in the **column major** order.<br><br>
*num_rows*(int) is the user input of the number of rows present in the matrix given in the file.<br><br>
*kernel_size*(int) is an integer n, which will make the kernel nxn.<br><br>
*pad_num*(int) is the number of zeros to add on each side of the matrix.<br><br>
*type*(string) is the type of pooling to use, **max** or **avg**. <br><br>
#### Please note that Pooling Function does not implement strides and considers the size of the kernel to be equal to the stride itself

## Convolution
To call the Convolution function, 
<pre>
$ ./main.out Convolution <i>file_path</i> <i>num_rows</i> <i>kernel_path</i> <i>kernel_rows</i> <i>padding</i> <i>stride_value</i> <i>type</i> <i>[type2]</i>
</pre>
Convolution function takes *file_path*(string) as the relative path to the txt file containing a **matrix** in the **column major** order.<br><br>
*num_rows*(int) is the user input of the number of rows present in the matrix given in the file.<br><br>
*kernel_path*(string) is the relative path to the txt file containing a **matrix** in the **column major** order.<br><br>
*kernel_rows*(int) is the user input of the number of rows present in the matrix given in the file.<br><br>
*padding*(string) is of two type <br><br>
&nbsp;&nbsp;-&nbsp;**same** :when the output is same as the input matrix.<br><br>
&nbsp;&nbsp;-&nbsp;**valid** :when no padding is applied on the input matrix.<br><br>
*stride_value*(int) is the stride value for calculating the Convolution.<br><br>
*type*(string) is used to select how you wish to calculate the output either by using Convolution or by using the Matrix Multiplication method.<br><br>

*type2*(string) is used for only the matrix multiplication method where you either write <i>pthreads</i> or <i>openBlas</i>or <i>MKL</i> depending on the library you want to use. Leaving it blank uses the **pthreads** implementation<br> <br>

&nbsp;&nbsp;-&nbsp;**matrix** for selecting Matrix Multiplication method.<br>
&nbsp;&nbsp;-&nbsp;**convolution** for selecting the convolution method.<br>

## Plotting Functions
To use the plotting functions, after compilation using the makefile
<pre> plot_[pthreads | mkl | openblas].out <i>rows_of_matrix</i> <i>columns_of_matrix</i> <i>iterations</i></pre>
**rows_of_matrix** gives the number of rows of the big matrix.
**columns_of_matrix*** gives the number of columns of the big matrix, or equivalently the length of the kernel.
**iterations** is a conditional that works as follows:

if **iterations** is given as **0** then the output comes as the time taken for the matrix multiplication on the terminal.
if it is non zero, then the output goes to a file [pthreads | openblas | mkl ].dat with the corresponding format:

<pre> Matrix Rows   Mean_Time   Std_Deviation</pre>


till the number of iterations provided by the user.

## GNUPLOT
After running the **make plot** command you can print the graph just by a simple command in the terminal.
<pre>gnuplot "plot.gp"</pre> 

## LENET Architecture
The Lenet Architecture is used to identify handwritten letter. It is easy to implement and easy to understand. The Layer by Layer implementation information is given below.<br>
<br>
The first step is to convert the given MNSIT image to an array of size 28x28. Then we store the array in the .txt file. The normalised form(values from 0-1) will be stored in the text file rather than the pixel values.<br>
Formula to for normalisation is 1-(Pixel Value)/255.<br>
<br>
MNIST Input image: 28x28 pixels, grayscale so number of channels 1

### Layer 1: Convolution 
Input dimension N: 28x28<br>
Input channels: 1<br>
Output channels(Number of filters): 20<br>
Kernel K = 5, so each filter is a 5x5 square<br>
Stride 1, padding 0, so output dimension (N-K+1) = 28-5+1 = 24<br>

### Layer 2: Pooling
Since we are doing max pooling hence no need of wweights.<br>
Input dimension N: 24x24<br>
Input channels: 20<br>
Pooling with kernel: K = 2, stride 2, so output is 12x12<br>
Output channel: 20<br>

### Layer 3: Convolution
Input dimension N: 12x12<br>
Input channels: 20<br>
Output channels(Number of Filters): 50<br>
Kernel K = 5, so each filter is a 5x5 square<br>
Stride 1, padding 0, so output dimension (N-K+1) = 12-5+1 = 8<br>

### Layer 4: Pooling
Since we are doing max pooling henc no need of weights.<br>
Input dimension: N = 8x8
Input channels: 50
Pooling with kernel: K = 2, stride 2, so output is 4x4
Output channel: 50.<br>

### Layer 5: Fully Connected
This layer has an relu layer in it.<br>
Input dimension N 4x4
Input channels 50
Output channels 500, so number of filters 500 -- each filter will produce 1 output channel
Kernel K = 4, so each filter is a 4x4 square
Stride 1, padding 0, so output dimension (N-K+1) = 4-4+1 = 1Input dimension N 4x4
Input channels 50
Output channels 500, so number of filters 500 -- each filter will produce 1 output channel
Kernel K = 4, so each filter is a 4x4 square<br>
Stride 1, padding 0, so output dimension (N-K+1) = 4-4+1 = 1<br>

### Layer 6: Fully Connected 
Input dimension: N 1x1<br>
Input channels: 500<br>
Output channels(Number of filters 10): 10<br>
Kernel K = 1, so each filter is a 1x1 square<br>
Stride 1, padding 0, so output size (N-K+1) = 1-1+1 = 1<br>

We get an array of size 10x1 which contains the probability of all the digits in it starting from 0 to 9.
<!--
### Changelog
The file **Output.txt** saves all the programs run along with its outputs. This file saves outputs across sessions and clever use of this file will allow a user to retrieve the matrices for further processing. -->
