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
    char sexo;
    char telefono[16];
    char email[31];
    Fecha fechaSocio;
    int isEmpty;
}Socio;

void getString(char mensaje[],char input[]);
int inicializarSocios(Socio vec[], int tam);
void altaSocio(Socio vec[],int cant);
char getChar (char mensaje[]);
int buscarLibre(Socio vec[], int tam);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
char pedirSexo(void);
int getStringTelefono(char mensaje[],char input[]);
int generarCodigo(Socio vec[], int cant);

int main()
{
    Socio arraySocios[CANTIDAD];
    int rta;


    inicializarSocios(arraySocios,CANTIDAD);
    printf("Ingrese una respuesta: \n");
    scanf("%d",&rta);
    while(rta==1)
    {
        altaSocio(arraySocios,CANTIDAD);
        printf("Ingrese una respuesta: \n");
        scanf("%d",&rta);
    }
    return 0;
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
    int mostrar;

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
    scanf("%d", &vec[libre].fechaSocio.dia);
    printf("Ingrese un mes: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.mes);
    printf("Ingrese un anio: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.anio);

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
