#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int mask = 1 << 31;
    int counter = 0;
    while ((n & mask) == 0)
    {
        n <<= 1;
        counter++;
    }
    n = ~n;
    while (counter > 0)
    {
        n >>= 1;
        counter--;
    }
    printf("%d\n", n);

    return 0;
}