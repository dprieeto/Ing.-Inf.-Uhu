#include "Empleado.h"

/// EJERCICIO 1
 int Empleado::contador=1;
Empleado::Empleado(char *nom,float sueldo)
{
    //cod_empleado=0;
    this->cod_empleado=contador;
    Empleado::contador++;

    delete [] this->nombre;
    this->nombre=new char[strlen(nom)+1];
    strcpy(this->nombre,nom);
    if(sueldo<900)
        this->sueldo=900;
    else
        this->sueldo=sueldo;


}

Empleado::~Empleado()
{
    delete [] this->nombre;
}
