#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "empleados.h"

int parser_EmpleadoFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Empleado* empleados;
    char datos[5][30];
    int cant;
    int todoOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", datos[0], datos[1], datos[2], datos[3],datos[4]);
            empleados = empleado_newParametros(datos[0],datos[1],datos[2],datos[3],datos[4]);
            if(empleados != NULL)
            {
                ll_add(pArrayListEmployee,empleados);
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
            todoOk = parser_EmpleadoFromText(file, pArrayListEmployee);
            fclose(file);
            }
        }
    }
    if(todoOk==0)
    {
        printf("\nNo pudieron cargarse los datos de EMPLEADO desde el archivo\n");
        system("pause");
    }
    else
    {
        printf("\nLos datos de EMPLEADO fueron cargados correctamente\n\n");
        system("pause");
        system("cls");
    }
    return todoOk;
}

int controller_saveResultado(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Empleado* empleados;
    int size, todoOk=0, i;
    int id, edad, horas;
    char nombre[32];
    char empleo[32];
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
                    empleados=(Empleado*)ll_get(pArrayListEmployee,i);
                    empleado_getId(empleados,&id);
                    empleado_getNombre(empleados,nombre);
                    empleado_getEmpleo(empleados,empleo);
                    empleado_getEdad(empleados,&edad);
                    empleado_getHoras(empleados,&horas);
                    fprintf(file,"%d,%s,%s,%d,%d\n",id,nombre,empleo,edad,horas);
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

int menuPrincipal()
{
    int opcion;
    printf("\n-----MENU------\n");
    printf("1) Leer archivo\n");
    printf("2) Listar empleados por nombre\n");
    printf("3) Cargar dedicacion\n");
    printf("4) Listar empleados por dedicacion\n");
    printf("5) Generar listados menores de 21 anios\n");
    printf("6) Guardar\n");
    printf("7) Salir\n");
    printf("8) Ingrese su opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

Empleado* empleado_new()
{
    Empleado* this = (Empleado*)malloc(sizeof(Empleado));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->empleo, "");
        this->edad = 0;
        this->horas = 0;
    }
    return this;
}

Empleado* empleado_newParametros(char* idStr, char* nameStr, char* empleo, char* edad, char* horas)
{
    Empleado* empleados = empleado_new();
    if(idStr != NULL && nameStr != NULL && empleo != NULL && edad != NULL && horas != NULL)
    {
        if(!empleado_setId(empleados,atoi(idStr)) || !empleado_setNombre(empleados,nameStr) || !empleado_setEmpleo(empleados,empleo) || !empleado_setEdad(empleados,atoi(edad)) || !empleado_setHoras(empleados,atoi(horas)))
            empleados = NULL;
    }
    return empleados;
}

int empleado_setId(Empleado* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre)>1)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int empleado_setEmpleo(Empleado* this, char* empleo)
{
    int todoOk = 0;
    if(this != NULL && empleo != NULL && strlen(empleo)>1)
    {
        strcpy(this->empleo,empleo);
        todoOk = 1;
    }
    return todoOk;
}

int empleado_setEdad(Empleado* this, int edad)
{
    int todoOk = 0;
    if(this != NULL && edad > 0)
    {
        this->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}

int empleado_setHoras(Empleado* this, int horas)
{
    int todoOk = 0;
    if(this != NULL && horas > 0)
    {
        this->horas = horas;
        todoOk = 1;
    }
    return todoOk;
}

int empleado_setDedicacion(Empleado* this,char* dedicacion)
{
    int todoOk = 0;
    if(this != NULL && dedicacion != NULL && strlen(dedicacion)>1)
    {
        strcpy(this->dedicacion,dedicacion);
        todoOk = 1;
    }
    return todoOk;
}

int empleado_getId(Empleado* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOK=1;
    }
    return todoOK;
}

int empleado_getNombre(Empleado* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        todoOK=1;
    }
    return todoOK;
}

int empleado_getEmpleo(Empleado* this,char* empleo)
{
    int todoOK=0;
    if(this!=NULL && empleo!=NULL)
    {
        strcpy(empleo, this->empleo);
        todoOK=1;
    }
    return todoOK;
}

int empleado_getEdad(Empleado* this,int* edad)
{
    int todoOK=0;
    if(this!=NULL && edad!=NULL)
    {
        *edad=this->edad;
        todoOK=1;
    }
    return todoOK;
}

int empleado_getHoras(Empleado* this,int* horas)
{
    int todoOK=0;
    if(this!=NULL && horas!=NULL)
    {
        *horas=this->horas;
        todoOK=1;
    }
    return todoOK;
}

int empleado_getDedicacion(Empleado* this,char* dedicacion)
{
    int todoOK=0;
    if(this!=NULL && dedicacion!=NULL)
    {
        strcpy(dedicacion, this->dedicacion);
        todoOK=1;
    }
    return todoOK;
}

void mostrarEmpleado(Empleado* this)
{
    if(this != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%d\n",this->id,this->nombre,this->empleo,this->edad,this->horas);
    }
}

void mostrarEmpleadoDedicacion(Empleado* this)
{
    if(this != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%d\t%s\n",this->id,this->nombre,this->empleo,this->edad,this->horas,this->dedicacion);
    }
}

void mostrarEmpleados(LinkedList* this)
{
    Empleado* empleados;
    int size = ll_len(this);
    int i;
    if(this!=NULL)
    {
        printf("|ID|\t|NOMBRE|\t|EMPLEO|\t|EDAD|\t|HORAS|\n");
        for(i=0;i<size;i++)
        {
            empleados=(Empleado*)ll_get(this, i);
            mostrarEmpleado(empleados);
        }
    }
}

void mostrarEmpleadosDedicacion(LinkedList* this)
{
    Empleado* empleados;
    int size = ll_len(this);
    int i;
    if(this!=NULL)
    {
        printf("|ID|\t|NOMBRE|\t|EMPLEO|\t|EDAD|\t|HORAS|\tDEDICACION\n");
        for(i=0;i<size;i++)
        {
            empleados=(Empleado*)ll_get(this, i);
            mostrarEmpleadoDedicacion(empleados);
        }
    }
}

int ordenarPorNombre(void* empleado1,void* empleado2)
{
    int retornar;
    char* nombre1=(char*)malloc(sizeof(char)*50);
    char* nombre2=(char*)malloc(sizeof(char)*50);

    Empleado* unEmpleado=(Empleado*)empleado1;
    Empleado* otroEmpleado=(Empleado*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        empleado_getNombre(unEmpleado,nombre1);
        empleado_getNombre(otroEmpleado,nombre2);
        retornar=strcmp(nombre1,nombre2);
    }
    free(nombre1);
    free(nombre2);

    return retornar;
}

int ordenarPorDedicacion(void* empleado1,void* empleado2)
{
    int retornar;
    char* dedicacion1=(char*)malloc(sizeof(char)*50);
    char* dedicacion2=(char*)malloc(sizeof(char)*50);

    Empleado* unEmpleado=(Empleado*)empleado1;
    Empleado* otroEmpleado=(Empleado*)empleado2;

    if(unEmpleado!=NULL && otroEmpleado!=NULL)
    {
        empleado_getDedicacion(unEmpleado,dedicacion1);
        empleado_getDedicacion(otroEmpleado,dedicacion2);
        retornar=strcmp(dedicacion1,dedicacion2);
    }
    free(dedicacion1);
    free(dedicacion2);
    return retornar;
}

int laQueMapea(void* empleados)
{
    int horas;
    empleado_getHoras(empleados,&horas);
    if(horas>0 && horas <=200)
        empleado_setDedicacion(empleados,"estandar");
    if(horas>200 && horas < 301)
        empleado_setDedicacion(empleados,"sobre la media");
    else
        empleado_setDedicacion(empleados,"excesivo");
    return 1;
}

int menores21(void* empleados)
{
    int edad;
    empleado_getEdad(empleados,&edad);
    if(edad<=21)
        return 1;
    return 0;
}
