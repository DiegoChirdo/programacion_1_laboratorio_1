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
            controller_loadFromText("data_final2.csv", envios);
            break;
        case 2:
            if(ll_len(envios))
            {
                print_envio(envios);
            }
            break;
        case 3:
            ll_map(envios,laQueMapea);
            controller_saveAsText("datos23.csv",envios);
            break;
        }
    }
    return 0;
}
