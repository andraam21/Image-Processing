#include <stdio.h>
#include <stdlib.h>

int **cmatrice(int n, int m)
{
    int **a;
    int i;
    a = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = calloc(m, sizeof(int));
    }
    return a;
}

int main()
{
    int **a;
    int n = 2;
    a = cmatrice(n, n);
    a = realloc(a, (n + 2) * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = realloc(a[i], (n + 2) * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
        }
    }

    return 0;
}