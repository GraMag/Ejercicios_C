/*
 ============================================================================
 1- Pedir dos numeros
 2- Si son iguales mostrarlos concatenados
 3- Si A > B los resto, de lo contrario los sumo
 4- Si la suma es +10 mostrar un mensaje "La suma es X y es +10"

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num1;
	int num2;
	int result;

	setbuf(stdout,NULL);
	printf("Ingrese numero:\n");
	scanf("%d",&num1);
	printf("Ingrese otro numero:\n");
	scanf("%d",&num2);

	if(num1 == num2)
	{
		printf("%d%d", num1, num2);
	}
	else if(num1>num2)
		{
			result = num1 - num2;
			printf("El resultado de la resta es %d", result);
		}
		else
		{
			result = num1 + num2;
			if (result > 10)
			{
				printf("El resultado de la suma es %d y es mayor que 10", result);
			}
			else
			{
				printf("El resultado de la suma es %d", result);
			}
		}

	return EXIT_SUCCESS;
}
