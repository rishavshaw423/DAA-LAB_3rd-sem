#include <iostream>
using namespace std;

#define MAX 100

int a[MAX];

long long totalCost = 0;
int reversalCount = 0;

/* Reverse elements from l to r */
void reverse(int l, int r)
{
    if (l >= r)
        return;

    int i = l;
    int j = r;

    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    /* Cost of one reversal = length of reversed part */
    totalCost += (r - l + 1);
    reversalCount++;
}

int partitionArray(int l, int r, int mid)
{
    if (l == r)
    {
        if (a[l] <= mid)
            return 1;
        else
            return 0;
    }

    int m = (l + r) / 2;

    /* Partition left half */
    int leftCount = partitionArray(l, m, mid);

    /* Partition right half */
    int rightCount = partitionArray(m + 1, r, mid);

    int leftSize = m - l + 1;

    int leftLargerStart = l + leftCount;
    int rightSmallerEnd = m + rightCount;

    if (leftLargerStart <= m && m + 1 <= rightSmallerEnd)
    {
        /* Three reversals perform a rotation */
        reverse(leftLargerStart, m);
        reverse(m + 1, rightSmallerEnd);
        reverse(leftLargerStart, rightSmallerEnd);
    }

    return leftCount + rightCount;
}

void sortPermutation(int l, int r, int low, int high)
{
    if (l >= r || low >= high)
        return;

    /* Middle value */
    int mid = (low + high) / 2;

    int count = partitionArray(l, r, mid);

    int boundary = l + count;

    /* Sort left part */
    sortPermutation(l, boundary - 1, low, mid);

    /* Sort right part */
    sortPermutation(boundary, r, mid + 1, high);
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter permutation (1 to " << n << "):" << endl;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nOriginal permutation:" << endl;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    sortPermutation(0, n - 1, 1, n);

    cout << "\n\nSorted permutation:" << endl;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n\nNumber of reversals = "
         << reversalCount;

    cout << "\nTotal reversal cost = "
         << totalCost << endl;

    return 0;
}