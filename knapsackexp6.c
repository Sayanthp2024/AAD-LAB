#include <stdio.h>

int main() {
    int i, n;
    float w[10], p[10], cap, profit = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%f %f", &w[i], &p[i]);

    scanf("%f", &cap);

    for (i = 0; i < n; i++) {
        if (w[i] <= cap) {
            profit += p[i];
            cap -= w[i];
        } else {
            profit += (p[i] / w[i]) * cap;
            break;
        }
    }

    printf("Maximum profit = %.2f", profit);
    return 0;
}