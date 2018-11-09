#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* empleado;

    empleado=(Employee*) malloc(sizeof(Employee));

    return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* empleado;

    if(esNumerica(idStr)!=-1)
    {
        if(esLetra(nombreStr)!=-1)
        {
            if(esNumerica(horasTrabajadasStr)!=-1)
            {
                empleado=employee_new();

                if(empleado!=NULL)
                {
                    employee_setId(empleado,atoi(idStr));
                    employee_setNombre(empleado,nombreStr);
                    employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
                }
            }
        }
    }

    return empleado;
}

int employee_setId(Employee* this,int id)
{
    if(this!=NULL)
    {
        this->id=id;
    }

    return 1;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
    }

    return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
    }

    return 1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL)
    {
        this->sueldo=sueldo;
    }

    return sueldo;
}

int employee_getId(Employee* this,int* id)
{
    int ret=0;
    if(this!=NULL)
    {
        *id=this->id;
        ret = 1;
    }
    return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int ret=0;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        ret=1;
    }
    return 1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret=0;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        ret=1;
    }
    return 1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret=0;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        ret=1;
    }
    return 1;
}
