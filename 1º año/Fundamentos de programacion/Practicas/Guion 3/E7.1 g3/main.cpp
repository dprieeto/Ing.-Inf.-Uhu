#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class merges
{
    int numuno,numdos;
    int uno[15],dos[15],tres[30];
public:
    void cargar();
    void mezclar();
    void ver();
    void verfusion();
};
void merges::cargar()
{
    do
    {
        system("cls");
        cout<<"Introduce cuantos valores quieres meter en la primera tabla(1-15): ";cin>>numuno;
    }while(numuno<1||numuno>15);
    for(int i=0;i<numuno;i++)
    {
        cout<<i+1<<".-Introduce un valor para la primera tabla: ";cin>>uno[i];
    }
    getch();system("cls");
    do
    {
        system("cls");
        cout<<"Introduce cuantos valores quieres meter a la segunda tabla: ";cin>>numdos;
    }while(numdos<1||numdos>15);
    for(int i=0;i<numdos;i++)
    {
        cout<<i+1<<".-Introduce un valor para la segunda tabla: ";cin>>dos[i];
    }
    getch();system("cls");
}
void merges::ver()
{
    cout<<"\tTABLA 1"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<numuno;i++)
    {
        cout<<uno[i];cout<<" ";
    }
    cout<<endl<<"------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<"\tTABLA 2"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<numdos;i++)
    {
        cout<<dos[i];cout<<" ";
    }
    cout<<endl<<"------------------------------------------------------------------------------"<<endl;
    system("pause");system("cls");
}
void merges::mezclar()
{
    //tiene que ser con while y los numeros de las dos tablas introducidos en orden en la fusion en orden creciente
    int i,j,k;
    i=j=k=0;
   	while(i < numuno || j < numdos){
		if((i != numuno && uno[i] < dos[j]) || j == numdos){
			tres[k] = uno[i];
			i++;
		}else{
			tres[k] = dos[j];
			j++;
		}
		k++;
	}
   /*
    while(i<numuno&&j<numdos)
    {
    if(uno[i]<dos[j])
    {
        tres[i]=uno[i];
    }
        else if(uno[i]>dos[j])
    {
    tres[k]=dos[j];
    j++;
    }
    else
    {
    tres[k]=uno[i];
    i++;
    }
    k++;
    }
    if(i<numuno)
    {
        while(i<numuno)
            tres[k]=uno[i];
            i++;k++;
    }
    else
        while(j<numuno)
            tres[k]=dos[j];
            j++;k++;*/
    /*
    for(int i=0;i<numuno;i++)
    {
        tres[i]=uno[i];
    }
    for(int i=numuno;i<numdos+numuno;i++)
    {
        tres[i]=dos[i-numuno];
    }
    */
}
void merges::verfusion()
{
    cout<<"\tTABLA FUSIONADA"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<numdos+numuno;i++)
    {
        cout<<tres[i];cout<<" ";
    }
    cout<<endl<<"------------------------------------------------------------------------------"<<endl;
    system("pause");system("cls");
}
int main()
{
    merges m;
    m.cargar();
    m.ver();
    m.mezclar();
    m.verfusion();
    return 0;
}
