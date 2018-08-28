#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    float numeroUno;
    float numeroDos;
    char respuesta;
    int opcion;

    do{
        opcion=menu(numeroUno,numeroDos);

        switch(opcion)
        {
        case 1:
            numeroUno=ingresoNumero("ingrese un numero: ","ingrese un numero valido: ");
            break;
        }

    }while(respuesta='y');
    return 0;
}
