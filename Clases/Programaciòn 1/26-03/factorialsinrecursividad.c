#include <stdio.h>

int main()
{
    int n;
    int resp = 1;
    printf("Ingrese un número: ");
    scanf("%d",&n);
    for(n;n>0;n--)
    {
        resp=resp*n;
    }
    printf("El factoreo es %d",resp);
    return resp;
}
