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
        {2000,"El hombre araña",{1000},1},
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



char getChar (char mensaje[])
{
    char caracter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &caracter);
    return caracter;
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

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

char pedirSexo(void)
{
    char sexo;
    printf("Ingrese el sexo: (m/f)\n");
    fflush(stdin);
    scanf("%c", &sexo);
    while(sexo != 'f' && sexo != 'm')
    {
        printf("Error, Reingrese el sexo: (m/f)\n");
        scanf("%c", &sexo);
    }
    return sexo;
}

int getStringTelefono(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esTelefono(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1)
        return 1;

    return 0;
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

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
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
