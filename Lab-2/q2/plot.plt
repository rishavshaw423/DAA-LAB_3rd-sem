set terminal pngcairo size 1000,700 enhanced
set output 'merge_sort.png'
set title 'Merge Sort vs Modified Merge Sort'
set xlabel 'Input Size (n)'
set ylabel 'Growth'
set grid
set key outside
plot 'merge_sort.txt' using 1:2 with lines lw 2 title 'Merge Sort O(n log_2 n)', 'merge_sort.txt' using 1:3 with lines lw 2 title 'Modified Merge Sort O(n log_3 n)'
set output
