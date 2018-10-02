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

int emp_cargarDatosVacio(Empleado* pEmpleados,int limite);
int emp_cargarIndice(Empleado* pEmpleados,int indice,int limite);
int emp_indicesVacios(Empleado* pEmpleados,int limite,int* indiceVacio);
int emp_buscarPantallaPorID(Empleado* pEmpleados, int limite, int id);
int emp_modificarID(Empleado* pEmpleados, int indice, int limite);
int emp_borrarPantallaPorID(Empleado* pEmpleados, int id, int limite);
int emp_chequearIndice(Empleado* pEmpleados,int limite);
int emp_calcularTotalPromedioSalarios(Empleado* pEmpleados, int limite);
int emp_mostrarEmpleadosOrdenados(Empleado* pEmpleados,int limite);
int emp_ordenarApellidos(Empleado* pEmpleados, int limite);
int emp_ordenarSectores(Empleado* pEmpleados, int limite);

#endif // EMPLEADOS_H_INCLUDED
