#include <stdio.h>

int main() {
    int a[10][10], v[10] = {0};
    int n, i, j, min, u, w, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    v[0] = 1;

    for (int k = 0; k < n - 1; k++) {
        min = 9999;

        for (i = 0; i < n; i++)
            if (v[i])
                for (j = 0; j < n; j++)
                    if (!v[j] && a[i][j] > 0 && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        w = j;
                    }

        printf("%d - %d : %d\n", u, w, min);
        cost += min;
        v[w] = 1;
    }

    printf("Minimum cost = %d\n", cost);
    return 0;
}