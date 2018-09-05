#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
/**
    static int getFloat: Valida y retorna un flotante.
    @param *pResult: Guarda los numeros ingresados luego de validarlos.
    @return Retorna 0 = OK, retorna -1 = error.

    static int getInt: Valida y retorna un int.
    @param *pResult: Guarda los numeros ingresados luego de validarlos.
    @return Retorna 0 = OK, retorna -1 = error.
*/
static int getFloat(float* pResult);
static int getInt(int* pResult);
int utn_menu(float num1,float num2)
{
    int operacion;
    printf("1. Ingresar primer numero operante (A: %.2f)\n",num1);
    printf("2. Ingresar segundo numero operante (B: %.2f)\n",num2);
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados de las operaciones\n");
    printf("5. Salir\n");
    fflush(stdin);
    utn_getInt(&operacion, 5, "Seleccione una de las opciones: ", "Esa opcion no es valida\n", 6, 0);
    return operacion;
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
int utn_getInt(int* pRes, int reint, char* msg, char* msgError, int max, int min)
{
    int auxiliarNum;
    int retorno = -1;
    for(; reint > 0 ; reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum < max && auxiliarNum > min)
            {
                *pRes = auxiliarNum;
                retorno = 0;
                break;

            }else
            {
                printf(msgError);
            }
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
static int getInt(int* pResult)
{
    int retorno = -1;
    int num;

    if(scanf("%d",&num)==1)
    {
        *pResult = num;
        retorno = 0;
    }
    return retorno;
}
void utn_respuesta(float result, char* msg)
{
    printf(msg,result);
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
int utn_dividir(float* pRes, float num1, float num2)
{
    int retorno = -1;
    if(num2 != 0)
    {
        *pRes = num1 / num2;
        retorno = 0;
    }
    return retorno;
}
int utn_factorial(float num)
{
    float i;
    float resp=1;
    if(num == 1 || num == 0)
    {
        resp = 1;
    }else if(num < 0)
    {
        resp = -1;
    }else
    {
         for (i = 1; i <= (int)num; i++)
         {
            resp = resp * i;
         }
    }
    return resp;
}
