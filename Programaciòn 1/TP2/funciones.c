#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"
void inicializarPersona(EPersona vec[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vec[i].estado=0;
    }
}

int buscarLibre(EPersona vec[], int tam)
{
    int indexLibre = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == 0)
        {
            indexLibre = i;
            break;
        }
    }
    return indexLibre;
}

int agregarPersona(EPersona vec[], int cant)
{
    int libre;
    char auxiliarEdad;
    char auxiliarDni;
    if(buscarLibre(vec, cant)==-1)
    {
        printf("\n No hay lugares libres. \n");
        return 0;
    }
    libre=buscarLibre(vec, cant);
    printf("1- Agregar persona\n\n");
    if(!getStringLetras("Ingrese un nombre:\n", vec[libre].nombre))
    {
        printf("Solo puede estar compuesto por letras. \n");
        return 0;
    }
    if(!getStringNumeros("Ingrese una edad: \n", atoi(auxiliarEdad)))
    {
        printf("La edad solo puede estar compuesta por números. \n");
        return 0;
    }
    if(!getStringNumeros("Ingrese un DNI: \n", atoi(auxiliarDni)))
    {
        printf("El DNI solo puede estar compuesto por numeros. \n");
        return 0;
    }
    vec[libre].edad=auxiliarEdad;
    vec[libre].dni=auxiliarDni;
    vec[libre].estado=-1;
    printf("HECHO!!!\n");
    return 0;
}

int borrarPersona(EPersona vec[], int cant)
{
    int dniBaja;
    int i;
    if(vec[0].estado == 0)
    {
        printf("Aun no se han ingresado datos. \n");
        return 0;
    }
    printf("Ingrese el DNI de la persona a borrar: \n");
    scanf("%d", &dniBaja);
    for(i=0; i<cant; i++)
    {
        if(vec[i].dni==dniBaja)
        {
            vec[i].estado=0;
            printf("HECHO!!!\n");
            return 0;
        }
        printf("No se encontro el DNI. \n");
        return 0;
    }
    return 0;
}


