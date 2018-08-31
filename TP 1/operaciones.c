#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

static int getFloat(float* pResult);

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
