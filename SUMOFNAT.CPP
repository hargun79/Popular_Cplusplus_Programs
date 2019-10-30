//to display a series of first n natural numbers and their sum and average.
#include<iostream.h>
#include<conio.h>
void main()
{
float sum=0,avg;
int n,f;
clrscr();
cout<<"\nEnter the value of n";
cin>>n;
cout<<"\nSeries of prime numbers is :";
for(int no=2,c=0;c<n;no++)
{
f=0;
for(int i=1;i<=no/2;i++)
if(no%i==0)
f++;
if(f==1)
{
cout<<no<<'\t';
sum+=no;
c++;
}
}
avg=sum/n;
cout<<"\nSum is :"<<sum;
cout<<"\nAverage is :"<<avg;
getch();
}