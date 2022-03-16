#include <stdio.h>
int main()
{
    int N, M;
    int i, j;
    scanf("%d %d", &N, &M);
    int a[N][M];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int x1, x2, x3, x4;
    int suma = 0;
    scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
    for (i = x1; i <= x3; i++)
    {
        for (j = x2; j <= x4; j++)
        {
            suma = suma + a[i][j];
        }
    }
    printf("%d", suma);
    return 0;
}