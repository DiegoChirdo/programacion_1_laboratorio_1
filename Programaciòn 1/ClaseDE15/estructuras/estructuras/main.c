#include <stdio.h>
#include <stdlib.h>
#include  "persona.h"

int main()
{
    struct persona per;

    printf("Ingrese apellido: ");
    fflush(stdin);
    scanf("%s", per.apellido);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", per.nombre);
    printf("Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &per.edad);
    per.isEmpty = 0;

    printf("%s\t%s\t%d\t%d", per.apellido, per.nombre, per.edad, per.isEmpty);

    return 0;
}
