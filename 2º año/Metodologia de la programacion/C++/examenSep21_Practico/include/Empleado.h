#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <typeinfo>

using namespace std;

class Empleado {
   int cod_empleado;
  char *nombre;
  float sueldo;
  static int contador;//incializado en 1 para que vaya incrementado en 1 cada empleado creado para que tenga un codigo distinto
public:
  Empleado (char *nom, float sueldo); // constructor
  ~ Empleado (); // destructor
  const char *getNombre() const { return nombre; }
  float nomina() const { return sueldo; }
  int codEmpleado () const { return cod_empleado; }
  float getSueldo() const { return sueldo; }
  void ver() const { cout << cod_empleado << ": " << nombre << ", nomina: " << nomina(); }
  //virtual void metodo() const=0; //para que sea abstracto debe tenert un metodo virtual puro
  virtual void nempleados();//para ser polimorfico debe tener al menos un metodo virtual

};

#endif // EMPLEADO_H
