// To implement Euler's method.

#include<bits/stdc++.h>
using namespace std;

#define f(x,y) x+y

int main()
{
 float x0,y0,xn,h,yn,slope;
 int i,n;
 cout<<"Enter initial condition :\n";
 cin>>x0;
 cin>>y0;
 cout<<"Enter calculation point: \n";
 cin>>xn;
 cout<<"Enter number of steps: \n";
 cin>>n;
 h=(xn-x0)/n;
 for(i=0;i<n;i++)
 {
  slope=f(x0,y0);
  yn=y0+h*slope;
  y0 = yn;
  x0 = x0+h;
 }
 cout<<"Value of y at x = "<<xn<<" is "<<yn;
 return 0;
}
