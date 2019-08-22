#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int estado;
} eEmpleado;

void inicializarEmpleados(eEmpleado* vec, int tam);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);
int buscarLibre(eEmpleado* vec, int tam);
void mostrarEmpleados(eEmpleado* vec, int tam);
void mostrarEmpleado(eEmpleado* emp);
int menu();
void altaEmpleado(eEmpleado* vec, int tam);
void guardarEmpleadosBinario(eEmpleado* vec, int tam);
void cargarEmpleados(eEmpleado* vec, int tam);

int main()
{
    char seguir = 's';
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)* TAM);

    if( lista == NULL)
    {
        printf("No se consiguio memoria");
        system("Pause");
        exit(EXIT_FAILURE);
    }

    inicializarEmpleados(lista, TAM);

    printf("Empleados inicializados\n\n");

    do
    {
        switch(menu())
        {

        case 1:
            cargarEmpleados(lista, TAM);
            system("pause");
            break;
        case 2:
            altaEmpleado(lista, TAM);
            system("pause");
            break;
        case 3:
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;
        case 4:
            guardarEmpleadosBinario(lista, TAM);
            system("pause");
            break;
        case 5:
            imprimirEmpleados(lista, TAM);
            system("pause");
            break;
        case 6:
            printf("Opcion 6\n");
            system("pause");
            seguir = 'n';
            break;


        }


    }
    while( seguir == 's');






    free(lista);

    return 0;
}

void inicializarEmpleados(eEmpleado* vec, int tam)
{

    for(int i=0; i < tam; i++)
    {
        (vec + i)->estado = 0;
    }
}

eEmpleado* newEmpleado()
{

    eEmpleado* emp = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(emp != NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo = 0;
        emp->estado = 0;
    }
    return emp;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo)
{

    eEmpleado* emp = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(emp != NULL)
    {
        emp->id = id;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo = sueldo;
        emp->estado = 1;
    }
    return emp;
}

int buscarLibre(eEmpleado* vec, int tam)
{
    int indice = -1;

    if( vec != NULL && tam >0)
    {
        for(int i=0; i < tam; i++)
        {
            if( (vec + i)->estado == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarEmpleados(eEmpleado* vec, int tam)
{

    if( vec != NULL && tam >0)
    {
        printf("Id  Nombre  Apellido  Sueldo\n\n");
        for(int i=0; i < tam; i++)
        {
            if( (vec + i)->estado == 1)
            {
                mostrarEmpleado( vec + i);
            }
        }
    }

}

void mostrarEmpleado(eEmpleado* emp)
{

    if( emp != NULL)
    {
        printf("%d %s %s %.2f\n", emp->id, emp->nombre, emp->apellido, emp->sueldo);
    }

}


int menu()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1_ Cargar empleados\n");
    printf("2_ Alta empleado\n");
    printf("3_ Listar empleados\n");
    printf("4_ Guardar empleados archivo\n");
    printf("5_ Imprimir empleados\n");
    printf("6_ Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void altaEmpleado(eEmpleado* vec, int tam)
{

    int indice;
    int auxInt;
    char auxCad[20];
    char auxCad2[20];
    float auxFloat;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("No hay lugar\n");
    }
    else
    {

        printf("Ingrese id: ");
        scanf("%d", &auxInt);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxCad);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxCad2);

        printf("Ingrese sueldo: ");
        scanf("%f", &auxFloat);

        eEmpleado* nuevoEmpleado = newEmpleadoParam(auxInt, auxCad, auxCad2, auxFloat);

        if(nuevoEmpleado != NULL)
        {
            *(vec + indice) = *nuevoEmpleado;

            free(nuevoEmpleado);
        }
    }

}

void imprimirEmpleados(eEmpleado* vec, int tam)
{
    FILE* f;

    if( vec != NULL && tam >0)
    {
        f = fopen("./listaEmpleados.txt", "w");
        if(f != NULL)
        {
            fprintf(f,"Id  Nombre  Apellido  Sueldo\n\n");
            for(int i=0; i < tam; i++)
            {
                if( (vec + i)->estado == 1)
                {
                    fprintf(f,"%d %s %s %.2f\n", (vec +i)->id, (vec +i)->nombre, (vec +i)->apellido, (vec +i)->sueldo);
                }
            }
            fprintf(f,"\n\n");
        }
        fclose(f);
    }
}

void guardarEmpleadosBinario(eEmpleado* vec, int tam)
{
    FILE* f;

    if( vec != NULL && tam >0)
    {
        f = fopen("./empleados.bin", "wb");
        if(f != NULL)
        {

            for(int i=0; i < tam; i++)
            {
                if( (vec + i)->estado == 1)
                {
                    fwrite( (vec+ i), sizeof(eEmpleado), 1, f);
                }
            }

        }
        fclose(f);
    }
}


void cargarEmpleados(eEmpleado* vec, int tam)
{
    int indice;
    FILE* f;
    int cant;

    f = fopen("./empleados.bin", "rb");

    while( !feof(f))
    {

        indice = buscarLibre(vec, tam);

        cant = fread( (vec + indice), sizeof(eEmpleado), 1, f);

     if( cant < 1){
        if(feof(f)){

            break;
        }
        else{
            printf("Problemas para leer el archivo");
        }
       }
    }

    fclose(f);
}




