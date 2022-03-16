#include <stdio.h>

int f_oglinda(int n)
{
    int ogl = 0;
    while (n != 0)
    {
        ogl = ogl * 10 + n % 10;
        n = n / 10;
    }
    return ogl;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", f_oglinda(x));
    return 0;
}
