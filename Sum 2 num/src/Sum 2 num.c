#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
	float num1;
	float num2;
	float result;

	printf("Ingrese un numero: ");
	scanf("%f", &num1);
	printf("Ingrese otro numero: ");
	scanf("%f", &num2);

	result = num1 + num2;

	printf("La suma de %.2f y %.2f es: %.2f \n", num1, num2, result);

	getch();

	return 0;

}
