#include <stdio.h>

int main()
{
    int k = 3229305093;
    unsigned char a, b, c, d;
    a = *((unsigned char *)&k);
    b = *((unsigned char *)&k + 1);
    c = *((unsigned char *)&k + 2);
    d = *((unsigned char *)&k + 3);

    printf("%d.%d.%d.%d", a, b, c, d);
    return 0;
}