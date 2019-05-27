#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

void mostrarEmpleados(eEmpleado* lista, int len);
eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();

int main()
{
     FILE* f;

     char buffer[4][20];
     eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));
     eEmpleado* pAuxEmpleado;
     int cont = 0;
     int cant;

    f = fopen("./empleados.csv","r");

    if(f == NULL){
        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);
     while( !feof(f) ){

    cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

     if( cant < 4){
        break;
      }

      eEmpleado* nuevoEmpleado = new_EmpleadoParam(atoi(buffer[0]), buffer[1],buffer[2],atof(buffer[3]));

      *(lista + cont) = *nuevoEmpleado;
    cont++;

    pAuxEmpleado = (eEmpleado*) realloc(lista, sizeof(eEmpleado) *(cont+1));
    if(pAuxEmpleado == NULL){
        exit(1);
    }
    lista = pAuxEmpleado;
              //printf(" %5d   %10s   %20s  %8.2f\n", atoi(buffer[0]), buffer[1], buffer[2], atof(buffer[3]));
    }

    mostrarEmpleados(lista, cont);



    fclose(f);

    return 0;
}


void mostrarEmpleados(eEmpleado* lista, int len){

for(int i=0; i < len; i++){
    printf(" %5d   %10s   %20s  %8.2f\n", (lista + i)->legajo, (lista + i)->nombre, (lista + i)->apellido, (lista + i)->sueldo);
}
printf("\n\n");

}


eEmpleado* new_Empleado(){

eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

if(emp != NULL){
    emp->legajo = 0;
    strcpy(emp->nombre, "");
    strcpy(emp->apellido, "");
    emp->sueldo = 0;

}
return emp;
}

eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo){

eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

if(emp != NULL){
    emp->legajo = leg;
    strcpy(emp->nombre, nombre);
    strcpy(emp->apellido, apellido);
    emp->sueldo = sueldo;

}
return emp;
}

