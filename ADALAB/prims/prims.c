#include <stdio.h>

int main()
{
    int n, cost[10][10];
    int visited[10] = {0};
    int min, u, v, edges = 0;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;   // No edge
        }
    }

    visited[0] = 1;  // Start from vertex 0

    printf("\nEdges in MST:\n");

    while(edges < n - 1)
    {
        min = 999;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);

        mincost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nTotal minimum Cost : %d\n", mincost);

    return 0;
}