// to print sum of the factorials of n prime numbers.
#include<iostream.h>
#include<conio.h>
void main()
{
int n;
float s=0, p;
clrscr();
cout<<"Enter a number";
cin>>n;
for(int i=1;i<=n;i++)
{
p=1;
for(int j=1;j<=i;j++)
p=p*j;
s+=p;
}
cout<<"Sum of series is:\t"<<s;
getch();
}