#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ventas.h"
#include "parser.h"
#include "LinkedList.h"

int menuPrincipal()
{
    int opcion;
    printf("\n-----MENU PRINCIPAL----\n");
    printf("1) Cargar archivo\n");
    printf("2) Imprimir ventas\n");
    printf("3) Generar archivo de montos\n");
    printf("4) Informes\n");
    printf("5) Salir\n");
    printf("Ingrese su opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

Ventas* venta_newParametros(char* idStr, char* nombre, char* dia, char* hora, char* sala, char* cantidad)
{
    Ventas* venta = venta_new();
    if(idStr != NULL && nombre != NULL && dia != NULL && hora != NULL && sala != NULL && cantidad != NULL)
    {
        if(!venta_setId(venta,atoi(idStr)) || !venta_setNombre(venta,nombre) || !venta_setDia(venta,atoi(dia)) || !venta_setHora(venta,hora) || !venta_setSala(venta,atoi(sala)) || !venta_setCantidad(venta,atoi(cantidad)))
            venta = NULL;
    }
    return venta;
}

Ventas* venta_new()
{
    Ventas* this = (Ventas*)malloc(sizeof(Ventas));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->nombre,"");
        this->dia=0;
        strcpy(this->hora,"");
        this->sala=0;
        this->cantidad=0;
        this->costo=0;
    }
    return this;
}

int venta_setId(Ventas* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int venta_setNombre(Ventas* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre)>1)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int venta_setDia(Ventas* this, int dia)
{
    int todoOk = 0;
    if(this != NULL && dia > 0)
    {
        this->dia = dia;
        todoOk = 1;
    }
    return todoOk;
}

int venta_setHora(Ventas* this, char* hora)
{
    int todoOk = 0;
    if(this != NULL && hora != NULL && strlen(hora)>1)
    {
        strcpy(this->hora,hora);
        todoOk = 1;
    }
    return todoOk;
}

int venta_setSala(Ventas* this, int sala)
{
    int todoOk = 0;
    if(this != NULL && sala > 0)
    {
        this->sala = sala;
        todoOk = 1;
    }
    return todoOk;
}

int venta_setCantidad(Ventas* this, int cantidad)
{
    int todoOk = 0;
    if(this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        todoOk = 1;
    }
    return todoOk;
}

int venta_setCosto(Ventas* this, int costo)
{
    int todoOk = 0;
    if(this != NULL && costo > 0)
    {
        this->costo = costo;
        todoOk = 1;
    }
    return todoOk;
}

int venta_getId(Ventas* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int venta_getNombre(Ventas* this, char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int venta_getDia(Ventas* this, int* dia)
{
    int todoOk = 0;
    if(this != NULL && dia != NULL)
    {
        *dia = this->dia;
        todoOk = 1;
    }
    return todoOk;
}

int venta_getHora(Ventas* this, char* hora)
{
    int todoOk = 0;
    if (this != NULL && hora != NULL)
    {
        strcpy(hora, this->hora);
        todoOk = 1;
    }
    return todoOk;
}

int venta_getSala(Ventas* this, int* sala)
{
    int todoOk = 0;
    if(this != NULL && sala != NULL)
    {
        *sala = this->sala;
        todoOk = 1;
    }
    return todoOk;
}

int venta_getCosto(Ventas* this, int* costo)
{
    int todoOk = 0;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        todoOk = 1;
    }
    return todoOk;
}

int venta_getCantidad(Ventas* this, int* cantidad)
{
    int todoOk = 0;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        todoOk = 1;
    }
    return todoOk;
}

void imprimir(Ventas* pElement)
{
    char dia_0[] = "DOMINGO";
    char dia_1[] = "LUNES";
    char dia_2[] = "MARTES";
    char dia_3[] = "MIERCOLES";
    char dia_4[] = "JUEVES";
    char dia_5[] = "VIERNES";
    char dia_6[] = "SABADO";
    int opcion;
    int auxId, auxSala, auxCant;
    char nombre[32];
    char hora[32];
    venta_getDia(pElement,&opcion);
    venta_getId(pElement,&auxId);
    venta_getCantidad(pElement,&auxCant);
    venta_getNombre(pElement,nombre);
    venta_getHora(pElement,hora);
    venta_getSala(pElement,&auxSala);

    switch(opcion)
    {
    case 0:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_0,hora,auxSala,auxCant);
        break;
    case 1:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_1,hora,auxSala,auxCant);
        break;
    case 2:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_2,hora,auxSala,auxCant);
        break;
    case 3:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_3,hora,auxSala,auxCant);
        break;
    case 4:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_4,hora,auxSala,auxCant);
        break;
    case 5:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_5,hora,auxSala,auxCant);
        break;
    case 6:
        printf("\n%d %s %s %s %d %d",auxId,nombre,dia_6,hora,auxSala,auxCant);
        break;
    }
}

void print_ventas(LinkedList* list)
{
    int len = ll_len(list);
    int i;
    for(i=0;i<len;i++)
    {
        Ventas* venta = ll_get(list,i);
        imprimir(venta);
    }
}

int laQueMapea(void* ventas)
{
    int dia;
    int cantidad;
    int descuento;
    venta_getDia(ventas,&dia);
    venta_getCantidad(ventas,&cantidad);
    if(dia == 1 || dia == 2 || dia == 3)
    {
        if(cantidad >= 3)
        {
            descuento = 240*cantidad/100;
            venta_setCosto(ventas,240*cantidad-descuento);
        }
        else
            venta_setCosto(ventas,240*cantidad);
    }
    else
    {
        if(cantidad >= 3)
        {
            descuento = 350*cantidad/100;
            venta_setCosto(ventas,350*cantidad-descuento);
        }
        else
            venta_setCosto(ventas,350*cantidad);
    }
    return 1;
}

void informe1(LinkedList* this, int auxSala)
{
    Ventas* aux;
    int sizeVentas = ll_len(this);
    int i;
    int acumulador;
    for(i=0;i<sizeVentas;i++)
    {
        aux = (Ventas*)ll_get(this,i);
        if(aux->sala == auxSala)
        {
        acumulador = buscarVentasPorSala(auxSala, this);
        }
    }
    printf("\nVENTAS DE LA SALA %d ES %d ENTRADAS\n", auxSala,acumulador);
}

int buscarVentasPorSala(int sala, LinkedList* this)
{
    Ventas* venta;
    int i;
    float acumulador = 0;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            venta=(Ventas*)ll_get(this, i);
            if(venta->sala==sala)
            {
                acumulador = acumulador + venta->cantidad;
            }
        }
    }
    return acumulador;
}
