//to calculate the factorial of a given number .
#include<iostream.h>
#include<conio.h>
void main()
{
int no;
unsigned long f=1;
clrscr();
cout<<"Enter a number ";
cin>>no;
for(int i=1; i<=no; i++)
f=f*i;
cout<<"The factorial of "<<no<<"is:"<<f;
getch();
}