#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int functie(int e1, ...)
{
    int suma = 0;
    va_list args;
    va_start(args, e1);
    int e = va_arg(args, int);
    while (e != -1)
    {
        suma = suma + e;
        e = va_arg(args, int);
    }
    va_end(args);
    return suma;
}

int main(int argc, char *argv[])
{
    int sumaafinala = functie(1, 2, 3, -1);
    printf("%d", sumaafinala);
}