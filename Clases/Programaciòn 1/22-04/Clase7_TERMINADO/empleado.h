#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct{
    char nombre[20];
    char apellido[20];
    int isEmpty;
    int idEmpleado;
}Empleado;

int empleado_MostrarArray(Empleado *arrayEmpleados,int tamArray);//2
int empleado_OrdenarNombre(Empleado *arrayEmpleados,int tamArray);
int empleado_InicializarArray(Empleado *arrayEmpleados,int tamArray);//1
int empleado_Alta(Empleado *arrayEmpleados,int tamArray,int id);//3
int empleado_Baja(Empleado *arrayEmpleados,int tamArray);
int empleado_BuscarLibre(Empleado *arrayEmpleados,int tamArray, int *posicionLibre);//3.5
int empleado_Modificacion(Empleado *arrayEmpleados,int tamArray);
int empleado_GenerarId();

#endif // EMPLEADOS_H_INCLUDED
