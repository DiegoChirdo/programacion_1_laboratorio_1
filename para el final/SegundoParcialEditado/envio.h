#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED

typedef struct
{
    int id_envio;
    char nombre_producto[50];
    int km_recorridos;
    int tipo_entrega;
    int costo;
}Envio;

int menuPrincipal();
Envio* envio_new();
Envio* envio_newParametros(char* idStr, char* nameStr, char* horasStr, char* sueldo);
int envio_setId(Envio* this, int id);
int envio_setNombre(Envio* this, char* nombre);
int envio_setKilometros(Envio* this, int horasTrabajadas);
int envio_setTipoEntrega(Envio* this, int sueldo);
void print_envio(LinkedList* list);
void imprimir(Envio* pElement);
int envio_getId(Envio* this, int* id);
int envio_getKmRecorridos(Envio* this, int* km);
int envio_getNombre(Envio* this, char* nombre);
int envio_getTipoEntrega(Envio* this, int* tipoEntrega);
int envio_setCosto(Envio* this, int costo);
int laQueMapea(void* this);
int envio_getCosto(Envio* this, int* costo);

#endif // ENVIO_H_INCLUDED
