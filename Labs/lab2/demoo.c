#include <stdio.h>

int main()
{

    int n;
    int suma = 0;
    int c;
    int b;
    int sumatermeni = 0;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    while (n != 0)
    {
        b = n % 10;
        n = n / 10;
        suma = suma + b;
    }
    if (suma >= 10)
        while (suma != 0)
        {
            c = suma % 10;
            suma = suma / 10;
            sumatermeni = sumatermeni + c;
        }
    printf("Suma termenilor este:%d \n", sumatermeni);
    return 0;
}
