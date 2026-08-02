#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long bubbleSortOptimized(int arr[], int n) {
    long long comparisons = 0;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    return comparisons;
}

long long bubbleSortStandard(int arr[], int n) {
    long long comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return comparisons;
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main(void) {
    srand((unsigned int)time(NULL));

    int maxSize, step;
    printf("Enter the maximum array size to test: ");
    scanf("%d", &maxSize);
    printf("Enter the step size for increasing array size: ");
    scanf("%d", &step);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        printf("Error: GNUplot not found. Please install GNUplot to view the plot.\n");
        return 1;
    }

    fprintf(gnuplotPipe, "set title 'Bubble Sort: Comparisons vs Array Size'\n");
    fprintf(gnuplotPipe, "set xlabel 'Array Size (n)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Number of Comparisons'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set key top left\n");
    fprintf(gnuplotPipe,
        "plot '-' with linespoints title 'Optimized (early exit)' lw 2 pt 7 lc rgb 'green', "
        "'-' with linespoints title 'Standard (always n-1 passes)' lw 2 pt 7 lc rgb 'red'\n");

    int numPoints = maxSize / step;
    int *sizes = malloc(numPoints * sizeof(int));
    long long *optimizedComparisons = malloc(numPoints * sizeof(long long));
    long long *standardComparisons = malloc(numPoints * sizeof(long long));

    int index = 0;
    for (int n = step; n <= maxSize; n += step) {
        int *original = malloc(n * sizeof(int));
        int *arrCopy1 = malloc(n * sizeof(int));
        int *arrCopy2 = malloc(n * sizeof(int));

        generateRandomArray(original, n);
        copyArray(original, arrCopy1, n);
        copyArray(original, arrCopy2, n);

        long long optComp = bubbleSortOptimized(arrCopy1, n);
        long long stdComp = bubbleSortStandard(arrCopy2, n);

        sizes[index] = n;
        optimizedComparisons[index] = optComp;
        standardComparisons[index] = stdComp;
        index++;

        printf("n = %d | Optimized: %lld comparisons | Standard: %lld comparisons\n", n, optComp, stdComp);

        free(original);
        free(arrCopy1);
        free(arrCopy2);
    }

    for (int i = 0; i < index; i++) fprintf(gnuplotPipe, "%d %lld\n", sizes[i], optimizedComparisons[i]);
    fprintf(gnuplotPipe, "e\n");

    for (int i = 0; i < index; i++) fprintf(gnuplotPipe, "%d %lld\n", sizes[i], standardComparisons[i]);
    fprintf(gnuplotPipe, "e\n");

    pclose(gnuplotPipe);

    free(sizes);
    free(optimizedComparisons);
    free(standardComparisons);

    printf("\nPlot generated successfully.\n");
    return 0;
}