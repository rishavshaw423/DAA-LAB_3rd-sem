#include <stdio.h>
#include <stdlib.h>

long long binary_count = 0;
long long ternary_count = 0;

/* ---------------- BINARY SEARCH ---------------- */

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        binary_count++;

        if (arr[mid] == key)
            return mid;

        binary_count++;

        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

/* ---------------- TERNARY SEARCH ---------------- */

int ternarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int third = (high - low) / 3;

        int mid1 = low + third;
        int mid2 = high - third;

        ternary_count++;

        if (arr[mid1] == key)
            return mid1;

        ternary_count++;

        if (arr[mid2] == key)
            return mid2;

        ternary_count++;

        if (key < arr[mid1])
        {
            high = mid1 - 1;
        }
        else if (key > arr[mid2])
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

/* ---------------- MAIN ---------------- */

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid value of n.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements in sorted order:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    /* ---------------- PERFORM BINARY SEARCH ---------------- */

    binary_count = 0;

    int binary_result = binarySearch(arr, n, key);

    /* ---------------- PERFORM TERNARY SEARCH ---------------- */

    ternary_count = 0;

    int ternary_result = ternarySearch(arr, n, key);

    /* ---------------- DISPLAY RESULT ---------------- */

    printf("\n====================================\n");
    printf("            SEARCH RESULT\n");
    printf("====================================\n");

    if (binary_result != -1)
        printf("Binary Search  : Found at index %d\n",
               binary_result);
    else
        printf("Binary Search  : Element not found\n");

    if (ternary_result != -1)
        printf("Ternary Search : Found at index %d\n",
               ternary_result);
    else
        printf("Ternary Search : Element not found\n");

    printf("\nBinary comparisons  = %lld\n",
           binary_count);

    printf("Ternary comparisons = %lld\n",
           ternary_count);

    printf("====================================\n");

    /* ---------------- CREATE DATA FILE ---------------- */

    FILE *fp = fopen("q1.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating q1.txt\n");

        free(arr);

        return 1;
    }

    fprintf(fp, "# n Binary Ternary\n");

    int sizes[] =
        {
            10,
            20,
            50,
            100,
            200,
            500,
            1000,
            2000,
            5000,
            10000,
            20000,
            50000,
            100000,
            200000,
            500000,
            1000000};

    int total_sizes =
        sizeof(sizes) / sizeof(sizes[0]);

    int max_n = sizes[total_sizes - 1];

    int *test = malloc(max_n * sizeof(int));

    if (test == NULL)
    {
        printf("Memory allocation failed.\n");

        fclose(fp);
        free(arr);

        return 1;
    }

    /* ---------------- GENERATE EXPERIMENTAL DATA ---------------- */

    for (int i = 0; i < total_sizes; i++)
    {
        int size = sizes[i];

        /* Create sorted array */

        for (int j = 0; j < size; j++)
        {
            test[j] = j;
        }

        /* Search for last element */

        int search_key = size - 1;

        binary_count = 0;
        ternary_count = 0;

        binarySearch(test, size, search_key);

        ternarySearch(test, size, search_key);

        fprintf(fp,
                "%d %lld %lld\n",
                size,
                binary_count,
                ternary_count);
    }

    fclose(fp);

    /* ---------------- FREE MEMORY ---------------- */

    free(test);
    free(arr);

    printf("\nq1.txt created successfully.\n");

    /* =========================================================
       CREATE GNUPLOT SCRIPT AUTOMATICALLY
       ========================================================= */

    FILE *gp = fopen("q1.gnu", "w");

    if (gp == NULL)
    {
        printf("Error creating q1.gnu\n");
        return 1;
    }

    fprintf(gp,
            "set terminal wxt size 1000,700\n"
            "set title 'Binary Search vs Ternary Search'\n"
            "set xlabel 'Input Size (n)'\n"
            "set ylabel 'Number of Comparisons'\n"
            "set grid\n"
            "set key outside\n"
            "set logscale x\n"
            "plot 'q1.txt' using 1:2 with linespoints title 'Binary Search O(log2 n)', \\\n"
            "     'q1.txt' using 1:3 with linespoints title 'Ternary Search O(log3 n)'\n"
            "pause -1\n");

    fclose(gp);

    printf("q1.gnu created successfully.\n");

    /* =========================================================
       RUN GNUPLOT AUTOMATICALLY
       ========================================================= */

    printf("\nOpening Gnuplot graph...\n");

    int result = system("gnuplot -persist q1.gnu");

    if (result != 0)
    {
        printf("\nError: Gnuplot could not be executed.\n");
        printf("Make sure Gnuplot is installed and added to PATH.\n");
    }

    return 0;
}