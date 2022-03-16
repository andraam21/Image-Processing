#include <stdio.h>

int main()
{
    int n, m, nr, i = 0;
    int mask = 1 << 31;
    //mask<<=31;
    int counter = 0;

    scanf("%d %d", &n, &m);
    nr = (n ^ m);
    //printf("%d", nr);
    while (i < 32)
    {
        if (nr & mask)
        {
            counter++;
        }
        i++;
        nr <<= 1;
    }

    printf("%d\n", counter);
    return 0;
}
