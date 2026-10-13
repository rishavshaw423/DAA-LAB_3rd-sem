
#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int parent[MAX], sz[MAX];
int A[MAX], result[MAX];
int componentValues[MAX], componentPositions[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (sz[u] < sz[v]) {
        int t = u;
        u = v;
        v = t;
    }

    parent[v] = u;
    sz[u] += sz[v];
}

int compareInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main(void) {
    int n, m;

    printf("Enter n and number of allowed swaps: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || n >= MAX || m < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter permutation:\n");

    int seen[MAX] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);

        if (A[i] < 1 || A[i] > n || seen[A[i]]) {
            printf("Input is not a valid permutation.\n");
            return 1;
        }

        seen[A[i]] = 1;
        parent[i] = i;
        sz[i] = 1;
    }

    printf("Enter allowed swaps (0-based positions):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid swap positions.\n");
            return 1;
        }

        unite(u, v);
    }

    /*
       Process each connected component.
       Positions are visited in increasing order.
    */
    for (int root = 0; root < n; root++) {
        if (find(root) != root)
            continue;

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == root) {
                componentPositions[count] = i;
                componentValues[count] = A[i];
                count++;
            }
        }

        qsort(componentValues, count, sizeof(int), compareInt);

        /*
           Positions are already in increasing order.
           Assign sorted values to those positions.
        */
        for (int i = 0; i < count; i++)
            result[componentPositions[i]] = componentValues[i];
    }

    printf("Lexicographically smallest permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
    return 0;
}