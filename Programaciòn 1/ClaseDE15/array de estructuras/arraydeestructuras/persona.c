#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

void alta( ePersona per[], int cantidad )
{
    int i;

    for( i = 0; i < cantidad; i++ )
        {
            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", per[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", per[i].nombre);

            printf("Edad:\n");
            scanf("%d", &per[i].edad);

            per[i].isEmpty = 0;
        }
}

void mostrar( ePersona per[], int cantidad )
{
    int i;
    for( i = 0; i < cantidad; i++ )
    {
        printf("%s\t%s\t%d\t%d\n", per[i].apellido, per[i].nombre, per[i].edad, per[i].isEmpty);
    }

}
