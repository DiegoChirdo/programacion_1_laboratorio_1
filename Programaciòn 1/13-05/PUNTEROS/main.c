#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[3] = {1, 2, 3};
    int *ptr, i;
    ptr = n;
	/* p = n;
	( p =8n[0] )  */
    for (i=0;i<3;i++)
    {
        printf("%d\n",n[i]);
    }
    for (i=0;i<3;i++)
   {
    printf("%d\n", *(ptr+i)); /*  (mostrará 1 porque ptr + i(0) igual primera posicion) == ptr + i * (sizeof(int)) */
    }

    return 0;
}
