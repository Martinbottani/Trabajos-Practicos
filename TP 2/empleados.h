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

int altaForzada(Empleado* empleados, int limite,char* nombre,int sector, char* apellido, float salario);
int cargarDatosVacio(Empleado* empleados,int limite);
int cargarIndice(Empleado* empleados,int indice,int limite);
int indicesVacios(Empleado* empleados,int limite,int* indiceVacio);
int buscarPantallaPorID(Empleado* empleados, int limite, int id);
int modificarID(Empleado* empleados, int indice, int limite);
int borrarPantallaPorID(Empleado* empleados, int id, int limite);
int chequearIndice(Empleado* empleados,int limite);
int calcularTotalPromedioSalarios(Empleado* empleados, int limite);


#endif // EMPLEADOS_H_INCLUDED
