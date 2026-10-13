#include <stdio.h>

int main() {
    int a[10][10], visited[10] = {0};
    int q[10], n, start, front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    q[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
