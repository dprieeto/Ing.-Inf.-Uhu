#ifndef EMPLEADOH_H
#define EMPLEADOH_H

#include <Empleado.h>


class EmpleadoH : public Empleado
{
    public:
        EmpleadoH(char *nom,float sueldo,int horas);
        virtual ~EmpleadoH();
        //float nomina(){return this->nomina;}
        const float nominaH(){return (Empleado::nomina()+this->horas*10);}
        void sethoras(int horas){this->horas=horas;}
        void verH(){cout << codEmpleado() << ": " << getNombre() << ", nomina: " << nominaH()<<", Horas: "<<getHoras() ;}
        const int getHoras(){return this->horas;}

    protected:

    private:
        int horas;
        float nomina;
};

#endif // EMPLEADOH_H
