#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
#include "socios.h"

char getChar (char mensaje[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringTelefono(char mensaje[],char input[]);
char pedirSexo(void);
void getString(char mensaje[],char input[]);
int buscarLibre(Socios vec[], int tam);
void inicializarSocios(Socios vec[], int tam);
int buscarPrimerOcurrencia(Socios arrayPersonas[],int cantidadDeElementos,int valor);



#endif // INPUT_H_INCLUDED
