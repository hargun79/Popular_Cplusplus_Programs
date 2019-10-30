
//to display table of any number and any number of times .
#include<iostream.h>
#include<conio.h>
void main()
{
unsigned long no,n;
clrscr();
cout<<"Enter any number and the number it is to be multiplied till.\n";
cin>>no>>n;
for(int c=1; c<=n; c++)
cout<<no<<"\tx\t"<<c<<"\t=\t"<<no*c<<'\n';
getch();
}