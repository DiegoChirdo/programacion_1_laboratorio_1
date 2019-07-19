#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
