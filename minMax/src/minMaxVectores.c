#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void cargarNumeros (int vec[], int tam);
float calcularPromedio (int vec[], int tam);
int buscarMax (int vec[], int tam);
int buscarMin (int vec[], int tam);
int buscarPosicion (int vec[], int num, int tam);
void contarPosicion (int num);


int main(void) {

	int num[TAM];
	int min;
	int max;

	setbuf(stdout,NULL);

	cargarNumeros(num, TAM);

	max = buscarMax(num, TAM);
	min = buscarMin(num, TAM);

	printf("El numero mayor es %d y esta en la posicion ", max);

	contarPosicion(buscarPosicion(num, max, TAM));

	printf("EL numero menor es %d y esta en la posicion ", min);

	contarPosicion(buscarPosicion(num, min, TAM));

	printf("El promedio es de los numeros es %.2f", calcularPromedio(num, TAM));

	return EXIT_SUCCESS;
}

void cargarNumeros (int vec[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%d", &vec[i]);
	}
}

int buscarMax (int vec[], int tam)
{
	int max;

	for (int i = 0; i < tam; i++)
		{
			if (vec[i] > max || i == 0) // Si el num en la posicion [i] es mayor que el numero mayor o es la primera vuelta max toma el valor
			{
				max = vec [i];
			}
		}

	return max;
}

int buscarMin (int vec[], int tam)
{
	int min;

		for (int i = 0; i < tam; i++)
			{
				if (vec[i] < min || i == 0) // Si el num en la posicion [i] es menor que el numero menor o es la primera vuelta min toma el valor
				{
					min = vec [i];
				}
			}

		return min;
}

int buscarPosicion (int vec[], int num, int tam)
{
	int position;
	int contador = 0;

	for (int i = 0; i < tam; i++)
		{
			if (vec[i] == num)
			{
				position = i + 1;
				contador++;
				printf("%d ", position);
			}
		}
	return contador;
}

void contarPosicion (int num)
{
	if (num > 1)
			{
				printf("\nSe repite %d veces\n", num);
			}
			else
			{
				printf("\nSolo se ingreso una vez.\n");
			}
}

float calcularPromedio (int vec[], int tam)
{
	int acumulador = 0;

	for (int i = 0; i < tam; i++)
		{
			acumulador += vec[i];
		}

	return ((float) acumulador / tam);
}
