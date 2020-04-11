/*
 ============================================================================
	1. Ingresar un numero entre -100 y 100
	2. y una letra
	3. mientras el usuario quiera
	4. Mostrar la cantidad de numeros pares,
	5. numeros impares
	6. y 0s
	7. Promedio de numeros positivos
	8. Suma de numeros negativos
	9. Numero y letra del max y min.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char letter;
	int num;
	int maxNum;
	int minNum;
	char maxLet;
	char minLet;
	int cantPar = 0;
	int cantImpar = 0;
	int cantCero = 0;
	int cantPos = 0;
	int sumPos = 0;
	int sumNeg = 0;
	float promedio;
	int flag = 0;
	char cont;

	setbuf(stdout,NULL);

	do {

		// Ingreso de numeros
		printf("Ingrese un numero:\n");
		scanf("%d", &num);

		// Comprueba que el numero este dentro de este rango
		while(num > 100 || num < -100)
		{
			printf("Error: Valor fuera de rango. \nIngrese un numero: \n");
			scanf("%d", &num);
		}

		// Ingreso de letras
		printf("Ingrese una letra:\n");
		fflush(stdin);
		scanf("%c", &letter);


		// Minimos y maximos

		if (flag == 0 || num > maxNum)
		{
			maxNum = num;
			maxLet = letter;
		}

		if (flag == 0|| num < minNum)
		{
			minNum = num;
			minLet = letter;
			flag++;
		}

		// Toma los numeros 0, negativos y positivos
		if (num == 0)
		{
			cantCero++;
		}
		else if (num > 0)
		{
			sumPos = sumPos + num;
			cantPos++;
		}
		else
		{
			sumNeg = sumNeg + num;
		}

		// Cuenta numeros pares e impares

		if (num % 2 == 0)
		{
			cantPar++;
		}
		else
		{
			cantImpar++;
		}

		// Continuar

		printf("Desea ingresar otro numero? S/N \n");
		fflush(stdin);
		scanf("%c", &cont);
		fflush(stdin);

	} while (cont == 'S' || cont == 's');

	// Promedio numeros positivos

	if (cantPos == 0)
	{
		promedio = 0;
	}
	else
	{
		promedio = (float) sumPos / cantPos;
	}

	// Muestra de resultados

	printf("Total numeros pares: %d\n"
			"Total numeros impares: %d\n"
			"Total de ceros: %d\n"
			"Suma de los numeros negativos: %d\n"
			"Promedio numeros positivos: %.2f\n"
			"Numero y letra maximo: %d %c\n"
			"Numero y letra minimo: %d %c\n",
			cantPar, cantImpar, cantCero, sumNeg, promedio, maxNum, maxLet, minNum, minLet);

	return EXIT_SUCCESS;
}
