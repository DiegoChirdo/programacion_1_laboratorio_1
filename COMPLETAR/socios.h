#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    int isEmpty;
}Autor;

typedef struct
{
    int codigo;
    char titulo[51];
    Autor codigoAutor;
    int isEmpty;
}Libro;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char email[31];
    Fecha fechaSocio;
    int isEmpty;
}Socio;

typedef struct
{
    int codigo;
    Libro codigoLibro;
    Socio codigoSocio;
    Fecha fechaPrestamo;
    int isEmpty;
}Prestamos;


int menuOpcion();
int menuAutores();
int menuListado();
void mostrarLibrosPrestados(Libro array[],Prestamos vec[], int cant);
int inicializarSocios(Socio vec[], int tam);
int altaSocio(Socio vec[],int cant);
void modificarSocio(Socio vec[],int cant);
int bajaSocio(Socio vec[],int cant);
int buscarLibre(Socio vec[], int tam);
int generarCodigo(Socio vec[], int cant);
int buscarSocio(Socio vec[], int cant, int codigoBuscar);
void listarSocios(Socio vec[], int cant);
void listarLibros(Libro vec[],int cant);
void listarAutores(Autor vec[],int cant);
int altaPrestamos(Prestamos vec[],Libro array[], Socio arr[], int cant);
int generarCodigoPrestamo(Prestamos vec[],int cant);
int buscarLibrePrestamo(Prestamos vec[], int tam);
void inicializarPrestamo (Prestamos vec[], int cant);
int buscarCodigoLibro(Libro vec[], int cant, int codigoBuscar);
int buscarCodigoSocio(Socio vec[], int cant, int codigoBuscar);
void altaAutor(Autor vec[],int cant);
int generarCodigoAutor(Autor vec[], int cant);
int buscarLibreAutor(Autor vec[], int tam);
void bajaAutor(Autor vec[],int cant);
int buscarAutor(Autor vec[], int cant, int codigoBuscar);
void modificarAutor(Autor vec[],int cant);
void mostrarPrestamos(Prestamos vec[], int cant);


#endif // SOCIOS_H_INCLUDED
