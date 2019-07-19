#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "envio.h"
#include "parser.h"


int menuPrincipal(void)
{
    int opcion;
    printf("\n----MENU----\n");
    printf("1) Cargar archivo\n");
    printf("2) Imprimir envios\n");
    printf("3) Generar archivo de costos\n");
    printf("4) Salir\n");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

Envio* envio_new()
{
    Envio* this = (Envio*)malloc(sizeof(Envio));
    if(this != NULL)
    {
        this->id_envio = 0;
        strcpy(this->nombre_producto, "");
        this->km_recorridos = 0;
        this->tipo_entrega = 0;
    }
    return this;
}

Envio* envio_newParametros(char* idStr, char* nameStr, char* horasStr, char* sueldo)
{
    Envio* envios = envio_new();
    if(idStr != NULL && nameStr != NULL && horasStr != NULL && sueldo != NULL && envios != NULL)
    {
        if(!envio_setId(envios,atoi(idStr)) || !envio_setNombre(envios,nameStr) || !envio_setTipoEntrega(envios,atoi(sueldo)) || !envio_setKilometros(envios,atoi(horasStr)))
            envios = NULL;
    }
    return envios;
}

int envio_setId(Envio* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id_envio = id;
        todoOk = 1;
    }
    return todoOk;
}

int envio_setNombre(Envio* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre)>1)
    {
        strcpy(this->nombre_producto,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int envio_setKilometros(Envio* this, int horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->km_recorridos = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int envio_setTipoEntrega(Envio* this, int sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo > 0)
    {
        this->tipo_entrega = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

void print_envio(LinkedList* list)
{
    int len = ll_len(list);
    int i;
    for(i=0;i<len;i++)
    {
        Envio* envios = ll_get(list,i);
        imprimir(envios);
    }
}

void imprimir(Envio* pElement)
{
    char problema_1[] = "NORMAL";
    char problema_2[] = "EXPRESS";
    char problema_3[] = "SEGUN DISPONIBILIDAD";
    int opcion = pElement->tipo_entrega;


    switch(opcion)
    {
    case 1:
        printf("\n%d %s %d %s",
            pElement->id_envio,
            pElement->nombre_producto,
            pElement->km_recorridos,
            problema_1);
        break;
    case 2:
        printf("\n%d %s %d %s",
            pElement->id_envio,
            pElement->nombre_producto,
            pElement->km_recorridos,
            problema_2);
        break;
    case 3:
        printf("\n%d %s %d %s",
            pElement->id_envio,
            pElement->nombre_producto,
            pElement->km_recorridos,
            problema_3);
        break;
    }
}
