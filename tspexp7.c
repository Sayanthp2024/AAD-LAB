#include <stdio.h>

int a[10][10], visited[10], n, min = 9999;

void tsp(int city, int count, int cost) {
    int i;

    if (count == n && a[city][0] > 0) {
        if (cost + a[city][0] < min)
            min = cost + a[city][0];
        return;
    }

    for (i = 1; i < n; i++) {
        if (!visited[i] && a[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, cost + a[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    visited[0] = 1;
    tsp(0, 1, 0);

    printf("Minimum cost = %d\n", min);
    return 0;
}