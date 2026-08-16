#include <stdio.h>

/* Structure to store minimum and maximum */
struct MinMax
{
    int min;
    int max;
};

/* Divide and Conquer function */
struct MinMax findMinMax(int arr[], int low, int high)
{
    struct MinMax result, leftResult, rightResult;

    /* Case 1: Only one element */
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];

        return result;
    }

    /* Case 2: Two elements */
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }

    /* Divide */
    int mid = low + (high - low) / 2;

    /* Conquer */
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    /* Combine: Find minimum */
    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    /* Combine: Find maximum */
    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    return result;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct MinMax result = findMinMax(arr, 0, n - 1);

    printf("\nMinimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);

    return 0;
}