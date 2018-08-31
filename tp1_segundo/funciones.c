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

    opcion=getInt("ingrese una opcion valida ");

    return opcion;
}
float ingresoNumero(char mensaje(),char mensajeError())
{
    float numero;

    system("cls");

    numero=getDec(mensaje,mensajeError);

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
float restar(float numeroUno,float numeroDos)
{
    float restador;

    system("cls");

    restador=numeroUno-numeroDos;

    printf("la resta es %.2f\n",restador);

    system("pause");

    return restador;
}
float multiplicar(float numeroUno,float numeroDos)
{
    float multiplicador;

    system("cls");

    multiplicador=numeroUno*numeroDos;

    printf("la multiplicacion es %.2f\n",multiplicador);

    system("pause");

    return multiplicador;
}
float dividir(float numeroUno,float numeroDos)
{
    float divisor;

    system("cls");
    if(numeroUno==0 && numeroDos==0 || numeroUno==0 || numeroDos==0)
    {
        printf("no es posible dividir por cero\n");
    }
    else
    {
        divisor=numeroUno/numeroDos;

        printf("la divicion es %.2f\n",divisor);
    }

    system("pause");

    return divisor;
}
float factoresUno(float numeroUno)
{
    float factor;

    if(numeroUno==0)
    {
        factor = 1;
    }
    else
    {
        factor=numeroUno * factoresUno(numeroUno-1);
    }

    return factor;
}
float factoresDos(float numeroDos)
{
    float factorDos;

    if(numeroDos==0)
    {
        factorDos = 1;
    }
    else
    {
        factorDos=numeroDos * factoresDos(numeroDos-1);
    }

    return factorDos;
}

int todosOperadores(float numeroUno,float numeroDos)
{
    int ret=-1;
    float suma;
    float resta;
    float mul;
    float div=0;
    float fact1;
    float fact2;

    if(numeroUno==0 && numeroDos==0)
    {
        ret=1;
    }
    else
    {
        suma=sumar(numeroUno,numeroDos);
        resta=restar(numeroUno,numeroDos);
        div=dividir(numeroUno,numeroDos);
        mul=multiplicar(numeroUno,numeroDos);
        fact1=factoresUno(numeroUno);
        fact2=factoresDos(numeroDos);

        system("cls");
        printf("el factor del primer numero es %.2f\n",fact1);
        system("pause");

        system("cls");
        printf("el factor del segundo numero es %.2f\n",fact2);
        system("pause");
        ret=0;
    }

    return ret;
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
