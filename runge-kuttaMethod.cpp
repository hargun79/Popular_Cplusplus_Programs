// To implement Runge-Kutta method.

#include<bits/stdc++.h>
using namespace std;

#define f(x,y) (y*y-x*x)/(y*y+x*x)

int main()
{
 float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
 int i, n;
 cout<<"Enter initial condition: \n";
 cin>>x0;
 cin>>y0;
 cout<<"Enter calculation point: \n";
 cin>>xn;
 cout<<"Enter number of steps: \n";
 cin>>n;
 h=(xn-x0)/n;
 for(i=0;i<n;i++)
 {
  k1=h*(f(x0,y0));
  k2=h*(f((x0+h/2),(y0+k1/2)));
  k3=h*(f((x0+h/2),(y0+k2/2)));
  k4=h*(f((x0+h),(y0+k3)));
  k=(k1+2*k2+2*k3+k4)/6;
  yn=y0+k;
  x0=x0+h;
  y0=yn;
 }
 cout<<"Value of y at x = "<< xn<< " is " << yn<<'\n';
 return 0;
}
