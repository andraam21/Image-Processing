#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char cuvant[100];
    char c;
    fgets(cuvant, sizeof(cuvant), stdin);
    scanf("%c", &c);
    char contor = '1';

    for (int i = 0; i < strlen(cuvant); i++)
    {
        if (cuvant[i] == c)
        {
            cuvant[i] = contor;
            contor++;
        }
    }
    for (int i = 0; i < strlen(cuvant); i++)
    {
        printf("%c", cuvant[i]);
    }
    return 0;
}