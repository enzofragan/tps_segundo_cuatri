#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define VER 0
#define FAL 1

/** \brief incializa la estructura empleado
 *
 * \param empleados eEmployee* estructura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna 0 si logro inicializarla
 *
 */
int initEmployees(eEmployee* empleados,int tam)
{
    int i;
    int ret=-1;

    for(i=0; i<tam; i++)
    {
        if((empleados+i)!=NULL)
        {
            (empleados+i)->isEmpty=VER;
            ret=0;
        }
    }

    return ret;
}

int initEmployeesHardcode(eEmployee* empleados)
{
    int i;
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={"enzo","luis","maria","sol","pedro"};
    char apellido[5][51]={"fragan","marcelo","anabel","santos","martin"};
    float salario[5]={15.00,20.00,15.00,30.00,40.50};
    int sector[5]={1,2,1,3,2};
    int ret=-1;

    for(i=0; i<5; i++)
    {
        if((empleados+i)!=NULL)
        {
            (empleados+i)->id=id[i];
            strcpy((empleados+i)->name,nombre[i]);
            strcpy((empleados+i)->lastName,apellido[i]);
            (empleados+i)->salary=salario[i];
            (empleados+i)->sector=sector[i];
            (empleados+i)->isEmpty=FAL;
            ret=0;
        }
    }

    return ret;
}

/** \brief busca el primer lugar libre que encuente
 *
 * \param empleados eEmployee* estructura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna la posicion encontrada
 *
 */
int buscarLibre(eEmployee* empleados,int tam)
{
    int i;
    int ret=-1;

    for(i=0; i<tam; i++)
    {
        if((empleados+i)->isEmpty == VER)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

/** \brief id auto incremental de empleados, le suma uno a la posicion libre
 *
 * \param empleados eEmployee* estruvtura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna la id auto incrementada
 *
 */
int autoId(eEmployee* empleados,int tam)
{
    int i;
    int id;

    i=buscarLibre(empleados,tam);

    id=i+1;

    return id;
}

/** \brief menu de opciones de empleados con validacion
 *
 * \return int retorna la opcion elegida
 *
 */
int menu()
{
    int opcion;

    printf("1- ALTA\n");
    printf("2- MODIFICAR\n");
    printf("3- BAJA\n");
    printf("4- LISTAR\n");
    printf("5- salir\n");

    opcion=getInt("ingrese una opcion valida ");

    while(opcion>5)
    {
        printf("ingrese una opcion valida ");
        opcion=getInt("ingrese una opcion valida ");
    }

    return opcion;
}

/** \brief el get para los numeros enteros, el proceso es el mismo que en de decimal y si es un numero pasa el buffer a int
 *
 * \param error[] char se le pasa el mensaje de error en caso de que la validacion falle
 * \return int si es un numero primero pasa la cadena a int y luego lo retorna
 *
 */
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

/** \brief get para cadena de caracteres, el proceso es el mismo que los demas, con la diferencia de que se le pasa la variable por parametro
 *
 * \param mensaje[] char mensaje a imprimir
 * \param error[] char mensaje de error
 * \param caracter[] char varible que guarda lo que se quiera ingrasar y luego se valida
 * \return char retorna lo ingresado
 *
 */
char getString(char mensaje[],char error[],char caracter[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(caracter);
    while(esLetra(caracter)==-1)
    {
        printf("%s",error);
        fflush(stdin);
        gets(caracter);
    }

    return caracter;
}

/** \brief obtiene el decimal a ingresar y lo pasa a string y lo valida
 *
 * \param mensaje[] char se le pasa el mensaje a utilizar
 * \param error[] char y el mensaje de error en caso de que la validacion falle
 * \return float retorna el numero pasado de string a float
 *
 */
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

/** \brief el get para los caracteres y es el mismo proceso que los otros dos
 *
 * \param mensaje[] char se le pasa el mensaje a utilizar
 * \param error[] char y el mensaje de error por si la validacion falla
 * \return char si es un char pasa el buffer a un auxiliar y lo retorna
 *
 */
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

/** \brief validacion para saber si el numero es decimal o si es un numero o letra
 *
 * \param cadena char* se el pasa el puntero a la cadena pasada en el get y lo recorre para verificar que se un numero o sea un numero decimal
 * \return int retorna -1 si es una letra y 1 si es un numero
 *
 */
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

/** \brief validacion para los numeros enteros
 *
 * \param cadena char* se le pasa la cadena del get y la recorre
 * \return int devuelve -1 si es una letra y 1 si es un numero
 *
 */
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

/** \brief validacion para las letras
 *
 * \param cadena char* se le pasa la cadena del get, para que la recorra
 * \return int retorna -1 si es un numero y 1 si es una letra
 *
 */
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

/** \brief alta de empleados, que pide los valores que se quiera ingresar y luego de validar los agrega
 *
 * \param empleados eEmployee* estructura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna 1 si se logro dar de alta
 *
 */
int altaEmployees(eEmployee* empleados,int tam)
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int ret=-1;


    id=autoId(empleados,tam);

    if(id>0)
    {
        getString("ingrese su nombre: ","ingrese un nombra valido ",nombre);
        getString("ingrese su apellido: ","ingrese un apellido valido ",apellido);
        salario=getDec("ingrese su salario: ","ingrese un numero valido ");
        printf("ingrese un sector: ");
        sector=getInt("ingrese un sector valida ");
        ret=addEmployee(empleados,tam,id,nombre,apellido,salario,sector);

    }

    return ret;
}

/** \brief agrega los datos ingresados a la estructura
 *
 * \param empleados eEmployee*estructura de empleados
 * \param len int cantidad de empleados
 * \param id int el id del empleado aunto calculado
 * \param name[] char nombre del empleado
 * \param lastName[] char apellido del empleado
 * \param salary float salario del empleado
 * \param sector int sector del empleado
 * \return int retorna 1 si se logro agradar
 *
 */
int addEmployee(eEmployee* empleados, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int ret=-1;

    i=buscarLibre(empleados,len);

    if((empleados+i)!=NULL)
    {
        if(i>=0)
        {
            (empleados+i)->id=id;
            strcpy((empleados+i)->name,name);
            strcpy((empleados+i)->lastName,lastName);
            (empleados+i)->salary=salary;
            (empleados+i)->sector=sector;
            (empleados+i)->isEmpty=FAL;
            ret=1;
        }
        else
        {
            printf("posicion erroronea\n");
        }
    }

    mostrarEmpleado(empleados+i);

    return ret;
}

/** \brief modificar un empleado ingresado,pide el id del empleado, lo muestra y pregunta que quiere modificar
 *
 * \param empleados eEmployee* estructura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna 1 si se logro modificar
 *
 */
int modificarEmployees(eEmployee* empleados,int tam)
{
    int i;
    int aux;
    int opcion;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int ret=-1;


    printf("ingrese el id a buscar: ");
    aux=getInt("ingrese un id valido ");

    i=findEmployeeById(empleados,tam,aux);

    if(i>=0)
    {
        mostrarEmpleado(empleados+i);

        printf("que desea modificar?\n");
        printf("1- nombre\n");
        printf("2- apellido\n");
        printf("3- salario\n");
        printf("4- sector\n");
        printf("5- nada\n");

        opcion=getInt("ingrese una opcion valida ");

        while(opcion>5)
        {
            printf("ingrese una opcion valida: ");
            opcion=getInt("ingrese una opcion valida ");
        }

        switch(opcion)
        {
        case 1:
            getString("ingrese nuevo nombre: ","ingrese un nombra valido ",nombre);
            strcpy((empleados+i)->name,nombre);
            ret=1;
            break;
        case 2:
            getString("ingrese nuevo apellido: ","ingrese un apellido valido ",apellido);
            strcpy((empleados+i)->lastName,apellido);
            ret=1;
            break;
        case 3:
            salario=getDec("ingrese nuevo salario: ","ingrese un numero valido ");
            (empleados+i)->salary=salario;
            ret=1;
            break;
        case 4:
            printf("ingrese nuevo sector: ");
            sector=getInt("ingrese un sector valida ");
            (empleados+i)->sector=sector;
            ret=1;
            break;
        case 5:
            ret=1;
            break;
        }

        mostrarEmpleado(empleados+i);
    }
    else
    {
        printf("id no encotrado\n");
    }

    return ret;
}

/** \brief busca el empleado por medio de la id
 *
 * \param empleados eEmployee* estructura de empleados
 * \param len int cantidad de empleados
 * \param id int id a buscar
 * \return int si encontro el empleado retorna su posicion
 *
 */
int findEmployeeById(eEmployee* empleados, int len,int id)
{
    int i;
    int ret=-1;

    for(i=0; i<len; i++)
    {
        if((empleados+i)->id==id && (empleados+i)->isEmpty==FAL)
        {
            ret=i;
        }
    }
    return ret;
}

/** \brief baja logica del empleado, busca el id pedido, mustra el empleado y pregunta ods veces si quiere darlo de baja
 *
 * \param empleados eEmployee* estructura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna 1 si logro darlo de vaja
 *
 */
int bajaEmployees(eEmployee* empleados,int tam)
{
    int i;
    int aux;
    int ret=-1;

    printf("ingrese el id a buscar ");
    aux=getInt("ingrese un id valido ");

    i=findEmployeeById(empleados,tam,aux);

    if(i>=0)
    {
        mostrarEmpleado(empleados+i);
        ret=removeEmployee(empleados,tam,i);

        if(ret>0)
        {
            ret=1;
        }
    }
    else
    {
        printf("id no encotrado\n");
    }
    return ret;
}

/** \brief remueve el empleado de la id buscada
 *
 * \param empleados eEmployee* estructura de empleado
 * \param len int cantidad de empleados
 * \param id int id o posicion buscada
 * \return int retorna 1 si logro removerlo o darlo de baja
 *
 */
int removeEmployee(eEmployee* empleados, int len, int id)
{
    char opcion;
    int ret=-1;

    opcion=getChar("desea eliminar a este empleado? ","ingrese una opcion valida ");

    while(opcion!='s' && opcion!='n')
    {
        printf("seguro? ");
        fflush(stdin);
        scanf("%c",&opcion);
    }

    if(opcion=='s')
    {
        (empleados+id)->isEmpty=VER;
        ret=1;
    }
    return ret;
}

/** \brief mustra un empleado
 *
 * \param empleados eEmployee* estructura de empleado
 * \return int no retorna nada
 *
 */
int mostrarEmpleado(eEmployee* empleados)
{
    printf(" %6d %9s %9s   %.2f %10d\n",empleados->id,empleados->name,empleados->lastName,empleados->salary,empleados->sector);
}

/** \brief muestra los empleados en forma estructurada
 *
 * \param empleados eEmployee* estrucgtura de empleados
 * \param length int cantidad de empleados
 * \return int retorna 1 si logro mostrarlos
 *
 */
int printEmployees(eEmployee* empleados, int length)
{
    int i;
    int ret=-1;

    if((empleados+i)!=NULL)
    {
        printf("%6s %10s %10s %8s %6s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

        for(i=0; i<length; i++)
        {
            if((empleados+i)->isEmpty==FAL)
            {
                mostrarEmpleado(empleados+i);
                ret=1;
            }
        }
    }

    return ret;
}

/** \brief ordenamiento de empleados por apellido y sector, el orden de pende del usuario y muestra el promedio y total de los salarios de los empleados
 *
 * \param empleados eEmployee* estructura de empleados
 * \param len int cantidad de empleados
 * \param order int forma de orden de empleados 1 ascendiento o 0 descendiente
 * \return int retorna 1 si se logro ordenar
 *
 */
int sortEmployees(eEmployee* empleados, int len, int order)
{
    int i;
    int j;
    eEmployee aux;
    int ret=-1;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(order==0)
            {
                if((empleados+i)->isEmpty==FAL && (empleados+j)->isEmpty==FAL)
                {
                    if((empleados+i)->sector > (empleados+j)->sector)
                    {
                            aux=*(empleados+i);
                            *(empleados+i)=*(empleados+j);
                            *(empleados+j)=aux;
                    }
                    if(strcmp((empleados+i)->lastName,(empleados+j)->lastName)>0)
                        {
                            aux=*(empleados+i);
                            *(empleados+i)=*(empleados+j);
                            *(empleados+j)=aux;
                            ret=1;
                        }
                }
            }
            if(order>0)
            {
                if((empleados+i)->isEmpty==FAL && (empleados+j)->isEmpty==FAL)
                {
                    if((empleados+i)->sector<(empleados+j)->sector)
                    {
                        aux=*(empleados+i);
                        *(empleados+i)=*(empleados+j);
                        *(empleados+j)=aux;
                    }
                    if(strcmp((empleados+i)->lastName,(empleados+j)->lastName)<0)
                    {
                        aux=*(empleados+i);
                        *(empleados+i)=*(empleados+j);
                        *(empleados+j)=aux;
                        ret=1;
                    }
                }
            }
        }
    }

    if(ret>0)
    {
        printEmployees(empleados,len);

        promedioEmpleados(empleados,len);
    }
    return 0;
}

/** \brief total y promedio de los empleados, los guarda en un acumulador y cuenta cada vez que se guarde un salario
 *
 * \param empleados eEmployee* estructura de empleados
 * \param tam int cantidad de empleados
 * \return int retorna 1 si se logro realizar la cuenta
 *
 */
int promedioEmpleados(eEmployee* empleados,int tam)
{
    int i;
    float aux;
    int cont=0;
    float promedio;
    int ret=-1;

    for(i=0; i<tam; i++)
    {
        if((empleados+i)->isEmpty==FAL)
        {
            aux=aux + (empleados+i)->salary;
            cont++;
        }
    }

    if(cont>0)
    {
        promedio = (float)aux/cont;
        ret=1;
    }

    printf("%.2f total de salario de los empleados\n%.2f este es el promedio\n",aux,promedio);

    return ret;
}
