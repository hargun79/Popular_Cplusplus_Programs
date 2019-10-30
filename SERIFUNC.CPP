#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<process.h>
unsigned long factorial(int no)
{
unsigned long f=1;
for(int i=1;i<=no;i++)
f=f*i;
return(f);
}
double power(double b,int e)
{
double p=1;
for(int i=1;i<=e;i++)
p=p*b;
return(p);
}
//series 1.
double sum1(double x,int n)
{
double s=1;
float num,de,term;
for(int i=1;i<n;i++)
{
num=power(x,i);
de=factorial(i+1);
term=num/de;
s+=term;
}
return(s);
}
//series 2.
double sum2(double x,int n)
{
double s=0;
float num,de,term;
int ctr=0;
for(int i=1;i<=n*2;i+=2)
{
ctr++;
num=power(x,i);
de=factorial(2*i);
term=num/de;
if(ctr%2)
s+=term;
else
s-=term;
}
return(s);
}
//series 3.
double sum3(double x,int n)
{
double s=0;
float num,de,term;
for(int i=1;i<=n;i++)
{
num=power(x,i);
de=factorial(i*2);
term=num/de;
if(i%2)
s+=term;
else
s-=term;
}
return(s);
}
//series 4.
double sum4(double x,int n)
{
double s=0;
float num,de,term;
int ctr=0;
for(int i=1;i<=n*2;i+=2)
{
ctr++;
num=power(x,i);
de=factorial(2*i-1);
term=num/de;
if(ctr%2)
s-=term;
else
s+=term;
}
return(s);
}
void main()
{
int ch,n;
float x;
double s;
do
{
clrscr();
cout<<"1. 1+x^1/2!+x^2/3!+...\n";
cout<<"2. x^1/2!-x^3/6!+x^5/10!+...\n";
cout<<"3. x^1/2!-x^2/4!+x^3/6!+...\n";
cout<<"4. -x^2/3!+x^4/7!-x^6/11!+...\n";
cout<<"5. Quit\n";
cout<<"Enter your choice\n";
cin>>ch;
switch(ch)
{
case 1:cout<<"Enter the value of numerator and number of terms\n";
cin>>x>>n;
s=sum1(x,n);
cout<<"The sum of the series is:\t"<<s;
break;
case 2:cout<<"Enter the value of numerator and number of terms\n";
cin>>x>>n;
s=sum2(x,n);
cout<<"The sum of the series is:\t"<<s;
break;
case 3:cout<<"Enter the value of numerator and number of terms\n";
cin>>x>>n;
s=sum3(x,n);
cout<<"The sum of the series is:\t"<<s;
break;
case 4:cout<<"Enter the value of numerator and number of terms\n";
cin>>x>>n;
s=sum4(x,n);
cout<<"The sum of the series is:\t"<<s;
break;
case 5:exit(0);
default:cout<<"Wrong choice\n";
}
getch();
}
while(ch!=5);
}
