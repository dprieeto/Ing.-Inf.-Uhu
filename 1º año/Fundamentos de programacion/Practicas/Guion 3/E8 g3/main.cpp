#include <iostream>
#include <conio.h>
#include <cstring>
#include <cctype>

#include <string>
#include <vector>

#define ENTER 13
#define BACKSPACE 8

using namespace std;

class palabraoculta
{
    string palabrasecreta;
    int puntos;
public:
    void iniciar();
    //void mayuscula(string &password);
    int jugar();
    void mostarsecreta();
};
/*
void palabraoculta::mayuscula(string &password)
{
    for(int i=0;i<password.length();i++)
    {
        password[i]=toupper(password[i]);
    }
}
void palabraoculta::iniciar()
{
    char caracter;
    //string password;
    cout<<"Introduce la palabra a adivinar: ";
    caracter=getch();
    palabrasecreta="";
    while(caracter!=ENTER)
    {
        if(caracter!=BACKSPACE)
        {
            palabrasecreta.push_back(caracter);
            cout<<"*";
        }
        else
        {
            if(palabrasecreta.length()>0)
            {
                cout<<"\b \b"; //retroceso hacia atras y eliminacion del asterisco
                palabrasecreta=palabrasecreta.substr(0,palabrasecreta.length()-1); //caracter introducido que se va a eliminar
            }
        }
        caracter=getch();
    }
    //cin.get();
    //cout.flush();
    puntos=9;
    mayuscula(palabrasecreta);
}
*/
void palabraoculta::iniciar()
{
    char caracter;
    int i=0;
    puntos=9;
    cout<<"Introduce la palabra a adivinar: ";
    do
    {
        caracter=getch();
        switch(caracter)
        {
        case '\b':
            {
                if(i>0)
                {
                    cout<<"\b \b";
                    i--;
                }
                break;
            }
        case '\r':
            {
                cout<<"\n";
                palabrasecreta[i]='\0'; // \0 (null termination character) marca el final de un string
                break;
            }
        default:
            {
                cout<<"*";
                palabrasecreta[i]=toupper(caracter);
                i++;
            }
        }
    }while(caracter!='\r');
}
int palabraoculta::jugar()
{

    char caracter;
    int longitud,estado=0;//0=nada/1=acerto/2=fallo/3=repitio letra
    do
    {
        caracter=palabrasecreta[longitud];
        longitud++;
    }while(caracter!='\0');
    for(int i=0;i<longitud;i++)
    {
        cout<<"-";
    }
}

int main()
{
    palabraoculta p;
    p.iniciar();
    p.jugar();
    return 0;
}
