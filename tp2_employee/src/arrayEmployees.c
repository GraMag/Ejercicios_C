#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

/**
 * @brief
 *
 * @return option selected by user (1) Add, (2) Modify, (3) Remove, (4) Information (5) Exit.
 */
int menue()
{
	int option;

	printf( "\n"
			"Por favor, seleccione una opcion:\n\n"
			"1.- Alta empleado\n"
			"2.- Modificar empleado\n"
			"3.- Baja empelado\n"
			"4.- Informar\n"
			"5.- Salir\n\n");
	scanf("%d", &option);

	return option;
}

int printMenue()
{
	int option;

		printf( "\n"
				"Por favor, seleccione una opcion:\n\n"
				"1.- Listado de empleados\n"
				"2.- Estadisticas\n");
		scanf("%d", &option);

		return option;
}

int modifyMenue ()
{
	int option;

		printf( "\n"
				"Seleccione parametro a modificar:\n\n"
				"1.- Nombre\n"
				"2.- Apellido\n"
				"3.- Salario\n"
				"4.- Sector\n\n");
		scanf("%d", &option);

		return option;
}
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee* list, int len)
{
	for (int i = 0; i < len; i++) {
		list[i].isEmpty = 1;
	}
	return 0;
}

int findEmployeeById(eEmployee* list, int len, int id)
{
	for(int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				return i;
			}
		}
	return -1;
}

int askData(eEmployee* list, int len, int id)
{
	char name[20];
	char lastName[20];
	float salary;
	int sector;

	for(int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1 )
		{
			printf("Ingrese nombre: ");
			fflush(stdin);
			gets(name);
			printf("Ingrese apellido: ");
			fflush(stdin);
			gets(lastName);
			printf("Ingrese salario: ");
			scanf("%f", &salary);
			printf("Ingrese sector: ");
			scanf("%d", &sector);

			addEmployees (list, len, id, name, lastName, salary, sector);

			return 0;
		}
	}
	return -1;
}

int addEmployees (eEmployee* list, int len, int id, char name[], char lastName [], float salary, int sector)

{
	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1 )
		{
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;
			return 0;
		}
	}
	 return -1;
}

int modifyEmployee (eEmployee* list, int len)
{
	int id;
	eEmployee auxEmp;

	printf("Ingrese ID: ");
	scanf("%d", &id);

	findEmployeeById(list, len, id);
	for (int i = 0; i < len; i++)
	 {
		 if (list[i].id == id)
		 {
			switch(modifyMenue())
			{
				case 1:
					printf("Ingrese nuevo nombre: ");
					fflush(stdin);
					gets(auxEmp.name);
					strcpy(list[id].name, auxEmp.name);
				break;
				case 2:
					printf("Ingrese nuevo apellido: ");
					fflush(stdin);
					gets(auxEmp.lastName);
					strcpy(list[id].lastName, auxEmp.lastName);
					break;
				case 3:
					printf("Ingrese nuevo salario: ");
					scanf("%f", &auxEmp.salary);
					list[id].salary = auxEmp.salary;
					break;
				case 4:
					printf("Ingrese nuevo sector: ");
					scanf("%d", &auxEmp.sector);
					list[id].sector = auxEmp.sector;
					break;
				default:
					printf("No se realizaron cambios.\n\n");
					break;
			}
		 }
	 }

	return 0;
}

int removeEmployee(eEmployee* list, int len, int id)
{
	char confirm = 'n';

	if (findEmployeeById(list, len, id))
	{
		printf("No se registran usuarios con ese ID.");
	}
	else
	{
		printf("Esta seguro que desea eliminar a %s %s? s/n ", list[id].name, list[id].lastName);
		fflush(stdin);
		scanf("%c", &confirm);
		if(confirm == 's')
		{
			list[id].isEmpty = 1;
			printf("Usuario eliminado exitosamente.\n");
			return 0;
		}
	}
	return -1;
}

int sortEmployees(eEmployee* list, int len, int order)
{
	eEmployee auxEmp;
	float totalSalary = 0;
	int totalEmployees = 0;
	float averageSalary;
	int overAverageSalary = 0;

	for (int i = 0; i < len -1 ; i++)
	{

		for (int j = i+1; j < len; j ++)
		{
			if (order == 1 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) > 0))
			{
				auxEmp = list[i];
				list[i] = list[j];
				list[j] = auxEmp;
			}
			if (order == 1 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector))
			{
				auxEmp = list[i];
				list[i] = list[j];
				list[j] = auxEmp;
			}
			if (order == 0 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) < 0))
			{
				auxEmp = list[i];
				list[i] = list[j];
				list[j] = auxEmp;
			}
			if (order == 0 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector))
			{
				auxEmp = list[i];
				list[i] = list[j];
				list[j] = auxEmp;
			}

		}
		if (list[i].isEmpty == 0)
		{
			totalSalary+= list[i].salary;
			totalEmployees++;
		}
	}

	averageSalary = totalSalary / totalEmployees;

	if(printMenue() == 1)
	{
		printEmployees(list, len);
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > averageSalary)
			{
				overAverageSalary++;
			}
		}
		printf("El monto total de los salarios es: $%.2f \n", totalSalary);
		printf("El promedio de los salarios es $%.2f \n", averageSalary);
		printf("Hay %d empleados que cobran por encima del promedio.", overAverageSalary);
	}
	return 0;
}

void printEmployee(eEmployee emp)
{
	printf("| %04d | %20s | %20s | $%10.2f |   %8d   |\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector);

}

int printEmployees(eEmployee* list, int len)
{
	printf("|  ID  |        NOMBRE        |       APELLIDO       |   SALARIO   |  SECTOR  |\n");
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printEmployee(list[i]);
		}
	}
	return 0;
}
