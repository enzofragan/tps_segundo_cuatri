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

    ret = parser_EmployeeFromText(pArchivo,pArrayListEmployee);

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
        else
        {
            ret=0;
        }
    }
    else
    {
        ret=-1;
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
    int i;
    int idB;
    int index=-1;
    int opcion;
    char respuesta;
    int len;
    int ret=-1;
    Employee* pAux;
    char nombre[50];
    char horas[50];
    char sueldo[50];

    if(pArrayListEmployee!=NULL)
    {
        printf("ingrese el id a buscar ");
        idB=getInt("ingrese un id valido ");

        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            pAux=(Employee*) ll_get(pArrayListEmployee,i);

            if(pAux->id==idB)
            {
                pAux=employee_new();

                pAux=ll_pop(pArrayListEmployee,i);

                index=i;
                break;
            }
        }

        controller_ListOneEmployee(pAux);

        printf("que desea modificar?\n");
        printf("1- nombre\n");
        printf("2- horas trabajadas\n");
        printf("3- sueldo\n");
        printf("4- nada\n");
        opcion=getInt("ingrese una opcion valida");

        while(opcion>4)
        {
            printf("ingrese una opcion valida ");
            opcion=getInt("ingrese una opcion valida ");
        }

        switch(opcion)
        {
        case 1:
            getString("ingrese su nombre: ","ingrese un nombre valido ",nombre);

            printf("desea continuar? y/n\n");
            fflush(stdin);
            scanf("%c",&respuesta);

            while(respuesta!= 'y' && respuesta!='n')
            {
                printf("ingrese un caracter valido y/n\n");
                fflush(stdin);
                scanf("%c",&respuesta);
            }

            if(respuesta=='y')
            {
                ret=employee_setNombre(pAux,nombre);
                ll_push(pArrayListEmployee,index,pAux);
            }
            else
            {
                ll_push(pArrayListEmployee,index,pAux);
                ret=0;
            }
            break;

        case 2:
            getStringEnteros("ingrese sus horas trabajadas: ","ingrese unas horas validas ",horas);

            printf("desea continuar? y/n\n");
            fflush(stdin);
            scanf("%c",&respuesta);

            while(respuesta!= 'y' && respuesta!='n')
            {
                printf("ingrese un caracter valido y/n\n");
                fflush(stdin);
                scanf("%c",&respuesta);
            }

            if(respuesta=='y')
            {
                ret=employee_setHorasTrabajadas(pAux,atoi(horas));
                ll_push(pArrayListEmployee,index,pAux);
            }
            else
            {
                ll_push(pArrayListEmployee,index,pAux);
                ret=0;
            }
            break;
        case 3:
            getStringEnteros("ingrese su sueldo: ","ingrese un sueldo valido ",sueldo);

            printf("desea continuar? y/n\n");
            fflush(stdin);
            scanf("%c",&respuesta);

            while(respuesta!= 'y' && respuesta!='n')
            {
                printf("ingrese un caracter valido y/n\n");
                fflush(stdin);
                scanf("%c",&respuesta);
            }

            if(respuesta=='y')
            {
                ret=employee_setSueldo(pAux,atoi(sueldo));
                ll_push(pArrayListEmployee,index,pAux);
            }
            else
            {
                ll_push(pArrayListEmployee,index,pAux);
                ret=0;
            }
            break;
        case 4:
            ll_push(pArrayListEmployee,index,pAux);
            ret=0;
            break;
        }
    }

    return ret;
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
    int i;
    int idB;
    int len;
    int ret=-1;
    int index=-1;
    Employee* pAux;
    char opcion;

    if(pArrayListEmployee!=NULL)
    {
        printf("ingrese el id a buscar ");
        idB=getInt("ingrese un id valido ");

        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            pAux=(Employee*) ll_get(pArrayListEmployee,i);

            if(pAux->id==idB)
            {
                pAux=employee_new();

                pAux=(Employee*) ll_get(pArrayListEmployee,i);

                index=i;
                break;
            }
        }

        controller_ListOneEmployee(pAux);

        printf("desea eliminar este dato? y/n\n");
        fflush(stdin);
        scanf("%c",&opcion);

        while(opcion!= 'y' && opcion!='n')
        {
            printf("ingrese un caracter valido y/n\n");
            fflush(stdin);
            scanf("%c",&opcion);
        }

        if(opcion=='y')
        {
            employee_delete(pAux);
            ll_remove(pArrayListEmployee,index);
            ret=1;
        }
        else if(opcion=='n')
        {
            ret=0;
        }
    }

    return ret;
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
    int orden;
    LinkedList* listaAux = ll_newLinkedList();
    int ret=-1;

    listaAux=ll_clone(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {

        printf("de que modo quiere ordenarlo ascendiente(1) o descendiente(0) ");
        orden=getInt("ingrese un orden valido");

        while(orden!=1 && orden!=0)
        {
            printf("de que modo quiere ordenarlo ascendiente(1) o descendiente(0)");
            orden=getInt("ingrese un orden valido");
        }

        if(orden==1)
        {
            ll_sort(listaAux, compararSueldos,orden);
            controller_ListEmployee(listaAux);
            ret=1;
        }
        if(orden==0)
        {
            orden=-1;
            ll_sort(listaAux,compararSueldos,orden);
            controller_ListEmployee(listaAux);
            ret=1;
        }
    }

    return ret;
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
    FILE* pArchivo;
    int i;
    Employee* pAux;
    int len;
    int ret=-1;
    int* id;
    char nombre[128];
    int* horas;
    int* sueldo;

    pArchivo=fopen(path,"w");

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            pAux=(Employee*) ll_get(pArrayListEmployee,i);

            if(pAux!=NULL)
            {
                employee_getId(pAux,&id);
                employee_getNombre(pAux,nombre);
                employee_getHorasTrabajadas(pAux,&horas);
                employee_getSueldo(pAux,&sueldo);
                fprintf(pArchivo," %d, %s, %d, %d\n",id,nombre,horas,sueldo);
                ret=1;
            }
        }
    }
    fclose(pArchivo);
    return ret;
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
    FILE* pArchivo;
    int i;
    Employee* pAux;
    int len;
    int ret=-1;
    int cantidad;

    pArchivo=fopen(path,"wb");

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        rewind(pArchivo);

        for(i=0;i<len;i++)
        {
            pAux=(Employee*) ll_get(pArrayListEmployee,i);
            cantidad=fwrite(pAux,sizeof(Employee),1,pArchivo);
            ret=1;
        }
    }
    pclose(pArchivo);
    return ret;
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

char getChar(char mensaje[],char error[])
{
    char auxiliar;
    char buffer[64];
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",buffer);
    while(esLetra(buffer)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }
    auxiliar=buffer;

    return auxiliar;
}


int compararSueldos(void* DatoA, void* DatoB)
{
    int comp=0;
    Employee* empleado1;
    Employee* empleado2;

    if(DatoA!=NULL && DatoB!=NULL)
    {

        empleado1 = (Employee*) DatoA;
        empleado2 = (Employee*) DatoB;
       if((empleado1->sueldo)>(empleado2->sueldo))
        {
            comp = 1;
        }
        else if((empleado1->sueldo)<(empleado2->sueldo))
        {
            comp = -1;
        }
    }

    return comp;
}
