#include <iostream>
#include <windows.h>
#include <string.h>
#include "Autobus.h"
#include "Itinerario.h"

using namespace std;

void listarhorario();

char menu()
{
    char opc;
    cout << "\t\t----- Menu principal -----" << endl;
    cout << "1.- Gestion de autobuses." << endl;
    cout << "2.- Gestion de Itinerarios." << endl;
    cout << "3.- Listar itinerarios segun franja horaria." << endl;
    cout << "4.- Salir." << endl;
    cin >> opc;

    return opc;
}

char menubus()
{
    char opc1;
    cout << "----- Gestion de autobuses -----" << endl;
    cout << "a) Insertar." << endl;
    cout << "b) Borrar." << endl;
    cout << "c) Modificar." << endl;
    cout << "d) Buscar." << endl;
    cout << "e) Listar." << endl;
    cout << "f) Cargar autobuses desde fichero." << endl;
    cout << "g) Guardar autobuses en fichero." << endl;
    cout << "v) Volver." << endl;
    cin >> opc1;

    return opc1;
}

char menuitinerario()
{
    char opc2;
    cout << "----- Gestion de itinerario -----" << endl;
    cout << "a) Insertar." << endl;
    cout << "b) Borrar." << endl;
    cout << "c) Modificar." << endl;
    cout << "d) Buscar." << endl;
    cout << "e) Listar." << endl;
    cout << "f) Cargar itinerario desde fichero." << endl;
    cout << "g) Guardar itinerario en fichero." << endl;
    cout << "v) Volver." << endl;
    cin >> opc2;

    return opc2;
}

int main()
{
    //AUTOBUS
    autobuses ab;
    autobus a;
    cadena respuestaactivo, respuestaitv, mat;
    char respuesta;
    //ITINERARIO
    int horaini, horaini2, horaini3, horafin, horafin2, horafin3;
    itinerarios its;
    itinerario i;
    char respuestainiam, respuestafinam;
    cadena nombre;
    //MENUS
    char opc, opc1, opc2;

    int pos;
    fstream fichero;
    do
    {
        opc=menu();
        switch(opc)
        {
        case '1':
            do
            {
                opc1=menubus();
                //system("cls");
                switch (opc1)
                {
                case 'a':
                    cout << "Matricula: " << endl;
                    cin >> a.matricula;
                    cout << "Plazas ocupadas: " << endl;
                    cin >> a.e.plazas;
                    cout << "Activo (s/n): " << endl;
                    cin >> respuestaactivo;
                    if(strcmp(respuestaactivo, "s")==0)
                    {
                        a.e.activo = true;
                    }else
                        a.e.activo = false;
                    cout << "Deposito: " << endl;
                    cin >> a.e.deposito;
                    cout << "Itv (s/n): "<< endl;
                    cin >> respuestaitv;
                    if(strcmp(respuestaitv, "s")==0)
                    {
                        a.e.itv = true;
                    }else
                        a.e.itv = false;
                    cout << "Numero del conductor: " << endl;
                    cin >> a.conductor;

                    ab.Insertar(a);
                    break;
                case 'b':
                do
                {
                    cout << "Desea borrar por matricula o por posicion (m/p): " << endl;
                    cin >> respuesta;
                }while(respuesta != 'm' && respuesta != 'M' && respuesta != 'p' && respuesta != 'P');

                    switch (respuesta)
                    {
                    case 'M':
                    case 'm':
                        cout << "Introduce la matricula que desea borrar: " << endl;
                        cin >> mat;
                        ab.Borrar(mat, -1);
                        break;
                    case 'P':
                    case 'p':
                        cout << "Introduce la posicion que desea borrar: " << endl;
                        cin >> pos;
                        ab.Borrar("XXXXXXXXXXXXXXX",pos);
                        break;
                    }
                    break;
                case 'c':
                do
                {
                    cout << "Desea modificar a traves de posicion o de matricula (p/m)" << endl;
                    cin >> respuesta;
                }while(respuesta != 'p' && respuesta != 'P' && respuesta != 'm' && respuesta != 'M');

                    switch(respuesta)
                    {
                    case 'P':
                    case 'p':
                        cout << "Introduce la posicion del autobus: " << endl;
                        cin >> pos;
                        cout << "Matricula: " << endl;
                        cin >> a.matricula;
                        cout << "Plazas ocupadas: " << endl;
                        cin >> a.e.plazas;
                        cout << "Activo (s/n): " << endl;
                        cin >> respuestaactivo;
                        if(strcmp(respuestaactivo, "s")==0)
                        {
                            a.e.activo = true;
                        }else
                            a.e.activo = false;
                        cout << "Deposito: " << endl;
                        cin >> a.e.deposito;
                        cout << "Itv (s/n): "<< endl;
                        cin >> respuestaitv;
                        if(strcmp(respuestaitv, "s")==0)
                        {
                            a.e.itv = true;
                        }else
                            a.e.itv = false;
                        cout << "Numero del conductor: " << endl;
                        cin >> a.conductor;
                        ab.Modificar(a, "-100000", pos);
                        break;
                    case 'M':
                    case 'm':
                        cout << "Introduce la matricula que desea modificar: " << endl;
                        cin >> mat;
                        cout << "Matricula: " << endl;
                        cin >> a.matricula;
                        cout << "Plazas ocupadas: " << endl;
                        cin >> a.e.plazas;
                        cout << "Activo (s/n): " << endl;
                        cin >> respuestaactivo;
                        if(strcmp(respuestaactivo, "s")==0)
                        {
                            a.e.activo = true;
                        }else
                            a.e.activo = false;
                        cout << "Deposito: " << endl;
                        cin >> a.e.deposito;
                        cout << "Itv (s/n): "<< endl;
                        cin >> respuestaitv;
                        if(strcmp(respuestaitv, "s")==0)
                        {
                            a.e.itv = true;
                        }else
                            a.e.itv = false;
                        cout << "Numero del conductor: " << endl;
                        cin >> a.conductor;

                        ab.Modificar(a, mat, -1);
                        break;
                    }
                    break;
                case 'd':

                    cout << "Introduce la matricula a buscar: " << endl;
                    cin >> a.matricula;
                    ab.Buscar(a.matricula);
                    break;
                case 'e':
                    ab.Listar();
                    break;
                case 'f':
                    ab.Cargar();
                    break;
                case 'g':
                    ab.Guardar();
                    break;
                case 'v':
                    break;
                }
            }while(opc1 != 'v');
            break;
        case '2':
            do
            {
                opc2=menuitinerario();
                switch (opc2)
                {
                case 'a':
                    cout << "Nombre del itinerario: " << endl;
                    cin >> i.nombre;
                    cout << "Origen: " << endl;
                    cin >> i.origen;
                    cout << "Destino: " << endl;
                    cin >> i.destino;
                    cout << "Hora de salida (1ºHoras 2ºMinutos): " << endl;
                    cin >> i.inicio.h >> i.inicio.m;
                do
                {
                    cout << "AM (s/n): " << endl;
                    cin >> respuestainiam;
                }while(respuestainiam!='s'&& respuestainiam !='S' && respuestainiam !='n'&& respuestainiam !='N');

                    switch(respuestainiam)
                    {
                    case 's':
                    case 'S':
                        i.inicio.am=true;
                        break;
                    case 'n':
                    case 'N':
                        i.inicio.am=false;
                        break;
                    }
                    cout << "Hora de llegada (1ºHoras 2ºMinutos):" << endl;
                    cin >>i.fin.h >> i.fin.m;
                do
                {
                    cout << "AM (s/n): " << endl;
                    cin >> respuestafinam;
                }while(respuestafinam!='s'&& respuestafinam !='S' && respuestafinam !='n'&& respuestafinam !='N');

                    switch(respuestafinam)
                    {
                    case 's':
                    case 'S':
                        i.fin.am=true;
                        break;
                    case 'n':
                    case 'N':
                        i.fin.am=false;
                        break;
                    }
                    cout << "Matricula autobus: " << endl;
                    cin >> i.matricula;

                    its.Insertar(i);
                    break;
                case 'b':
                do
                {
                    cout << "Desea eliminar por nombre e itinerario o por posicion (n/p): " << endl;
                    cin >> respuesta;
                }while(respuesta != 'n' && respuesta != 'N' && respuesta != 'p' && respuesta != 'P');

                    switch(respuesta)
                    {
                    case 'N':
                    case 'n':
                        cout << "Introduce el nombre: " << endl;
                        cin >> nombre;
                        cout << "Introduce la matricula: " << endl;
                        cin >> mat;

                        its.Borrar(nombre, mat, -1);
                        break;
                    case 'P':
                    case 'p':
                        cout << "Introduce la posicion que desea borrar: " << endl;
                        cin >> pos;

                        its.Borrar("NOMBRENODADO", "MATRICULANODADA", pos);
                        break;
                    }
                }
                    break;
                case 'c':
                do
                {
                    cout << "Desea modificar por nombre(y matricula) o por posicion(n/p): " << endl;
                    cin >> respuesta;
                }while(respuesta != 'n' && respuesta != 'N' && respuesta != 'p' && respuesta != 'P');

                    switch(respuesta)
                    {
                    case 'N':
                    case 'n':
                        cout << "Introduce el nombre: " << endl;
                        cin >> nombre;
                        cout << "Introduce la matricula: " << endl;
                        cin >> mat;

                        cout << "\n\nIntroduce los nuevos datos: " << endl;
                        cout << "Nombre del itinerario: " << endl;
                        cin >> i.nombre;
                        cout << "Origen: " << endl;
                        cin >> i.origen;
                        cout << "Destino: " << endl;
                        cin >> i.destino;
                        cout << "Hora de salida (1ºHoras 2ºMinutos): " << endl;
                        cin >> i.inicio.h >> i.inicio.m;
                    do
                    {
                        cout << "AM (s/n): " << endl;
                        cin >> respuestainiam;
                    }while(respuestainiam!='s'&& respuestainiam !='S' && respuestainiam !='n'&& respuestainiam !='N');

                        switch(respuestainiam)
                        {
                        case 's':
                        case 'S':
                            i.inicio.am=true;
                            break;
                        case 'n':
                        case 'N':
                            i.inicio.am=false;
                            break;
                        }
                        cout << "Hora de llegada (1ºHoras 2ºMinutos):" << endl;
                        cin >>i.fin.h >> i.fin.m;
                    do
                    {
                        cout << "AM (s/n): " << endl;
                        cin >> respuestafinam;
                    }while(respuestafinam!='s'&& respuestafinam !='S' && respuestafinam !='n'&& respuestafinam !='N');
                        switch(respuestafinam)
                        {
                        case 's':
                        case 'S':
                            i.fin.am=true;
                            break;
                        case 'n':
                        case 'N':
                            i.fin.am=false;
                            break;
                        }

                        its.Modificar(i, nombre, mat, -1);
                        break;
                    case 'P':
                    case 'p':
                        cout << "Introdue la posicion: " << endl;
                        cin >> pos;

                         cout << "\n\nIntroduce los nuevos datos: " << endl;
                        cout << "Nombre del itinerario: " << endl;
                        cin >> i.nombre;
                        cout << "Origen: " << endl;
                        cin >> i.origen;
                        cout << "Destino: " << endl;
                        cin >> i.destino;
                        cout << "Hora de salida (1ºHoras 2ºMinutos): " << endl;
                        cin >> i.inicio.h >> i.inicio.m;
                        cout << "AM (s/n): " << endl;
                        cin >> respuestainiam;
                    do
                    {
                        cout << "AM (s/n): " << endl;
                        cin >> respuestainiam;
                    }while(respuestainiam!='s'&& respuestainiam !='S' && respuestainiam !='n'&& respuestainiam !='N');
                        switch(respuestainiam)
                        {
                        case 's':
                        case 'S':
                            i.inicio.am=true;
                            break;
                        case 'n':
                        case 'N':
                            i.inicio.am=false;
                            break;
                        }
                        cout << "Hora de llegada (1ºHoras 2ºMinutos):" << endl;
                        cin >>i.fin.h >> i.fin.m;
                        do
                        {
                            cout << "AM (s/n): " << endl;
                            cin >> respuestafinam;
                        }while(respuestafinam!='s'&& respuestafinam !='S' && respuestafinam !='n'&& respuestafinam !='N');

                            switch(respuestafinam)
                            {
                            case 's':
                            case 'S':
                                i.fin.am=true;
                                break;
                            case 'n':
                            case 'N':
                                i.fin.am=false;
                                break;
                            }
                            its.Modificar(i, "NOPIDENINGUNNOMBRE", "NOEXSITEESTAMARICULA", pos);
                            break;
                        }
                        break;
                    case 'd':
                        cout << "Introduce el nombre: " << endl;
                        cin >> nombre;
                        cout << "Introduce la matricula: " << endl;
                        cin >> mat;

                        its.Buscar(nombre, mat);
                        break;
                    case 'e':
                        its.Listar();
                        break;
                    case 'f':
                        its.Cargar();
                        break;
                    case 'g':
                        break;
                    case 'v':
                        break;
                }while(opc2 != 'v');
                break;
            case '3':
                cout << "Introduce la hora unicamente de inicio: " << endl;
                cin >> horaini;
                cout << "Introduce los minutos unicamente de inicio: " << endl;
                cin >> horaini2;
            do
            {
                cout << "Elige AM o PM para la hora de inicio (a/p): " << endl;
                cin >>respuestainiam;
            }while(respuestainiam!='a' && respuestainiam!= 'A' && respuestainiam != 'p' && respuestainiam != 'P');
            switch(respuestainiam)
            {
            case 'a':
            case 'A':
                horaini3=horaini*60+horaini2;
                break;
            case 'p':
            case 'P':
                horaini3=(horaini+12)*60+horaini2;
                break;
            }

                cout << "Introduce la hora unicamente de fin: " << endl;
                cin >> horafin;
                cout << "Introduce los minutos unicamente de fin: " << endl;
                cin >> horafin2;
            do
            {
                cout << "Elige AM o PM para la hora de fin (a/p): " << endl;
                cin >>respuestafinam;
            }while(respuestafinam!='a' && respuestafinam!= 'A' && respuestafinam != 'p' && respuestafinam != 'P');
            switch(respuestainiam)
            {
            case 'a':
            case 'A':
                horafin3=horafin*60+horafin2;
                break;
            case 'p':
            case 'P':
                horafin3=(horafin+12)*60+horafin2;
                break;
            }

            its.itinerariosenintervalo(horaini3, horafin3);
            break;
        case '4':
            break;
        }
    }while(opc!='4');
    return 0;
}
