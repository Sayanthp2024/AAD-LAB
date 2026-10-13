#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int l, int h) {
    if (l < h) {
        int p = a[h], i = l - 1, t;

        for (int j = l; j < h; j++) {
            if (a[j] <= p) {
                i++;
                t = a[i]; a[i] = a[j]; 
                a[j] = t;
            }
        }

        t = a[i + 1];
        a[i + 1] = a[h];
        a[h] = t;

        quicksort(a, l, i);
        quicksort(a, i + 2, h);
    }
}

int main() {
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int a[10000];

    FILE *f = fopen("data.txt", "w");
    if (f == NULL) return 1;

    srand(time(NULL));

    for (int k = 0; k < 5; k++) {
        int n = sizes[k];

        for (int i = 0; i < n; i++)
            a[i] = rand();

        clock_t s = clock();
        quicksort(a, 0, n - 1);
        clock_t e = clock();

        double tm = (double)(e - s) / CLOCKS_PER_SEC;

        printf("%d  %f\n", n, tm);
        fprintf(f, "%d %f\n", n, tm);
    }
    fclose(f);

    FILE *g = fopen("plot.gnu", "w");
    if (g == NULL) return 1;

    fprintf(g, "set terminal pngcairo\n");
    fprintf(g, "set output 'QuickSort_Time.png'\n");
    fprintf(g, "set title 'Quick Sort Execution Time'\n");
    fprintf(g, "set xlabel 'Input Size'\n");
    fprintf(g, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(g, "set grid\n");
    fprintf(g, "plot 'data.txt' using 1:2 with linespoints title 'Quick Sort'\n");
    fclose(g);

    system("gnuplot plot.gnu");
    printf("Graph saved as QuickSort_Time.png\n");

    return 0;
}
