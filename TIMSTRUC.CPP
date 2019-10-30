#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
//to accept a valid time and return the same
struct tim
{int h,m,s;};
tim accept()
{
tim t;int max;char V='N';
do{cout<<"\n Enter a time";
cin>>t.h>>t.m>>t.s;
if(t.m>=0&&t.m<=59)
if(t.s>=0&&t.s<=59)
if(t.h>=0&&t.h<=23)V='Y';
}while (V!='Y');
return(t);
}
//to display a time in digital clock format
void digiclock(tim t)
{cout<<"\n The time is \t";
cout<<t.h<<":"<<t.m<<":"<<t.s<<'\n';
}
//to display a time in analog clock format
void anaclock(tim t)
{
cout<<"\n The time is \t";
if(t.h>=0&&t.h<=12)
cout<<t.h<<":"<<t.m<<":"<<t.s<<"A.M"<<'\n';
if(t.h>=13&&t.h<=23)
cout<<(t.h-12)<<":"<<t.m<<":"<<t.s<<"P.M"<<'\n';
}
//to calculate difference of two given time assuming t1 >t2
tim timdiff(tim t1,tim t2)
{ tim t;
 if(t1.s<t2.s)
  {t1.s+=60;
  t1.m-=1;}
  t.s=t1.s-t2.s;
  if(t1.m<t2.m)
  {t1.m+=60;
   t1.h-=1;}
   t.m=t1.m-t2.m;
  t.h=t1.h-t2.h;
  return(t);
}
//sum of 2 given time and return the same as a valid time
tim timesum(tim t1,tim t2)
{ tim t;
  t.s=t1.s+t2.s;
  t.m=t1.m+t2.m;
  t.h=t1.h+t2.h;
  do
  {
   if(t.s>=59)
   {
    t.s-=60;
    t.m+=1;
   }
   if(t.m>=59)
   {
    t.m-=60;
    t.h+=1;
   }
   if(t.s<59&&t.m<59)
   if(t.h>24)
   t.h-=24;
   break;
  }
  while(t.s>59&&t.m>59);
 return(t);
 }
void main()
{tim t,t1,t2;int ch;
do
{ clrscr();
  cout<<"\n 1.to display in digital clock format";
  cout<<"\n 2.to display in analog clock format";
  cout<<"\n 3.to find difference of two times";
  cout<<"\n 4.To find the sum of 2 times";
  cout<<"\n 5. Quit";
  cout<<"\n Enter your choice";
  cin>>ch;
  switch(ch)
  {case 1:t1=accept();
	digiclock(t1);
	break;
   case 2:t1=accept();
	anaclock(t1);
	break;
   case 3:t1=accept();
	  t2=accept();
	  t=timdiff(t1,t2);
	  cout<<"\n Difference is ";
	  digiclock(t);
	  break;
   case 4:t1=accept();
	  t2=accept();
	  t=timesum(t1,t2);
	  cout<<"\n Sum is ";
	  digiclock(t);
	  break;
   case 5:exit(0);
   default:cout<<"\n Wrong choice";
   }
  getch();
 }while(ch!=5);
}

