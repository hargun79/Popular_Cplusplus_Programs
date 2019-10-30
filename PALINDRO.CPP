//to accept a palindrome number .
#include<iostream.h>
#include<conio.h>
void main()
{
int rev,no,r,d;
clrscr();
rev=0;
cout<<"Enter a number to check whether it is palindrome or not.";
cin>>no;
d=no;
while(d!=0)
{
rev=rev*10;
rev=rev+d%10;
d=d/10;
}
if(no==rev)
cout<<no<<"is a palindrome number";
else
cout<<no<<"is not a palindrome number";
getch();
}