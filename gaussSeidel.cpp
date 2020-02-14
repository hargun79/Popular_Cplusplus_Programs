// To implement Gauss Seidel's method.

#include<bits/stdc++.h>
using namespace std;

#define f1(x,y,z,a1,b1,c1,d1)  (d1-b1*y-c1*z)/a1
#define f2(x,y,z,a2,b2,c2,d2)  (d2-a2*x-c2*z)/b2
#define f3(x,y,z,a3,b3,c3,d3)  (d3-a3*x-b3*y)/c3

int main()
{
 int a1,b1,c1,d1;
 int a2,b2,c2,d2;
 int a3,b3,c3,d3;
 float x0=0,y0=0,z0=0,x1,y1,z1,e1,e2,e3,e;
 int count=1;
 cout<<"Enter precision: \n";
 cin>>e;
 cout<<"Enter coeffecients of first equation: \n";
 cin>>a1>>b1>>c1>>d1;
 cout<<"Enter coeffecients of second equation: \n";
 cin>>a2>>b2>>c2>>d2;
 cout<<"Enter coeffecients of third equation: \n";
 cin>>a3>>b3>>c3>>d3;
 cout<<"Count\t\tx\t\ty\t\tz \n";
 do
 {
  x1=f1(x0,y0,z0,a1,b1,c1,d1);
  y1=f2(x0,y0,z0,a2,b2,c2,d2);
  z1=f3(x0,y0,z0,a3,b3,c3,d3);
  cout<<count<<"\t\t"<<x1<<"\t\t"<<y1<<"\t\t"<<z1<<'\n';
  e1=fabs(x0-x1);
  e2=fabs(y0-y1);
  e3=fabs(z0-z1);
  count++;
  x0=x1;
  y0=y1;
  z0=z1;
 }while(e1>e && e2>e && e3>e);
 cout<<"Solution is: X="<<x1<<" Y="<<y1<<" Z="<<z1<<'\n';
 return 0;
}
