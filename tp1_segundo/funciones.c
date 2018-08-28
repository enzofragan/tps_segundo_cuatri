#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu(float numeroUno,float numeroDos)
{
    int opcion;

    printf("1- Ingresar 1er operando (Uno= %.2f)\n",numeroUno);
    printf("2- Ingresar 2do operando (Dos= %.2f)\n",numeroDos);
    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operacione\n");
    printf("9- Salir\n");

    scanf("%d",&opcion);

    return opcion;
}
float ingresoNumero(char mensaje(),char mensajeError())
{
    float numero;

    printf("%s",mensaje);
    scanf("%f",&numero);

    while(numero==0)
    {
       printf("%s",mensajeError);
       scanf("%f",&numero);
    }
    return numero;
}
