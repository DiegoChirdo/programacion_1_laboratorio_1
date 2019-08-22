#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

int getInt(char mensaje[]);
char getChar (char mensaje[]);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
float getFloat(char mensaje[]);
float calcularAreaCirculo(float radio);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
void inicializarArrayInt(int array[],int cantidad_de_elementos,int valor);




#endif // BIBLIOTECA_H_INCLUDED
