
#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int parent[MAX], sz[MAX], parity[MAX];

int find(int x) {
    if (parent[x] != x) {
        int oldParent = parent[x];
        parent[x] = find(oldParent);
        parity[x] ^= parity[oldParent];
    }
    return parent[x];
}

/* Returns 1 if edge can be accepted, 0 otherwise. */
int addEdge(int u, int v) {
    int ru = find(u);
    int pu = parity[u];

    int rv = find(v);
    int pv = parity[v];

    if (ru == rv) {
        /* Endpoints must have opposite colors. */
        return (pu ^ pv) == 1;
    }

    /* Attach smaller component to larger component. */
    if (sz[ru] < sz[rv]) {
        parent[ru] = rv;
        parity[ru] = pu ^ pv ^ 1;
        sz[rv] += sz[ru];
    } else {
        parent[rv] = ru;
        parity[rv] = pu ^ pv ^ 1;
        sz[ru] += sz[rv];
    }

    return 1;
}

int main(void) {
    int V, E;

    printf("Enter number of vertices and incoming edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V >= MAX || E < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        sz[i] = 1;
        parity[i] = 0;
    }

    printf("Enter each edge (u v), using vertices 0 to %d:\n",
           V - 1);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge; skipped.\n");
            continue;
        }

        if (addEdge(u, v)) {
            printf("Edge (%d,%d) accepted: graph remains bipartite.\n",
                   u, v);
        } else {
            printf("Edge (%d,%d) rejected: odd cycle detected.\n",
                   u, v);
        }
    }

    return 0;
}