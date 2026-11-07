
#include <stdio.h>

int main()
{
    int a[10][10], indeg[10] = {0};
    int q[10], n, i, j;
    int front = 0, rear = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            if(a[i][j] == 1)
                indeg[j]++;
        }
    }

    // Insert vertices with indegree 0
    for(i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
            q[rear++] = i;
    }

    printf("Topological order: ");

    while(front < rear)
    {
        int v = q[front++];

        printf("%d ", v);
        count++;

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1)
            {
                indeg[i]--;

                if(indeg[i] == 0)
                    q[rear++] = i;
            }
        }
    }

    if(count != n)
        printf("\nGraph contains a cycle");

    return 0;
}
