#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
    float num1;
    float num2;
    float resultadoSuma = 0;
    float resultadoResta = 0;
    float resultadoMultiplicacion = 0;
    float resultadoDivision = 0;
    float resultadoFactoreo1 = 0;
    float resultadoFactoreo2 = 0;
    int errores = 0;
    int salir = 1;
    int operacion;
    do
    {
        system("cls");
        fflush(stdin);
        operacion = utn_menu(num1,num2);
        switch(operacion)
        {
            case 1:
            system("cls");
            utn_getDecimal(&num1, 5, "Ingrese Numero 1: ", "Eso no es un numero\n");
            fflush(stdin);
            break;
            case 2:
            system("cls");
            utn_getDecimal(&num2, 5, "Ingrese Numero 2: ", "Eso no es un numero\n");
            fflush(stdin);
            break;
            case 3:
            utn_suma(&resultadoSuma, num1, num2);
            utn_resta(&resultadoResta, num1, num2);
            utn_multiplicar(&resultadoMultiplicacion, num1, num2);
            resultadoFactoreo1= utn_factorial(num1);
            resultadoFactoreo2= utn_factorial(num2);
            if(resultadoFactoreo1 == -1 || resultadoFactoreo2 == -1 )
            {
                errores = 2;
            }
            if(utn_dividir(&resultadoDivision, num1, num2) == -1)
            {
                if(errores == 2)
                {
                    errores = 3;
                }else
                {
                    errores = 1;
                }
            }
            break;
            case 4:
            utn_respuesta(resultadoSuma,"1)El resultado de A+B es: %.2f \n");
            utn_respuesta(resultadoResta,"2)El resultado de A-B es: %.2f \n");
            if(num2 == 0)
            {
                utn_respuesta(resultadoDivision,"3)No se puede dividir por 0\n");
            }else
            {
                utn_respuesta(resultadoDivision,"3)El resultado de A/B es: %.2f \n");
            }
                utn_respuesta(resultadoMultiplicacion,"4)El resultado de A*B es: %.2f \n");
            if(num1 < 0)
            {
                utn_respuesta(resultadoFactoreo1,"5)No se puede factorizar el A ya que es negativo");
            }else
            {
                utn_respuesta(resultadoFactoreo1,"5)El factorial de A es: %.0f");
            }
            if(num2 < 0)
            {
                utn_respuesta(resultadoFactoreo2," y no se puede factorizar el B ya que es negativo\n");
            }else
            {
                utn_respuesta(resultadoFactoreo2," y el factorial de B es: %.0f\n");
            }
            system("pause");
            break;
            case 5:
            salir = 0;
        }
    }while(salir == 1);

return 0;
}
