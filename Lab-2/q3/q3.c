#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_K 100

/*
    Merge two sorted arrays
*/
void mergeTwoArrays(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];
}

/*
    METHOD 1

    Merge first two arrays.
    Then merge result with third array.
    Continue until all k arrays are merged.
*/
void method1(int **arrays, int k, int n)
{
    int currentSize = n;

    int *result = (int *)malloc(sizeof(int) * n * k);

    for (int i = 0; i < n; i++)
        result[i] = arrays[0][i];

    for (int i = 1; i < k; i++)
    {
        int newSize = currentSize + n;

        int *temp = (int *)malloc(sizeof(int) * newSize);

        mergeTwoArrays(
            result,
            currentSize,
            arrays[i],
            n,
            temp);

        free(result);

        result = temp;
        currentSize = newSize;
    }

    free(result);
}

/*
    METHOD 2

    Merge arrays pairwise.
*/
void method2(int **arrays, int k, int n)
{
    int currentK = k;
    int **current = arrays;

    while (currentK > 1)
    {
        int newK = (currentK + 1) / 2;

        int **next =
            (int **)malloc(sizeof(int *) * newK);

        int index = 0;

        for (int i = 0; i < currentK; i += 2)
        {
            if (i + 1 < currentK)
            {
                int *merged =
                    (int *)malloc(sizeof(int) * n * 2);

                mergeTwoArrays(
                    current[i],
                    n,
                    current[i + 1],
                    n,
                    merged);

                next[index++] = merged;
            }
            else
            {
                int *remaining =
                    (int *)malloc(sizeof(int) * n);

                for (int j = 0; j < n; j++)
                    remaining[j] = current[i][j];

                next[index++] = remaining;
            }
        }

        if (current != arrays)
        {
            for (int i = 0; i < currentK; i++)
                free(current[i]);

            free(current);
        }

        current = next;
        currentK = newK;
    }

    if (current != arrays)
    {
        free(current[0]);
        free(current);
    }
}

int main()
{
    FILE *fp;

    /*
        Create data file
    */

    fp = fopen("q3_merge.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp,
            "# k Method1_O(nk^2) Method2_O(nklogk)\n");

    int n = 10;

    for (int k = 2; k <= MAX_K; k++)
    {
        /*
            Method 1:

            O(nk^2)
        */

        double method1Growth =
            n * (double)k * (k + 1) / 2.0;

        /*
            Method 2:

            O(nk log2(k))
        */

        double method2Growth =
            n * k * log2(k);

        fprintf(fp,
                "%d %.4lf %.4lf\n",
                k,
                method1Growth,
                method2Growth);
    }

    fclose(fp);

    /*
        Create sample sorted arrays
        and execute both methods once.
    */

    int k = 4;

    int **arrays =
        (int **)malloc(sizeof(int *) * k);

    for (int i = 0; i < k; i++)
    {
        arrays[i] =
            (int *)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++)
        {
            arrays[i][j] =
                i * n + j;
        }
    }

    method1(arrays, k, n);
    method2(arrays, k, n);

    for (int i = 0; i < k; i++)
        free(arrays[i]);

    free(arrays);

    /*
        Create Gnuplot script
    */

    FILE *gp = fopen("q3_plot.plt", "w");

    if (gp == NULL)
    {
        printf("Error creating Gnuplot script.\n");
        return 1;
    }

    fprintf(gp,
            "set terminal pngcairo size 1000,700 enhanced\n"
            "set output 'q3_merge.png'\n"
            "\n"
            "set title 'Comparison of Two K-Way Merge Methods'\n"
            "set xlabel 'Number of Arrays (k)'\n"
            "set ylabel 'Growth / Operations'\n"
            "\n"
            "set grid\n"
            "set key outside\n"
            "\n"
            "plot "
            "'q3_merge.txt' using 1:2 with lines lw 2 "
            "title 'Method 1 O(nk^2)', "
            "'q3_merge.txt' using 1:3 with lines lw 2 "
            "title 'Method 2 O(nk log_2 k)'\n"
            "\n"
            "set output\n");

    fclose(gp);

    /*
        Run Gnuplot automatically
    */

    printf("q3_merge.txt created successfully.\n");
    printf("Generating Gnuplot graph...\n");

    int result = system("gnuplot q3_plot.plt");

    if (result != 0)
    {
        printf("\nError: Gnuplot could not be executed.\n");
        printf("Make sure Gnuplot is installed and added to PATH.\n");
        return 1;
    }

    /*
        Open PNG automatically in Windows
    */

    system("start \"\" \"q3_merge.png\"");

    printf("Graph generated successfully.\n");

    return 0;
}