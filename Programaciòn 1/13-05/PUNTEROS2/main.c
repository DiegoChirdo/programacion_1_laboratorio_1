#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=5;
    int *puntero, **punteropuntero;

    puntero=&a;
    punteropuntero=&puntero;
    printf("Con un puntero: %d\n", *puntero);
    printf("Con dos punteros: %d\n", **punteropuntero);
    return 0;
}
