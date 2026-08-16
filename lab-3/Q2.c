#include <stdio.h>
#include <stdlib.h>

/*
    Returns:
    -1 : left group is lighter
     0 : both groups have equal weight
     1 : right group is lighter
*/
int weigh(int coins[], int left, int mid, int right)
{
    int leftWeight = 0;
    int rightWeight = 0;

    for (int i = left; i <= mid; i++)
        leftWeight += coins[i];

    for (int i = mid + 1; i <= right; i++)
        rightWeight += coins[i];

    if (leftWeight < rightWeight)
        return -1;

    if (leftWeight > rightWeight)
        return 1;

    return 0;
}

/*
    Find the defective coin using
    Divide and Conquer.
*/
int findDefective(int coins[], int left, int right, int normalWeight)
{
    /* Only one coin remains */
    if (left == right)
    {
        if (coins[left] < normalWeight)
            return left;

        return -1;
    }

    int n = right - left + 1;

    /*
        Odd number of coins:
        keep one coin aside.
    */
    if (n % 2 != 0)
    {
        int extra = right;

        int mid = left + (n - 1) / 2 - 1;

        int result = weigh(coins, left, mid, extra - 1);

        if (result == -1)
        {
            return findDefective(
                coins, left, mid, normalWeight
            );
        }

        if (result == 1)
        {
            return findDefective(
                coins, mid + 1, extra - 1, normalWeight
            );
        }

        /*
            Both groups have equal weight.
            Therefore, only the extra coin
            can possibly be defective.
        */
        if (coins[extra] < normalWeight)
            return extra;

        return -1;
    }

    /*
        Even number of coins:
        divide into two equal groups.
    */
    int mid = left + (right - left) / 2;

    int result = weigh(coins, left, mid, right);

    if (result == -1)
    {
        return findDefective(
            coins, left, mid, normalWeight
        );
    }

    if (result == 1)
    {
        return findDefective(
            coins, mid + 1, right, normalWeight
        );
    }

    /*
        Equal weight means there is no
        defective coin in these groups.
    */
    return -1;
}

int main()
{
    int n;
    int normalWeight;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of coins.\n");
        return 1;
    }

    printf("Enter weight of a normal coin: ");
    scanf("%d", &normalWeight);

    int *coins = (int *)malloc(n * sizeof(int));

    if (coins == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter weights of %d coins:\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Weight of coin %d: ", i + 1);
        scanf("%d", &coins[i]);

        /*
            A coin cannot weigh more than
            the normal coin according to Q2.
        */
        if (coins[i] > normalWeight)
        {
            printf("\nInvalid input!\n");
            printf("Coin %d weighs %d, which is greater than "
                   "the normal weight %d.\n",
                   i + 1, coins[i], normalWeight);

            printf("No further input will be taken.\n");

            free(coins);
            return 1;
        }
    }

    /*
        Find defective coin.
    */
    int result =
        findDefective(coins, 0, n - 1, normalWeight);

    printf("\n========== RESULT ==========\n");

    if (result == -1)
    {
        printf("No defective coin found.\n");
    }
    else
    {
        printf("Defective coin = Coin %d\n", result + 1);
        printf("Defective coin weight = %d\n", coins[result]);
        printf("Normal coin weight = %d\n", normalWeight);
    }

    free(coins);

    return 0;
}