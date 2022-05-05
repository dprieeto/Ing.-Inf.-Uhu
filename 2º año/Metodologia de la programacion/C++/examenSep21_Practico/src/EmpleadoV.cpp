#include "EmpleadoV.h"

EmpleadoV::EmpleadoV(char *nom, float sueldo,int ventas) :Empleado(nom,sueldo)
{
    this->ventas=ventas;
}

EmpleadoV::~EmpleadoV()
{
    //dtor
}
