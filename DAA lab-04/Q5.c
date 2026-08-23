#include <stdio.h>

struct Interval {
    int start;
    int end;
};

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval a[n];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].start, &a[i].end);
    }

    // Simple sorting
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (a[i].start > a[j].start) {

                struct Interval temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int start = a[0].start;
    int end = a[0].end;

    printf("Merged intervals:\n");

    for (int i = 1; i < n; i++) {

        if (a[i].start <= end) {

            if (a[i].end > end)
                end = a[i].end;

        } else {

            printf("(%d,%d) ", start, end);

            start = a[i].start;
            end = a[i].end;
        }
    }

    printf("(%d,%d)\n", start, end);

    return 0;
}