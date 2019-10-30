//to show the GCD and LCM.
#include<iostream.h>
#include<conio.h>
void main()
{
int a,b,dd,dv,r,gcd,lcm;
clrscr();
cout<<"Enter two numbers\n";
cin>>a>>b;
if(a>b)
{dd=a; dv=b;}
else
{dd=b; dv=a;}
do
{
r=dd%dv;
if(r==0)
break;
dd=dv;
dv=r;
}
while(1);
gcd=dv;
lcm=(a*b)/gcd;
cout<<"The GCD is:"<<gcd;
cout<<"\nThe LCM is:"<<lcm;
getch();
}
