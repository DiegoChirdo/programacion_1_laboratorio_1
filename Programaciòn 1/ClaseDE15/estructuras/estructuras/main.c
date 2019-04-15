#include <stdio.h>
#include <stdlib.h>

struct persona
   {
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
    };

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

    printf("Apellido: %s", per.apellido);
    printf("\nNombre: %s", per.nombre);
    printf("\nEdad: %d", per.edad);

    return 0;
}
