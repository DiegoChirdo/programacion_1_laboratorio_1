#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"
#define CANTIDAD 20

int main()
{
    EPersona persona[CANTIDAD];
    char seguir='s';
    int opcion=0;

    inicializarPersona(persona, CANTIDAD);

    while(seguir=='s')
    {
        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(persona, CANTIDAD);
                break;
            case 2:
                borrarPersona(persona, CANTIDAD);
                break;
            case 3:
                listarNombre(persona, CANTIDAD);
                break;
            case 4:
                printf("hey");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
