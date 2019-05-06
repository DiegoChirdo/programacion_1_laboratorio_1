#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
#include "socios.h"
#define SOCIOS 10
#define LIBROS 10
#define AUTORES 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct
{
    int codigo;
    char apellido[51];
    char nombre[51];
}Autor;

typedef struct
{
    int codigo;
    char titulo[51];
    Autor codigoAutor;
}Libros;

typedef struct
{
    int codigo;
    char apellido[51];
    char nombre[51];
    char sexo;
    char telefono[16];
    char email[51];
    Fecha asociado;
    int isEmpty;
}Socios;

typedef struct
{
    int codigoPrestamo;
    Libros codigoLibro;
    Socios codigoSocio;
    Fecha prestamo;
}Prestamo;

int main()
{
    char auxiliarNombre[31]:
    char auxiliarApellido[31];
    char auxiliarNumero[16];
    char auxiliarSexo;
    char auxiliarEmail[31];
    int auxiliarDia;
    int auxiliarMes;
    int auxiliarAnio;
    char opcion;
    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int i,j;
    Socios lista[SOCIOS];

    Autor autores[AUTORES]=
    {
        {1000,"Perez","Marcos"},
        {1001,"Gimenez","Pablo"},
        {1002,"Cortazar","Julio"},
        {1003,"Miguel","Roberto"},
        {1004,"Neira","Enrique"},
        {1005,"Perez","Marcos"},
    };

    Libros libritos[LIBROS]=
    {
        {2000,"El hombre araña",{1000}},
        {2001,"Titanic",{1001}},
        {2002,"Interstellar",{1002}},
        {2003,"Titanic",{1003}},
    };



    inicializarSocios(lista,SOCIOS);
    while(opcion!='h')
    {
        opcion=getChar("a) ALTA\nb) MODIFICAR\nc) BAJA\nd) LISTAR\ne) LISTAR LIBROS\nf) LISTAR AUTORES\ng) PRESTAMOS\n");
        switch(opcion)
        {
        case 'a':
            printf("ALTA:\n");
            indiceLugarLibre=buscarLibre(lista,SOCIOS);
            if(indiceLugarLibre==-1)
            {
                printf("NO HAY LUGARES LIBRES.\n");
                break;
            }
            if(!getStringLetras("INGRESE UN NOMBRE: \n",auxiliarNombre))
            {
                printf("EL NOMBRE DEBE ESTAR COMPUESTO SOLO POR LETRAS. \n");
                break;
            }
            if(!getStringLetras("INGRESE UN APELLIDO: \n",auxiliarApellido))
            {
                printf("EL APELLIDO DEBE ESTAR COMPUESTO UNICAMENTE POR LETRAS.\n");
                break;
            }


        }


    }

}
