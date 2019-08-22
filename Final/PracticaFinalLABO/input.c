#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "cliente.h"
#include "input.h"

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

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

int conseguirPositivo(){

    char aux[50];
    int len;
    int flagOK;
    int positivo;

    fflush(stdin);
    gets(aux);

    flagOK=1;
    len=strlen(aux);

    ///Consigue una cadena que es transformada a entero solo si todos los elementos son digitos
    for(int i=0 ; i<len ; i++){
        if(isdigit(aux[i])!=1){
            flagOK=0;
        }
    }

    if(flagOK==0){
        positivo=-1;
        ///Si la validacion no es correcta, devuelve -1
    }else{
        positivo=atoi(aux);
    }

    return positivo;

}
