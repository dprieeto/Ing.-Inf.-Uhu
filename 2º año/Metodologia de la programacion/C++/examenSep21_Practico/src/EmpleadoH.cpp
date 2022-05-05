#include "EmpleadoH.h"

EmpleadoH::EmpleadoH(char *nom, float sueldo, int horas) :Empleado(nom,sueldo)
{
    this->horas=horas;
}

EmpleadoH::~EmpleadoH()
{
    //dtor
     //ya se encarga de borrar el nombre el destructor padre
}
