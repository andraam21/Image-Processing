#include <stdio.h>
int main()
{
    int N, M;
    int i, j, b;
    scanf("%d %d", &N, &M);
    int a[N][M];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 0; j < M; j++)
            {
                printf("%d ", a[i][j]);
            }
        }
        else
        {
            for (j = M - 1; j >= 0; j--)
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}