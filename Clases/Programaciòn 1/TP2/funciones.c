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
    int i;
    char auxiliarEdad[50];
    char auxiliarDni[50];
    if(buscarLibre(vec, cant)==-1)
    {
        printf("\n No hay lugares libres. \n");
        return 0;
    }
    libre=buscarLibre(vec, cant);
    printf("1- Agregar persona\n\n");
    system("cls");
    if(!getStringLetras("Ingrese un nombre:\n", vec[libre].nombre))
    {
        printf("Solo puede estar compuesto por letras. \n");
        return 0;
    }
    if(!getStringNumeros("Ingrese una edad: \n", auxiliarEdad))
    {
        printf("La edad solo puede estar compuesta por números. \n");
        return 0;
    }
    if(!getStringNumeros("Ingrese un DNI: \n",auxiliarDni))
    {
        printf("El DNI solo puede estar compuesto por numeros. \n");
        return 0;
    }
    for(i=0;i<cant;i++)
    {
        if(atoi(auxiliarDni)==vec[i].dni)
        {
            system("cls");
            printf("\nEl documento ya existe. \n\n");
            return 0;
        }
    }
    vec[libre].edad=atoi(auxiliarEdad);
    vec[libre].dni=atoi(auxiliarDni);
    vec[libre].estado=-1;
    printf("\n\nHECHO!!!\n");
    return 0;
}

int borrarPersona(EPersona vec[], int cant)
{
    int dniBaja;
    int i;
    if(vec[0].estado == 0)
    {
        system("cls");
        printf("Aun no se han ingresado datos. \n");
        return 0;
    }
    system("cls");
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
        system("cls");
        printf("No se encontro el DNI. \n");
        return 0;
    }
    return 0;
}


int listarNombre(EPersona vec[], int cant)
{

    system("cls");
    EPersona aux;
    int i,j;
    if(vec[0].estado==0)
    {
        printf("\nAun no se han ingresado datos. \n");
        return 0;
    }
    printf("LISTAR POR NOMBRE.\n");
    printf("NOMBRE\t-\tEDAD\t-\tDNI\t\n");
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(vec[i].nombre<vec[j].nombre)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
    for(i=0;i<cant;i++)
    {
        if(vec[i].estado==-1)
        {
        printf("%s\t-\t%d\t-\t%d\t\n", vec[i].nombre, vec[i].edad, vec[i].dni);
        }
    }
    return 0;
}

void listarEdad(EPersona vec[], int cant)
{
    system("cls");
    printf("LISTAR EDADES: \n");
    int i;
    for(i=0;i<cant;i++)
    {
        if(vec[i].estado==-1)
        {
            printf("<18   -   19-35   -   >35\n");

        }
    }
}
