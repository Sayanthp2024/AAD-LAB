
#include <stdio.h>

// Normal Method
void normal(int a[], int n)
{
    int min, max, i, c = 0;

    min = max = a[0];

    for(i = 1; i < n; i++)
    {
        c++;
        if(a[i] < min)
            min = a[i];

        c++;
        if(a[i] > max)
            max = a[i];
    }

    printf("\nNormal Method");
    printf("\nMin = %d", min);
    printf("\nMax = %d", max);
    printf("\nComparisons = %d\n", c);
}

// Divide and Conquer
int min, max, c = 0;

void divide(int a[], int low, int high)
{
    int mid, min1, max1, min2, max2;

    if(low == high)
    {
        min = max = a[low];
    }
    else if(high == low + 1)
    {
        c++;
        if(a[low] < a[high])
        {
            min = a[low];
            max = a[high];
        }
        else
        {
            min = a[high];
            max = a[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        divide(a, low, mid);
        min1 = min;
        max1 = max;

        divide(a, mid + 1, high);
        min2 = min;
        max2 = max;

        c += 2;

        min = (min1 < min2) ? min1 : min2;
        max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    normal(a, n);

    c = 0;
    divide(a, 0, n - 1);

    printf("\nDivide and Conquer");
    printf("\nMin = %d", min);
    printf("\nMax = %d", max);
    printf("\nComparisons = %d\n", c);

    return 0;
}
