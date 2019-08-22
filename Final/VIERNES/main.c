#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "empleados.h"

int main()
{
    int opcion = 0;
    LinkedList* empleados = ll_newLinkedList();
    while(opcion!=7)
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
            case 1:
                controller_loadFromText("datos.csv",empleados);
                break;
            case 2:
                system("cls");
                ll_sort(empleados,ordenarPorNombre,1);
                mostrarEmpleados(empleados);
                break;
            case 3:
                ll_map(empleados,laQueMapea);
                printf("\n\nDedicaciones seteadas\n\n");
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printf("EMPLEADOS ORDENADOS POR DEDICACION:\n");
                ll_sort(empleados,ordenarPorDedicacion,1);
                mostrarEmpleadosDedicacion(empleados);
                break;
            case 5:
                ll_filter(empleados,menores21);
                break;
            case 6:
                ll_filter2(empleados,menores21);
                break;
        }
    }

    return 0;
}
