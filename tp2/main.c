#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define tam 1000

int main()
{
    eEmployee empleados[tam];
    int resultado;
    char seguir='s';
    int opcion;

    resultado=initEmployees(empleados,tam);

    if(resultado==0)
    {
        do
        {
            opcion=menu();

            switch(opcion)
            {
                case 6:
                    seguir='n';
                    break;
            }
        }while(seguir=='s');
    }
    return 0;
}
