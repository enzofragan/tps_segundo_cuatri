#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int menu(float numeroUno,float numeroDos)
{
    int opcion;

    printf("1- Ingresar 1er numero (Uno= %.2f)\n",numeroUno);
    printf("2- Ingresar 2do numero (Dos= %.2f)\n",numeroDos);
    printf("3- Calcular suma (A+B)\n");
    printf("4- Calcular resta (A-B)\n");
    printf("5- Calcular division (A/B)\n");
    printf("6- Calcular multiplicacion (A*B)\n");
    printf("7- Calcular factorial (A!)\n");
    printf("8- Calcular todas las operacione\n");
    printf("9- Salir\n");

    while(getInt(&opcion)==-1)
    {
        printf("ingrese una opcion valida");
    }

    return opcion;
}
float ingresoNumero(char mensaje(),char mensajeError())
{
    float numero;

    system("cls");

    printf("%s",mensaje);

    while(getDec(&numero)==-1)
    {
       printf("%s",mensajeError);
    }

    return numero;
}

float sumar(float numeroUno,float numeroDos)
{
    float sumador;

    system("cls");

    sumador=numeroUno+numeroDos;

    printf("la suma es %.2f\n",sumador);

    system("pause");

    return sumador;
}

float getDec(float* pNum)
{
    int ret=-1;
    char buffer[64];
    scanf("%s",buffer);
    if(esDecimal(buffer)==1)
    {
        *pNum = atof(buffer);
        ret=1;
    }
    return ret;
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
            }///para validar numero
            i++;
        }
    }
    return 1;
}
int getInt(int* pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf("%s",buffer);
    if(esNumerica(buffer)==1)
    {
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
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
