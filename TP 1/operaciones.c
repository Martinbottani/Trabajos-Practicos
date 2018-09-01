#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
/**
    getFloat: Valida y retorna un flotante.
    utn_getDecimal: Le pide un decimal al usuario.
    utn_getChar: Le pide un caracter al usuario y valida para realizar una operación.
    utn_suma: Suma los dos decimales ingresados por el usuario.
    utn_resta: Resta los dos decimales ingresados por el usuario.
    utn_multiplicar: Multiplica los dos decimales ingresados por el usuario.
    utn_dividir: Divide los dos decimales ingresados por el usuario.
    utn_factorial: Factoriza los dos decimales ingresados por el usuario.
    @param reint: Reintentos para el usuario.
    @param num1: Primer numero ingresado por el usuario.
    @param num2: Segundo numero ingresado por el usuario.
    @param msg: Mensaje para el usuario.
    @param msgError: Mensaje de error para el usuario.

*/
static int getFloat(float* pResult);
int utn_getChar(char* pRes, int reint, char* msg,char* msgError)
{
       int retorno = -1;
       char auxiliar;
       printf(msg);
       scanf("%c",&auxiliar);
       for(; reint > 0; reint--)
        {
            printf("Elija porfavor: ");
            scanf("%c",&auxiliar);
            if( auxiliar == 's' || auxiliar == 'r' || auxiliar == 'm'||
                auxiliar == 'd' || auxiliar == 'f')
            {
                *pRes = auxiliar;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
                fflush(stdin);
            }
        }

        return retorno;
}
int utn_getDecimal(float* pRes, int reint, char* msg,char* msgError)
{
    int retorno = -1;
    float auxiliarNum;
    for(; reint > 0; reint--)
    {
        printf(msg);
        if(getFloat(&auxiliarNum) == 0)
        {
                *pRes = auxiliarNum;
                retorno = 0;
                break;
        }else
        {
            printf(msgError);
            fflush(stdin);
        }
    }

    return retorno;
}
static int getFloat(float* pResult)
{
    int retorno = -1;
    float num;
    if(scanf("%f", &num) == 1)
    {
        *pResult = num;
        retorno = 0;
    }
    return retorno;
}
int utn_suma(float* pRes, float num1, float num2)
{
    *pRes = num1 + num2;
    return 0;
}
int utn_resta(float* pRes, float num1, float num2)
{
    *pRes = num1 - num2;
    return 0;
}
int utn_multiplicar(float* pRes, float num1, float num2)
{
    *pRes = num1 * num2;
    return 0;
}
int utn_dividir(float* pRes, float num1, float num2, char* msgError)
{
    int retorno = -1;
    if(num2 != 0)
    {
        *pRes = num1 / num2;
        retorno = 0;
    }else
    {
        printf(msgError);
    }
    return retorno;
}
int utn_factorial(float num)
{
    float resp;
    if(num == 1 || num == 0)
    {
        resp = 1;
    }else
    {
        resp = num * utn_factorial(num - 1);
    }
    return resp;
}
