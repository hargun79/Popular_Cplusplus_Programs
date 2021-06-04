// To implement matrix chain multiplication and find the bracket sequence

#include<bits/stdc++.h>
using namespace std;

#define MAX 10

int lookup[MAX][MAX],b[MAX][MAX];

void printMultiplication(int i,int j)
{
 if(i==j)
  cout<<" "<<"M"<<i<<" ";
 else
 {
  cout<<"(";
  printMultiplication(i,b[i][j]);
  printMultiplication(b[i][j]+1, j);
  cout<<")";
 }
}

// Function to find the most efficient way to multiply given sequence of matrices
int MatrixChainMultiplication(int dims[],int i,int j)
{
 if(j<=i+1)
  return 0;
 int min=INT_MAX;
 if(lookup[i][j]==0)
 {
  for(int k=i+1;k<=j-1;k++)
  {
   int cost=MatrixChainMultiplication(dims,i,k);
   cost+=MatrixChainMultiplication(dims,k,j);
   cost+=dims[i]*dims[k]*dims[j];
   if(cost<min)
	min=cost;
   b[i][j]=k;	
  }
  lookup[i][j]=min;
 }
 return lookup[i][j];
}

int main()
{
 int dims[]={10,30,5,60};
 int n=sizeof(dims)/sizeof(dims[0]);
 cout<<"Minimum cost is: "<<MatrixChainMultiplication(dims,0,n-1)<<'\n';
 printMultiplication(0,n-1);
 return 0;
}
