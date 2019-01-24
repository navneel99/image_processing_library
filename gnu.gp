#!/usr/bin/gnuplot -persist

set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5
set style line 2 \
    linecolor rgb '#dd181f' \
    linetype 1 linewidth 2 \
    pointtype 5 pointsize 1.5

plot 'graph1pthread.dat' index 0 with linespoints linestyle 1, \
     'graph2openblas.dat' index 1 with linespoints linestyle 2
