#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socios.h"
#include "input.h"

int menuOpcion()
{
    int rta;

    printf("\tMENU DE OPCIONES\n");
    printf("1) ALTA\n");
    printf("2) MODIFICAR\n");
    printf("3) BAJA\n");
    printf("4) LISTAR\n");
    printf("5) LISTAR LIBROS\n");
    printf("6) LISTAR AUTORES\n");
    printf("7) PRESTAMOS\n");
    printf("8) SALIR\n");
    scanf("%d", &rta);

    return rta;
}

int menuAutores()
{
    int rta;
    printf("1) ALTA DE AUTOR\n2) MODIFICAR AUTOR\n 3)BAJA\n4) SALIR\n;");
    scanf("%d",&rta);
    return rta;
}

int inicializarSocios(Socio vec[], int tam)
{
    int result=-1;

    for(int i=0; i<tam ; i++)
    {
        vec[i].isEmpty=0;
        result=0;
    }

    return result;
}

void altaSocio(Socio vec[],int cant)
{
    int codigo;
    int libre;
    char sexo;
    if(buscarLibre(vec, cant)==-1)
    {
        printf("\nNo hay lugares libres\n");
        system("pause");
    }
    libre=buscarLibre(vec, cant);
    codigo=generarCodigo(vec, cant);
    vec[libre].codigo=codigo;
    if(!getStringLetras("Ingrese un nombre: \n",vec[libre].nombre))
    {
        printf("Solo letras.\n");
        system("pause");
    }
    if(!getStringLetras("Ingrese un apellido: \n",vec[libre].apellido))
    {
        printf("Solo letras.\n");
        system("pause");
    }
    printf("Ingrese un sexo (m/f):\n");
    fflush(stdin);
    scanf("%c",&sexo);
    while(sexo!='f' && sexo!='m')
    {
        printf("Reingrese el sexo: \n");
        scanf("%c",&sexo);
    }
    vec[libre].sexo=sexo;
    if(!getStringTelefono("Ingrese un telefono: \n",vec[libre].telefono))
    {
        printf("Ingrese correctamente.\n");
        system("pause");
    }
    getString("Ingrese un email: \n", vec[libre].email);
    printf("Fecha de ingreso: \n");
    printf("Ingrese un dia: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.dia);
    printf("Ingrese un mes: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.mes);
    printf("Ingrese un anio: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.anio);
    vec[libre].isEmpty=1;
    printf("HECHO!!!\n");
}

void modificarSocio(Socio vec[],int cant)
{
    int codigoModificar;
    int indexBuscar;
    int campoModificar;

    printf("Ingrese el codigo de socio: \n");
    scanf("%d", &codigoModificar);
    indexBuscar=buscarSocio(vec, CANTIDAD, codigoModificar);

    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
    }

    while(campoModificar!=6)
    {

        printf("Ingrese el campo a modificar: \n");
        printf("1) Apellido\n2) Nombre\n3) Sexo\n4) Telefono\n5) eMail\n6) Salir\n");
        scanf("%d", &campoModificar);
        switch(campoModificar)
        {
        case 1:
            if(!getStringLetras("Ingrese nuevo apellido: \n",vec[indexBuscar].apellido))
            {
                printf("Solo letras.\n");
                break;
            }
            break;
        case 2:
            if(!getStringLetras("Ingrese nuevo nombre: \n",vec[indexBuscar].nombre))
            {
                printf("Solo letras.\n");
                break;
            }
            break;
        case 3:
            vec[indexBuscar].sexo=pedirSexo();
            break;
        case 4:
            if(!getStringTelefono("Ingrese nuevo telefono: \n",vec[indexBuscar].telefono))
            {
                printf("Ingrese correctamente.\n");
                break;
            }
            break;
        case 5:
            getString("Ingrese nuevo correo: \n",vec[indexBuscar].email);
            break;
        }

    }

}

void bajaSocio(Socio vec[],int cant)
{
    int codigoBaja;
    int indexBuscar;

    printf("Ingrese codigo de socio para la baja: \n");
    scanf("%d", &codigoBaja);
    indexBuscar=buscarSocio(vec, cant, codigoBaja);
    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
    }
    vec[indexBuscar].isEmpty=0;
    printf("Hecho!!!\n");
}

int buscarLibre(Socio vec[], int tam)
{
    int indexLibre=-1;

    for(int i=0 ; i<tam ; i++){
        if(vec[i].isEmpty==0)
        {
            indexLibre=i;
            break;
        }
    }
    return indexLibre;
}

int generarCodigo(Socio vec[], int cant)
{
    int indexLibre=buscarLibre(vec, cant);
    int codigoAnterior;
    int codigo;

    if(indexLibre==0)
    {
        codigo=1000;
    }else
    {
        codigoAnterior=vec[indexLibre-1].codigo;
        codigo=codigoAnterior+1;
    }

    return codigo;

}


int buscarSocio(Socio vec[], int cant, int codigoBuscar){

    int indexSocio=-1;

    for(int i=0; i<cant ; i++)
    {
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexSocio=i;
            break;
        }
    }

    return indexSocio;
}

void listarSocios(Socio vec[], int cant)
{
    int i;

    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("APELLIDO  -  NOMBRE  -  SEXO  -  TELEFONO  -  EMAIL\n");
            printf("%s   -  %s   -  %c  -  %s  -  %s\n\n",vec[i].apellido,vec[i].nombre,vec[i].sexo,vec[i].telefono,vec[i].email);
        }
    }
}

void listarLibros(Libro vec[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("CODIGO  -  LIBRO  -  COD. AUTOR\n");
            printf("%d  -  %s   -  %d\n",vec[i].codigo,vec[i].titulo,vec[i].codigoAutor.codigo);
        }
    }
}

void listarAutores(Autor vec[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("CODIGO  -  APELLIDO  -  NOMBRE\n");
            printf("%d  -  %s   -  %s\n",vec[i].codigo,vec[i].apellido,vec[i].nombre);
        }
    }
}

void altaPrestamos(Prestamos vec[],Libro array[], Socio arr[], int cant)
{
    int indexLibre;
    int busquedaLibro;
    int busquedaSocio;
    int codigo;
    int codigoLibro;
    int codigoSocio;

    indexLibre=buscarLibrePrestamo(vec,cant);
    codigo=generarCodigoPrestamo(vec,cant);
    printf("INGRESE UN CODIGO DE LIBRO: \n");
    scanf("%d",&codigoLibro);
    busquedaLibro=codigoLibro;
    if(buscarCodigoLibro(array,cant,busquedaLibro)==-1)
    {
        printf("NO SE ENCONTRO.\n");
        system("pause");
    }
    printf("INGRESE UN CODIGO DE SOCIO: \n");
    scanf("%d",&codigoSocio);
    busquedaSocio=codigoSocio;
    if(buscarCodigoSocio(arr,cant,busquedaSocio)==-1)
    {
        printf("NO SE ENCONTRO. \n");
        system("pause");
    }
    printf("Fecha de prestamo: \n");
    printf("Ingrese un dia: \n");
    fflush(stdin);
    scanf("%d",&vec[indexLibre].fechaPrestamo.dia);
    printf("Ingrese un mes: \n");
    fflush(stdin);
    scanf("%d",&vec[indexLibre].fechaPrestamo.mes);
    printf("Ingrese un anio: \n");
    fflush(stdin);
    scanf("%d",&vec[indexLibre].fechaPrestamo.anio);
    vec[indexLibre].codigo=codigo;
    vec[indexLibre].codigoLibro.codigo=busquedaLibro;
    vec[indexLibre].codigoSocio.codigo=busquedaSocio;
    vec[indexLibre].isEmpty=1;
    printf("HECHO!!!\n");

}

void mostrarPrestamos(Prestamos vec[], int cant)
{

int i;

    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("CODIGO  -  COD. LIBRO  -  COD. SOCIO  -  Fecha de prestamo\n");
            printf("%d   -  %d   -  %d  -  %d/%d/%d\n",vec[i].codigo,vec[i].codigoLibro.codigo,vec[i].codigoSocio.codigo,vec[i].fechaPrestamo.dia,vec[i].fechaPrestamo.mes,vec[i].fechaPrestamo.anio);
        }
    }

}


int generarCodigoPrestamo(Prestamos vec[],int cant)
{
    int indexLibre;
    int codigoAnterior;
    int codigo;

    indexLibre=buscarLibrePrestamo(vec,cant);
    if(indexLibre==0)
    {
        codigo=1000;
    }
    else
    {
        codigoAnterior=vec[indexLibre-1].codigo;
        codigo=codigoAnterior+1;
    }
    return codigo;
}

int buscarLibrePrestamo(Prestamos vec[], int tam)
{
    int indexLibre=-1;

    for(int i=0 ; i<tam ; i++){
        if(vec[i].isEmpty==0)
        {
            indexLibre=i;
            break;
        }
    }
    return indexLibre;
}

 void inicializarPrestamo (Prestamos vec[], int cant)
{
    for(int i=0; i<cant ; i++)
    {
        vec[i].isEmpty=0;
    }
}

int buscarCodigoLibro(Libro vec[], int cant, int codigoBuscar)
{
    int indexLibro=-1;

    for(int i=0; i<cant ; i++){
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexLibro=i;
            break;
        }
    }

    return indexLibro;
}

int buscarCodigoSocio(Socio vec[], int cant, int codigoBuscar)
{
    int indexSocio=-1;

    for(int i=0; i<cant ; i++){
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexSocio=i;
            break;
        }
    }

    return indexSocio;
}

void altaAutor(Autor vec[],int cant)
{
    int codigo;
    int libre;
    libre=buscarLibreAutor(vec, cant);
    if(libre==-1)
    {
        printf("NO HAY MAS LUGAR.\n");
        system("pause");
    }
    codigo=generarCodigoAutor(vec,cant);
    vec[libre].codigo=codigo;
    if(!getStringLetras("Ingrese nombre: \n",vec[libre].nombre))
    {
        printf("Solo letras.\n");
        system("pause");
    }
    if(!getStringLetras("Ingrese apellido: \n",vec[libre].apellido))
    {
        printf("Solo letras.\n");
        system("pause");
    }
    vec[libre].isEmpty=1;
    printf("HECHO!!!\n");
}

int generarCodigoAutor(Autor vec[], int cant)
{
    int indexLibre=buscarLibreAutor(vec, cant);
    int codigoAnterior;
    int codigo;

    if(indexLibre==0)
    {
        codigo=1000;
    }else
    {
        codigoAnterior=vec[indexLibre-1].codigo;
        codigo=codigoAnterior+1;
    }

    return codigo;

}

int buscarLibreAutor(Autor vec[], int tam)
{
    int indexLibre=-1;

    for(int i=0 ; i<tam ; i++){
        if(vec[i].isEmpty==0)
        {
            indexLibre=i;
            break;
        }
    }
    return indexLibre;
}

void bajaAutor(Autor vec[],int cant)
{
    int codigoBaja;
    int indexBuscar;

    printf("Ingrese codigo de autor para la baja: \n");
    scanf("%d", &codigoBaja);
    indexBuscar=buscarAutor(vec, cant, codigoBaja);
    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
    }
    vec[indexBuscar].isEmpty=0;
    printf("Hecho!!!\n");
}

int buscarAutor(Autor vec[], int cant, int codigoBuscar){

    int indexAutor=-1;

    for(int i=0; i<cant ; i++)
    {
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexAutor=i;
            break;
        }
    }

    return indexAutor;
}

void modificarAutor(Autor vec[],int cant)
{
    int codigoModificar;
    int indexBuscar;
    int campoModificar;

    printf("Ingrese el codigo de autor: \n");
    scanf("%d", &codigoModificar);
    indexBuscar=buscarAutor(vec, CANTIDAD, codigoModificar);

    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
    }

    while(campoModificar!=3)
    {

        printf("Ingrese el campo a modificar: \n");
        printf("1) Apellido\n2) Nombre\n3) Salir\n");
        scanf("%d", &campoModificar);
        switch(campoModificar)
        {
        case 1:
            if(!getStringLetras("Ingrese nuevo apellido: \n",vec[indexBuscar].apellido))
            {
                printf("Solo letras.\n");
                break;
            }
            break;
        case 2:
            if(!getStringLetras("Ingrese nuevo nombre: \n",vec[indexBuscar].nombre))
            {
                printf("Solo letras.\n");
                break;
            }
            break;
        }

    }

}

