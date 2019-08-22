#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ventas.h"
#include "parser.h"
#include "LinkedList.h"

int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Ventas* venta;
    char datos[5][30];
    int cant;
    int todoOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", datos[0], datos[1], datos[2], datos[3],datos[4],datos[5]);
            venta = venta_newParametros(datos[0],datos[1],datos[2],datos[3],datos[4],datos[5]);
            if(venta != NULL)
            {
                ll_add(pArrayListEmployee,venta);
                todoOk = 1;
            }
            if(cant < 4)
            {
                if(feof(pFile))
                    break;
                else
                {
                    todoOk = 0;
                    break;
                }
            }
        }
    }
    return todoOk;
}

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int todoOk=0;
    char rta;
    if(!ll_isEmpty(pArrayListEmployee)){
        printf("\nConfirmar carga desde texto? Se sobreescribiran los datos existentes S/N: ");
        rta=tolower(getchar());
    }

    if(rta=='s' || ll_isEmpty(pArrayListEmployee))
    {
        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            ll_clear(pArrayListEmployee);
            file=fopen(path, "r");
            if(file!=NULL)
            {
            todoOk = parser_VentasFromText(file, pArrayListEmployee);
            fclose(file);
            }
        }
    }
    if(todoOk==0)
    {
        printf("\nNo pudieron cargarse los datos desde el archivo\n");
        system("pause");
    }
    else
    {
        printf("\nLos datos fueron cargados correctamente\n");
        system("pause");
    }
    return todoOk;
}

int controller_saveVentas(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Ventas* venta;
    int size, todoOk=0, i;
    int id, dia, cantidad, sala, costo;
    char nombre[32];
    char hora[32];
    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("\nAun no se han ingresado datos.\n");
    }
    else
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
            size = ll_len(pArrayListEmployee);
            file=fopen(path,"w");
            if(file!=NULL)
            {
                for(i=0;i<size;i++)
                {
                    venta=(Ventas*)ll_get(pArrayListEmployee,i);
                    venta_getId(venta,&id);
                    venta_getHora(venta,hora);
                    venta_getNombre(venta,nombre);
                    venta_getDia(venta,&dia);
                    venta_getCantidad(venta,&cantidad);
                    venta_getSala(venta,&sala);
                    venta_getCosto(venta,&costo);
                    fprintf(file,"%d,%s,%d,%s,%d,%d,%d\n",id,nombre,dia,hora,sala,cantidad,costo);
                }
                fclose(file);
                if(i==size)
                {
                    todoOk=1;
                }
                else
                {
                    todoOk=0;
                }
            }
        }
    }
    if(todoOk==1)
    {
        printf("\nLos datos se han guardado correctamente.\n");
        system("pause");
    }
    else
    {
        printf("\nNo se han guardado correctamente.\n");
        system("pause");
    }

    return todoOk;
}
