#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAM 15
#define TAMSEC 5

typedef struct
{
   int dia;
   int mes;
   int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

typedef struct{

    int id;
    char descripcion[20];
} eComida;

typedef struct{

    int idAlmuerzo;
    int idComida;
    int legajoEmp;
    eFecha fecha;
} eAlmuerzo;

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarSectores( eSector sectores[], int tam);
void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec);




int main()
{
    char seguir = 's';
    char confirma;
    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},

    };
    eEmpleado lista[TAM]=
    {
        {1234, "Juan", 'm', 30000,{12,3,2000},5, 1},
        {2222, "Ana", 'f', 32000, {2,7,2010}, 2,1},
        {2211, "Jorge", 'm', 28000,{14,5,2013}, 2,1},
        {3241, "Alberto", 'm', 35000, {2,9,2010},1, 1},
        {8944, "Sonia", 'f', 39000, {12,3,2012},3,1},
        {2231, "Miguel", 'm', 29700, {28,7,2009}, 2,1},
        {6578, "Adrian", 'm', 43200, {11,1,2016},5, 1},
        {3425, "Lucia", 'f', 32300, {19,10,2004}, 2,1},
        {5546, "Gaston", 'm', 29760, {13,9,2006},4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 0},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,0},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,0}
    };
    //inicializarEmpleados(lista, TAM);




    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            //printf("\nListar empleados\n\n");
            mostrarSectoresConEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
         case 7:
            //printf("\nListar empleados\n\n");
            mostrarCantEmpleadosXSector(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

         case 8:
            //printf("\nListar empleados\n\n");
            SectorMasEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 9:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Sectores con Empleados\n");
    printf("7- Cantidad de empleados por sector\n");
    printf("8- Sectores con mas empleados\n");
    printf("9- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    int consigioNombre;

   consigioNombre =  obtenerSector(sectores, tam, emp.idSector, nombreSector);

    if( !consigioNombre){
         strcpy(nombreSector, "Sin definir");
     }
    printf("   %d   %10s     %c     %.2f     %02d/%02d/%4d    %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    system("cls");

    printf(" Legajo      Nombre     Sexo    Sueldo     FechaIngreso   Sector\n");
    printf(" ------      ------     ----    ------     ------------   ------\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{

    int indice;
    int legajo;
    int esta;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

             printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);

            mostrarSectores(sectores, tamSector);

            printf("Ingrese id sector: ");
            scanf("%d", &vec[indice].idSector);


            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    system("cls");

    for(int i=0; i < tamSec; i++){
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++){
            if( empleados[j].idSector == sectores[i].id && empleados[j].ocupado== 1){
                mostrarEmpleado(sectores, tamSec, empleados[j]);
            }
        }
        printf("\n\n");

    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int contador;

    for(int i=0; i < tamSec; i++){
        contador = 0;
        printf("Sector: %s\n\n", sectores[i].descripcion);

        for(int j=0; j < tam; j++){
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1){
                contador++;
            }
        }

        printf("Cantidad: %d\n\n", contador);
    }


}

void mostrarSectores( eSector sectores[], int tam){

    printf("\n    Sectores\n");
    printf(" id     descripcion\n\n");

    for(int i=0; i < tam; i++){
        printf("  %d      %10s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\n\n");
}


void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec){


int totales[tamSec];
int mayor;
int flag = 0;



    for(int i=0; i < tamSec; i++){

          totales[i] = 0;
        for(int j=0; j < tam; j++){
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1){
                totales[i]++;
            }
        }


    }

     for(int i=0; i < tamSec; i++){
            if( flag == 0 || mayor < totales[i]){
                mayor = totales[i];
                flag = 1;
            }
     }

     printf("Cantidad mayor de empleados %d\n\n", mayor);
     printf("En el o los siguientes sectore\n\n");

      for(int i=0; i < tamSec; i++){
            if( totales[i] == mayor){
                printf("%s\n", sectores[i].descripcion);
            }

      }
}


int pedirInt(char mensaje[]){

    int num;

    printf("%s\n", mensaje);
    scanf("%d", &num);

    return num;
}

float pedirFloat(char mensaje[]){

    float num;

    printf("%s\n", mensaje);
    scanf("%d", &num);

    return num;
}

char pedirString(char mensaje[]){

    char cadena[20];

    printf("%s\n", mensaje);
    gets(cadena);

    return cadena;
}

char pedirSexo(void){

    char sexo;

    printf("Ingrese el sexo: \n");
    scanf("%c", &sexo);

    while(sexo != 'f' || sexo != 'm'){

        printf("Error, Reingrese el sexo: \n");
        scanf("%c", &sexo);
    }


    return sexo;
}

void validarLegajo(int num){

    while(num < 1000 || num > 9999){

        pedirInt("Error, Reingrese el legajo: \n");
    }
}

void validarSueldo(int num){

    while(num < 1000 || num > 100000){

        pedirInt("Error, Reingrese el legajo: \n");
    }
}

void validarString(char cadena[]){

    while(strlen(cadena) > 20){

        pedirString("Error, Reingrese nombre: \n");
    }
}


