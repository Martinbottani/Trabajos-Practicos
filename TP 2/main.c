#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"
#define CANT_EMPLEADOS 1000

int main()
{
    Empleado empleados[CANT_EMPLEADOS];
    int op;
    int id;
    int indiceVacio;
    int bandera=0;
    int salir=0;
    emp_cargarDatosVacio(empleados,CANT_EMPLEADOS);
    do
    {
        system("cls");
        fflush(stdin);
        if(emp_chequearIndice(empleados,CANT_EMPLEADOS) == -1)
        {
            bandera = 1;
        }
        else
        {
            bandera = 0;
        }
        utn_getEntero(&op,3,"1-Cargar empleados:\n2-Modificar datos de empleados\n3-Baja de empleados\n4-Mostrar lista de empleados ordenada\n5-Calcular total, promedio y cuantos empleados superan el salario promedio\n6-Salir\n","\nError\n",6,0);
        switch(op)
        {
                case 1:
                    if(emp_indicesVacios(empleados,CANT_EMPLEADOS,&indiceVacio)==0)
                    {
                        emp_cargarIndice(empleados,indiceVacio,CANT_EMPLEADOS);
                        break;
                    }
                    else
                    {
                        printf("\nNo hay indice.\n");
                    }
                    break;
                case 2:
                    if(bandera == 1)
                    {
                        if(utn_getEntero(&id,2,"\nIngrese el ID a modificar: ", "Error", CANT_EMPLEADOS, -1) == 0)
                        {
                            if(id >=0)
                            {
                                emp_modificarID(empleados, id,CANT_EMPLEADOS);
                            }
                            else
                            {
                                printf("\nError, indice invalido.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(bandera == 1)
                    {
                        if(utn_getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_EMPLEADOS, -1) == 0)
                        {
                            if(id >=0)
                            {
                                emp_borrarPantallaPorID(empleados, id,CANT_EMPLEADOS);
                            }
                            else
                            {
                                printf("\nError, indice invalido.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(bandera == 1)
                    {
                        emp_mostrarEmpleadosOrdenados(empleados, CANT_EMPLEADOS);
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 5:
                    if(bandera == 1)
                    {
                        emp_calcularTotalPromedioSalarios(empleados, CANT_EMPLEADOS);
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 6:
                salir = 1;
        }
    }while(salir==0);
    return 0;
}
