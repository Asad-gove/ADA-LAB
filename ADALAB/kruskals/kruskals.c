#include <stdio.h>

int parent[20];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[20][20];
    int mincost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Edges in MST:\n");

    while (edges < n - 1) {
        int min = 9999, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if (uni(u, v)) {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = 9999;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
