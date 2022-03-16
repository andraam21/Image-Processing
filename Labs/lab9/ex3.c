#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char prop[100];
    char cuv[20];
    int k = 0;
    int nr = 0;
    int i = 0;
    fgets(prop, sizeof(prop), stdin);
    scanf("\n%s", cuv);
    char cuvinte[10][100];
    char *p = strtok(prop, " .,!\n");
    while (p != NULL)
    {
        strcpy(cuvinte[i], p);
        k++;
        p = strtok(NULL, " .,!\n");
        i++;
    }

    for (int i = 0; i <= k; i++)
    {
        if (strcmp(cuvinte[i], cuv) == 0)
        {
            nr++;
        }
    }
    printf("%d", nr);
    return 0;
}