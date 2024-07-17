#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, j, i, capacity;
    int weight[20], value[20];
    int v[50][50], w;

    printf("\n\n\t\tEnter the number of items: ");
    scanf("%d", &n);
    printf("\t\t--------------------------------\n");
    printf("\n\t\t Enter : WEIGHTS - VALUES \n");
    printf("\t\t--------------------------------\n");
    for (i = 1; i <= n; i++)
    {
        printf("Item %d:\n", i);
        printf("Weight: ");
        scanf("%d", &weight[i]);
        printf("Value: ");
        scanf("%d", &value[i]);
    }
    printf("\t\t--------------------------------\n");
    printf("\t\tEnter the capacity of Knapsack: ");
    scanf("%d", &capacity);
    printf("\t\t--------------------------------\n\t\t");

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (j - weight[i] >= 0)
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + value[i]);
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
            printf("%4d", v[i][j]);
        }
        printf("\n\t\t");
    }

    w = capacity;
    printf("The items in the knapsack:\n");
    for (i = n; i > 0; i--)
    {
        if (v[i][w] == v[i - 1][w])
        {
            continue;
        }
        else
        {
            w = w - weight[i];
            printf("%3d", i);
        }
    }
    printf("\n\t\tTotal Profit = %d\n", v[n][capacity]);

    return 0;
}

// enter the no of items 4
// enter the wt of 4 item: 2 1 3 2
// enter the values(profit) : 12 10 20 15
// enter the knapsack capacity 5
// the o/p is
// 0 0 0 0 0 0
// 0 0 12 12 12 12
// 0 10 12 22 22 22
// 0 10 12 22 30 32
// 0 10 15 25 30 37
// the o.s is37