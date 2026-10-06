#include <stdio.h>

int main() {
    int n;
    int totalCoins, minMoves;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    totalCoins = n * (n + 1) / 2;

    minMoves = totalCoins / 3;

    printf("Total coins = %d\n", totalCoins);
    printf("Minimum moves = %d\n", minMoves);

    return 0;
}