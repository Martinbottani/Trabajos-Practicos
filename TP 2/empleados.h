#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
struct S_empleado{
int ID;
char nombre[51];
int sector;
char apellido[51];
float salario;
int isEmpty;
}typedef Empleado;
/**
    emp_cargarDatosVacio: Carga un valor en el mismo campo de todas las posiciones del array recibido.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_cargarDatosVacio(Empleado* pEmpleados,int limite);
/**
    emp_cargarIndice: carga valores en la posicion del array recibido.
    @param pEmpleado: Guarda el array recibido.
    @param indice: Guarda el int de la posicion del array.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_cargarIndice(Empleado* pEmpleados,int indice,int limite);
/**
    emp_indicesVacios: Busca dentro del array hasta encontrar un indice vacio donde cargar un dato.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param indiceVacio: Guarda el indice de la posicion vacia del array.
    @return return 0 OK, -1 Error.
*/
int emp_indicesVacios(Empleado* pEmpleados,int limite,int* indiceVacio);
/**
    emp_buscarEmpleadoPorID: Recibe un ID para buscar un empleado.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param id: Guarda el int del empleado a buscar.
    @return return el indice del array donde esta el empleado.
*/
int emp_buscarPantallaPorID(Empleado* pEmpleados, int limite, int id);
/**
    emp_modificarIndice: Recibe un ID para modificar una posicion del array.
    @param pEmpleado: Guarda el array recibido.
    @param id: Guarda el int recibido del ID a modificar.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_modificarID(Empleado* pEmpleados, int indice, int limite);
/**
    emp_borrarEmpleado: Recibe un ID para borrar un empleado.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param id: Guarda el int del empleado a borrar.
    @return return 0 OK, -1 Error.
*/
int emp_borrarPantallaPorID(Empleado* pEmpleados, int id, int limite);
/**
    emp_chequearIndice: Recibe el array para chequear si esta cargado o no.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_chequearIndice(Empleado* pEmpleados,int limite);
/**
    emp_mostrarEmpleadosOrdenados: Muestra los datos ordenados alfabeticamente y por sector de
    todas las posiciones del array.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_mostrarEmpleadosOrdenados(Empleado* pEmpleados,int limite);
/**
    emp_ordenarApellidosYSectores: Recibe el array y lo ordena alfabeticamente y por sector usando
    el metodo de burbujeo mejorado.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_ordenarApellidosYSectores(Empleado* pEmpleados, int limite);
/**
    emp_calcularTotalPromedioSalarios: Recibe el array y realiza las operaciones de los salarios
    pedidas por el ejercicio.
    @param pEmpleado: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int emp_calcularTotalPromedioSalarios(Empleado* pEmpleados, int limite);
#endif // EMPLEADOS_H_INCLUDED
