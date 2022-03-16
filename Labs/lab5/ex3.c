#include <stdio.h>

int main()
{
    int i, k, j;
    int counter = 0;
    int a[5], b[5];
    scanf("%d", &k);
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 5; i++)
    {
        b[i] = a[i];
    }
    for (i = 0; i < 5; i++)
    {
        a[i] = a[i + k];
    }
    for (i = 4; i > (5 - k); i--)
    {
        for (j = 0; j < 5; j++)
        {
            a[i] = b[j];
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}