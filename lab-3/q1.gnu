set terminal wxt size 1000,700
set title 'Binary Search vs Ternary Search'
set xlabel 'Input Size (n)'
set ylabel 'Number of Comparisons'
set grid
set key outside
set logscale x
plot 'q1.txt' using 1:2 with linespoints title 'Binary Search O(log2 n)', \
     'q1.txt' using 1:3 with linespoints title 'Ternary Search O(log3 n)'
pause -1
