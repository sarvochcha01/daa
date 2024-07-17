#include <stdio.h>
#include <time.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyds(int cost[10][10], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

int main()
{
    int n, cost[10][10], i, j;
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("Enter the cost matrix of the graph:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }

    floyds(cost, n);

    printf("The shortest path matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] == 9999)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the no of vertices of the graph
// 4
// Enter the cost matrix of the graph
// 0 999 3 999
// 2 0 999 999
// 999 7 0 1
// 6 999 999 0
// The all pairs shortest path is
// 0 10 3 4
// 2 0 5 6
// 7 7 0 1
// 6 16 9 0