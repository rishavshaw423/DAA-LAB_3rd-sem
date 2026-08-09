#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void plot_sorted_array() {
    FILE *fp = fopen("sorted_array.dat", "w");
    if(fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    
    // Generate data for n = 1 to 100
    for(int n = 1; n <= 100; n++) {
        double log_n = log2(n > 1 ? n : 2);
        
        // Asymptotic complexities for Sorted Array
        // Search: O(log n), Insert: O(n), Delete: O(n), Max: O(1), Min: O(1), Pred: O(log n), Suc: O(log n)
        double search = log_n;
        double insert = n;
        double delete = n;
        double max = 1;
        double min = 1;
        double pred = log_n;
        double suc = log_n;
        
        fprintf(fp, "%d %f %f %f %f %f %f %f\n", 
                n, search, insert, delete, max, min, pred, suc);
    }
    fclose(fp);
    
    // Gnuplot
    FILE *gp = popen("gnuplot -persistent", "w");
    if(gp == NULL) {
        printf("Gnuplot not found!\n");
        return;
    }
    
    fprintf(gp, "set terminal wxt size 1200,800 enhanced\n");
    fprintf(gp, "set title 'Sorted Array - Dictionary Operations'\n");
    fprintf(gp, "set xlabel 'Input Size (n)'\n");
    fprintf(gp, "set ylabel 'Number of Operations'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key outside right\n");
    fprintf(gp, "set key font ',10'\n");
    fprintf(gp, "set style data linespoints\n");
    fprintf(gp, "set pointsize 1.5\n");
    fprintf(gp, "set xrange [0:105]\n");
    fprintf(gp, "set yrange [0:110]\n");
    
    fprintf(gp,
        "plot "
        "'sorted_array.dat' using 1:2 with linespoints lw 2 lc rgb 'red' title 'Search O(log n)', "
        "'sorted_array.dat' using 1:3 with linespoints lw 2 lc rgb 'blue' title 'Insert O(n)', "
        "'sorted_array.dat' using 1:4 with linespoints lw 2 lc rgb 'green' title 'Delete O(n)', "
        "'sorted_array.dat' using 1:5 with linespoints lw 2 lc rgb 'orange' title 'Max O(1)', "
        "'sorted_array.dat' using 1:6 with linespoints lw 2 lc rgb 'purple' title 'Min O(1)', "
        "'sorted_array.dat' using 1:7 with linespoints lw 2 lc rgb 'brown' title 'Pred O(log n)', "
        "'sorted_array.dat' using 1:8 with linespoints lw 2 lc rgb 'magenta' title 'Suc O(log n)'\n");
    
    fprintf(gp, "pause -1 'Press Enter to close...'\n");
    pclose(gp);
    printf("Sorted Array plotted successfully!\n");
}

int main() {
    plot_sorted_array();
    return 0;
}