#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define LEN 10 // cambiarlo a 1000 cuando termine

int main(void) {


	eEmployee employees[LEN];
	int nextID = 0000;
	char repeat = 's';

	setbuf(stdout, NULL);

	initEmployees(employees, LEN);

	printf("*** BIENVENIDO ***\n\n");

	do
	{
		system("cls");
		fflush(stdin);

		switch(menue())
		{
			case 1:
				if(askData(employees, LEN, nextID))
				{
					printf("Listado completo. No se pueden ingresar nuevos empleados.\n\n");
				}
				else
				{
					nextID++;
				}
				break;
			case 2:
				printf("modif");
				modifyEmployee(employees, LEN);
				break;
			case 3:
				if (removeEmployee(employees, LEN, 0))
				{
					printf("No se realizaron cambios.");
				}
				break;
			case 4:
				printf("informes\n");
				sortEmployees(employees, LEN, 1);
				break;
			case 5:
				printf("salir");
				break;
		}

		system("pause");

	} while (repeat == 's');

	return EXIT_SUCCESS;
}



