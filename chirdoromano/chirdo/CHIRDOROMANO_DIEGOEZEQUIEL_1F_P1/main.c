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
    int isEmpty;
}Autor;

typedef struct
{
    int codigo;
    char titulo[51];
    Autor codigoAutor;
    int isEmpty;
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
    Socios auxiliarSocios;
    int auxiliarCodigo;
    int auxiliarDia;
    int auxiliarMes;
    int auxiliarAnio;
    char opcion;
    int opcionseg;
    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int i,j;
    Socios arraySocios[SOCIOS];

    Autor autores[AUTORES]=
    {
        {1000,"Perez","Marcos",1},
        {1001,"Gimenez","Pablo",1},
        {1002,"Cortazar","Julio",1},
        {1003,"Miguel","Roberto",1},
        {1004,"Neira","Enrique",1},
        {1005,"Perez","Marcos",1},
    };

    Libros libritos[LIBROS]=
    {
        {2000,"El hombre araña",{1000},1},
        {2001,"Titanic",{1001},1},
        {2002,"Interstellar",{1002},1},
        {2003,"Titanic",{1003},1},
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
            if(!getStringNumeros("INGRESE EL CODIGO DE SOCIO: \n",textoCodigo))
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
            while(opcionseg!=6)
            {
                opcionseg=getInt("MODIFICAR:\n1) NOMBRE\n2) APELLIDO\n 3)SEXO\n 4) TELEFONO\n 5) eMAIL\n");
                switch(opcionseg)
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
            if(!getStringNumeros("INGRESE EL CODIGO DE SOCIO: \n", textoCodigo))
            {
                printf("EL CODIGO DE SOCIO SOLO PUEDE TENER NUMEROS. \n");
                break;
            }
            indiceResultadoBusqueda=buscarPrimerOcurrencia(arraySocios[SOCIOS],SOCIOS,atoi(textoCodigo));
            if(indiceResultadoBusqueda==-1)
            {
                printf("EL CODIGO NO EXISTE.\n");
                break;
            }
            arraySocios[indiceResultadoBusqueda].isEmpty=0;
            break;
        case 'd':
            for(i=0;i<SOCIOS-1;i++)
            {
                if(arraySocios[i].isEmpty==0)
                {
                    continue;
                }
                for(j=i+1;j<SOCIOS;j++)
                {
                    if(arraySocios[j].isEmpty==0)
                    {
                        continue;
                    }
                    if(strcmp(arraySocios[i].apellido,arraySocios[j].apellido)>0)
                    {
                        auxiliarSocios=arraySocios[j];
                        arraySocios[j]=arraySocios[i];
                        arraySocios[i]=auxiliarSocios;
                    }
                }
            }
            printf("LISTADO: \n\n");
            for(i=0;i<SOCIOS;i++)
            {
                if(arraySocios[i].isEmpty!=0)
                {
                    printf("CODIGO  -  APELLIDO   -  NOMBRE  -  SEXO  -  TELEFONO  -  EMAIL");
                    printf("%d -  %s  - %s  -  %s  -  %s  -  %s\n",arraySocios[i].codigo, arraySocios[i].apellido, arraySocios[i].nombre, arraySocios[i].sexo, arraySocios[i].telefono, arraySocios[i].email);
                }
            }
            break;
        case 'e':
            printf("LISTADO DE LIBROS: \n");
            for(i=0;i<LIBROS;i++)
            {
                if(libritos[i].isEmpty==1)
                {
                    printf("CODIGO  -  LIBRO  -  COD. AUTOR \n");
                    printf("%d  -  %s  -  %d  \n",libritos[i].codigo,libritos[i].titulo,libritos[i].codigoAutor);
                }
            }
            break;
        case 'f':
            printf("LISTADO DE AUTORES: \n");
            for(i=0;i<AUTORES;i++)
            {
                if(libritos[i].isEmpty==1)
                {
                    printf("CODIGO  -  NOMBRE  -  APELLIDO\n");
                    printf("%d  -  %s  -  %s  \n",autores[i].codigo,autores[i].nombre,autores[i].apellido);
                }

            }
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
