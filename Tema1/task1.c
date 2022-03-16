#include <stdio.h>
#include <math.h>

char operatie(int a, int b)
{
    char op;
    if (a == 0 && b == 0)
    {
        op = '+';
    }
    if (a == 0 && b == 1)
    {
        op = '-';
    }
    if (a == 1 && b == 0)
    {
        op = '*';
    }
    if (a == 1 && b == 1)
    {
        op = '/';
    }
    return op;
}

int main()
{
    int binar[32];
    unsigned int numar, n, dim;
    int i = 0;
    unsigned int mask = 1 << 31;
    scanf("%u", &numar);
    n = numar;
    n >>= 29;
    n++;
    dim = numar;
    dim <<= (2 * n + 3);
    dim >>= 28;
    dim++;
    while (i < 32)
    {
        if (numar & mask)
        {
            binar[i] = 1;
        }
        else
        {
            binar[i] = 0;
        }
        numar <<= 1;
        i++;
    } //  aflam forma binara a numarului folosind o masca
    printf("%d ", n);
    char op[8];
    int j = 0;
    for (i = 3; i < (2 * n + 3); i++)
    {
        if (i % 2 == 1)
        {
            op[j] = operatie(binar[i], binar[i + 1]);
            j++;
        }
    } //  testam bitii doi cate doi pentru a descoperi operatiile
    for (j = 0; j < n; j++)
    {
        printf("%c ", op[j]);
    }
    printf("%d\n", dim);
    return 0;
}
