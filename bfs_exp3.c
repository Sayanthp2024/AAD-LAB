#include <stdio.h>

int a[10][10], visited[10], queue[10];
int n, front = 0, rear = -1;

void bfs(int start)
{
    int v, i;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
