// #include <stdio.h>
// #include <math.h>

// #define MAX 1000

// int main()
// {
//     FILE *fp;

//     fp = fopen("merge_sort.txt", "w");

//     if(fp == NULL)
//     {
//         printf("Error opening file.\n");
//         return 1;
//     }

//     fprintf(fp, "# n MergeSort ModifiedMergeSort\n");

//     for(int n = 1; n <= MAX; n++)
//     {
//         /*
//            Ordinary Merge Sort:

//            T(n) = 2T(n/2) + O(n)

//            Therefore:
//            T(n) = O(n log2 n)
//         */

//         double mergeSort;

//         if(n == 1)
//             mergeSort = 1;
//         else
//             mergeSort = n * log2(n);

//         /*
//            Modified Merge Sort:

//            Divide the array into 3 parts.
//            Recursively sort each part.
//            Three-way merge takes O(n).

//            T(n) = 3T(n/3) + O(n)

//            Therefore:
//            T(n) = O(n log3 n)

//            log3(n) = log2(n) / log2(3)
//         */

//         double modifiedMergeSort;

//         if(n == 1)
//             modifiedMergeSort = 1;
//         else
//             modifiedMergeSort = n * (log2(n) / log2(3));

//         fprintf(fp,
//             "%d %.4lf %.4lf\n",
//             n,
//             mergeSort,
//             modifiedMergeSort);
//     }

//     fclose(fp);

//     printf("merge_sort.txt created successfully.\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main()
{
    FILE *fp;

    /* Create data file */
    fp = fopen("merge_sort.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "# n MergeSort ModifiedMergeSort\n");

    for (int n = 1; n <= MAX; n++)
    {
        /*
            Ordinary Merge Sort:
            T(n) = 2T(n/2) + O(n)
            T(n) = O(n log2 n)
        */

        double mergeSort;

        if (n == 1)
            mergeSort = 1;
        else
            mergeSort = n * log2(n);

        /*
            Modified Merge Sort:
            T(n) = 3T(n/3) + O(n)
            T(n) = O(n log3 n)

            log3(n) = log2(n) / log2(3)
        */

        double modifiedMergeSort;

        if (n == 1)
            modifiedMergeSort = 1;
        else
            modifiedMergeSort = n * (log2(n) / log2(3));

        fprintf(fp, "%d %.4lf %.4lf\n",
                n, mergeSort, modifiedMergeSort);
    }

    fclose(fp);

    printf("merge_sort.txt created successfully.\n");

    /*
        Create Gnuplot script
    */

    FILE *gp = fopen("plot.plt", "w");

    if (gp == NULL)
    {
        printf("Error creating Gnuplot script.\n");
        return 1;
    }

    fprintf(gp,
            "set terminal pngcairo size 1000,700 enhanced\n"
            "set output 'merge_sort.png'\n"
            "set title 'Merge Sort vs Modified Merge Sort'\n"
            "set xlabel 'Input Size (n)'\n"
            "set ylabel 'Growth'\n"
            "set grid\n"
            "set key outside\n"
            "plot "
            "'merge_sort.txt' using 1:2 with lines lw 2 "
            "title 'Merge Sort O(n log_2 n)', "
            "'merge_sort.txt' using 1:3 with lines lw 2 "
            "title 'Modified Merge Sort O(n log_3 n)'\n"
            "set output\n");

    fclose(gp);

    /*
        Run Gnuplot
    */

    printf("Generating graph...\n");

    int result = system("gnuplot plot.plt");

    if (result != 0)
    {
        printf("Error: Gnuplot could not be executed.\n");
        printf("Make sure Gnuplot is installed and added to PATH.\n");
        return 1;
    }

    /*
        Open generated PNG automatically
        Windows command
    */

    system("start \"\" \"merge_sort.png\"");

    printf("Graph generated and opened successfully.\n");

    return 0;
}