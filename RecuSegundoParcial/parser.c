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
            if(empleado != NULL)
            {
                ll_add(pArrayListEmployee,envios);
                todoOk = 1;
            }
            if(cant < 3)
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

