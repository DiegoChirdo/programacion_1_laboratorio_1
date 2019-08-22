#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define ALMUERZOS 5
#define EMPLEADOS 10
typedef struct
{
    int codigo;
    char descripcion[50];
    int importe;
}Menu;

typedef struct
{
    int id;
    char descripcion[50];
}Sector;

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct
{
    int legajo;
    char nombre[50];
    char apellido[50];
    char sexo;
    int salario;
    Fecha fechaIngreso;
    Sector idSector;
    int isEmpty;
}Empleado;

typedef struct
{
    int codigo;
    Menu codigoMenu;
    Empleado legajo;
    Fecha fecha;
}Almuerzo;


int main()
{
    Empleado empleado[EMPLEADOS];
    Almuerzo almuerzo[ALMUERZOS];
    int opcion;
    int indiceLugarLibre;
    int resultadoBusqueda;
    inicializarEmpleados(empleado,EMPLEADOS);

    while(opcion!=8)
    {
        opcion=getInt("HOLA");
        switch(opcion)
        {
        case 1:
            printf("ALTA DE EMPLEADO;");
            indiceLugarLibre=buscarLibre(empleado,EMPLEADOS);
            if(indiceLugarLibre==-1)
            {
                printf("NO HAY MAS LUGAR.");
                break;
            }




        }
    }




}
