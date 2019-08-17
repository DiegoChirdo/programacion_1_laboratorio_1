#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ventas.h"
#include "parser.h"
#include "LinkedList.h"

int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveVentas(char* path , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
