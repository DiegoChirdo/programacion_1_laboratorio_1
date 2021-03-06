#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "socios.h"
#include "input.h"
#define CANTIDAD 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    int isEmpty;
}Autor;

typedef struct
{
    int codigo;
    char titulo[51];
    Autor codigoAutor;
    int isEmpty;
}Libro;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char email[31];
    Fecha fechaSocio;
    int isEmpty;
}Socio;

typedef struct
{
    int codigo;
    Libro codigoLibro;
    Socio codigoSocio;
    Fecha fechaPrestamo;
    int isEmpty;
}Prestamos;

int main()
{
    Autor autores[CANTIDAD]=
    {
        {1000,"Perez","Marcos",1},
        {1001,"Gimenez","Pablo",1},
        {1002,"Cortazar","Julio",1},
        {1003,"Miguel","Roberto",1},
        {1004,"Neira","Enrique",1},
        {1005,"Perez","Marcos",1},
    };

    Libro libritos[CANTIDAD]=
    {
        {2000,"El hombre ara�a",{1000},1},
        {2001,"Titanic",{1001},1},
        {2002,"Interstellar",{1002},1},
        {2003,"Titanic",{1003},1},
    };

Socio arraySocios[CANTIDAD];
Prestamos arrayPrestamos[CANTIDAD];
int opcion;
int opcionAutores;

inicializarSocios(arraySocios,CANTIDAD);
inicializarPrestamo(arrayPrestamos,CANTIDAD);

while(opcion!=8)
{
    opcion=menuOpcion();
    switch(opcion)
    {
    case 1:
        printf("ALTA:\n");
        altaSocio(arraySocios,CANTIDAD);
        system("cls");
        break;
    case 2:
        printf("MODIFICACION: \n");
        modificarSocio(arraySocios,CANTIDAD);
        break;
    case 3:
        printf("BAJA: \n");
        bajaSocio(arraySocios,CANTIDAD);
        break;
    case 4:
        printf("LISTAR: \n");
        listarSocios(arraySocios,CANTIDAD);
        break;
    case 5:
        printf("LISTAR LIBROS: \n");
        listarLibros(libritos,CANTIDAD);

        break;
    case 6:
        printf("LISTAR AUTORES: \n");
        listarAutores(autores,CANTIDAD);
        while(opcionAutores!=4)
        {
        opcionAutores=menuAutores();
        switch(opcionAutores)
        {
        case 1:
            printf("ALTA AUTOR:\n");
            altaAutor(autores,CANTIDAD);
            system("cls");
            break;
        case 2:
            printf("BAJA AUTOR: \n");
            bajaAutor(autores,CANTIDAD);
            break;
        case 3:
            printf("MODIFICAR AUTOR: \n");
            modificarAutor(autores, CANTIDAD);
            break;
        }
        }
        break;
    case 7:
        printf("ALTA PRESTAMO \n");
        mostrarPrestamos(arrayPrestamos, CANTIDAD);
        altaPrestamos(arrayPrestamos,libritos, arraySocios,CANTIDAD);
        break;
    }
}
    return 0;
}


int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
