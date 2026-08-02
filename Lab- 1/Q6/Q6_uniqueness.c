#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));

    int n, range;

    printf("Enter the number of random numbers (n): ");
    scanf("%d", &n);

    printf("Enter the range of random numbers (e.g. 100): ");
    scanf("%d", &range);

    int *arr = malloc(n * sizeof(int));
    int *seen = calloc(range, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }

    printf("\nGenerated numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int found = 0;

    printf("\nDuplicate values: ");

    for (int i = 0; i < n; i++) {
        if (seen[arr[i]] == 1) {
            printf("%d ", arr[i]);
            found = 1;
            seen[arr[i]] = 2; // mark as already printed, avoid repeating same duplicate value
        } else if (seen[arr[i]] == 0) {
            seen[arr[i]] = 1;
        }
    }

    if (found == 0) {
        printf("None");
    }
    printf("\n");

    if (found == 1) {
        printf("\nResult: Duplicates found!\n");
    } else {
        printf("\nResult: All elements are unique.\n");
    }

    free(arr);
    free(seen);

    return 0;
}