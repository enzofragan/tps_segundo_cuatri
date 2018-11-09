#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int ret=-1;

    pArchivo = fopen(path,"r");

    ret=parser_EmployeeFromText(pArchivo,pArrayListEmployee);

    fclose(pArchivo);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int ret=-1;

    pArchivo = fopen(path,"rb");

    ret=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

    fclose(pArchivo);
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char id[50];
    char nombre[50];
    char horas[50];
    char sueldo[50];
    Employee* pAux;
    int ret=0;
    int aux;

    if(pArrayListEmployee!=NULL)
    {
        getStringEnteros("ingrese su id: ","ingrese un id valido ",id);
        getString("ingrese su nombre: ","ingrese un nombre valido ",nombre);
        getStringEnteros("ingrese sus horas trabajadas: ","ingrese unas horas validas ",horas);
        getStringEnteros("ingrese su sueldo: ","ingrese un sueldo valido ",sueldo);

        pAux=employee_newParametros(id,nombre,horas);

        if(pAux!=NULL)
        {
            aux=atoi(sueldo);
            employee_setSueldo(pAux,aux);
            ll_add(pArrayListEmployee,pAux);
            ret=1;
        }
    }

    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;

    len=ll_len(pArrayListEmployee);

    printf("id   nombre   horas trabajadas   sueldo\n");

    for(i=0;i<len;i++)
    {
        aux=(Employee*) ll_get(pArrayListEmployee,i);

        if(aux!=NULL)
        {
            controller_ListOneEmployee(aux);
        }
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int menu()
{
    int opcion;

    printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3- Alta de empleado\n");
    printf("4- Modificar datos de empleado\n");
    printf("5- Baja de empleado\n");
    printf("6- Listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9- Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10- Salir\n");

    opcion=getInt("ingrese una opcion valida ");

    while(opcion>10)
    {
        printf("ingrese una opcion valida ");
        opcion=getInt("ingrese una opcion valida ");
    }

    return opcion;
}

int getInt(char error[])
{
    int aux;
    char buffer[64];
    scanf("%s",buffer);
    while(esNumerica(buffer)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }
    aux = atoi(buffer);
    return aux;
}

int esNumerica(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])))
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int esLetra(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isalpha(cadena[i])))
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int controller_ListOneEmployee(Employee* empleado)
{
    int* id;
    char nombre[128];
    int* horas;
    int* sueldo;
    employee_getId(empleado,&id);
    employee_getNombre(empleado,nombre);
    employee_getHorasTrabajadas(empleado,&horas);
    employee_getSueldo(empleado,&sueldo);
    printf("%d   %s   %d   %d\n",id,nombre,horas,sueldo);
}

char getString(char mensaje[],char error[],char caracter[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(caracter);
    while(esLetra(caracter)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        gets(caracter);
    }

    return caracter;
}

char getStringEnteros(char mensaje[],char error[],char caracter[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(caracter);

    while(esNumerica(caracter)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        gets(caracter);
    }

    return caracter;
}
