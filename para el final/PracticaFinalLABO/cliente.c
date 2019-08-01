#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "cliente.h"
#include "input.h"
#include "venta.h"

int menuPrincipal()
{
    int opcion;
    printf("\n-----MENU-----\n");
    printf("1) Alta de cliente\n");
    printf("2) Modificacion de cliente\n");
    printf("3) Baja de cliente\n");
    printf("4) Listar clientes\n");
    printf("5) Realizar una venta\n");
    printf("6) Anular una venta\n");
    printf("7) Informar ventas\n");
    printf("8) Informar ventas por producto\n");
    printf("9) Generar informe de ventas\n");
    printf("10) Informar cantidad de ventas por cliente\n");
    fflush(stdin);
    scanf("%d", &opcion);
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


int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Cliente* clientes;
    char datos[4][30];
    int cant;
    int todoOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", datos[0], datos[1], datos[2], datos[3]);
            clientes = cliente_newParametros(datos[0],datos[1],datos[2],datos[3]);
            if(clientes != NULL)
            {
                ll_add(pArrayListEmployee,clientes);
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

int controller_saveClientes(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Cliente* clientes;
    int size, todoOk=0, i;
    int id;
    float dni;
    char nombre[32];
    char apellido[32];
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
                    clientes=(Cliente*)ll_get(pArrayListEmployee,i);
                    cliente_getNombre(clientes,nombre);
                    cliente_getApellido(clientes,apellido);
                    cliente_getId(clientes,&id);
                    cliente_getDni(clientes,&dni);
                    fprintf(file,"%d,%s,%s,%f\n",id,nombre,apellido,dni);
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
    }
    else
    {
        printf("\nNo se han guardado correctamente.\n");
    }

    return todoOk;
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        todoOK=1;
    }
    return todoOK;
}

int cliente_getApellido(Cliente* this,char* apellido)
{
    int todoOK=0;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido, this->apellido);
        todoOK=1;
    }
    return todoOK;
}

int cliente_getId(Cliente* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOK=1;
    }
    return todoOK;
}

int cliente_getDni(Cliente* this,float* dni)
{
    int todoOK=0;
    if(this!=NULL && dni!=NULL)
    {
        *dni=this->dni;
        todoOK=1;
    }
    return todoOK;
}


Cliente* cliente_newParametros(char* idStr, char* nameStr, char* apellidoStr, char* dni)
{
    Cliente* clientes = cliente_new();
    if(idStr != NULL && nameStr != NULL && apellidoStr != NULL && dni != NULL && dni != NULL)
    {
        if(!cliente_setId(clientes,atoi(idStr)) || !cliente_setNombre(clientes,nameStr) || !cliente_setApellido(clientes,apellidoStr) || !cliente_setDni(clientes,atoi(dni)))
            clientes = NULL;
    }
    return clientes;
}

Cliente* cliente_new()
{
    Cliente* this = (Cliente*)malloc(sizeof(Cliente));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->nombre,"");
        strcpy(this->apellido, "");
        this->dni= 0;
    }
    return this;
}

int cliente_setId(Cliente* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre)>1)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int todoOk = 0;
    if(this != NULL && apellido != NULL && strlen(apellido)>1)
    {
        strcpy(this->apellido,apellido);
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setDni(Cliente* this, int dni)
{
    int todoOk = 0;
    if(this != NULL && dni > 0)
    {
        this->dni = dni;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_addCliente(LinkedList* this)
{
    Cliente* clientes = cliente_new();
    Cliente* auxCliente;

    int id;
    char nombre[32];
    char apellido[32];
    char dni[32];
    int size;

    system("cls");
    if(this != NULL)
    {
        if(clientes==NULL)
        {
            printf("No hay mas memoria\n");
            return 0;
        }
        else
        {
            if(ll_isEmpty(this))
            {
                id = 100;
            }
            else
            {
                size = ll_len(this);
                auxCliente = (Cliente*)ll_get(this, size-1);
                id = auxCliente->id;
                id++;
            }

            printf("\n---ALTA DE CLIENTE---\n");
            if(!getStringLetras("Ingrese un nombre: \n",nombre))
            {
                printf("Solo letras.\n");
                system("pause");
                return 0;
            }
            if(!getStringLetras("Ingrese un apellido: \n",apellido))
            {
                printf("Solo letras.\n");
                system("pause");
                return 0;
            }
            if(!getStringNumeros("Ingrese un DNI: \n",dni))
            {
                printf("Solo numeros.\n");
                system("pause");
                return 0;
            }
            clientes->id = id;
            clientes->dni=atof(dni);
            strcpy(clientes->nombre,nombre);
            strcpy(clientes->apellido,apellido);
            ll_add(this, (void*)clientes);
            printf("\n Alta exitosa \n");
            system("pause");
        }
    }
    return 1;
}

int cliente_editCliente(LinkedList* this)
{
    Cliente* clientes;
    char nombre[32];
    char dni[32];
    char apellido[32];
    int index;
    int id;
    int rta;
    if(this->size == 0)
    {
        printf("\n Aun no se han ingresado elementos.\n");
        system("pause");
        return 0;
    }
    else
    {
        system("cls");
        printf("---MODIFICAR CLIENTE---\n");
        printf("CLIENTES: \n\n");
        mostrarClientes(this);
        printf("\nIngrese ID de cliente a modificar: \n");
        id = conseguirPositivo();
        index = buscarCliente(id, this);
        if(index<0)
        {
            printf("No se encontro la ID\n");
            system("pause");
            return 0;
        }
        while(rta!=4)
        {
            system("cls");
            printf("ID\tNOMBRE\tAPELLIDO\tDNI\n");
            clientes=(Cliente*)ll_get(this,index);
            mostrarCliente(clientes);
            printf("INGRESE QUÉ QUIERE MODIFICAR: \n");
            printf("1) NOMBRE\n");
            printf("2) APELLIDO\n");
            printf("3) DNI\n");
            printf("4) SALIR\n");
            rta = conseguirPositivo();
            switch(rta)
            {
            case 1:
                if(!getStringLetras("Ingrese un nombre: \n",nombre))
                {
                    printf("Solo letras.\n");
                    return 0;
                }
                strcpy(clientes->nombre,nombre);
                break;
            case 2:
                if(!getStringLetras("Ingrese un apellido: \n",apellido))
                {
                    printf("Solo letras. \n");
                    return 0;
                }
                strcpy(clientes->apellido,apellido);
                break;
            case 3:
                if(!getStringNumeros("Ingrese un DNI: \n",dni))
                {
                    printf("Solo numeros\n");
                    return 0;
                }
                clientes->dni=atof(dni);
                break;
            }
        }
    }
    printf("\n Listo !!!! \n");
    return 1;
}

int buscarCliente(int id, LinkedList* this)
{
    Cliente* clientes;
    int index = -1;
    int i;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            clientes=(Cliente*)ll_get(this, i);
            if(clientes->id==id)
            {
                index=ll_indexOf(this, (void*)clientes);
                break;
            }
        }
    }
    return index;
}

void mostrarCliente(Cliente* this)
{
    if(this != NULL)
    {
        printf("%d\t%s\t%s\t%f\n",this->id,this->nombre,this->apellido,this->dni);
    }
}

void mostrarClientes(LinkedList* this)
{
    Cliente* clientes;
    int size = ll_len(this);
    int i;
    if(this!=NULL)
    {
        printf("ID\tNOMBRE\tAPELLIDO\tDNI\n");
        for(i=0;i<size;i++)
        {
            clientes=(Cliente*)ll_get(this, i);
            mostrarCliente(clientes);
        }
    }
}

int cliente_removeCliente(LinkedList* this)
{
    int index;
    int index2;
    char rta;
    int auxId;

    if(this->size == 0)
    {
        printf("Aun no se han ingresado datos. \n");
        system("pause");
        return 0;
    }
    system("cls");
    mostrarClientes(this);
    printf("Ingrese el ID a eliminar. \n");
    auxId = conseguirPositivo();
    index = buscarCliente(auxId, this);
    if(index == -1)
    {
        printf("No existe esa ID, se cancela la baja. \n");
        system("pause");
        return 0;
    }
    index2 = buscarVentaPorCliente(auxId,this);
    if(index2 >= 0)
    {
        printf("No se puede borrar porque tiene una venta\n");
        system("pause");
        return 0;
    }
    printf("Ingrese S/N para confirmar o cancelar la baja de cliente. \n");
    fflush(stdin);
    rta=tolower(getchar());
    if(rta == 's')
    {
        ll_remove(this, index);
        printf("\nEl cliente fue eliminado\n");
    }
    else
    {
        printf("La baja fue cancelada. \n");
        system("pause");
        return 0;
    }
    return 1;
}

void ventaPorCliente(LinkedList* this, LinkedList* that)
{
    Cliente* aux;
    int sizeClientes = ll_len(this);
    int i;
    int contador = 0;
    float acumulador = 0;
    int auxId;
    if(ll_isEmpty(this) || ll_isEmpty(that))
    {
        printf("Aun no se han ingresado clientes o ventas. \n");
        system("pause");
        exit(1);
    }
    for(i=0;i<sizeClientes;i++)
    {
        aux = (Cliente*)ll_get(this, i);
        auxId = aux->id;
        acumulador = buscarVentaPorCliente2(auxId, that);
        contador = buscarVentaPorCliente3(auxId,that);
        printf("IDCLIENTE:%d  -  CANTIDAD DE COMPRAS:%d  -  TOTAL:%f\n\n",aux->id,contador,acumulador);
        contador = 0;
        acumulador = 0;
    }
}
