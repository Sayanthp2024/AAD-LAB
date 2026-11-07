#include <stdio.h>
#include <stdlib.h>

int x[20], n, count = 0;

int place(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (x[i] == col || abs(x[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row)
{
    int col;

    if (row > n)
    {
        count++;

        printf("\nSolution %d:\n", count);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (x[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        return;
    }

    for (col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            x[row] = col;
            queen(row + 1);
        }
    }
}

int main()
{
    printf("Enter N: ");
    scanf("%d", &n);

    queen(1);

    printf("\nTotal solutions = %d\n", count);

    return 0;
}
