// Menu driven program for performing operations on 2D Matrix.

#include<iostream>
using namespace std;

// To input a matrix.
void input(int a[][10],int m,int n)
{
 cout<<"Enter a matrix : \n";
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
   cin>>a[i][j];
}

// To display a matrix row wise.
void displayr(int a[][10],int m,int n)
{
 for(int i=0;i<m;i++)
 {
  cout<<"\n";
  for(int j=0;j<n;j++)
   cout<<a[i][j]<<"\t";
 }
}

// To display a matrix column wise.
void displayc(int a[][10],int m,int n)
{
 for(int j=0;j<n;j++)
 {
  cout<<"\n";
  for(int i=0;i<m;i++)
   cout<<a[i][j]<<"\t";
 }
}

// To calculate the sum of two matrices.
void sum(int a[][10],int b[][10],int c[][10],int m,int n)
{
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
  {
   c[i][j]=a[i][j]+b[i][j];
  }
}

// To calculate the difference of two matrices.
void diff(int a[][10],int b[][10],int d[][10],int m,int n)
{
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
  {
   d[i][j]=a[i][j]-b[i][j];
  }
}

// To calculate the product of two matrices.
void product(int a[][10],int b[][10],int c[][10],int m,int r,int n)
{
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
  {
   c[i][j]=0;
   for(int k=0;k<r;k++)
    c[i][j]+=a[i][k]*b[k][j];
  }
}

//To find the transpose of the matrix.
void transpose(int a[][10],int m,int n)
{
 int b[10][10];
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
   b[j][i]=a[i][j];
 cout<<"Transpose of matrix is : ";
 for(int i=0;i<m;i++)
 {
  cout<<"\n";
  for(int j=0;j<n;j++)
   cout<<b[i][j]<<'\t';
 }
}

int main()
{
 int a[10][10],b[10][10],c[10][10],m,r,n,ch,s;
 do
 {
  cout<<"\n1: Sum of matrices\n";
  cout<<"2: Difference of matrices\n";
  cout<<"3: Product of matrices\n";
  cout<<"4: Transpose of matrix\n";
  cout<<"5: Quit\n";
  cout<<"Enter your choice : \n";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Enter the size of matrix : \n";
	      cin>>m>>n;
	      input(a,m,n);
	      input(b,m,n);
	      sum(a,b,c,m,n);
	      cout<<"Sum of matrix : ";
	      displayr(c,m,n);
	      break;
	case 2:cout<<"Enter the size of matrix : \n";
	       cin>>m>>n;
	       input(a,m,n);
	       input(b,m,n);
	       diff(a,b,c,m,n);
	       cout<<"Difference of matrices : ";
	       displayr(c,m,n);
	       break;  
    case 3:cout<<("Enter the row I : \n");
	       cin>>m;
	       cout<<("Enter the column I/row II : \n");
	       cin>>r;
	       cout<<("Enter the column II : \n");
	       cin>>n;
	       input(a,m,n);
	       input(b,m,n);
	       product(a,b,c,m,r,n);
	       cout<<"Product of matrix : ";
	       displayr(c,m,n);
	       break;
    case 4:cout<<"Enter the size of square matrix : \n";
	       cin>>m;
	       input(a,m,m);
	       transpose(a,m,m);
   	       break;
    case 5:exit(0);
    default:cout<<"Wrong choice\n";
  }
 }while(ch!=5);
 return 0;
}
