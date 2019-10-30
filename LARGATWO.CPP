//to accept two numbers and display the larger among them .
#include<iostream.h>
#include<conio.h>
void main()
{
float a,b,l,s;
clrscr();
cout<<"Enter two numbers";
cin>>a>>b;
l=(a>b)?a:b;
s=(a<b)?a:b;
cout<<"\n The largest number is:"<<l;
cout<<"\n The smallest number is:"<<s;
getch();
}
