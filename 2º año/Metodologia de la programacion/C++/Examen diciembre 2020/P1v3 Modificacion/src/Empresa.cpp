#include <typeinfo>
#include <cstdio>
#include "Empresa.h"

using namespace std;

Empresa::Empresa(): nmaxcli(100)
{
    this->ncli=0;
    this->ncon=0;
    this->nmaxcon=10;
    contratos=new Contrato*[10];
}

Empresa::~Empresa()
{
    for(int i=0; i<ncli; i++)
        delete clientes[i];
    for(int i=0; i<ncon; i++)
        delete contratos[i];
    delete [] contratos;
}

int Empresa::buscarCliente(long int dni)
{
    bool existe=false;
    int i=0, pos=-1;

    while(i<ncli && !existe)
    {
        if(clientes[i]->getDni()==dni)
        {
            existe=true;
            pos=i;
        }else
        i++;
    }
    return pos;
}

int Empresa::altaCliente(Cliente *c)
{
    int pos=-1;
    if(ncli<nmaxcli)
    {
        pos=ncli;
        clientes[ncli++]=c;
    }

    return pos;
}

void Empresa::cargarDatos()
{
Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002), f4(1,1,2017);
    this->clientes[0] = new Cliente(75547001, "Peter Lee", f1);
    this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
    this->clientes[2] = new Cliente(37000017, "Luis Bono", f2);
    //this->clientes[3] = new Cliente(22330014, "pepe luis", Fecha(2,2,2017));///CLIENTE AÑADIDO PARA AGILIZAR EL PROGRAMA
    this->ncli=3;
    this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
    this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
    this->contratos[2] = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
    this->contratos[3] = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
    this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10/m
    this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
    this->contratos[6] = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
    //this->contratos[7] = new ContratoMovil(37000017, f3, 0.25, 100, "aleman"); ///CONTRATO AÑADIDO PARA AGILIZAR EL PROGRAMA
   // this->contratos[8] = new ContratoTP(22330014, Fecha(2,2,2017), 305); ///CONTRATO AÑADIDO PARA AGILIZAR EL PROGRAMA
    this->ncon=7;
}

void Empresa::ver() const ///REPASAR OTRA VEZ
{
    cout << "\nLa empresa tiene " << ncli << " clientes y " << ncon << " contratos";
    cout << "\nClientes:" << endl;
    for(int i = 0; i<ncli; i++)
        cout << *clientes[i] << endl;

    cout << "\nContratos:" << endl;
    for(int i = 0; i<ncon; i++)
    {
        if(typeid(*contratos[i]) == typeid (ContratoTP))
            cout << (*(ContratoTP*)contratos[i]) << endl; //Muestra el contenido del puntero ContratoTP que apunta a contratos[i]
        else if(typeid(*contratos[i]) == typeid (ContratoMovil))
            cout << (*(ContratoMovil*)contratos[i]) << endl; //Muestra el contenido del puntero ContratoTP que apunta a contratos[i]
    }
}

int Empresa::nContratosTP() const
{
    int contador=0;
    for(int i=0; i<ncon; i++)
    {
        if(typeid(*contratos[i])==typeid(ContratoTP))
            contador++;
    }

    return contador;
}

int Empresa::descuento(float porcentaje) const ///REPASAR OTRA VEZ
{
    int contador=0;
    porcentaje=1-(porcentaje/100);

    for(int i=0; i<ncon; i++)
    {
        if(ContratoMovil *c = dynamic_cast<ContratoMovil*>(contratos[i]))
        {
            c->setPrecioMinuto(c->getPrecioMinuto()*porcentaje);
            contador++;
        }
    }
    return contador;
}

int Empresa::altaContrato(Contrato *c)
{
    int pos=-1;
    if(ncon == nmaxcon) //Se aumenta el tamaño al doble
    {
        nmaxcon*=2;
        Contrato **tmp= new Contrato*[nmaxcon];
        for(int i=0; i<ncon; i++)
            tmp[i]=contratos[i];

        delete [] contratos;
        contratos=tmp;
        delete [] tmp;
    }

    if(ncon<nmaxcon)
    {
        pos=ncon;
        contratos[ncon++]=c;
    }

    return pos;
}

void Empresa::crearContrato()
{
    long int dni;
    int existe;
    cout << "\nIntroduzca dni: "; cin >>dni;
    existe=buscarCliente(dni);
    if(existe==-1) //El cliente no existe, hay que darlo de alta.
    {
        char nom[30];
        cout << "Nombre del cliente: "; cin.ignore(); cin.getline(nom, 30);
        int dia, mes, anio;
        cout << "dia: "; cin >> dia;
        cout << "mes: "; cin >> mes;
        cout << "anio: "; cin >> anio;
        Cliente *c;
        c=new Cliente(dni, nom, Fecha(dia, mes, anio));
        existe=altaCliente(c);

        if(existe==-1) //Devuelve -1 si no lo ha creado y la posicion de donde ha sido creado.
            delete c;
    }

    if(existe!=-1) //El cliente existe
    {
        int tipoContrato;

        cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): "; cin >> tipoContrato;
        if(tipoContrato==1)
        {
            int dia, mes, anio;
            cout << "Fecha del contrato: ";
            cout << "\ndia: "; cin >> dia;
            cout << "mes: "; cin >> mes;
            cout << "anio: "; cin >> anio;
            int minutoshablados;
            cout << "Minutos hablados: "; cin >> minutoshablados;
            ContratoTP *c;
            c=new ContratoTP(dni, Fecha(dia, mes, anio), minutoshablados);
            altaContrato(c);
        }else if(tipoContrato==2)
        {
            int dia, mes, anio;
            cout << "Fecha del contrato: ";
            cout << "\ndia: "; cin >> dia;
            cout << "mes: "; cin >> mes;
            cout << "anio: "; cin >> anio;
            int minutoshablados;
            cout << "Minutos hablados: "; cin >> minutoshablados;
            float preciominuto;
            cout << "Precio minuto: "; cin >> preciominuto;
            char nac[30];
            cout << "Nacionalidad: "; cin >> nac;
            ContratoMovil *c;
            c=new ContratoMovil(dni, Fecha(dia, mes, anio), preciominuto, minutoshablados, nac);
            altaContrato(c);

        }else
            cout << "Contrato erróneo. Operación cancelada." << endl;
    }
}

bool Empresa::cancelarContrato(int idContrato)
{
    bool existe=false;
    int i=0, pos;
    ///Se busca el contrato
    while(i<ncon && !existe)
    {
        if(contratos[i]->getIdContrato()==idContrato) //Existe.
        {
            existe=true;
        }else
            i++;
    }
    if(existe)
    {
        while(i<ncon-1)
        {
            contratos[i]=contratos[i+1]; //++i
            i++;
        }

        ncon--;
    }

    return existe;
}

bool Empresa::bajaCliente(long int dni)
{
    bool baja=false;
    int pos=buscarCliente(dni);
    if(pos!=-1)
    {
        for(int i=0; i<ncon; i++)
        {
            if(contratos[i]->getDniContrato()==dni)
            {
                cancelarContrato(contratos[i]->getIdContrato());
                i--; //cancelar Contrato elimina un contrato, y asigna a la posicion que se elimina el contrato siguiente.
                     //Hay que disminuir tambien la i para recorrer toda la tabla. Ej: Elimina posicion 2 y la posicion 2
                     //contiene ahora lo que deberia de haber en la posicion 3. Si no hacemos i--, saltaria la nueva posición.
            }
        }

        while(pos<ncli)
        {
            clientes[pos]=clientes[pos+1];
            pos++;
        }
        ncli--;
        baja=true;

    }else
        cout << "El cliente no existe." << endl;

    return baja;
}

//1A) PRIMERO HAY Q CALCULAR LA FACTURA MEDIA DE LOS CONTRATOSTP
//PREGUNTA 1B PASAR CHQR POR PARAMETRO
//1C LOS METODOS SON ESTATICOS
