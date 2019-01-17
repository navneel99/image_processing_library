# image_processing_library
The first task of COP290 course, IIT Delhi. 

## Makefile
To compile the code, run 
```sh
make
```
And to remove all the .out files, run
```sh
make clean
```
This will output the .out file with name, **main.out**
## Functions
The program has many functions which can be run individually with different set of arguments.

###Convolution
To call the Convolution function,
<pre>
$ ./yourcode.out Sigmoid  <i>file_path</i> <i>num_rows</i>
</pre>

###convm
To call the convolution by matrix multiplication method
<pre>
$ ./yourcode.out Sigmoid  <i>file_path</i> <i>num_rows</i>
</pre>

### Sigmoid

The sigmoid activation function can be called using the syntax below:

<pre>
$ ./main.out Sigmoid  <i>file_path</i>
</pre>

Here the file_path is the relative path fo the txt file containing a **vector**, for the function to be applied to. The function returns a vector after applying the Sigmoid function to each of its elements. 

### Softmax

To call the Softmax function,

<pre>
$ ./yourcode.out Softmax  <i>file_path</i>
</pre>

Same as sigmoid, the *file_path* is the relative path fo the txt file containing a **vector**, for the function to be applied to. The function returns a vector after applying the Softmax function to each of its elements.

### Relu

To call the Relu function on the matrix,
<pre>
$ ./yourcode.out Relu  <i>file_path</i>  <i>num_rows</i>  
</pre>

The Relu function, takes the *file_path* of the txt file containing a **matrix** in the **column major** order. It returns a vector in the row major order after applying the Relu function to each of its elements.
*num_rows* is the user input of the number of rows present in the matrix given in the file.
### Tanh

To call the Tanh function on the matrix,
<pre>
$ ./yourcode.out Tanh <i>file_path</i>  <i>num_rows</i>  
</pre>

The Tanh function, takes the file_path of the txt file containing a **matrix** in the **column major** order. It returns a matrix in the row major order after applying the Relu function to each of its elements.
*num_rows* is the user input of the number of rows present in the matrix given in the file.

### Padding
To call the padding function on the matrix,
<pre>
$ ./yourcode.out Padding <i>file_path</i> <i> num_rows</i> <i>pad_num</i>
</pre>
Padding function takes *file_path* as the relative path to the txt file containing a **matrix** in the **column major** order.
*num_rows* is the user input of the number of rows present in the matrix given in the file.
*pad_num* is the number of zeros to add on each side of the matrix. For eg. On a 4x4 matrix adding a *pad_num* of 1 will add 1 zero on each side and make the matrix (1+4+1)x(1+4+1) i.e. 6x6.

### Pooling 
To call the pooling function,
<pre>
$ ./yourcode.out Pooling <i>file_path</i> <i>num_rows</i> <i>kernel_size</i> <i>pad_num</i> <i>type</i>
</pre>
Padding function takes *file_path* as the relative path to the txt file containing a **matrix** in the **column major** order.
*num_rows* is the user input of the number of rows present in the matrix given in the file.
*kernel_size* is an integer n, which will make the kernel nxn.
*pad_num* is the number of zeros to add on each side of the matrix.
*type* is the type of pooling to use, **max** or **avg**. 

