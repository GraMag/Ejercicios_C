#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int min; //min value
	int max; // max value
	int i; // iteration
	int bufferInt; // number

	//this program runs 5 times
	for (i = 0 ; i < 5 ; i++)
	{
		setbuf(stdout,NULL);
		printf("%d- Ingrese un numero:\n", i+1);
		scanf("%d", &bufferInt);
		// Min and max is the same number during the first iteration.
		if(i == 0)
		{
			min = bufferInt;
			max = bufferInt;
		}
		else
		{
			// Set max
			if (bufferInt > max){
				max = bufferInt;
			}
			// Set min
			if (bufferInt < min){
				min = bufferInt;
			}
		}
	}

	printf("El numero maximo es: %d \nEl numero minimo es: %d\n", max, min);
	return EXIT_SUCCESS;
}
