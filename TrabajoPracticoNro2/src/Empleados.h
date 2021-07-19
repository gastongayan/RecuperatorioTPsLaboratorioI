/*
 * Empleados.h
 *
 *  Created on: 14 may. 2021
 *      Author: gasto
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct{
	int idEmpleado;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}Employee;

#include "input.h"


int initEmployees(Employee* list, int tam);
int findFreeEmployee(Employee* list, int len);
int findEmployeeById(Employee* list, int len, int id);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int dataChargeEmployee(Employee* list, int len);

int printEmployees(Employee* list, int length);
void showOneEmployee(Employee* list, int index);

int controllerRemoveEmployee(Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int editEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);
int buscarIdMayor(Employee* list, int len);

float sumaSueldosEmpleados(Employee* list, int len);
int contadorEmpleados(Employee* list, int len);
float promedioSueldoEmpleados(Employee* list, int len);
int salarioMayorPromedio(Employee* list, int len);
#endif /* EMPLEADOS_H_ */
