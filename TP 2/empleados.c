#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn.h"
static int generarID(void);

int altaForzada(Empleado* empleados, int limite,char* nombre,int sector, char* apellido, float salario)
{
    int retorno = -1;
    int indiceVacio;
    indicesVacios(empleados,limite, &indiceVacio);
    if(empleados != NULL && limite >0)
    {
          if(indiceVacio >= 0)
          {
            strncpy(empleados[indiceVacio].nombre,nombre,51);
            empleados[indiceVacio].sector=sector;
            strncpy(empleados[indiceVacio].apellido,apellido,51);
            empleados[indiceVacio].salario=salario;
            empleados[indiceVacio].ID=generarID();
            empleados[indiceVacio].isEmpty=0;
            retorno =0;
          }
    }
    return retorno;
}
int cargarDatosVacio(Empleado* empleados, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        empleados[i].isEmpty=-1;
    }
    return 0;
}
int cargarIndice(Empleado* empleados,int indice,int limite)
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
                                strncpy(empleados[indice].nombre,auxNombre,32);
                                strncpy(empleados[indice].apellido,auxApellido,128);
                                empleados[indice].sector = auxSector;
                                empleados[indice].salario = auxSalario;
                                empleados[indice].isEmpty = 0;
                                empleados[indice].ID = generarID();
                        }
                    }
                }

    }
    return 0;
}
int indicesVacios(Empleado* empleados,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    while(i<limite)
    {
        if(empleados[i].isEmpty==-1)
        {
            *indiceVacio=i;
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
int buscarPantallaPorID(Empleado* empleados, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].ID == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int modificarID(Empleado* empleados, int indice, int limite)
{
    char auxNombre[51];
    char auxApellido[51];
    int auxSector;
    float auxSalario;
    int id;
    int opciones;
    int salir=0;
    id = buscarPantallaPorID(empleados,limite,indice);
    if(id >= 0)
    {
        if(empleados != NULL && limite >0)
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
                                 strncpy(empleados[indice].nombre,auxNombre,51);
                            }
                            break;
                        case 2:
                             printf("Nuevo apellido: \n");
                            if(utn_getString(auxApellido,128)==0)
                            {
                                strncpy(empleados[indice].apellido,auxApellido,51);
                            }
                            break;
                        case 3:
                            if(utn_getEntero(&auxSector,2,"Nuevo sector: \n", "\nError\n",4,0) == 0)
                            {
                                empleados[indice].sector = auxSector;
                            }
                            break;
                        case 4:
                            if(utn_getNumeroDecimal(&auxSalario,2,"Nuevo salario: \n","\nError\n",15000,0) == 0)
                            {
                                empleados[indice].salario = auxSalario;
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
int borrarPantallaPorID(Empleado* empleados, int id, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].ID == id)
        {
            empleados[i].isEmpty = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int chequearIndice(Empleado* empleados,int limite)
{
    int i=0;
    int retorno = 0;
    if(empleados != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(empleados[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}
int calcularTotalPromedioSalarios(Empleado* empleados, int limite)
{
    int retorno = -1;
    int i;
    int bandera = 0;
    float acumuladorEmpleados = 0;
    float cantSalarios = 0;
    float promedio;
    int cantMayorSalario =0;
    if(empleados != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(empleados[i].isEmpty == 0)
            {
                acumuladorEmpleados += empleados[i].salario;
                cantSalarios++;
            }
        }

        promedio = acumuladorEmpleados / cantSalarios;

        for(i = 0; i < limite; i++)
        {
            if(empleados[i].isEmpty == 0 && empleados[i].salario > promedio)
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
    }else
    {
        printf("No hay salarios cargados\n");
    }
    if(bandera == 1)
    {
        printf("La cantidad de salarios que superan el promedio es de: %d\n", cantMayorSalario);
    }else
    {
        printf("Ningun salario supera al promedio");
    }
    return retorno;

}
