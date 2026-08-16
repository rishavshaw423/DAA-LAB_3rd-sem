#include <stdio.h>

void selectionSort(int A[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        // Find the smallest element
        // in the unsorted part
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    selectionSort(A, n);

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}