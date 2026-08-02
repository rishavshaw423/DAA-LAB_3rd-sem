#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[30];
    double value;
} Function;

int compare(const void *a, const void *b)
{
    Function *f1 = (Function *)a;
    Function *f2 = (Function *)b;

    if (f1->value > f2->value)
        return 1;
    if (f1->value < f2->value)
        return -1;
    return 0;
}

int main()
{
    int maxN, n;

    printf("Enter a value of n to display the increasing order of functions (n >= 1): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n must be at least 1.\n");
        return 1;
    }

    Function f[] = {
        {"1/n", 1.0 / n},
        {"log2(n)", log2(n)},
        {"12sqrt(n)", 12 * sqrt(n)},
        {"50sqrt(n)", 50 * sqrt(n)},
        {"n^0.51", pow(n, 0.51)},
        {"nlog2(n)", n * log2(n)},
        {"100n^2+6n", 100.0 * n * n + 6 * n},
        {"n^2-324", n * n - 324},
        {"2n^3", 2.0 * n * n * n},
        {"2^32*n", pow(2.0, 32) * n},
        {"n^(log2 n)", pow(n, log2(n))},
        {"3^n", pow(3.0, n)}
    };

    qsort(f, 12, sizeof(Function), compare);

    printf("\nIncreasing order of functions for n = %d:\n\n", n);
    for (int i = 0; i < 12; i++) {
        printf("%s", f[i].name);
        if (i != 11)
            printf(" < ");
    }
    printf("\n\n");

    printf("Enter the maximum value of n for plotting: ");
    scanf("%d", &maxN);

    if (maxN < 2) {
        printf("Error: maximum n must be at least 2.\n");
        return 1;
    }

    FILE *fp = fopen("functions.dat", "w");
    if (fp == NULL) {
        printf("Error creating data file!\n");
        return 1;
    }

    for (int i = 1; i <= maxN; i++) {
        fprintf(fp,
                "%d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                i,
                1.0 / i,
                (i == 1) ? 0.0001 : log2(i),
                12 * sqrt(i),
                50 * sqrt(i),
                pow(i, 0.51),
                (i == 1) ? 0.0001 : i * log2(i),
                100.0 * i * i + 6 * i,
                i * i - 324,
                2.0 * i * i * i,
                pow(2.0, 32) * i,
                (i == 1) ? 1.0 : pow(i, log2(i)),
                pow(3.0, i));
    }

    fclose(fp);

    FILE *gp = popen("gnuplot -persistent", "w");
    if (gp == NULL) {
        printf("GNUplot not found!\n");
        return 1;
    }

    fprintf(gp, "set terminal wxt size 1200,800\n");
    fprintf(gp, "set title 'Growth of Functions'\n");
    fprintf(gp, "set xlabel 'n'\n");
    fprintf(gp, "set ylabel 'f(n)'\n");
    fprintf(gp, "set logscale y\n");
    fprintf(gp, "set format y '10^{%%L}'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key outside right\n");
    fprintf(gp, "set key font ',9'\n");

    fprintf(gp,
        "plot "
        "'functions.dat' using 1:2 with lines lw 2 lc rgb 'red' title '1/n',"
        "'functions.dat' using 1:3 with lines lw 2 lc rgb 'orange' title 'log2(n)',"
        "'functions.dat' using 1:4 with lines lw 2 lc rgb 'gold' title '12sqrt(n)',"
        "'functions.dat' using 1:5 with lines lw 2 lc rgb 'green' title '50sqrt(n)',"
        "'functions.dat' using 1:6 with lines lw 2 lc rgb 'dark-green' title 'n^0.51',"
        "'functions.dat' using 1:7 with lines lw 2 lc rgb 'cyan' title 'nlog2(n)',"
        "'functions.dat' using 1:8 with lines lw 2 lc rgb 'blue' title '100n^2+6n',"
        "'functions.dat' using 1:9 with lines lw 2 lc rgb 'dark-blue' title 'n^2-324',"
        "'functions.dat' using 1:10 with lines lw 2 lc rgb 'purple' title '2n^3',"
        "'functions.dat' using 1:11 with lines lw 2 lc rgb 'magenta' title '2^32*n',"
        "'functions.dat' using 1:12 with lines lw 2 lc rgb 'brown' title 'n^(log2 n)',"
        "'functions.dat' using 1:13 with lines lw 2 lc rgb 'black' title '3^n'\n");

    pclose(gp);

    printf("\nGraph plotted successfully.\n");

    return 0;
}