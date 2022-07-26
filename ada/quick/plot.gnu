set title "Quick Sort"
set xrange [10:100]
set yrange [10:5200]
set xlabel "Input size'
set ylabel "Basic Count"
set style data linespoints
plot "best.txt" title "Best case","worst.txt" title "Worst case","avg.txt" title "Avg case"
