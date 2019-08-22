#include <stdio.h>

int factorial(int);

void main(void)
{
	int valor,result;
	printf("\nIngrese numero:");
	scanf("%d",&valor);
	result=factorial(valor);
	printf("\nEl factorial de %d es %d",valor,result);
}
int factorial(int n)
{
	int resp;
	if(n==1)
	return 1;
	resp=n* factorial(n-1);
	return (resp);
}
