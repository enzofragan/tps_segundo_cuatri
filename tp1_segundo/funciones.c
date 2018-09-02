#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/** \brief el menu general del programa donde tiene todo lo pedido
 *
 * \param numeroUno float es el primer numero a utilizar en los calculos y se pasa para poder mostrarse en pantalla
 * \param numeroDos float es el segundo numero a utilizar en los calculos y se pasa para poder mostrarse en pantalla
 * \return int retorna el numero de la opcion elegida validado
 *
 */
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

/** \brief el ingreso de los numero que el usuario quiera utilizar y se le pasa el mensaje a utilizar y el de error por si la validacion falla
 *
 * \return float ingresoNumero(char mensaje(),char devuelve el numero en flotante por si se quiere usar un numero con coma
 *
 */
float ingresoNumero(char mensaje(),char mensajeError())
{
    float numero;

    system("cls");

    numero=getDec(mensaje,mensajeError);

    return numero;
}

/** \brief el sumador de los dos numeros
 *
 * \param numeroUno float se le pasa el primer numero guardado
 * \param numeroDos float se le pasa el segundo numero guardado
 * \return float devuelve la suma en flotante
 *
 */
float sumar(float numeroUno,float numeroDos)
{
    float sumador;

    system("cls");

    sumador=numeroUno+numeroDos;

    printf("la suma es %.2f\n",sumador);

    system("pause");

    return sumador;
}

/** \brief el restador de los dos numeros
 *
 * \param numeroUno float se le pasa el primer numero guardado
 * \param numeroDos float se le pasa el segundo numero guardado
 * \return float devuelve la resta en flotante
 *
 */
float restar(float numeroUno,float numeroDos)
{
    float restador;

    system("cls");

    restador=numeroUno-numeroDos;

    printf("la resta es %.2f\n",restador);

    system("pause");

    return restador;
}

/** \brief el multiplicador de los dos numeros
 *
 * \param numeroUno float se le pasa el primer numero guardado
 * \param numeroDos float se le pasa el segundo numero guardado
 * \return float devuelve la multiplicacion en flotante
 *
 */
float multiplicar(float numeroUno,float numeroDos)
{
    float multiplicador;

    system("cls");

    multiplicador=numeroUno*numeroDos;

    printf("la multiplicacion es %.2f\n",multiplicador);

    system("pause");

    return multiplicador;
}

/** \brief el divisor de los dos numeros y si alguno de los dos numero o ambos son 0 se mostrara el mensaje de error
 *
 * \param numeroUno float se le pasa el primer numero guardado
 * \param numeroDos float se le pasa el segundo numero guardado
 * \return float devuelve la divicion en flotante
 *
 */
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

/** \brief el factorial del numero a elegir
 *
 * \param numeroUno float se le pasa el numero y se realiza el factorial llaman do a la misma funcion hasta que retorne 1
 * \return float retorna el numero factoriado y en caso de ser 0 retornara 1
 *
 */
float factores(float numeroUno)
{
    float factor;

    if(numeroUno==0)
    {
        factor = 1;
    }
    else
    {
        factor=numeroUno * factores(numeroUno-1);
    }

    return factor;
}

/** \brief realiza todas las operaciones a la vez y las muestra una por una
 *
 * \param numeroUno float se le pasa el primer numero guardado
 * \param numeroDos float se le pasa el segundo numero guardado
 * \return int retorna si se pudieron resalizar las operaciones o no
 *
 */
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
        fact1=factores(numeroUno);
        fact2=factores(numeroDos);

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
