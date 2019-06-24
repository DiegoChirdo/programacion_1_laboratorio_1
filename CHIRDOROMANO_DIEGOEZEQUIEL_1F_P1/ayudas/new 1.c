#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAM 9
#define TAMSECT 5
#define TAMCOM  5
#define TAMALM  10

//LINEA DE PRUEBA EN GIT

typedef struct{

    int dia;
    int mes;
    int anno;

}eFecha;

typedef struct{

    int id;
    char desc[20];

}eComida;

typedef struct{

    int id;
    int legajo;
    int idComida;
    eFecha fecha;

}eAlmuerzo;

typedef struct{

    int ID;
    char desc[20];

}eSector;

typedef struct{

    int legajo;
    int idSector;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha ingreso;
    int ocupado;

}eEmpleado;

///FALTAN VALIDACIONES!!

int inicializarEmpleados (eEmpleado vec[], int tam);
void inicializarSectores (eSector sectores[], int tamSect);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (eEmpleado vec[], int tam, int legajoABuscar);
void bajaEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void modificarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void mostrarEmpleado (eEmpleado emp, eSector sectores[], int sector);
void mostrarEmpleados (eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void agregarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void ordenarParametro(eEmpleado vec[], int tam, int parametro, int orden);
void ordenarEmpleados(eEmpleado vec[], int tam);
void hardCodearEmpleados(eEmpleado vec[], int tam);
void hardCodearSectores(eSector sectores[], int tam);
void informesPorAnnio(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void mostrarSectores(eSector sectores[], int tam);
int elegirSector (eSector sectores[], int tam);
int averiguarSector(eEmpleado emp, eSector sectores[], int tamSect);
void swapearEmp(int i, int j, eEmpleado vec[]);
void seleccionarYMostrarSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void totalEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sectorMaxEmp(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sueldoMaxPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sueldosPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void printEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void sexosPorSector(eEmpleado vec[], eSector sectores[], int tam, int tamSect);
void cargarSectores(eSector sectores[], int tamSect);
void femeninosPorComida (eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], int tamAlm, int tam, int tamCom);
void menuInformes();
int generarLegajo(eEmpleado vec[], int tam);
int menuOpcion();
void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], eEmpleado vec[], int tamCom, int tam);
int buscarComida(int idComida, eComida comidas[], int tamCom);
void mostrarAlmuerzos(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], int tamCom, int tam, int tamAlm);
void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm);
void mostrarComidas(eComida comidas[], int tamCom);
void inicializarComidas(eComida comidas[], int tamCom);
void cargarAlmuerzos(eAlmuerzo almuerzos[], eEmpleado vec[], eComida comidas[], int tam, int tamAlm, int tamCom);
void cargarComidas(eComida comdias[], int tamCom);
void menuAlmuerzos(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], eSector sectores[], int tamSec, int tamAlm, int tam, int tamCom);
void mostrarAlmuerzoPorSector(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], eSector sectores[], int tamSec, int tamAlm, int tam, int tamCom);
void mostarAlmuerzosPorComida(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], int tamAlm, int tam, int tamCom);

int main()
{
    eEmpleado lista[TAM];
    eSector sectores[TAMSECT];
    eComida comidas[TAMCOM]={{1, "Arroz"}, {2, "Fideos"}, {3, "Milanesas"} , {4, "Hamburguesa"}, {5, "Pollo"}};
    eAlmuerzo almuerzos[TAMALM]={
        {101, 1001, 4, {15,12,2019}}
        ,{102, 1004, 1, {6,2,2019}}
        ,{103, 1006, 3, {7,9,2019}}
        ,{104, 1007, 2, {11,11,2019}}
        ,{105, 1008, 5, {1,3,2019}}
        ,{106, 1005, 4, {19,7,2019}}
        ,{107, 1002, 1, {9,10,2019}}
        ,{108, 1001, 3, {3,5,2019}}
        ,{109, 1003, 2, {8,2,2019}}
        ,{110, 1005, 5, {25,11,2019}}
     };
    int rta;

    inicializarEmpleados(lista, TAM);
    inicializarSectores(sectores, TAMSECT);
     //inicializarAlmuerzos(almuerzos, TAMALM);
    //inicializarComidas(comidas, TAMCOM);
    hardCodearSectores(sectores, TAMSECT);
    hardCodearEmpleados(lista, TAM);



    do{
        system("cls");
        rta=menuOpcion();

        switch(rta){
        case 0:
            cargarSectores(sectores, TAMSECT);
            break;
        case 1:
            agregarEmpleado(lista, sectores, TAM, TAMSECT);
            system("cls");
            break;
        case 2:
            bajaEmpleado(lista, sectores, TAM, TAMSECT);
            break;
        case 3:
            modificarEmpleado(lista, sectores, TAM, TAMSECT);
            break;
        case 4:
            ordenarEmpleados(lista, TAM);
            break;
        case 5:
            mostrarEmpleados(lista, sectores, TAM, TAMSECT);
            break;
        case 6:
            menuInformes(lista, sectores, TAM, TAMSECT);
            break;
        case 7:
            menuAlmuerzos(almuerzos, comidas, lista, sectores, TAMSECT, TAMALM, TAM, TAMCOM);
        case 8:
            printf("\nEl programa ha finalizado\n");
            system("pause");
            break;
        default:
                system("cls");
        }
    }while(rta!=8);

        return 0;
}

void modificarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int legajoModificar;
    int indexBuscar;
    int campoModificar;

    if(vec[0].ocupado==0){
        printf("Aun no se han ingresado empleados\n");
        system("pause");
    }else{

        printf("\n\nIngrese el legajo del empleado a modificar: ");
        scanf("%d", &legajoModificar);

        indexBuscar=buscarEmpleado(vec, TAM, legajoModificar);

        if(indexBuscar==-1){
            printf("\nNo existe ninguna empleado con ese legajo\n");
            system("pause");
        }else{
            do{
                system("cls");
                printf("\nEmpleado seleccionado legajo %d", legajoModificar);
                mostrarEmpleado(vec[indexBuscar], sectores, averiguarSector(vec[indexBuscar], sectores, tamSect));
                printf("\n\nIngrese el dato a modificar: ");
                printf("\n\n\t1-Nombre\n\t2-Sueldo\n\t3-Sexo\n\t4-Fecha de Ingreso\n\t5-Sector\n\t6- Terminar modificacion");
                printf("\n\nOpcion: ");
                scanf("%d", &campoModificar);

                switch(campoModificar){
                    case 1:
                        printf("\n\tIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(vec[indexBuscar].nombre);
                        break;
                    case 2:
                        printf("\n\tIngrese nuevo sueldo: ");
                        scanf("%f", &vec[indexBuscar].sueldo);
                        break;
                    case 3:
                        printf("\n\tIngrese nuevo sexo: ");
                        fflush(stdin);
                        vec[indexBuscar].sexo=tolower(getchar());
                        break;
                    case 4:
                        printf("\n\tIngrese nueva fecha de ingreso: ");
                        printf("\n\tDia: ");
                        scanf("%d", &vec[indexBuscar].ingreso.dia);
                        printf("\tMes: ");
                        scanf("%d", &vec[indexBuscar].ingreso.mes);
                        printf("\tAño: ");
                        scanf("%d", &vec[indexBuscar].ingreso.anno);
                        break;
                    case 5:
                         vec[indexBuscar].idSector=elegirSector(sectores, tamSect);
                        break;
                    case 6:
                        printf("\n\tModificacion terminada\n");
                        system("pause");
                        break;
                    default:
                        system("cls");
                        break;
                }

            }while(campoModificar!=6);

            }
        }
}

void bajaEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int legajoBaja;
    int indexBuscar;
    char confirmoBaja;

    if(vec[0].ocupado==0){
        printf("Aun no se han ingresado empleados\n");
        system("pause");
    }else{
        printf("\nIngrese el legajo a dar de baja: ");
        scanf("%d", &legajoBaja);

        indexBuscar=buscarEmpleado(vec, TAM, legajoBaja);

        if(indexBuscar==-1){
                printf("\nNo existe ningun empleado con ese legajo\n");
                system("pause");
        }else{
            printf("\nEmpleado con legajo %d: ", legajoBaja);
            mostrarEmpleado(vec[indexBuscar], sectores, averiguarSector(vec[indexBuscar], sectores, tamSect));

            printf("\n\nConfirmar la baja de este empleado? S/N: ");
            fflush(stdin);
            confirmoBaja=tolower(getchar());

            if(confirmoBaja=='n'){
                printf("\nBaja de empleado cancelada\n");
                system("pause");
            }else{
                printf("\nBaja de empleado confirmada\n");
                system("pause");
                vec[indexBuscar].ocupado=0;
            }
        }
    }


}

void ordenarEmpleados(eEmpleado vec[], int tam){

    int parametro;
    int orden;

    if(vec[0].ocupado==0){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{
        printf("\nElija un parametro por el cual ordenar: ");
        printf("\n\n\t1- Legajo\n\t2- Sexo\n\t3- Sueldo\n\t4- Nombre\n\t5- Fecha de Ingreso");
        printf("\n\n\tOpcion: ");
        scanf("%d", &parametro);
        printf("\nElija el orden: ");
        printf("\n\t1- Creciente\n\t2- Decreciente");
        printf("\n\n\tOpcion: ");
        scanf("%d", &orden);
    }

    ordenarParametro(vec, TAM, parametro, orden);
}

void swapearEmp(int i, int j, eEmpleado vec[])
{
    eEmpleado auxEmp;

    auxEmp=vec[i];
    vec[i]=vec[j];
    vec[j]=auxEmp;

}
void ordenarParametro(eEmpleado vec[], int tam, int parametro, int orden){


for(int i=0 ; i<tam-1 ; i++){

    for(int j=i+1 ; j<tam ;j++){

    switch(parametro){
        case 1:
            switch(orden){
            case 1:
                  if(vec[i].legajo>vec[j].legajo){
                    ///Legajo creciente
                    swapearEmp(i, j, vec);
                    }
                break;
            case 2:
                  if(vec[i].legajo<vec[j].legajo){
                    ///Legajo decreciente
                    swapearEmp(i, j, vec);
                    }
                break;
                }
            break;
        case 2:
                switch(orden){
            case 1:
                if(vec[i].sexo>vec[j].sexo){
                    ///Sexo creciente
                      swapearEmp(i, j, vec);
                    }
            case 2:
                if(vec[i].sexo<vec[j].sexo){
                    ///Sexo decreciente
                     swapearEmp(i, j, vec);
                    }
                }
                break;
        case 3:
            switch(orden){
                case 1:
                    if(vec[i].sueldo>vec[j].sueldo){
                    ///Sueldo creciente
                        swapearEmp(i, j, vec);
                        }
                break;
            case 2:
                if(vec[i].sueldo<vec[j].sueldo){
                    ///Sueldo decreciente
                       swapearEmp(i, j, vec);
                }
                break;
            }
            break;
        case 4:
            switch(orden){
            case 1:
                if((stricmp(vec[i].nombre, vec[j].nombre)==1)){
                    ///Nombre creciente
                    swapearEmp(i, j, vec);
            }
            break;
            case 2:
            if((stricmp(vec[i].nombre, vec[j].nombre)==-1)){
                ///Nombre decreciente
                    swapearEmp(i, j, vec);
                }
            }
            break;
        case 5:
            switch(orden){
            case 1:
                if(vec[i].ingreso.anno>vec[j].ingreso.anno){
                    ///Ingreso creciente
                    swapearEmp(i, j, vec);
                }else{
                    if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes>vec[j].ingreso.mes){
                        swapearEmp(i, j, vec);
                    }else{
                        if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes==vec[j].ingreso.mes && vec[i].ingreso.dia>vec[j].ingreso.dia){
                           swapearEmp(i, j, vec);
                        }
                    }
                }
            break;
            case 2:
                if(vec[i].ingreso.anno<vec[j].ingreso.anno){
                    ///Ingreso creciente
                   swapearEmp(i, j, vec);
                }else{
                    if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes<vec[j].ingreso.mes){
                       swapearEmp(i, j, vec);
                    }else{
                        if(vec[i].ingreso.anno==vec[j].ingreso.anno && vec[i].ingreso.mes==vec[j].ingreso.mes && vec[i].ingreso.dia<vec[j].ingreso.dia){
                          swapearEmp(i, j, vec);
                        }
                    }
                }
            break;
            }
        }

        }
}
}
void agregarEmpleado(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int legajo;
    int indexLibre;
    int indexMostrar;

    if(buscarLibre(vec, TAM)==-1){
        printf("\nNo hay lugares libres\n");
        system("pause");
    }else{
        /**
        El codigo comentado retornaba un valor correspondiente a si el empleado existia o no.
        Con esta modificacion, no se le pide ningun legajo al usuario, se le asigna uno al nuevo empleado de manera automatica.
        **/
        indexLibre=buscarLibre(vec, TAM);
        legajo=generarLegajo(vec, tam);
        /**printf("\nIngrese el legajo: ");
        scanf("%d", &legajo);
        if(buscarEmpleado(vec, TAM, legajo)==-1){
     Si buscarEmpleado devuelve -1, entonces el empleado no existe. Pido datos**/
            vec[indexLibre].legajo=legajo;
            printf("\nLegajo: %d", legajo);
            printf("\nNombre: ");
            fflush(stdin);
            gets(vec[indexLibre].nombre);
            printf("Sueldo: $");
            scanf("%f", &vec[indexLibre].sueldo);
            vec[indexLibre].ocupado=1;
            printf("Sexo: ");
            fflush(stdin);
            vec[indexLibre].sexo=getchar();
            printf("Fecha de ingreso: ");
            printf("\n\tDia: ");
            scanf("%d", &vec[indexLibre].ingreso.dia);
            printf("\tMes: ");
            scanf("%d", &vec[indexLibre].ingreso.mes);
            printf("\tAño: ");
            scanf("%d", &vec[indexLibre].ingreso.anno);
            if(sectores[0].ID==0){
                printf("Aun no se han agregado sectores. Modifique luego");
            }else{
                vec[indexLibre].idSector=elegirSector(sectores, tamSect);
            }

            printf("\nEl empleado ha sido registrado por exito\n");
            system("pause");
        /**}else{
    ///Si es diferente a -1, entonces existe, y el valor devuelto sera el indice con el que muestro
            printf("\nYa hay un empleado con ese legajo\n");
            indexMostrar=buscarEmpleado(vec, TAM, legajo);
            mostrarEmpleado(vec[indexMostrar], sectores, averiguarSector(vec[indexMostrar], sectores, tamSect));
            printf("\n\n");
            system("pause");
        }**/
      }

}

int menuOpcion(){

    int rta;

    printf("\t***ABM Empleado***");
    printf("\n\n\t0- Cargar sectores");
    printf("\n\t1- Alta empleados");
    printf("\n\t2- Baja empleado");
    printf("\n\t3- Modificar empleado");
    printf("\n\t4- Ordenar");
    printf("\n\t5- Listar");
    printf("\n\t6- Informes");
    printf("\n\t7- Almuerzos");
    printf("\n\t8- Salir");
    printf("\n\n\tIngrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}

int inicializarEmpleados(eEmpleado vec[], int tam){

    int result=-1;

    for(int i=0; i<tam ; i++){
        vec[i].ocupado=0;
        vec[i].idSector=0;
        result=0;
    }

    return result;
}



int buscarLibre(eEmpleado vec[], int tam){

    int indexLibre=-1;

    for(int i=0 ; i<tam ; i++){
        if(vec[i].ocupado==0){
            indexLibre=i;
            break;
        }
    }

    return indexLibre;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajoABuscar){

    int indexEmpleado=-1;

    for(int i=0; i<tam ; i++){
        if(vec[i].legajo==legajoABuscar && vec[i].ocupado==1){
            indexEmpleado=i;
            break;
        }
    }

    return indexEmpleado;
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int sector){

        printf("\n\tLegajo: %d\tNombre: %s\tSueldo: %.2f\tSexo: %c", emp.legajo, emp.nombre, emp.sueldo, emp.sexo);
        printf("\n\tIngreso: %02d/%02d/%d\tSector: %s\n", emp.ingreso.dia, emp.ingreso.mes, emp.ingreso.anno, sectores[sector].desc);

}

void mostrarEmpleados(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int flagMostrar=0;

        for(int i=0 ; i<tam ; i++){
            if(vec[i].ocupado==1){
              mostrarEmpleado(vec[i], sectores, averiguarSector(vec[i], sectores, tamSect));
              flagMostrar=1;
            }
        }

        if(flagMostrar==0){
            printf("\nAun no se han ingresado empleados\n");
        }
        printf("\n\n");
        system("pause");
}

int averiguarSector(eEmpleado emp, eSector sectores[], int tamSect){

    int sector;
    for(int j=0 ; j<tamSect ; j++){
        if(emp.idSector==sectores[j].ID){
                sector=j;
        }
    }
    return sector;
}

void hardCodearEmpleados(eEmpleado vec[], int tam){

    eEmpleado empleados[]={
        {1001,1,"Juan",'m',25000,{2,6,1998},1},
        {1002,3,"Maria",'f',30000,{6,4,1996},1},
        {1003,4,"Lucas",'m',15000,{10,12,2002},1},
        {1004,4,"Belen",'f',20000,{7,1,2010},1},
        {1005,5,"Mario",'m',90000,{6,5,2014},1},
        {1006,1,"Juana",'f',20000,{1,7,1999},1},
        {1007,3,"Daniel",'m',9000,{16,5,2014},1},
        {1008,1,"Kevin",'m',70000,{4,5,2010},1},
        {1009,3,"Claudia",'f',120000,{2,5,2000},1}
            };

    for(int i=0 ; i<tam ; i++){
        vec[i]=empleados[i];
    }

}

void informesPorAnnio(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int annio;
    int flagMostrar=0;

    printf("\n\n\tIngrese el anio a comprar: ");
    scanf("%d", &annio);

    for(int i=0 ; i<tam ; i++){
        if(vec[i].ingreso.anno==annio){
            for(int j=0 ; j<tamSect ; j++){
                    if(vec[i].idSector==sectores[j].ID){
                        mostrarEmpleado(vec[i], sectores, j);
                        flagMostrar=1;
                    }
            }
        }
    }

    if(flagMostrar==0){
        printf("\nNingun empleado ingreso en ese anio\n");
    }

    printf("\n\n");
    system("pause");

}

void hardCodearSectores(eSector sectores[], int tam){

    eSector sectAux[]={{1, "RRHH"},{2, "Ventas"},{3, "Compras"},{4, "Gerencia"},{5, "Calidad"}};

    for(int i=0 ; i<tam ; i++){
        sectores[i]=sectAux[i];
    }

}

void mostrarSectores(eSector sectores[], int tam){

    for(int i=0 ; i<tam ; i++){
        if(sectores[i].ID!=0){
            printf("\n\t%d- %s", sectores[i].ID, sectores[i].desc);
            printf("\n");
        }
    }

}

int elegirSector(eSector sectores[], int tam){

    int idSector;

    printf("\nElija un sector: \n");
    printf("\n\t0- No asignar sector\n");
    mostrarSectores(sectores, tam);
    printf("\nOpcion: ");
    scanf("%d", &idSector);

    return idSector;

}

int opcionesInformes(){

    int opcion;

    printf("Informes: ");
    printf("\n\n\t1- Ingrese sector para ver empleados");
    printf("\n\t2- Ver los empleados por sector");
    printf("\n\t3- Total de empleados por sector");
    printf("\n\t4- El/los sectores con mas empleados");
    printf("\n\t5- Datos de los que mas ganan por sector");
    printf("\n\t6- Averiguar ingresos por año");
    printf("\n\t7- Sueldos totales por sector");
    printf("\n\t8- Cantidad de mujeres y hombres por sector");
    printf("\n\t9- Volver al menu principal");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void menuInformes(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int opcion;

    if(vec[0].ocupado==0){
        printf("\nAun no se han ingresado empleados\n");
        system("pause");
    }else{
        do{
            system("cls");
            opcion=opcionesInformes();
            switch(opcion){

            case 1:
                seleccionarYMostrarSect(vec, sectores, tam, tamSect);
                system("pause");
                break;
            case 2:
                printEmpPorSect(vec, sectores, tam, tamSect);
                break;
            case 3:
                totalEmpPorSect(vec, sectores, tam, tamSect);
                break;
            case 4:
                sectorMaxEmp(vec, sectores, tam, tamSect);
                break;
            case 5:
                sueldoMaxPorSect(vec, sectores, tam, tamSect);
                break;
            case 6:
                informesPorAnnio(vec, sectores, tam, tamSect);
                break;
            case 7:
                sueldosPorSect(vec, sectores, tam, tamSect);
                break;
            case 8:
                sexosPorSector(vec, sectores, tam, tamSect);
                break;
            case 9:
                break;
            default:
                system("cls");
            }

        }while(opcion!=9);
    }

}

void seleccionarYMostrarSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int sectorAMostrar;

    sectorAMostrar=elegirSector(sectores, tamSect);

    for(int i=0 ; i<tam ; i++){
        if(sectorAMostrar==vec[i].idSector){
            mostrarEmpleado(vec[i], sectores, sectorAMostrar-1);
        }
    }
}

void printEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    printf("Empleados por sector");
    for(int i=0 ; i<tamSect ; i++){
        printf("\n%s:\n", sectores[i].desc);
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector && vec[j].ocupado!=0){
                mostrarEmpleado(vec[j], sectores, i);
            }
        }
    }
    system("pause");
}

void totalEmpPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int cont;

    for(int i=0 ; i<tamSect ; i++){
            cont=0;
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector && vec[j].ocupado!=0){
                cont++;
            }
        }
    printf("\n%s: %d empleado(s)", sectores[i].desc, cont);
    }
    system("pause");
}

void sectorMaxEmp(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int cont, max;

    for(int i=0 ; i<tamSect ; i++){
            cont=0;
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector){
                cont++;
            }
        }
        if(i==0){
            max=cont;
        }else{
            if(cont>max){
            max=cont;
            }
        }
    }

    printf("Sector(es) con mas empleados: \n");
    for(int i=0 ; i<tamSect ; i++){
            cont=0;
        for(int j=0 ; j<tam ; j++){
            if(sectores[i].ID==vec[j].idSector){
                cont++;
            }
        }
        if(cont==max){
            printf("%s\n", sectores[i].desc);
        }
    }

    system("pause");

}

void sueldoMaxPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    float sueldoMax;
    int indexMax;

    for(int i=0 ; i<tamSect ; i++){
        if(sectores[i].ID==0){
            continue;
        }else{
            sueldoMax=0;
            printf("%s, sueldo maximo: ", sectores[i].desc);
            indexMax=-1;
            for(int j=0 ; j<tam ; j++){
                if(vec[j].sueldo>sueldoMax && vec[j].idSector==sectores[i].ID){
                    sueldoMax=vec[j].sueldo;
                    indexMax=j;
                }
            }
            if(indexMax!=-1){
               mostrarEmpleado(vec[indexMax], sectores, i);
            }else{
                printf("\n\tSin empleados asignados\n");
            }
        }
    }
    printf("\n \n");
    system("pause");
}

void inicializarSectores (eSector sectores[], int tamSect){

    for(int i=0; i<tamSect ; i++){
        sectores[i].ID=0;
        strcpy(sectores[i].desc, "Sin sector asignado");
    }

}

void cargarSectores(eSector sectores[], int tamSect){

    char rta;
    int j;

    do{

        for(j=0 ; j<tamSect ; j++){
            if(sectores[j].ID==0){
                sectores[j].ID=j+1;
                break;
            }
        }

        printf("\nSector %d, ingrese descripcion: ", j+1);
        fflush(stdin);
        gets(sectores[j].desc);
        printf("\nIngresar otro sector? S/N: ");
        fflush(stdin);
        rta=getchar();
        rta=tolower(rta);



    }while(rta=='s');

}

void sueldosPorSect(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    float acum;

    for (int i=0 ; i<tamSect ; i++){
        acum=0;
        if(sectores[i].ID!=0){
            for(int j=0 ; j<tam ; j++){
                if(vec[j].idSector==sectores[i].ID){
                    acum+=vec[j].sueldo;
                }
            }
        printf("\nSector %s, sueldos totales: $%.2f", sectores[i].desc, acum);
        }
    }

    system("pause");


}

void sexosPorSector(eEmpleado vec[], eSector sectores[], int tam, int tamSect){

    int mujeres, hombres;

    for(int i=0 ; i<tamSect ; i++){
        mujeres=0;
        hombres=0;
        if(sectores[i].ID!=0){
             for(int j=0 ; j<tam ; j++){
                if(vec[j].idSector==sectores[i].ID){
                    if(vec[j].sexo=='f'){
                        mujeres++;
                    }else{
                        hombres++;
                    }
                }
            }
            printf("\n\tSector %s. Mujeres: %d | Hombres: %d\n", sectores[i].desc, mujeres, hombres);

        }

    }
    system("pause");

}

int generarLegajo(eEmpleado vec[], int tam){

    int indexLibre=buscarLibre(vec, tam);
    int legajoAnterior;
    int legajo;

    if(indexLibre==0){
        legajo=1000;
    }else{
        legajoAnterior=vec[indexLibre-1].legajo;
        legajo=legajoAnterior+1;
    }

    return legajo;

}

int buscarComida(int idComida, eComida comidas[], int tamCom){

    int indexCom;

    for(int i=0 ; i<tamCom ; i++){
        if(idComida==comidas[i].id){
            indexCom=i;
        }
    }

    return indexCom;
}

void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], eEmpleado vec[], int tamCom, int tam){

    int indexEmp;
    int indexCom;

    indexEmp=buscarEmpleado(vec, tam, almuerzo.legajo);
    indexCom=buscarComida(almuerzo.idComida, comidas, tamCom);

    printf("\n%d\t%d\t%s\t%s\t%02d/%02d/%d", almuerzo.id, almuerzo.legajo, vec[indexEmp].nombre, comidas[indexCom].desc, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anno);

}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], int tamCom, int tam, int tamAlm){

    printf("ID\tLegajo\tNombre\tComida\tFecha");

    for(int i=0 ; i<tamAlm ; i++){
        if(almuerzos[i].id!=0){
            mostrarAlmuerzo(almuerzos[i], comidas, vec, tamCom, tam);
        }
    }

}

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm){

    for(int i=0 ; i<tamAlm ; i++){
        almuerzos[i].id=0;
    }

}

void inicializarComidas(eComida comidas[], int tamCom){

    for(int i=0 ; i<tamCom ; i++){
        comidas[i].id=0;
    }

}

void mostrarComidas(eComida comidas[], int tamCom){

    for(int i=0 ; i<tamCom ; i++){
        if(comidas[i].id!=0){
            printf("\nID: %d, %s", comidas[i].id, comidas[i].desc);
        }
    }
}

void cargarAlmuerzos(eAlmuerzo almuerzos[], eEmpleado vec[], eComida comidas[], int tam, int tamAlm, int tamCom){

    char rta;
    int indexAlm;
    int idAlm;

    do{

        for(int i=0 ; i<tamAlm ; i++){
            if(almuerzos[i].id==0){
                indexAlm=i;
                idAlm=i+100;
                break;
            }
        }

        almuerzos[indexAlm].id=idAlm;

        printf("Almuerzo #%d\n", almuerzos[indexAlm].id);
        printf("\nLegajo empleado: ");

        for(int i=0 ; i<tam ; i++){
            if(vec[i].ocupado!=0){
                printf("\n\t%d %s", vec[i].legajo, vec[i].nombre);
            }
        }

        printf("\n\nIngrese: ");
        scanf("%d", &almuerzos[indexAlm].legajo);

        printf("Id Comida: ");
        mostrarComidas(comidas, tamCom);
        printf("\nIngrese: ");
        scanf("%d", &almuerzos[indexAlm].idComida);

        printf("Ingrese fecha: ");
        printf("\nDia: ");
        scanf("%d", &almuerzos[indexAlm].fecha.dia);
        printf("\nMes: ");
        fflush(stdin);
        scanf("%d", &almuerzos[indexAlm].fecha.mes);
        printf("\nAnno: ");
        fflush(stdin);
        scanf("%d", &almuerzos[indexAlm].fecha.anno);

        printf("Cargar otro almuerzo? S/N: ");
        fflush(stdin);
        rta=getchar();
        rta=tolower(rta);

    }while(rta=='s');

}

void cargarComidas(eComida comidas[], int tamCom){

    int rta;

    do{

        for(int i=0 ; i<tamCom ; i++){
            if(comidas[i].id==0){
                comidas[i].id=i+1;
                printf("Comida #%d, ingrese: ", comidas[i].id);
                fflush(stdin);
                gets(comidas[i].desc);
                break;
            }
        }

        printf("Cargar otra comida? S/N: ");
        fflush(stdin);
        rta=getchar();
        rta=tolower(rta);

    }while(rta=='s');
}

void menuAlmuerzos(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], eSector sectores[], int tamSec, int tamAlm, int tam, int tamCom){

    int opcion;

    do{

        system("cls");
        printf("\t**Menu Almuerzos**");
        printf("\n\n\t1- Cargar comidas");
        printf("\n\t2- Cargar almuerzos");
        printf("\n\t3- Mostrar comidas");
        printf("\n\t4- Mostrar almuerzos");
        printf("\n\t5- Mostrar almuerzo por sector");
        printf("\n\t6- Mostrar almuerzo por comida");
        printf("\n\t7-Mostrar femeninos por comida");
        printf("\n\t8- Comida preferida por sector");
        printf("\n\t9- Volver al menu principal");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
            case 1:
                cargarComidas(comidas, tamCom);
                break;
            case 2:
                cargarAlmuerzos(almuerzos, vec, comidas, tam, tamAlm, tamCom);
                break;
            case 3:
                if(comidas[0].id==0){
                    printf("\nAun no se han ingresado comidas\n");
                }else{
                    mostrarComidas(comidas, tamCom);
                }
                system("pause");
                break;
            case 4:
                if(almuerzos[0].id==0){
                    printf("\nAun no se han ingresado almuerzos\n");
                }else{
                    mostrarAlmuerzos(almuerzos, comidas, vec, tamCom, tam, tamAlm);
                }
                system("pause");
                break;
            case 5:
                mostrarAlmuerzoPorSector(almuerzos, comidas, vec, sectores, tamSec, tamAlm, tam, tamCom);
                system("pause");
                break;
            case 6:
                mostarAlmuerzosPorComida(almuerzos, comidas, vec, tamAlm, tam, tamCom);
                system("pause");
                break;
            case 7:
                femeninosPorComida(almuerzos, comidas, vec, tamAlm, tam, tamCom);
                system("pause");
            case 8:
                //comidaFavPorSector();
                break;
            case 9:
                break;
            default:
                system("cls");
       }

    }while(opcion!=9);

}

void femeninosPorComida (eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], int tamAlm, int tam, int tamCom){

    int f;

    for(int i=0 ; i<tamCom ; i++){
        f=0;
        for(int j=0 ; j<tamAlm ; j++){
            for(int k=0 ; k<tam ; k++){
                if(comidas[i].id==almuerzos[j].idComida){
                    if(almuerzos[j].legajo==vec[k].legajo && vec[k].sexo=='f'){
                        f++;
                    }
                }
            }
        }
        printf("\nFemeninos que comieron %s: %d\n", comidas[i].desc, f);
    }
}

void mostrarAlmuerzoPorSector(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], eSector sectores[], int tamSec, int tamAlm, int tam, int tamCom){

    int idSectorMostrar;
    int indexSector;

    printf("Seleccione el sector a mostrar: \n");
    mostrarSectores(sectores, tamSec);
    printf("\nOpcion: ");
    scanf("%d", &idSectorMostrar);

    for(int k=0 ; k<tamSec ; k++){
        if(sectores[k].ID==idSectorMostrar){
            indexSector=k;
            break;
        }
    }

    printf("Sector %s", sectores[indexSector].desc);

    for(int i=0 ; i<tam ; i++){
        if(vec[i].idSector==sectores[indexSector].ID){
           for(int j=0 ; j<tamAlm ; j++){
                if(vec[i].legajo==almuerzos[j].legajo){
                    mostrarAlmuerzo(almuerzos[j], comidas, vec, tamCom, tam);
                }
           }
        }
    }
}

void mostarAlmuerzosPorComida(eAlmuerzo almuerzos[], eComida comidas[], eEmpleado vec[], int tamAlm, int tam, int tamCom){

    int idComida;

    printf("\nIngrese comida a mostrar: \n");
    mostrarComidas(comidas, tamCom);
    printf("\n\nOpcion: ");
    scanf("%d", &idComida);

    for(int i=0 ; i<tamAlm ; i++){
        if(almuerzos[i].idComida==idComida){
            mostrarAlmuerzo(almuerzos[i], comidas, vec, tamCom, tam);
        }
    }

}
