#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "partidas.h"

int main()
{
    int opcion = 0;
    int opcion2 = 0;
    char auxArchivo[10];
    LinkedList* partidas = ll_newLinkedList();
    while(opcion != 5)
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre del archivo: ");
            fflush(stdin);
            scanf("%s",auxArchivo);
            strcat(auxArchivo,".csv");
            controller_loadFromText(auxArchivo,partidas);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("PARTIDAS: \n");
            if(ll_len(partidas))
                print_partidas(partidas);
            break;
        case 3:
            system("cls");
            printf("\n\nPROMEDIO DE PING PONG ES DE: ");
            ll_filter(partidas,promedioTipo0);
            printf("PROMEDIO DE POOL ES: ");
            ll_filter(partidas,promedioTipo1);
            printf("PROMEDIO DE METEGOL ES: ");
            ll_filter(partidas,promedioTipo2);
            printf("PROMEDIO DE DARDOS ES: ");
            ll_filter(partidas,promedioTipo3);
            break;
        case 4:
            system("cls");
            printf("\n---GENERAR ARCHIVO DE COSTOS---\n");
            printf("0) PING PONG\n");
            printf("1) POOL\n");
            printf("2) METEGOL\n");
            printf("3) DARDOS\n");
            printf("4) SALIR\n");
            printf("Ingrese una opcion: ");
            fflush(stdin);
            scanf("%d",&opcion2);
            switch(opcion2)
            {
            case 0:
                ll_map(partidas,promedioTipo0);
                system("cls");
                break;
            case 1:
                ll_map(partidas,promedioTipo1);
                system("cls");
                break;
            case 2:
                ll_map(partidas,promedioTipo2);
                system("cls");
                break;
            case 3:
                ll_map(partidas,promedioTipo3);
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            }
            break;
        }
    }
    return 0;
}
