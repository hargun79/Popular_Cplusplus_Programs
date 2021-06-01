// To implement equal sum partition problem

#include<bits/stdc++.h>
using namespace std;

// Function to check if array can be divided into two partitions of equal sum
int equalPartition(int n, int arr[])
{
 int sum=0;
 for(int i=0;i<n;i++)
  sum+=arr[i];
 if(sum%2!=0)
  return 0;
 else
 {
  sum/=2;
  bool dp[n+1][sum+1]; 
  for(int i=0;i<=n;i++) 
  { 
   for(int j=0;j<=sum;j++) 
   { 
    if(i==0 || j==0)
    { 
     dp[i][j]=false;
     if(j==0)
      dp[i][j]=true;
    } 
    else
     if(arr[i-1]<=j) 
	  dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
    else
	 dp[i][j]=dp[i-1][j]; 
   } 
  } 
  if(dp[n][sum])
   return 1;
  else
   return 0;
 }
}

int main() 
{ 
 int arr[]={1,5,5,11};  
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<equalPartition(n,arr); 
 return 0; 
}