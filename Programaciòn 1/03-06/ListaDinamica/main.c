#include <stdio.h>
#include <stdlib.h>
char preguntarSalir();
char preguntarNombre();
int preguntarEdad();


typedef struct
{
    int edad;
    char nombre[20];
}Persona;

int main()
{
    int size = 10;
    int index = 0;
    Persona** lista = (Persona**)malloc(sizeof(Persona*)*size);
    do
    {
        Persona persona;
        preguntarNombre(&persona->nombre);
        persona.edad = preguntarEdad();

        lista[index] = &persona;
        index++;
        if(index>=size)
        {
            size+=10;
            lista = realloc(lista,sizeof(Persona*)*size);
        }
    }while(preguntarSalir()!='S');

}


char preguntarSalir()
{
    char respuesta;
    printf("¿Desea continuar? (S/N)\n");
    scanf("%c", respuesta);
    return respuesta;
}

char preguntarNombre()
{
    char nombre;
    printf("Ingrese un nombre: \n");
    scanf("%s", &nombre);
    return nombre;
}

int preguntarEdad()
{
    int edad;
    printf("Ingrese una edad: \n");
    scanf("%d", &edad);
    return edad;
}
