#include <stdio.h>

int main()
{
    int n, s, p;
    char c;
    char F, K, C;
    printf("Introduceti temperatura: ");
    scanf("%s %d", &c, &n);
    //scanf("%d", &n);
    if (c == 'F')
    {
        s = ((n + 460) * 4) / 9;
        printf("%d K", s);
    }
    if (c == 'C')
    {
        p = n + 273;
        printf("%d K", p);
    }
    if (c == 'K')
    {
        printf("%d K", n);
    }
    return 0;
}