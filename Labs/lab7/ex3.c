#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

int main()
{
    int v[] = {1, 2, 6, 9};

    qsort(v, 4, sizeof(int), compar);
    for (int i = 0; i < 4; i++)
    {
        printf("%d", v[i]);
    }
}