#include <iostream>
#include <stdlib.h>

using namespace std;

class merges
{
    int uno[15],dos[15],tres[30];
    int n1,n2;
public:
    void cargar();
    void ver();
    void mezclar();
    void verfus();
};
void merges::cargar()
{
    do
    {
        cout<<"Introduce el numero de elementos que quieres poner en la primera tabla: ";cin>>n1;
    }while(n1<1||n1>15);
    for(int i=0;i<n1;i++)
    {
        cout<<i+1<<".-Introduce un valor para la primera tabla: ";cin>>uno[i];
    }system("pause");system("cls");
    do
    {
        cout<<"Introduce el numero de elementos que quieres poner en la segunda tabla: ";cin>>n2;
    }while(n2<1||n2>15);
    for(int i=0;i<n2;i++)
    {
        cout<<i+1<<".-Introduce un valor para la segunda tabla: ";cin>>dos[i];
    }system("pause");system("cls");
}
void merges::ver()
{
    cout<<"TABLA 1"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<n1;i++)
    {
        cout<<uno[i];cout<<" ";
    }
    cout<<endl<<"----------------------------------------------------------------------------------"<<endl<<endl<<endl;
    cout<<"TABLA 2"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<n2;i++)
    {
        cout<<dos[i];cout<<" ";
    }
    cout<<endl<<"----------------------------------------------------------------------------------"<<endl<<endl;
    system("pause");
}
void merges::mezclar()
{
    for(int i=0;i<n1;i++)
    {
        tres[i]=uno[i];
    }
    for(int i=n1;i<(n1+n2);i++)
    {
        tres[i]=dos[i-(n1)];
    }
}
void merges::verfus()
{
    system("cls");
    cout<<"TABLA FUSIONADA"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<(n1+n2);i++)
    {
        cout<<tres[i];cout<<" ";
    }
    cout<<endl<<"----------------------------------------------------------------------------------"<<endl;
    system("pause");
}
int main()
{
    merges m;
    m.cargar();
    m.ver();
    m.mezclar();
    m.verfus();
    return 0;
}
