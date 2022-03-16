#include <stdio.h>

int main()
{

    int a = 156135;
    int i;
    printf("%d\n", a);
    int mask = 1 << 31;
    for (i = 0; i < 32; i++)
    {
        if (a & mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        a <<= 1;
    }
    printf("\n");
    return 0;
}