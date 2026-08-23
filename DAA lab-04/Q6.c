#include <stdio.h>
#include <stdlib.h>

struct Event {
    int point;
    int value;
};

int compare(const void *a, const void *b) {
    struct Event *x = (struct Event *)a;
    struct Event *y = (struct Event *)b;

    return x->point - y->point;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Event e[2 * n];

    for (int i = 0; i < n; i++) {

        int l, r;

        printf("Enter interval: ");
        scanf("%d %d", &l, &r);

        e[2 * i].point = l;
        e[2 * i].value = 1;

        e[2 * i + 1].point = r;
        e[2 * i + 1].value = -1;
    }

    // Sort events
    qsort(e, 2 * n, sizeof(struct Event), compare);

    int count = 0;
    int maxCount = 0;
    int answer = 0;

    for (int i = 0; i < 2 * n; i++) {

        count = count + e[i].value;

        if (count > maxCount) {
            maxCount = count;
            answer = e[i].point;
        }
    }

    printf("\nPoint = %d", answer);
    printf("\nMaximum intervals = %d\n", maxCount);

    return 0;
}