#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int k = 0;
    int v[20];
    int w[20];
    int sir[20];
    FILE *fisier = fopen("data.in", "r");
    FILE *fisier_out = fopen("./altu/data.out", "w");
    fscanf(fisier, "%d ", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fisier, "%d ", &v[i]);
        //printf("%d", v[i]);
    }

    fscanf(fisier, "%d", &m);
    for (int i = 0; i < m; i++)
    {
        fscanf(fisier, "%d", &w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sir[k] = v[i];
        k++;
    }
    for (int i = 0; i < m; i++)
    {
        sir[k] = w[i];
        k++;
    }
    for (int i = 0; i < (n + m); i++)
    {
        for (int j = 0; j < (n + m); j++)
        {
            if (sir[i] < sir[j])
            {
                int aux = sir[i];
                sir[i] = sir[j];
                sir[j] = aux;
            }
        }
    }
    fprintf(fisier_out, "%d \n", n + m);
    for (int i = 0; i < (n + m); i++)
    {
        fprintf(fisier_out, "%d ", sir[i]);
    }
    fclose(fisier);
    fclose(fisier_out);
}