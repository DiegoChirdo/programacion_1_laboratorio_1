#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "cliente.h"
#include "input.h"
#include "venta.h"

int main()
{
    int opcion = 0;
    int opcion2 = 0;
    LinkedList* clientes = ll_newLinkedList();
    LinkedList* venta = ll_newLinkedList();
    controller_loadFromText("clientes.txt",clientes);
    controller_ventasFromText("informe.txt",venta);
    while(opcion != 11)
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            cliente_addCliente(clientes);
            break;
        case 2:
            cliente_editCliente(clientes);
            break;
        case 3:
            cliente_removeCliente(clientes);
            break;
        case 4:
            mostrarClientes(clientes);
            break;
        case 5:
            venta_addVenta(venta, clientes);
            break;
        case 6:
            remove_Venta(venta);
            break;
        case 7:
            mostrarVentas(venta);
            break;
        case 8:
            switch(opcion2 = menuVentasPorProducto())
            {
            case 1000:
                ll_filter(venta,codigo1000);
                break;
            case 1001:
                ll_filter(venta,codigo1001);
                break;
            case 1002:
                ll_filter(venta,codigo1002);
                break;
            }
            break;
        case 9:
            controller_saveVentas("informe.txt",venta);
            break;
        case 10:
            ventaPorCliente(clientes,venta);
            break;
        }
    }
    return 0;
}

