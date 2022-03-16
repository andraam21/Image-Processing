#include <stdio.h>
#include <math.h>

int verificare_patrat(int n, int a, int b)
{
    int sp = a * a + b * b;
    if (sp < (n * n))
    {
        for (int i = 1; (i * i) < sp; i++)
        {
            if ((i * i) == sp)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    for (a = 2; a < n; a++)
    {
        for (b = a; b < n; b++)
        {
            if (verificare_patrat(n, a, b))
            {
                printf("%d %d %.0f\n", a, b, sqrt(a * a + b * b));
            }
        }
    }
    return 0;
}
