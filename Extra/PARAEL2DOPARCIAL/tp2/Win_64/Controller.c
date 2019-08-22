#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"
#include "String.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
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
            todoOk = parser_EmployeeFromText(file, pArrayListEmployee);
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int todoOk=0;
    char rta;
    if(!ll_isEmpty(pArrayListEmployee)){
        printf("\nConfirmar carga desde texto? Se sobreescribiran los datos existentes S/N: ");
        rta=tolower(getchar());
    }

    if(rta=='s' || ll_isEmpty(pArrayListEmployee)){
        if(path!=NULL && pArrayListEmployee!=NULL){
            ll_clear(pArrayListEmployee);
            file=fopen(path,"rb");
            if(file!=NULL){
                todoOk = parser_EmployeeFromBinary(file,pArrayListEmployee);
                fclose(file);
            }
        }
    }
    if(todoOk==0){
        printf("\nNo pudieron cargarse los datos desde el archivo\n");
        system("pause");
    }else{
        printf("\nLos datos fueron cargados correctamente\n");
        system("pause");
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado = employee_new();
    Employee* auxEmp;

    static int id;
    int horasTrabajadas, sueldo;
    char nombre[128];
    int intentos = 1;
    int size;

    system("cls");
    if(pArrayListEmployee != NULL)
    {
        if(empleado == NULL)
        {
            printf("No hay mas memoria. \n");
        }
        else
        {
            if(ll_isEmpty(pArrayListEmployee))
            {
                id = 1001;
            }
            else
            {
                size = ll_len(pArrayListEmployee);
                auxEmp = (Employee*)ll_get(pArrayListEmployee, size-1);
                id = auxEmp->id;
                id++;
            }
            printf("\nALTA EMPLEADO\n");
            printf("\nID: %d", id);
            printf("\nINGRESE EL NOMBRE: ");
            gets(nombre);
            printf("\nINGRESE HORAS TRABAJADAS: ");
            horasTrabajadas=conseguirPositivo();
            while(horasTrabajadas < 0 && intentos < 3)
            {
                printf("\nIngrese horas trabajadas: ");
                horasTrabajadas = conseguirPositivo();
                intentos++;
            }
            intentos = 1;
            if(horasTrabajadas<0)
            {
                printf("\nAlta de empleado cancelada.\n");
                exit(1);
            }
            else
            {
                printf("\nIngrese sueldo: ");
                sueldo=conseguirPositivo();
                while(horasTrabajadas < 0 && intentos < 3)
                {
                    printf("\nIngrese sueldo: ");
                    sueldo=conseguirPositivo();
                    intentos++;
                }
                if(sueldo < 0)
                {
                    printf("\nAlta empleado cancelada. \n");
                    exit(1);
                }
                else
                {
                    empleado->horasTrabajadas=horasTrabajadas;
                    empleado->id=id;
                    id++;
                    strcpy(empleado->nombre, nombre);
                    empleado->sueldo=sueldo;
                    ll_add(pArrayListEmployee, (void*)empleado);
                    printf("\nAlta de empleado correcta\n");
                }
            }
        }
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
     Employee* empleado;
    int index, id, intentos=1, rta, auxHoras, auxSueldo;
    char auxNombre[128];
    if(pArrayListEmployee->size==0)
    {
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("Modificar empleado");
        printf("\nEmpleados: \n");

        mostrarEmpleados(pArrayListEmployee);

        printf("Ingrese ID del empleado a modificar: ");
        id=conseguirPositivo();
        index=buscarEmpleado(id, pArrayListEmployee);

        while(index<0 && intentos<3)
        {
            printf("ID inexistente. Ingrese ID del empleado a modificar: ");
            id=conseguirPositivo();
            index=buscarEmpleado(id, pArrayListEmployee);
            intentos++;
        }
        if(index<0)
        {
            printf("\nLa modificacion fue cancelada");
        }
        else
        {
            do{
                system("cls");
                printf("\n%12s%12s%12s%12s\n", "ID", "Nombre", "Horas", "Sueldo");
                empleado=(Employee*)ll_get(pArrayListEmployee, index);
                mostrarEmpleado(empleado);
                printf("Indique campo a modificar\n");
                printf("\n1- Nombre");
                printf("\n2- Horas trabajadas");
                printf("\n3- Sueldo");
                printf("\n4- Volver al menu principal");
                printf("\n\nOpcion: ");
                rta=conseguirPositivo();

                switch(rta){
                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        gets(auxNombre);
                        strcpy(empleado->nombre, auxNombre);
                        break;
                    case 2:
                        printf("\nIngrese horas trabajadas: ");
                        auxHoras=conseguirPositivo();
                        if(auxHoras<0){
                            printf("\nHoras trabajadas debe ser mayor a 0");
                            system("pause");
                        }else{
                            empleado->horasTrabajadas=auxHoras;
                        }
                        break;
                    case 3:
                        printf("\nIngrese sueldo: ");
                        auxSueldo=conseguirPositivo();
                        if(auxSueldo<0){
                            printf("\nSueldo debe ser mayor a 0");
                            system("pause");
                        }else{
                            empleado->sueldo=auxSueldo;
                        }
                        break;
                    default:
                        system("cls");
                }
            }while(rta!=4);
        }
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     Employee* empleado;
    int index, id, intentos=1, rta, auxHoras, auxSueldo;
    char auxNombre[128];
    if(pArrayListEmployee->size==0){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{

        system("cls");
        printf("Modificar empleado");
        printf("\nEmpleados: \n");

        mostrarEmpleados(pArrayListEmployee);

        printf("Ingrese ID del empleado a modificar: ");
        id=conseguirPositivo();
        index=buscarEmpleado(id, pArrayListEmployee);

        while(index<0 && intentos<3){
            printf("ID inexistente. Ingrese ID del empleado a modificar: ");
            id=conseguirPositivo();
            index=buscarEmpleado(id, pArrayListEmployee);
            intentos++;
        }

        if(index<0){
            printf("\nLa modificacion fue cancelada");
        }else{

            do{
                system("cls");
                printf("\n%12s%12s%12s%12s\n", "ID", "Nombre", "Horas", "Sueldo");
                empleado=(Employee*)ll_get(pArrayListEmployee, index);
                mostrarEmpleado(empleado);
                printf("Indique campo a modificar\n");
                printf("\n1- Nombre");
                printf("\n2- Horas trabajadas");
                printf("\n3- Sueldo");
                printf("\n4- Volver al menu principal");
                printf("\n\nOpcion: ");
                rta=conseguirPositivo();

                switch(rta){
                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        gets(auxNombre);
                        strcpy(empleado->nombre, auxNombre);
                        break;
                    case 2:
                        printf("\nIngrese horas trabajadas: ");
                        auxHoras=conseguirPositivo();
                        if(auxHoras<0){
                            printf("\nHoras trabajadas debe ser mayor a 0");
                            system("pause");
                        }else{
                            empleado->horasTrabajadas=auxHoras;
                        }
                        break;
                    case 3:
                        printf("\nIngrese sueldo: ");
                        auxSueldo=conseguirPositivo();
                        if(auxSueldo<0){
                            printf("\nSueldo debe ser mayor a 0");
                            system("pause");
                        }else{
                            empleado->sueldo=auxSueldo;
                        }
                        break;
                    default:
                        system("cls");
                }
            }while(rta!=4);
        }
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        if(pArrayListEmployee->size == 0)
        {
            printf("\nAun no se han ingresado empleados. \n");
        }
        else
        {
            mostrarEmpleados(pArrayListEmployee);
            system("pause");
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int orden;
    int intentos=1;
    if(pArrayListEmployee != NULL)
    {
        if(pArrayListEmployee->size == 0)
        {
            printf("\n Aun no se han ingresado empleados. \n");
        }
        else
        {
            printf("\nIndique el orden: o ascendente, o descendente.\n");
            orden = conseguirPositivo();
            while((orden!=1 && orden!=0) && intentos<3)
            {
                printf("\n Orden invalido, indique nuevamente.\n");
                orden=conseguirPositivo();
                intentos++;
            }
            if(orden != 1 && orden !=0)
            {
                printf("\nEl ordenamiento fue cancelado.\n");
            }
            else
            {
                printf("\nLos empleados estan siendo ordenados\n");
                ll_sort(pArrayListEmployee, ordenarEmpleados,orden);
            }
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Employee* empleado;
    int size, id, auxSueldo, auxHoras, todoOk=0, i;
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
                    empleado=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(empleado,&id);
                    employee_getNombre(empleado,auxNombre);
                    employee_getHorasTrabajadas(empleado, &auxHoras);
                    employee_getSueldo(empleado,&auxSueldo);
                    fprintf(file,"%d,%s,%d,%d\n",id,auxNombre,auxHoras,auxSueldo);
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    FILE* file;
    int todoOk = 0, i;
    int size;

    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("\nAun no se han ingresado empleados. \n");
    }
    else
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
            size = ll_len(pArrayListEmployee);
            file = fopen(path,"wb");
            if(file != NULL)
            {
                for(i=0;i<size;i++)
                {
                    empleado=ll_get(pArrayListEmployee, i);
                    if(empleado != NULL)
                    {
                        fwrite(empleado,sizeof(Employee),1,file);
                    }
                }
                if(i==size)
                {
                    todoOk=1;
                    fclose(file);
                }
                else
                {
                    todoOk=0;
                }
            }
        }
    }
    if(todoOk == 1)
    {
        printf("\nLos datos se guardaron correctamente. \n");
    }
    else
    {
        printf("\nLos datos no pudieron ser cargados.\n");
    }

    return todoOk;
}

int menuOpciones(){

    int rta;

    printf("---------MENU DE OPCIONES-----------\n");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    printf("\n10. Salir");
    printf("\n\nOpcion: ");
    rta=conseguirPositivo();
    return rta;
}

int conseguirPositivo()
{
    char aux[50];
    int len;
    int flagOK;
    int positivo;
    fflush(stdin);
    gets(aux);
    flagOK=1;
    len=strlen(aux);
    for(int i=0 ; i<len ; i++)
    {
        if(isdigit(aux[i])!=1)
        {
            flagOK=0;
        }
    }

    if(flagOK==0)
    {
        positivo=-1;
    }
    else
    {
        positivo=atoi(aux);
    }
    return positivo;
}
