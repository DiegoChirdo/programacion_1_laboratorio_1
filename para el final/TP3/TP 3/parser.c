#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    char datos[4][30];
    int cant;
    int todoOk=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile)){
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", datos[0], datos[1], datos[2], datos[3]);
            empleado=employee_newParametros(datos[0],datos[1],datos[2],datos[3]);
            ///Leera del archivo recibido hasta que llegue al final del mismo
            if(empleado!=NULL){
                ///Si el empleado devuelto no es null, lo agrega a la lista
                ll_add(pArrayListEmployee,empleado);
                todoOk=1;
            }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }
    }


    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){

    int todoOk=0,cant=0;
    Employee* empleado;

    if(pFile!=NULL && pArrayListEmployee!= NULL){
        while(!feof(pFile)){
            empleado=employee_new();
            cant = fread(empleado,sizeof(Employee),1,pFile);
            ///Leera del archivo recibido hasta que llegue al final del mismo
            if(empleado!=NULL){
                if(empleado->id>0){
                ///Solo agregara empleados con id mayor a 0 (para evitar basura)
                ll_add(pArrayListEmployee,empleado);
                todoOk=1;
                }
            }
            if(cant<1){
                if(feof(pFile)){
                    break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }
    }

    return todoOk;

}
