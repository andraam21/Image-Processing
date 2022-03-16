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
    unsigned int numar, n, dim;
    int i = 0;
    scanf("%u", &numar);
    n = numar;
    n >>= 29;
    n++;
    dim = numar;
    dim <<= (2 * n + 3);
    dim >>= 28;
    dim++;
    int binar[32];
    unsigned int mask = 1 << 31;
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
    }
    char op[8];
    int j = 0;
    for (i = 3; i < (2 * n + 3); i++)
    {
        if (i % 2 == 1)
        {
            op[j] = operatie(binar[i], binar[i + 1]);
            j++;
        }
    }
    float citire;
    float N = n;
    float Dim = dim;
    citire = ((N + 1) * Dim) / 16; //  aflam valoarea si o rotunjim prin lipsa sau adaos
    if (round(citire) < citire)
    {
        citire = round(citire) + 1;
    }
    else
    {
        citire = round(citire);
    }
    int k = citire;
    unsigned short int numerecitite[k];
    for (i = 0; i < k; i++)
    {
        scanf("%hu", &numerecitite[i]);
    }
    int unsigned short operand[9];
    //  in functie de dimensiune prelucram numerele citite prin shiftari
    if (dim == 1)
    {
        for (i = 0; i < 9; i++)
        {
            operand[i] = numerecitite[0];
        }
        for (i = 0; i < 9; i++)
        {
            operand[i] <<= i;
            operand[i] >>= 15;
        }
    }
    if (dim == 2)
    {
        for (i = 0; i < 8; i++)
        {
            operand[i] = numerecitite[0];
        }
        operand[8] = numerecitite[1];

        for (i = 0; i < 8; i++)
        {
            operand[i] <<= (2 * i);
            operand[i] >>= 14;
        }
        operand[8] >>= 14;
    }
    if (dim == 4)
    {
        operand[0] = numerecitite[0];
        operand[1] = numerecitite[0];
        operand[2] = numerecitite[0];
        operand[3] = numerecitite[0];
        operand[4] = numerecitite[1];
        operand[5] = numerecitite[1];
        operand[6] = numerecitite[1];
        operand[7] = numerecitite[1];
        operand[8] = numerecitite[2];
        for (i = 0; i < 9; i++)
        {
            if (i == 1 || i == 5)
            {
                operand[i] <<= 4;
            }
            if (i == 2 || i == 6)
            {
                operand[i] <<= 8;
            }
            if (i == 3 || i == 7)
            {
                operand[i] <<= 12;
            }
            operand[i] >>= 12;
        }
    }
    if (dim == 8)
    {
        operand[0] = numerecitite[0];
        operand[1] = numerecitite[0];
        operand[2] = numerecitite[1];
        operand[3] = numerecitite[1];
        operand[4] = numerecitite[2];
        operand[5] = numerecitite[2];
        operand[6] = numerecitite[3];
        operand[7] = numerecitite[3];
        operand[8] = numerecitite[4];
        for (i = 0; i < 9; i++)
        {
            if (i % 2 == 0)
            {
                operand[i] >>= 8;
            }
            else
            {
                operand[i] <<= 8;
                operand[i] >>= 8;
            }
        }
    }
    if (dim == 16)
    {
        for (i = 0; i < 9; i++)
        {
            operand[i] = numerecitite[i];
        }
    }
    int rezultat = operand[0];
    for (i = 0; i < 8; i++)
    {
        if (op[i] == '-')
        {
            rezultat = rezultat - operand[i + 1];
        }
        if (op[i] == '+')
        {
            rezultat = rezultat + operand[i + 1];
        }
        if (op[i] == '/')
        {
            rezultat = rezultat / operand[i + 1];
        }
        if (op[i] == '*')
        {
            rezultat = rezultat * operand[i + 1];
        }
    } //  calculam rezultatul folosind operanzii si operatiile gasite
    printf("%d\n", rezultat);
    return 0;
}
