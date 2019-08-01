#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "cliente.h"
#include "input.h"
#include "venta.h"

int controller_ventasFromText(char* path , LinkedList* pArrayListEmployee)
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
            todoOk = parser_VentasFromText(file, pArrayListEmployee);
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

int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Ventas* venta;
    char datos[5][30];
    int cant;
    int todoOk = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", datos[0], datos[1], datos[2], datos[3], datos[4]);
            venta = venta_newParametros(datos[0],datos[1],datos[2],datos[3],datos[4]);
            if(venta != NULL)
            {
                ll_add(pArrayListEmployee,venta);
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

Ventas* venta_newParametros(char* idStr, char* idClienteStr, char* codigoProductoStr, char* cantidadStr, char* precioUnitarioStr)
{
    Ventas* venta = ventas_new();
    if(idStr != NULL && idClienteStr != NULL && codigoProductoStr != NULL && cantidadStr != NULL && precioUnitarioStr != NULL)
    {
        if(!venta_setId(venta,atoi(idStr)) || !venta_setIdCliente(venta,atoi(idClienteStr)) || !venta_setCodigo(venta,atoi(codigoProductoStr)) || !venta_setCantidad(venta,atoi(cantidadStr)) || !venta_setPrecioUnitario(venta,atof(precioUnitarioStr)))
            venta = NULL;
    }
    return venta;
}

Ventas* ventas_new()
{
    Ventas* this=(Ventas*) malloc(sizeof(Ventas));
    ///Consigue memoria para un nuevo empleado
    if(this!=NULL)
    {
        this->idVenta=0;
        this->idCliente=0;
        this->codigoProducto=0;
        this->cantidad=0;
        this->precioUnitario=0;
    }
    return this;
}

int venta_addVenta(LinkedList* this, LinkedList* clientes)
{
    Ventas* auxVenta;
    int auxId;
    int index;
    int size;
    int idVenta;
    int idProducto;
    int cantidad;
    int precioUnitario;

    system("cls");
    printf("\n---ALTA DE VENTA---\n");
    printf("INGRESE ID DEL CLIENTE: \n");
    auxId = conseguirPositivo();
    index = buscarCliente(auxId, clientes);
    if(index < 0)
    {
        printf("No se encontro la ID.\n");
        return 0;
    }
    printf("\nINGRESE CODIGO DE PRODUCTO\n");
    printf("\n1000 - TV_LG_32 - $8999.99\n1001 - PS4 - 12999.99\n1002 - IPHONE7 - 19480.99\n");
    scanf("%d", &idProducto);
    if(idProducto<1000 || idProducto>1002)
    {
        printf("Codigo de venta incorrecto\n");
        return 0;
    }
    Ventas* venta=ventas_new();
    if(this != NULL)
    {
        if(venta==NULL)
        {
            printf("No se pudo asignar memoria. \n");
            return 0;
        }
        if(ll_isEmpty(this))
            idVenta = 1000;
        else
        {
            size = ll_len(this);
            auxVenta = (Ventas*)ll_get(this, size-1);
            idVenta = auxVenta->idVenta;
            idVenta++;
        }
        printf("Ingrese cantidad a comprar: \n");
        scanf("%d",&cantidad);
        if(idProducto == 1000)
            precioUnitario = 8999.99;
        if(idProducto == 1001)
            precioUnitario = 12999.99;
        if(idProducto == 1002)
            precioUnitario = 19480.99;
        venta_setId(venta,idVenta);
        venta_setIdCliente(venta,auxId);
        venta_setCodigo(venta,idProducto);
        venta_setCantidad(venta,cantidad);
        venta_setPrecioUnitario(venta,precioUnitario);
        ll_add(this, (void*)venta);
        printf("Todo ok!! \n Alta hecha \n");
        system("pause");
    }
    return 1;
}

int remove_Venta(LinkedList* this)
{
    int auxId;
    int index;
    char rta;

    if(this->size == 0)
    {
        printf("Aun no se han ingresado ventas. \n");
        system("pause");
        return 1;
    }
    system("cls");
    mostrarVentas(this);
    printf("Ingrese ID de venta a borrar: \n");
    scanf("%d", &auxId);
    index = buscarVenta(auxId,this);
    if(index < 0)
    {
        printf("Error, la ID no existe. \n");
        return 1;
    }
    printf("¿Seguro que desea eliminar esta venta? s/n\n");
    fflush(stdin);
    rta=tolower(getchar());
    if(rta == 's')
    {
        ll_remove(this, index);
        printf("Venta eliminada.\n");
        system("pause");
    }
    else
        printf("Baja cancelada\n");
    return 1;

}

int venta_setId(Ventas* this,int id)
{
    int todoOK=0;
    if(this!=NULL && id>0)
    {
        this->idVenta=id;
        todoOK=1;
    }
    return todoOK;
}

int venta_setIdCliente(Ventas* this,int id)
{
    int todoOK=0;
    if(this!=NULL && id>0)
    {
        this->idCliente=id;
        todoOK=1;
    }
    return todoOK;
}

int venta_setCodigo(Ventas* this,int id)
{
    int todoOK=0;
    if(this!=NULL && id>0)
    {
        this->codigoProducto=id;
        todoOK=1;
    }
    return todoOK;
}

int venta_setCantidad(Ventas* this,int id)
{
    int todoOK=0;
    if(this!=NULL && id>0)
    {
        this->cantidad=id;
        todoOK=1;
    }
    return todoOK;
}

int venta_setPrecioUnitario(Ventas* this,int id)
{
    int todoOK=0;
    if(this!=NULL && id>0)
    {
        this->precioUnitario=id;
        todoOK=1;
    }
    return todoOK;
}

void mostrarVenta(Ventas* this)
{
    if(this != NULL)
    {
        printf("%d\t%d\t%d\t%d\t%f\n",this->idVenta,this->idCliente,this->codigoProducto,this->cantidad,this->precioUnitario);
    }
}

void mostrarVentas(LinkedList* this)
{
    Ventas* venta;
    int size = ll_len(this);
    int i;
    if(this!=NULL)
    {
        printf("IDVENTA\tIDCLIENTE\tCODIGOPRODUCTO\tCANTIDAD\tPRECIOUNIDAD\n");
        for(i=0;i<size;i++)
        {
            venta=(Ventas*)ll_get(this, i);
            mostrarVenta(venta);
        }
    }
}

int buscarVenta(int id, LinkedList* this)
{
    Ventas* venta;
    int index = -1;
    int i;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            venta=(Ventas*)ll_get(this, i);
            if(venta->idVenta==id)
            {
                index=ll_indexOf(this, (void*)venta);
                break;
            }
        }
    }
    return index;
}

int buscarVentaPorCliente(int id, LinkedList* this)
{
    Ventas* venta;
    int index = -1;
    int i;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            venta=(Ventas*)ll_get(this, i);
            if(venta->idCliente==id)
            {
                index=ll_indexOf(this, (void*)venta);
                break;
            }
        }
    }
    return index;
}

int buscarVentaPorCliente2(int id, LinkedList* this)
{
    Ventas* venta;
    int i;
    float acumulador;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            venta=(Ventas*)ll_get(this, i);
            if(venta->idCliente==id)
            {
                acumulador = acumulador + venta->precioUnitario;
            }
        }
    }
    return acumulador;
}

int buscarVentaPorCliente3(int id, LinkedList* this)
{
    Ventas* venta;
    int i;
    int contador = 0;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            venta=(Ventas*)ll_get(this, i);
            if(venta->idCliente==id)
            {
                contador++;
            }
        }
    }
    return contador;
}

int menuVentasPorProducto()
{
    int id;
    printf("VENTAS POR PRODUCTO: \n");
    printf("\n1000 - TV_LG_32 - $8999.99\n1001 - PS4 - 12999.99\n1002 - IPHONE7 - 19480.99\n");
    while(id < 1000 || id > 1002)
    {
        printf("\nINGRESE CODIGO DE PRODUCTO:\n");
        scanf("%d",&id);
    }
    return id;
}

int codigo1000(void* unaVenta)
{
    int codigo;
    int codigoValido=0;
    venta_getCodigo(unaVenta,&codigo);
    if(codigo == 1000)
    {
        codigoValido=1;
    }
    return codigoValido;
}

int codigo1001(void* unaVenta)
{
    int codigo;
    int codigoValido=0;
    venta_getCodigo(unaVenta,&codigo);
    if(codigo == 1001)
    {
        codigoValido=1;
    }
    return codigoValido;
}

int codigo1002(void* unaVenta)
{
    int codigo;
    int codigoValido=0;
    venta_getCodigo(unaVenta,&codigo);
    if(codigo == 1002)
    {
        codigoValido=1;
    }
    return codigoValido;
}

int venta_getIdVenta(Ventas* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->idVenta;
        todoOK=1;
    }

    return todoOK;
}

int venta_getIdCliente(Ventas* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->idCliente;
        todoOK=1;
    }

    return todoOK;
}

int venta_getCantidad(Ventas* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->cantidad;
        todoOK=1;
    }

    return todoOK;
}

int venta_getPrecioUnitario(Ventas* this,float* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->precioUnitario;
        todoOK=1;
    }

    return todoOK;
}

int venta_getCodigo(Ventas* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->codigoProducto;
        todoOK=1;
    }

    return todoOK;
}

int controller_saveVentas(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Ventas* venta;
    int size, todoOk=0, i;
    int idVenta, idCliente, codigoProducto, cantidad;
    float precioUnitario;
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
                    venta=(Ventas*)ll_get(pArrayListEmployee,i);
                    venta_getIdVenta(venta,&idVenta);
                    venta_getIdCliente(venta,&idCliente);
                    venta_getCodigo(venta,&codigoProducto);
                    venta_getCantidad(venta,&cantidad);
                    venta_getPrecioUnitario(venta,&precioUnitario);
                    fprintf(file,"%d,%d,%d,%d,%f\n",idVenta,idCliente,codigoProducto,cantidad,precioUnitario);
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
