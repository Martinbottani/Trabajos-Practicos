#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
    float num1;
    float num2;
    float result;
    float resultDos;
    char* respuesta;
    int errores = 0;
    char operacion;
    if(utn_getDecimal(&num1, 5, "Dame el primer numero:\n", "Error, ingrese un numero valido.\n") == 0)
    {
        if(utn_getDecimal(&num2, 5, "Dame el segundo numero:\n", "Error, ingrese un numero valido.\n") == 0)
        {
            printf("El primer numero es: %.2f\nEl segundo numero es: %.2f\n", num1, num2);
        }
    }
    if(utn_getChar(&operacion, 3,
    "Ingrese la letra correspondiente a la operacion que quiere acceder:\ns = sumar\nr = restar\nm = multiplicar\nd = dividir\nf = factorizar\n",
    "Error, la letra ingresada no es valida\n") == 0)
    {
        switch(operacion)
        {
            case 's':
                utn_suma(&result, num1, num2);
                respuesta = "La respuesta de la suma de %.2f + %.2f es: %.2f";
                break;
            case 'r':
                utn_resta(&result, num1, num2);
                respuesta = "La respuesta de la resta de %.2f - %.2f es: %.2f";
                break;
            case 'm':
                utn_multiplicar(&result, num1, num2);
                respuesta = "La respuesta de la multiplicacion de %.2f x %.2f es: %.2f";
                break;
            case 'd':
                if(utn_dividir(&result, num1, num2, "No es posible dividir por 0\n") == -1)
                {
                    errores++;
                }
                respuesta = "La respuesta de la division de %.2f / %.2f es: %.2f";
                break;
            case 'f':
                result = utn_factorial(num1);
                resultDos = utn_factorial(num2);
                respuesta = "El resultado de la factorizacion de %.2f y de %.2f es: %.2f y %.2f";
        }
    }
    if(errores == 0)
    {
        printf(respuesta,num1,num2,result,resultDos);
    }

    return 0;
}
