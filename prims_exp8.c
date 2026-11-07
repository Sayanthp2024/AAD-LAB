
#include <stdio.h>

int main()
{
    int a[10][10], visited[10] = {0};
    int n, i, j, k, min, u, v, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    visited[0] = 1;

    for(k = 0; k < n-1; k++)
    {
        min = 9999;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && a[i][j] > 0 && a[i][j] < min)
                    {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);

        cost = cost + min;
        visited[v] = 1;
    }

    printf("Minimum cost = %d\n", cost);

    return 0;
}
