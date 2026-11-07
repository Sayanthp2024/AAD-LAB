
#include <stdio.h>

int a[10][10], t[10][10], vis[10];
int stack[10], top = -1, n;

void dfs1(int v)
{
    vis[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(a[v][i] == 1 && vis[i] == 0)
            dfs1(i);
    }

    stack[++top] = v;
}

void dfs2(int v)
{
    vis[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++)
    {
        if(t[v][i] == 1 && vis[i] == 0)
            dfs2(i);
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            t[j][i] = a[i][j];
        }
    }

    // First DFS
    for(i = 0; i < n; i++)
    {
        if(vis[i] == 0)
            dfs1(i);
    }

    // Reset visited array
    for(i = 0; i < n; i++)
        vis[i] = 0;

    printf("Strongly Connected Components:\n");

    // Second DFS
    while(top >= 0)
    {
        int v = stack[top--];

        if(vis[v] == 0)
        {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}
