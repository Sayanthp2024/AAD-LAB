
#include <stdio.h>

int a[10][10], visited[10], n;
int min = 9999, path[10], best[10];

void tsp(int city, int count, int cost)
{
    int i;

    path[count - 1] = city;

    // All cities visited
    if (count == n)
    {
        if (a[city][0] > 0 && cost + a[city][0] < min)
        {
            min = cost + a[city][0];

            for (i = 0; i < n; i++)
                best[i] = path[i];
        }
        return;
    }

    // Visit next city
    for (i = 1; i < n; i++)
    {
        if (visited[i] == 0 && a[city][i] > 0)
        {
            visited[i] = 1;

            tsp(i, count + 1, cost + a[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    visited[0] = 1;

    tsp(0, 1, 0);

    if (min == 9999)
        printf("No tour possible");
    else
    {
        printf("\nMinimum cost = %d", min);

        printf("\nOptimal path: ");

        for (i = 0; i < n; i++)
            printf("%d -> ", best[i]);

        printf("0\n");
    }

    return 0;
}
