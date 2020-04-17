// To find largest Eigen value of a matrix by Power method.

#include<bits/stdc++.h>
using namespace std;

#define SIZE 10

int main()
{
 float a[SIZE][SIZE],x[SIZE],x_new[SIZE];
 float temp,lambda_new,lambda_old,error;
 int i,j,n,step=1;
 cout<<"Enter Order of Matrix: \n";
 cin>>n;
 cout<<"Enter Tolerable Error: \n";
 cin>>error;
 cout<<"Enter Coefficient of Matrix: \n";
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   cin>>a[i][j];
 cout<<"Enter Initial Guess Vector: \n";
 for(i=1;i<=n;i++)
  cin>>x[i];
 lambda_old=1;
 label:for(i=1;i<=n;i++)
	   {
	    temp = 0.0;
		for(j=1;j<=n;j++)
		 temp=temp+a[i][j]*x[j];
		x_new[i]=temp;
	   }
 for(i=1;i<=n;i++)
  x[i]=x_new[i];
 lambda_new=fabs(x[1]);
 for(i=1;i<=n;i++)
  x[i]=x[i]/lambda_new;
 for(i=2;i<=n;i++)
  if(fabs(x[i])>lambda_new)
   	lambda_new = fabs(x[i]);
 cout<<"Eigen Value = "<< lambda_new<<'\n';
 for(i=1;i<=n;i++)
 if(fabs(lambda_new-lambda_old)>error)
 {
  lambda_old=lambda_new;
  step++;
  goto label;
 }
 return 0;
}
