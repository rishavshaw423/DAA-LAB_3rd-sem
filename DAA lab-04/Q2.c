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

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

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
    int n, x;
    int i;

    printf("Enter size of sets: ");
    scanf("%d", &n);

    int S1[n], S2[n];

    printf("Enter elements of S1:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &S1[i]);

    printf("Enter elements of S2:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    /* Sort S2 */
    sort(S2, n);

    /* Check every element of S1 */
    for (i = 0; i < n; i++)
    {
        int needed = x - S1[i];

        if (binarySearch(S2, n, needed))
        {
            printf("\nPair found: %d + %d = %d\n",
                   S1[i], needed, x);

            return 0;
        }
    }

    printf("\nNo pair found.\n");

    return 0;
}