#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define verdadero 0
#define falso 1

int initEmployees(eEmployee* empleados,int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        empleados[i].isEmpty=verdadero;
        ret=0;
    }

    return ret;
}

int buscarLibre(eEmployee empleados[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty == verdadero)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int menu()
{
    int opcion;

    printf("1- \n");
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

int altaEmployees(eEmployee empleados[],int tam)
{
    int i;
    int id;


}
