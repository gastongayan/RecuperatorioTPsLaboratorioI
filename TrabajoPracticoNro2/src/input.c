/*
 * input.c
 *      Author: GASTON ALEJANDRO GAYAN
 *               UTN FRA
 *               1RO "F"
*       RECUPERATORIO 1ER PARCIAL
 */



//Funcion que recibe el valor como parametro devolviendolo incrmentado en 1
#include "nexo.h"
#include <ctype.h>
int idAutonumerico = 0;

int get_Id(void){

	return idAutonumerico += 1;
}

int MenuABM(char* mensaje){
	int opcion;
	printf("----%s-----\n\n", mensaje);
	puts("1. Alta\n");
	puts("2. Baja\n");
	puts("3. Modificar\n");
	puts("4. Listar\n");
	puts("5. Ordenar\n");
	puts("6. Informe\n");
	puts("0. Salir\n");
	CargarUnEntero("Ingrese una opcion",&opcion, 0, 6);

	return opcion;
}
int CargarUnFloat(char mensaje[], float* numFloat, int menor, int mayor){

	int rtn=-1;
	char numero[51];
	float auxiliar;
	int contador=0;
	do{
		printf("%s",mensaje);
		scanf("%s", numero);

		if(validar_float(numero))
		{
			auxiliar = atof(numero);
			if(auxiliar>menor && auxiliar<mayor)
			{
				*numFloat = auxiliar;
				rtn=0;
			}
			else
			{
				printf("\nError! ingrese datos entre %d y %d\n", menor, mayor);
				contador++;
			}

		}else
		{
			printf("\n Error, dato ingresado incorrecto\n");
			contador++;
		}
	}while(contador<3 && rtn!=0);

	if(contador==3 && rtn == -1){
		printf("\nDemasiados intentos realizados. \nDato no cargado\n");
		system("pause");
	}

	return rtn;
}

int validar_float(char* numeroChar) {
    int len = strlen(numeroChar);
    while (len > 0 && isspace(numeroChar[len - 1]))
        len--;
    if (len <= 0) return 0;
    int i;
    int punto = 0;
    for (i = 0; i < len; ++i) {

        if (numeroChar[i] == '-' && i > 0) {
            return 0;
        }

        if (numeroChar[i] == '.') {

            if (punto) {
                return 0;
            } else {

                punto = 1;
            }
        }

        if (!isdigit(numeroChar[i]) && numeroChar[i] != '-' && numeroChar[i] != '.') {
            return 0;
        }
    }
    return 1;
}
int validar_numero(char numero[51]){
	int len;
	int i;
	int rtn=0;
	len=strlen(numero);
	for(i=0; i<len; i++)
	{
		if(!isdigit(numero[i]))
		{
			rtn=1;
			break;
		}
	}
	return rtn;
}


int CargarUnEntero(char* mensaje, int* entero, int menor, int mayor)
{

	char numeroChar[51]="";
	int rtn=-1;
	int numeroInt;
	int contador = 0;
	do{

		printf("%s: ",mensaje);
		fflush(stdin);
		scanf("%s",numeroChar);
		if(numeroChar[0]!='\0')
		{
			if(!validar_numero(numeroChar))
			{
				numeroInt = atoi(numeroChar);
				if(validar_rango(&numeroInt, menor, mayor))
				{
					*entero=numeroInt;
					rtn=0;
					break;
				}else{
					printf("\nIngrese datos entre %d y %d\n",menor, mayor);
					contador++;
				}

			}else
			{
				printf("\nSolo se deben de cargar numeros entre %d y %d\n", menor, mayor);
				contador++;
			}
		}else
		{
			printf("\nNo se puede cargar un dato vacio");
			contador++;
		}

	}while(contador<3);
	if(contador==3){
		printf("\nDemasiados intentos realizados\n");
		system("pause");
	}
	return rtn;
}


int validar_rango(int* numero, int menor, int mayor){

	int rtn=1;


	if(*numero<menor || *numero>mayor){

		rtn=0;
	}
	return rtn;
}
int validar_cadena(char cadena[51]){
	int rtn = 0;
	int i;
	int len;
	len = strlen(cadena);
	if (len > 0 && len < 50){

		for(i=0; i<len; i++)
		{
			if(isalpha(cadena[i])==0)
			{
				rtn=1;
			}
		}
	}

	return rtn;
}

int CargarUnaCadena(char mensaje[51], char* datoIngresado){
	int rtn = 0;
	char auxString[500];
	int contador = 0;
	do{
		printf("%s:", mensaje);
		fflush(stdin);
		scanf("%s",auxString);
		if(!validar_cadena(auxString)){
			strcpy(datoIngresado, auxString);
			rtn = 1;
		}
		else
		{
			printf("Error, datos ingresados incorrectos\n");
			contador++;
		}

	}while(rtn != 1 && contador < 3);


	return rtn;
}

