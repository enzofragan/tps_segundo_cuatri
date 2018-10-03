#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

#endif // FUNCIONES_H_INCLUDED

int initEmployees(eEmployee*,int );
int menu();
int getInt(char []);
char getString(char [],char [],char []);
float getDec(char [],char []);
char getChar(char [],char []);
int esNumerica(char* );
int esLetra(char* );
int esDecimal(char* );
int buscarLibre(eEmployee*,int );
int autoId(eEmployee*,int );
int altaEmployees(eEmployee*,int );
int bajaEmployees(eEmployee*,int );
int modificarEmployees(eEmployee*,int );
int removeEmployee(eEmployee*, int, int );
int addEmployee(eEmployee*, int, int, char [],char [],float,int );
int findEmployeeById(eEmployee*, int,int );
int mostrarEmpleado(eEmployee* );
int printEmployees(eEmployee*, int );
int sortEmployees(eEmployee*, int, int );
int promedioEmpleados(eEmployee*,int );
