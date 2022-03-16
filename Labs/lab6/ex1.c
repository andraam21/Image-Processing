#include <stdio.h>

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    int a[n][n];
    a[0][0] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j + 1] = a[i][j] + 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}