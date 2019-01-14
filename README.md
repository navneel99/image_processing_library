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
