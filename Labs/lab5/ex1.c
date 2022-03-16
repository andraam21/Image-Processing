#include <stdio.h>
int main()
{
    int i, a[20];
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &a[20]);
    }
    for (i = 0; i < 20; i++)
    {
        if (i % 2 == 0)
        {
            printf("vectorii pari sunt:");
            printf("%d", a[i]);
        }
        else
        {
            printf("vectorii impari sunt:");
            printf("%d", a[i]);
        }
    }
    return 0;
}