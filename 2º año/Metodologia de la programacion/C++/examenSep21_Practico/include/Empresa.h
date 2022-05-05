#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include "Empleado.h"
#include "EmpleadoH.h"
#include "EmpleadoV.h"


using namespace std;



class Empresa {
  Empleado **lista;  //el nº máximo de empleados inicial es 3
  int nmax;          //nmax: capacidad de lista
  int n;             //nº elementos en lista
public:
  Empresa() { // constructor
    nmax = 3;  n=0;
    lista = new Empleado*[nmax];
  }

  //A RELLENAR POR EL ALUMNO
  ~Empresa();
  void ver();
  void contratar();
  void eliminarH();
  void duplicar();
};


#endif // EMPRESA_H
