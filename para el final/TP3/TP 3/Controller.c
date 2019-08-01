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

    ///Si la lista no esta vacia, pregunta al usuario si desea sobreescribir los datos existentes
    if(!ll_isEmpty(pArrayListEmployee)){
        printf("\nConfirmar carga desde texto? Se sobreescribiran los datos existentes S/N: ");
        rta=tolower(getchar());
    }

    if(rta=='s' || ll_isEmpty(pArrayListEmployee)){
        ///Si la respuesta es SI, borra los datos existentes y guarda desde texto
        if(path!=NULL && pArrayListEmployee!=NULL){
            ll_clear(pArrayListEmployee);
            file=fopen(path, "r");
            if(file!=NULL){
            todoOk=parser_EmployeeFromText(file, pArrayListEmployee);
            fclose(file);
            }
        }
    }

    ///Si pudieron o no cargarse los datos, informa
    if(todoOk==0){
        printf("\nNo pudieron cargarse los datos desde el archivo\n");
        system("pause");
    }else{
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

    ///Si la lista no esta vacia, pregunta al usuario si desea sobreescribir los datos existentes
    if(!ll_isEmpty(pArrayListEmployee)){
        printf("\nConfirmar carga desde texto? Se sobreescribiran los datos existentes S/N: ");
        rta=tolower(getchar());
    }

    if(rta=='s' || ll_isEmpty(pArrayListEmployee)){
        ///Si la respuesta es SI, borra los datos existentes y guarda desde texto
        if(path!=NULL && pArrayListEmployee!=NULL){
            ll_clear(pArrayListEmployee);
            file=fopen(path,"rb");
            if(file!=NULL){
                todoOk=parser_EmployeeFromBinary(file,pArrayListEmployee);
                fclose(file);
            }
        }
    }

    ///Si pudieron o no cargarse los datos, informa
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
    Employee* empleado=employee_new();
    Employee* auxEmp;

    static int id;
    int horasTrabajadas, sueldo;
    char nombre[128];
    int intentos=1;
    int size;

    system("cls");
    if(pArrayListEmployee!=NULL){
        if(empleado==NULL){
            printf("No pudo conseguirse memoria para el empleado");
        }else{

            /**
                Si la lista esta vacia a la hora del alta,
                el id sera 1001. Caso contrario sera uno mas del ultimo
                id registrado en la lista.
            **/

            if(ll_isEmpty(pArrayListEmployee)){
                id=1001;
            }else{
                size=ll_len(pArrayListEmployee);
                auxEmp=(Employee*)ll_get(pArrayListEmployee, size-1);
                id=auxEmp->id;
                id++;
            }

            printf("---Alta de empleado---\n");
            printf("\nID: %d", id);

            printf("\nIngrese el nombre: ");
            gets(nombre);

            printf("Ingrese horas trabajadas: ");
            horasTrabajadas=conseguirPositivo();

            while(horasTrabajadas<0 && intentos<3){
                printf("Ingrese horas trabajadas: ");
                horasTrabajadas=conseguirPositivo();
                intentos++;
            }

            intentos=1;

            if(horasTrabajadas<0){
                printf("\nAlta de empleado cancelada");
                exit(1);
            }else{

                printf("Ingrese sueldo: ");
                sueldo=conseguirPositivo();

                while(horasTrabajadas<0 && intentos<3){
                    printf("Ingrese sueldo: ");
                    sueldo=conseguirPositivo();
                    intentos++;
                }

                if(sueldo<0){
                    printf("\nAlta de empleado cancelada");
                    exit(1);
                }else{
                    empleado->horasTrabajadas=horasTrabajadas;
                    empleado->id=id;
                    id++;
                    strcpy(empleado->nombre, nombre);
                    empleado->sueldo=sueldo;
                    ll_add(pArrayListEmployee, (void*)empleado);
                    printf("\nAlta de empleado correcta");
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

    ///Comprueba que haya empleados en la lista
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
                ///Menu de modificacion para que el usuario elija que campo desea modificar
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

    int auxID;
    int intentos=1;
    int index;
    char rta;

    ///Verifica que haya empleados en la lista
    if(pArrayListEmployee->size==0){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{

        ///Muestra todos los empleados para que el usuario elija cual remover
        system("cls");
        mostrarEmpleados(pArrayListEmployee);

        printf("Ingrese ID del empleado a eliminar: ");
        auxID=conseguirPositivo();
        index=buscarEmpleado(auxID, pArrayListEmployee);

        while(index<0 && intentos<3){
            printf("ID invalido, ingrese nuevamente: ");
            auxID=conseguirPositivo();
            index=buscarEmpleado(auxID, pArrayListEmployee);
            intentos++;
        }
        ///Si el index ingresado no existe, informa
        if(index==-1){
            printf("\nID invalido. Baja de empleado cancelada");
        }else{
            printf("Ingrese S/N para confirmar o cancelar la baja del empleado: ");
            fflush(stdin);
            rta=tolower(getchar());

            if(rta=='s'){
                ll_remove(pArrayListEmployee, index);
                printf("\nEl empleado fue eliminado");
            }else{
                printf("\nLa baja del empleado fue cancelada");
            }
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
    ///Lista los empleados si hay al menos uno cargado
    if(pArrayListEmployee!=NULL){
        if(pArrayListEmployee->size==0){
            printf("\nAun no se han ingresado empleados\n");
        }else{
            mostrarEmpleados(pArrayListEmployee);
        }
        system("pause");
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

    ///Ordena los empleados por ID
    if(pArrayListEmployee!=NULL){
        if(pArrayListEmployee->size==0){
            printf("\nAun no se han ingresado empleados\n");
            system("pause");
        }else{
            printf("\nIndique el orden: 0 ascendente, 1 descendente: ");
            orden=conseguirPositivo();

            while((orden!=1 && orden!=0) && intentos<3){
                printf("\nOrden invalido. Indique nuevamente: 1 ascendente, 0 descendente: ");
                orden=conseguirPositivo();
                intentos++;
            }

            if(orden!=1 && orden!=0){
                printf("\nEl ordenamiento fue cancelado");
            }else{
                printf("\nLos empleados estan siendo ordenados..");
                ll_sort(pArrayListEmployee, ordenarEmpleados, orden);
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

    ///Si aun no se ingresaron empleados, informa
     if(ll_isEmpty(pArrayListEmployee)){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{
        if(path!=NULL && pArrayListEmployee!=NULL){

            size=ll_len(pArrayListEmployee);
            file=fopen(path,"w");
            ///Si pudo abrirse el archivo, imprime los datos de todos los empleados en archivo texto
            if(file!=NULL){
                for(i=0;i<size;i++){
                    empleado=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(empleado,&id);
                    employee_getNombre(empleado,auxNombre);
                    employee_getHorasTrabajadas(empleado,&auxHoras);
                    employee_getSueldo(empleado,&auxSueldo);
                    fprintf(file,"%d,%s,%d,%d\n",id,auxNombre,auxHoras,auxSueldo);
                }
                fclose(file);
                if(i==size){
                    todoOk=1;
                }
                }else{
                    todoOk=0;
                }
        }
    }

    ///Informa si pudieron o no guardarse los datos
    if(todoOk==1){
        printf("\nLos datos pudieron guardarse correctamente\n");
    }else{
        printf("\nLos datos no pudieron guardarse correctamente\n");
    }

    system("pause");

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
    int todoOk=0, i;
    int size;

    ///Si aun no se ingresaron empleados, informa
    if(ll_isEmpty(pArrayListEmployee)){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{
        if(path != NULL && pArrayListEmployee!= NULL){
            size=ll_len(pArrayListEmployee);
            file=fopen(path,"wb");
            ///Si pudo abrirse el archivo, guarda los datos de los empleados en el archivo binario
            if(file!=NULL){
                for(i=0;i<size;i++){
                    empleado=ll_get(pArrayListEmployee,i);
                    if(empleado!= NULL){
                        fwrite(empleado,sizeof(Employee),1,file);
                    }
                }
                if(i==size){
                    todoOk=1;
                    fclose(file);
                }else{
                    todoOk=0;
                }
            }
        }
    }

     ///Informa si pudieron o no guardarse los datos
    if(todoOk==1){
        printf("\nLos datos pudieron guardarse correctamente\n");
    }else{
        printf("\nLos datos no pudieron guardarse correctamente\n");
    }

    system("pause");

    return todoOk;

}

/** \brief Muestra opciones del menu y devuelve la elegida por el usuario
 *
 * \return int
 */
int menuOpciones(){

    int rta;

    printf("ABM Empleado - TP 3\n");
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

/** \brief Convierte la cadena obtenida a numero positivo. Si no es posible, devuelve -1
 *
 * \return int
 */

int conseguirPositivo(){

    char aux[50];
    int len;
    int flagOK;
    int positivo;

    fflush(stdin);
    gets(aux);

    flagOK=1;
    len=strlen(aux);

    ///Consigue una cadena que es transformada a entero solo si todos los elementos son digitos
    for(int i=0 ; i<len ; i++){
        if(isdigit(aux[i])!=1){
            flagOK=0;
        }
    }

    if(flagOK==0){
        positivo=-1;
        ///Si la validacion no es correcta, devuelve -1
    }else{
        positivo=atoi(aux);
    }

    return positivo;

}
