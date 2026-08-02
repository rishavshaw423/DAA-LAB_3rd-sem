#include <stdio.h>
#include <stdlib.h>

long long moveCount = 0;

void TOH(int n, char L, char R, char M) {
    if (n == 1) {
        moveCount++;
        return;
    }

    TOH(n - 1, L, M, R);
    moveCount++;
    TOH(n - 1, M, R, L);
}

int main(void) {
    int d;

    printf("Enter the number of disks: ");
    scanf("%d", &d);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    if (gnuplotPipe == NULL) {
        printf("Error: GNUplot not found. Please install GNUplot to view the plot.\n");
        return 1;
    }

    fprintf(gnuplotPipe, "set title 'Tower of Hanoi: Total Moves vs Number of Disks'\n");
    fprintf(gnuplotPipe, "set xlabel 'Number of Disks (n)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Total Moves Required'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot '-' with linespoints title 'Simulation Data' lw 2 pt 7 lc rgb 'red'\n");

    for (int n = 1; n <= d; n++) {
        moveCount = 0;

        TOH(n, 'L', 'R', 'M');

        fprintf(gnuplotPipe, "%d %lld\n", n, moveCount);
    }

    fprintf(gnuplotPipe, "e\n");

    pclose(gnuplotPipe);

    printf("Simulation complete. GNUplot window opened successfully.\n");
    return 0;
}