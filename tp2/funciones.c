#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define VER 0
#define FAL 1

int initEmployees(eEmployee* empleados,int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if((empleados+i)!=NULL)
        {
           (empleados+i)->isEmpty=VER;
            ret=0;
        }
    }

    return ret;
}

int buscarLibre(eEmployee empleados[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty == VER)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int autoId(eEmployee empleados[],int tam)
{
    int i;
    int id;

    i=buscarLibre(empleados,tam);

    id=i+1;

    return id;
}

int menu()
{
    int opcion;

    printf("1- ALTA\n");
    printf("2- MODIFICAR\n");
    printf("3- BAJA\n");
    printf("4- LISTAR\n");
    printf("5- salir\n");

    opcion=getInt("ingrese una opcion valida ");

    while(opcion>5)
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

float getDec(char mensaje[],char error[])
{
    float aux;
    char buffer[64];
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",buffer);
    while(esDecimal(buffer)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }

    aux = atof(buffer);

    return aux;
}

char getChar(char mensaje[],char error[])
{
    char auxiliar;
    char buffer[64];
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",buffer);
    while(esLetra(buffer)==-1 && buffer!='y' && buffer!='n')
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }
    auxiliar=buffer;
    return auxiliar;
}


int esDecimal(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])) && cadena[i]!='.')
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
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
            }///para validar numero
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

int altaEmployees(eEmployee* empleados,int tam)
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int ret=-1;


    id=autoId(empleados,tam);

    if(id>0)
    {
        getString("ingrese su nombre: ","ingrese un nombra valido ",nombre);
        getString("ingrese su apellido: ","ingrese un apellido valido ",apellido);
        salario=getDec("ingrese su salario: ","ingrese un numero valido ");
        printf("ingrese un sector: ");
        sector=getInt("ingrese un sector valida ");
        ret=addEmployee(empleados,tam,id,nombre,apellido,salario,sector);

    }


    return ret;
}

int addEmployee(eEmployee* empleados, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int ret=-1;

    i=buscarLibre(empleados,len);

    if((empleados+i)!=NULL)
    {
        if(i>=0)
        {
            (empleados+i)->id=id;
            strcpy((empleados+i)->name,name);
            strcpy((empleados+i)->lastName,lastName);
            (empleados+i)->salary=salary;
            (empleados+i)->sector=sector;
            (empleados+i)->isEmpty=FAL;
            ret=1;
        }
        else
        {
            printf("posicion erroronea\n");
        }
    }

    mostrarEmpleado(empleados+i);

    return ret;
}

int modificarEmployees(eEmployee* empleados,int tam)
{
    int i;
    int aux;
    int opcion;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int ret=-1;


    printf("ingrese el id a buscar: ");
    aux=getInt("ingrese un id valido ");

    i=findEmployeeById(empleados,tam,aux);

    if(i>=0)
    {
        mostrarEmpleado(empleados+i);

        printf("que desea modificar?\n");
        printf("1- nombre\n");
        printf("2- apellido\n");
        printf("3- salario\n");
        printf("4- sector\n");
        printf("5- nada\n");

        opcion=getInt("ingrese una opcion valida ");

        while(opcion>5)
        {
            printf("ingrese una opcion valida: ");
            opcion=getInt("ingrese una opcion valida ");
        }

        switch(opcion)
        {
            case 1:
                getString("ingrese nuevo nombre: ","ingrese un nombra valido ",nombre);
                strcpy((empleados+i)->name,nombre);
                ret=1;
                break;
            case 2:
                getString("ingrese nuevo apellido: ","ingrese un apellido valido ",apellido);
                strcpy((empleados+i)->lastName,apellido);
                ret=1;
                break;
            case 3:
                salario=getDec("ingrese nuevo salario: ","ingrese un numero valido ");
                (empleados+i)->salary=salario;
                ret=1;
                break;
            case 4:
                printf("ingrese nuevo sector: ");
                sector=getInt("ingrese un sector valida ");
                (empleados+i)->sector=sector;
                ret=1;
                break;
            case 5:
                ret=1;
                break;
        }

        mostrarEmpleado(empleados+i);
    }
    else
    {
        printf("id no encotrado\n");
    }

    return ret;
}

int findEmployeeById(eEmployee* empleados, int len,int id)
{
    int i;
    int ret=-1;

    for(i=0;i<len;i++)
    {
        if((empleados+i)->id==id && (empleados+i)->isEmpty==FAL)
        {
            ret=i;
        }
    }
    return ret;
}

int bajaEmployees(eEmployee* empleados,int tam)
{
    int i;
    int aux;
    int ret=-1;

    printf("ingrese el id a buscar ");
    aux=getInt("ingrese un id valido ");

    i=findEmployeeById(empleados,tam,aux);

    if(i>=0)
    {
        mostrarEmpleado(empleados+i);
        ret=removeEmployee(empleados,tam,i);

        if(ret>0)
        {
            ret=1;
        }
    }
    else
    {
        printf("id no encotrado\n");
    }
    return ret;
}

int removeEmployee(eEmployee* empleados, int len, int id)
{
    char opcion;
    int ret=-1;

        opcion=getChar("desea eliminar a este empleado? ","ingrese una opcion valida ");

        while(opcion!='s' && opcion!='n')
        {
            printf("seguro? ");
            fflush(stdin);
            scanf("%c",&opcion);
        }

        if(opcion=='s')
        {
            (empleados+id)->isEmpty=VER;
            ret=1;
        }
    return ret;
}

int mostrarEmpleado(eEmployee* empleados)
{
    printf(" %6d %9s %9s   %.2f %10d\n",empleados->id,empleados->name,empleados->lastName,empleados->salary,empleados->sector);
}

int printEmployees(eEmployee* empleados, int length)
{
    int i;
    int ret=-1;

    if((empleados+i)!=NULL)
    {
         printf("%6s %10s %10s %8s %6s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

        for(i=0;i<length;i++)
        {
            if((empleados+i)->isEmpty==FAL)
            {
                mostrarEmpleado(empleados+i);
                ret=1;
            }
        }
    }

    return ret;
}

int sortEmployees(eEmployee* empleados, int len, int order)
{
    int i;
    int j;
    eEmployee aux;
    int ret=-1;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(order>0)
            {
                if((empleados+i)->isEmpty==FAL && (empleados+j)->isEmpty==FAL)
                {
                    if(strcmp((empleados+i)->lastName,(empleados+j)->lastName)>0 && (empleados+i)->sector>(empleados+j)->sector)
                    {
                        aux=*(empleados+i);
                        *(empleados+i)=*(empleados+j);
                        *(empleados+j)=aux;
                        ret=1;
                    }
                }
            }
            if(order==0)
            {
                if((empleados+i)->isEmpty==FAL && (empleados+j)->isEmpty==FAL)
                {
                    if(strcmp((empleados+i)->lastName,(empleados+j)->lastName)<0 && (empleados+i)->sector<(empleados+j)->sector)
                    {
                        aux=*(empleados+i);
                        *(empleados+i)=*(empleados+j);
                        *(empleados+j)=aux;
                        ret=1;
                    }
                }
            }
        }
    }

    if(ret>0)
    {
        printEmployees(empleados,len);

        promedioEmpleados(empleados,len);
    }
    return 0;
}

int promedioEmpleados(eEmployee* empleados,int tam)
{
    int i;
    float aux;
    int cont=0;
    float promedio;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if((empleados+i)->isEmpty==FAL)
        {
            aux=aux + (empleados+i)->salary;
            cont++;
        }
    }

    if(cont>0)
    {
        promedio = (float)aux/cont;
        ret=1;
    }

    printf("%.2f este es el promedio\n",promedio);

    return ret;
}
