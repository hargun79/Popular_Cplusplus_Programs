//to input a date and check for its validity .
#include<iostream.h>
#include<conio.h>
void main()
{
int dd,mm,yy,Max;
char valid='N';
clrscr();
cout<<"Enter the date";
cin>>dd>>mm>>yy;
if(mm>=1 && mm<=12)
switch(mm)
{
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:Max=31;break;
case 2:if(yy%4==0 && yy%100!=0 || yy%400==0)
Max=29;
else Max=28;break;
default:Max=30;
}
if(dd>=1 && dd<=Max)
valid='Y';
else
valid='N';
if(valid=='Y')
cout<<"It is a valid date\n";
else
cout<<"It is not a valid date";
getch();
}
