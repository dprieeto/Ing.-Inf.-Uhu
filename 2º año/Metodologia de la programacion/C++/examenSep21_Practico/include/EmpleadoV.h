#ifndef EMPLEADOV_H
#define EMPLEADOV_H

#include <Empleado.h>


class EmpleadoV : public Empleado
{
    public:
        EmpleadoV(char *nom,float sueldo, int ventas);
        virtual ~EmpleadoV();
        const float nominaV(){return (Empleado::nomina()+this->ventas*0.05);}
        void ver(){cout << codEmpleado() << ": " << getNombre() << ", nomina: " << nominaV()<<", Ventas: "<<getVentas() ;}
        void setventas(int ventas){this->ventas=ventas;}
        const int getVentas(){return this->ventas;}
    protected:

    private:
        int ventas;
};

#endif // EMPLEADOV_H
