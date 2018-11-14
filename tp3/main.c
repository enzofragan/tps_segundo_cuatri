#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int datoT;
    int datoB;
    int alta;
    int modificacion;
    int baja;
    int guardarT;
    int guardarB;
    do{
        option=menu();

        switch(option)
        {
            case 1:
                datoT=controller_loadFromText("data.csv",listaEmpleados);

                if(datoT==1)
                {
                    printf("datos cargados con exito\n");
                }
                else
                {
                    printf("error\n");
                }
                break;
            case 2:
                datoB=controller_loadFromBinary("data.dat",listaEmpleados);

                if(datoB==1)
                {
                    printf("datos cargados con exito\n");
                }
                else
                {
                    printf("error\n");
                }
                break;
            case 3:
                if(datoT==1 || datoB==1)
                {
                    alta=controller_addEmployee(listaEmpleados);

                    if(alta==1)
                    {
                        printf("empleado ingresado con exito\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                }
                break;
            case 4:
                if(datoT==1 || datoB==1)
                {
                    modificacion=controller_editEmployee(listaEmpleados);

                    if(modificacion==1)
                    {
                        printf("empleado modificado con exito\n");
                    }
                    else if(modificacion==0)
                    {
                        printf("accion cancelada\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                }
                break;
            case 5:
                if(datoT==1 || datoB==1)
                {
                    baja=controller_removeEmployee(listaEmpleados);

                    if(baja==1)
                    {
                        printf("empleado eliminado con exito\n");
                    }
                    else if(baja==0)
                    {
                        printf("accion cancelada\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(datoT==1 || datoB==1)
                {
                    guardarT=controller_saveAsText("data.csv",listaEmpleados);

                    if(guardarT==1)
                    {
                        printf("datos guardados con exito\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                }
                break;
            case 9:
                if(datoT==1 || datoB==1)
                {
                    guardarB=controller_saveAsBinary("data.dat",listaEmpleados);

                    if(guardarB==1)
                    {
                        printf("datos guardados con exito\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                }
                break;
        }
    }while(option != 10);
    return 0;
}
