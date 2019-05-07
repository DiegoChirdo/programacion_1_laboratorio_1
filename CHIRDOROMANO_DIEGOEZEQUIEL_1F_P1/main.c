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

void inicializarSocios(Socios vec[], int tam);
int buscarLibre(Socios vec[], int tam);
int buscarPrimerOcurrencia(Socios arrayPersonas[],int cantidadDeElementos,int valor);

int main()
{
    char auxiliarNombre[31];
    char auxiliarApellido[31];
    char auxiliarNumero[16];
    char auxiliarEmail[31];
    char textoCodigo[50];
    int auxiliarCodigo;
    int auxiliarDia;
    int auxiliarMes;
    int auxiliarAnio;
    char opcion;
    int opcion2;
    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int i,j;
    Socios arraySocios[SOCIOS];

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



    inicializarSocios(arraySocios,SOCIOS);
    while(opcion!='h')
    {
        opcion=getChar("a) ALTA\nb) MODIFICAR\nc) BAJA\nd) LISTAR\ne) LISTAR LIBROS\nf) LISTAR AUTORES\ng) PRESTAMOS\n");
        switch(opcion)
        {
        case 'a':
            printf("ALTA:\n");
            indiceLugarLibre=buscarLibre(arraySocios,SOCIOS);
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
            arraySocios[indiceLugarLibre].sexo=pedirSexo();
            if(!getStringTelefono("INGRESE UN NUMERO DE TELEFONO: \n",auxiliarNumero))
            {
                printf("EL NUMERO ESTA MAL ESCRITO.\n");
                break;
            }
            getString("INGRESE UN CORREO ELECTRONICO: \n",auxiliarEmail);
            strcpy(arraySocios[indiceLugarLibre].nombre,auxiliarNombre);
            strcpy(arraySocios[indiceLugarLibre].apellido,auxiliarApellido);
            strcpy(arraySocios[indiceLugarLibre].telefono,auxiliarNumero);
            strcpy(arraySocios[indiceLugarLibre].email,auxiliarEmail);
            arraySocios[indiceLugarLibre].codigo=indiceLugarLibre;
            printf("ALTA HA SIDO UN EXITO. EL CODIGO DE SOCIO ES: %d\n\n", arraySocios[indiceLugarLibre].codigo);
            break;
        case 'b':
            printf("MODIFICAR: \n");
            if!(getStringNumeros("INGRESE EL CODIGO DE SOCIO: \n",textoCodigo))
            {
                printf("EL CODIGO DE SOCIO SOLO PUEDEN SER NUMEROS. \n");
                break;
            }
            indiceResultadoBusqueda=buscarPrimerOcurrencia(arraySocios[SOCIOS],SOCIOS,atoi(textoCodigo));
            if (indiceResultadoBusqueda==-1)
            {
                printf("EL CODIGO NO EXISTE!!\n");
                break;
            }
            while(opcion2!=6)
            {
                opcion2=getInt("MODIFICAR:\n1) NOMBRE\n2) APELLIDO\n 3)SEXO\n 4) TELEFONO\n 5) eMAIL\n");
                switch(opcion2)
                {
                case 1:
                    if(!getStringLetras("INGRESE UN NOMBRE: \n",auxiliarNombre))
                    {
                        printf("EL NOMBRE DEBE ESTAR COMPUESTO SOLO POR LETRAS. \n");
                        break;
                    }
                    strcpy(arraySocios[indiceResultadoBusqueda].nombre,auxiliarNombre);
                    break;
                case 2:
                    if(!getStringLetras("INGRESE UN APELLIDO: \n",auxiliarApellido))
                    {
                        printf("EL APELLIDO DEBE ESTAR COMPUESTO UNICAMENTE POR LETRAS.\n");
                        break;
                    }
                    strcpy(arraySocios[indiceResultadoBusqueda].apellido,auxiliarApellido);
                    break;
                case 3:
                    arraySocios[indiceResultadoBusqueda].sexo=pedirSexo();
                    break;
                case 4:
                    if(!getStringTelefono("INGRESE UN NUMERO DE TELEFONO: \n",auxiliarNumero))
                    {
                        printf("EL NUMERO ESTA MAL ESCRITO.\n");
                        break;
                    }
                    strcpy(arraySocios[indiceResultadoBusqueda].telefono,auxiliarNumero);
                    break;
                case 5:
                     getString("INGRESE UN CORREO ELECTRONICO: \n",auxiliarEmail);
                     strcpy(arraySocios[indiceResultadoBusqueda].email,auxiliarEmail);
                     break;
                }
            }
        case 'c':
            printf("BAJA\n\n");





        }


    }

}


int buscarPrimerOcurrencia(Socios arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].codigo == valor)
        {
            return i;
        }
    }
    return -1;
}
