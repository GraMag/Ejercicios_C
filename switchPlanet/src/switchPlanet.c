/*
 ============================================================================
 Name        : switchPlanet.c
 Author      : Maga
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int planet;

	setbuf(stdout,NULL);
	printf("Ingrese el numero del planeta:\n");
	scanf("%d", &planet);

	switch(planet){
	case 1:
		printf("Mercurio\n");
		break;
	case 2:
		printf("Marte\n");
		break;
	case 3:
		printf("Tierra\n");
		break;
	case 4:
		printf("Venus\n");
		break;
	case 5:
		printf("Jupiter\n");
		break;
	case 6:
		printf("Saturno\n");
		break;
	case 7:
		printf("Neptuno\n");
		break;
	case 8:
		printf("Urano\n");
		break;
	default:
		printf("No es un planeta");
		break;
	}

	return EXIT_SUCCESS;
}
