#include <stdio.h>
void invers(int *v, int n)
{
    int *s, *d, *start;
    int j = n - 1;
    s = v;
    d = v + j;
    start = v;
    while (s < d)
    {
        int aux = *s;
        *s = *d;
        *d = aux;
        s++;
        j--;
        d = start + j;
    }
}
int main()
{
    int v[] = {1, 2, 3, 4};
    invers(v, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}
