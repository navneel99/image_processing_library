#!/bin/bash
echo "Select What would you like to Run:"

make plot_openblas
make plot_mkl
make plot_pthreads

echo "Enter End Matrix Size(Above 30)"
read var
echo "Enter Kernel Size."
read var2
for ((i=10;i<=var; i=i+20))
    do
        echo "Row $i"
         ./plot_openblas.out $i $var2 20
         ./plot_mkl.out $i $var2 20
         ./plot_pthreads.out $i $var2 20
    done

echo "Now Plotting the data."
gnuplot plot.gp
echo "Output in \"graph_plots\"."