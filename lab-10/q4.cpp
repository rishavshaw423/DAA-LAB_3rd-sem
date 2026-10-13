
#include <stdio.h>

#define MAX 100005
#define MAXE 200005

int parent[MAX], sz[MAX], active[MAX];
long long weight[MAX], sum[MAX], answer[MAX];

int head[MAX], to[2 * MAXE], nextEdge[2 * MAXE];
int edgeCount = 0;

void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

long long unite(int u, int v, long long best) {
    u = find(u);
    v = find(v);

    if (u == v)
        return best;

    if (sz[u] < sz[v]) {
        int t = u;
        u = v;
        v = t;
    }

    parent[v] = u;
    sz[u] += sz[v];
    sum[u] += sum[v];

    if (sum[u] > best)
        best = sum[u];

    return best;
}

int main(void) {
    int n, m;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || n >= MAX || m < 0 || m > MAXE) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        head[i] = -1;
        parent[i] = i;
        sz[i] = 1;
        active[i] = 0;
        sum[i] = 0;
    }

    printf("Enter vertex weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%lld", &weight[i]);

    printf("Enter edges (u v), 0-based:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge.\n");
            return 1;
        }

        addEdge(u, v);
        addEdge(v, u);
    }

    int order[MAX];
    int deleted[MAX] = {0};

    printf("Enter deletion order (0-based vertices):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &order[i]);

        if (order[i] < 0 || order[i] >= n || deleted[order[i]]) {
            printf("Invalid deletion permutation.\n");
            return 1;
        }

        deleted[order[i]] = 1;
    }

    long long best = 0;

    for (int i = n - 1; i >= 0; i--) {
        /* Record graph state after deletion i+1. */
        answer[i] = best;

        int u = order[i];
        active[u] = 1;
        parent[u] = u;
        sz[u] = 1;
        sum[u] = weight[u];

        if (sum[u] > best)
            best = sum[u];

        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            int v = to[e];

            if (active[v])
                best = unite(u, v, best);
        }
    }

    printf("Maximum component weights after each deletion:\n");
    for (int i = 0; i < n; i++)
        printf("%lld\n", answer[i]);

    return 0;
}