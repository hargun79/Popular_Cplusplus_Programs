//to calculate the area of a triangle.
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
float a,b,c,s,A;
clrscr();
cout<<"\n Enter the three sides";
cin>>a>>b>>c;
s=(a+b+c)/2;
A=sqrt(s*(s-a)*(s-b)*(s-c));
cout<<"\n The area of a triangle:"<<A;
getch();
}