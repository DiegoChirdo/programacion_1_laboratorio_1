#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "input.h"
#include "partidas.h"

int menuPrincipal()
{
    int opcion;
    printf("\n\n------MENU PRINCIPAL------\n\n");
    printf("1) Cargar archivo\n");
    printf("2) Imprimir partidas\n");
    printf("3) Cantidad de jugadores promedio por tipo de partido\n");
    printf("4) Generar archivo de costos por tipo de juego\n");
    printf("5) Salir\n");
    fflush(stdin);
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int todoOk=0;
    char rta;
    if(!ll_isEmpty(pArrayListEmployee)){
        printf("\nConfirmar carga desde texto? Se sobreescribiran los datos existentes S/N: ");
        rta=tolower(getchar());
    }

    if(rta=='s' || ll_isEmpty(pArrayListEmployee))
    {
        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            ll_clear(pArrayListEmployee);
            file=fopen(path, "r");
            if(file!=NULL)
            {
            todoOk = parser_ClienteFromText(file, pArrayListEmployee);
            fclose(file);
            }
        }
    }
    if(todoOk==0)
    {
        printf("\nNo pudieron cargarse los datos desde el archivo\n");
        system("pause");
    }
    else
    {
        printf("\nLos datos fueron cargados correctamente\n");
        system("pause");
    }
    return todoOk;
}

int controller_savePartidas(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Partida* partidas;
    int size, todoOk=0, i;
    int id, tipo, cantidad, duracion, costo;
    char fecha[32];
    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("\nAun no se han ingresado datos.\n");
    }
    else
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
            size = ll_len(pArrayListEmployee);
            file=fopen(path,"w");
            if(file!=NULL)
            {
                for(i=0;i<size;i++)
                {
                    partidas=(Partida*)ll_get(pArrayListEmployee,i);
                    partida_getId(partidas,&id);
                    partida_getFecha(partidas,fecha);
                    partida_getTipo(partidas,&tipo);
                    partida_getCantidad(partidas,&cantidad);
                    partida_getDuracion(partidas,&duracion);
                    partida_getCosto(partidas,&costo);
                    fprintf(file,"%d,%s,%d,%d,%d,%d\n",id,fecha,tipo,cantidad,duracion,costo);
                }
                fclose(file);
                if(i==size)
                {
                    todoOk=1;
                }
                else
                {
                    todoOk=0;
                }
            }
        }
    }
    if(todoOk==1)
    {
        printf("\nLos datos se han guardado correctamente.\n");
        system("pause");
    }
    else
    {
        printf("\nNo se han guardado correctamente.\n");
        system("pause");
    }

    return todoOk;
}

int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Partida* partidas;
    char datos[4][30];
    int cant;
    int todoOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]", datos[0], datos[1], datos[2], datos[3],datos[4]);
            partidas = partida_newParametros(datos[0],datos[1],datos[2],datos[3],datos[4]);
            if(partidas != NULL)
            {
                ll_add(pArrayListEmployee,partidas);
                todoOk = 1;
            }
            if(cant < 4)
            {
                if(feof(pFile))
                    break;
                else
                {
                    todoOk = 0;
                    break;
                }
            }
        }
    }
    return todoOk;
}

Partida* partida_newParametros(char* idStr, char* fecha, char* tipo, char* cantidad, char* duracion)
{
    Partida* partidas = partida_new();
    if(idStr != NULL && fecha != NULL && tipo != NULL && cantidad != NULL && duracion != NULL)
    {
        if(!partida_setId(partidas,atoi(idStr)) || !partida_setFecha(partidas,fecha) || !partida_setTipo(partidas,atoi(tipo)) || !partida_setCantidad(partidas,atoi(cantidad)) || !partida_setDuracion(partidas,atoi(duracion)))
            partidas = NULL;
    }
    return partidas;
}


Partida* partida_new()
{
    Partida* this = (Partida*)malloc(sizeof(Partida));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->fecha,"");
        this->tipo=0;
        this->cantidad=0;
        this->duracion=0;
        this->costo=0;
    }
    return this;
}

int partida_setId(Partida* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int partida_setFecha(Partida* this, char* fecha)
{
    int todoOk = 0;
    if(this != NULL && fecha != NULL && strlen(fecha)>1)
    {
        strcpy(this->fecha,fecha);
        todoOk = 1;
    }
    return todoOk;
}

int partida_setTipo(Partida* this, int tipo)
{
    int todoOk = 0;
    if(this != NULL && tipo >= 0)
    {
        this->tipo = tipo;
        todoOk = 1;
    }
    return todoOk;
}

int partida_setCantidad(Partida* this, int cantidad)
{
    int todoOk = 0;
    if(this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        todoOk = 1;
    }
    return todoOk;
}

int partida_setDuracion(Partida* this, int duracion)
{
    int todoOk = 0;
    if(this != NULL && duracion > 0)
    {
        this->duracion = duracion;
        todoOk = 1;
    }
    return todoOk;
}

int partida_setCosto(Partida* this, int costo)
{
    int todoOk = 0;
    if(this != NULL && costo > 0)
    {
        this->costo = costo;
        todoOk = 1;
    }
    return todoOk;
}

void print_partidas(LinkedList* list)
{
    int len = ll_len(list);
    int i;
    for(i=0;i<len;i++)
    {
        Partida* partidas = ll_get(list,i);
        imprimir(partidas);
    }
}

void imprimir(Partida* pElement)
{
    char tipo_0[] = "PING PONG";
    char tipo_1[] = "POOL";
    char tipo_2[] = "METEGOL";
    char tipo_3[] = "DARDOS";
    int opcion;
    int auxId, auxDur, auxCant;
    char fecha[32];
    partida_getTipo(pElement,&opcion);
    partida_getId(pElement,&auxId);
    partida_getDuracion(pElement,&auxDur);
    partida_getCantidad(pElement,&auxCant);
    partida_getFecha(pElement,fecha);

    switch(opcion)
    {
    case 0:
        printf("\n%d %s %s %d %d",auxId,fecha,tipo_0,auxCant,auxDur);
        break;
    case 1:
        printf("\n%d %s %s %d %d",auxId,fecha,tipo_1,auxCant,auxDur);
        break;
    case 2:
        printf("\n%d %s %s %d %d",auxId,fecha,tipo_2,auxCant,auxDur);
        break;
    case 3:
        printf("\n%d %s %s %d %d",auxId,fecha,tipo_3,auxCant,auxDur);
        break;
    }
}

int partida_getId(Partida* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int partida_getFecha(Partida* this, char* fecha)
{
    int todoOk = 0;
    if (this != NULL && fecha != NULL)
    {
        strcpy(fecha, this->fecha);
        todoOk = 1;
    }
    return todoOk;
}

int partida_getTipo(Partida* this, int* tipo)
{
    int todoOk = 0;
    if(this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        todoOk = 1;
    }
    return todoOk;
}

int partida_getCantidad(Partida* this, int* cantidad)
{
    int todoOk = 0;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        todoOk = 1;
    }
    return todoOk;
}

int partida_getDuracion(Partida* this, int* duracion)
{
    int todoOk = 0;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        todoOk = 1;
    }
    return todoOk;
}

int partida_getCosto(Partida* this, int* costo)
{
    int todoOk = 0;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        todoOk = 1;
    }
    return todoOk;
}

int promedioTipo0(void* this)
{
    int tipo;
    partida_getTipo(this,&tipo);
    if(tipo == 0)
        return 1;
    return 0;
}

int promedioTipo1(void* this)
{
    int tipo;
    partida_getTipo(this,&tipo);
    if(tipo == 1)
        return 1;
    return 0;
}

int promedioTipo2(void* this)
{
    int tipo;
    partida_getTipo(this,&tipo);
    if(tipo == 2)
        return 1;
    return 0;
}

int promedioTipo3(void* this)
{
    int tipo;
    partida_getTipo(this,&tipo);
    if(tipo == 3)
        return 1;
    return 0;
}

