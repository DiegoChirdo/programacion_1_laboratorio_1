#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int idVenta;
    int idCliente;
    int codigoProducto;
    int cantidad;
    float precioUnitario;
}Ventas;

int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int controller_ventasFromText(char* path , LinkedList* pArrayListEmployee);
Ventas* venta_newParametros(char* idStr, char* idClienteStr, char* codigoProductoStr, char* cantidadStr, char* precioUnitarioStr);
Ventas* ventas_new();
int venta_addVenta(LinkedList* this, LinkedList* clientes);
int remove_Venta(LinkedList* this);
int venta_setId(Ventas* this,int id);
int venta_setIdCliente(Ventas* this,int id);
int venta_setCodigo(Ventas* this,int id);
int venta_setCantidad(Ventas* this,int id);
int venta_setPrecioUnitario(Ventas* this,int id);
void mostrarVenta(Ventas* this);
void mostrarVentas(LinkedList* this);
int buscarVenta(int id, LinkedList* this);
int menuVentasPorProducto();
int codigo1000(void* unaVenta);
int codigo1001(void* unaVenta);
int codigo1002(void* unaVenta);
int venta_getIdVenta(Ventas* this,int* id);
int venta_getIdCliente(Ventas* this,int* id);
int venta_getCantidad(Ventas* this,int* id);
int venta_getPrecioUnitario(Ventas* this,float* id);
int venta_getCodigo(Ventas* this,int* id);
int controller_saveVentas(char* path , LinkedList* pArrayListEmployee);
int buscarVentaPorCliente(int id, LinkedList* this);
int buscarVentaPorCliente2(int id, LinkedList* this);
int buscarVentaPorCliente3(int id, LinkedList* this);


#endif // VENTA_H_INCLUDED
