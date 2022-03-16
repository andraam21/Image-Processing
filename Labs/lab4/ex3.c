#include <stdio.h>

int main()
{
    int n, c;
    int i = 0, nr_final = 0;
    scanf("%d %d", &n, &c);
    int v[10] = {0};
    for (i = 0; i < 10; i++)
    {
        if (n == 0)
        {
            break;
        }
        v[i] = n % 10;
        n /= 10;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", v[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (v[9 - i] != c)
        {
            nr_final = nr_final * 10 + v[9 - i];
        }
    }
    printf("%d\n", nr_final);
    return 0;
}
