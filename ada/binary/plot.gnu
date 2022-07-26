set title "BINARY SEARCH RECURSIVE"
set xlabel "Input Size"
set ylabel "Basic Op Count"
set xrange [10:100]
set yrange [0:9]
set style data linespoints
plot "best.txt" title "best case","worst.txt" title "Worst case","avg.txt" title "Avg Case"
