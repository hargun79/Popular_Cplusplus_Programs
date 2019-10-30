#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
void input(int a[],int &n)
{
 cout<<"\n Enter the size";
 cin>>n;
 cout<<"\n Enter the list";
 for(int i=0;i<n;i++)
  cin>>a[i];
}
void display(int a[],int n)
{
 cout<<"\n The new list is:";
 for(int i=0;i<n;i++)
  cout<<a[i]<<'\t';
}
void lsearch(int a[],int n,int no)
{
 int pos=-1;
 for(int i=0;i<n;i++)
  if(a[i]==no)
  {
   pos=i;
   break;
  }
  if(pos==-1)
  cout<<"\n Number not found";
  else
  cout<<"\n Number found at "<<pos<<" position";
}
void bsearcha(int a[],int n,int no)
{
 int L=0,U=n-1,Mid;
 int pos=-1;
 while(L<=U)
 {
  Mid=(L+U)/2;
  if(a[Mid]==no)
  {
   pos=Mid;
   break;
  }
  else
  if(a[Mid]<no)
   L=Mid+1;
  else
   U=Mid-1;
 }
 cout<<"\n Number found at "<<pos<<" position";
}
void bsearchd(int a[],int n,int no)
{
 int L=0,U=n-1,Mid;
 int pos=-1;
 while(L<=U)
 {
  Mid=(L+U)/2;
  if(a[Mid]==no)
  {
   pos=Mid;
   break;
  }
  else
  if(a[Mid]<no)
   U=Mid-1;
  else
   L=Mid+1;
 }
 cout<<"\n Number found at "<<pos<<" position";
}
void ssorta(int a[],int n)
{
 int t,min;
 int pos;
 for(int i=0;i<n-1;i++)
 {
  min=a[i];
  pos=i;
  for(int j=i+1;j<n;j++)
   if(a[j]<min)
   {
    min=a[j];
    pos=j;
   }
  t=a[i];
  a[i]=a[pos];
  a[pos]=t;
 }
}
void ssortd(int a[],int n)
{
 int t,max;
 int pos;
 for(int i=0;i<n-1;i++)
 {
  max=a[i];
  pos=i;
  for(int j=i+1;j<n;j++)
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
void bsorta(int a[],int n)
{
 int t;
 for(int i=0;i<n-1;i++)
  for(int j=0;j<n-(i+1);j++)
   if(a[j]>a[j+1])
   {
    t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;
   }
}
void bsortd(int a[],int n)
{
 int t;
 for(int i=0;i<n-1;i++)
  for(int j=0;j<n-(i+1);j++)
   if(a[j]<a[j+1])
   {
    t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;
   }
}
void isorta(int a[],int n)
{
 for(int i=1;i<n;i++)
 {
  for(int j=i-1,t=a[i];t<a[j] && j>=0;j--)
   a[j+1]=a[j];
  a[j+1]=t;
 }
}
void isortd(int a[],int n)
{
 for(int i=1;i<n;i++)
 {
  for(int j=i-1,t=a[i];t>a[j] && j>=0;j--)
   a[j+1]=a[j];
  a[j+1]=t;
 }
}
void mergeAAA(int a[],int b[],int c[],int m,int n)
{
 int i=0,j=0,k=0;
 while(i<m && j<n)
  if(a[i]<b[j])
   c[k++]=a[i++];
  else
   c[k++]=b[j++];
 if(i<m)
  while(i<m)
  c[k++]=a[i++];
 if(j<n)
  while(j<n)
  c[k++]=b[j++];
}
void mergeADAs(int a[],int b[],int c[],int m,int n)
{
 int i=0,j=n-1,k=0;
 while(i<m && j>=0)
  if(a[i]<b[j])
   c[k++]=a[i++];
  else
   c[k++]=b[j--];
 while(i<m)
  c[k++]=a[i++];
 while(j>=0)
  c[k++]=a[j--];
}
void mergeADAl(int a[],int b[],int c[],int m,int n)
{
 int i=m-1,j=0,k=m+n-1;
 while(i>=0 && j<n)
  if(a[i]<b[j])
   c[k--]=a[i--];
  else
   c[k--]=b[j++];
 while(i<m)
  c[k--]=a[i--];
 while(j>=0)
  c[k--]=a[j++];
}
void mergeADD(int a[],int b[],int c[],int m,int n)
{
 int i=m-1,j=0,k=0;
 while(i>=0 && j<n)
  if(a[i]<b[j])
   c[k++]=a[i--];
  else
   c[k++]=b[j++];
 while(i>=0)
  c[k++]=a[i--];
 while(j<n)
  c[k++]=a[j++];
}
void mergeDAA(int a[],int b[],int c[],int m,int n)
{
 int i=0,j=n-1,k=m+n-1;
 while(i<m && j>=0)
  if(a[i]<b[j])
   c[k--]=a[i++];
  else
   c[k--]=b[j--];
 while(i<m)
  c[k--]=a[i++];
 while(j>=0)
  c[k--]=a[j--];
}
void insert(int a[],int &n,int max,int no,int pos)
{
 if(n==max)
  cout<<"\n Insertion not possible";
 else
 {
  for(int i=n-1;i>=pos;i--)
   a[i+1]=a[i];
  a[i]=no;
  n++;
 }
}
void inserta(int a[],int &n,int max,int no)
{
 if(n==max)
  cout<<"\n Insertion not possible";
 else
 {
  for(int i=n-1;a[i]>no;i--)
   a[i+1]=a[i];
  a[i]=no;
  n++;
 }
}
void insertd(int a[],int &n,int max,int no)
{
 if(n==max)
  cout<<"\n Insertion not possible";
 else
 {
  for(int i=n-1;a[i]<no;i--)
   a[i+1]=a[i];
  a[i+1]=no;
  n++;
 }
}
void del(int a[],int &n,int no)
{
 int pos=-1;
 if(n==0)
  cout<<"\n List is empty";
 else
 {
  for(int i=0;i<n;i++)
   if(a[i]==no)
   {
    pos=i;
    break;
   }
 }
 if(pos==-1)
  cout<<"\n Number not found";
 else
 {
  for(int j=pos;j<n-1;j++)
   a[j]=a[j+1];
  n--;
 }
}
void main()
{
 int ch1,n,no,a[20],b[20],c[40],m,i,pos,ch2;
 char ch3;
 do
 {
  clrscr();
  cout<<"\n 1:Searching";
  cout<<"\n 2:Sorting";
  cout<<"\n 3:Merging";
  cout<<"\n 4:Insertion In An Array";
  cout<<"\n 5:Deleion";
  cout<<"\n 6:Transversal";
  cout<<"\n 7:Quit";
  cout<<"\n Enter your choice";
  cin>>ch1;
  switch(ch1)
  {
   case 1:cout<<"\nYou have selected Searching";
	  do
	  {
	   clrscr();
	   cout<<"\n 1.Linear Searching";
	   cout<<"\n 2.Binary Searching";
	   cout<<"\n 3.Return";
	   cout<<"\n Enter your choice";
	   cin>>ch2;
	   switch(ch2)
	   {
	    case 1:cout<<"\nYou have selected Linear Searching";
		   input(a,n);
		   cout<<"\nEnter the number to be searched";
		   cin>>no;
		   lsearch(a,n,no);
		   break;
	    case 2:cout<<"\nYou have selected Binary Searching";
		   do
		   {
		    clrscr();
		    cout<<"\n A:Ascending";
		    cout<<"\n D:Decending";
		    cout<<"\n R:Return";
		    cout<<"\n Enter your choice";
		    cin>>ch3;
		    switch(ch3)
		    {
		     case 'A':cout<<"\nYou have selected Ascending Order";
			      input(a,n);
			      cout<<"\nEnter the number to be searched";
			      cin>>no;
			      bsearcha(a,n,no);
			      break;
		     case 'D':cout<<"\nYou have selected Decending Order";
			      input(a,n);
			      cout<<"\nEnter the number to be searched";
			      cin>>no;
			      bsearchd(a,n,no);
			      break;
		     case 'R':return;
		     default:cout<<"\nInvalid choice";
		    } getch();
		   }while(ch3!='R');
		   break;
	    case 3:return;
	    default:cout<<"\nInvalid choice";
	   }getch();
	  }while(ch3!='R');
	  break;
   case 2:cout<<"\nYou have selected Sorting";
	  do
	  {
	   clrscr();
	   cout<<"\n 1.Selection Sorting";
	   cout<<"\n 2.Bubble Sorting";
	   cout<<"\n 3.Insertion Sorting";
	   cout<<"\n 4.Return";
	   cout<<"\n Enter your choice";
	   cin>>ch2;
	   switch(ch2)
	   {
	    case 1:cout<<"\n You have selected Selection Sorting";
		   do
		   {
		    clrscr();
		    cout<<"\n A:Ascending";
		    cout<<"\n D:Decending";
		    cout<<"\n R:Return";
		    cout<<"\n Enter your choice";
		    cin>>ch3;
		    switch(ch3)
		    {
		     case 'A':input(a,n);
			      ssorta(a,n);
			      display(a,n);
			      break;
		     case 'D':input(a,n);
			      ssortd(a,n);
			      display(a,n);
			      break;
		     case 'R':return;
		     default:cout<<"\nInvalid choice";
		    }getch();
		   }while(ch2!='R');
		   break;
	    case 2:cout<<"\n You have selected Bubble Sorting";
		   do
		   {
		    clrscr();
		    cout<<"\n A:Ascending";
		    cout<<"\n D:Decending";
		    cout<<"\n R:Return";
		    cout<<"\n Enter your choice";
		    cin>>ch3;
		    switch(ch3)
		    {
		     case 'A':input(a,n);
			      bsorta(a,n);
			      display(a,n);
			      break;
		     case 'D':input(a,n);
			      bsortd(a,n);
			      display(a,n);
			      break;
		     case 'R':return;
		     default:cout<<"\nInvalid choice";
		    }getch();
		   }while(ch2!='R');
		   break;
	    case 3:cout<<"\n You have selected Insertion Sorting";
		   do
		   {
		    clrscr();
		    cout<<"\n A:Ascending";
		    cout<<"\n D:Decending";
		    cout<<"\n R:Return";
		    cout<<"\n Enter your choice";
		    cin>>ch3;
		    switch(ch3)
		    {
		     case 'A':input(a,n);
			      isorta(a,n);
			      display(a,n);
			      break;
		     case 'D':input(a,n);
			      isortd(a,n);
			      display(a,n);
			      break;
		     case 'R':return;
		     default:cout<<"\nInvalid choice";
		    }getch();
		   }while(ch2!='R');
		   break;
	    case 4:return;
	    default:cout<<"\nInvalid choice";
	   }
	  }while(ch2!='R');
	  break;
   case 3:cout<<"\nYou have selected Merging";
	  do
	  {
	   clrscr();
	   cout<<"\n 1:Merging Two Lists In Ascending Order to Ascending Order";
	   cout<<"\n 2:Merging A List In Ascending Order And Other In Decending to Ascending Order";
	   cout<<"\n 3:Merging A List In Ascending Order And Other In Decending to Decending Order";
	   cout<<"\n 4:Merging A List In Decending Order And Other In Ascending to Ascending Order";
	   cout<<"\n 5:Quit";
	   cout<<"\n Enter your choice";
	   cin>>ch1;
	   switch(ch1)
	   {
	    case 1:cout<<"\nYou have selected AAA";
		   cout<<"\n Enter the size";
		   cin>>m;
		   cout<<"\n Enter the list(1)";
		   for(i=0;i<m;i++)
		    cin>>a[i];
		   ssorta(a,m);
		   cout<<"\n Enter the size";
		   cin>>n;
		   cout<<"\n Enter the list(2)";
		   for(i=0;i<n;i++)
		    cin>>b[i];
		   ssorta(b,n);
		   mergeAAA(a,b,c,m,n);
		   display(c,m+n);
		   break;
	    case 2:cout<<"\nYou have selected ADA";
		   cout<<"\n Enter the size";
		   cin>>m;
		   cout<<"\n Enter the list(1)";
		   for(i=0;i<m;i++)
		    cin>>a[i];
		   ssorta(a,m);
		   cout<<"\n Enter the size";
		   cin>>n;
		   cout<<"\n Enter the list(2)";
		   for(i=0;i<n;i++)
		    cin>>b[i];
		   ssortd(b,n);
		   mergeADAs(a,b,c,m,n);
		   display(c,m+n);
		   break;
	    case 3:cout<<"\nYou have selected ADD";
		   cout<<"\n Enter the size";
		   cin>>m;
		   cout<<"\n Enter the list(1)";
		   for(i=0;i<m;i++)
		    cin>>a[i];
		   ssorta(a,m);
		   cout<<"\n Enter the size";
		   cin>>n;
		   cout<<"\n Enter the list(2)";
		   for(i=0;i<n;i++)
		    cin>>b[i];
		   ssortd(b,n);
		   mergeADD(a,b,c,m,n);
		   display(c,m+n);
		   break;
	    case 4:cout<<"\nYou have selected DAA";
		   cout<<"\n Enter the size";
		   cin>>m;
		   cout<<"\n Enter the list(1)";
		   for(i=0;i<m;i++)
		    cin>>a[i];
		   ssortd(b,m);
		   cout<<"\n Enter the size";
		   cin>>n;
		   cout<<"\n Enter the list(2)";
		   for(i=0;i<n;i++)
		    cin>>b[i];
		   ssorta(b,n);
		   mergeDAA(a,b,c,m,n);
		   display(c,m+n);
		   break;
	    case 5:return;
	    default:cout<<"\n Invalid Choice";
	   }getch();
	  }while(ch1!=5);
	  break;
   case 4:cout<<"\nYou have selected Insertion";
	  do
	  {
	   clrscr();
	   cout<<"\n A:Ascending";
	   cout<<"\n D:Decending";
	   cout<<"\n S:Specific position";
	   cout<<"\n R:Return";
	   cout<<"\n Enter your choice";
	   cin>>ch2;
	   switch(ch2)
	   {
	    case 'A':input(a,n);
		     cout<<"\n Enter a number to  insert in the list";
		     cin>>no;
		     inserta(a,n,20,no);
		     display(a,n);
		     break;
	    case 'D':input(a,n);
		     cout<<"\n Enter a number to insert in the list";
		     cin>>no;
		     insertd(a,n,20,no);
		     display(a,n);
		     break;
	    case 'S':input(a,n);
		     cout<<"\n Enter a number to insert in the list";
		     cin>>no;
		     cout<<"\n Enter a position to which number will be inserted";
		     cin>>pos;
		     insert(a,n,20,no,pos);
		     display(a,n);
	    case 'R':return;
	    default:cout<<"\nInvalid choice";
	   }getch();
	  }while(ch2!='R');
	  break;
   case 5:cout<<"\nYou have selected Deletion";
	  input(a,n);
	  cout<<"\n Enter a number to be deleted from the list";
	  cin>>no;
	  del(a,n,no);
	  break;
   case 6:cout<<"\nYou have selected Transversal";
	  break;
   case 7:exit(0);
   default:cout<<"\n Invalid Choice";
  }
  getch();
 }while(ch1!=7);
}