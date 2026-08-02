#include <stdio.h>

int find_the_switch(int arr[], int total_elements) {
    int start = 0;
    int end = total_elements - 1;
    int best_guess = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == 1) {
            best_guess = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return best_guess;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array (0 or 1): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int total_elements = n;

    int switch_index = find_the_switch(arr, total_elements);

    if (switch_index != -1) {
        printf("The 1s start exactly at index: %d\n", switch_index);
    } else {
        printf("The array is entirely filled with 0s.\n");
    }

    return 0;
}