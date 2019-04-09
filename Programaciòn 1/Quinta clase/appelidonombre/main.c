#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[20];
    char apellido[20];
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    nombre[0]=toupper(nombre[0]);
    printf("Ingrese su apellido: ");
    scanf("%s", apellido);
    apellido[0]=toupper(apellido[0]);
  /*  printf("\nSu nombre es %s y su apellido es %s", nombre, apellido); */
    printf("\nSu nombre es %s", strcat(nombre, apellido));
    return 0;
}
