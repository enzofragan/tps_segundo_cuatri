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
    printf("2- \n");
    printf("3- \n");
    printf("4- \n");
    printf("5- \n");
    printf("6- salir\n");

    opcion=getInt("ingrese una opcion valida ");

    while(opcion>6)
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

int altaEmployees(eEmployee empleados[],int tam)
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
        getString("ingrese su nombre ","ingrese un nombra valido",nombre);
        getString("ingrese su apellido ","ingrese un apellido valido",apellido);
        salario=getDec("ingrese su salario ","ingrese un numero valido");
        printf("ingrese un sector ");
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

    //printf("%d  %s  %s  %f  %d",(empleados+i)->id,(empleados+i)->name,(empleados+i)->lastName,(empleados+i)->salary,(empleados+i)->sector);

    return ret;
}

int mostrarEmpleado(eEmployee* empleados)
{
    printf(" %6d %9s %9s   %.2f %10d\n",empleados->id,empleados->name,empleados->lastName,empleados->salary,empleados->sector);
}

int printEmployees(eEmployee* empleados, int length)
{
    int i;

    printf("%6s %10s %10s %8s %6s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(i=0;i<length;i++)
    {
        if((empleados+i)->isEmpty==FAL)
        {
            mostrarEmpleado(empleados+i);
        }
    }
    return 0;
}
