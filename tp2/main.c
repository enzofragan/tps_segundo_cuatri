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
    int mostrar;
    int modifi;
    int baja;
    int orden;
    int prom;

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
                    if(alta>0)
                    {
                        printf("empleado guardado\n");
                    }
                    else
                    {
                        printf("error en ingresar empleado\n");
                    }
                    break;
                case 2:
                    modifi=modificarEmployees(empleados,TAM);
                    if(modifi>0)
                    {
                        printf("modificacion completa\n");
                    }
                    break;
                case 3:
                    baja=bajaEmployees(empleados,TAM);
                    break;
                case 4:
                    printf("orden ascendiente (1) o descendiente (0)");
                    fflush(stdin);
                    scanf("%d",&orden);
                    mostrar=sortEmployees(empleados,TAM,orden);
                    if(mostrar<0)
                    {
                        printf("debe ingresar un dato primero\n");
                    }
                    break;
                case 5:
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
