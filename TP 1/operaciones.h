#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED
/**
    utn_getDecimal: Le pide un decimal al usuario.
    utn_getChar: Le pide un caracter al usuario para realizar una operación.
    utn_suma: Suma los dos decimales ingresados por el usuario.
    utn_resta: Resta los dos decimales ingresados por el usuario.
    utn_multiplicar: Multiplica los dos decimales ingresados por el usuario.
    utn_dividir: Divide los dos decimales ingresados por el usuario.
    utn_factorial: Factoriza los dos decimales ingresados por el usuario.
*/
int utn_getDecimal(float* pRes, int reint, char* msg, char* msgError);
int utn_getChar(char* pRes, int reint, char* msg,char* msgError);
int utn_suma(float* pRes, float num1, float num2);
int utn_resta(float* pRes, float num1, float num2);
int utn_multiplicar(float* pRes, float num1, float num2);
int utn_dividir(float* pRes, float num1, float num2, char* msgError);
int utn_factorial(float num);
#endif // OPERACIONES_H_INCLUDED
