/* To implement matrix operation using class and perform the functions:
  1. Upper Triangle of a matrix.
  2. Lower Triangle of a matrix.
  3. Addition of matrix.
  4. Subtraction of matrix.
  5. Product of matrix.
  6. Fill a matrix with prime numbers starting from a given no.
  7. Sum and average of prime numbers in a matrix.
  8. Return sum of diagonal elements.
  9. Display the middle row of a matrix.
  10.Display the middle column of a matrix.
*/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int ch;
class matrix
{
 int a[10][10]; // To store a 2D array.
 int r,c;       // To store number of rows and columns.
 public:
	void input();
	void outputr();
	void outputc();
	void upper();
	void lower();
	void add(matrix m1,matrix m2);
	void sub(matrix m1,matrix m2);
	void product(matrix m1,matrix m2);
	void fillprimer(int);
	void sumprime();
	int dsum();
	void dmidr();
	void dmidc();
};
// To input the details of a 2D matrix.
void matrix::input()
{
 int no;
 cout<<"\n Enter number of rows and colums\n";
 cin>>r>>c;
 if(ch!=6)
 {
  cout<<"\n Enter a matrix\n";
  for(int i=0;i<r;i++)
   for(int j=0;j<c;j++)
    cin>>a[i][j];
 }
 else
 {
  cout<<"\n Enter the starting number\n";
  cin>>no;
  fillprimer(no);
 }
}
// To display the details of a 2D matrix row wise.
void matrix::outputr()
{
 for(int i=0;i<r;i++)
 {
  cout<<'\n';
  for(int j=0;j<c;j++)
   cout<<a[i][j]<<'\t';
 }
}
// To display the details of a 2D matrix column wise.
void matrix::outputc()
{
 for(int j=0;j<c;j++)
 {
  cout<<'\n';
  for(int i=0;i<r;i++)
   cout<<a[i][j]<<'\t';
 }
}
// To display upper triangular matrix.
void matrix::upper()
{
 cout<<"\n Upper Triangular matrix is:";
 for(int i=0;i<r;i++)
 {
  cout<<'\n';
  for(int j=0;j<c;j++)
  if(i<=j)
   cout<<a[i][j]<<'\t';
  else
   cout<<" "<<'\t';
 }
}
// To display lower triangular matrix.
void matrix::lower()
{
 cout<<"\n Lower Triangular matrix is:";
 for(int i=0;i<r;i++)
 {
  cout<<'\n';
  for(int j=0;j<c;j++)
  if(i>=j)
   cout<<a[i][j]<<'\t';
  else
   cout<<" "<<'\t';
 }
}
// To add two 2D matrix.
void matrix::add(matrix m1,matrix m2)
{
 r=m1.r;
 c=m2.c;
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
  {
   a[i][j]=m1.a[i][j]+m2.a[i][j];
  }
}
// To subtract two 2D matrix.
void matrix::sub(matrix m1,matrix m2)
{
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
  {
   a[i][j]=m1.a[i][j]-m2.a[i][j];
  }
}
// To find the product of two 2D matrix.
void matrix::product(matrix m1,matrix m2)
{
 int x=m1.r*m2.r;
 r=m1.r;
 c=m1.c;
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
  {
   a[i][j]=0;
   for(int k=0;k<x;k++)
    a[i][j]+=m1.a[i][k]*m2.a[k][j];
  }
}
// To check if a given number is prime or not.
prime(int no)
{
 int f=0;
 for(int i=1;i<=no/2;i++)
  if(no%i==0)
   f++;
 if(f==1)
  return('Y');
 else
  return('N');
}
// To fill a matrix with prime numbers starting from a given number row wise.
void matrix::fillprimer(int no)
{
 char p;
 for(int i=0;i<r;i++)
  for(int j=0;j<c;no++)
   {
    p=prime(no);
    if(p=='Y')
     {
      a[i][j]=no;
      j++;
     }
   }
}
// To find sum of all prime numbers in a 2D matrix.
void matrix::sumprime()
{
 char p;
 int s=0,x=0;
 float avg;
 for(int i=0;i<r;i++)
 {
  cout<<"\n";
  for(int j=0;j<c;j++)
  {
   p=prime(a[i][j]);
   if(p=='Y')
   {
    cout<<a[i][j]<<" ";
    s+=a[i][j];
    x++;
   }
   else
    cout<<"  ";
  }
 }
 avg=(float)s/x;
 cout<<"\n Sum is:"<<s;
 cout<<"\n Average is:"<<avg;
}
// To display the sum of diagonals.
int matrix::dsum()
{
 matrix m;
 int s=0,j,i;
 cout<<"\n Diagonal one is:";
 for(i=0;i<r;i++)
 {
  cout<<'\n';
  for(j=0;j<c;j++)
   if(i==j)
    {
     cout<<a[i][j]<<'\t';
     s+=a[i][j];
    }
   else
    cout<<" "<<'\t';
 }
 cout<<"\n Diagonal two is:";
 for(i=0;i<r;i++)
 {
  cout<<'\n';
  for(j=0;j<c;j++)
   if(i+j==r-1)
    {
     cout<<a[i][j]<<'\t';
     s+=a[i][j];
    }
   else
    cout<<" "<<'\t';
 }
 return(s);
}
// To display the middle row of a 2D matrix.
void matrix::dmidr()
{
 matrix m;
 int mid;
 if(r%2==0)
  cout<<"\n No middle row";
 else
  {
   mid=r/2;
   for(int i=0;i<c;i++)
    cout<<a[mid][i]<<'\t';
  }
}
// To display the middle column of a 2D matrix.
void matrix::dmidc()
{
 matrix m;
 int mid;
 if(c%2==0)
  cout<<"\n No middle column";
 else
  {
   mid=c/2;
   for(int i=0;i<r;i++)
    cout<<a[i][mid]<<'\t';
  }
}
void main()
{
 int r,c,no,s;
 matrix m,m1,m2,m3;
 do
 {
  clrscr();
  cout<<"\n 1. Upper Triangle of a matrix";
  cout<<"\n 2. Lower Triangle of a matrix";
  cout<<"\n 3. Addition of matrix";
  cout<<"\n 4. Subtraction of matrix";
  cout<<"\n 5. Product of matrix";
  cout<<"\n 6. Fill a matrix with prime numbers starting from a given no";
  cout<<"\n 7. Sum and average of prime numbers in a matrix";
  cout<<"\n 8. Return sum of diagonal elements";
  cout<<"\n 9. Display the middle row of a matrix";
  cout<<"\n 10.Display the middle column of a matrix";
  cout<<"\n 11.Quit";
  cout<<"\n Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:clrscr();
	  m.input();
	  m.upper();
	  break;
   case 2:clrscr();
	  m.input();
	  m.lower();
	  break;
   case 3:clrscr();
	  cout<<"Enter the first matrix";
	  m1.input();
	  cout<<"Enter the second matrix";
	  m2.input();
	  m.add(m1,m2);
	  cout<<"\nThe sum of the two matrix is:";
	  m.outputr();
	  break;
   case 4:clrscr();
	  cout<<"Enter the first matrix";
	  m1.input();
	  cout<<"Enter the second matrix";
	  m2.input();
	  m.sub(m1,m2);
	  cout<<"\nThe difference of the two matrix is:";
	  m.outputr();
	  break;
   case 5:clrscr();
	  cout<<"Enter the first matrix";
	  m1.input();
	  cout<<"Enter the second matrix";
	  m2.input();
	  m.product(m1,m2);
	  cout<<"\n Product of matrix:";
	  m.outputr();
	  break;
   case 6:clrscr();
	  m.input();
	  m.outputr();
	  break;
   case 7:clrscr();
	  cout<<"\nEnter a matrix";
	  m.input();
	  m.sumprime();
	  break;
   case 8:clrscr();
	  cout<<"Enter a matrix\n";
	  m.input();
	  s=m.dsum();
	  cout<<"\nThe sum of diagonals is:\n"<<s;
	  break;
   case 9:clrscr();
	  cout<<"Enter a matrix\n";
	  m.input();
	  cout<<"\nThe middle row of the matrix is:\t";
	  m.dmidr();
	  break;
   case 10:clrscr();
	   cout<<"Enter a matrix \n";
	   m.input();
	   cout<<"\nThe middle column of the matrix is:\t";
	   m.dmidc();
	   break;
   case 11:exit(0);
   default:cout<<"Wrong choice\n";
  }
  getch();
 }while(ch!=11);
}

