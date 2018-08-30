#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    float numeroUno;
    float numeroDos;
    float suma;
    float resta;
    float mul;
    float div;
    float fact;
    char respuesta='y';
    int opcion;

    do{
        opcion=menu(numeroUno,numeroDos);

        switch(opcion)
        {
        case 1:
            numeroUno=ingresoNumero("ingrese un numero: ","ingrese un numero valido: ");
            break;
        case 2:
            numeroDos=ingresoNumero("ingrese un numero: ","ingrese un numero valido: ");
            break;
        case 3:
            suma=sumar(numeroUno,numeroDos);
            break;

        case 9:
            respuesta='n';
            break;
        }

        system("cls");

    }while(respuesta=='y');
    return 0;
}
