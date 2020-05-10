/*
 * arrayEmployees.h
 *
 *  Created on: 9 may. 2020
 *      Author: reyna
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[20];
	char lastName[20];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */

int menue();
int printMenue();
int modifyMenue();
int initEmployees(eEmployee* list, int len);
int findEmployeeById(eEmployee* list, int len, int id);
int askData (eEmployee* list, int len, int id);
int addEmployees (eEmployee* list, int len, int id, char name[], char lastName [], float salary, int sector);
int modifyEmployee (eEmployee* list, int len);
int removeEmployee(eEmployee* list, int len, int id);
int sortEmployees(eEmployee* list, int len, int order);
void printEmployee(eEmployee emp);
int printEmployees(eEmployee* list, int len);
