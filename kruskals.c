#include<stdio.h>
#include<stdlib.h>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, g[10][10], parent[10];

int findParent(int);
int unionVertices(int, int);

int findParent(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionVertices(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    printf("enter number of vertices:");
    scanf("%d", &n);
    printf("enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 0)
                g[i][j] = 999;
        }
    printf("MST:\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (g[i][j] < min) {
                    min = g[i][j];
                    u = i;
                    v = j;
                }

        u = findParent(u);
        v = findParent(v);

        if (unionVertices(u, v)) {
            printf("%d edge(%d,%d)=%d\n", ne++, u, v, min);
            mincost += min;
        }
        g[u][v] = g[v][u] = 999;
    }
    printf("minimum cost=%d", mincost);
    return 0;
}
