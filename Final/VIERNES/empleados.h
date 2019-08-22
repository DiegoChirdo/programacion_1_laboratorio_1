#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char empleo[30];
    int edad;
    int horas;
    char dedicacion[32];
}Empleado;

int menuPrincipal();
int parser_EmpleadoFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveResultado(char* path , LinkedList* pArrayListEmployee);
Empleado* empleado_new();
Empleado* empleado_newParametros(char* idStr, char* nameStr, char* empleo, char* edad, char* horas);
int empleado_setId(Empleado* this, int id);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_setEmpleo(Empleado* this, char* empleo);
int empleado_setEdad(Empleado* this, int edad);
int empleado_setHoras(Empleado* this, int horas);
int empleado_setDedicacion(Empleado* this,char* dedicacion);
int empleado_getId(Empleado* this,int* id);
int empleado_getNombre(Empleado* this,char* nombre);
int empleado_getEmpleo(Empleado* this,char* empleo);
int empleado_getEdad(Empleado* this,int* edad);
int empleado_getHoras(Empleado* this,int* horas);
int empleado_getDedicacion(Empleado* this,char* dedicacion);
void mostrarEmpleado(Empleado* this);
void mostrarEmpleadoDedicacion(Empleado* this);
void mostrarEmpleados(LinkedList* this);
void mostrarEmpleadosDedicacion(LinkedList* this);
int ordenarPorNombre(void* empleado1,void* empleado2);
int ordenarPorDedicacion(void* empleado1,void* empleado2);
int laQueMapea(void* empleados);
int menores21(void* empleados);

#endif // EMPLEADOS_H_INCLUDED
