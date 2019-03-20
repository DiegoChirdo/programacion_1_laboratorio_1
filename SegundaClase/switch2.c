#include <stdio.h>
#include <stdlib.h>

char main()
{
    char hora;
    printf("Ingrese una hora\n");
    setbuf(NULL,stdin);
    scanf("%d",&hora);
    switch (hora)
    {
        case 24:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        printf("¡A dormir!");
        break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        printf("Es la mañana");
        break;
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        printf("Es la tarde xd");
        break;
        case 20:
        case 21:
        case 22:
        case 23:
        printf("Es de noche");
        break;
    }
    return 0;
}
