
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W, i, w;
    int wt[11], val[11], dp[11][101];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value:\n");

    for(i = 1; i <= n; i++)
        scanf("%d%d", &wt[i], &val[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    // DP table
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(wt[i] <= w)
                dp[i][w] = max(val[i] + dp[i-1][w-wt[i]],
                               dp[i-1][w]);

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("\nMaximum value = %d", dp[n][W]);

    // Print selected items
    printf("\nSelected items: ");

    w = W;

    for(i = n; i > 0; i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            printf("Item %d ", i);
            w = w - wt[i];
        }
    }

    printf("\n");

    return 0;
}
