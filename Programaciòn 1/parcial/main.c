#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#define CANTIDAD 20


typedef struct
{
    char nombre[50];
    char apellido[50];
    int legajo;
}Persona;

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor);

int main()
{
    Persona arrayPersonas[CANTIDAD];
    Persona auxiliarPersonas;

    char auxiliarNombre[50];
    char auxiliarApellido[50];
    char textoLegajo[50];
    int auxiliarLegajo;
    int indiceResultadoBusqueda;
    int indiceLugarLibre;
    int opcion;
    int i,j;

    inicializarArrayPersonas(arrayPersonas,CANTIDAD,-1);
    while(opcion!=6)
    {
        opcion=getInt("1) ALTA\n2)BAJA\n3)MODIFICACION\n4)LISTAR\n5)ORDENAR\n6)SALIR\n");
        switch(opcion)
        {
        case 1:
            printf("ALTA:\n");
            indiceLugarLibre=buscarPrimerOcurrencia(arrayPersonas,CANTIDAD,-1);
            if(indiceLugarLibre==-1)
            {
                printf("NO HAY LUGARES LIBRES.\n");
                break;
            }
            if(!getStringLetras("INGRESE UN NOMBRE: \n",auxiliarNombre))
            {
                printf("EL NOMBRE TIENE LETRAS.\n");
                break;
            }
            if(!getStringLetras("INGRESE UN APELLIDO: \n",auxiliarApellido))
            {
                printf("EL APELLIDO TIENE LETRAS.\n");
                break;
            }
            if(!getStringNumeros("INGRESE EL LEGAJO: \n", textoLegajo))
            {
                printf("EL LEGAJO TIENE NUMEROS.\n");
                break;
            }
            auxiliarLegajo=atoi(textoLegajo);
            if(buscarPrimerOcurrencia(arrayPersonas,CANTIDAD,auxiliarLegajo)!=-1)
            {
                printf("EL LEGAJO YA EXISTE.\n");
                break;
            }

            strcpy(arrayPersonas[indiceLugarLibre].nombre,auxiliarNombre);
            strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellido);
            arrayPersonas[indiceLugarLibre].legajo=auxiliarLegajo;
            break;

        case 2:
            printf("BAJA: \n");
            if(!getStringNumeros("INGRESE EL LEGAJO: \n",textoLegajo))
            {
                printf("EL LEGAJO SOLO PUEDE TENER NUMEROS.\n");
                break;
            }
            indiceResultadoBusqueda=buscarPrimerOcurrencia(arrayPersonas,CANTIDAD,atoi(textoLegajo));
            if(indiceResultadoBusqueda==-1)
            {
                printf("EL LEGAJO NO EXISTE.\n");
                break;
            }
            arrayPersonas[indiceResultadoBusqueda].legajo=-1;
            break;
        case 3:
            printf("MODIFICACION: \n");
            if(!getStringNumeros("INGRESE EL LEGAJO: \n",textoLegajo))
            {
                printf("EL LEGAJO SOLO PUEDE TENER NUMEROS.\n");
                break;
            }
            indiceResultadoBusqueda=buscarPrimerOcurrencia(arrayPersonas,CANTIDAD,atoi(textoLegajo));
            if(indiceResultadoBusqueda==-1)
            {
                printf("EL LEGAJO NO EXISTE!\n");
                break;
            }
            if(!getStringLetras("Ingrese el nuevo nombre: \n",auxiliarNombre))
            {
                printf("El nombre mal.\n");
                break;
            }
            if(!getStringLetras("Ingrese el nuevo apellido: \n",auxiliarApellido))
            {
                printf("El apellido mal.\n");
                break;
            }
            strcpy(arrayPersonas[indiceResultadoBusqueda].nombre,auxiliarNombre);
            strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxiliarApellido);
            break;
        case 4:
            printf("LISTAR: \n");
            for(i=0;i<CANTIDAD;i++)
            {
                if(arrayPersonas[i].legajo!=-1)
                {
                    printf("%d   -  %s    -  %s\n",arrayPersonas[i].legajo,arrayPersonas[i].nombre,arrayPersonas[i].apellido);
                }
                break;
        case 5:
            printf("ORDENADO.-.-.-\n");
            for(i=0;i<CANTIDAD-1;i++)
            {
                if(arrayPersonas[i].legajo==-1)
                {
                    continue;
                }
                for(j=i;j<CANTIDAD;j++)
                {
                    if(arrayPersonas[j].legajo==-1)
                    {
                        continue;
                    }
                    if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido)>0)
                    {
                        auxiliarPersonas=arrayPersonas[j];
                        arrayPersonas[j]=arrayPersonas[i];
                        arrayPersonas[i]=auxiliarPersonas;
                    }
                }
            }
            break;
            }

        }
    }


    return 0;
}

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].legajo = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param array Es el array en el cual buscar
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}
