#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binarySearch(int a[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return 1;

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main()
{
    int n, T;
    int i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int S[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &S[i]);

    printf("Enter target T: ");
    scanf("%d", &T);

    /* Sort the array */
    sort(S, n);

    /* Choose first two numbers */
    for (i = 0; i < n - 2; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            int needed = T - S[i] - S[j];

            if (binarySearch(S, j + 1, n - 1, needed))
            {
                printf("\nThree numbers found:\n");
                printf("%d + %d + %d = %d\n",
                       S[i], S[j], needed, T);

                return 0;
            }
        }
    }

    printf("\nNo three numbers found.\n");

    return 0;
}