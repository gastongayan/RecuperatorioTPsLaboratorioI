/*
 * input.h
 *
 *  Created on: 8 may. 2021
 *      Author: gasto
 */

#ifndef INPUT_H_
#define INPUT_H_


int incrementarId(int);
int CargarUnFloat(char mensaje[], float* numFloat, int menor, int mayor);
int CargarUnEntero(char mensaje[], int* entero, int menor, int mayor);

int validar_rango(int* numero, int menor, int mayor);
int CargarUnaCadena(char mensaje[51], char* datoIngresado);
int validar_numero(char numero[51]);
int validar_cadena(char cadena[51]);
int validar_float(char* numeroChar);

#endif /* INPUT_H_ */
