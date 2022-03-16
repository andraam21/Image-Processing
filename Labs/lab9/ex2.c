#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    int n;
    char aux[10][100];
    scanf("%d", &n);
    char cuvinte[10][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cuvinte[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (strcmp(cuvinte[i], cuvinte[i + 1]) > 0)
        {
            strcpy(aux[i], cuvinte[i]);
            strcpy(cuvinte[i], cuvinte[i + 1]);
            strcpy(cuvinte[i + 1], aux[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s ", cuvinte[i]);
    }
}