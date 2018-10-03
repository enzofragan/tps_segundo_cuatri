#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define TAM 1000

int main()
{
    eEmployee empleados[TAM];
    int resultado=-1;
    char seguir='s';
    int opcion;
    int alta;

    resultado=initEmployees(empleados,TAM);

    if(resultado==0)
    {
        do
        {
            opcion=menu();

            switch(opcion)
            {
                case 1:
                    alta=altaEmployees(empleados,TAM);
                    break;
                case 6:
                    seguir='n';
                    break;
            }
        }while(seguir=='s');
    }
    else
    {
        printf("se debe iniciar una lista primero\n");
    }
    return 0;
}
