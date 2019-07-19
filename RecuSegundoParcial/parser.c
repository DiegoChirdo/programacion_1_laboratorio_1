#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "envio.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
            todoOk = parser_EnvioFromText(file, pArrayListEmployee);
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

int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Envio* envios;
    char datos[4][30];
    int cant;
    int todoOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", datos[0], datos[1], datos[2], datos[3]);
            envios = envio_newParametros(datos[0],datos[1],datos[2],datos[3]);
            if(envios != NULL)
            {
                ll_add(pArrayListEmployee,envios);
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

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Envio* envios;
    int size, id, auxSueldo, auxHoras, costo, todoOk=0, i;
    char auxNombre[50];
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
                    envios=(Envio*)ll_get(pArrayListEmployee,i);
                    envio_getId(envios,&id);
                    envio_getNombre(envios,auxNombre);
                    envio_getKmRecorridos(envios, &auxHoras);
                    envio_getTipoEntrega(envios,&auxSueldo);
                    envio_getCosto(envios,&costo);
                    fprintf(file,"%d,%s,%d,%d,%d\n",id,auxNombre,auxHoras,auxSueldo,costo);
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
    }
    else
    {
        printf("\nNo se han guardado correctamente.\n");
    }

    return todoOk;
}
