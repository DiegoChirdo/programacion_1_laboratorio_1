typedef struct
{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
}ePersona;

void alta( ePersona per[], int cantidad );

void mostrar( ePersona per[], int cantidad );
