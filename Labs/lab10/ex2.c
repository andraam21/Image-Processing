#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fisier = fopen("binar.in", "rb");
    int counter = 0;
    int n;
    // fseek(fisier, 0, 2);
    // int f = ftell(fisier);
    // printf("%d", f / 4);
    while (!feof(fisier))
    {
        if (fread(&n, sizeof(int), 1, fisier) == 0)
            break;
        counter++;
        printf("%d ", n);
    }
    printf("%d", counter);
    fclose(fisier);
}