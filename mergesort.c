
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);

        int b[10000], i = l, j = m + 1, k = l;

        while (i <= m && j <= r)
        {
            if (a[i] < a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }

        while (i <= m)
            b[k++] = a[i++];

        while (j <= r)
            b[k++] = a[j++];

        for (i = l; i <= r; i++)
            a[i] = b[i];
    }
}

int main()
{
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int a[10000];

    FILE *f = fopen("data.txt", "w");
    if (f == NULL) return 1;

    srand(time(NULL));

    for (int k = 0; k < 5; k++)
    {
        int n = sizes[k];

        for (int i = 0; i < n; i++)
            a[i] = rand();

        clock_t s = clock();
        mergesort(a, 0, n - 1);
        clock_t e = clock();

        double tm = (double)(e - s) / CLOCKS_PER_SEC;

        printf("%d  %f\n", n, tm);
        fprintf(f, "%d %f\n", n, tm);
    }

    fclose(f);

    FILE *g = fopen("plot.gnu", "w");
    if (g == NULL) return 1;

    fprintf(g, "set terminal pngcairo\n");
    fprintf(g, "set output 'MergeSort_Time.png'\n");
    fprintf(g, "set title 'Merge Sort Execution Time'\n");
    fprintf(g, "set xlabel 'Input Size'\n");
    fprintf(g, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(g, "set grid\n");
    fprintf(g, "plot 'data.txt' using 1:2 with linespoints title 'Merge Sort'\n");
    fclose(g);

    system("gnuplot plot.gnu");
    printf("Graph saved as MergeSort_Time.png\n");

    return 0;
}
