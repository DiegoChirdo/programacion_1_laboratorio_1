#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ventas.h"
#include "parser.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[32];
    int dia;
    char hora[32];
    int sala;
    int cantidad;
    int costo;
}Ventas;

int menuPrincipal();
Ventas* venta_newParametros(char* idStr, char* nombre, char* dia, char* hora, char* sala, char* cantidad);
Ventas* venta_new();
int venta_setId(Ventas* this, int id);
int venta_setNombre(Ventas* this, char* nombre);
int venta_setDia(Ventas* this, int dia);
int venta_setHora(Ventas* this, char* hora);
int venta_setSala(Ventas* this, int sala);
int venta_setCantidad(Ventas* this, int cantidad);
int venta_setCosto(Ventas* this, int costo);
int venta_getId(Ventas* this, int* id);
int venta_getNombre(Ventas* this, char* nombre);
int venta_getDia(Ventas* this, int* dia);
int venta_getHora(Ventas* this, char* hora);
int venta_getSala(Ventas* this, int* sala);
int venta_getCantidad(Ventas* this, int* cantidad);
int venta_getCosto(Ventas* this, int* costo);
void imprimir(Ventas* pElement);
void print_ventas(LinkedList* list);
int laQueMapea(void* ventas);
void informe1(LinkedList* this, int auxSala);
int buscarVentasPorSala(int sala, LinkedList* this);


#endif // VENTAS_H_INCLUDED
