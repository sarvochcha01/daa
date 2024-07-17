#include <stdio.h>

void warshall(int cost[10][10], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cost[i][j] = cost[i][j] || (cost[i][k] && cost[k][j]);
            }
        }
    }
}

int main()
{
    int n, cost[10][10], i, j;
    printf("Enter the number of vertices of the graph\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    warshall(cost, n);

    printf("The path matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Enter the no of vertices of graph
// 4
// Enter adjacency matrix of graph
// 0 1 0 0
// 0 0 0 1
// 0 0 0 0
// 1 0 1 0
// the path matrix is:
// 1 1 1 1
// 1 1 1 1
// 0 0 0 0
// 1 1 1 1