#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn.h"
/**
    generarID: Genera un ID. Comienza en -1 para ir generando IDs desde el 0 en adelante.
    @param cont: Contador.
    @return return cont + 1.
*/
static int generarID(void);

int emp_cargarDatosVacio(Empleado* pEmpleados, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        pEmpleados[i].isEmpty=-1;
    }
    return 0;
}

int emp_cargarIndice(Empleado* pEmpleados,int indice,int limite)
{
    char auxNombre[32];
    char auxApellido[32];
    int auxSector;
    float auxSalario;
    printf("Nombre:\n");
    if(utn_getString(auxNombre,32)==0)
    {

                printf("Apellido: \n");
                if(utn_getString(auxApellido,128)==0)
                {
                    if(utn_getEntero(&auxSector,2,"Sector: \n", "\nError\n",6,0) == 0)
                    {
                        if(utn_getNumeroDecimal(&auxSalario, 2, "Salario: \n", "\nError\n",15000,0)== 0)
                        {
                                strncpy(pEmpleados[indice].nombre,auxNombre,32);
                                strncpy(pEmpleados[indice].apellido,auxApellido,128);
                                pEmpleados[indice].sector = auxSector;
                                pEmpleados[indice].salario = auxSalario;
                                pEmpleados[indice].isEmpty = 0;
                                pEmpleados[indice].ID = generarID();
                        }
                    }
                }

    }
    return 0;
}

int emp_indicesVacios(Empleado* pEmpleados,int limite,int* indiceVacio)
{
    int i = 0;
    int retorno = -1;
    while(i < limite)
    {
        if(pEmpleados[i].isEmpty == -1)
        {
            *indiceVacio = i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

static int generarID(void)
{
    static int cont = -1;
    return ++cont;
}

int emp_buscarPantallaPorID(Empleado* pEmpleados, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(pEmpleados[i].isEmpty == 0 && pEmpleados[i].ID == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int emp_modificarID(Empleado* pEmpleados, int indice, int limite)
{
    char auxNombre[51];
    char auxApellido[51];
    int auxSector;
    float auxSalario;
    int id;
    int opciones;
    int salir=0;
    id = emp_buscarPantallaPorID(pEmpleados,limite,indice);
    if(id >= 0)
    {
        if(pEmpleados != NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                utn_getEntero(&opciones,4,"1-Modificar nombre del empleado:\n2-Modificar apellido del empleado:\n3-Modificar sector del empleado\n4-Modificar salario del empleado\n5-Salir\n","\nError\n",6,0);
                switch(opciones)
                {
                        case 1:
                            printf("Nuevo nombre:\n");
                            if(utn_getString(auxNombre,51)==0)
                            {
                                 strncpy(pEmpleados[indice].nombre,auxNombre,51);
                            }
                            break;
                        case 2:
                             printf("Nuevo apellido: \n");
                            if(utn_getString(auxApellido,128)==0)
                            {
                                strncpy(pEmpleados[indice].apellido,auxApellido,51);
                            }
                            break;
                        case 3:
                            if(utn_getEntero(&auxSector,2,"Nuevo sector: \n", "\nError\n",4,0) == 0)
                            {
                                pEmpleados[indice].sector = auxSector;
                            }
                            break;
                        case 4:
                            if(utn_getNumeroDecimal(&auxSalario,2,"Nuevo salario: \n","\nError\n",15000,0) == 0)
                            {
                                pEmpleados[indice].salario = auxSalario;
                            }
                            system("pause");
                            break;
                        case 5:
                        salir = 1;
                }
            }while(salir==0);
        }
    }
    return 0;
}

int emp_borrarPantallaPorID(Empleado* pEmpleados, int id, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pEmpleados[i].isEmpty == 0 && pEmpleados[i].ID == id)
        {
            pEmpleados[i].isEmpty = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int emp_chequearIndice(Empleado* pEmpleados,int limite)
{
    int i=0;
    int retorno = 0;
    if(pEmpleados != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmpleados[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int emp_mostrarEmpleadosOrdenados(Empleado* pEmpleados,int limite)
{
    int retorno=-1;
    int i;
    if(pEmpleados != NULL && limite > 0)
    {
        if(emp_ordenarApellidosYSectores(pEmpleados, limite) == 0)
        {
            for(i=0;i<limite;i++)
            {
                if(pEmpleados[i].isEmpty==0)
                {
                    printf("\nEl nombre del empleado es: %s", pEmpleados[i].nombre);
                    printf("\nEl apellido del empleado es: %s", pEmpleados[i].apellido);
                    printf("\nEl sector del empleado es: %d", pEmpleados[i].sector);
                    printf("\nEl salario del empleado es: %.2f\n", pEmpleados[i].salario);
                    printf("El ID del empleado es: %d\n", pEmpleados[i].ID);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int emp_ordenarApellidosYSectores(Empleado* pEmpleados, int limite)
{
    int retorno = -1;
    Empleado auxEmpleados;
    int i;
    int flagSwap;
    if(pEmpleados != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i < limite -1; i++)
            {
                if(pEmpleados[i].sector > pEmpleados[i+1].sector ||
                (pEmpleados[i].sector == pEmpleados[i+1].sector &&
                strcmp(pEmpleados[i].apellido,pEmpleados[i+1].apellido) > 0))
                {
                    flagSwap = 1;
                    auxEmpleados = pEmpleados[i];
                    pEmpleados[i] = pEmpleados[i+1];
                    pEmpleados[i+1] = auxEmpleados;
                    retorno = 0;
                }
            }
        }while(flagSwap == 1);
    }
    return retorno;
}


int emp_calcularTotalPromedioSalarios(Empleado* pEmpleados, int limite)
{
    int retorno = -1;
    int i;
    int bandera = 0;
    float acumuladorEmpleados = 0;
    float cantSalarios = 0;
    float promedio;
    int cantMayorSalario =0;
    if(pEmpleados != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(pEmpleados[i].isEmpty == 0)
            {
                acumuladorEmpleados += pEmpleados[i].salario;
                cantSalarios++;
            }
        }

        promedio = acumuladorEmpleados / cantSalarios;

        for(i = 0; i < limite; i++)
        {
            if(pEmpleados[i].isEmpty == 0 && pEmpleados[i].salario > promedio)
            {
                cantMayorSalario++;
                bandera = 1;
            }
        }
        retorno = 0;
    }
    if(cantSalarios > 0)
    {
        printf("El total de los salarios es: %.2f", acumuladorEmpleados);
        printf(" y el promedio es: %.2f\n", promedio);
    }
    if(bandera == 1)
    {
        printf("La cantidad de salarios que superan el promedio es de: %d\n", cantMayorSalario);
    }else
    {
        printf("\nNingun salario supera al promedio\n");
    }
    return retorno;

}
