#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "socios.h"
#include "input.h"
char getChar (char mensaje[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
char pedirSexo(void);
int getStringTelefono(char mensaje[],char input[]);
void getString(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int esNumerico(char str[]);
int esTelefono(char str[]);




#endif // INPUT_H_INCLUDED
