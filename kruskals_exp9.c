
#include <stdio.h>

int parent[10], a[10][10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

int main()
{
    int n, i, j, u, v, min, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Selected edges:\n");

    for (int k = 0; k < n - 1; k++)
    {
        min = 999;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (a[i][j] > 0 && a[i][j] < min)
                {
                    u = i;
                    v = j;
                    min = a[i][j];
                }

        if (min == 999)
            break;

        i = find(u);
        j = find(v);

        if (i != j)
        {
            printf("%d - %d : %d\n", u, v, min);
            cost += min;
            parent[i] = j;
        }

        a[u][v] = a[v][u] = 0;
    }

    printf("Minimum cost = %d\n", cost);

    return 0;
}
