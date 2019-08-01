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
    int opcion;
    int auxId, auxKms;
    char nombreProducto[32];
    envio_getTipoEntrega(pElement,&opcion);
    envio_getId(pElement,&auxId);
    envio_getKmRecorridos(pElement,&auxKms);
    envio_getNombre(pElement,nombreProducto);

    switch(opcion)
    {
    case 1:
        printf("\n%d %s %d %s",auxId,nombreProducto,auxKms,problema_1);
        break;
    case 2:
        printf("\n%d %s %d %s",auxId,nombreProducto,auxKms,problema_2);
        break;
    case 3:
        printf("\n%d %s %d %s",auxId,nombreProducto,auxKms,problema_3);
        break;
    }
}

int envio_getId(Envio* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id_envio;
        todoOk = 1;
    }
    return todoOk;
}

int envio_getNombre(Envio* this, char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre_producto);
        todoOk = 1;
    }
    return todoOk;
}

int envio_getKmRecorridos(Envio* this, int* km)
{
    int todoOk = 0;
    if(this != NULL && km != NULL)
    {
        *km = this->km_recorridos;
        todoOk = 1;
    }
    return todoOk;
}

int envio_getTipoEntrega(Envio* this, int* tipoEntrega)
{
    int todoOk = 0;
    if(this != NULL && tipoEntrega != NULL)
    {
        *tipoEntrega = this->tipo_entrega;
        todoOk = 1;
    }
    return todoOk;
}

int laQueMapea(void* envios)
{
    int kmRecorridos;
    int tipoEntrega;
    envio_getKmRecorridos(envios,&kmRecorridos);
    envio_getTipoEntrega(envios, &tipoEntrega);
    if(kmRecorridos>0 && kmRecorridos <=50)
    {
        if(tipoEntrega == 1)
        {
            envio_setCosto(envios, 697);
        }
        else if(tipoEntrega == 2)
        {
            envio_setCosto(envios, 867);
        }
        else if(tipoEntrega == 3)
        {
            envio_setCosto(envios, 147);
        }
    }
    else
    {
        if(tipoEntrega == 1)
        {
            envio_setCosto(envios, 410);
        }
        else if(tipoEntrega == 2)
        {
            envio_setCosto(envios, 640);
        }
        else if(tipoEntrega == 3)
        {
            envio_setCosto(envios, 160);
        }
    }
    return 1;

}

int envio_setCosto(Envio* this, int costo)
{
    int todoOk = 0;
    if(this != NULL && costo > 0)
    {
        this->costo = costo;
        todoOk = 1;
    }
    return todoOk;
}

int envio_getCosto(Envio* this, int* costo)
{
    int todoOk = 0;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        todoOk = 1;
    }
    return todoOk;
}
