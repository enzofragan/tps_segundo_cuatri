#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* pAux;
    int cantidad;
    char id[50];
    char nombre[50];
    char horas[50];
    char sueldo[50];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
        do{
            cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

            if(cantidad==4)
            {
                pAux=employee_new();
               employee_setId(pAux,atoi(id));
               employee_setNombre(pAux,nombre);
               employee_setHorasTrabajadas(pAux,atoi(horas));
               employee_setSueldo(pAux,atoi(sueldo));
               ll_add(pArrayListEmployee,pAux);
               ret=1;
            }
        }while(!feof(pFile));
    }
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}