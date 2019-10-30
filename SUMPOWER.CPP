// to print the sum of n numbers to their power.
#include<iostream.h>
#include<conio.h>
void main()
{
int n;
float s=0,p;
clrscr();
cout<<"Enter a number";
cin>>n;
for(int i=1;i<=n;i++)
{
p=1;
for(int j=1;j<=i;j++)
p=p*i;
s+=p;
}
cout<<"The sum of series is :\t"<<s;
getch();
}