#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[32];
    char apellido[32];
    float dni;
}Cliente;

int menuPrincipal();
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListEmployee);
Cliente* cliente_newParametros(char* idStr, char* nameStr, char* apellidoStr, char* dni);
Cliente* cliente_new();
int cliente_setId(Cliente* this, int id);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_setDni(Cliente* this, int dni);
int cliente_addCliente(LinkedList* this);
int cliente_editCliente(LinkedList* this);
int buscarCliente(int id, LinkedList* this);
void mostrarCliente(Cliente* this);
void mostrarClientes(LinkedList* this);
int cliente_removeCliente(LinkedList* this);


#endif // CLIENTE_H_INCLUDED
