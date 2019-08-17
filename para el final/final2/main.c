#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ventas.h"
#include "parser.h"
#include "LinkedList.h"

int main()
{
    int opcion = 0;
    char auxArchivo[10];
    LinkedList* ventas = ll_newLinkedList();
    while(opcion!=5)
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            printf("\nIngrese el nombre del archivo: ");
            fflush(stdin);
            scanf("%s",auxArchivo);
            strcat(auxArchivo,".csv");
            controller_loadFromText(auxArchivo,ventas);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("VENTAS\n\n");
            if(ll_len(ventas))
                print_ventas(ventas);
            break;
        case 3:
            ll_map(ventas,laQueMapea);
            controller_saveVentas("montos.csv",ventas);
            break;
        case 4:
            system("cls");
            ll_map(ventas,laQueMapea);
            printf("\n------INFORMES------\n");
            int auxSala;
            printf("Ingrese sala: ");
            scanf("%d",&auxSala);
            informe1(ventas,auxSala);
            break;
        }
    }

    return 0;
}
