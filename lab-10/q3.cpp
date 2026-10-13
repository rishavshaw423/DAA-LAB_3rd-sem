
#include <stdio.h>

#define MAX 100005

int parent[MAX], sz[MAX];
long long sum[MAX], weight[MAX];

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
    sum[u] += sum[v];
}

long long getMaximum(int n, int K) {
    long long best = 0;

    for (int i = 0; i < n; i++) {
        if (find(i) == i && sz[i] <= K && sum[i] > best)
            best = sum[i];
    }

    return best;
}

int main(void) {
    int n, m, K;

    printf("Enter vertices, edges, and K: ");
    scanf("%d %d %d", &n, &m, &K);

    if (n <= 0 || n >= MAX || m < 0 || K < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Weight of vertex %d: ", i);
        scanf("%lld", &weight[i]);

        parent[i] = i;
        sz[i] = 1;
        sum[i] = weight[i];
    }

    printf("Enter edges (u v), using 0-based vertices:\n");

    printf("Initial maximum = %lld\n", getMaximum(n, K));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge.\n");
            continue;
        }

        unite(u, v);

        printf("After edge %d: maximum = %lld\n",
               i + 1, getMaximum(n, K));
    }

    return 0;
}