/*
 ============================================================================
 Name        : TrabajoPracticoNro2.c
 Author      : Gaston A. Gayan
 Version     : RECUPERATORIO
 Copyright   : 1 F
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define T 1000

int main(void) {
	setbuf(stdout,NULL);
	Employee list[T];

	int opc;
	int orden;
	int id;


	initEmployees(list, T);
	do{
		opc=MenuABM("EMPLEADOS");
		if(opc!=-1)
		{
			switch(opc){

			case 1:
				printf("\n----ALTA----\n\n");

				if(dataChargeEmployee(list, T)==1){

					printf("Dato guardado con exito\n");
					system("pause");

				}else{

					printf("Error en carga de datos\n");
					system("pause");
				}

				break;

			case 2:
				printf("Baja\n");

				if(contadorEmpleados(list, T)>0){

					if(controllerRemoveEmployee(list, T)){

						printf("Dato eliminado con exito\n");
						system("pause");

					}else{

						printf("Error en borrado de datos\n");
						system("pause");

					}

				}else{
					printf("No hay datos cargados\n");
					system("pause");
				}

				break;

			case 3:
				printf("Modificacion\n");

				if(contadorEmpleados(list, T)!=0){
					printEmployees(list, T);
					if(!CargarUnEntero("Ingrese id del emplado a modificar",&id, 1, buscarIdMayor(list, T)))
					{
						if(editEmployee(list, T, id)){
							printf("\nDatos guardados con exito\n");
							system("pause");
						}
					}

				}else{
					printf("Debe ingresar un empleado para poder modificar\n");
				}
				break;

			case 4:
				if(contadorEmpleados(list, T)>0){
					printf("Listados\n");

					if(!printEmployees(list, T))
					{
						printf("Error al imprimir datos\n");
						system("pause");
					}
				}else{

					printf("No hay datos cargados\n");
					system("pause");
				}


				break;

			case 5:
				printf("Ordenar por nombre\n");

				if(contadorEmpleados(list, T)>0){

					if(!CargarUnEntero("Ingrese criterio de ordenacion ((1 = Ascendente) (0 = Descendente))",&orden,0,1))
					{
						if(!sortEmployees(list, T, orden))
						{
							printf("Error al ordenar datos\n");
							system("pause");
						}

					}
				}else{
					printf("No hay datos cargados, no es posible ordenar\n");
					system("pause");
				}
				break;

			case 6:
				printf("Informe\n");

				if(contadorEmpleados(list, T)>0){

					printf("Suma total de salarios: %.2f\n",sumaSueldosEmpleados(list, T));
					printf("Promedio total de salarios: %.2f\n",promedioSueldoEmpleados(list, T));
					printf("Cantidad total de empleados que superan el salario promedio: %d\n",salarioMayorPromedio(list, T));

				}else{
					printf("No hay datos cargados\n");
				}
				break;

			case 0:

				printf("---SALIDA---\nPROGRAMA TERMINADO");
				break;
			}
		}

	}while(opc!=0);

}
