#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
    float num1;
    float num2;
    if(utn_getDecimal(&num1, 5, "Dame el primer numero:\n", "Error, ingrese un numero valido.\n") == 0)
    {
        if(utn_getDecimal(&num2, 5, "Dame el segundo numero:\n", "Error, ingrese un numero valido.\n") == 0)
        {
            printf("El primer numero es: %.2f\nEl segundo numero es: %.2f", num1, num2);
        }
    }
    return 0;
}
