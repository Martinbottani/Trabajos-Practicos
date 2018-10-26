#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include <string.h>

static int isValidNombre(char* name);
static int isValidHorasTrabajadas(char* horasTrabajadas);
static int isValidSueldo(char* sueldo);
static int isValidId(char* id);

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL ||
        employee_setNombre(this, nombreStr) ||
        employee_setHorasTrabajadas(this, horasTrabajadasStr) ||
        employee_getSueldo(this, sueldoStr) ||
        employee_setId(this, idStr))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre) == 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    int retorno = -1;
    if(isLetra(nombre) == -1)
    {
        printf("\nNombre invalido\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas) == 0)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int retorno = -1;
    if(isInt(horasTrabajadas) == -1)
    {
        printf("\nLas horas trabajadas no son validas\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
/*
int employee_compareNombre(Employee* thisA, Employee* thisB)
{
    return strcmp(thisA->name, thisB->name);
}
*/
/*
void employee_print(Employee* this)
{
    if(this != NULL) printf("\n%d - %s - %s", this->id, this->name, this->surname);
}
*/

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo) == 0)
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

static int isValidSueldo(char* sueldo)
{
    int retorno = -1;
    if(isInt(sueldo) == -1)
    {
        printf("\nEl sueldo no es valido\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && isValidId(id) == 0)
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

static int isValidId(char* id)
{
    int retorno = -1;
    if(isInt(id) == -1)
    {
        printf("\nId invalido\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

void employee_mostrar(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int size = ll_len(pArrayListEmployee);
    Employee* pAux;
    for(i = 0; i < size; i++)
    {
        pAux = ll_get(pArrayListEmployee, i);
        employee_getId(pAux, &auxId);
        employee_getNombre(pAux, auxNombre);
        employee_getHorasTrabajadas(pAux, &auxHorasTrabajadas);
        employee_getSueldo(pAux, &auxSueldo);
        printf("\nID: %d - NOMBRE: %s - HORAS TRABAJADAS: %d - SUELDO: %d\n", &auxId, auxNombre,
                                                            &auxHorasTrabajadas, &auxSueldo);
    }
}
