
#include <stdio.h>

int main()
{
    int n, i, j;
    float w[10], p[10], ratio[10];
    float cap, profit = 0, temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &w[i], &p[i]);
        ratio[i] = p[i] / w[i];
    }

    printf("Enter capacity: ");
    scanf("%f", &cap);

    // Sort according to profit/weight ratio
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Select items
    for(i = 0; i < n; i++)
    {
        if(w[i] <= cap)
        {
            profit += p[i];
            cap -= w[i];
        }
        else
        {
            profit += ratio[i] * cap;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", profit);

    return 0;
}
