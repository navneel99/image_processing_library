# image_processing_library
The first task of COP290 course, IIT Delhi

## Makefile
To compile the code, run 
```sh
make
```
And to remove all the .out files, run
```sh
make clean
```
This will output the .out file with name, **yourcode.out**
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

To call the Sigmoid function,

<pre>
$ ./yourcode.out Sigmoid  <i>file_path</i>
</pre>

### Softmax

To call the Softmax function,

<pre>
$ ./yourcode.out Softmax  <i>file_path</i>
</pre>

### Relu

To call the Relu function on the matrix,
<pre>
$ ./yourcode.out Relu  <i>file_path</i>  <i>num_rows</i>  
</pre>

### Tanh

To call the Tanh function on the matrix,
<pre>
$ ./yourcode.out Tanh <i>file_path</i>  <i>num_rows</i>  
</pre>

### Padding
To call the padding function on the matrix,
<pre>
$ ./yourcode.out Padding <i>file_path</i> <i> num_rows</i> <i>pad_num</i>
</pre>

### Pooling 
To call the pooling function,
<pre>
$ ./yourcode.out Pooling <i>file_path</i> <i>num_rows</i> <i>kernel_size</i> <i>pad_num</i> <i>type</i>
</pre>

### <b>Legend</b>:<br>
file_path: Relative Path to the file<br>
num_rows: Number of rows in the matrix to the above file_path<br>
pad_num: Units of padding surrounding the actual matrix<br>
kernel_size: Size of the kernel to apply the pooling function on<br>
type: Either "max" pooling or "avg" pooling<br>
