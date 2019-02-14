output_folder = "graph_plots/"

set terminal postscript eps enhanced color  # (These commented lines would be used to )
set output  output_folder."Pthreads.eps"   # (generate a postscript file.            )

#setting the global size of the font to 10 and displaying grids
set key font "Verdana,20"
set mxtics 5
set grid ytics
set grid xtics mxtics

set title "Rows vs Time plot using data"
set xlabel "No. of rows"
set ylabel "Time(in microseconds)"


plot "dat_files/pthread.dat" using 1:2:3 with linespoint title "Pthread"
     
set output output_folder . "Openblas.eps"
plot "dat_files/openblas.dat" using 1:2:3 with linespoint title "Openblas"

set output output_folder . "MKL.eps"
plot "dat_files/mkl.dat" using 1:2:3 with linespoint title "MKL"

set output output_folder . "All_comparision_without_error_bars.eps"
plot "dat_files/pthread.dat" using 1:2:3 with linespoint title "Pthread",\
     "dat_files/openblas.dat" using 1:2:3 with linespoint title "Openblas",\
     "dat_files/mkl.dat" using 1:2:3 with linespoint title "MKL"

set output output_folder . "openblas_vs_mkl_without_error_bars.eps"
plot "dat_files/openblas.dat" using 1:2:3 with linespoint title "Openblas",\
     "dat_files/mkl.dat" using 1:2:3 with linespoint title "MKL"

set output output_folder. "Pthreads_with_error_bars.eps"
plot "dat_files/pthread.dat" using 1:2:3 with lines title "Pthread",\
    "dat_files/pthread.dat" using 1:2:3 with yerrorbars notitle

set output output_folder. "openblas_with_error_bars.eps"
plot "dat_files/openblas.dat" using 1:2:3 with lines title "Openblas",\
     "dat_files/openblas.dat" using 1:2:3 with yerrorbars notitle

set output output_folder. "MKL_with_error_bars.eps"
plot "dat_files/mkl.dat" using 1:2:3 with lines title "MKL",\
     "dat_files/mkl.dat" using 1:2:3 with yerrorbars notitle

set output output_folder . "All_comparision_with_error_bars.eps"
plot "dat_files/pthread.dat" using 1:2:3 with lines title "Pthread",\
     "dat_files/openblas.dat" using 1:2:3 with lines title "Openblas",\
     "dat_files/mkl.dat" using 1:2:3 with lines title "MKL",\
     "dat_files/pthread.dat" using 1:2:3 with yerrorbars notitle,\
     "dat_files/openblas.dat" using 1:2:3 with yerrorbars notitle,\
     "dat_files/mkl.dat" using 1:2:3 with yerrorbars notitle 
#pause -1 "Hit any key to continue"
