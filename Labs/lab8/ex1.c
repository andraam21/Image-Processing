#include <stdio.h>
#include <stdlib.h>

int *realloc_eu(int *a, int dimi, int dimf)
{

    int *aux;
    aux = malloc(dimf * sizeof(int));
    for (int i = 0; i < dimi; i++)
    {
        aux[i] = a[i];
    }
    free(a);
    return aux;
}

int main()
{
    int *a = malloc(20 * sizeof(int));
    realloc_eu(a, 20, 40);
    return 0;
}