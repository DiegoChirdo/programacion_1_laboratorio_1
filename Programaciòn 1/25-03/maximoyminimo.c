#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int nro,max,min, flag = 0;
	char rta;
	do
	{
		printf("Ingrese un nro: ");
		scanf("%d",&nro);
		if (flag == 0 || nro>max)
		{
			max=nro;
		}
		if (flag == 0 || nro<min)
		{
			min=nro;
			flag=1;
		}
		printf("¿Desea continuar?");
		fflush(stdin);
		scanf("%c",&rta);
		rta = toupper(rta);


	}
	while(rta == 'S');
	system("cls");
    printf("El nro máximo es %d\nEl nro mínimo es %d",max,min);
    return 0;
}
