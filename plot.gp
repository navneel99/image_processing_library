#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )

#setting the global size of the font to 10 and displaying grids
set key font "Verdana,20"
set mxtics 5
set grid ytics
set grid xtics mxtics

set title "Rows vs Time plot using data"
set xlabel "No. of rows"
set ylabel "Time"


plot "pthread.dat" using 1:2:3 with linespoint title "Pthread",\
     "openblas.dat" using 1:2:3 with linespoint title "Openblas",\
     "mkl.dat" using 1:2:3 with linespoint title "MKL",\
     "pthread.dat" using 1:2:3 with yerrorbars notitle,\
     "openblas.dat" using 1:2:3 with yerrorbars notitle,\
     "mkl.dat" using 1:2:3 with yerrorbars notitle 
     
     
pause -1 "Hit any key to continue"
