#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int opcion;


inicializarSocios(arraySocios,CANTIDAD);
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
    vec[libre].sexo=pedirSexo();
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
    char confirmarBaja;

    printf("Ingrese codigo de socio para la baja: \n");
    scanf("%d", &codigoBaja);
    indexBuscar=buscarSocio(vec, CANTIDAD, codigoBaja);
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

char pedirSexo(void)
{
    char sexo;
    printf("Ingrese el sexo: (m/f)\n");
    scanf("%c", &sexo);
    while(sexo != 'f' || sexo != 'm')
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
