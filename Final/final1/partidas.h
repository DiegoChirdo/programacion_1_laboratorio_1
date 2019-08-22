#ifndef PARTIDAS_H_INCLUDED
#define PARTIDAS_H_INCLUDED

typedef struct
{
    int id;
    char fecha[32];
    int tipo;
    int cantidad;
    int duracion;
    float costo;
}Partida;

int menuPrincipal();
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListEmployee);
Partida* partida_newParametros(char* idStr, char* fecha, char* tipo, char* cantidad, char* duracion);
Partida* partida_new();
int partida_setId(Partida* this, int id);
int partida_setFecha(Partida* this, char* fecha);
int partida_setTipo(Partida* this, int tipo);
int partida_setCantidad(Partida* this, int cantidad);
int partida_setDuracion(Partida* this, int duracion);
int partida_setCosto(Partida* this, int costo);
void print_partidas(LinkedList* list);
void imprimir(Partida* pElement);
int partida_getId(Partida* this, int* id);
int partida_getFecha(Partida* this, char* fecha);
int partida_getTipo(Partida* this, int* tipo);
int partida_getCantidad(Partida* this, int* cantidad);
int partida_getDuracion(Partida* this, int* duracion);
int partida_getCosto(Partida* this, int* costo);
int promedioTipo0(void* this);
int promedioTipo1(void* this);
int promedioTipo2(void* this);
int promedioTipo3(void* this);
int controller_savePartidas(char* path , LinkedList* pArrayListEmployee);


#endif // PARTIDAS_H_INCLUDED
