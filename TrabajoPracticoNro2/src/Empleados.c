
#include "nexo.h"
#define VACIO 1
#define OCUPADO 0


/**
 * @fn int initEmployees(Employee*, int)
 * @brief Inicializa array colocando en TRUE el campo isEmpty de la estructura
 *
 * @param list
 * @param len
 * @return (-1) list NULL (0) OK
 */
int initEmployees(Employee* list, int len){
	int i;
	int rtn;
	rtn=-1;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++){
			list[i].isEmpty=VACIO;
			rtn=0;
		}
	}

	return rtn;
}

/**
 * @fn int findFreeEmployee(Employee*, int)
 * @brief Busca indice del array que se encuentra vacio
 *
 * @param list
 * @param len
 * @return (-1) error, indice (OK)
 */
int findFreeEmployee(Employee* list, int len){
	int i;
	int index;
	index=-1;
	for(i=0; i<len; i++){
		if(list[i].isEmpty==VACIO){
			index=i;
			break;
		}
	}
	return index;
}

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief Agrega un elemento al array con datos recibidos por parametro
 *
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return (1) OK - (0) list NULL o Longitud 0
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int index;
	int rtn;
	rtn = 0;
	if(list!=NULL && len>0){
		index=findFreeEmployee(list, len);
		if(index!=-1){
			rtn = 1;

			list[index].idEmpleado=id;
			strcpy(list[index].nombre, name);
			strcpy(list[index].apellido, lastName);
			list[index].sector=sector;
			list[index].salario=salary;
			list[index].isEmpty=OCUPADO;
		}

	}

	return rtn;


}

/**
 * @fn int dataChargeEmployee(Employee*, int)
 * @brief  Carga de datos de empleados
 *
 * @param list
 * @param len
 * @return  (0) error en grabado de datos - (1) OK - (-1) list NULL o Longitud 0
 */
int dataChargeEmployee(Employee *list, int len){


	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int rtn=-1;
	if(list!= NULL && len >0)
	{
		if(CargarUnaCadena("Ingrese nombre", name) &&
			CargarUnaCadena("Ingrese apellido", lastName)&&
			!CargarUnFloat("Ingrese salario", &salary, 0, 1000000) &&
			!CargarUnEntero("Ingrese numero de sector (0-10)", &sector, 0, 10))
		{
			id = get_Id();
			rtn=0;

			if(addEmployee(list, len, id, name, lastName, salary, sector))
			{
				rtn=1;
			}
		}
	}
	return rtn;
}



/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief Busca primer elemento vacio del array, utilizando de criterio el campo isEmpty de la estructura
 *
 * @param list
 * @param len
 * @param id
 * @return indice o (-1) ERROR (lista vacia, longitud array menor igual a 0, id menor o igual a o)
 */
int findEmployeeById(Employee* list, int len, int id)
{
	int i;
	int index=-1;

	if(list!=NULL && len>0 && id>0){
		index = 0;
		for(i=0; i<len; i++){

			if(list[i].idEmpleado==id && list[i].isEmpty==OCUPADO){

				index= i;
				break;
			}

		}

	}


	return index;
}



/**
 * @fn int controllerRemoveEmployee(Employee*, int)
 * @brief Controla eliminacion de un elemento del array
 *
 * @param list
 * @param len
 * @return (-1) lista NULL len <=0 / (1) OK / (0) ERROR
 */
int controllerRemoveEmployee(Employee* list, int len)
{
	int rtn=-1;
	int contador;
	int id;
	int opcion;
	int index;
	if(list!=NULL && len>0)
	{
		contador=contadorEmpleados(list, len);
		rtn=0;
		if(contador>0)
		{

			printEmployees(list, len);
			if(!CargarUnEntero("Ingrese id del empleado a eliminar",&id, 0, buscarIdMayor(list, len)))
			{
				index=findEmployeeById(list, len, id);
				if(!CargarUnEntero("Esta seguro de eliminar el empleado (1=SI 0=NO)",&opcion, 0, 1))
				{
					if(opcion==1)
					{
						if(!removeEmployee(list, len, index))
						{
							rtn=1;
						}
					}
				}
			}
		}
	}
	return rtn;
}

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Elimina dato colocando VACIO en campo isEmpty del Array
 *
 * @param list
 * @param len
 * @param index
 * @return (-1) error - (0) OK
 */
int removeEmployee(Employee* list, int len, int index)
{
	int rtn=-1;

	if(list != NULL && len>0)
	{
		list[index].isEmpty=VACIO;
		rtn=0;
	}

	return rtn;
}


/**
 * @fn int editEmployee(Employee*, int, int)
 * @brief edita campos del empleado buscado por id recibido por parametro
 *
 * @param list
 * @param len
 * @param id
 * @return  (0) error - (1) OK
 */
int editEmployee(Employee* list, int len, int id){
	Employee auxiliar;

	int rtn=0;
	int index;
	int opcion;
	int guardar=0;
	int bandera=0;
	if(list!=NULL && len>0)
	{

		index=findEmployeeById(list, len, id);
		showOneEmployee(list, index);
		if(index!=-1){
			auxiliar=list[index];
			do{

				if(!CargarUnEntero("\n\nQue desea modificar? \n1-Nombre\n2-Apellido\n3-Salario \n4-Sector \n0- Salir",&opcion,0,4))
				{
					switch(opcion){
						case 1:
							if(CargarUnaCadena("\nIngrese nombre", auxiliar.nombre))
							{
								bandera=1;
							}

							break;
						case 2:
							if(CargarUnaCadena("\nIngrese apellido", auxiliar.apellido))
							{
								bandera=1;
							}

							break;

						case 3:
							if(!CargarUnFloat("\nIngrese salario",&(auxiliar.salario), 0, 1000000))
							{
								bandera=1;
							}

							break;

						case 4:

							if(!CargarUnEntero("\nIngrese numero de sector (1-10)",&(auxiliar.sector), 1, 10))
							{
								bandera=1;
							}

							break;

						case 0:
							if(bandera==1){
								if(!CargarUnEntero("\nDesea guardar los cambios? 1 = SI   0 = NO",&guardar, 0, 1)){
									if(guardar==1)
									{
										list[index] = auxiliar;

										rtn=1;
									}
								}
							}
							break;
						}
				}

			}while(opcion!=0);
		}

	}
	return rtn;


}


/**
 * @fn int printEmployees(Employee*, int)
 * @brief Imprime todos los elementos del array
 *
 * @param list
 * @param length
 * @return (-1) lista NULL len <=0 / (1) OK / (0) ERROR
 */
int printEmployees(Employee* list, int length)
{
	int rtn=-1;
	int i;
	if(list!=NULL && length>0)
	{
		rtn=0;
		printf("| %4s | %10s | %15s | %15s | %10s |\n","ID","NOMBRE","APELLIDO","SECTOR","SALARIO");
		for(i=0; i<length; i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				rtn=1;
				showOneEmployee(list, i);
			}

		}

	}
	return rtn;
}

/**
 * @fn void showOneEmployee(Employee*, int)
 * @brief Muestra un solo empleado
 *
 * @param list
 * @param index
 */
void showOneEmployee(Employee* list, int index)
{
	if(list!= NULL && list[index].isEmpty==OCUPADO){
		printf("| %4d | %10s | %15s | %15d | %10.2f |\n",list[index].idEmpleado, list[index].nombre, list[index].apellido, list[index].sector, list[index].salario);
	}
}



/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Ordena empleados por nombre de acuerdo al criterio
 * 			0 - DESCENDENTE    1 - ASCENDENTE
 *
 * @param list
 * @param len
 * @param order
 * @return (-1) lista NULL len <=0 / (1) OK / (0) ERROR
 */
int sortEmployees(Employee* list, int len, int order)
{
    Employee pEmpleado;
    int rtn = -1;
    if(list != NULL && len>0)
    {
    	rtn = 0;
    	 if(order==1){
    	        for(int i=0; i<len-1; i++){
    	            for(int j=i+1; j<len; j++){

    	            	if(strcmp(list[j].nombre,list[i].nombre)<0){

    	            		pEmpleado = list[i];
    	                    list[i] = list[j];
    	                    list[j] = pEmpleado;

    	            	}
    	                else
    	                {
    	                	if(strcmp(list[j].nombre, list[i].nombre) == 0 && list[i].sector>list[j].sector){

    	                		pEmpleado = list[i];
    							list[i] = list[j];
    							list[j] = pEmpleado;
    	                	}

    	                }
    	            }
    	        }
    	        rtn = 1;
    	    }

    	    if(order==0){
    	        for(int i=0; i<len-1; i++){
    	            for(int j=i+1; j<len; j++) {

    	                if(strcmp(list[j].nombre,list[i].nombre)>0){
    	                    pEmpleado = list[i];
    	                    list[i] = list[j];
    	                    list[j] = pEmpleado;
    	                }
    	                else
    	                {

    	                	if(strcmp(list[j].nombre, list[i].nombre) == 0 && list[i].sector<list[j].sector){
    							pEmpleado = list[i];
    							list[i] = list[j];
    							list[j] = pEmpleado;
    	                	}
    	                }
    	            }
    	        }
    	        rtn = 1;
    	    }
    }


    printEmployees(list,len);
    return rtn;
}


/**
 * @fn int sumaSueldosEmpleados(Employee*, int)
 * @brief Suma los salarios de todos los empleados
 *
 * @param list
 * @param len
 * @return (-1) lista NULL len <=0 / (SUMA TOTAL) OK / (0) ERROR
 */
float sumaSueldosEmpleados(Employee* list, int len)
{
	int i;
	float acumulador=-1;
	if(list!=NULL && len>0)
	{
		acumulador=0;
		for(i=0; i<len; i++){
			if(list[i].isEmpty==OCUPADO)
			{
				acumulador+=list[i].salario;
			}
		}
	}
	return acumulador;
}

/**
 * @fn int contadorEmpleados(Employee*, int)
 * @brief
 *
 * @param list
 * @param len
 * @return (-1) lista NULL len <=0 / (CONTIDAD TOTAL DE EMPLEADOS CARGADOS) OK / (0) ERROR
 */

int contadorEmpleados(Employee* list, int len)
{
	int contador=-1;
	int i;
	if(list!=NULL && len>0)
	{
		contador=0;
		for(i=0; i<len; i++){
			if(list[i].isEmpty==OCUPADO)
			{
				contador++;

			}



		}
	}
	return contador;
}


 /**
   * @fn float promedioSueldoEmpleados(Employee*, int)
  * @brief
  *
  * @param list
  * @param len
  * @return (-1) lista NULL len <=0 / (PROMEDIO DE SUELDOS EMPLEADOS) OK / (0) ERROR
  */
float promedioSueldoEmpleados(Employee* list, int len)
{
	int contador;
	int sumador;
	float promedio=-1;

	contador=contadorEmpleados(list, len);
	sumador=sumaSueldosEmpleados(list, len);

	if(contador!=-1 && sumador!=-1)
	{
		promedio=sumador/contador;
	}

	return promedio;
}


/**
 * @fn int salarioMayorPromedio(Employee*, int)
 * @brief cuenta los salarios que superan al promedio
 *
 * @param list
 * @param len
 * @return (-1) lista NULL len <=0 / (CANT DE SUELDOS EMPLEADOS QUE SUPERAN PROMEDIO) OK / (0) ERROR
 */
int salarioMayorPromedio(Employee* list, int len)
{
	int i;
	int contador=-1;
	if(list != NULL && len>0)
	{
		contador=0;
		for(i=0; i<len; i++)
		{
			if(list[i].salario >= promedioSueldoEmpleados(list, len) && list[i].isEmpty == OCUPADO)
			{
				contador++;
			}
		}
	}

	return contador;
}

/**
 * @fn int buscarIdMayor(Employee*, int)
 * @brief Busca id Mayor del array
 *
 * @param list
 * @param len
 * @return (-1) lista NULL len <=0 / (idMayor) OK / (0) ERROR
 */
int buscarIdMayor(Employee* list, int len)
{
	int idMayor=-1;
	if(list!=NULL && len>0)
	{
		idMayor=0;
		for(int i=0; i<len; i++)
		{
			if(i==0 || list[i].idEmpleado>idMayor)
			{
				if(list[i].isEmpty==OCUPADO){

					idMayor = list[i].idEmpleado;
				}

			}
		}
	}
	return idMayor;
}
