#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void plot_singly_unsorted() {
    FILE *fp = fopen("singly_unsorted.dat", "w");
    if(fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    
    // Generate data for n = 1 to 100
    for(int n = 1; n <= 100; n++) {
        // Asymptotic complexities for Singly Unsorted List
        // Search: O(n), Insert: O(1), Delete: O(n), Max: O(n), Min: O(n), Pred: O(n), Suc: O(n)
        double search = n;
        double insert = 1;
        double delete = n;
        double max = n;
        double min = n;
        double pred = n;
        double suc = n;
        
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
    fprintf(gp, "set title 'Singly Unsorted Linked List - Dictionary Operations'\n");
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
        "'singly_unsorted.dat' using 1:2 with linespoints lw 2 lc rgb 'red' title 'Search O(n)', "
        "'singly_unsorted.dat' using 1:3 with linespoints lw 2 lc rgb 'blue' title 'Insert O(1)', "
        "'singly_unsorted.dat' using 1:4 with linespoints lw 2 lc rgb 'green' title 'Delete O(n)', "
        "'singly_unsorted.dat' using 1:5 with linespoints lw 2 lc rgb 'orange' title 'Max O(n)', "
        "'singly_unsorted.dat' using 1:6 with linespoints lw 2 lc rgb 'purple' title 'Min O(n)', "
        "'singly_unsorted.dat' using 1:7 with linespoints lw 2 lc rgb 'brown' title 'Pred O(n)', "
        "'singly_unsorted.dat' using 1:8 with linespoints lw 2 lc rgb 'magenta' title 'Suc O(n)'\n");
    
    fprintf(gp, "pause -1 'Press Enter to close...'\n");
    pclose(gp);
    printf("Singly Unsorted Linked List plotted successfully!\n");
}

int main() {
    plot_singly_unsorted();
    return 0;
}