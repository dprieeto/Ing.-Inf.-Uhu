#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class merges
{
    int uno[15],dos[15],fus[30];
    int numuno,numdos;
public:
    void cargar();
    void mezclar();
    void ver();
    void verfusion();
};
void merges::cargar()
{
    //los valores tienen que estar metidos en orden creciente para ordenarlos en la tabla
    bool error;
    do
    {
        system("cls");
        cout<<"Introduce el numero de valores a introducir en la primera tabla(1-15): ";cin>>numuno;
    }while(numuno<1||numuno>15);
    for(int i=0;i<numuno;i++)
    {
        do
            {
                cout<<i+1<<".-Introduce un valor para la primera tabla: ";cin>>uno[i];
                if(i!=0&&uno[i]<uno[i-1])
                {
                    //system("cls");
                    cout<<"Los numeros introducidos tienen que estar en orden creciente__";
                    getch();cout<<endl;
                    error=true;
                }
                else
                    error=false;
            }while(error);
    }
    do
    {
        system("cls");
        cout<<"Introduce el numero de valores a introducir en la segunda tabla(1-15): ";cin>>numdos;
    }while(numdos<1||numdos>15);
    for(int i=0;i<numdos;i++)
    {
        do
            {
                cout<<i+1<<".-Introduce un valor para la segunda tabla: ";cin>>dos[i];
                if(i!=0&&dos[i]<dos[i-1])
                {
                    //system("cls");
                    cout<<"Los numeros introducidos tienen que estar en orden creciente"<<endl;
                    getch();cout<<endl;
                    error=true;
                }
                else
                    error=false;
            }while(error);
    }
}
void merges::ver()
{
    cout<<"\tTABLA 1"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<numuno;i++)
    {
        cout<<uno[i];cout<<" ";
    }
    cout<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<"\tTABLA 2"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<numdos;i++)
    {
        cout<<dos[i];cout<<" ";
    }
    cout<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
    system("pause");
    system("cls");
}
void merges::mezclar()
{
    int i,j,k;
    i=j=k=0;
    while(i<numuno||j<numdos)
    {
        if((i!=numuno&&uno[i]<dos[j])||j==numdos)
        {
            fus[k]=uno[i];
            i++;
        }
        else
        {
            fus[k]=dos[j];
            j++;
        }
        k++;
    }
}
void merges::verfusion()
{
    cout<<"\tTABLA FUSIONADA"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<numuno+numdos;i++)
    {
        cout<<fus[i];cout<<" ";
    }
    cout<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
}
int main()
{
    merges m;
    m.cargar();
    m.ver();
    m.mezclar();
    m.verfusion();
    system("pause");
    return 0;
}
