#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

char getChar (char mensaje[])
{
    char caracter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &caracter);
    return caracter;
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

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
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

