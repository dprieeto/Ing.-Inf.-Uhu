#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

   int main()
{
  float x1,x2,a,b,c,d;
  cout<<"Dada una ecuacion de segundo grado 'ax^2+bx+c=0'.Introduce:\n";
    cout<<"El valor de a: ";cin>>a;
    cout<<"El valor de b: ";cin>>b;
    cout<<"El valor de c: ";cin>>c;
   d=sqrt((b*b)-4*a*c);
   if (d==0)
   {x1=((-b)/(2*a));
    cout<<"\nLa ecuacion tiene una solucion doble: "<<x1;}
    else if (d>0){
        x1=((-b+d)/(2*a));
        x2=((-b-d)/(2*a));
        cout<<"\nLas soluciones a la ecuacion son '"<<x1<<"' y '"<<x2<<"'.";}
  else
     cout<<"\nLa ecuacion no tiene soluciones reales.";

}

