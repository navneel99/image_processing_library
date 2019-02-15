#!/bin/bash
while true; do
    echo "Select What would you like to Run:"
    echo  -e "1. SubTask-1 \n2. Plot \n3. LeNet \n4. Remove Files \n('q' to exit)"
    read option
    if [[ "$option" == "1"  || "$option" == "SubTask-1" ]]; then 
        echo "You can compile the SubTask-1 function using this script."
        make main
        echo "Use the command ./main.out [suitable arguments] for running this " 
        break
    elif [[ "$option" == "2" || "$option" == "Plot" ]]; then
        make plot_openblas
        make plot_mkl
        make plot_pthreads
        echo "Do you want to automatically generate and plot the data(y/n)?"
        read ans
        if (( "$ans"  == "n")); then
            echo "Exiting..."
            break
        else
            echo "The Starting Matrix size for plot is 10."
            echo "Enter end Matrix Size(Above 30)"
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
        fi
        echo "\n\n"
    elif [[ "$option" == "3" || "$option" == "LeNet" ]]; then
        echo -e "You have entered the LeNet Architecture.\n\n Make sure you have a png file on the same directory level as this script.\n For testing purposes we already have '1.png' and '2.png'."
        echo "Enter your png file name(with the extension ''.png')"
        read file_name
        python3 preprocess.py $file_name
        echo "The input file has been processed. Output is in 'inputData.txt'."
        make lenet
        echo "Running the LeNet Architecture..."
        ./lenet.out inputData.txt
        echo -e "\n\n"
    elif [[ "$option" == "4" || "$option" == "Remove Files" ]]; then
        make clean
    elif [[ "$option" == "q" ]]; then
        echo "Exiting..."
        break
    else 
        echo -e "Wrong Input Given. Just write the Number or the Option Name. Do note that it is Case Sensitive\n\n"
    fi
done 
