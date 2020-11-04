#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class array
{
int a[100];
int n;
public:
	void input();
	void display();
	void reverse();
	int bsearchd(int no);
	void ssortd();
	void isorta();
	void insertsa(int no);
	void deletion(int no);
	void mergeddd(array a1,array a2);
	};
void array::input()
{
cout<<"\n enter the size";
cin>>n;
cout<<"\n Enter the array";
for(int i=0;i<n;i++)
cin>>a[i];
}
void array::display()
{
cout<<"\n Array is:";
for(int i=0;i<n;i++)
cout<<a[i]<<'\t';
}

void array::reverse()
{int t,j,i;
for(i=0,j=n-1;i<j;i++,j--)
{t=a[i];
a[i]=a[j];
a[j]=t;
}}

int array::bsearchd(int no)
{
 int mid,l=0,u=n-1;int pos=-1;
 while(l<=u)
 {
  mid=(l+u)/2;
  if(a[mid]==no)
  {
   pos=mid;
   break;
  }
  else
   if (a[mid]>no)
    l=mid+1;
   else
    u=mid-1;
 }
 return(pos);
}
 void array::ssortd()
 {
   int t,max;
   int pos;
   for(int i=0;i<n-1;i++)
   {
   max=a[i];
   pos=i;
   for(int j=0;j<n;j++)
   if(a[j]>max)
   {
     max=a[j];
     pos=j;
   }
     t=a[i];
     a[i]=a[pos];
     a[pos]=t;
   }
   }
 void array::isorta()
 {
   int t;
   for(int i=0;i<n;i++)
 {
   for(int j=t-1,t=a[i];t<a[j] && j>=0;j--)
   a[j=1]=a[j];
   a[j=1]=t;
 }
 }
 void array::insertsa(int no)
 {
    int max;
    if (n==max)
    cout<<"\n insertion not possible";
    else
 {
 for(int i=n-1;a[i]>no;i--)
 a[i=1]=a[i];
 a[i]=no;
 n++;
 }
 }
 void array::deletion(int no)
 {
   int pos=-1;
   if(n==0)
   cout<<"\n list is empty";
   else
   {
   for(int i=0;i<n;i++)
   if(a[i]==no)
   {
     pos=i;
     break;
   }}
   if(pos==-1)
   cout<<"\n no not found";
   else
   {
   for(int j=pos;j<n-1;j++)
   a[j]=a[j+1];
   n--;
   }}
   void array::mergeddd(array a1,array a2)
   { int n=a1.n+a2.n;int i=n-1,j=n-1,k=n-1;
	  while(i>=0 && j>=0)
	  {
	  if(a[i] < a[j])
	  a[k--] = a1.a[i--];
	  else
	  a[k--] = a2.a[j--];
	  }
     while(i>=0)
     a[k--]=a1.a[i--];
     while(j>=0)
     a[k--]=a2.a[j--];
     }
     void main()
     {
     int ch,pos,no; array a,a1,a2;
     do
     {
     clrscr();
     cout<<"\n 1.reversal of list";
     cout<<"\n 2.searching a no in a list";
     cout<<"\n 3.sorting in descending order";
     cout<<"\n 4.sorting in ascending order";
     cout<<"\n 5.inserting a no in ascending order";
     cout<<"\n 6. deletion of a no in a list";
     cout<<"\n 7.merging a no in ddd format";
     cout<<"\n 8. quit";
     cout<<"\n enter your choice";
     cin>>ch;
     switch(ch)
     {
     case 1:a.input();
	    a.display();
	    a.reverse();
	    a.display();
	    break;
     case 2:a.input();
	    a.display();
	    cout<<"\n enter the no to be searched";
	    cin>>no;
	    a.ssortd();
	    a.display();
	    pos=a.bsearchd(no);
	    if(pos==-1)
	    cout<<"\n no not found";
	    else
	    cout<<"\n the position of the searched no is"<<pos;
	    break;
     case 3:a.input();
	    a.display();
	    a.ssortd();
	    a.display();
	    break;
     case 4:a.input();
	    a.display();
	    a.isorta();
	    a.display();
	    break;
     case 5:a.input();
	    a.display();
	    a.ssortd();
	    cout<<"\n enter the no to be added in a list";
	    cin>>no;
	    a.insertsa(no);
	    a.display();
	    break;
     case 6:a.input();
	    a.display();
	    a.isorta();
	    cout<<"\n enter the no to be deleted";
	    cin>>no;
	    a.deletion(no);
	    a.display();
	    break;
     case 7:a.input();
	    a.display();
	    a.ssortd();
	    a.isorta();
	    a.mergeddd(a1,a2);
	    a.display();
	    break;
     case 8:exit(0);
     }
     getch();
     }while(ch!=8);
     }
