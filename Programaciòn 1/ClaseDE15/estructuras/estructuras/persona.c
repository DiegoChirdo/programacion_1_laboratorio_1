#include <stdio.h>
#include <stdlib.h>
#include  "persona.h"

ePersona alta(ePersona per)
{
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

    return per;
}
