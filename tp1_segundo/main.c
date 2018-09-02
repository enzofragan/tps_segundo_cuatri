#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    float numeroUno=0;
    float numeroDos=0;
    float suma;
    float resta;
    float mul;
    float div;
    float fact1;
    float fact2;
    int op;
    char respuesta='y';
    int opcion;

    do
    {
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
        case 4:
            resta=restar(numeroUno,numeroDos);
            break;
        case 5:
            div=dividir(numeroUno,numeroDos);
            break;
        case 6:
            mul=multiplicar(numeroUno,numeroDos);
            break;
        case 7:
            fact1=factores(numeroUno);
            fact2=factores(numeroDos);

            system("cls");
            printf("el factor del primer numero es %.2f\n",fact1);
            system("pause");

            system("cls");
            printf("el factor del segundo numero es %.2f\n",fact2);
            system("pause");
            break;
        case 8:
            op=todosOperadores(numeroUno,numeroDos);
            if(op==1)
            {
                system("cls");
                printf("no se puede realizar por que falta ingresar valores\n");
                system("pause");
            }
            break;
        case 9:

            respuesta=getChar("desas continuar? ","ingrese un valor valido, desas continuar? ");

            while(respuesta!='y' && respuesta!='n')
            {
                printf("ingrese un valor valido, desas continuar? ");
                fflush(stdin);
                scanf("%c",&respuesta);
            }
            break;
        }

        system("cls");

    }
    while(respuesta=='y');
    return 0;
}
