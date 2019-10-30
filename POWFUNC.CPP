//to calculate a number to some power without using math.h .
#include<iostream.h>
#include<conio.h>
void main()
{
float a,p=1;
int b;
clrscr();
cout<<"Enter the base ";
cin>>a;
cout<<"Enter the exponent";
cin>>b;
for(int  i=1; i<=b; i++)
p=p*a;
cout<<"The result is \t"<<p;
getch();
}