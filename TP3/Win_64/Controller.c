#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(parser_EmployeeFromText(pFile , pArrayListEmployee) == 0)
    {
        printf("\nSe cargaron los datos correctamente de los empleados.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudieron cargar los datos.\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path, "rb");
    if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
    {
        printf("\nSe cargaron los datos correctamente de los empleados.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudieron cargar los datos.\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_cargarEmpleado(pArrayListEmployee) == 0)
    {
        printf("\nSe agrego correctamente el nuevo empleado.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudo agregar el nuevo empleado.\n");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_modificarEmployee(pArrayListEmployee) == 0)
    {
        printf("\nSe modifico correctamente el empleado.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudo modificar el empleado.\n");
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =- 1;
    if(employee_borrarEmployee(pArrayListEmployee) == 0)
    {
        printf("\nSe borro correctamente el empleado.\n");
        retorno=0;
    }
    else
    {
        printf("\nError, no se pudo borrar el empleado.\n");
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_mostrar(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_criterioNombre, 1);
        printf("\nSe ordeno correctamente la lista de empleados por nombre.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudo ordenar la lista.\n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosEnTexto(pArrayListEmployee, path) == 0)
    {
        printf("\nLos datos se guardaron correctamente en el archivo de texto.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudieron guardar los datos.\n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosEnBinario(pArrayListEmployee, path) == 0)
    {
        printf("\nLos datos se guardaron correctamente en el archivo binario.\n");
        retorno = 0;
    }
    else
    {
        printf("\nError, no se pudieron guardar los datos.\n");
    }
    return retorno;
}

