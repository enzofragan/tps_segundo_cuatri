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

    return 1;
}
