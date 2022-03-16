#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BigNumber
{
    int size;
    int v_elements[500];
} Number;

int main()
{
    struct BigNumber n1, n2, suma;
    int nr1, nr2;
    n1.size = 4;
    for (int i = 0; i < n1.size; i++)
    {
        scanf("%d", &n1.v_elements[i]);
    }
    n2.size = 3;
    for (int i = 0; i < n2.size; i++)
    {
        scanf("%d", &n2.v_elements[i]);
    }
    suma.size = 4;
    for (int i = 0; i < n1.size; i++)
    {
        nr1 = nr1 * 10 + n1.v_elements[i];
    }
    for (int i = 0; i < n2.size; i++)
    {
        nr2 = nr2 * 10 + n2.v_elements[i];
    }
    printf("%d %d\n", nr1, nr2);
    int sumaa = nr1 + nr2;
    printf("%d\n", sumaa);
    int j = suma.size - 1;
    while (j >= 0)
    {
        suma.v_elements[j] = sumaa % 10;
        sumaa /= 10;

        j--;
    }
    for (int i = 0; i < suma.size; i++)
    {
        printf("%d", suma.v_elements[i]);
    }
}