#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED
/**
    utn_menu: Utiliza la función "utn_getInt" para seleccionar las opciones y las printea.
    @param num1: Guarda el numero 1 ingresado.
    @param num2: Guarda el numero 2 ingresado.
    @return : Retorna la opcion del menu que seleccionada.

    utn_getDecimal: Le pide un decimal al usuario y lo valida con getFloat.
    @param *pRes: Puntero a numero.
    @param reint: Cantidad de reintentos.
    @param msg: Muestra el mensaje.
    @param msgError: Muestra el mensaje de error.
    @return Retorna 0 = OK, retorna -1 = error.

    utn_getInt: Le pide un entero al usuario y lo valida con getInt.
    @param *pRes: Puntero a numero.
    @param reint: Cantidad de reintentos.
    @param msg: Muestra el mensaje.
    @param msgError: Muestra el mensaje de error.
    @param max: Numero maximo.
    @param min: Numero minimo.
    @return Retorna 0 = OK, retorna -1 = error.

    utn_respuesta: Recibe las respuestas y printea el mensaje con ellas.
    @param result: Numero con coma.
    @param msg: Muestra el mensaje.

    utn_suma: Suma los dos decimales ingresados por el usuario.
    @param *pRes: Guarda el resultado de la suma del numero 1 y el numero 2.
    @param num1: Guarda el numero 1 recibido.
    @param num2: Guarda el numero 2 recibido.


    utn_resta: Resta los dos decimales ingresados por el usuario.
    @param *pRes: Guarda el resultado de la resta del numero 1 y del numero 2.
    @param num1: Guarda el numero 1 ingresado.
    @param num2: Guarda el numero 2 ingresado.


    utn_multiplicar: Multiplica los dos decimales ingresados por el usuario.
    @param *pRes: Guarda el resultado de la multiplicacion del numero 1 y el numero 2.
    @param num1: Guarda el numero 1 recibido.
    @param num2: Guarda el numero 2 recibido.


    utn_dividir: Divide los dos decimales ingresados por el usuario.
    @param *pRes: Guarda el resultado de la division del numero 1 y el numero 2.
    @param num1: Guarda el numero 1 recibido.
    @param num2: Guarda el numero 2 recibido.
    @return Retorna 0 = OK, retorna -1 = error.

    utn_factorial: Factoriza los dos decimales ingresados por el usuario, utilizando un for.
    @param num: Guarda el numero para factorizar.
    @return Retorna la respuesta del numero factoreado.
*/
int utn_menu(float num1,float num2);
int utn_getDecimal(float* pRes, int reint, char* msg, char* msgError);
int utn_getInt(int* pRes,int reint,char* msg,char* msgError,int max,int min);
void utn_respuesta(float resultado, char* msg);
int utn_suma(float* pRes, float num1, float num2);
int utn_resta(float* pRes, float num1, float num2);
int utn_multiplicar(float* pRes, float num1, float num2);
int utn_dividir(float* pRes, float num1, float num2);
int utn_factorial(float num);
#endif // OPERACIONES_H_INCLUDED
