#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "envio.h"
#include "parser.h"

int main()
{
    int opcion = 0;
    LinkedList* envios = ll_newLinkedList();

    while(opcion != 4)
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            parser_EnvioFromText("data_final2.csv",envios);
            break;
        case 2:
            if(ll_len(envios))
            {
                print_envio(envios);
            }
            break;
        case 3:
            break;

        }
    }


    printf("Hello world!\n");
    return 0;
}
