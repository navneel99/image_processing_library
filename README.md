# image_processing_library
The first task of COP290 course, IIT Delhi. 

## Makefile
## The main function
The code can be compiled in different ways. If you want to run functions like Pooling, Convolutions.... etc.Use the command
<pre> make main </pre>
<!--To compile the code, run 
```sh
make
```-->
## Matrix multiplication using Pthreads
To compile the program for Pthreads multiplication,
<pre> make plot_pthreads </pre>

## Matrix multiplication using Intel MKL
To compile the program for MKL matrix multiplication,
<pre> make plot_mkl </pre>

## Matrix multiplication using openBlas
To compile the program for Matrix multiplication using openBlas,
<pre> make plot_openblas </pre>

And to remove all the .out files, run
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
Padding function takes *file_path*(string) as the relative path to the txt file containing a **matrix** in the **column major** order.<br>
*num_rows*(int) is the user input of the number of rows present in the matrix given in the file.<br>
*pad_num*(int) is the number of zeros to add on each side of the matrix. For eg. On a 4x4 matrix adding a *pad_num* of 1 will add 1 zero on each side and make the matrix (1+4+1)x(1+4+1) i.e. 6x6.<br>

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

### Changelog
The file **Output.txt** saves all the programs run along with its outputs. This file saves outputs across sessions and clever use of this file will allow a user to retrieve the matrices for further processing.
