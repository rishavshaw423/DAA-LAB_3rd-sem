
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 1000005

int parent[MAX_CELLS], sz[MAX_CELLS];
int land[MAX_CELLS];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (sz[a] < sz[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}

int main(void) {
    int R, C, k;

    printf("Enter rows, columns, and number of operations: ");
    scanf("%d %d %d", &R, &C, &k);

    if (R <= 0 || C <= 0 || k < 0 ||
        (long long)R * C > MAX_CELLS) {
        printf("Invalid grid dimensions or operation count.\n");
        return 1;
    }

    int total = R * C;

    for (int i = 0; i < total; i++) {
        parent[i] = i;
        sz[i] = 1;
        land[i] = 0;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int islands = 0;

    printf("Enter land positions (row column), 0-based:\n");

    for (int i = 0; i < k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);

        if (r < 0 || r >= R || c < 0 || c >= C) {
            printf("Invalid position. Islands = %d\n", islands);
            continue;
        }

        int id = r * C + c;

        if (!land[id]) {
            land[id] = 1;
            islands++;

            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                    continue;

                int nid = nr * C + nc;

                if (land[nid] && unite(id, nid))
                    islands--;
            }
        }

        printf("After operation %d: %d island(s)\n",
               i + 1, islands);
    }

    return 0;
}