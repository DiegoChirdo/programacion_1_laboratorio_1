#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"

int employee_setId(Employee* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre)>1)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new()
{
    Employee* this = (Employee*)malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

void mostrarEmpleado(Employee* this)
{
    if(this != NULL)
        printf("%d\t%s\t%d\t%d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
}

int ordenarEmpleados(void* empleado1, void* empleado2)
{
    Employee* emp1 = (Employee*) empleado1;
    Employee* emp2 = (Employee*) empleado2;
    int orden;
    if(emp1 != NULL && emp2 != NULL)
    {
        if(emp1->id == emp2->id)
            orden = 0;
        else
        {
            if(emp1->id > emp2->id)
                orden = -1;
            else
                orden = 1;
        }
    }
    return orden;
}

void mostrarEmpleados(LinkedList* listaEmpleados)
{
    Employee* empleado;
    int size = ll_len(listaEmpleados);
    int i;
    if(listaEmpleados != NULL)
    {
        printf("\n\n%12s%12s%12s%12s\n\n", "ID", "Nombre", "Horas", "Sueldo");
        for(i=0;i<size;i++)
        {
            empleado=(Employee*)ll_get(listaEmpleados,i);
            mostrarEmpleado(empleado);
        }
    }
}

int buscarEmpleado(int id, LinkedList* listaEmpleados)
{
    Employee* empleado;
    int index = -1;
    int size;
    int i;
    if(listaEmpleados != NULL)
    {
        size = ll_len(listaEmpleados);
        for(i=0;i<size;i++)
        {
            empleado=(Employee*)ll_get(listaEmpleados,i);
            if(empleado->id==id)
            {
                index=ll_indexOf(listaEmpleados, (void*)empleado);
                break;
            }
        }
    }
    return index;
}

Employee* employee_newParametros(char* idStr, char* nameStr, char* horasStr, char* sueldo)
{
    Employee* empleado = employee_new();
    if(idStr != NULL && nameStr != NULL && horasStr != NULL && sueldo != NULL && empleado != NULL)
    {
        if(!employee_setId(empleado,atoi(idStr)) || !employee_setNombre(empleado,nameStr) || !employee_setSueldo(empleado,atoi(sueldo)) || !employee_setHorasTrabajadas(empleado,atoi(horasStr)))
            empleado = NULL;
    }
    return empleado;
}

