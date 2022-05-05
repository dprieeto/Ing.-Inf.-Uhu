#include <iostream>

using namespace std;
class campo{
    double q,qt,rt,r;
    public:
        void leer();
        double intensidad();
};
void campo::leer(){
    cout<<"\tAntes de introducir los datos, tienes que elegir primero las unidades de dichos datos:\n\n";
    int mq,mr;

    {
        cout<<"\t\t\t\t\tUnidades de la carga:\n";
        cout<<"\t\t\t\t\t\t1.Miliculombios(mC).\n";
        cout<<"\t\t\t\t\t\t2.Microculonbios(uC).\n";
        cout<<"\t\t\t\t\t\t3.Nanoculombios(nC).\n";
        cout<<"\n\t\t\t\t\tElige una opcion: ";cin>>mq;
        switch (mq)
            {
            case 1:
                {
                float mc;
                mc=1e-3;
                qt=q*mc;
                cout<<"\t\t\t\t\t\tIntroduce su valor: ";cin>>q;
                break;
                }
            case 2:
                {
                float uc;
                uc=1e-6;
                qt=q*uc;
                cout<<"\t\t\t\t\t\tIntroduce su valor: ";cin>>q;
                break;
                }
            case 3:
                {
                float nc;
                nc=1e-9;
                qt=q*nc;
                cout<<"\t\t\t\t\t\tIntroduce su valor: ";cin>>q;
                break;
                }
            default: cout<<"\t\t\tOpcion invalida.Introduce el valor de la carga(Se tomara como unidad el microculombio): ";cin>>qt;
            }
    }

        {
            cout<<"\n\t\t\t\t\tUnidades de la distancia:\n";
            cout<<"\t\t\t\t\t\t1.Decimetros(dm).\n";
            cout<<"\t\t\t\t\t\t2.Centimetros(cm).\n";
            cout<<"\t\t\t\t\t\t3.Milimetros(mm).\n";
            cout<<"\n\t\t\t\t\tElige una opcion: ";cin>>mr;
            switch (mr)
            {
            case 1:
                {
                float dm;
                dm=1e-1;
                rt=q*dm;
                cout<<"\t\t\t\t\t\tIntroduce su valor: ";cin>>r;
                break;
                }
            case 2:
                {
                float cm;
                cm=1e-2;
                rt=q*cm;
                cout<<"\t\t\t\t\t\tIntroduce su valor: ";cin>>r;
                break;
                }
            case 3:
                {
                float mm;
                mm=1e-3;
                qt=q*mm;
                cout<<"\t\t\t\t\t\tIntroduce su valor: ";cin>>r;
                break;
                }
            default: cout<<"\t\t\tOpcion invalida.Introduce el valor de la distancia(Se tomara como unidad el metro): ";cin>>rt;
            }
        }
    }

double campo::intensidad(){
    double E,ep,pi;
    pi=3.141592;
    ep=8.85e-12;
    E=((qt)/(4*pi*ep*rt*rt));
    return E;
}
int main()
{
    campo ob;
    ob.leer();
    cout<<"La intensidad del campo electrico es de : "<<ob.intensidad()<<" N/C.";
}

