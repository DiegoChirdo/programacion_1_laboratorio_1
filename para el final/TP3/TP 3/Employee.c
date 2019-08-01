#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"

/** \brief Asigna el id recibido al empleado
 *
 * \param id int
 * \param this Employee*
 * \return int
 *
 */
int employee_setId(Employee* this,int id){

    int todoOK=0;

    ///Asigna el id recibido al empleado
    if(this!=NULL && id>0){
        this->id=id;
        todoOK=1;
    }

    return todoOK;

}

/** \brief Consigue el id del empleado recibido
 *
 * \param id int*
 * \param this Employee*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id){

    int todoOK=0;

    ///Consigue el id del empleado recibido
    if(this!=NULL && id!=NULL){
        *id=this->id;
        todoOK=1;
    }

    return todoOK;
}

/** \brief Asigna el nombre recibido al empleado
 *
 * \param nombre char*
 * \param this Employee*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre){

    int todoOK=0;

    ///Asigna el nombre recibido al empleado
    if(this!=NULL && nombre!=NULL && strlen(nombre)>1){
        strcpy(this->nombre, nombre);
        todoOK=1;
    }

    return todoOK;

}

/** \brief Consigue el nombre del empleado recibido
 *
 * \param nombre char*
 * \param this Employee*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre){

    int todoOK=0;

    ///Consigue el nombre del empleado recibido
    if(this!=NULL && nombre!=NULL){
        strcpy(nombre, this->nombre);
        todoOK=1;
    }

    return todoOK;

}

/** \brief Asigna las horas trabajadas al empleado recibido
 *
 * \param horasTrabajadas int
 * \param this Employee*
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int todoOK=0;

    ///Asigna las horas trabajadas al empleado recibido
    if(this!=NULL && horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        todoOK=1;
    }

    return todoOK;



}


/** \brief Consigue las horas trabajadas del empleado recibido
 *
 * \param horasTrabajadas int*
 * \param this Employee*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

    int todoOK=0;

    ///Consigue las horas trabajadas del empleado recibido
    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        todoOK=1;
    }

    return todoOK;

}

/** \brief Asigna el sueldo al empleado recibido
 *
 * \param sueldo int
 * \param this Employee*
 * \return int
 *
 */

int employee_setSueldo(Employee* this,int sueldo){

    int todoOK=0;

    ///Asigna el sueldo al empleado recibido
    if(this!=NULL && sueldo>0){
        this->sueldo=sueldo;
        todoOK=1;
    }

    return todoOK;


}

/** \brief Consigue el sueldo del empleado recibido
 *
 * \param sueldo int*
 * \param this Employee*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo){

    int todoOK=0;

    ///Consigue el sueldo del empleado recibido
    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
        todoOK=1;
    }

    return todoOK;

}


/** \brief Consigue memoria para un nuevo empleado e inicializa sus campos
 *
 * \return Employee*
 */
Employee* employee_new(){

    Employee* this=(Employee*) malloc(sizeof(Employee));

    ///Consigue memoria para un nuevo empleado
    if(this!=NULL){
        this->id=0;
        strcpy(this->nombre, "");
        this->horasTrabajadas=0;
        this->sueldo=0;
    }

    return this;

}


/** \brief Muestra el empleado recibido
 *
 * \param emp Employee*
 * \return void
 */
void mostrarEmpleado(Employee* emp){

    if(emp!=NULL){
        printf("%12d%12s%12d%12d\n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}

/** \brief Recibe dos empleados, compara sus IDs y devuelve un entero segun la comparacion
 *
 * \param empleado1 Employee*
 * \param empleado2 Employee*
 * \return int
 */

int ordenarEmpleados(void* empleado1, void* empleado2){

    Employee* emp1=(Employee*) empleado1;
    Employee* emp2=(Employee*) empleado2;
    int orden;

    ///Compara los dos empleados recibidos segun su id, y devuelve -1, 1 o 0 segun la comparacion
    if(emp1!=NULL && emp2!=NULL){
        if(emp1->id == emp2->id){
            orden=0;
        }else{
            if(emp1->id > emp2->id){
                orden=-1;
            }else{
                orden=1;
            }
        }
    }

    return orden;
}

/** \brief Muestra todos los empleados de la lista
 *
 * \param listaEmpleados LinkedLista*
 * \return void
 */
void mostrarEmpleados(LinkedList* listaEmpleados){

    Employee* empleado;
    int size=ll_len(listaEmpleados);

    ///Lista todos los empleados usando ll_get
    if(listaEmpleados!=NULL){
        printf("\n\n%12s%12s%12s%12s\n\n", "ID", "Nombre", "Horas", "Sueldo");
        for(int i=0 ; i<size; i++){
            empleado=(Employee*) ll_get(listaEmpleados, i);
            mostrarEmpleado(empleado);
        }

    }

}

/** \brief Recibe un ID y devuelve el index de la lista del empleado que tiene ese ID
 *
 * \param id int
 * \param listaEmpleados LinkedList*
 * \return int
 */


int buscarEmpleado(int id, LinkedList* listaEmpleados){

    Employee* empleado;
    int index=-1;
    int size;

    if(listaEmpleados!=NULL){
        ///Recorre la lista y devuelve el indice del empleado que coincida con el id recibido
        size=ll_len(listaEmpleados);
        for(int i=0 ; i<size ; i++){
            empleado=(Employee*) ll_get(listaEmpleados, i);
            if(empleado->id==id){
                index=ll_indexOf(listaEmpleados, (void*)empleado);
                break;
            }
        }
    }

    return index;

}

/** \brief Asigna a un nuevo empleado los datos recibidos por parametro convertidos
 *
 * \param idStr char*
 * \param nameStr char*
 * \param hoursWorkedStr char*
 * \param salary char*
 * \return Employee*
 */

Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salary){

    Employee* empleado=employee_new();
    int index;

    if(idStr!=NULL && nameStr!=NULL && hoursWorkedStr!=NULL && salary!=NULL && empleado!=NULL){
        if(!employee_setId(empleado,atoi(idStr)) || !employee_setNombre(empleado,nameStr)|| !employee_setSueldo(empleado,atoi(salary))|| !employee_setHorasTrabajadas(empleado,atoi(hoursWorkedStr))){
            ///Si alguna de las funciones del if falla, el empleado devuelvo sera NULL
            empleado=NULL;
        }
    }

    return empleado;
}



