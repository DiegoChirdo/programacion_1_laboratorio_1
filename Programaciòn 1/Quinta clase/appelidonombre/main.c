#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char nombre[20];
    char apellido[20];
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    strlwr(nombre);  /* Pasa todo a minùscula */
    nombre[0]=toupper(nombre[0]); /* Convierte el primer caracter a mayùscula */
    printf("Ingrese su apellido: ");
    scanf("%s", apellido);
    strlwr(apellido);
    apellido[0]=toupper(apellido[0]);
   /*pellidoNombre = strcat(nombre, apellido);
    apellidoNombre[0]='\0';
    strcat(apellidoNombre, apellido);
    strcat(apellidoNombre," ");
    strcat(apellidoNombre, nombre);
    printf("%s", apellidoNombre); */
    printf("\nSu nombre es %s", strcat(nombre, apellido));

    return 0;
}
